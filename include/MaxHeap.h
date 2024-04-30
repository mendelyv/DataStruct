#pragma once

#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__

#include <iostream>

//最大堆
//起始索引下标为0

template <class T>
class MaxHeap
{
public:
	MaxHeap();
	MaxHeap(int capacity);
	~MaxHeap();

	int GetIndex(T data);
	int Remove(T data);
	int Insert(T data);

	void Print();

private:
	T* mHeap;//数据
	int mCapacity;//总容量
	int mSize;//实际容量

	// 最大堆的向下调整算法
	void FilterDown(int start, int end);
	//最大堆的向上调整算法（从start开始向上直到0）
	void FilterUp(int start);
};

template <class T>
MaxHeap<T>::MaxHeap()
{
	new (this)MaxHeap(30);//这么写的意义是什么？
}


template <class T>
MaxHeap<T>::MaxHeap(int capacity)
{
	mSize = 0;
	mCapacity = capacity;
	mHeap = new T[mCapacity];
}


template <class T>
MaxHeap<T>::~MaxHeap()
{
	mSize = 0;
	mCapacity = 0;
	delete[] mHeap;
}


template <class T>
int MaxHeap<T>::GetIndex(T data)
{
	for (int i = 0; i < mSize; i++)
	{
		if (data == mHeap[i])
			return i;
	}
	return -1;
}


/*
 * 最大堆的向上调整算法(从start开始向上直到0，调整堆)
 *
 * 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
 *
 * 参数说明：
 *     start -- 被上调节点的起始位置(一般为数组中最后一个元素的索引)
 *
 * 函数说明：当插入节点时，通常直接插入到数组的尾部，然后将该新节点按照最大堆的特性向上调整到合适的位置
 */
template <class T>
void MaxHeap<T>::FilterUp(int start)
{
	int c = start;//当前节点的位置
	int p = (c - 1) / 2;//父节点的位置
	T tmp = mHeap[c];//获取到数据

	while (c > 0)
	{
		if (mHeap[p] >= tmp) //如果父节点比当前的数据大，即满足最大堆的特性，跳出
			break;
		else//如果小于
		{
			mHeap[c] = mHeap[p];//将父节点的值赋给当前节点
			c = p;
			p = (p - 1) / 2;
		}
	}
	mHeap[c] = tmp;//最后将c下标位置赋值为开始的值
}


template <class T>
int MaxHeap<T>::Insert(T data)
{
	//堆已满
	if (mSize >= mCapacity)
		return -1;

	mHeap[mSize] = data;//将数据插入表尾
	FilterUp(mSize);
	mSize++;

	return 0;
}


/*
 * 最大堆的向下调整算法
 *
 * 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
 *
 * 参数说明：
 *     start -- 被下调节点的起始位置(一般为0，表示从第1个开始)
 *     end   -- 截至范围(一般为数组中最后一个元素的索引)
 */
template <class T>
void MaxHeap<T>::FilterDown(int start, int end)
{
	int c = start;	//当前节点的下标
	int l = 2 * c + 1;//当前节点的左孩子下标
	T tmp = mHeap[c];//当前节点的值

	while (l <= end)
	{
		             //l是左孩子		    l+1是右孩子
		if (l < end && mHeap[l] < mHeap[l + 1])
			l++;//左右孩子中选择值较大者，即mHeap[l + 1]
		if (tmp >= mHeap[l])
			break;
		else
		{
			mHeap[c] = mHeap[l];
			c = l;
			l = 2 * c + 1;
		}
	}
	mHeap[c] = tmp;
}


template <class T>
int MaxHeap<T>::Remove(T data)
{
	int index;
	if (mSize == 0)
		return -1;

	index = GetIndex(data);
	if (index == -1)
		return -1;

	mHeap[index] = mHeap[--mSize];//使用最后一个数据覆盖
	FilterDown(index, mSize - 1);

	return 0;
}


template <class T>
void MaxHeap<T>::Print()
{
	for (int i = 0; i < mSize; i++)
		std::cout << mHeap[i] << " ";
}


#endif