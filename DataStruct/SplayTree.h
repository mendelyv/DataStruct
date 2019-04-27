#pragma once

#ifndef __SPLAYTREE_H__
#define __SPLAYTREE_H__

#include <iostream>
//伸展树(Splay Tree)是特殊的二叉查找树。
//它的特殊是指，它除了本身是棵二叉查找树之外，它还具备一个特点 : 当某个节点被访问时，伸展树会通过旋转使该节点成为树根。这样做的好处是，下次要访问该节点时，能够迅速的访问到该节点。

template <class T>
class SplayTreeNode
{
public:
	T key;
	SplayTreeNode* left;
	SplayTreeNode* right;

public:
	SplayTreeNode() :key(NULL), left(NULL), right(NULL) {}

	SplayTreeNode(T value, SplayTreeNode* l, SplayTreeNode* r) :
		key(value), left(l), right(r) {}
};


template <class T>
class SplayTree
{
public:
	SplayTree();
	~SplayTree();

	void PreOrder();
	void InOrder();
	void PostOrder();

	SplayTreeNode<T>* Search(T key);
	SplayTreeNode<T>* IterativeSearch(T key);

	T Maximum();
	T Minimum();

	void Splay(T key);

	void Insert(T key);
	void Remove(T key);

	void Destroy();
	void Print();

private:
	SplayTreeNode<T>* mRoot;

	void PreOrder(SplayTreeNode<T>* node) const;
	void InOrder(SplayTreeNode<T>* node) const;
	void PostOrder(SplayTreeNode<T>* node) const;

	SplayTreeNode<T>* Search(SplayTreeNode<T>* node, T key) const;
	SplayTreeNode<T>* IterativeSearch(SplayTreeNode<T>* node, T key) const;

	SplayTreeNode<T>* Maximum(SplayTreeNode<T>* node);
	SplayTreeNode<T>* Minimum(SplayTreeNode<T>* node);

	// 旋转key对应的节点为根节点，并返回值为根节点
	SplayTreeNode<T>* Splay(SplayTreeNode<T>* node, T key);

	SplayTreeNode<T>* Insert(SplayTreeNode<T>*& node, SplayTreeNode<T>* z);
	SplayTreeNode<T>* Remove(SplayTreeNode<T>*& node, T key);

	void Destroy(SplayTreeNode<T>* &node);
	void Print(SplayTreeNode<T>* tree, T key, int direction);

};


template <class T>
SplayTree<T>::SplayTree() :mRoot(NULL) {}

template <class T>
SplayTree<T>::~SplayTree()
{
	Destroy(mRoot);
}

template <class T>
void SplayTree<T>::PreOrder(SplayTreeNode<T>* node) const
{
	if (node != NULL)
	{
		std::cout << node->key << " ";
		PreOrder(node->left);
		PreOrder(node->right);
	}
}

template <class T>
void SplayTree<T>::PreOrder()
{
	PreOrder(mRoot);
}

template <class T>
void SplayTree<T>::InOrder(SplayTreeNode<T>* node) const
{
	if (node != NULL)
	{
		InOrder(node->left);
		std::cout << node->key << " ";
		InOrder(node->right);
	}
}

template <class T>
void SplayTree<T>::InOrder()
{
	InOrder(mRoot);
}

template <class T>
void SplayTree<T>::PostOrder(SplayTreeNode<T>* node) const
{
	if (node != NULL)
	{
		PostOrder(node->left);
		PostOrder(node->right);
		std::cout << node->key << " ";
	}
}

template <class T>
void SplayTree<T>::PostOrder()
{
	PostOrder(mRoot);
}


template <class T>
SplayTreeNode<T>* SplayTree<T>::Search(SplayTreeNode<T>* node, T key) const
{
	if (node == NULL || node->key == key)
		return node;
	if (key < node->key)
		Search(node->left, key);
	else
		Search(node->right, key);
}

template <class T>
SplayTreeNode<T>* SplayTree<T>::Search(T key)
{
	return Search(mRoot, key);
}


template<class T>
SplayTreeNode<T>* SplayTree<T>::IterativeSearch(SplayTreeNode<T>* node, T key) const
{
	while (node != NULL && node->key != key)
	{
		if (key < node->key)
			node = node->left;//这里真的不会改变mRoot指针的指向吗？
		else
			node = node->right;
	}
	return node;
}

template <class T>
SplayTreeNode<T>* SplayTree<T>::IterativeSearch(T key)
{
	return IterativeSearch(key);
}


template <class T>
SplayTreeNode<T>* SplayTree<T>::Maximum(SplayTreeNode<T>* node)
{
	if (node == NULL) return NULL;
	while (node->right != NULL)
		node = node->right;
	return node;
}

template <class T>
T SplayTree<T>::Maximum()
{
	SplayTreeNode<T>* p = Maximum(mRoot);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}


template <class T>
SplayTreeNode<T>* SplayTree<T>::Minimum(SplayTreeNode<T>* node)
{
	if (node == NULL) return NULL;
	while (node->left != NULL)
		node = node->left;
	return node;
}

template <class T>
T SplayTree<T>::Minimum()
{
	SplayTreeNode<T>* p = Minimum(mRoot);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}

#pragma region 旋转是伸展树中需要重点关注
/*
 * 旋转key对应的节点为根节点，并返回值为根节点。
 *
 * 注意：
 *   (a)：伸展树中存在"键值为key的节点"。
 *          将"键值为key的节点"旋转为根节点。
 *   (b)：伸展树中不存在"键值为key的节点"，并且key < tree->key。
 *      b-1 "键值为key的节点"的前驱节点存在的话，将"键值为key的节点"的前驱节点旋转为根节点。
 *      b-2 "键值为key的节点"的前驱节点存在的话，则意味着，key比树中任何键值都小，那么此时，将最小节点旋转为根节点。
 *   (c)：伸展树中不存在"键值为key的节点"，并且key > tree->key。
 *      c-1 "键值为key的节点"的后继节点存在的话，将"键值为key的节点"的后继节点旋转为根节点。
 *      c-2 "键值为key的节点"的后继节点不存在的话，则意味着，key比树中任何键值都大，那么此时，将最大节点旋转为根节点。
 */
template <class T>
SplayTreeNode<T>* SplayTree<T>::Splay(SplayTreeNode<T>* node, T key)
{
	SplayTreeNode<T> N, * l, * r, * c;
	if (node == NULL)
		return node;

	N.left = N.right = NULL;
	l = r = &N;

	while (true)
	{
		if (key < node->key)
		{
			if (node->left == NULL) break;

			if (key < node->left->key) // 右旋
			{
				c = node->left;
				node->left = c->right;
				c->right = node;
				node = c;

				if (node->left == NULL) break;
			}

			r->left = node; //链接右端
			r = node;
			node = node->left;
		}
		else if (key > node->key)
		{
			if (node->right == NULL) break;

			if (key > node->right->key) // 左旋
			{
				c = node->right;
				node->right = c->left;
				c->left = node;
				node = c;

				if (node->right == NULL) break;
			}
			l->right = node; // 链接左端
			l = node;
			node = node->right;
		}
		else
			break;
	}

	l->right = node->left;
	r->left = node->right;
	node->left = N.right;
	node->right = N.left;

	return node;

}


template <class T>
void SplayTree<T>::Splay(T key)
{
	mRoot = Splay(mRoot, key);
}

#pragma endregion


template <class T>
SplayTreeNode<T>* SplayTree<T>::Insert(SplayTreeNode<T>*& node, SplayTreeNode<T>* z)
{
	SplayTreeNode<T>* y = NULL;
	SplayTreeNode<T>* x = node;

	//循环找插入点
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else if (z->key > x->key)
			x = x->right;
		else
		{
			std::cout << "不允许插入相同的节点(" << z->key << ")!" << std::endl;
			delete z;
			return node;
		}
	}

	if (y == NULL)
		node = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;

	return node;
}


template <class T>
void SplayTree<T>::Insert(T key)
{
	SplayTreeNode<T>* z = NULL;
	if ((z = new SplayTreeNode<T>(key, NULL, NULL)) == NULL)
		return;

	mRoot = Insert(mRoot, z);
	mRoot = Splay(mRoot, key);
}


template <class T>
SplayTreeNode<T>* SplayTree<T>::Remove(SplayTreeNode<T>*& node, T key)
{
	SplayTreeNode<T>* x;
	if (node == NULL)
		return NULL;

	if (Search(node, key) == NULL)
		return node;

	//将key对应的节点旋转成根节点
	node = Splay(node, key);

	if (node->left != NULL)
	{
		//将node节点的前驱节点旋转为根节点
		x = Splay(node->left, key);
		//移除node节点
		x->right = node->right;
	}
	else
		x = node->right;

	delete node;

	return x;
}


template <class T>
void SplayTree<T>::Remove(T key)
{
	mRoot = Remove(mRoot, key);
}


template <class T>
void SplayTree<T>::Destroy(SplayTreeNode<T>*& node)
{
	if (node == NULL) return;

	if (node->left != NULL)
		Destroy(node->left);
	if (node->right != NULL)
		Destroy(node->right);

	delete node;
}

template <class T>
void SplayTree<T>::Destroy()
{
	Destroy(mRoot);
}

template < class T>
void SplayTree<T>::Print(SplayTreeNode<T>* tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)    // tree是根节点
			    std::cout << tree->key << " is root" << std::endl;
		else                // tree是分支节点
			    std::cout << tree->key << " is " << key << "'s " << (direction == 1 ? "right child" : "left child") << std::endl;
		
			Print(tree->left, tree->key, -1);
		Print(tree->right, tree->key, 1);
	}
}

template <class T>
void SplayTree<T>::Print()
{
	if (mRoot != NULL)
		Print(mRoot, mRoot->key, 0);
}


#endif
