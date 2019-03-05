#ifndef __ARRAY_QUEUE_H__
#define __ARRAY_QUEUE_H__

#include <iostream>

template <class T>
class ArrayQueue
{
public:
	ArrayQueue();
	~ArrayQueue();

	void Add(T value);
	T Front();
	T Pop();
	int Size();
	bool IsEmpty();

private:
	T *arr;
	int count;

protected:
	int MAXSIZE;
};


template <class T>
ArrayQueue<T>::ArrayQueue()
{
	MAXSIZE = 12;
	count = 0;
	arr = new T[MAXSIZE];
	if (!arr) std::cout << "Array Malloc ERROR" << std::endl;
}


template <class T>
ArrayQueue<T>::~ArrayQueue()
{
	if (!arr) return;

	delete[] arr;
	arr = NULL;
	count = 0;
}


template <class T>
void ArrayQueue<T>::Add(T value)
{
	arr[count++] = value;
}


template <class T>
T ArrayQueue<T>::Front()
{
	return arr[0];
}


template <class T>
T ArrayQueue<T>::Pop()
{
	T ret = arr[0];
	count--;
	for (int i = 1; i <= count; i++)
	{
		arr[i - 1] = arr[i];
	}
	return ret;
}


template <class T>
int ArrayQueue<T>::Size()
{
	return count;
}


template <class T>
bool ArrayQueue<T>::IsEmpty()
{
	return count == 0;
}

#endif