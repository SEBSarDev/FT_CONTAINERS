#ifndef FT_HPP
# define FT_HPP
# include <memory>
# include <exception>
# include <stdexcept>
# include <iostream>

namespace ft
{
	/*************************** PAIR *****************************/
	template <class T1, class T2>
		struct pair
		{
			public:
			typedef T1 first_type;
			typedef T2 second_type;

			pair(void) : first(first_type()), second(second_type()) {}
			template<class U, class V>
				pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
			pair (const first_type& a, const second_type& b) : first(a), second(b) {}
			pair& operator= (const pair& pr) { this->first = pr.first; this->second = pr.second; return (*this);}
			void swap (pair& pr)
			{
				first_type tmpf = pr.first;
				second_type tmpS = pr.second;
				pr.first = this->first;
				pr.second = this->second;
				this->first = tmpf;
				this->second = tmpS;
			}
			template <class t1, class t2>
				friend bool operator== (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs);
			template <class t1, class t2>
				friend bool operator!= (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs);
			template <class t1, class t2>
				friend bool operator<  (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs);
			template <class t1, class t2>
				friend bool operator<= (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs);
			template <class t1, class t2>
				friend bool operator>  (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs);
			template <class t1, class t2>
				friend bool operator>= (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs);
			
			first_type first;
			second_type second;
		};
	template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first==rhs.first && lhs.second==rhs.second; }
	template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs==rhs); }
	template <class T1, class T2>
		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }
	template <class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(rhs<lhs); }
	template <class T1, class T2>
		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return rhs<lhs; }
	template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs<rhs); }

	/************************* MAKE PAIR ****************************/
	template <class T1,class T2>
		pair<T1,T2> make_pair (T1 x, T2 y)
		{
			return ( pair<T1,T2>(x,y) );
		}

	/********************** BINARY_FUNCTION ************************/
	template <class Arg1, class Arg2, class Result>
		struct binary_function
		{
			typedef Arg1 first_argument_type;
			typedef Arg2 second_argument_type;
			typedef Result result_type;
		};
	
	/********************** ENABLE_IF ************************/
	template<bool B, class T = void>
		struct enable_if {};
	
	template<class T>
		struct enable_if<true, T> { typedef T type; };
	
	/********************* IS_INTEGRAL ***********************/
	template<class T>
		struct is_integral { static const bool value = false; };
	template<>
		struct is_integral<bool> { static const bool value = true; };
	template<>
		struct is_integral<char> { static const bool value = true; };
	template<>
		struct is_integral<wchar_t> { static const bool value = true; };
	template<>
		struct is_integral<signed char> { static const bool value = true; };
	template<>
		struct is_integral<short int> { static const bool value = true; };
	template<>
		struct is_integral<int> { static const bool value = true; };
	template<>
		struct is_integral<long int> { static const bool value = true; };
	template<>
		struct is_integral<long long int> { static const bool value = true; };
	template<>
		struct is_integral<unsigned char> { static const bool value = true; };
	template<>
		struct is_integral<unsigned short int> { static const bool value = true; };
	template<>
		struct is_integral<unsigned int> { static const bool value = true; };
	template<>
		struct is_integral<unsigned long int> { static const bool value = true; };
	template<>
		struct is_integral<unsigned long long int> { static const bool value = true; };

	/*************************** EQUAL *****************************/
	template <class InputIterator1, class InputIterator2>
		bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
		{
			while (first1!=last1)
			{
				if (!(*first1 == *first2))
					return false;
				++first1; ++first2;
			}
			return true;
		}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
		bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
		{
			while (first1!=last1)
			{
				if (!pred(*first1,*first2))
					return false;
				++first1; ++first2;
			}
			return true;
		}

	/********************* LEXICOGRAPHICAL_COMPARE *****************/
	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
		{
			while (first1!=last1)
			{
				if (first2==last2 || *first2<*first1)
					return (false);
				else if (*first1<*first2)
					return (true);
				++first1; ++first2;
			}
			return (first2!=last2);
		}
	template <class InputIterator1, class InputIterator2, class Compare>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
		{
			while (first1!=last1)
			{
				if (first2 == last2 || comp(*first1, *first2) == false)
					return (false);
				++first1; ++first2;
			}
			return (first2!=last2);
		}


	/******************************** ITERATOR ****************************/
	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
		struct iterator
	{
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};
	
	/******************************** ITERATOR_TAG ****************************/
	struct random_access_iterator_tag {};
	struct bidirectionnal_iterator_tag {};

	/******************************** ITERATOR_TRAITS ****************************/
	template <class Iterator>
		class iterator_traits
		{
			public :
			typedef typename Iterator::difference_type difference_type;
			typedef typename Iterator::value_type value_type;
			typedef typename Iterator::pointer pointer;
			typedef typename Iterator::reference reference;
			typedef typename Iterator::iterator_category iterator_category;
		};

	template <class T>
		class iterator_traits<T*>
		{
			public :
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef ft::random_access_iterator_tag iterator_category;
		};

	template <class T>
		class iterator_traits<const T*>
		{
			public :
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef const T* pointer;
			typedef const T& reference;
			typedef ft::random_access_iterator_tag iterator_category;
		};

/******************************** REVERSE_ITERATOR *************************************/
	template <class Iterator>
		class reverse_iterator
		{
			typedef Iterator iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
			typedef typename iterator_traits<Iterator>::value_type value_type;
			typedef typename iterator_traits<Iterator>::difference_type difference_type;
			typedef typename iterator_traits<Iterator>::pointer pointer;
			typedef typename iterator_traits<Iterator>::reference reference;

			public :
			reverse_iterator() : _revIt(0) {return ;}
			explicit reverse_iterator (iterator_type it) : _revIt(--it) { return ; }
			template <class Iter>
				reverse_iterator (const reverse_iterator<Iter>& rev_it)
				{
					this->_revIt = rev_it.base();
					this->_revIt--;
				}
			iterator_type base() const
			{
				iterator_type copy = this->_revIt;
				copy++;
				return (copy);
			}
			reference operator*() const
			{
					iterator_type copy = this->base();
				   	copy--;
				   	return (*copy);
			}
			reverse_iterator operator+(difference_type n) const
			{
					return reverse_iterator(base() - n);
			}
			reverse_iterator &operator++(void)
			{
					this->_revIt--;
					return (*this);
			}
			reverse_iterator operator++(int)
			{
					reverse_iterator tmp = *this;
					this->_revIt--;
					return (tmp);
			}
			reverse_iterator& operator+=(difference_type n)
			{
				int i = 0;
				while (i < n)
				{
					this->_revIt--;
					i++;
				}
				return *this;
			}
			reverse_iterator operator-(difference_type n) const
			{
					return reverse_iterator(base() + n);
			}
			reverse_iterator &operator--(void)
			{
					_revIt++;
					return (*this);
			}
			reverse_iterator operator--(int)
			{
					reverse_iterator tmp = *this;
					this->_revIt++;
					return (tmp);
			}
	        reverse_iterator& operator-=(difference_type n)
			{
				int i = 0;
				while (i < n )
				{
					_revIt++;
					i++;
				}
				return *this;
			}
			pointer operator->(void) const
			{
					return (&(*_revIt));
			}
			reference operator[](difference_type n) const
			{
				
				return (this->base()[-n-1]);
			}

			template <class Iter>
				friend bool operator!=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
			template <class Iter>
				friend bool operator==(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
			template <class Iter>
				friend bool operator>=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
			template <class Iter>
				friend bool operator<=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
			template <class Iter>
				friend bool operator>(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
			template <class Iter>
				friend bool operator<(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
			template <class Iter>
				friend typename reverse_iterator<Iter>::difference_type operator+(const reverse_iterator<Iter> lhs, const reverse_iterator<Iter> rhs);
			template <class Iter>
				friend typename reverse_iterator<Iter>::difference_type operator-(const reverse_iterator<Iter> lhs, const reverse_iterator<Iter> rhs);
			
			template <class Iter, class Iter2>
				friend bool operator!=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter2>& rhs);
			template <class Iter, class Iter2>
				friend bool operator==(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter2>& rhs);
			template <class Iter, class Iter2>
				friend bool operator>=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter2>& rhs);
			template <class Iter, class Iter2>
				friend bool operator<=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter2>& rhs);
			template <class Iter, class Iter2>
				friend bool operator>(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter2>& rhs);
			template <class Iter, class Iter2>
				friend bool operator<(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter2>& rhs);
			template <class Iter, class Iter2>
				friend typename reverse_iterator<Iter>::difference_type operator+(const reverse_iterator<Iter> lhs, const reverse_iterator<Iter2> rhs);
			template <class Iter, class Iter2>
				friend typename reverse_iterator<Iter>::difference_type operator-(const reverse_iterator<Iter> lhs, const reverse_iterator<Iter2> rhs);
			template <class Iter>
				friend reverse_iterator<Iter> operator+(const typename reverse_iterator<Iter>::difference_type lhs, const reverse_iterator<Iter> rhs);
			template <class Iter>
				friend reverse_iterator<Iter> operator-(const typename reverse_iterator<Iter>::difference_type lhs, const reverse_iterator<Iter> rhs);


		
			private :
			iterator_type _revIt;
		};

	template <class Iterator>
		bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); }
	template <class Iterator>
		bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }
	template <class Iterator>
		bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); }
	template <class Iterator>
		bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); }
	template <class Iterator>
		bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); }
	template <class Iterator>
		bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() < rhs.base()); }
	template<class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator+(const reverse_iterator<Iterator> lhs, const reverse_iterator<Iterator> rhs) { return (lhs.base() + rhs.base()); }
	template<class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> lhs, const reverse_iterator<Iterator> rhs) { return (rhs.base() - lhs.base()); }

	template <class Iterator, class Iterator2>
		bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() == rhs.base()); }
	template <class Iterator, class Iterator2>
		bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() != rhs.base()); }
	template <class Iterator, class Iterator2>
		bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() >= rhs.base()); }
	template <class Iterator, class Iterator2>
		bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() <= rhs.base()); }
	template <class Iterator, class Iterator2>
		bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() > rhs.base()); }
	template <class Iterator, class Iterator2>
		bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() < rhs.base()); }
	template<class Iterator, class Iterator2>
		typename reverse_iterator<Iterator>::difference_type operator+(const reverse_iterator<Iterator> lhs, const reverse_iterator<Iterator2> rhs) { return (lhs.base() + rhs.base()); }
	template<class Iterator, class Iterator2>
		typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> lhs, const reverse_iterator<Iterator2> rhs) { return (rhs.base() - lhs.base()); }
	template <class T>
		reverse_iterator<T> operator+(const typename reverse_iterator<T>::difference_type lhs, const reverse_iterator<T> rhs) { return (rhs + lhs); }
	template<class T>
		reverse_iterator<T> operator-(const typename reverse_iterator<T>::difference_type lhs, const reverse_iterator<T> rhs) { return (rhs - lhs); }
};

#endif
