#pragma once
#include "unit.hpp"




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

	this_type operator+(const this_type& other)const
	{ 
		this_type ret =*this;
		ret += other;
		return ret;
	}
	this_type operator-(const this_type& other)const
	{
		this_type ret = *this;
		ret -= other;
		return ret;
	}


	this_type& operator+=(const this_type& other){ val+=other.val; return *this; }
	this_type& operator-=(const this_type& other){ val+=other.val; return *this; }

protected:
	double val;		
};

template<class T1, class T2>
struct multi
{

};

template<class T1, class T2>
struct divide
{

};

template<class T>
struct root
{

};

template<>
struct multi<double ,double>
{
	typedef double  type;
};

template<>
struct divide<double ,double>
{
	typedef double type;
};


template<class _U1,class _U2>
struct multi< Quantity<_U1>, Quantity<_U2> >
{
	typedef BaseUnit< typename dim_plus<typename _U1::Dimension,typename _U1::Dimension>::type > unit_type;
	typedef Quantity<unit_type> type;
};

template<class _U1, class _U2>
struct divide< Quantity<_U1>, Quantity<_U2> >
{
	typedef BaseUnit< typename dim_minus<typename _U1::Dimension,typename _U2::Dimension>::type > unit_type;
	typedef Quantity<unit_type> type; 
};





template<class U1,class U2>
typename multi< Quantity<U1>,Quantity<U2> >::type operator*(const Quantity<U1>& q1, const Quantity<U2>& q2)
{
	double val =  q1.base_value() * q2.base_value();
	multi< Quantity<U1>,Quantity<U2> >::type q;
	q.value(val);
	return q;
}

template<class U1,class U2>
Quantity< typename divide<U1,U2>::type >  operator/(const Quantity<U1>& q1, const Quantity<U2>& q2)
{
	double val =  q1.base_value() * q2.base_value();
	divide< Quantity<U1>,Quantity<U2> >::type q;
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

