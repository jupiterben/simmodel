#pragma once
#include "array.h"

template<class T1,class T2>
struct multi;

template<class T>
class Vector2 : public array<T,2>
{
public:
	typedef Vector2<T> this_type;

	T x()const{ return elems[0]; }
	T y()const{ return elems[1]; }

	T  length()const;

	typename multi<T,T>::type  dot(const this_type& other)
	{
		return x()*other.x() + y()*other.y();
	}

	Vector2<double> normal()const
	{
		T 
	}
	
};


template<class T>
class Point2 : public array<T,2>
{
public:
	typedef Vector2<T> VectorType;


	 
};