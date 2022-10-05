#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft
{

/********************************** VECTOR ITERATOR ***************************/
template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
struct vector_iterator
{
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
	typedef Category iterator_category;

	public :
	vector_iterator (void) {}
	vector_iterator (pointer ptr) : _itPtr(ptr) {}
	vector_iterator (const vector_iterator &a) { *this = a; }
	vector_iterator &operator=(const vector_iterator &a) { this->_itPtr = a.getPtr(); return (*this); }
	~vector_iterator (void) {}
	pointer base(void) const { return (this->_itPtr); }
	reference operator*(void) const { return (*_itPtr);}
	pointer operator->(void) const { return (_itPtr);}
	vector_iterator &operator=(value_type v) { this->_itPtr = v; return (*this); }
	vector_iterator &operator++(void) { _itPtr++; return (*this); }
	vector_iterator operator++(int) { vector_iterator tmp = *this; ++(*this); return (tmp); }
	vector_iterator &operator--(void) { _itPtr--; return (*this); }
	vector_iterator operator--(int) { vector_iterator tmp = *this; --(*this); return (tmp); }
	vector_iterator operator+(difference_type rhs) const { return (_itPtr + rhs); }
	vector_iterator operator-(difference_type rhs) const { return (_itPtr - rhs); }
	vector_iterator& operator+=(difference_type rhs) { _itPtr += rhs; return *this; }
	vector_iterator& operator-=(difference_type rhs) { _itPtr -= rhs; return *this; }
	T &operator[](difference_type rhs) const { return (_itPtr[rhs]); }
	void swap(pointer a, pointer b) { pointer tmp = a._itPtr; a._itPtr = b._itPtr; b._itPtr = tmp; }
	operator vector_iterator<Category, const T> (void) const { return (vector_iterator<Category, const T>(this->_itPtr));}
	template <class C, class Iter>
	friend bool operator==(const vector_iterator<C, Iter>& lhs, const vector_iterator<C, Iter>& rhs);
	template <class C, class Iter>
	friend bool operator!=(const vector_iterator<C, Iter>& lhs, const vector_iterator<C, Iter>& rhs);
	template <class C, class Iter>
	friend bool operator>=(const vector_iterator<C, Iter>& lhs, const vector_iterator<C, Iter>& rhs);
	template <class C, class Iter>
	friend bool operator<=(const vector_iterator<C, Iter>& lhs, const vector_iterator<C, Iter>& rhs);
	template <class C, class Iter>
	friend bool operator>(const vector_iterator<C, Iter>& lhs, const vector_iterator<C, Iter>& rhs);
	template <class C, class Iter>
	friend bool operator<(const vector_iterator<C, Iter>& lhs, const vector_iterator<C, Iter>& rhs);
	template <class C, class Iter, class Iter2>
	friend bool operator==(const vector_iterator<C, Iter>& lhs, const vector_iterator<C, Iter2>& rhs);
	template <class C, class Iter, class Iter2>
	friend bool operator!=(const vector_iterator<C, Iter>& lhs, const vector_iterator<C, Iter2>& rhs);
	template <class C, class Iter, class Iter2>
	friend bool operator>=(const vector_iterator<C, Iter>& lhs, const vector_iterator<C, Iter2>& rhs);
	template <class C, class Iter, class Iter2>
	friend bool operator<=(const vector_iterator<C, Iter>& lhs, const vector_iterator<C, Iter2>& rhs);
	template <class C, class Iter, class Iter2>
	friend bool operator>(const vector_iterator<C, Iter>& lhs, const vector_iterator<C, Iter2>& rhs);
	template <class C, class Iter, class Iter2>
	friend bool operator<(const vector_iterator<C, Iter>& lhs, const vector_iterator<C, Iter2>& rhs);
	template <class C, class Iter>
	friend typename vector_iterator<C,Iter>::difference_type operator+(const vector_iterator<C,Iter> lhs, const vector_iterator<C,Iter> rhs);
	template <class C, class Iter>
	friend typename vector_iterator<C,Iter>::difference_type operator-(const vector_iterator<C,Iter> lhs, const vector_iterator<C,Iter> rhs);
	template <class C, class Iter, class Iter2>
	friend typename vector_iterator<C,Iter>::difference_type operator+(const vector_iterator<C,Iter> lhs, const vector_iterator<C,Iter2> rhs);
	template <class C, class Iter, class Iter2>
	friend typename vector_iterator<C,Iter>::difference_type operator-(const vector_iterator<C,Iter> lhs, const vector_iterator<C,Iter2> rhs);
	template <class C, class Iter>
	friend vector_iterator<C,Iter> operator+(const typename vector_iterator<C,Iter>::difference_type lhs, const vector_iterator<C,Iter> rhs);
	template <class C, class Iter>
	friend vector_iterator<C,Iter> operator-(const typename vector_iterator<C,Iter>::difference_type lhs, const vector_iterator<C,Iter> rhs);

	private :
	pointer getPtr(void) const {return (this->_itPtr);}
	pointer _itPtr;
};

	template <class Category, class Iterator>
	bool operator==(const vector_iterator<Category, Iterator>& lhs, const vector_iterator<Category, Iterator>& rhs) { return (lhs._itPtr == rhs._itPtr); }
	template <class Category, class Iterator>
	bool operator!=(const vector_iterator<Category, Iterator>& lhs, const vector_iterator<Category, Iterator>& rhs) { return (lhs._itPtr != rhs._itPtr); }
	template <class Category, class Iterator>
	bool operator>=(const vector_iterator<Category, Iterator>& lhs, const vector_iterator<Category, Iterator>& rhs) { return (lhs._itPtr >= rhs._itPtr); }
	template <class Category, class Iterator>
	bool operator<=(const vector_iterator<Category, Iterator>& lhs, const vector_iterator<Category, Iterator>& rhs) { return (lhs._itPtr <= rhs._itPtr); }
	template <class Category, class Iterator>
	bool operator>(const vector_iterator<Category, Iterator>& lhs, const vector_iterator<Category, Iterator>& rhs) { return (lhs._itPtr > rhs._itPtr); }
	template <class Category, class Iterator>
	bool operator<(const vector_iterator<Category, Iterator>& lhs, const vector_iterator<Category, Iterator>& rhs) { return (lhs._itPtr < rhs._itPtr); }
	template <class Category, class Iterator, class Iterator2>
	bool operator==(const vector_iterator<Category, Iterator>& lhs, const vector_iterator<Category, Iterator2>& rhs) { return (lhs._itPtr == rhs._itPtr); }
	template <class Category, class Iterator, class Iterator2>
	bool operator!=(const vector_iterator<Category, Iterator>& lhs, const vector_iterator<Category, Iterator2>& rhs) { return (lhs._itPtr != rhs._itPtr); }
	template <class Category, class Iterator, class Iterator2>
	bool operator>=(const vector_iterator<Category, Iterator>& lhs, const vector_iterator<Category, Iterator2>& rhs) { return (lhs._itPtr >= rhs._itPtr); }
	template <class Category, class Iterator, class Iterator2>
	bool operator<=(const vector_iterator<Category, Iterator>& lhs, const vector_iterator<Category, Iterator2>& rhs) { return (lhs._itPtr <= rhs._itPtr); }
	template <class Category, class Iterator, class Iterator2>
	bool operator>(const vector_iterator<Category, Iterator>& lhs, const vector_iterator<Category, Iterator2>& rhs) { return (lhs._itPtr > rhs._itPtr); }
	template <class Category, class Iterator, class Iterator2>
	bool operator<(const vector_iterator<Category, Iterator>& lhs, const vector_iterator<Category, Iterator2>& rhs) { return (lhs._itPtr < rhs._itPtr); }
	template <class Category, class T>
	typename vector_iterator<Category, T>::difference_type operator+(const vector_iterator<Category,T> lhs, const vector_iterator<Category,T> rhs) { return (lhs.base() + rhs.base()); }
	template<class Category, class T>
	typename vector_iterator<Category, T>::difference_type operator-(const vector_iterator<Category,T> lhs, const vector_iterator<Category,T> rhs) { return (lhs.base() - rhs.base()); }
	template <class Category, class T, class T2>
	typename vector_iterator<Category, T>::difference_type operator+(const vector_iterator<Category,T> lhs, const vector_iterator<Category,T2> rhs) { return (lhs.base() + rhs.base()); }
	template<class Category, class T, class T2>
	typename vector_iterator<Category, T>::difference_type operator-(const vector_iterator<Category,T> lhs, const vector_iterator<Category,T2> rhs) { return (lhs.base() - rhs.base()); }
	template <class Category, class T>
	vector_iterator<Category, T> operator+(const typename vector_iterator<Category,T>::difference_type lhs, const vector_iterator<Category,T> rhs) { return (rhs + lhs); }
	template<class Category, class T>
	vector_iterator<Category, T> operator-(const typename vector_iterator<Category,T>::difference_type lhs, const vector_iterator<Category,T> rhs) { return (rhs - lhs); }
}

#endif
