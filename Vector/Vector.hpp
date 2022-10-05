#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <exception>
# include <stdexcept>
# include <iostream>
# include "../utils/ft.hpp"
# include "VectorIterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public :
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T& const_pointer;
		typedef ft::vector_iterator<ft::random_access_iterator_tag, T> iterator;
		typedef ft::vector_iterator<ft::random_access_iterator_tag, const T> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;


/************************** FORME COPLIENNE **************************/
		explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc)
		{
			this->_ptr = this->_alloc.allocate(this->_capacity);
			return ;
		}

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc)
		{
			this->_ptr = this->_alloc.allocate(this->_capacity);
			for (size_t i = 0; i < n; i++)
				this->_alloc.construct(&this->_ptr[i], val);
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) : _alloc(alloc)
		{
			InputIterator it;
			size_t i = 0;
			it = first;
			while (it != last)
			{
				it++;
				i++;
			}
			this->_size = i;
			this->_capacity = i;
			this->_ptr = this->_alloc.allocate(this->_capacity);
			int j = 0;
			for (InputIterator it = first; it != last; it++, j++)
				this->_alloc.construct(&this->_ptr[j], *it);
		}
	
		vector (const vector& x) : _size(x.size()), _capacity(x.capacity()), _alloc(x.get_allocator())
		{
			this->_ptr = this->_alloc.allocate(this->_capacity);
			for (size_t i = 0; i < this->_size; i++)
				this->_alloc.construct(&this->_ptr[i], x.at(i));
			return ;
		}
	
		vector& operator= (const vector& x)
		{
			vector tmp(x);
			(*this).swap(tmp);
			return (*this);
		}

		~vector(void) 
		{
			for (size_t i = 0; i < this->_size; i++)
				this->_alloc.destroy(&this->_ptr[i]);
			this->_alloc.deallocate(this->_ptr, this->_capacity);
			return ;
		}


/************************** ITERATOR **************************/
		iterator begin() { return (iterator (&this->_ptr[0])); }
		const_iterator begin() const { return (const_iterator (&this->_ptr[0])); }
		iterator end() { return (iterator(&this->_ptr[this->_size])); }
		const_iterator end() const { return (const_iterator(&this->_ptr[this->_size])); }
		reverse_iterator rbegin() 
		{
			if (this->_size == 0)
				return (this->rend());
			return (reverse_iterator(&this->_ptr[this->_size]));
		}
		const_reverse_iterator rbegin() const
		{
			if (this->_size == 0)
				return (this->rend());
			return (const_reverse_iterator(&this->_ptr[this->_size]));
		}
		reverse_iterator rend() { return (reverse_iterator(this->begin())); }
		const_reverse_iterator rend() const { return (const_reverse_iterator(this->begin())); }


/************************** CAPACITY **************************/
		size_type size() const{ return (this->_size); }
		size_type max_size() const { return (this->_alloc.max_size()); }
		void resize (size_type n, value_type val = value_type())
		{	
			if (n >= this->_capacity)
			{
				size_type stocks = this->_size;
				size_type stockc = this->_capacity;
				pointer tmp = this->_alloc.allocate(this->_capacity);
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.construct(&tmp[i], this->_ptr[i]);
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_ptr[i]);
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				this->_capacity = n * 2;
				this->_size = n;
				this->_ptr = this->_alloc.allocate(this->_capacity);
				for (size_t i = 0; i < stocks; i++)
					this->_alloc.construct(&this->_ptr[i], tmp[i]);
				for (size_t i = stocks; i < n; i++)
					this->_alloc.construct(&this->_ptr[i], val);
				for (size_t i = 0; i < stocks; i++)
					this->_alloc.destroy(&tmp[i]);
				this->_alloc.deallocate(tmp, stockc);
			}
			else if (n < this->_capacity && n > this->_size)
			{
				for (size_t i = this->_size; i < n; i++)
						this->_alloc.construct(&this->_ptr[i], val);
				this->_size = n;
			}
			else
			{
				for (size_t i = n; i < this->_size; i++)
					this->_alloc.destroy(&this->_ptr[i]);
				this->_size = n;
			}
		}
		size_type capacity() const{ return (this->_capacity); }
		bool empty() const { return (this->_size == 0); }
		void reserve (size_type n)
		{
			if (n > this->max_size())
				throw std::length_error("vector::reserve");
			if (n > this->_capacity)
			{
				size_t stockc = this->_capacity;
				pointer tmp = this->_alloc.allocate(this->_capacity);
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.construct(&tmp[i], this->_ptr[i]);
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_ptr[i]);
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				this->_capacity = n;
				this->_ptr = this->_alloc.allocate(this->_capacity);
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.construct(&this->_ptr[i], tmp[i]);
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.destroy(&tmp[i]);
				this->_alloc.deallocate(tmp, stockc);
			}
		}


/************************** ELEMENT ACCESS **************************/
		reference operator[] (size_type n) { return (this->_ptr[n]);	}
		const_reference operator[] (size_type n) const { return (this->_ptr[n]); }
		reference at (size_type n)
		{
			if (n < 0 || n >= this->_size)
				throw std::out_of_range("");	
			return (this->_ptr[n]);
		}
		const_reference at (size_type n) const
		{
			if (n < 0 || n >= this->_size)
				throw std::out_of_range("");	
			return (this->_ptr[n]);
		}
		reference front() { return (this->_ptr[0]); }
		const_reference front() const {return (this->_ptr[0]); }
		reference back()
		{
			if (this->_size == 0)
				return (this->_ptr[this->_size]);
			return (this->_ptr[this->_size - 1]);
		}
		const_reference back() const
		{
			if (this->_size == 0)
				return (this->_ptr[this->_size]);
			return (this->_ptr[this->_size - 1]);
		}

/************************** MODIFIERS **************************/
		template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				vector tmp(first, last, this->_alloc);
				(*this).swap(tmp);
			}
		void assign (size_type n, const value_type& val)
		{
			vector tmp(n, val, this->_alloc);
			(*this).swap(tmp);
		}
		void push_back (const value_type& val)
		{
			if (this->_size >= this->_capacity)
			{
				size_t stocks = this->_size;
				size_t stockc = this->_capacity;
				pointer tmp = this->_alloc.allocate(this->_capacity);
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.construct(&tmp[i], this->_ptr[i]);
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_ptr[i]);
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				if (stockc < 1)
					this->_capacity = 1;
				else
					this->_capacity = stockc * 2;
				this->_size = stocks;
				this->_ptr = this->_alloc.allocate(this->_capacity);
				for (size_t i = 0; i < stocks; i++)
					this->_alloc.construct(&this->_ptr[i], tmp[i]);
				for (size_t i = 0; i < stocks; i++)
					this->_alloc.destroy(&tmp[i]);
				this->_alloc.deallocate(tmp, stockc);	
			}
			this->_alloc.construct(&this->_ptr[this->_size], val);
			this->_size++;
		}
		void pop_back()
		{
			if ( this->_size > 0)
			{
				this->_alloc.destroy(&this->_ptr[this->_size - 1]);
				this->_size--;
			}
		}
		iterator insert (iterator position, const value_type& val)
		{
			iterator temp = this->begin();
			size_t pos = 0;
			while (temp != position)
			{
				temp++;
				pos++;
			}
			size_t stock = this->_size - 1;
			this->resize(this->_size + 1, value_type());
			size_t newEnd = this->_size - 1;
			for (size_t i = newEnd; i > pos; i--, stock--)
			{
				if (stock >= 0)
					this->_ptr[i] = this->_ptr[stock];
				else
					this->_ptr[i] = this->_ptr[0];
			}
			this->_ptr[pos] = val;
			return (&this->_ptr[pos]);
		}
		void insert (iterator position, size_type n, const value_type& val)
		{
			size_t pos = 0;
			iterator temp = this->begin();
			while (temp != position)
			{
				temp++;
				pos++;
			}
			int stock = this->_size - 1;
			this->resize(this->_size + n, value_type());
			size_t newEnd = this->_size - 1;
			for (size_t i = newEnd; i > pos; i--, stock--)
			{
					if (stock >= 0)
						this->_ptr[i] = this->_ptr[stock];
					else
						this->_ptr[i] = this->_ptr[0];
			}
			for (size_t j = 0; j < n ; j++)
				this->_ptr[pos + j] = val;
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			size_t n = 0;
			InputIterator temp = first;
			while (temp != last)
			{
				temp++;
				n++;
			}
			size_t pos = 0;
			iterator temp2 = this->begin();
			while (temp2 != position)
			{
				temp2++;
				pos++;
			}
			int stock = this->_size - 1;
			this->resize(this->_size + n, value_type());
			size_t newEnd = this->_size - 1;
			if (this->_size > 0)
			{
				for (size_t i = newEnd; i > pos; i--, stock--)
				{
					if (stock >= 0)
						this->_ptr[i] = this->_ptr[stock];
					else
						this->_ptr[i] = this->_ptr[0];
				}
			}
			for (size_t j = 0; first != last; first++, j++) 
				this->_ptr[pos + j] = *first;
		}
		iterator erase (iterator position)
		{
			vector tmp;

			int i = 0;
			iterator pos = begin();
			while (pos != position)
			{
					pos++;
					i++;
			}
			for (iterator it = begin(); it != pos; it++)
				tmp.push_back(*it);
			for (size_t j = i + 1; j < this->_size; j++)
				tmp.push_back(this->_ptr[j]);
			(*this).swap(tmp);
			return (iterator(&this->_ptr[i]));
		}
		iterator erase (iterator first, iterator last)
		{
			vector tmp;

			int i = 0;
			iterator pos = begin();
			while (pos != first)
			{
					pos++;
					i++;
			}
			for (iterator it = begin(); it != first; it++)
				tmp.push_back(*it);
			for (iterator it = last; it != end(); it++)
				tmp.push_back(*it);
			(*this).swap(tmp);
			return (iterator(&this->_ptr[i]));
			
		}
		void swap (vector& x)
		{
			size_type sizeTmp = x._size;
			size_type capacityTmp = x._capacity;
			value_type *ptrTmp = x._ptr;
			allocator_type allocTmp = x._alloc;
		
			x._size = this->_size;
			this->_size = sizeTmp;
			x._capacity = this->_capacity;
			this->_capacity = capacityTmp;
			x._ptr = this->_ptr;
			this->_ptr = ptrTmp;
			x._alloc = this->_alloc;
			this->_alloc = allocTmp;

		}
		void clear()
		{
			for (size_t i = 0; i < this->_size; i++)
				this->_alloc.destroy(&this->_ptr[i]);
			this->_size = 0;
		}

/************************** ALLOCATOR **************************/
		allocator_type get_allocator() const { return (this->_alloc); }


/************** NON-MEMBER FUNCTION OVERLOADS *******************/
		template <class U, class A>
			friend bool operator==(const vector<U, A>& lhs, const vector<U, A>& rhs);
		template <class U, class A>
			friend bool operator!=(const vector<U, A>& lhs, const vector<U, A>& rhs);
		template <class U, class A>
			friend bool operator>=(const vector<U, A>& lhs, const vector<U, A>& rhs);
		template <class U, class A>
			friend bool operator<=(const vector<U, A>& lhs, const vector<U, A>& rhs);
		template <class U, class A>
			friend bool operator>(const vector<U, A>& lhs, const vector<U, A>& rhs);
		template <class U, class A>
			friend bool operator<(const vector<U, A>& lhs, const vector<U, A>& rhs);
		template <class U, class A>
			void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
		
		private :
		size_type _size;
		size_type _capacity;
		value_type *_ptr;
		allocator_type _alloc;

};

/************** NON-MEMBER FUNCTION OVERLOADS (implementation) *******************/
		template <class T, class Alloc>
		bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			size_t i = 0;
			if (lhs.size() != rhs.size())
				return (false);
			for (typename vector<T>::const_iterator it = lhs.begin(); it < lhs.end(); it++)
			{
				if (*it != rhs.at(i))
					return (false);				
				i++;
			}
			return (true);
		}
		template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs == rhs)); }
		template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs < lhs)); }
		template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return(rhs < lhs); }
		template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return(!(lhs < rhs)); }
		template<class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); return ; }

}

#endif
