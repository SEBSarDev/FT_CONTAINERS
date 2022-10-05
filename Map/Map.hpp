#ifndef MAP_HPP
# define MAP_HPP
# include "../utils/ft.hpp"
# include "bstIterator.hpp"
# include "Bst.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public :
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const key_type,mapped_type> value_type;
		typedef Compare key_compare;
			class value_compare : ft::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected :
				Compare comp;
				value_compare (Compare c) : comp(c) {}
				public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
			};
		typedef Alloc allocator_type;
		typedef typename Alloc::template rebind<ft::BstNode<T> >::other allocator_node;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef typename ft::BinarySearchTree<value_type, key_compare, allocator_type>::iterator iterator;
		typedef typename ft::BinarySearchTree<value_type, key_compare, allocator_type>::const_iterator const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

/************************** FORME COPLIENNE **************************/
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp) { this->_tree.setCompare(comp); this->setEmptyPair();}
		template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _comp(comp)
			{
				this->_tree.setCompare(comp);
				for (; first != last; first++)
					this->_tree.addValeur(ft::make_pair(first->first, first->second), this->_tree.getRoot());	
				this->setEmptyPair();
			}
		map (const map& x) : _alloc(x.get_allocator()), _comp(x.key_comp())
		{
				this->_tree.setCompare(_comp);
				for (const_iterator beg = x.begin(); beg != x.end(); beg++)
					this->_tree.addValeur(*beg.getPtr()->_data, this->_tree.getRoot());
				this->setEmptyPair();
		}
		~map(){ }
		map& operator= (const map& x)
		{
			this->clear();
			this->_alloc = x.get_allocator();
			this->_comp = x.key_comp();
			this->_tree.setCompare(_comp);
			for (const_iterator beg = x.begin(); beg != x.end(); beg++)
				this->_tree.addValeur(*beg.getPtr()->_data, this->_tree.getRoot());
			this->setEmptyPair();
			return (*this);
		}

/************************** ITERATOR **************************/

		iterator begin()
		{
				iterator it(this->_tree.getRbegin());
				it++;
				return (it);
		}

		const_iterator begin() const
		{
				const_iterator it(this->_tree.getRbegin());
				it++;
				return (it);
		}
		iterator end() { return (iterator(this->_tree.getEnd())); }
		const_iterator end() const { return (const_iterator(this->_tree.getEnd())); }
		reverse_iterator rbegin() { return (reverse_iterator (this->end())); }
		const_reverse_iterator rbegin() const { return (const_reverse_iterator (this->end())); }
		reverse_iterator rend() { iterator it(this->_tree.getRbegin()); return (reverse_iterator (it)); }
		const_reverse_iterator rend() const { const_iterator it(this->_tree.getRbegin()); return (const_reverse_iterator (it)); }

/************************** CAPACITY  **************************/
		bool empty() const
		{
			if (this->_tree.getSize() == 0)
				return (true);
			else
				return (false);
		}
		size_type size() const { return (this->_tree.getSize()); }
		size_type max_size() const {return (allocator_node().max_size()); }

/************************** ELEMENT ACCESS **************************/
		mapped_type& operator[] (const key_type& k)
		{
			return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
		}

/************************** MODIFIERS **************************/
		pair<iterator,bool> insert (const value_type& val)
		{
			ft::BstNode<value_type> *tmp;
			if (this->_tree.getSize() == 0)
				tmp = NULL;
			else
				tmp = this->_tree.getRoot();
			while (tmp != NULL && tmp->_data != NULL)
			{
				if (this->_comp(val.first, tmp->_data->first) == false
						&& this->_comp(tmp->_data->first, val.first) == false && tmp->_sub != 0)
					return (ft::make_pair(iterator (tmp), false));
				if (this->_comp(val.first, tmp->_data->first) == false)
						tmp = tmp->_right;
				else
						tmp = tmp->_left;
			}
			this->_tree.addValeur(val, this->_tree.getRoot());
			tmp = this->_tree.getRoot();
			while (tmp != NULL && tmp->_sub != 0)
			{
				if (this->_comp(val.first, tmp->_data->first) == false
						&& this->_comp(tmp->_data->first, val.first) == false)
					return (ft::make_pair(iterator (tmp), true));
				if (this->_comp(val.first, tmp->_data->first) == false)
						tmp = tmp->_right;
				else
						tmp = tmp->_left;
			}
			return (ft::make_pair(iterator (tmp), true));
		}
		iterator insert (iterator position, const value_type& val)
		{
			this->insert(val);
			ft::BstNode<value_type> *tmp = this->_tree.find(val);
			if (iterator(tmp) == position)
					return (position);
			return (iterator(tmp));
		}
		template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				for (; first != last; first++)
					this->_tree.addValeur(ft::make_pair(first->first, first->second), this->_tree.getRoot());	
			}
		void erase (iterator position) { this->_tree.removeOne(position.getPtr()); }
		size_type erase (const key_type& k)
		{
			iterator it = find(k);
			if (it == this->end())
				return (0);
			else
				this->_tree.removeOne(it.getPtr());
			return (1);
		}
		void erase (iterator first, iterator last)
		{
			iterator stock = first;
			while (first != last)
			{
				stock++;
				this->_tree.removeOne(first.getPtr());
				first = stock;
			}
		}
		void swap (map& x)
		{
			size_t sizeTmp = x.size();
			ft::BstNode<value_type> *ptrTmp = x._tree.getRoot();
			ft::BstNode<value_type> *begTmp = x._tree.getRbegin();
			ft::BstNode<value_type> *endTmp = x._tree.getEnd();
			
			x._tree.setSize(this->size());
			x._tree.setRoot(this->_tree.getRoot());
			x._tree.setBeg(this->_tree.getRbegin());
			x._tree.setEnd(this->_tree.getEnd());
			this->_tree.setSize(sizeTmp);
			this->_tree.setRoot(ptrTmp);
			this->_tree.setBeg(begTmp);
			this->_tree.setEnd(endTmp);
		}
		void clear() { this->_tree.removeAll(this->_tree.getRoot()); }

	
/************************** OBSERVERS **************************/
		key_compare key_comp() const { return (this->_comp); }
		value_compare value_comp() const { return (value_compare(this->_comp)); }

/************************** OPERATIONS **************************/
		iterator find (const key_type& k)
		{
			return (iterator(this->_tree.find(ft::make_pair(k, mapped_type()))));
		}
		const_iterator find (const key_type& k) const
		{
			const ft::pair<key_type, mapped_type> mypair(k, mapped_type());
			return (const_iterator(this->_tree.find(mypair)));
		}
		size_type count (const key_type& k) const
		{
			const_iterator it = this->begin();
			while (it != this->end())
			{
				if (this->_comp(it->first, k) == false
						&& this->_comp(k, it->first) == false)
					break;
				it++;
			}
			if (it == this->end())
					return (0);
			return (1);
		}
		iterator lower_bound (const key_type& k)
		{
			iterator it = this->begin();
			while (it != this->end())
			{
				if (this->_comp(it->first, k) == false)
					break ;
				it++;
			}
			return (it);
		}
		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator it = this->begin();
			while (it != this->end())
			{
				if (this->_comp(it->first, k) == false)
					break ;
				it++;
			}
			return (it);
		}
		iterator upper_bound (const key_type& k)
		{
			iterator it = this->begin();
			while (it != this->end())
			{
				if (this->_comp(it->first, k) == false)
					break ;
				it++;
			}
			if (this->_comp(k, it->first) == false)
				it++;
			return (it);
		}
		const_iterator upper_bound (const key_type& k) const
		{
			const_iterator it = this->begin();
			while (it != this->end())
			{
				if (this->_comp(it->first, k) == false)
					break ;
				it++;
			}
			if (this->_comp(k, it->first) == false)
				it++;
			return (it);
		}
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			const_iterator low = this->lower_bound(k);
			const_iterator up = this->upper_bound(k);
			ft::pair<const_iterator, const_iterator> ret(low, up);
			return (ret);
		}
		pair<iterator,iterator> equal_range (const key_type& k)
		{
			ft::pair<iterator, iterator> ret(this->lower_bound(k), this->upper_bound(k));
			return (ret);
		}

/************************** ALLOCATOR **************************/
		allocator_type get_allocator() const { return (this->_alloc); }

/************************** NON-MEMBER FUNCTIONS **************************/
		template <class K, class U, class C, class A>
			friend bool operator== ( const map<K,U,C,A>& lhs, const map<K,U,C,A>& rhs );
		template <class K, class U, class C, class A>
			friend bool operator!= ( const map<K,U,C,A>& lhs, const map<K,U,C,A>& rhs );
		template <class K, class U, class C, class A>
			friend bool operator<  ( const map<K,U,C,A>& lhs, const map<K,U,C,A>& rhs );
		template <class K, class U, class C, class A>
			friend bool operator<= ( const map<K,U,C,A>& lhs, const map<K,U,C,A>& rhs );
		template <class K, class U, class C, class A>
			friend bool operator>  ( const map<K,U,C,A>& lhs, const map<K,U,C,A>& rhs );
		template <class K, class U, class C, class A>
			friend bool operator>= ( const map<K,U,C,A>& lhs, const map<K,U,C,A>& rhs );
		template <class K, class U, class C, class A>
			friend void swap (map<K,U,C,A>& x, map<K,U,C,A>& y);

		private :
		allocator_type _alloc;
		key_compare _comp;
		ft::BinarySearchTree<value_type, key_compare, allocator_type> _tree;
		void setEmptyPair(void)
		{
			ft::pair<key_type, mapped_type> mypair;
			mypair = ft::make_pair(key_type(), mapped_type());
			if (this->_tree.getRbegin()->_data == NULL)
			{
				this->_tree.getRbegin()->_data = this->_alloc.allocate(1);
				this->_alloc.construct(this->_tree.getRbegin()->_data, mypair);
			}
			if (this->_tree.getEnd()->_data == NULL)
			{
				this->_tree.getEnd()->_data = this->_alloc.allocate(1);
				this->_alloc.construct(this->_tree.getEnd()->_data, mypair);
			}
		}
	};

	template<class Key, class T, class Compare, class Alloc>
		bool operator==(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
		{
				if (lhs.size() != rhs.size())
					return (false);
				typename map<Key,T,Compare,Alloc>::const_iterator itl = lhs.begin();
				typename map<Key,T,Compare,Alloc>::const_iterator itr = rhs.begin();
				while (itl != lhs.end() && itr != rhs.end())
				{
					if (itr != itl)
						return (false);
					itl++;
					itr++;
				}
				if (itr != itl)
					return (false);
				return (true);

		}
	template<class Key, class T, class Compare, class Alloc>
		bool operator!=(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
		{
			return (!(lhs == rhs));
		}
	template<class Key, class T, class Compare, class Alloc>
		bool operator<(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}
	template<class Key, class T, class Compare, class Alloc>
		bool operator<=(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
		{
			return (!(rhs < lhs));
		}
	template<class Key, class T, class Compare, class Alloc>
		bool operator>(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
		{
			return (rhs < lhs);
		}
	template<class Key, class T, class Compare, class Alloc>
		bool operator>=(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
		{
			return (!(lhs < rhs));
		}
	template<class Key, class T, class Compare, class Alloc>
		void swap(map<Key, T, Compare, Alloc> &x, map<Key,T,Compare,Alloc> &y) {x.swap(y); return;}
}
#endif
