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

//
template
<
	template<int N1, int N2,int N3,int N4,int N5,int N6,int N7> class D1,
	template<int N1, int N2,int N3,int N4,int N5,int N6,int N7> class D2
>
struct dim_plus
{
	typedef dimension<D1::N1 + D2::N1
					,D1::N2 + D2::N2
					,D1::N3 + D2::N3
					,D1::N4 + D2::N4
					,D1::N5 + D2::N5
					,D1::N6 + D2::N6
					,D1::N7 + D2::N7> type;
};

////////////////////////////////////////////////////////////////////////////
//template
//<
//template<int N1, int N2,int N3,int N4,int N5,int N6,int N7> class D1,
//template<int N1, int N2,int N3,int N4,int N5,int N6,int N7> class D2
//>
//struct dim_minus
//{
//	typedef dimension<D1::N1 - D2::N1
//		,D1::N2 - D2::N2
//		,D1::N3 - D2::N3
//		,D1::N4 - D2::N4
//		,D1::N5 - D2::N5
//		,D1::N6 - D2::N6
//		,D1::N7 - D2::N7> type;
//};



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
	quantity():val(0){}
	quantity(T d):val(d){ }
	T value()const{ return val; }
protected:
	T val;
};

template <typename T, typename D>
quantity<T,D>
	operator+(quantity<T,D> x, quantity<T,D> y)
{
	return quantity<T,D>(x.value() + y.value());
}

template <typename T, typename D>
quantity<T,D>
	operator-(quantity<T,D> x, quantity<T,D> y)
{
	return quantity<T,D>(x.value() - y.value());
}

template<class T, typename D1, typename D2>
quantity<T, typename dim_plus<typename D1,typename D2>::type > operator*(quantity<T,D1> x, quantity<T,D2> y)
{
	return quantity<T, dim_plus<D1,D2>::type > (x.value()*y.value());
}

//template<class T, class D1, class D2>
//quantity<T, typename dim_minus<D1,D2>::type > operator/(quantity<T,D1> x, quantity<T,D2> y)
//{
//	return quantity<T,dim_minus<D1,D2>::type > (x.value()/y.value());
//}



NSEND


