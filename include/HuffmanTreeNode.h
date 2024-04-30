#pragma once

#ifndef __HUFFMANTREE_NODE_H__
#define __HUFFMANTREE_NODE_H__

template<class T>
class HuffmanTreeNode
{
public:
	T key;
	HuffmanTreeNode* left;
	HuffmanTreeNode* right;
	HuffmanTreeNode* parent;

	HuffmanTreeNode() {}
	HuffmanTreeNode(T k, HuffmanTreeNode* l, HuffmanTreeNode* r, HuffmanTreeNode* p):key(k), left(l), right(r), parent(p) {}
};




#endif