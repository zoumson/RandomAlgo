#pragma once
#include <iostream>
#include "Algo.h"

namespace za
{
    typedef struct BinSearchT_
    {
        int val;
        struct BinSearchT_ * l, * r;

        // A utility function to create a new BST node
        BinSearchT_()
        {
            BinSearchT_(0);
        }

        BinSearchT_(int val_)
        {
            this->val = val_;
            this->l = this->r = nullptr;
        }

        //BinSearchT_(int val_, BinSearchT_* _l, BinSearchT_* _r)
        //{
        //    this->val = val_;
        //    this->l = _l;
        //    this->r = _r;
        //}

    } BinSearchT;

    //typedef struct TreeBin_ {
    //    int low_idx;
    //    int high_idx;
    //    BinSearchT* node;
    //    TreeBin_()
    //    {
    //        TreeBin_(0, 0, nullptr);
    //    }
    //    TreeBin_(int low, int high, BinSearchT* _node)
    //    {
    //        low_idx = low;
    //        high_idx = high;
    //        node = _node;
    //    }        
    //    

    //}TreeBin;
    /* A utility function to insert a new node with given key in BST */
    BinSearchT* insert(BinSearchT* racine, int key);
    BinSearchT* search(BinSearchT* racine, int key);
    BinSearchT* deletenode(BinSearchT* root, int k);
    void inorder(BinSearchT* root, std::vector<int>& values);
    void preorder(BinSearchT* root, std::vector<int>& values);
    void postorder(BinSearchT* root, std::vector<int>& values);
    BinSearchT* sortedArrayToBST1(std::vector<int>& arr,
            int start, int end);    
    BinSearchT* sortedArrayToBST2(std::vector<int>& arr);

    // Function returns the minimum number of swaps 
    // required to sort the array 
    int minSwaps(BinSearchT* node);
    /*
    Given a non-empty binary search tree,
    return the minimum data value found in that
    tree. Note that the entire tree does not need
    to be searched.
    */
    int minValue(BinSearchT* racine);

    /*
    Given a non-empty binary search tree,
    return the maximum data value found in that
    tree. Note that the entire tree does not need
    to be searched.
    */
    int maxValue(BinSearchT* racine);

    /* 
    This function traverse the skewed binary tree and
    stores its nodes pointers in vector nodes[] 
    */
    void buildInorderNodes(BinSearchT* root, std::vector<BinSearchT*>& nodes);

    /* 
    Recursive function to construct binary tree 
    */
    BinSearchT* buildBalancedBinaryTreeUtil(std::vector<BinSearchT*>& nodes, int start,
        int end);

    // This functions converts an unbalanced BST to 
    // a balanced BST 
    BinSearchT* buildBalancedBinaryTree(BinSearchT* racine);

    // This functions find Kth Minimum Element in BST
    int findKthMinimumElement(BinSearchT* root, int k);

    // function return sum of all element smaller than 
    // and equal to Kth smallest element 
    int ksmallestElementSumUtil(BinSearchT* racine, int k, int& count);


    // Wrapper over ksmallestElementSumUtil() 
    int ksmallestElementSum(BinSearchT* racine, int k);

    /*
        Binary Tree is one of the most used Tree Data Structure and is used in real life Software systems.

        Following are the Applications of Binary Tree:

        1. Binary Tree is used to as the basic data structure in Microsoft Excel and spreadsheets in usual.
        2. Binary Tree is used to implement indexing of Segmented Database.
        3. Splay Tree (Binary Tree variant) is used in implemented efficient cache is hardware and software systems.
        4. Binary Space Partition Trees are used in Computer Graphics, Back face Culling, 
        Collision detection, Ray Tracing and algorithms in rendering game graphics.
        5. Syntax Tree (Binary Tree with nodes as operations) are used to compute arithmetic expressions 
        in compilers like GCC, AOCL and others.
        6. Binary Heap (Binary Tree variant of Heap) is used to implement Priority Queue efficiently 
        which in turn is used in Heap Sort Algorithm.
        7. Binary Search Tree is used to search elements efficiently and used as a collision handling technique 
        in Hash Map implementations.
        8. Balanced Binary Search Tree is used to represent memory to enable fast memory allocation.
        9. Huffman Tree (Binary Tree variant) is used internally in a Greedy Algorithm for Data Compression 
        known as Huffman Encoding and Decoding.
        10. Merkle Tree/ Hash Tree (Binary Tree variant) is used in Blockchain implementations and p2p programs requiring signatures.
        11. Binary Tries (Tries with 2 child) is used to represent a routing data which vacillate efficient traversal.
        12. Morse code is used to encode data and uses a Binary Tree in its representation.
        13. Goldreich, Goldwasser and Micali (GGM) Tree (Binary Tree variant) is used compute 
        pseudorandom functions using an arbitrary pseudorandom generator.
        14. Scapegoat tree (a self-balancing Binary Search Tree) is used in implementing 
        Paul-Carole games to model a faulty search process.
        15. Treap (radomized Binary Search Tree)


        Why is Binary Tree is so widely used?
        Binary Tree is the most widely used Data Structure because:

        1. Binary Tree is the most simpliest and efficient data structure to be used in most Software Systems. 
        It is the properties of Binary Tree that makes it so widely used.

        2. N-ary Tree which is the generalization of Binary Tree is complex to implement and is rarely a better fit.

        3. Binary Tree can be implemented as an array using ideas of Binary Heap. Hence, the ideas of OOP (Object Oriented Programming) is not necessary for a safe implementation.

        4. There is a wide range of variants of Binary Tree which makes it very likely to find a suitable variant for a specific problem. For example, if we want a Data Structure where recently accessed elements are closer to the beginning of the data structure so that access is fast, then we have a variant of Binary Tree known as Splay Tree.

        Alternatives to Binary Tree
        Despite the wide use of Binary Tree, there are a few Data Structures that have found strong use case and Binary Tree cannot replace them in terms of performance.
        Alternatives to Binary Trees are:

        B-Tree and B+ Tree: used in indexing of database
        Space Partitioning Tree: For higher dimensional games
        Quadtree
        Tree pyramid (T-pyramid)
        Octree
        k-d (K dimensional) tree
        R-tree: to find shortest path or nearby objects in 3D graphs  
    
    */
}