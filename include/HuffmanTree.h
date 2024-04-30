#pragma once

#ifndef __HUFFMANTREE_H__
#define __HUFFMANTREE_H__

#include "HuffmanHeap.h"
#include "HuffmanTreeNode.h"
#include <iostream>

template<class T>
class HuffmanTree
{
public:
	HuffmanTree();
	~HuffmanTree();

	void PreOrder();
	void InOrder();
	void PostOrder();

	void Create(T a[], int size);
	void Destroy();
	void Print();

private:
	HuffmanTreeNode<T>* mRoot;//���ڵ�

	void PreOrder(HuffmanTreeNode<T>* tree) const;
	void InOrder(HuffmanTreeNode<T>* tree) const;
	void PostOrder(HuffmanTreeNode<T>* tree) const;

	void Destroy(HuffmanTreeNode<T>*& tree);
	void Print(HuffmanTreeNode<T>* tree, T key, int direction);
};


template<class T>
HuffmanTree<T>::HuffmanTree():mRoot(NULL)
{

}


template<class T>
HuffmanTree<T>::~HuffmanTree()
{

}


template<class T>
void HuffmanTree<T>::PreOrder()
{
	PreOrder(mRoot);
}

template<class T>
void HuffmanTree<T>::PreOrder(HuffmanTreeNode<T>* tree) const
{
	if (tree != NULL)
	{
		std::cout << tree->key << " ";
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
}


template<class T>
void HuffmanTree<T>::InOrder()
{
	InOrder(mRoot);
}


template<class T>
void HuffmanTree<T>::InOrder(HuffmanTreeNode<T>* tree) const
{
	if (tree != NULL)
	{
		InOrder(tree->left);
		std::cout << tree->key << " ";
		InOrder(tree->right);
	}
}


template<class T>
void HuffmanTree<T>::PostOrder()
{
	PostOrder(mRoot);
}


template<class T>
void HuffmanTree<T>::PostOrder(HuffmanTreeNode<T>* tree) const
{
	if (tree != NULL)
	{
		PostOrder(tree->left);
		PostOrder(tree->right);
		std::cout << tree->key << " ";
	}
}

//������������
//���ν�Ȩֵ��С������ɭ�ֽڵ�ϲ��ɶ�����
template<class T>
void HuffmanTree<T>::Create(T a[], int size)
{
	HuffmanTreeNode<T> *left = NULL, *right = NULL, *parent = NULL;
	HuffmanHeap<T> *heap = new HuffmanHeap<T>();//ʹ����С������������
	heap->Create(a, size);
	
	for (int i = 0; i < size - 1; i++)
	{
		left = heap->DumpFromMinimum();//��С�ڵ�Ϊ����
		right = heap->DumpFromMinimum();//�����Һ���

		//����parent�ڵ�
		//parent�ڵ��ȨֵΪ���Һ���֮��
		parent = new HuffmanTreeNode<T>(left->key + right->key, left, right, NULL);
		left->parent = parent;
		right->parent = parent;

		//��parent�ڵ㿽��������С��
		if (heap->CopyOf(parent) != 0)
		{
			std::cout << "����ʧ��" << std::endl;
			Destroy(parent);
			parent = NULL;
			break;
		}
	}

	mRoot = parent;

	heap->Destroy();
	delete heap;

}


template<class T>
void HuffmanTree<T>::Destroy(HuffmanTreeNode<T>*& tree)
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


template<class T>
void HuffmanTree<T>::Destroy()
{
	Destroy(mRoot);
}


/*
 * ��ӡ"Huffman��"
 *
 * key        -- �ڵ�ļ�ֵ
 * direction  --  0����ʾ�ýڵ��Ǹ��ڵ�;
 *               -1����ʾ�ýڵ������ĸ���������;
 *                1����ʾ�ýڵ������ĸ������Һ��ӡ�
 */
template <class T>
void HuffmanTree<T>::Print(HuffmanTreeNode<T>* tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)	// tree�Ǹ��ڵ�
			std::cout << tree->key << " is root" << std::endl;
		else				// tree�Ƿ�֧�ڵ�
			std::cout << tree->key << " is " << key << "'s " << (direction == 1 ? "right child" : "left child") << std::endl;

		Print(tree->left, tree->key, -1);
		Print(tree->right, tree->key, 1);
	}
}

template <class T>
void HuffmanTree<T>::Print()
{
	if (mRoot != NULL)
		Print(mRoot, mRoot->key, 0);
}

#endif