#pragma once

#ifndef __SPLAYTREE_H__
#define __SPLAYTREE_H__

#include <iostream>
//��չ��(Splay Tree)������Ķ����������
//����������ָ�������˱����ǿö��������֮�⣬�����߱�һ���ص� : ��ĳ���ڵ㱻����ʱ����չ����ͨ����תʹ�ýڵ��Ϊ�������������ĺô��ǣ��´�Ҫ���ʸýڵ�ʱ���ܹ�Ѹ�ٵķ��ʵ��ýڵ㡣

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

	// ��תkey��Ӧ�Ľڵ�Ϊ���ڵ㣬������ֵΪ���ڵ�
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
			node = node->left;//������Ĳ���ı�mRootָ���ָ����
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

#pragma region ��ת����չ������Ҫ�ص��ע
/*
 * ��תkey��Ӧ�Ľڵ�Ϊ���ڵ㣬������ֵΪ���ڵ㡣
 *
 * ע�⣺
 *   (a)����չ���д���"��ֵΪkey�Ľڵ�"��
 *          ��"��ֵΪkey�Ľڵ�"��תΪ���ڵ㡣
 *   (b)����չ���в�����"��ֵΪkey�Ľڵ�"������key < tree->key��
 *      b-1 "��ֵΪkey�Ľڵ�"��ǰ���ڵ���ڵĻ�����"��ֵΪkey�Ľڵ�"��ǰ���ڵ���תΪ���ڵ㡣
 *      b-2 "��ֵΪkey�Ľڵ�"��ǰ���ڵ���ڵĻ�������ζ�ţ�key�������κμ�ֵ��С����ô��ʱ������С�ڵ���תΪ���ڵ㡣
 *   (c)����չ���в�����"��ֵΪkey�Ľڵ�"������key > tree->key��
 *      c-1 "��ֵΪkey�Ľڵ�"�ĺ�̽ڵ���ڵĻ�����"��ֵΪkey�Ľڵ�"�ĺ�̽ڵ���תΪ���ڵ㡣
 *      c-2 "��ֵΪkey�Ľڵ�"�ĺ�̽ڵ㲻���ڵĻ�������ζ�ţ�key�������κμ�ֵ������ô��ʱ�������ڵ���תΪ���ڵ㡣
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

			if (key < node->left->key) // ����
			{
				c = node->left;
				node->left = c->right;
				c->right = node;
				node = c;

				if (node->left == NULL) break;
			}

			r->left = node; //�����Ҷ�
			r = node;
			node = node->left;
		}
		else if (key > node->key)
		{
			if (node->right == NULL) break;

			if (key > node->right->key) // ����
			{
				c = node->right;
				node->right = c->left;
				c->left = node;
				node = c;

				if (node->right == NULL) break;
			}
			l->right = node; // �������
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

	//ѭ���Ҳ����
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else if (z->key > x->key)
			x = x->right;
		else
		{
			std::cout << "�����������ͬ�Ľڵ�(" << z->key << ")!" << std::endl;
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

	//��key��Ӧ�Ľڵ���ת�ɸ��ڵ�
	node = Splay(node, key);

	if (node->left != NULL)
	{
		//��node�ڵ��ǰ���ڵ���תΪ���ڵ�
		x = Splay(node->left, key);
		//�Ƴ�node�ڵ�
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
		if (direction == 0)    // tree�Ǹ��ڵ�
			    std::cout << tree->key << " is root" << std::endl;
		else                // tree�Ƿ�֧�ڵ�
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
