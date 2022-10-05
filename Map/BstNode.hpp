#ifndef BSTNODE_HPP
# define BSTNODE_HPP
# include <cstddef>

namespace ft
{
	template <class T>
		struct BstNode
		{
			public :
			typedef T value_type;
			BstNode(void)
			{
				this->_sub = 1;
				this->_data = NULL;
				this->_parent = NULL;
				this->_left = NULL;
				this->_right = NULL;
			}
			BstNode(const value_type &data) : _data(data)
			{
				this->_sub = 1;
				this->_parent = NULL;
				this->_left = NULL;
				this->_right = NULL;
			}
			BstNode(const BstNode &x) : _data(x.getData()), _parent(x.getParent()), _left(x.getLeft()), _right(x.getRight()), _sub(x.getSub()) {}
			BstNode &operator=(const BstNode &x)
			{
				this->_data = x.getData();
				this->_parent = x.getParent();
				this->_left = x.getLeft();
				this->_right = x.getRight();
				this->_sub = x.getSub();
				return (*this);
			}
			BstNode &operator=(T *v)
			{
				this->_data = v;
				return (*this);
			}
			~BstNode(void) {};
			value_type *getData(void) const { return (this->_data); }
			BstNode *getLeft(void) const { return (this->_left); }
			BstNode *getRight(void) const { return (this->_right); }
			BstNode *getParent(void) const { return (this->_parent); }
			int getSub(void) const { return (this->_sub); }
			void setSub(int level) { this->_sub = level; }
			void setData(value_type *a) {this->_data = a; }
			void setParent(BstNode *a) {this->_parent = a; }
			void setLeft(BstNode *a) {this->_left = a; }
			void setRight(BstNode *a) {this->_right = a; }
			
			value_type *_data;
			BstNode *_parent;
			BstNode *_left;
			BstNode *_right;
			int		_sub;
		};
}

#endif
