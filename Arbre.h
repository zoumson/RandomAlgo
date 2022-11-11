#pragma once
#include <iostream>
#include "Algo.h"

namespace za
{
	template <typename T>
	struct GTriNode
	{
		T val;
		std::vector<GTriNode*> childreen;
		int childrenNum;
		GTriNode()
		{
			this->val = T();
			this->childrenNum = 0;
		}		
		 
		GTriNode(T val_)
		{
			this->val = val_;
			this->childrenNum = 0;
		}

	};

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




	typedef GTriNode<int> GTNodeI;
	typedef GTriNode<std::string> GTNodeS;
	typedef GTriNode<double> GTNodeD;


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

	void Inversion1(TNodeI* racine);
	void Inversion2(TNodeI* racine);
	void Inversion3(TNodeI* racine);

	//3. Types of view in Binary Tree
	/* Different Types of Views in Binary Tree are :
		Left View
		Right View
		Top View
		Bottom View
	*/


	//5. Converting Inorder+Preorder to Binary Tree 
	/* Steps :
		First we pick the current node from Preorder traversal using the preIndex and increment preIndex
		If that node has no children then we will return
		Else we find the index of this node in Inorder traversal
		Using the index in the Inorder traversal, we will construct the left and right subtree
	*/

	TNodeI* BinTreeFromPreInorder(std::vector<int>& inOrder, std::vector<int>& postOrder, int& currIdx, int lIdx, int rIdx);
	//TNodeI* BinTreeFromPreInorder(std::vector<int>& inOrder, std::vector<int>& preOrder, int lIdx, int rIdx);

	//6. Height of  Binary Tree 
	/* Steps :
		If tree is empty then height of tree is 0
		else Start from the root and, 
			Find the maximum depth of left sub-tree recursively
			Find the maxium depth of right sub-tree recursively
			Maxium depth of this two is (left and right subtree) height of binary tree
	*/

	int HeightTree(TNodeI* racine);


	//7. Level of each node in  Binary Tree from root 
	/* Steps :
		Set level of root node as 1
		Pop the first element in the queue and enqueue all the nodes which are directly connected to the popped element
		Set the level of all the element which are enqueued in the previos Step to 1 more than element popped in the second step
	*/

	void LevelFromRoot(GTNodeI* racine);
	

	//8. Diameter of a Binary Tree
	/* There can be two possibilities for the longest path of a tree
	*	It passes through the root
		It doesn't pass through the root

	Steps for recursion:
		Undirected graph
		If the node that is passed in the recursive function is null, then return zero
		Calculate the height of the left subtree
		Calculate the height of the right subtree
		If the diameter passes through the root node, then the no. of nodes in the path will be : Left subtree height + Right subtree height + 1
		However, if it doesn't pass through the root node, then the diameter will be max(left subtree diameter, right subtree diameter)

	*/

	int TriDiameter1(TNodeI* racine);

	//8. Diameter of a Binary Tree
	/* 2 DFS


	Steps:
		Undirected graph
		Start at the root node and find the farthest node from it using BFS
		Consider this farthest node to be the start node of the longest path
		Find the farthest node from the start node using BFS
		This farthest node will be the end node of the longest path

	*/

	int TriDiameter2(GTNodeI* racine);

	//13. Universal Binary Tree
	/* Top to Bottom 


	Steps:
		When the subtree's both left and right nodes values are equal to root's value
		When they are leaves i.e. left and right nodes are null
		When the left or right node is null but the existing right or left node has value equal to the root's value.
		When the subtree doesnt satisfy these three conditions , then it is not a univalue subtree

	*/

	bool TriUniversal(TNodeI* racine, int& count);

	//14. Counting subtrees where nodes sum to a specific value
	/* Preorder trasversal


	Steps:
			X=Specified value
			count=Subtrees count

			Store all nodes in a stack in postorder fashion.
			Select the top and check if its left and right nodes exists.
			If yes then check if the node's value is equal to X.
			If the value=X then increment the count.
			If No then:
			Store the left,right nodes in a stack by calling postorder function and derive 
			the sum by adding all the top elements and popping them up.
			Check if their sum=X.If yes then increment the count.
			Pop the top and continue same steps with the next node until the stack is empty.

	*/

	int TriCountSubtreesum(TNodeI* racine, int sumVal);
	//15. Find if a given Binary Tree is a Sub-Tree of another Binary Tree
	/* Preorder trasversal


	Steps:
			1: Find out the preorder and inorder traversals of 'Target' and save them in arrays.
			2: Find out the preorder and inorder traversals of 'Source' and save them in arrays.
			3: If the arrays of 'Source' are substrings of respective arrays of 'Target' then its a sub-tree else not.

	*/

	bool TriSubTriOfEachOther(TNodeS* source, TNodeS* target);


	//13. Balanced Binary Tree
	/* Top to Bottom


	Steps:
			The left subtree is balanced for each node.
			Right subtree is also balanced for each node.
			The absolute height difference of left and right subtree is not more than 1
			Further,all empty trees are always height balanced

	*/

	int TriBalance(TNodeI* racine);

	//16. Check if a Binary Tree has duplicate values
	/* Top to Bottom


	Steps:
			We traverse the given tree, for every node, 
			we check if it's data value already exists in the Hash Map.
			If it does not exist,then we put it into the Hash Map.
			If it exists already i.e. there is a duplicate and we return true.

	*/
	bool TriDuplicate1(TNodeI* racine, std::unordered_set<int>& vis);
	//16. Check if a Binary Tree has duplicate values
	/* Trasversal and keep data in array
	* check if array has duplicate

	*/
	bool TriDuplicate2(TNodeI* racine);

	//16. Find nodes which are at a distance k from root in a Binary Tree
	/* Top to Bottom/recursion


		We will make a recursion function, let's say printNodes(node * root, int k) .
		This function will recursively call itself in its left and right children, with a distance of k-1.
		Finally, when k=0 is encountered, we will print the value in the current node. 
		This node will be at a distance of k from the root.

	*/
	void TriNodesAtDistanceKFromRoot1(TNodeI* racine, int k, std::vector< TNodeI*>& levelKNodes);

	//16. Find nodes which are at a distance k from root in a Binary Tree
	/* Level Order


		Count tree level

	*/
	void TriNodesAtDistanceKFromRoot2(TNodeI* racine, int k, std::vector< TNodeI*>& levelKNodes);


	//24-1 Level trasversal using recursion
	void Levelorder2(TNodeI* racine, std::vector<int>& dat);

	//24-2 Level trasversal each level with its node iterative
	void Levelorder3(TNodeI* racine, std::map<int, std::vector<TNodeI*>>& m);
	//24-3 Level trasversal each level with its node recursion
	void Levelorder4(TNodeI* racine, std::map<int, std::vector<TNodeI*>>& m);


	//16. Ancestors
	/* Preorder and map


	*/

	void TriAncestor1(TNodeI* racine, TNodeI* node, std::vector< TNodeI*>& ances);	
	bool TriAncestor2(TNodeI* racine, TNodeI* node, std::vector< TNodeI*>& ances);

}