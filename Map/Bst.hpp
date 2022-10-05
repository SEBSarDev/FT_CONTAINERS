#ifndef BINARYSEARCHTREE_HPP
# define BINARYSEARCHTREE_HPP
#include "BstNode.hpp"
#include "bstIterator.hpp"
#include "../utils/ft.hpp"

namespace ft
{
	template < class T, class Compare, class Alloc >
	class BinarySearchTree
	{
		public :
		typedef T value_type;
		typedef Compare key_compare;
		typedef ft::BstNode<T> node_type;
		typedef typename Alloc::template rebind<ft::BstNode<T> >::other allocNode;
		typedef typename ft::bst_iterator<ft::bidirectionnal_iterator_tag, ft::BstNode<T> > iterator;
		typedef typename ft::bst_iterator_const<ft::bidirectionnal_iterator_tag, ft::BstNode<value_type> > const_iterator;

		BinarySearchTree(const key_compare& comp = key_compare(), const allocNode& alloc = allocNode()) : _root(NULL), _size(0), _allocN(alloc), _compare(comp) { initExtremNode(); }
		~BinarySearchTree(void) { removeAll(this->_root); removeExtrem(); }
		allocNode getAllocN() const { return (this->_allocN); }
		key_compare getCompare() const { return (this->_compare); }
		ft::BstNode<T> *getRoot(void) const { return (this->_root); }
		ft::BstNode<T> *getRbegin(void) const { return (this->_rbeginNode); }
		ft::BstNode<T> *getEnd(void) const { return (this->_endNode); }
		int getSize(void) const { return (this->_size); }
		void setBeg(ft::BstNode<T> *node) { this->_rbeginNode = node; }
		void setEnd(ft::BstNode<T> *node) {	this->_endNode = node; }
		void setRoot(ft::BstNode<T> *node) { this->_root = node; }
		void setSize(size_t size) { this->_size = size;	}
		void removeAll(ft::BstNode<T> *depart)
		{
			Alloc allocPair;
			if (this->_size <= 0)
					return ;
			if (depart->_left != NULL)
					removeAll(depart->_left);
			if (depart->_right != NULL)
					removeAll(depart->_right);
			if (depart->_sub != 0)
			{
				allocPair.destroy(depart->_data);
				allocPair.deallocate(depart->_data, 1);
				this->_allocN.destroy(depart);
				this->_allocN.deallocate(depart, 1);
				depart = NULL;
				this->_size--;
			}
			this->_rbeginNode->_parent = NULL;
			this->_endNode->_parent = NULL;
		}
		void addValeur(T a, ft::BstNode<T> *tmp)
		{
			Alloc allocPair;
			ft::BstNode<T> *tmp2 = NULL;
			int side = 0;
		   	if (this->_size != 0)
			{
				tmp2 = tmp;
				cutExtrem();
				while (tmp != NULL && tmp->_sub != 0)
				{
					tmp2 = tmp;
					if (this->_compare(a.first, tmp->_data->first) == false
						&& this->_compare(tmp->_data->first, a.first) == false)
					{
						insertExtrem();
						return ;
					}
					if (this->_compare(a.first, tmp->getData()->first) == true)
					{
						tmp = tmp->getLeft();
						side = 1;
					}
					else
					{
						side = 2;
						tmp = tmp->getRight();
					}
				}
			}
			tmp = this->_allocN.allocate(1);
			this->_allocN.construct(tmp, node_type());
			tmp->_data = allocPair.allocate(1);
			allocPair.construct(tmp->_data, a);
			tmp->setParent(tmp2);
			tmp->setLeft(NULL);
			tmp->setRight(NULL);
			tmp->setSub(1);
			if (side == 1)
				tmp->_parent->_left = tmp;
			if (side == 2)
				tmp->_parent->_right = tmp;
			if (side == 0)
					this->_root = tmp;
			balance(tmp);
			this->_size++;
			insertExtrem();
		}
		size_t max_size(void) const {return (allocNode().max_size()); }
		ft::BstNode<T> *find(T a) const
		{
			ft::BstNode<T> *tmp = this->_root;
			
			while (tmp != NULL)
			{
				if (a.first == tmp->_data->first)
					return (tmp);
				if (this->_compare(a.first, tmp->getData()->first) == true)
					tmp = tmp->_left;
				else
					tmp = tmp->_right;
			}
			return (this->_endNode);
		}
		void removeOne(ft::BstNode<T> *sup)
		{
			if (!sup || sup == this->_rbeginNode || sup == this->_endNode)
				return ;
			cutExtrem();
			Alloc allocPair;
			allocPair.destroy(sup->_data);
			allocPair.deallocate(sup->_data, 1);
			if (sup->_left == NULL && sup->_right == NULL)
				removeLeaf(sup);
			else if (sup->_left != NULL && sup->_right == NULL)
				removeOneWOneChild(sup);
			else if (sup->_left == NULL && sup->_right != NULL)
				removeOneWOneChild(sup);
			else if (sup->_left != NULL && sup->_right != NULL)
				removeOneWTwoChild(sup);
			this->_size--;
			insertExtrem();
		}
		int nbFeuilles(ft::BstNode<T> *node)
		{
			if(node == NULL)
					return (0);
			if (node->_left == NULL && node->_right == NULL)
					return (1);
			else
				return (nbFeuilles(node->_left) + nbFeuilles(node->_right));
		}
		void setCompare(const key_compare &comp = key_compare()) { this->_compare = comp; }
		
		private :
		ft::BstNode<T> *_root;
		ft::BstNode<T> *_rbeginNode;
		ft::BstNode<T> *_endNode;
		size_t _size;
		allocNode _allocN;
		key_compare _compare;
		void removeExtrem(void)
		{	
			Alloc allocPair;
			if (this->_rbeginNode != NULL)
			{
				allocPair.destroy(this->_rbeginNode->_data);
				allocPair.deallocate(this->_rbeginNode->_data, 1);
				this->_allocN.destroy(this->_rbeginNode);
				this->_allocN.deallocate(this->_rbeginNode, 1);
			}
			if (this->_endNode != NULL)
			{
				allocPair.destroy(this->_endNode->_data);
				allocPair.deallocate(this->_endNode->_data, 1);
				this->_allocN.destroy(this->_endNode);
				this->_allocN.deallocate(this->_endNode, 1);
			}
		}
		void initExtremNode(void)
		{
			this->_rbeginNode = this->_allocN.allocate(1);
			this->_allocN.construct(this->_rbeginNode, node_type());
			this->_rbeginNode->setSub(0);
			this->_endNode = this->_allocN.allocate(1);
			this->_allocN.construct(this->_endNode, node_type());
			this->_endNode->setSub(0);
		}
		void insertExtrem(void)
		{
			if (this->_size == 0)
				return ;
			ft::BstNode<T> *dep = this->_root;
			while(dep->_left != NULL)
				dep = dep->_left;
			dep->_left = this->_rbeginNode;
			this->_rbeginNode->_parent = dep;
			this->_rbeginNode->_sub = 0;
			dep = this->_root;
			while(dep->_right != NULL)
					dep = dep->_right;
			dep->_right = this->_endNode;
			this->_endNode->_parent = dep;
			this->_endNode->_sub = 0;
		}
		void cutExtrem(void)
		{
			if (this->_rbeginNode->_parent != NULL)
			{
				this->_rbeginNode->_parent->_left = NULL;
				this->_rbeginNode->_parent = NULL;
			}
			if (this->_endNode->_parent != NULL)
			{
				this->_endNode->_parent->_right = NULL;
				this->_endNode->_parent = NULL;
			}
		}
		void removeOneWTwoChild(ft::BstNode<T> *sup)
		{
			if (this->_size == 1)
			{
				this->_allocN.destroy(sup);
				this->_allocN.deallocate(sup, 1);
				return ;
			}
			Alloc allocPair;
			ft::BstNode<T> *copy = sup->_parent;
			ft::BstNode<T> *replace = sup->_left;
			while (replace->_right != NULL)
				replace = replace->_right;
			if (replace == sup->_left)
			{
				sup->_left = replace->_left;
				if (replace->_left != NULL)
					replace->_left->_parent = replace->_parent;
			}
			sup->_data = replace->_data;
			if (replace->_parent != NULL
				&& replace->_parent->_right == replace)
			{
				replace->_parent->_right = replace->_left;
				if (replace->_left != NULL)
					replace->_left->_parent = replace->_parent;
			}
			this->_allocN.destroy(replace);
			this->_allocN.deallocate(replace, 1);
			replace = NULL;
			balance(copy);
		}
		void removeLeaf(ft::BstNode<T> *sup)
		{
			if (this->_size == 1)
			{
				this->_allocN.destroy(sup);
				this->_allocN.deallocate(sup, 1);
				return ;
			}
			ft::BstNode<T> *copy = sup->_parent;
			if (sup->_parent->_left == sup)
				sup->_parent->_left = NULL;
			else
				sup->_parent->_right = NULL;
			this->_allocN.destroy(sup);
			this->_allocN.deallocate(sup, 1);
			sup = NULL;
			balance(copy);
		}
		void removeOneWOneChild(ft::BstNode<T> *sup)
		{
			if (this->_size == 1)
			{
				this->_allocN.destroy(sup);
				this->_allocN.deallocate(sup, 1);
				return ;
			}
			ft::BstNode<T> *copy = sup->_parent;
			ft::BstNode<T> *side;
			if (sup->_left != NULL)
				side = sup->_left;
			else
				side = sup->_right;
			if (sup->_parent == NULL)
			{
				side->_parent = NULL;
				this->_root = side;
			}
			else
			{
				if (sup->_parent->_left == sup )
					sup->_parent->_left = side;
				else
					sup->_parent->_right = side;
			}
			side->_parent = sup->_parent;
			this->_allocN.destroy(sup);
			this->_allocN.deallocate(sup, 1);
			sup = NULL;
			balance(copy);
		}
		int getProf(ft::BstNode<T> *node)
		{
			if (node->_left == NULL && node->_right == NULL)
					return (1);
			else if ((node->_left != NULL && node->_right == NULL)
				|| (node->_left != NULL && node->_right != NULL
				&& node->_left->_sub > node->_right->_sub))
					return (node->_left->_sub + 1);
			else
					return (node->_right->_sub + 1);
		}
		void right_rot(ft::BstNode<T> *mv, int a)
		{
			ft::BstNode<T> *stock = mv->_parent;
			ft::BstNode<T> *stock2 = mv->_parent->_parent;
		
			if (mv->_parent->_parent != NULL && a == 1)
			{
				if (mv->_parent->_parent->_right == stock)
					mv->_parent->_parent->_right = mv;
				else
					mv->_parent->_parent->_left = mv;
			}
			if (mv->_right != NULL)
				mv->_right->_parent = mv->_parent;
			mv->_parent->_parent = mv;
			mv->_parent->_left = mv->_right;
			mv->_parent->_sub = getProf(mv->_parent);
			mv->_right = stock;
			mv->_parent = stock2;
			mv->_sub = getProf(mv);
			if (mv->_parent == NULL)
					this->_root = mv;
		}
		void left_right_rot(ft::BstNode<T> *mv)
		{
			left_rot(mv, 0);
			right_rot(mv, 1);
		}
		void left_rot(ft::BstNode<T> *mv, int a)
		{
			ft::BstNode<T> *stock = mv->_parent;
			ft::BstNode<T> *stock2 = mv->_parent->_parent;

			if (mv->_parent->_parent != NULL && a == 1)
			{
				if (mv->_parent->_parent->_right == stock)
					mv->_parent->_parent->_right = mv;
				else
					mv->_parent->_parent->_left = mv;
			}
			if (mv->_left != NULL)
				mv->_left->_parent = mv->_parent;
			mv->_parent->_parent = mv;
			mv->_parent->_right = mv->_left;
			mv->_parent->_sub = getProf(mv->_parent);
			mv->_left = stock;
			mv->_parent = stock2;
			mv->_sub = getProf(mv);
			if (mv->_parent == NULL)
					this->_root = mv;
		}
		void right_left_rot(ft::BstNode<T> *mv)
		{
			right_rot(mv, 0);
			left_rot(mv, 1);
		}
		void balance(ft::BstNode<T> *tmp)
		{
			ft::BstNode<T> *mv;
			
			while(tmp != NULL)
			{
				mv = tmp;
				mv->_sub = getProf(mv);
				if ((mv->_sub > 2 && mv->_left == NULL)
					|| (mv->_left && mv->_sub - mv->_left->_sub > 2))
				{
					mv = mv->_right;
					if (mv->_left == NULL
						|| (mv->_right != NULL && mv->_left->_sub <= mv->_right->_sub))
						left_rot(mv, 1);
					else
						right_left_rot(mv->_left);
			
				}
				else if ((mv->_sub > 2 && mv->_right == NULL)
						|| (mv->_right && mv->_sub - mv->_right->_sub > 2))
				{
						mv = mv->_left;
						if (mv->_right == NULL
							|| (mv->_left != NULL && mv->_right->_sub <= mv->_left->_sub))
								right_rot(mv, 1);
						else
								left_right_rot(mv->_right);
				}
				tmp = tmp->_parent;
			}
		}
		
	};
};

#endif
