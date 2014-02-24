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
