#pragma once

#ifndef __BSTREE_H__
#define __BSTREE_H__

#include <iostream>
#include <iomanip>

template <class T>
class BSTNode
{
public:
	T key;//关键字，用来对二叉查找树的结点进行排序的
	BSTNode *left;//左孩子
	BSTNode *right;//右孩子
	BSTNode *parent;//父节点

	BSTNode(T value, BSTNode *p, BSTNode *l, BSTNode *r) :key(value), parent(), left(l), right(r) {}
};


template <class T>
class BSTree
{
public:
	BSTree();
	~BSTree();

	//前序遍历
	void PreOrder();
	//中序遍历
	void InOrder();
	//后序遍历
	void PostOrder();
	//(递归实现) 查找二叉树中键值为key的节点
	BSTNode<T>* Search(T key);
	//(非递归实现) 查找二叉树中键值为key的节点
	BSTNode<T>* IterativeSearch(T key);
	//查找最小节点，返回最小节点的键值
	T Minimum();
	//查找最大节点，返回最大节点的键值
	T Maximum();
	//找节点的后继节点，即二叉树中大于改节点的最小节点
	BSTNode<T>* Successor(BSTNode<T> *node);
	//找节点的后继节点，即二叉树中小于改节点的最大节点
	BSTNode<T>* Predecessor(BSTNode<T> *node);
	//将节点插入二叉树中
	void Insert(T key);
	//删除节点
	void Remove(T key);
	//销毁二叉树
	void Destroy();
	//打印二叉树
	void Print();
private:
	BSTNode<T> *mRoot;//根节点

	//前序遍历
	void PreOrder(BSTNode<T>* tree) const;
	//中序遍历
	void InOrder(BSTNode<T>* tree) const;
	//后序遍历
	void PostOrder(BSTNode<T>* tree) const;
	//(递归实现) 查找二叉树中键值为key的节点
	BSTNode<T>* Search(BSTNode<T>* tree, T key) const;
	//(非递归实现) 查找二叉树中键值为key的节点、
	BSTNode<T>* IterativeSearch(BSTNode<T>* tree, T key) const;
	//查找最小节点，返回最小节点的键值
	BSTNode<T>* Minimum(BSTNode<T>* tree);
	//查找最大节点，返回最大节点的键值
	BSTNode<T>* Maximum(BSTNode<T>* tree);
	//将节点插入二叉树中
	void Insert(BSTNode<T>* &tree, BSTNode<T>* z);
	//删除节点，并返回被删除节点的数据
	BSTNode<T>* Remove(BSTNode<T>* &tree, BSTNode<T> *z);
	//销毁二叉树
	void Destroy(BSTNode<T>* &tree);
	//打印二叉树
	void Print(BSTNode<T> *tree, T key, int direction);
};

template <class T>
BSTree<T>::BSTree():mRoot(NULL)
{

}


template <class T>
BSTree<T>::~BSTree()
{

}

//前序遍历二叉树    中左右：
//访问根结点
//前序遍历左子树
//前序遍历右子树
template <class T>
void BSTree<T>::PreOrder(BSTNode<T>* tree) const
{
	if (tree != NULL)
	{
		std::cout << tree->key << " ";
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
}

template <class T>
void BSTree<T>::PreOrder()
{
	PreOrder(mRoot);
}

//中序遍历二叉树   左中右
//中序遍历左子树
//访问根结点
//中序遍历右子树
template <class T>
void BSTree<T>::InOrder(BSTNode<T>* tree) const
{
	if (tree != NULL)
	{
		InOrder(tree->left);
		std::cout << tree->key << " ";
		InOrder(tree->right);
	}
}

template <class T>
void BSTree<T>::InOrder()
{
	InOrder(mRoot);
}

//后序遍历二叉树   左右中
//后序遍历左子树
//后序遍历右子树
//访问根结点
template <class T>
void BSTree<T>::PostOrder(BSTNode<T>* tree) const
{
	if (tree != NULL)
	{
		InOrder(tree->left);
		InOrder(tree->right);
		std::cout << tree->key << " ";
	}
}

template <class T>
void BSTree<T>::PostOrder()
{
	PostOrder(mRoot);
}

//(递归实现) 查找二叉树中键值为key的节点
template <class T>
BSTNode<T>* BSTree<T>::Search(BSTNode<T>* tree, T key) const
{
	if (tree == NULL || tree->key == key)
		return tree;
	if (key < tree->key)
		return Search(tree->left, key);
	else
		return Search(tree->right, key);
}

template <class T>
BSTNode<T>* BSTree<T>::Search(T key)
{
	return Search(mRoot, key);
}

//(非递归实现) 查找二叉树中键值为key的节点、
template <class T>
BSTNode<T>* BSTree<T>::IterativeSearch(BSTNode<T>* tree, T key) const
{
	while (tree != NULL && tree->key != key)
	{
		if (key < tree->key)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return tree;
}

template <class T>
BSTNode<T>* BSTree<T>::IterativeSearch(T key)
{
	return IterativeSearch(mRoot, key);
}

//查找最小节点
template <class T>
BSTNode<T>* BSTree<T>::Minimum(BSTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

template <class T>
T BSTree<T>::Minimum()
{
	BSTNode<T> *p = Minimum(mRoot);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}

//查找最大节点
template <class T>
BSTNode<T>* BSTree<T>::Maximum(BSTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}

template <class T>
T BSTree<T>::Maximum()
{
	BSTNode<T> *p = Maximum(mRoot);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}

#pragma region 重点查看的部分
template <class T>
BSTNode<T>* BSTree<T>::Successor(BSTNode<T> *node)
{
	//如果该节点存在右孩子，那么该节点的后继节点为 其右孩子为根的子树的最小节点
	if (node->right != NULL)
		return Minimum(node->right);

	//如果没有右孩子，有两种情况
	//1.该节点是一个左孩子，那他的后继节点为他的父节点
	//2.该节点是一个右孩子，那查找该节点的最低的父节点，且这个父节点还要具有左孩子，这个父节点就是该节点的后继节点
	BSTNode<T> *y = node->parent;
	while (y != NULL && node == y->right)
	{
		node = y;
		y = y->parent;
	}
	return y;
}

/*找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。*/
template < class T>
BSTNode<T>* BSTree<T>::Predecessor(BSTNode<T> *node)
{
	// 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
	if (node->left != NULL)
		return Maximum(node->left);
	// 如果x没有左孩子。则x有以下两种可能：
	// (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
	// (01) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
	BSTNode<T>* y = node->parent;
	while ((y != NULL) && (node == y->left))
	{
		node = y;
		y = y->parent;
	}

	return y;
}
#pragma endregion

//插入二叉树中，tree二叉树的根节点，z插入的节点
template <class T>
void BSTree<T>::Insert(BSTNode<T>* &tree, BSTNode<T>* z)
{
	BSTNode<T> *y = NULL;//中间变量，用于记录查找的最后一个节点
	BSTNode<T> *x = tree;

	//查找z的插入位置
	while (x != NULL)//先从二叉树的根节点开始找
	{
		y = x;
		if (z->key < x->key)//如果小于根节点的键值，就往左走
			x = x->left;
		else//如果大于根节点的键值，就往右走
			x = x->right;
	}

	z->parent = y;

	//判断改把插入的这个节点放在什么位置
	if (y == NULL) tree = z;
	else if (z->key < y->key) y->left = z;
	else y->right = z;
}


template <class T>
void BSTree<T>::Insert(T key)
{
	BSTNode<T> *z = NULL;
	if ((z = new BSTNode<T>(key, NULL, NULL, NULL)) == NULL) return;
	Insert(mRoot, z);
}


//删除节点，返回删除的节点数据   tree二叉树的根   z删除的节点
template <class T>
BSTNode<T>* BSTree<T>::Remove(BSTNode<T>* &tree, BSTNode<T> *z)
{
	BSTNode<T> *x = NULL;
	BSTNode<T> *y = NULL;

	if (z->left == NULL || z->right == NULL)
		y = z;
	else
		y = Successor(z);

	if (y->left != NULL)
		x = y->left;
	else
		x = y->right;

	if (x != NULL)
		x->parent = y->parent;

	if (y->parent == NULL)
		tree = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	if (y != z)
		z->key = y->key;

	return y;
}

template <class T>
void BSTree<T>::Remove(T key)
{
	BSTNode<T> *z, *node;
	if ((z = Search(mRoot, key)) != NULL)
		if ((node = Remove(mRoot, z)) != NULL)
			delete node;
}

template <class T>
void BSTree<T>::Destroy(BSTNode<T>* &tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		return Destroy(tree->left);
	if (tree->right != NULL)
		return Destroy(tree->right);

	delete tree;
	tree = NULL;
}

template <class T>
void BSTree<T>::Destroy()
{
	Destroy(mRoot);
}

template <class T>
void BSTree<T>::Print(BSTNode<T> *tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)
			std::cout << std::setw(2) << tree->key << " is root" << std::endl;
		else
			std::cout << std::setw(2) << tree->key << " is " << std::setw(2) << key << "`s" << std::setw(12) << (direction == 1 ? "right child" : "left child") << std::endl;
		Print(tree->left, tree->key, -1);
		Print(tree->right, tree->key, 1);
	}
}

template <class T>
void BSTree<T>::Print()
{
	if (mRoot != NULL)
		Print(mRoot, mRoot->key, 0);
}

#endif
