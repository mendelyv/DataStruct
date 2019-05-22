#pragma once

#ifndef __MINHEAP_H__
#define __MINHEAP_H__

#include <iostream>

//最小堆
//起始下标为0

template<class T>
class MinHeap
{
public:
	MinHeap();
	MinHeap(int capacity);
	~MinHeap();

	int GetIndex(T data);
	int Insert(T data);
	int Remove(T data);

	void Print();

private:
	T* mHeap;//数据数组指针
	int mCapacity;//总容量
	int mSize;//当前容量

	void FilterDown(int start, int end);
	void FilterUp(int start);
};


template<class T>
MinHeap<T>::MinHeap()
{
	new (this)MinHeap(30);
}


template<class T>
MinHeap<T>::MinHeap(int capacity)
{
	mSize = 0;
	mCapacity = capacity;
	mHeap = new T[mCapacity];
}


template<class T>
MinHeap<T>::~MinHeap()
{
	mSize = 0;
	mCapacity = 0;
	delete[] mHeap;
}


template<class T>
int MinHeap<T>::GetIndex(T data)
{
	for (int i = 0; i < mSize; i++)
	{
		if (data == mHeap[i])
			return i;
	}
	return -1;
}


template<class T>
void MinHeap<T>::FilterDown(int start, int end)
{
	int c = start;
	int l = c * 2 + 1;
	T tmp = mHeap[c];

	while (l <= end)
	{
		if (l < end && mHeap[l] > mHeap[l + 1])
			l++;//左右孩子中选择值较小者
		if (tmp <= mHeap[l])
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
void MinHeap<T>::FilterUp(int start)
{
	int c = start;
	int p = (c - 1) / 2;
	T tmp = mHeap[c];

	while (c > 0)
	{
		if (mHeap[p] <= tmp) //如果父节点比当前的数据小，即符合最小堆的特性，跳出
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
int MinHeap<T>::Insert(T data)
{
	if (mSize >= mCapacity)
		return -1;

	mHeap[mSize] = data;
	FilterUp(mSize);
	mSize++;

	return 0;
}


template<class T>
int MinHeap<T>::Remove(T data)
{
	if (mSize == 0)
		return -1;

	int index = GetIndex(data);
	if (index == -1)
		return -1;

	mHeap[index] = mHeap[--mSize];
	FilterDown(index, mSize - 1);
	
	return 0;
}


template <class T>
void MinHeap<T>::Print()
{
	for (int i = 0; i < mSize; i++)
		std::cout << mHeap[i] << " ";
}


#endif