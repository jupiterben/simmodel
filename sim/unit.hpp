#pragma once


template <int _N1, int _N2, int _N3, int _N4=0, int _N5 =0 , int _N6 = 0, int _N7=0>
class dimension
{
public:
	const static int N1 = _N1;
	const static int N2 = _N2;
	const static int N3 = _N3;
	const static int N4 = _N4;
	const static int N5 = _N5;
	const static int N6 = _N6;
	const static int N7 = _N7;

	typedef dimension<N1, N2, N3,N4,N5,N6,N7> type;
};

template<class D1, class D2>
struct dim_plus
{
	typedef dimension< D1::N1+D2::N1
		,D1::N2+D2::N2
		,D1::N3+D2::N3
		,D1::N4+D2::N4
		,D1::N5+D2::N5
		,D1::N6+D2::N6
		,D1::N7+D2::N7 >  type;
};

template<class D1, class D2>
struct dim_minus
{
	typedef dimension< D1::N1-D2::N1
		,D1::N2-D2::N2
		,D1::N3-D2::N3
		,D1::N4-D2::N4
		,D1::N5-D2::N5
		,D1::N6-D2::N6
		,D1::N7-D2::N7 >  type;
};


//


template<class _D>
struct BaseUnit 
{
	typedef _D Dimension;
	static double scale(){ return 1.0; }
};


template<class _D>
struct Unit
{
	typedef _D Dimension;	
};


template<class _U1, class _U2>
struct multi
{
	typedef BaseUnit< typename dim_plus<typename _U1::Dimension,typename _U2::Dimension>::type > type;
};
template<class _U1, class _U2>
struct divide
{
	typedef BaseUnit< typename dim_minus<typename _U1::Dimension,typename _U2::Dimension>::type > type;
};


template<class _U, class _D = typename _U::Dimension>
class Quantity
{
public:
	typedef Quantity<_U,_D> this_type;
	typedef _U this_unit;



	Quantity():val(0){}
	explicit Quantity(double v):val(v){}

	template<class _U1>
		Quantity(const Quantity<_U1,_D>& other)
	{
		val = other.base_value()/this_unit::scale();
	}

	this_type& value(double v){ val = v; return *this; }
	double value()const{ return val; }
	double base_value()const{ return val * this_unit::scale(); }	

	this_type& operator*=(double s){ val*=s; return *this; }
	this_type& operator/=(double s){ val/=s; return *this; }	


	this_type& operator+=(const this_type& other){ val+=other.val; return *this; }
	this_type& operator-=(const this_type& other){ val+=other.val; return *this; }

protected:
	double val;		
};

template<class U1,class U2>
Quantity< typename multi<U1,U2>::type >  operator*(const Quantity<U1>& q1, const Quantity<U2>& q2)
{
	double val =  q1.base_value() * q2.base_value();
	Quantity< multi<U1,U2>::type > q;
	q.value(val);
	return q;
}



template<class U1,class U2>
Quantity< typename divide<U1,U2>::type >  operator/(const Quantity<U1>& q1, const Quantity<U2>& q2)
{
	double val =  q1.base_value() * q2.base_value();
	Quantity<  divide<U1,U2>::type > q;
	q.value(val);
	return q;
}

template<class U>
Quantity<U> operator*(double s, const Quantity<U>& q)
{
	Quantity<U> r = q;
	q *= s
	return r;
}



#define UNIT_DEFINE_BASE(classname, dim, sname, sshortname)  class classname : public BaseUnit<dim>{ \
public: \
	static const char* name(){ return sname; } \
	static const char* short_name(){ return sshortname; }\
};

#define UNIT_DEFINE( classname, dim, dscale, sname, sshortname)  class classname : public Unit<dim>{ \
public: \
	static double scale(){ return dscale; } \
	static const char* name(){ return sname; } \
	static const char* short_name(){ return sshortname; }\
};
