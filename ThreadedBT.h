#pragma once
#pragma once
#pragma once
#include <iostream>
#include "Algo.h"

namespace za
{
	typedef struct ThBiTri_ 
	{
		struct ThBiTri_ * lChild, * rChild;
		int val;

		// True if left pointer points to predecessor
		// in Inorder Traversal
		bool lthread;

		// True if right pointer points to predecessor
		// in Inorder Traversal
		bool rthread;

		ThBiTri_()
		{
			this->val = 0;
			this->lChild = nullptr;
			this->rChild = nullptr;
		}

		ThBiTri_(int val_)
		{
			this->val = val_;
			this->lChild = nullptr;
			this->rChild = nullptr;
		}


	} ThBiTri;	
	
	typedef struct ThBiTri_2 
	{
		struct ThBiTri_2 * lChild, * rChild;
		int val;
		// True if right pointer points to predecessor
		// in Inorder Traversal
		bool rthread;

		ThBiTri_2()
		{
			this->val = 0;
			this->lChild = nullptr;
			this->rChild = nullptr;
		}

		ThBiTri_2(int val_)
		{
			this->val = val_;
			this->lChild = nullptr;
			this->rChild = nullptr;
		}

	} ThBiTri2;

	ThBiTri* search(ThBiTri* racine, int key);
	ThBiTri* insert(ThBiTri* racine, int ikey);
	ThBiTri* inSucc(ThBiTri* ptr);
	ThBiTri* inorderSuccessor(ThBiTri* ptr);
	void inorder(ThBiTri* racine, std::vector<int>& values);
	ThBiTri* inPred(ThBiTri* ptr);
	ThBiTri* case1(ThBiTri* racine, ThBiTri* par,
		ThBiTri* ptr);
	ThBiTri* case2(ThBiTri* racine, ThBiTri* par,
		ThBiTri* ptr);
	ThBiTri* case3(ThBiTri* racine, ThBiTri* par,
		ThBiTri* ptr);
	ThBiTri* deleteFromThreadedBst(ThBiTri* racine, int target);

	ThBiTri2* leftMostNode2(ThBiTri2* node);
	void convert2(ThBiTri2* root);
	void inorder2(ThBiTri2* root, ThBiTri2* previous);
	void print2(ThBiTri2* root);
}