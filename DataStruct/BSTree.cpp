//#include "BSTree.h"
//
//template <class T>
//BSTree<T>::BSTree():mRoot(NULL)
//{
//
//}
//
//
//template <class T>
//BSTree<T>::~BSTree()
//{
//
//}
//
////前序遍历二叉树    中左右
//template <class T>
//void BSTree<T>::PreOrder(BSTNode<T>* tree) const
//{
//	if (tree != NULL)
//	{
//		std::cout << tree->key << " ";
//		PreOrder(tree->left);
//		PreOrder(tree->right);
//	}
//}
//
//template <class T>
//void BSTree<T>::PreOrder()
//{
//	PreOrder(mRoot);
//}
//
////中序遍历二叉树   左中右
//template <class T>
//void BSTree<T>::InOrder(BSTNode<T>* tree) const
//{
//	if (tree != NULL)
//	{
//		InOrder(tree->left);
//		std::cout << tree->key << " ";
//		InOrder(tree->right);
//	}
//}
//
//template <class T>
//void BSTree<T>::InOrder()
//{
//	InOrder(mRoot);
//}
//
////后序遍历二叉树   左右中
//template <class T>
//void BSTree<T>::PostOrder(BSTNode<T>* tree) const
//{
//	if (tree != NULL)
//	{
//		InOrder(tree->left);
//		InOrder(tree->right);
//		std::cout << tree->key << " ";
//	}
//}
//
//template <class T>
//void BSTree<T>::PostOrder()
//{
//	PostOrder(mRoot);
//}
//
////(递归实现) 查找二叉树中键值为key的节点
//template <class T>
//BSTNode<T>* BSTree<T>::Search(BSTNode<T>* tree, T key) const
//{
//	if (tree == NULL || tree->key == key)
//		return tree;
//	if (key < tree->key)
//		return Search(tree->left, key);
//	else
//		return Search(tree->right, key);
//}
//
//template <class T>
//BSTNode<T>* BSTree<T>::Search(T key)
//{
//	return Search(mRoot, key);
//}
//
////(非递归实现) 查找二叉树中键值为key的节点、
//template <class T>
//BSTNode<T>* BSTree<T>::IterativeSearch(BSTNode<T>* tree, T key) const
//{
//	while (tree != NULL && tree->key != key)
//	{
//		if (key < tree->key)
//			tree = tree->left;
//		else
//			tree = tree->right;
//	}
//
//	return tree;
//}
//
//template <class T>
//BSTNode<T>* BSTree<T>::IterativeSearch(T key)
//{
//	return IterativeSearch(mRoot, key);
//}
//
////查找最小节点
//template <class T>
//BSTNode<T>* BSTree<T>::Minimum(BSTNode<T>* tree)
//{
//	if (tree == NULL)
//		return NULL;
//	while (tree->left != NULL)
//		tree = tree->left;
//	return tree;
//}
//
//template <class T>
//T BSTree<T>::Minimum()
//{
//	BSTNode<T> *p = Minimum(mRoot);
//	if (p != NULL)
//		return p->key;
//	return (T)NULL;
//}
//
////查找最大节点
//template <class T>
//BSTNode<T>* BSTree<T>::Maximum(BSTNode<T>* tree)
//{
//	if (tree == NULL)
//		return NULL;
//	while (tree->right != NULL)
//		tree = tree->right;
//	return tree;
//}
//
//template <class T>
//T BSTree<T>::Maximum()
//{
//	BSTNode<T> *p = Maximum(mRoot);
//	if (p != NULL)
//		return p->key;
//	return (T)NULL;
//}
//
//#pragma region 重点查看的部分
//template <class T>
//BSTNode<T>* BSTree<T>::Successor(BSTNode<T> *node)
//{
//	//如果该节点存在右孩子，那么该节点的后继节点为 其右孩子为根的子树的最小节点
//	if (node->right != NULL)
//		return Minimum(node->right);
//
//	//如果没有右孩子，有两种情况
//	//1.该节点是一个左孩子，那他的后继节点为他的父节点
//	//2.该节点是一个右孩子，那查找该节点的最低的父节点，且这个父节点还要具有左孩子，这个父节点就是该节点的后继节点
//	BSTNode<T> *y = node->parent;
//	while (y != NULL && node == y->right)
//	{
//		node = y;
//		y = y->parent;
//	}
//	return y;
//}
//
///*找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。*/
//template < class T>
//BSTNode<T>* BSTree<T>::Predecessor(BSTNode<T> *node)
//{
//	// 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
//	if (node->left != NULL)
//		return Maximum(node->left);
//	// 如果x没有左孩子。则x有以下两种可能：
//	// (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
//	// (01) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
//	BSTNode<T>* y = node->parent;
//	while ((y != NULL) && (node == y->left))
//	{
//		node = y;
//		y = y->parent;
//	}
//
//	return y;
//}
//#pragma endregion
//
////插入二叉树中，tree二叉树的根节点，z插入的节点
//template <class T>
//void BSTree<T>::Insert(BSTNode<T>* &tree, BSTNode<T>* z)
//{
//	BSTNode<T> *y = NULL;
//	BSTNode<T> *x = tree;
//
//	//查找z的插入位置
//	while (x != NULL)
//	{
//		y = x;
//		if (z->key < x->key)
//			x = x->left;
//		else
//			x = x->right;
//	}
//
//	z->parent = y;
//	if (y == NULL) tree = z;
//	else if (z->key < y->key) y->left = z;
//	else y->right = z;
//}
//
//
//template <class T>
//void BSTree<T>::Insert(T key)
//{
//	BSTNode<T> *z = NULL;
//	if ((z = new BSTNode<T>(key, NULL, NULL, NULL)) == NULL) return;
//	insert(mRoot, z);
//}
//
//
////删除节点，返回删除的节点数据   tree二叉树的根   z删除的节点
//template <class T>
//BSTNode<T>* BSTree<T>::Remove(BSTNode<T>* &tree, BSTNode<T> *z)
//{
//	BSTNode<T> *x = NULL;
//	BSTNode<T> *y = NULL;
//
//	if (z->left == NULL || z->right == NULL)
//		y = z;
//	else
//		y = Successor(z);
//
//	if (y->left != NULL)
//		x = y->left;
//	else
//		x = y->right;
//
//	if (x != NULL)
//		x->parent = y->parent;
//
//	if (y->parent == NULL)
//		tree = x;
//	else if (y == y->parent->left)
//		y->parent->left = x;
//	else
//		y->parent->right = x;
//
//	if (y != z)
//		z->key = y->key;
//
//	return y;
//}
//
//template <class T>
//void BSTree<T>::Remove(T key)
//{
//	BSTNode<T> *z, *node;
//	if (z = Search(mRoot, key) != NULL)
//		if (node = Remove(mRoot, z) != NULL)
//			delete node;
//}
//
//template <class T>
//void BSTree<T>::Destroy(BSTNode<T>* &tree)
//{
//	if (tree == NULL)
//		return;
//	if (tree->left != NULL)
//		return Destroy(tree->left);
//	if (tree->right != NULL)
//		return Destroy(tree->right);
//
//	delete tree;
//	tree = NULL;
//}
//
//template <class T>
//void BSTree<T>::Destroy()
//{
//	Destroy(mRoot);
//}
//
//template <class T>
//void BSTree<T>::Print(BSTNode<T> *tree, T key, int direction)
//{
//	if (tree != NULL)
//	{
//		if (direction == 0)
//			std::cout << std::setw(2) << tree->key << " is root" << std::endl;
//		else
//			std::cout << std::setw(2) << tree->key << " is " << std::setw(2) << key << "`s" << std::setw(12) << (direction == 1 ? "right child" : "left child") << std::endl;
//		Print(tree->left, tree->key, -1);
//		Print(tree->right, tree->key, 1);
//	}
//}
//
//template <class T>
//void BSTree<T>::Print()
//{
//	if (mRoot != NULL)
//		Print(mRoot, mRoot->key, 0);
//}