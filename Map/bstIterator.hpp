#ifndef BSTITERATOR_HPP
# define BSTITERATOR_HPP
# include "BstNode.hpp"
namespace ft
{

/********************************** MAP ITERATOR ***************************/
template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
struct bst_iterator 
{
	typedef typename T::value_type value_type;
	typedef Distance difference_type;
	typedef value_type *pointer;
	typedef value_type &reference;
	typedef Category iterator_category;

	public :
	bst_iterator (void) {}
	bst_iterator (T *ptr) : _itPtr(ptr) {}
	bst_iterator (const bst_iterator &a) { *this = a; }
	bst_iterator &operator=(const bst_iterator &a) { this->_itPtr = a.getPtr(); return (*this); }
	~bst_iterator (void) {}
	reference operator*(void) const { return (*this->_itPtr->_data);}
	pointer operator->(void) const { return (this->_itPtr->_data);}
	T *getPtr(void) const {return (this->_itPtr);}
	bst_iterator &operator++(void)
	{
		if (_itPtr->_right != NULL)
		{
			_itPtr = _itPtr->_right;
			while (_itPtr->_left != NULL)
				_itPtr = _itPtr->_left;
			return (*this);
		}
		else
		{
			while (_itPtr->_parent != NULL &&_itPtr->_parent->_right == _itPtr)
				_itPtr = _itPtr->_parent;
			if (_itPtr->_parent != NULL)
				_itPtr = _itPtr->_parent;
			else
			{
				while (_itPtr->_right != NULL)
					_itPtr = _itPtr->_right;
			}
			return (*this);
		}
	}
	bst_iterator operator++(int) { bst_iterator tmp = *this; ++(*this); return (tmp); }
	bst_iterator &operator--(void)
	{
		if (_itPtr->_left != NULL)
		{
			_itPtr = _itPtr->_left;
			while (_itPtr->_right != NULL)
				_itPtr = _itPtr->_right;
			return (*this);
		}
		else
		{
			while (_itPtr->_parent != NULL &&_itPtr->_parent->_left == _itPtr)
				_itPtr = _itPtr->_parent;
			if (_itPtr->_parent != NULL)
				_itPtr = _itPtr->_parent;
			else
			{
				while (_itPtr->_left != NULL)
					_itPtr = _itPtr->_left;
			}
			return (*this);
		}
	}
	bst_iterator operator--(int) { bst_iterator tmp = *this; --(*this); return (tmp); }
	template <class C, class Iter>
	friend bool operator==(const bst_iterator<C, Iter>& lhs, const bst_iterator<C, Iter>& rhs);
	template <class C, class Iter>
	friend bool operator!=(const bst_iterator<C, Iter>& lhs, const bst_iterator<C, Iter>& rhs);
	template <class C, class Iter, class Iter2>
	friend bool operator==(const bst_iterator<C, Iter>& lhs, const bst_iterator<C, Iter2>& rhs);
	template <class C, class Iter, class Iter2>
	friend bool operator!=(const bst_iterator<C, Iter>& lhs, const bst_iterator<C, Iter2>& rhs);
	
	private :
	T *_itPtr;
};

	template <class Category, class Iterator>
		bool operator==(const bst_iterator<Category, Iterator>& lhs, const bst_iterator<Category, Iterator>& rhs)
	{
		if (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub == 0)
			return (true);
		if ((rhs.getPtr()->_sub != 0 && lhs.getPtr()->_sub == 0) || (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub != 0))
			return (false);
		return (lhs.getPtr()->_data->first == rhs.getPtr()->_data->first);
	}

	template <class Category, class Iterator>
		bool operator!=(const bst_iterator<Category, Iterator>& lhs, const bst_iterator<Category, Iterator>& rhs)
	{
		if (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub == 0)
			return (false);
		if ((rhs.getPtr()->_sub != 0 && lhs.getPtr()->_sub == 0) || (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub != 0))
			return (true);
		return (lhs.getPtr()->_data->first != rhs.getPtr()->_data->first);
	}

	template <class Category, class Iterator, class Iterator2>
		bool operator==(const bst_iterator<Category, Iterator>& lhs, const bst_iterator<Category, Iterator2>& rhs) 
	{
		if (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub == 0)
			return (true);
		if ((rhs.getPtr()->_sub != 0 && lhs.getPtr()->_sub == 0) || (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub != 0))
			return (false);
		return (lhs.getPtr()->_data->first == rhs.getPtr()->_data->first);
	}
	
	template <class Category, class Iterator, class Iterator2>
		bool operator!=(const bst_iterator<Category, Iterator>& lhs, const bst_iterator<Category, Iterator2>& rhs)
	{
		if (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub == 0)
			return (false);
		if ((rhs.getPtr()->_sub != 0 && lhs.getPtr()->_sub == 0) || (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub != 0))
			return (true);
		return (lhs.getPtr()->_data->first != rhs.getPtr()->_data->first);
	}
	

template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
struct bst_iterator_const : ft::iterator<Category, T, Distance, Pointer, Reference>
{
	typedef typename T::value_type value_type;
	typedef Distance difference_type;
	typedef const value_type *pointer;
	typedef const value_type &reference;
	typedef Category iterator_category;

	public :
	bst_iterator_const (void) {}
	bst_iterator_const (const T *ptr) : _itPtr(ptr) {}
	bst_iterator_const (bst_iterator_const const &a) { *this = a; }
	bst_iterator_const (bst_iterator<Category, T, Distance, Pointer, Reference> const &a) {*this = a; }
	bst_iterator_const &operator=(const bst_iterator_const &a) { this->_itPtr = a.getPtr(); return (*this); }

	bst_iterator_const &operator=(bst_iterator<Category, T, Distance, Pointer, Reference> const &a) { this->_itPtr = a.getPtr(); return (*this); }
	~bst_iterator_const (void) {}
	reference operator*(void) const { return (*this->_itPtr->_data);}
	pointer operator->(void) const { return (this->_itPtr->_data);}
	const T *getPtr(void) const {return (this->_itPtr);}

	bst_iterator_const &operator++(void)
	{
		if (_itPtr->_right != NULL)
		{
			_itPtr = _itPtr->_right;
			while (_itPtr->_left != NULL)
				_itPtr = _itPtr->_left;
			return (*this);
		}
		else
		{
			while (_itPtr->_parent != NULL &&_itPtr->_parent->_right == _itPtr)
					_itPtr = _itPtr->_parent;
			if (_itPtr->_parent != NULL)
				_itPtr = _itPtr->_parent;
			else
			{
				while (_itPtr->_right != NULL)
					_itPtr = _itPtr->_right;
			}
			return (*this);
		}
	}
	bst_iterator_const operator++(int) { bst_iterator_const tmp = *this; ++(*this); return (tmp); }
	bst_iterator_const &operator--(void)
	{
		if (_itPtr->_left != NULL)
		{
			_itPtr = _itPtr->_left;
			while (_itPtr->_right != NULL)
				_itPtr = _itPtr->_right;
			return (*this);
		}
		else
		{
			while (_itPtr->_parent != NULL &&_itPtr->_parent->_left == _itPtr)
				_itPtr = _itPtr->_parent;
			if (_itPtr->_parent != NULL)
				_itPtr = _itPtr->_parent;
			else
			{
				while (_itPtr->_left != NULL)
					_itPtr = _itPtr->_left;
			}
			return (*this);
		}
	}
	bst_iterator_const operator--(int) { bst_iterator_const tmp = *this; --(*this); return (tmp); }
	template <class C, class Iter>
	friend bool operator==(const bst_iterator_const<C, Iter>& lhs, const bst_iterator_const<C, Iter>& rhs);
	template <class C, class Iter>
	friend bool operator!=(const bst_iterator_const<C, Iter>& lhs, const bst_iterator_const<C, Iter>& rhs);
	template <class C, class Iter>
	friend bool operator==(const bst_iterator_const<C, Iter>& lhs, const bst_iterator<C, Iter>& rhs);
	template <class C, class Iter>
	friend bool operator!=(const bst_iterator_const<C, Iter>& lhs, const bst_iterator<C, Iter>& rhs);

	private :
	const T *_itPtr;
};

	template <class Category, class Iterator>
		bool operator==(const bst_iterator_const<Category, Iterator>& lhs, const bst_iterator_const<Category, Iterator>& rhs)
	{
		if (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub == 0)
			return (true);
		if ((rhs.getPtr()->_sub != 0 && lhs.getPtr()->_sub == 0) || (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub != 0))
			return (false);
		return (lhs.getPtr()->_data->first == rhs.getPtr()->_data->first);
	}

	template <class Category, class Iterator>
		bool operator!=(const bst_iterator_const<Category, Iterator>& lhs, const bst_iterator_const<Category, Iterator>& rhs)
	{
		if (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub == 0)
			return (false);
		if ((rhs.getPtr()->_sub != 0 && lhs.getPtr()->_sub == 0) || (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub != 0))
			return (true);
		return (lhs.getPtr()->_data->first != rhs.getPtr()->_data->first);
	}

	template <class Category, class Iterator>
		bool operator==(const bst_iterator_const<Category, Iterator>& lhs, const bst_iterator<Category, Iterator>& rhs) 
	{
		if (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub == 0)
			return (true);
		if ((rhs.getPtr()->_sub != 0 && lhs.getPtr()->_sub == 0) || (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub != 0))
			return (false);
		return (lhs.getPtr()->_data->first == rhs.getPtr()->_data->first);
	}
	
	template <class Category, class Iterator>
		bool operator!=(const bst_iterator_const<Category, Iterator>& lhs, const bst_iterator<Category, Iterator>& rhs)
	{
		if (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub == 0)
			return (false);
		if ((rhs.getPtr()->_sub != 0 && lhs.getPtr()->_sub == 0) || (rhs.getPtr()->_sub == 0 && lhs.getPtr()->_sub != 0))
			return (true);
		return (lhs.getPtr()->_data->first != rhs.getPtr()->_data->first);
	}
}

#endif
