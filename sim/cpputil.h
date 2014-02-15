#pragma once

#define NSBEGIN(x)  namespace x {
#define NSEND }

#include <vector>
#include <algorithm>
#include <cassert>


#define FOR_INC(var, indexf, indext)  for(int var = indexf; var < indext; ++var)
#define FOR_ITR(itrT, var, itrb, itre)  for(itrT var = itrb;var!=itre;++var)


NSBEGIN(Unit)
template <int N1, int N2, int N3, int N4, int N5, int N6, int N7>
class dimension
{

};



typedef dimension<1,0,0,0,0,0,0> mass;
typedef dimension<0,1,0,0,0,0,0> length;
typedef dimension<0,0,1,0,0,0,0> time;
typedef dimension<0,0,0,1,0,0,0> charge;
typedef dimension<0,0,0,0,1,0,0> temperature;
typedef dimension<0,0,0,0,0,1,0> intensity;
typedef dimension<0,0,0,0,0,0,1> angle;

typedef dimension<0,0,0,0,0,0,0> scalar;

template <typename T, typename D>
class quantity
{
public:
	T value()const{ return val; }
protected:
	T val;
};

template <class T, class D>
quantity<T,D>
	operator+(quantity<T,D> x, quantity<T,D> y)
{
	return quantity<T,D>(x.value() + y.value());
}

template <class T, class D>
quantity<T,D>
	operator-(quantity<T,D> x, quantity<T,D> y)
{
	return quantity<T,D>(x.value() - y.value());
}


NSEND


