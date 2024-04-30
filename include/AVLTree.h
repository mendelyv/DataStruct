#pragma once

#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#include <iostream>

//AVL树是高度平衡的二叉查找树。它的特点是：AVL树中任何节点的两个子树的高度最大差别为1。
//当二叉查找树结构成为线型的时候，其效率会大大降低

template <class T>
class AVLTreeNode
{
public :
	T key;//关键字，用来给树排序使用
	int height;//高度
	AVLTreeNode *left;//左孩子
	AVLTreeNode *right;//右孩子

	AVLTreeNode(T key, AVLTreeNode *l, AVLTreeNode *r):
		key(key), height(0), left(l), right(r) {}
};


template <class T>
class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	int Height();//获取树的高度
	int Max(int a, int b);//找大值
	void PreOrder();//前序遍历
	void InOrder();//中序遍历
	void PostOrder();//后序遍历

	AVLTreeNode<T>* Search(T key);
	AVLTreeNode<T>* IterativeSearch(T key);

	//最大最小节点的键值
	T Minimum();
	T Maximum();

	void Insert(T key);
	void Remove(T key);

	void Destroy();
	void Print();
private:
	AVLTreeNode<T> *mRoot;//根节点

	//const修饰符放在函数后面代表这个方法只可读类数据不可修改
	int Height(AVLTreeNode<T> *node);
	void PreOrder(AVLTreeNode<T> *node) const;
	void InOrder(AVLTreeNode<T> *node) const;
	void PostOrder(AVLTreeNode<T> *node) const;
	//（递归实现）查找键值为key的节点
	AVLTreeNode<T>* Search(AVLTreeNode<T> *node, T key) const;
	//（非递归实现）查找键值为key的节点
	AVLTreeNode<T>* IterativeSearch(AVLTreeNode<T>* node, T key) const;

	AVLTreeNode<T>* Minimum(AVLTreeNode<T> *node);
	AVLTreeNode<T>* Maximum(AVLTreeNode<T> *node);

	//如果在AVL树中进行插入或删除节点后，可能导致AVL树失去平衡。这种失去平衡的可以概括为4种姿态：LL(左左)，LR(左右)，RR(右右)和RL(右左)
	
	//根节点的左子树的左子树还有非空子节点，导致"根的左子树的高度"比"根的右子树的高度"大2，导致AVL树失去了平衡。
	AVLTreeNode<T>* LLRotation(AVLTreeNode<T> *node);

	//根节点的右子树的右子树还有非空子节点，导致"根的右子树的高度"比"根的左子树的高度"大2，导致AVL树失去了平衡。
	AVLTreeNode<T>* RRRotation(AVLTreeNode<T> *node);

	//根节点的左子树的右子树还有非空子节点，导致"根的左子树的高度"比"根的右子树的高度"大2，导致AVL树失去了平衡。
	AVLTreeNode<T>* LRRotation(AVLTreeNode<T> *node);

	//根节点的右子树的左子树还有非空子节点，导致"根的右子树的高度"比"根的左子树的高度"大2，导致AVL树失去了平衡。
	AVLTreeNode<T>* RLRotation(AVLTreeNode<T> *node);

	//在传参的时候，使用指针传参，编译器需要给指针另行分配存储单元，存储一个该指针的副本，在函数中对这个副本进行操作；而使用引用传参，编译器就不需要分配存储空间和保存副本了，函数将直接对实参进行操作。所以使用引用使得程序的运行速度更快，执行效率更高。
	//如果是传递指针，那么会先复制该指针，在函数内部使用的是复制后的指针，这个指针与原来的指针指向相同的地址，如果在函数内部将复制后的指针指向了另外的新的对象，那么不会影响原有的指针；
	//这里使用的指针的引用，原理上跟传递二级指针是一样的，但是如果写为二级指针，函数的实现体会带有大量的解引用符，会导致代码难以读懂和提高代码书写难度
	AVLTreeNode<T>* Insert(AVLTreeNode<T>* &node, T key);
	AVLTreeNode<T>* Remove(AVLTreeNode<T>* &node, AVLTreeNode<T>* z);
	void Destroy(AVLTreeNode<T>* &node);
	void Print(AVLTreeNode<T> *node, T key, int direction);
};


template<class T>
AVLTree<T>::AVLTree():mRoot(NULL)
{

}

template <class T>
AVLTree<T>::~AVLTree()
{

}

template <class T>
int AVLTree<T>::Height()
{	
	return Height(mRoot);
}

template <class T>
int AVLTree<T>::Height(AVLTreeNode<T> *node)
{
	if (node != NULL)
		return node->height;
	return 0;
}

template <class T>
int AVLTree<T>::Max(int a, int b)
{
	return a > b ? a : b;
}

//前序遍历二叉树    中左右：
//访问根结点
//前序遍历左子树
//前序遍历右子树
template<class T>
void AVLTree<T>::PreOrder(AVLTreeNode<T> *node) const
{
	if (node != NULL)
	{
		std::cout << node->key << " ";
		PreOrder(node->left);
		PreOrder(node->right);
	}
}

template <class T>
void AVLTree<T>::PreOrder()
{
	PreOrder(mRoot);
}

//中序遍历二叉树   左中右
//中序遍历左子树
//访问根结点
//中序遍历右子树
template <class T>
void AVLTree<T>::InOrder(AVLTreeNode<T> *node) const
{
	if (node != NULL)
	{
		InOrder(node->left);
		std::cout << node->key << " ";
		InOrder(node->right);
	}
}

template <class T>
void AVLTree<T>::InOrder()
{
	InOrder(mRoot);
}

//后序遍历二叉树   左右中
//后序遍历左子树
//后序遍历右子树
//访问根结点
template <class T>
void AVLTree<T>::PostOrder(AVLTreeNode<T> *node) const
{
	if (node != NULL)
	{
		PostOrder(node->left);
		PostOrder(node->right);
		std::cout << node->key << " ";
	}
}

template <class T>
void AVLTree<T>::PostOrder()
{
	PostOrder(mRoot);
}

//(递归实现) 查找键值为key的节点
template <class T>
AVLTreeNode<T>* AVLTree<T>::Search(AVLTreeNode<T> *node, T key) const
{
	if (node == NULL || node->key == key) return node;
	if (key < node->key)
		Search(node->left, key);
	else
		Search(node->right, key);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::Search(T key)
{
	return Search(mRoot, key);
}

//（非递归实现）查找键值为key的节点
template <class T>
AVLTreeNode<T>* AVLTree<T>::IterativeSearch(AVLTreeNode<T> *node, T key) const
{
	while (node != NULL && node->key != key)
	{
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return node;
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::IterativeSearch(T key)
{
	return IterativeSearch(mRoot, key);
}


template <class T>
AVLTreeNode<T>* AVLTree<T>::Minimum(AVLTreeNode<T> *node)
{
	if (node == NULL) return NULL;
	while (node->left != NULL)
		node = node->left;
	return node;
}

template <class T>
T AVLTree<T>::Minimum()
{
	AVLTreeNode<T> *p = Minimum(mRoot);
	if (p != NULL) return p->key;
	return (T)NULL;
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::Maximum(AVLTreeNode<T> *node)
{
	if (node == NULL) return NULL;
	while (node->right != NULL)
		node = node->right;
	return node;
}

template <class T>
T AVLTree<T>::Maximum()
{
	AVLTreeNode<T> *p = Maximum(mRoot);
	if (p != NULL) return p->key;
	return (T)NULL;
}

#pragma region 旋转是AVL树的重点

//LL旋转是围绕"失去平衡的AVL根节点"进行的
template <class T>
AVLTreeNode<T>* AVLTree<T>::LLRotation(AVLTreeNode<T> *node)
{
	AVLTreeNode<T> *l;//要旋转成根节点的节点

	l = node->left;//失衡点的左孩子即为要成为根的节点
	node->left = l->right;//失衡点要成为新的根节点的右孩子，所以之前的右孩子要补到失衡点的左孩子上
	l->right = node;//旋转树

	//修改高度值
	node->height = Max(Height(node->left), Height(node->right)) + 1;//注意此时失衡点已经不为根节点了，所以它的高度即为左右子树最高的那棵 + 1
	l->height = Max(Height(l->left), node->height) + 1;//此时l点已经为根节点了，失衡点已经变成它的右孩子，所以用左子树的高与重新计算的node的高度最高的那棵 + 1

	return l;
}

//RR旋转即为LL旋转的对称
template <class T>
AVLTreeNode<T>* AVLTree<T>::RRRotation(AVLTreeNode<T> *node)
{
	AVLTreeNode<T> *r;//要旋转成根节点的节点

	r = node->right;//失衡点的右孩子即为要成为根的节点
	node->right = r->left;//失衡点要成为新的根节点的左孩子，所以之前的左孩子要补到失衡点的右孩子上
	r->left = node;//旋转树

	node->height = Max(Height(node->left), Height(node->right)) + 1;//注意此时失衡点已经不为根节点了，所以它的高度即为左右子树最高的那棵 + 1
	r->height = Max(Height(r->right), node->height) + 1;//此时l点已经为根节点了，失衡点已经变成它的左孩子，所以用右子树的高与重新计算的node的高度最高的那棵 + 1

	return r;
}


//LR失去平衡的情况，需要经过两次旋转才能让AVL树恢复平衡
//第一次旋转是围绕失衡点node的左孩子进行的"RR旋转"，第二次是围绕失衡点node进行的"LL旋转"。
template <class T>
AVLTreeNode<T>* AVLTree<T>::LRRotation(AVLTreeNode<T> *node)
{
	node->left = RRRotation(node->left);
	return LLRotation(node);
}


//RL是与LR的对称情况
//第一次旋转是围绕失衡点node的右孩子进行的"LL旋转"，第二次是围绕失衡点node进行的"RR旋转"。
template <class T>
AVLTreeNode<T>* AVLTree<T>::RLRotation(AVLTreeNode<T> *node)
{
	node->right = LLRotation(node->right);
	return RRRotation(node);
}

#pragma endregion

//（递归实现）插入键值
template <class T>
AVLTreeNode<T>* AVLTree<T>::Insert(AVLTreeNode<T>* &node, T key)
{
	//如果是空树，就新建
	if (node == NULL)
	{
		node = new AVLTreeNode<T>(key, NULL, NULL);
		if (node == NULL)
		{
			std::cout << "Create AVLTree Node Failed" << std::endl;
			return NULL;
		}
	}
	else if (key < node->key)//应该插入左子树的情况
	{
		//递归插入
		node->left = Insert(node->left, key);
		// 插入节点后，若AVL树失去平衡，则进行相应的调节
		if (Height(node->left) - Height(node->right) == 2)
		{
			if (key < node->left->key)//如果在左孩子的左边，出现LL情况
			{
				node = LLRotation(node);
			}
			else//如果在左孩子的右边，出现LR情况
			{
				node = LRRotation(node);
			}
		}
	}
	else if (key > node->key)//应该插入右子树的情况
	{
		//递归插入
		node->right = Insert(node->right, key);
		// 插入节点后，若AVL树失去平衡，则进行相应的调节
		if (Height(node->right) - Height(node->left) == 2)
		{
			if (key < node->right->key)//如果在右孩子的左边，出现RL情况
			{
				node = RLRotation(node);
			}
			else//如果在右孩子的右边，出现RR情况
			{
				node = RRRotation(node);
			}
		}
	}
	else //已经有这个key了
	{
		std::cout << "Insert Failed" << std::endl;
	}

	node->height = Max(Height(node->left), Height(node->right)) + 1;
	return node;
}

template <class T>
void AVLTree<T>::Insert(T key)
{
	Insert(mRoot, key);
}


template <class T>
AVLTreeNode<T>* AVLTree<T>::Remove(AVLTreeNode<T>* &node, AVLTreeNode<T>* z)
{
	if (node == NULL || z == NULL)
		return NULL;

	if (z->key < node->key)//如果要删除的节点在左子树中
	{
		//递归删除
		node->left = Remove(node->left, z);
		// 删除节点后，若AVL树失去平衡，则进行相应的调节
		if (Height(node->right) - Height(node->left) == 2)
		{
			AVLTreeNode<T>* t = node->right;//获取一棵新树，即为高度失衡的右子树
			if (Height(t->left) > Height(t->right))//左子树比右子树高，RL旋转
				RLRotation(node);
			else//右子树比左子树高，RR旋转
				RRRotation(node);
		}
	}
	else if (z->key > node->key)//如果要删除的节点在右子树中
	{
		//递归删除
		node->right = Remove(node->right, z);
		// 删除节点后，若AVL树失去平衡，则进行相应的调节
		if (Height(node->left) - Height(node->right) == 2)
		{
			AVLTreeNode<T> *t = node->left;//获取一棵新树，即为高度失衡的左子树
			if (Height(t->left) > Height(t->right))//左子树比右子树高，LL旋转
				LLRotation(node);
			else//右子树比左子树高，LR旋转
				LRRotation(node);
		}
	}
	else //根节点是要删除的节点
	{
		//当左右都不为空的时候
		if ((node->left != NULL) && (node->right != NULL))
		{
			if (Height(node->left) > Height(node->right))
			{
				// 如果node的左子树比右子树高；
				// 则(01)找出node的左子树中的最大节点
				//   (02)将该最大节点的值赋值给node。
				//   (03)删除该最大节点。
				// 这类似于用"node的左子树中最大节点"做"node"的替身；
				// 采用这种方式的好处是：删除"node的左子树中最大节点"之后，AVL树仍然是平衡的。
				AVLTreeNode<T> *m = Maximum(node->left);
				node->key = m->key;
				node->left = Remove(node->left, m);
			}
			else
			{
				// 如果node的左子树不比右子树高(即它们相等，或右子树比左子树高1)
				// 则(01)找出node的右子树中的最小节点
				//   (02)将该最小节点的值赋值给node。
				//   (03)删除该最小节点。
				// 这类似于用"node的右子树中最小节点"做"node"的替身；
				// 采用这种方式的好处是：删除"node的右子树中最小节点"之后，AVL树仍然是平衡的。
				AVLTreeNode<T> *m = Minimum(node->right);
				node->key = m->key;
				node->right = Remove(node->right, m);
			}
		}
		else
		{
			AVLTreeNode<T> *tmp = node;
			node = (node->left != NULL) ? node->left : node->right;
			delete tmp;
		}
	}
	

	return node;
}

template <class T>
void AVLTree<T>::Remove(T key)
{
	AVLTreeNode<T> *t = NULL;
	if ((t = Search(mRoot, key)) != NULL)
		mRoot = Remove(mRoot, t);
}


template <class T>
void AVLTree<T>::Destroy(AVLTreeNode<T>* &node)
{
	if(node == NULL)
		return;	
	if(node->left != NULL)
		Destroy(node->left);
	if(node->right != NULL)
		Destroy(node->right);
}

template <class T>
void AVLTree<T>::Destroy()
{
	Destroy(mRoot);
}

template <class T>
void AVLTree<T>::Print(AVLTreeNode<T> *node, T key, int direction)
{
	if(node != NULL)
	{
		if(direction == 0)
			std::cout << node->key << " is root" << std::endl;
		else
			std::cout << node->key << " is " << key << "`s " << (direction == 1 ? "right child" : "left child") << std::endl;

		Print(node->left, node->key, -1);
		Print(node->right, node->key, 1);
	}
}


template <class T>
void AVLTree<T>::Print()
{
	if(mRoot != NULL)
		Print(mRoot, mRoot->key, 0);
}



#endif
