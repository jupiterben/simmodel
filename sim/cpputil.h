#pragma once

#define NSBEGIN(x)  namespace x {
#define NSEND }

#include <vector>
#include <algorithm>
#include <cassert>


#define FOR_INC(var, indexf, indext)  for(int var = indexf; var < indext; ++var)
#define FOR_ITR(itrT, var, itrb, itre)  for(itrT var = itrb;var!=itre;++var)


NSBEGIN(Unit)

template <class T, int Mass =0, int Len =0, int Time =0, int Charge=0, int Temp =0, int Intensity=0, int Angle=0>
class dimension
{
public:
	dimension():val(0){}
	dimension(const T& v):val(v){}

	typedef dimension<T,Mass, Len, Time, Charge, Temp, Intensity, Angle> type;

	T value()const{ return val; }

	template<int M1, int M2, int M3, int M4, int M5 ,int M6 , int M7>
	dimension<T, M1+N1, M2+N2, M3+N3, M4+N4, M5+N5, M6+N6, M7+N7> operator*(const dimension<T,Mass, Len, Time, Charge, Temp, Intensity, Angle> & other)const
	{
		dimension<T, M1+N1, M2+N2, M3+N3, M4+N4, M5+N5, M6+N6, M7+N7> retint Mass =0, int Len =0, int Time =0, int Charge=0, int Temp =0, int Intensity=0, int Angle=0(value()*other.value());
		return ret;
	}

	template<int M1, int M2, int M3, int M4, int M5 ,int M6 , int M7>
	dimension<T, -M1+N1, -M2+N2, -M3+N3, -M4+N4, -M5+N5, -M6+N6, -M7+N7> operator/(const dimension<T,M1,M2,M3,M4,M5,M6,M7>& other)const
	{
		dimension<T, -M1+N1, -M2+N2, -M3+N3, -M4+N4, -M5+N5, -M6+N6, -M7+N7> ret(value()/other.value());
		return ret;
	}

	type operator+(const type& other)const
	{
		return type(value()+other.value());
	}
	type operator-(const type& other)const
	{
		return type(value()-other.value());
	}
protected:
	T val;
};




typedef dimension<double,1,0,0,0,0,0,0> mass;
typedef dimension<double,0,1,0,0,0,0,0> length;
typedef dimension<double,0,0,1,0,0,0,0> time;
typedef dimension<double,0,0,0,1,0,0,0> charge;
typedef dimension<double,0,0,0,0,1,0,0> temperature;
typedef dimension<double,0,0,0,0,0,1,0> intensity;
typedef dimension<double,0,0,0,0,0,0,1> angle;

typedef dimension<double,0,0,0,0,0,0,0> scalar;

typedef dimension<double,0,1,-1> velocity;
typedef dimension<double,0,1,-2> acceleration;
typedef dimension<double,1,1,-1> momentum;
typedef dimension<double,1,1,-2> force;

scalar Sin(const angle& a)
{
	return sin(a.value());
}
angle Asin(const scalar& s)
{
	return asin(s.value());
}

NSEND


