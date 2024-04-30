#pragma once

#ifndef __HUFFMAN_HEAP_H__
#define __HUFFMAN_HEAP_H__

#include "HuffmanTreeNode.h"

//为霍夫曼树准备的最小堆
template<class T>
class HuffmanHeap
{
public:
	HuffmanHeap();
	~HuffmanHeap();

	// 将node的全部数据拷贝给"最小堆的指定节点"
	int CopyOf(HuffmanTreeNode<T>* node);
	// 获取最小节点
	HuffmanTreeNode<T>* DumpFromMinimum();
	// 创建最小堆
	void Create(T a[], int size);
	// 销毁最小堆
	void Destroy();

private:
	HuffmanTreeNode<T>* mHeap;
	int mSize;
	int mCapacity;
	void FilterDown(int start, int end);
	void FilterUp(int start);
	void SwapNode(int i, int j);
};


template<class T>
HuffmanHeap<T>::HuffmanHeap() {}


template<class T>
HuffmanHeap<T>::~HuffmanHeap()
{
	Destroy();
}


template<class T>
void HuffmanHeap<T>::FilterDown(int start, int end)
{
	int c = start;
	int l = c * 2 + 1;
	HuffmanTreeNode<T> tmp = mHeap[c];

	while (l <= end)
	{
		if (l < end && mHeap[l].key > mHeap[l + 1].key)
			l++;
		if (tmp.key < mHeap[l].key)
			break;
		else
		{
			mHeap[c] = mHeap[l];
			c = l;
			l = c * 2 + 1;
		}
	}
	mHeap[c] = tmp;
}


template<class T>
void HuffmanHeap<T>::FilterUp(int start)
{
	int c = start;
	int p = (c - 1) / 2;
	HuffmanTreeNode<T> tmp = mHeap[c];

	while (c > 0)
	{
		if (mHeap[p].key < tmp.key)
			break;
		else
		{
			mHeap[c] = mHeap[p];
			c = p;
			p = (c - 1) / 2;
		}
	}
	mHeap[c] = tmp;
}


template<class T>
int HuffmanHeap<T>::CopyOf(HuffmanTreeNode<T>* node)
{
	if (mSize == mCapacity)
		return -1;

	mHeap[mSize] = *node;
	FilterUp(mSize);
	mSize++;

	return 0;
}


template<class T>
HuffmanTreeNode<T>* HuffmanHeap<T>::DumpFromMinimum()
{
	if (mSize == 0)
		return NULL;

	HuffmanTreeNode<T>* node;
	if ((node = new HuffmanTreeNode<T>()) == NULL)
		return NULL;

	*node = mHeap[0];
	SwapNode(0, mSize - 1);
	FilterDown(0, mSize - 2);
	mSize--;

	return node;
}


template<class T>
void HuffmanHeap<T>::SwapNode(int i, int j)
{
	HuffmanTreeNode<T> tmp = mHeap[i];
	mHeap[i] = mHeap[j];
	mHeap[j] = tmp;
}

template<class T>
void HuffmanHeap<T>::Create(T a[], int size)
{
	mSize = size;
	mCapacity = size;
	mHeap = new HuffmanTreeNode<T>[size];

	for (int i = 0; i < size; i++)
	{
		mHeap[i].key = a[i];
		mHeap[i].parent = mHeap[i].left = mHeap[i].right = NULL;
	}

	for (int i = size / 2 - 1; i >= 0; i--)
	{
		FilterDown(i, size - 1);
	}
}


template<class T>
void HuffmanHeap<T>::Destroy()
{
	mSize = 0;
	mCapacity = 0;
	delete[] mHeap;
	mHeap = NULL;
}

#endif