#pragma once

#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__

#include <iostream>

//����
//��ʼ�����±�Ϊ0

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
	T* mHeap;//����
	int mCapacity;//������
	int mSize;//ʵ������

	// ���ѵ����µ����㷨
	void FilterDown(int start, int end);
	//���ѵ����ϵ����㷨����start��ʼ����ֱ��0��
	void FilterUp(int start);
};

template <class T>
MaxHeap<T>::MaxHeap()
{
	new (this)MaxHeap(30);//��ôд��������ʲô��
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
 * ���ѵ����ϵ����㷨(��start��ʼ����ֱ��0��������)
 *
 * ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
 *
 * ����˵����
 *     start -- ���ϵ��ڵ����ʼλ��(һ��Ϊ���������һ��Ԫ�ص�����)
 *
 * ����˵����������ڵ�ʱ��ͨ��ֱ�Ӳ��뵽�����β����Ȼ�󽫸��½ڵ㰴�����ѵ��������ϵ��������ʵ�λ��
 */
template <class T>
void MaxHeap<T>::FilterUp(int start)
{
	int c = start;//��ǰ�ڵ��λ��
	int p = (c - 1) / 2;//���ڵ��λ��
	T tmp = mHeap[c];//��ȡ������

	while (c > 0)
	{
		if (mHeap[p] >= tmp) //������ڵ�ȵ�ǰ�����ݴ󣬼��������ѵ����ԣ�����
			break;
		else//���С��
		{
			mHeap[c] = mHeap[p];//�����ڵ��ֵ������ǰ�ڵ�
			c = p;
			p = (p - 1) / 2;
		}
	}
	mHeap[c] = tmp;//���c�±�λ�ø�ֵΪ��ʼ��ֵ
}


template <class T>
int MaxHeap<T>::Insert(T data)
{
	//������
	if (mSize >= mCapacity)
		return -1;

	mHeap[mSize] = data;//�����ݲ����β
	FilterUp(mSize);
	mSize++;

	return 0;
}


/*
 * ���ѵ����µ����㷨
 *
 * ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
 *
 * ����˵����
 *     start -- ���µ��ڵ����ʼλ��(һ��Ϊ0����ʾ�ӵ�1����ʼ)
 *     end   -- ������Χ(һ��Ϊ���������һ��Ԫ�ص�����)
 */
template <class T>
void MaxHeap<T>::FilterDown(int start, int end)
{
	int c = start;	//��ǰ�ڵ���±�
	int l = 2 * c + 1;//��ǰ�ڵ�������±�
	T tmp = mHeap[c];//��ǰ�ڵ��ֵ

	while (l <= end)
	{
		             //l������		    l+1���Һ���
		if (l < end && mHeap[l] < mHeap[l + 1])
			l++;//���Һ�����ѡ��ֵ�ϴ��ߣ���mHeap[l + 1]
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

	mHeap[index] = mHeap[--mSize];//ʹ�����һ�����ݸ���
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