#pragma once
#include <iostream>
#include "Algo.h"

namespace za
{
	template <typename T>
	struct TriNode
	{
		T val;
		TriNode* l;
		TriNode* r;

		TriNode()
		{
			this->val = T();
			this->l = nullptr;
			this->r = nullptr;
		}		
		
		TriNode(T val_)
		{
			this->val = val_;
			this->l = nullptr;
			this->r = nullptr;
		}

	};
	typedef TriNode<int> TNodeI;
	typedef TriNode<std::string> TNodeS;
	typedef TriNode<double> TNodeD;
	//1. Two Sum Problem in Binary Search Tree

	/* Given a Binary Search Treeand an integer k,
		we have to determine if there exist two nodes 
		in the the BST with sum of values equal to the given target.
		The input is root of the treeand output can be true or false.
		Problem Statement
			Approach 1: Using DFS and hashtable
			Approach 2 : Using Inorder traversal
			Approach 3 : Using Augmented BST
	*/
	void TwoSum1(TNodeI& racine, int target);
	void TwoSum2(TNodeI& racine, int target);

	//2. Invert / Reverse a Binary Tree
	/* Inverting a binary tree is producing another binary tree 
		as output where all the left and right nodes of all non-leaf 
		nodes of the original binary tree are interchanged. 
		The inverted binary tree is also known as a Mirror tree.
		Methods of Inversion
			Recursion
			Iterative solution using stack
			Iterative solution using queue
	*/



	//4. Traverse a Binary Tree (Inorder , Preorder , Postorder)
	/* Depth first traversals of Binary tree:
		Inorder traversal: left, root, right
		Preorder traversal: root, left, right
		Postorder traversal: left, right, root
	*/

	void Inorder1(TNodeI* racine, std::vector<int>& dat);
	void Preorder1(TNodeI* racine, std::vector<int>& dat);
	void Postorder1(TNodeI* racine, std::vector<int>& dat);

	void Inorder2(TNodeI* racine, std::vector<int>& dat);
	void Preorder2(TNodeI* racine, std::vector<int>& dat);
	void Postorder2(TNodeI* racine, std::vector<int>& dat);


	//24. Traverse a Binary Tree (Level order)
	void Levelorder1(TNodeI* racine, std::vector<int>& dat);





}