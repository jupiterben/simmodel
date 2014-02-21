#pragma once

template<class T, std::size_t N>
class array
{
public:
	T elems[N];

public:
	typedef T              value_type;
	typedef T*             iterator;
	typedef const T*       const_iterator;
	typedef T&             reference;
	typedef const T&       const_reference;
	typedef std::size_t    size_type;
	//typedef std::ptrdiff_t difference_type;
	iterator        begin()       { return elems; }
	const_iterator  begin() const { return elems; }
	const_iterator cbegin() const { return elems; }

	iterator        end()       { return elems+N; }
	const_iterator  end() const { return elems+N; }
	const_iterator cend() const { return elems+N; }

	static size_type size() { return N; }
	static bool empty() { return false; }
	static size_type max_size() { return N; }
	enum { static_size = N };

	// swap (note: linear complexity)
	void swap (array<T,N>& y) {
		for (size_type i = 0; i < N; ++i)
			std::swap(elems[i],y.elems[i]);
	}

	// direct access to data (read-only)
	const T* data() const { return elems; }
	T* data() { return elems; }


	// assignment with type conversion
	template <typename T2>
		array<T,N>& operator= (const array<T2,N>& rhs) {
			std::copy(rhs.begin(),rhs.end(), begin());
			return *this;
		}

		// assign one value to all elements
		void assign (const T& value) { fill ( value ); }    // A synonym for fill
		void fill   (const T& value)
		{
			std::fill_n(begin(),size(),value);
		}

};