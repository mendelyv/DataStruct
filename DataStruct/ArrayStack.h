#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define MAXSIZE 12
#include <iostream>

template <class T>
class ArrayStack 
{
public:
	ArrayStack();
	~ArrayStack();

	void Push(T value);
	T Pop();
	T Peek();

	int Size();
	bool IsEmpty();
private :
	T *arr;
	int count;
};


template <class T>
ArrayStack<T>::ArrayStack()
{
	arr = new T[MAXSIZE];
	count = 0;
	if (!arr)
		std::cout << "Array Malloc ERROR" << std::endl;
}


template <class T>
ArrayStack<T>::~ArrayStack()
{
	if (!arr) return;

	delete[] arr;
	count = 0;
	arr = NULL;
}


template <class T>
void ArrayStack<T>::Push(T value)
{
	arr[count++] = value;
}


template <class T>
T ArrayStack<T>::Pop()
{
	T ret = arr[count - 1];
	count--;
	return ret;
}

template <class T>
T ArrayStack<T>::Peek()
{
	return arr[count - 1];
}


template <class T>
int ArrayStack<T>::Size()
{
	return count;
}


template <class T>
bool ArrayStack<T>::IsEmpty()
{
	return count == 0;
}

#endif
