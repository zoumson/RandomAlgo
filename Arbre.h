#pragma once
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


	//20-1 Succinct (0-1) Encoding of Binary Tree
	/* Idea:
		To implement this encoding we can first traverse the nodes of the tree in preorder traversal. 
		This should output the encoding of "1" for internal node and "0" for leaf nodes. 
		In case of the tree nodes containing values, we can store them in an array using preorder traversal.
		
	   Algo:
		1. We start by checking if the node is null or not.
		2. If it is null then we will append 0 to s.
		3. Else we append 1 to s.
		4. Then we append value of node to data array at nth index.
		5. Then we recursively call encoding function for left subtree and then for right subtree.


	*/
	void TriEnCoding(TNodeI* racine, std::deque<bool> &enCodeBitList, std::deque<int>& enCodeDataList);
	//20-2 Succinct (0-1) Decoding of Binary Tree
	/* 
		
	   Algo:
		1. We start by appending first bit of s to x and remove it from s
		2. If x is equivalent to 1 then we create new node n
		3. Then we remove first element of data and put in n.data
		4. We call recursively decoding function for left node and then for right node.
		5. Then we return n node.
		6. Else we return NULL


	*/
	TNodeI* TriDeCoding(std::deque<bool>& encodeBitList, std::deque<int>& encodeDataList);	
	//19-1 Array serialization
	/* 
	we declare an empty string t. Then using for loop we add the length of string to "l" 
	and push that value to string "t". 
	Then, we add delimeter or character (here "-") and the string to temp.
	So if the initial string was Opengenus, it would become 9-Opengenus.


	*/
	//Function to serialize a string array
	std::string SerializeArray(std::string s[], int l);
	//19-2 Array serialization
	/* 
	We start by initialising position with 0 and declaring length variable and an empty string t. 
	Then we use while loop to iterate from the element next to "-" in array. 
	If the position is returned greater than 0 then we store the length of string that 
	lies on previous index of "-". We subtracted 48 because '6' has the int value 54
	if we write '6'-'0' it evaluates to 54-48, or the int 6.
	Now, we append "t" with "s" from position + 1 till length of string. 
	Then, store the string t in d array. Now, initialise the string t as empty for next iteration.


	*/
	//Function to deserialize a string array
	std::string DeserializeArray(std::string s, std::string d[], int l);


	//19-1 Serialization of Binary Tree
	/*
	We used the preorder traversal and marked the null as "#" after converting the tree to single string.

	*/
	//Function to serialize a string array
	void TriSerializeHelper1(std::stringstream& ss, TNodeI* cur);
	std::string TriSerialize1(TNodeI* cur);	

	//19-4 Deserialization of Binary Tree
	/*
		We used the preorder traversal and marked the null as "#" after converting the tree to single string.

	*/
	void TriDeSerializeHelper1(std::stringstream& ss, TNodeI* cur);
	TNodeI* TriDeSerialize1(std::string data);


	//19-5 Serialization of Binary Tree
	/*
	    1. Serialization:

		Then, we have two functions, serialize and serializeRecursive.
		The serialize function calls the serializeRecursive function iteratively.
		Inside the serialize function, we create an output stream "oss".
		Then we call the serializeRecursive function with root and oss as arguments.

		Inside serializeRecursive function:

			The base condition is if the root is null, 
			the output string will be having value "X" to denote null node.
			If the node is not null then we insert the value of root into 
			output string and empty string for the space between two consecutive node values.
			Then, we recursively call the serializeRecurive function for traversing 
			all the nodes of the left subtree.
			Similarly, then we recursively call the serializeRecurive function for 
			traversing all the nodes of the right subtree.
			Once, the whole recurisve process is over, we return back to our Serialize function. 
			Now, we return the output string "oss" as a string.

	*/
	void TriSerializeHelper2(TNodeI* racine, std::ostringstream& os);
	std::string TriSerialize2(TNodeI* racine);
	//19-6 Deserialization of Binary Tree
	/*
	    1. Deserialization:
			Firstly, we have two functions deserialize and deserializeRecursive.
			Then, we have istringstream is(data), we pass the data in the input 
			string stream to handle the input strings.
			Then we return deserialization function by passing "is" that 
			contains the data of input string stream.

		Inside deserializeRecurisve  function:

			Firstly, initialise the string val. Then, put it in input stream.
			Whenever, the val is equivalent to  "X", representing the null node, 
			we return the nullptr. It is the base condition.
			If we do not have our base condition as true then 
			the recursive function allocates the memory for a new node.
			Similarly, we recursively iterate and reconstruct our 
			binary tree by initialising values to our nodes. 
			First, we call the function for left subtree and then for right subtree.
			At the end we return out root.

	*/
	TNodeI* TriDeSerializeHelper2(std::istringstream& is);
	TNodeI* TriDeSerialize2(std::string data);
	//21-1 Zig Zag Traversal of Binary Tree
	/*
	*/
	void TriZigZag1(TNodeI* racine, std::vector<int>& dat);
	//21-2 Zig Zag Traversal of Binary Tree
	/*
	*/
	void TriZigZag2(TNodeI* racine, std::vector<int>& dat);
	//21-3-1 Zig Zag Traversal of Binary Tree
	/*
		We will print the nodes in different levels in lterating order.
		We use a bool variable to change printing order of levels.
		If itr is equivalent to 1 then we print nodes left to right.
		Else we print nodes right to left.
		We will complement value of bool variabe in each iteration to change order.
	*/

	void TriZigZag3Level(TNodeI* racine, int level, bool l, std::vector<int>& dat);
	//21-3-2 Zig Zag Traversal of Binary Tree
	/*
		In this function we will check the height of a tree.
		We start by checking ig the node is null. If so then we return 0.
		Else we compute the height of each subtree. 
		In recrusive fashion we iterate the call left and right subtree.
		Then we check if left height is greater or right subtree height. 
		We return the greater height + 1.
	*/
	int TriZigZag3Height(TNodeI* racine);
	//21-3-3 Zig Zag Traversal of Binary Tree
	/*
		In this function we will print the zigzag traversal result. 
		We initialise the height of tree using height function defined above.
		Then we initialise boolean ltr with false.
		Then we have for loop from 1 till height of tree. 
		Here we call the Level function defined above in each iteration.
		We also revert ltr to traverse next level in opposite order
	*/
	void TriZigZag3(TNodeI* racine, std::vector<int>& dat);
	//21-4 Zig Zag Traversal of Binary Tree
	/*
		This is the iterative appproach. We will use two stacks for printing left to right stack.
		We use two stacks one for left to right and other for right to left.
		In each iteration, we have nodes of one level in one of the stack.
		We will print nodes, and then push nodes of next level in other stack.

		For the above tree, We check if the root is null or not. Since in the above tree 
		it is not the case, we initialise s1 and s2 stack. Then we push the root to s1 stack.
		Now we start iteration till s1 or s2 is not empty. 
		Then we have another while loop within it. It will iterate till s1 is not empty. 
		Then we have temp that will store the top node of s1. 
		Which right now will be the root node. Then we pop the root node 
		from the s1 stack and print the data of root node. 
		If the right of the root node is not null then s2 will store the value temp. 
		If the left of node is not null then we will store its value in s2.
		This will store values for right to left.
		Then we will enter another loop where we start 
		by initialising value of top of s2 in temp. 
		Then we pop top value of s2 and print its data. 
		If the left of temp node is not null then we will store its value in s1. 
		Then if the right of temp is not null then we will store its value in right of temp.
		This will store values for left to right.
	* 
	*/
	void TriZigZag4(TNodeI* racine, std::vector<int>& dat);

	//25 Checking if a Binary Tree is foldable
	/*
		We can check if a binary tree is foldable or not in two ways:

		By changing the left subtree to its mirror equivalent. 
		Then checking if the mirror is equivalent to te right subtree.
		Compare and check if right and left subtrees are mirrors of each other
	*
	*/
	//25-1  Checking if a Binary Tree is foldable
	/*
	Algorithm for Method 1:
		If tree is empty, return true.
		Convert left subtree to mirror image.
		If the right subtree is equivalent to mirror image 
		then return true else return false.
	*
	*/	
	//25-1-1  Mirror
	/*
		If the node is null then we will return.
		Else, first we traverse the left subtree in recursive fashion then the right subtree.
		We will swap the left and right node pointers.
	*
	*/
	void TriFoldable1Mirror(TNodeI* racine);	
	//25-1-2  Same
	/*
		If both a and b are null then return true.
		If a and b are not null and both left and right 
		nodes of both a and b are null then return true.
		Else return false.
	*
	*/
	bool TriFoldable1Same(TNodeI* node1,TNodeI* node2);	
	//25-1-3  foldable 1
	/*
		Here first we declare a boolean variable res.
		Then if root is null then return true.
		Then we call mirror function defined above for left subtree.
		Then in res we store the result of function same we defined above.
		Then we again recursively call the left node as argument in Mirror function.
		Return res.
	*
	*/

	bool TriFoldable1(TNodeI* racine);

	//25-2  Checking if a Binary Tree is foldable
	/*
	Algorithm for Method 2:
	*
	*/

	//25-2-1  check
	/*
		Check if both trees are empty then return true.
		If only one of them is empty then return false.
		If one subtree is mirror of other then return true.

	*/
	bool TriFoldable2Check(TNodeI* node1, TNodeI* node2);
	//25-2-2  foldable 2
	/*
		First we will check if the trees are null then return true.
		Else check if the left and right subtree are the mirror
		of each other using the check function defined above.

	*/
	bool TriFoldable2(TNodeI* racine);	
	
	//26 Check if 2 Binary Trees are isomorphic
	/*
		Two Binary Trees are known as isomorphic if one of them 
		can be obtained from the other one by series of flipping 
		of nodes, swapping the children both left and right of 
		number of nodes. 
		Any number of nodes at all levels can swap their child nodes.

	*/	
	//26-1 Check if 2 Binary Trees are isomorphic
	/*
		In approach 1, 
		we need to traverse both trees first.
		To be isomorphic we have following conditions:
			Data of n1 is equivalent to n2
			One of following is true for children of n1 and n2:
				Left child of n1 is isomorphic to left child of n2.
				Right child of n1 is isomorphic to right child of n2
				Left child of n1 is isomorphic to right child of n2
				Right child of n1 is isomorphic to left child of n2


		In the function we start by checking if both roots are null or not. 
		If they are null then the trees are isomorphic. 
		Hence we return true if so.
		Then we check if one of n1 and n2 are null then the trees are not isomorphic.
		Then we start to check for both trees being isomorphic if none of above conditions hold true:
				We start a loop till value of n1 is not equivalent to val of n2
				We call the Isomorphic function recursively to check :
					The subtree rooted at these nodes have not been flipped , 
					Both of these subtrees have to be isomorphic
					The subtrees rooted at these nodes have been flipped


	*/
	bool TriIsomorphic1(TNodeI* racine1,TNodeI* racine2);	
	
	//26-2 Check if 2 Binary Trees are isomorphic
	/*
		In approach 2, 
			we will traverse the trees iteratively using 
			level order traversal and store that in a queue. 
			At each level we will iterate through array 
			to check whether each value exist on map or not.

			We will traverse the trees iteratively using level order traversal and store that in a queue.
				The conditions to be checked are:
					- The values of nodes is same
					- The number of nodes at each level is same
			We have to check the size of queue to ensure that the second condition is true. 
			We will store the nodes of each level of first tree as val. 
			For second tree store the nodes of the tree in vector. 
			In case of repetitive values, we will decrease the value to keep track of 
			how many nodes with same value exist at given level. If value become zero 
			then it shows that the first tree only has this much number of nodes. 
			At each level we will iterate through array to check whether each value exist on map or not. 
			There are 3 key conditions:

				-	If the key is not found then first tree does not have node found in other tree 
					does not have node at given level
				-	If key is found but value is negative then second tree has more nodes with 
					same value as first one
				-	If size of the map is not zero then it means there are some keys left. 
					Hence the first tree has node that does not match any node in other tree

			Function Isomorphic:
				We check if both roots are null then the tree is isomorphic
				Else we check if one node is false
				Then we start to enqueue the roots of both trees if above conditions are false
				Then we start a while loop till either queue is empty
					- We check if number of nodes are not same at given level
					- Then in another loop we dequeue the nodes
					- We check if the value exists in the map
					- Then we enqueue the child nodes
				Then we iterate through each node to check if it exists. We do this at each level
				Finally we check if there is any key remaining then we return false
				Else return true
	*/
	bool TriIsomorphic2(TNodeI* racine1,TNodeI* racine2);	

	//27  Convert Binary Tree to Circular Doubly Linked list
	/*
		To convert binary tree to circular doubly linked list, 
		we will take left node as previous pointer and right node as next pointer. 
		The order of nodes in Doubly Linked List must be same as in inorder of 
		the given binary tree. 
		The very first node of inorder traversal will become the head of the doubly linked list.

		We need to check following conditions:

			-If left subtree exists then process left subtree to DLL. 
			 We will use recursion to convert left subtree to DLL. 
			 Then we will find inorder predecessor (left most node in left subtree) of root in left subtree. Then we will make inorder predecessor as previous of root.
			-If right subtree exists then we follow below conditions to process it. 
			 Recursively convert right subtree to DLL. 
			 Find inorder successor of root in right subtree. 
			 Make inorder successor as next of root. 
			 Make root as previous of inorder successor. 
			 Find leftmost node and return that as head of dll.


		We have two main approaches:

		   -In first approaches we will use two functions, first is function convert. 
		    We will use inorder traversal to convert the binary tree. 
			We will form the doubly linked list by using convert function.
		   -In next approach, we will traverse the tree in inorder fashion. 
		   Then we will keep track of each node we visit.


	*/
	
	//27-1  Convert Binary Tree to Circular Doubly Linked list
	/*
		In this approach we will use two functions, first is function convert. 
		In convert function we will use inorder traversal to convert the binary tree. 
		In next function, dll we will form the doubly linked list by using convert function.

		Function convert:
			In this we first check if the nodes are null or not.
			Then we convert the left subtree and link it to the root. Then we will convert the left subtree.
			Then we will find the inorder predecessor. After this loop, left points to the inorder predecessor.
			Make root as next of predecessor and predecessor as previous of root.
			Then we convert right subtree and link it to the root.
			Then we will convert the right subtree.
			Then we will find the inorder successor. After the loop, right will point to the inorder successor.
			Make root as previous of successor.
			Make successor as next of root.

	*/

	TNodeI* TriToCircularDoublyLinkedList1();	

	//27-2  Convert Binary Tree to Circular Doubly Linked list
	/*
		In this approach we will use two functions, first is function convert. 
		In convert function we will use inorder traversal to convert the binary tree. 
		In next function, dll we will form the doubly linked list by using convert function.

		Function convert:
			In this we first check if the nodes are null or not.
			Then we convert the left subtree and link it to the root. Then we will convert the left subtree.
			Then we will find the inorder predecessor. After this loop, left points to the inorder predecessor.
			Make root as next of predecessor and predecessor as previous of root.
			Then we convert right subtree and link it to the root.
			Then we will convert the right subtree.
			Then we will find the inorder successor. After the loop, right will point to the inorder successor.
			Make root as previous of successor.
			Make successor as next of root.

	*/


	TNodeI* TriConvertCircularDoublyLinkedList2(TNodeI* racine, TNodeI** head, TNodeI** tail);
	TNodeI* TriCircularDoublyLinkedList2(TNodeI* racine);

	//27-4  Convert Binary Tree to Circular Doubly Linked list
	/*
		In this approach, we will do inorder traversal of binary tree. 
		While inorder traversal we will keep track of the previously visited nodes in prev variable. 
		For each node that has been visited we make it next of prev and previous of this node as prev. 
		Instead of static used in below implementation we can also use double pointer or refernce pointer.

		Function convert:
			We start by checking if the root is null. If so then we retrun.
			Else Initialise the previously visited node as NULL.
			We have taken it static for accessibility of same value in all recusive calls.
			Then we recusively convert the left subtree
			Then we convert the node
			Then we convert the right subtree.

	*/
	
	void TriCircularDoublyLinkedList4(TNodeI* racine, TNodeI** head);

	//28-1  Left Skewed Binary Tree
	/*
		If all nodes are having a left child or no child at all then 
		it can be called a left skewed binary tree. 
		In this tree all children at right side remain null.

	*/
	
	void TriLeftSkewed(TNodeI* racine, std::vector<int> values);

	//28-2  Right Skewed Binary Tree
	/*
		If all nodes are having a right child or no child at all then 
		it can be called a right skewed binary tree. 
		In this tree all children at left side remain null.

	*/
	
	void TriRightSkewed(TNodeI* racine, std::vector<int> values);

	//29  Check if a Binary Tree is skewed or not
	/*
		For each node N, check the following:
		If both left and right child nodes are present, it is not a valid skewed tree.
		If the node has only one left child node then we check its left child node
		If the node has only one right child node then we check its right child node
		If there are no child nodes, it is a valid node of a skewed tree

	*/
	
	bool TriSkewedCheck(TNodeI* racine);

	//30  Convert a Binary Tree to a Skewed Binary Tree
	/*
		We can convert binary tree into two types of skewed binary trees:

			-Increasing Skewed Binary Trees
			-Decreasing Skewed Binary Trees

		Case 1 : Increasing Order
			We will do inorder traversal, as inorder traversal of a Binary Search 
			Tree provides us increasing sequence of values of nodes.
			Using above logic, the left node traversal will give us smaller values.
			Then after traversal of left subtree, 
			we will add previous node of skewed tree to our root node.
			For the larger values, now we traverse the right subtree.

		Case 2 : Decreasing Order
			Recursion of the right node will be done first in order to get larger values first.
			Then we will connect the root node after the previous node.
			At the end we traverse the left subtree for smaller values 
			since the tree should be skewed in decreasing order.
	*/
	
	void TriSkewedConv(TNodeI* racine, int k);
}
