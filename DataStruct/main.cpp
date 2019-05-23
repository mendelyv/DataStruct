#pragma region Pointer复习

//#include <iostream>
//using namespace std;
//
//class tmp
//{
//public: 
//	int value;
//
//	tmp(int a) :value(a) {}
//};
//
//void Change(int* a, int* b)
//{
//	*a = 11;
//	*b = 22;
//}
//
//void Change(tmp* &a, tmp* &b)
//{
//	a->value = 10000;
//	b->value = 20000;
//}
//
//int main()
//{
//	//int a = 90, b = 100;
//	//int* i = &a;
//	//int* j = &b;
//
//	//Change(i, j);
//
//	//cout << *i << "   " << *j << endl;
//	//cout << a << "   " << b << endl;
//
//	tmp* a = new tmp(10);
//	tmp* b = new tmp(20);
//
//	Change(a, b);
//
//	cout << a->value << endl;
//	cout << b->value << endl;
//
//	system("pause");
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
////值传递
//void change1(int n) {
//	cout << "值传递--函数操作地址" << &n << endl;         //显示的是拷贝的地址而不是源地址 
//	n++;
//}
//
////引用传递
//void change2(int& n) {
//	cout << "引用传递--函数操作地址" << &n << endl;
//	n++;
//}
////指针传递
//void change3(int* n) {
//	cout << "指针传递--函数操作地址 " << n << endl;
//	*n = *n + 1;
//}
//int main() {
//	int n = 10;
//	cout << "实参的地址" << &n << endl;
//	change1(n);
//	cout << "after change1() n=" << n << endl;
//	change2(n);
//	cout << "after change2() n=" << n << endl;
//	change3(&n);
//	cout << "after change3() n=" << n << endl;
//
//	system("pause");
//	return 0;
//}

#pragma endregion

#pragma region 位运算

// & : 按位与，两个位都为1时，结果才为1
// | ：按位或，两个位都为0时，结果才为0
// ^ : 按位异或，两个位相同为0，相异为1
// ~ : 按位取反，1变0，0变1
// << : 按位左移，各二进位全部左移n位，高位丢弃，低位补0
// >> : 按位右移，各二进位全部右移n位，无符号数高位补0，有符号数：补符号位(算数右移) 或 补0(逻辑右移)

//#include <iostream>
//
//bool IsEvenNum(int num)
//{
//	return (num & 1) == 0 ? true : false;
//}
//
//int main()
//{
//	int a = 5;
//	if (IsEvenNum(a))
//		std::cout << "偶数" << std::endl;
//	else
//		std::cout << "奇数" << std::endl;
//
//	system("pause");
//}

#pragma endregion

#pragma region 二叉搜索树的测试
//#include <iostream>
//#include "BSTree.h"
//
//static int arr[] = { 1,5,4,3,2,6 };
//#define TBL_SIZE(a) ((sizeof(a)) / (sizeof(a[0])))
//
//int main()
//{
//	int i, ilen;
//	BSTree<int>* tree = new BSTree<int>();
//	
//	std::cout << "== 依次添加: ";
//	ilen = TBL_SIZE(arr);
//	for (i = 0; i < ilen; i++)
//	 {
//	     std::cout << arr[i] << " ";
//	     tree->Insert(arr[i]);
//	 }
//	
//	std::cout << "\n== 前序遍历: ";
//	tree->PreOrder();
//
//	std::cout << "\n== 中序遍历: ";
//	tree->InOrder();
//
//	std::cout << "\n== 后序遍历: ";
//	tree->PostOrder();
//	std::cout << std::endl;
//	//
//	std::cout << "== 最小值: " << tree->Minimum() << std::endl;
//	std::cout << "== 最大值: " << tree->Maximum() << std::endl;
//	std::cout << "== 树的详细信息: " << std::endl;
//	tree->Print();
//
//	std::cout << "\n== 删除根节点: " << arr[3];
//	tree->Remove(arr[3]);
//
//	std::cout << "\n== 中序遍历: ";
//	tree->InOrder();
//	std::cout << std::endl;
//	// 销毁二叉树
//	tree->Destroy();
//	system("pause");
//	return 0;
//}
#pragma endregion

#pragma region 数组栈的测试
//#include <iostream>
//#include "ArrayStack.h"
//
//int main()
//{
//	ArrayStack<int> *stack = new ArrayStack<int>();
//
//	stack->Push(1);
//	stack->Push(2);
//	stack->Push(3);
//
//	while (!stack->IsEmpty())
//	{
//		std::cout << stack->Pop() << std::endl;
//	}
//
//	system("pause");
//}
#pragma endregion

#pragma region 数组队列的测试
//#include <iostream>
//#include "ArrayQueue.h"
//
//int main()
//{
//	ArrayQueue<int> *queue = new ArrayQueue<int>();
//
//	queue->Add(1);
//	queue->Add(2);
//	queue->Add(3);
//
//	while (!queue->IsEmpty())
//	{
//		std::cout << queue->Pop() << std::endl;
//	}
//
//	system("pause");
//}
#pragma endregion

#pragma region AVL树的测试

//#include "AVLTree.h"
//#include <iostream>
//
//static int arr[] = { 3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9 };
//#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )
//
//int main()
//{
//	int i, iLen;
//	AVLTree<int>* tree = new AVLTree<int>();
//
//	std::cout << "== 依次添加：";
//	iLen = TBL_SIZE(arr);
//	for (i = 0; i < iLen; i++)
//	{
//		std::cout << arr[i] << " ";
//		tree->Insert(arr[i]);
//	}
//
//	std::cout << "\n== 前序遍历：";
//	tree->PreOrder();
//
//	std::cout << "\n== 中序遍历：";
//	tree->InOrder();
//
//	std::cout << "\n== 后序遍历：";
//	tree->PostOrder();
//	std::cout << std::endl;
//
//	std::cout << "== 高度：" << tree->Height() << std::endl;
//	std::cout << "== 最小值：" << tree->Minimum() << std::endl;
//	std::cout << "== 最大值：" << tree->Maximum() << std::endl;
//	std::cout << "== 树的详细信息：" << std::endl;
//	tree->Print();
//
//	i = 8;
//	std::cout << "\n== 删除根节点：" << i;
//	tree->Remove(i);
//
//	std::cout << "\n== 高度：" << tree->Height();
//	std::cout << "\n== 中序遍历：";
//	tree->InOrder();
//	std::cout << "\n== 树的详细信息：" << std::endl;
//	tree->Print();
//
//	tree->Destroy();
//
//	system("pause");
//
//	return 0;
//
//
//}

#pragma endregion

#pragma region 伸展树的测试

//#include <iostream>
//#include "SplayTree.h"
//using namespace std;
//
//static int arr[] = { 10,50,40,30,20,60 };
//#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )
//
//int main()
//{
//	int i, ilen;
//	SplayTree<int>* tree = new SplayTree<int>();
//
//	cout << "== 依次添加: ";
//	ilen = TBL_SIZE(arr);
//	for (i = 0; i < ilen; i++)
//	{
//		cout << arr[i] << " ";
//		tree->Insert(arr[i]);
//	}
//
//	cout << "\n== 前序遍历: ";
//	tree->PreOrder();
//
//	cout << "\n== 中序遍历: ";
//	tree->InOrder();
//
//	cout << "\n== 后序遍历: ";
//	tree->PostOrder();
//	cout << endl;
//
//	cout << "== 最小值: " << tree->Minimum() << endl;
//	cout << "== 最大值: " << tree->Maximum() << endl;
//	cout << "== 树的详细信息: " << endl;
//	tree->Print();
//
//	i = 30;
//	cout << "\n== 旋转节点(" << i << ")为根节点";
//	tree->Splay(i);
//	cout << "\n== 树的详细信息: " << endl;
//	tree->Print();
//
//	// 销毁二叉树
//	tree->Destroy();
//
//	system("pause");
//
//	return 0;
//}

#pragma endregion

//#pragma region 最大堆的测试
//
//#include <iostream>
//#include "MaxHeap.h"
//
//int main()
//{
//	int a[] = { 10, 40, 30, 60, 90, 70, 20, 50, 80 };
//	int i, len = (sizeof(a)) / (sizeof(a[0]));
//	MaxHeap<int>* tree = new MaxHeap<int>();
//
//	std::cout << "== 依次添加: ";
//	for (i = 0; i < len; i++)
//	{
//		std::cout << a[i] << " ";
//		tree->Insert(a[i]);
//	}
//
//	std::cout << "\n== 最 大 堆: ";
//	tree->Print();
//
//	i = 85;
//	tree->Insert(i);
//	std::cout << "\n== 添加元素: " << i;
//	std::cout << "\n== 最 大 堆: ";
//	tree->Print();
//
//	i = 90;
//	tree->Remove(i);
//	std::cout << "\n== 删除元素: " << i;
//	std::cout << "\n== 最 大 堆: ";
//	tree->Print();
//	std::cout << std::endl;
//
//	system("pause");
//
//	return 0;
//}
//
//#pragma endregion


#pragma region 最小堆测试

//#include <iostream>
//#include "MinHeap.h"
//
//int main()
//{
//	int a[] = { 80, 40, 30, 60, 90, 70, 10, 50, 20 };
//	int i, len = (sizeof(a)) / (sizeof(a[0]));
//	MinHeap<int>* tree = new MinHeap<int>();
//
//	std::cout << "== 依次添加: ";
//	for (i = 0; i < len; i++)
//	{
//		std::cout << a[i] << " ";
//		tree->Insert(a[i]);
//	}
//
//	std::cout << "\n== 最 小 堆: ";
//	tree->Print();
//
//	i = 15;
//	tree->Insert(i);
//	std::cout << "\n== 添加元素: " << i;
//	std::cout << "\n== 最 小 堆: ";
//	tree->Print();
//
//	i = 10;
//	tree->Remove(i);
//	std::cout << "\n== 删除元素: " << i;
//	std::cout << "\n== 最 小 堆: ";
//	tree->Print();
//	std::cout << std::endl;
//
//	system("pause");
//
//	return 0;
//}

#pragma endregion



#pragma region 霍夫曼树测试

#include <iostream>
#include "HuffmanTree.h"
using namespace std;


int main()
{
	int a[] = { 5,6,8,7,15 };
	int i, ilen = sizeof(a) / (sizeof(a[0]));
	HuffmanTree<int>* tree = new HuffmanTree<int>();

	cout << "== 添加数组: ";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";

	tree->Create(a, ilen);

	cout << "\n== 前序遍历: ";
	tree->PreOrder();

	cout << "\n== 中序遍历: ";
	tree->InOrder();

	cout << "\n== 后序遍历: ";
	tree->PostOrder();
	cout << endl;

	cout << "== 树的详细信息: " << endl;
	tree->Print();

	// 销毁二叉树
	tree->Destroy();

	system("pause");
	return 0;
}

#pragma endregion