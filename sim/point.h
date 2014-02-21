#pragma once


template<class T>
class Vector2 : public array<T,2>
{
public:
	T x()const{}
	T y()const{}

	T  length()const;

	Vector2<T> dot();
	Vector2<T> cross();
};


