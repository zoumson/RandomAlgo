#include "ThreadedBT.h"

namespace za
{

    ThBiTri* search(ThBiTri* racine, int key) 
    {

        ThBiTri* ptr = racine;

        while (ptr != nullptr) 
        {

            if (ptr->val == key) 
            {
                // indicating that the element is found then
                return ptr;
            }
            else if (ptr->val < key) 
            {
                // moving to inorder predecessor of the current node 
                ptr = ptr->rChild;
            }
            else {
                // moving to inorder successor of the current node
                ptr = ptr->lChild;
            }

        }

        // if element is not found then we can return nullptr indicating element not 
        // found in the given binary search tree
        return nullptr;

    }

    // Insert a ThBiTri in Binary Threaded Tree
    ThBiTri* insert(ThBiTri* racine, int ikey)
    {
        // Searching for a ThBiTri with given value
        ThBiTri* ptr = racine;
        ThBiTri* par = nullptr; // Parent of key to be inserted
        while (ptr != nullptr) 
        {
            // If key already exists, return
            if (ikey == (ptr->val)) 
            {
                //std::cout << "Duplicate Key !\n";
                return racine;
            }

            par = ptr; // Update parent pointer

            // Moving on lChild subtree.
            if (ikey < ptr->val) 
            {
                if (ptr->lthread == false)
                {
                    ptr = ptr->lChild;
                }
                else
                {
                    break;
                }
            }

            // Moving on rChild subtree.
            else 
            {
                if (ptr->rthread == false)
                {
                    ptr = ptr->rChild;
                }
                else
                {
                    break;
                }
            }
        }

        // Create a new ThBiTri
        ThBiTri* tmp = new ThBiTri;
        tmp->val = ikey;
        tmp->lthread = true;
        tmp->rthread = true;

        if (par == nullptr) 
        {
            racine = tmp;
            tmp->lChild = nullptr;
            tmp->rChild = nullptr;
        }
        else if (ikey < (par->val)) 
        {
            tmp->lChild = par->lChild;
            tmp->rChild = par;
            par->lthread = false;
            par->lChild = tmp;
        }
        else 
        {
            tmp->lChild = par;
            tmp->rChild = par->rChild;
            par->rthread = false;
            par->rChild = tmp;
        }

        return racine;
    }

    // Returns inorder successor using lChild
    // and rChild children (Used in deletion)
    ThBiTri* inSucc(ThBiTri* ptr)
    {
        if (ptr->rthread == true)
        {
            return ptr->rChild;
        }

        ptr = ptr->rChild;
        while (ptr->lthread == false)
        {
            ptr = ptr->lChild;
        }

        return ptr;
    }

    // Returns inorder successor using rthread
    // (Used in inorder)
    ThBiTri* inorderSuccessor(ThBiTri* ptr)
    {
        // If rthread is set, we can quickly find
        if (ptr->rthread == true)
        {
            return ptr->rChild;
        }

        // Else return leftmost child of rChild subtree
        ptr = ptr->rChild;
        while (ptr->lthread == false)
        {
            ptr = ptr->lChild;
        }
        return ptr;
    }

    // Printing the threaded tree
    void inorder(ThBiTri* racine, std::vector<int>& values)
    {
        if (racine == nullptr)
        {
            return;
        }

        // Reach leftmost ThBiTri
        ThBiTri* ptr = racine;
        while (ptr->lthread == false)
        {
            ptr = ptr->lChild;
        }

        // One by one print successors
        while (ptr != nullptr) 
        {
            values.push_back(ptr->val);
            ptr = inorderSuccessor(ptr);
        }
    }

    ThBiTri* inPred(ThBiTri* ptr)
    {
        if (ptr->lthread == true)
        {
            return ptr->lChild;
        }

        ptr = ptr->lChild;
        while (ptr->rthread == false)
        {
            ptr = ptr->rChild;
        }
        return ptr;
    }

    // Here 'par' is pointer to parent ThBiTri and 'ptr' is
    // pointer to current ThBiTri.
    ThBiTri* case1(ThBiTri* racine, ThBiTri* par,
        ThBiTri* ptr)
    {
        // If ThBiTri to be deleted is racine
        if (par == nullptr)
        {
            racine = nullptr;
        }

        // If ThBiTri to be deleted is lChild
        // of its parent
        else if (ptr == par->lChild) 
        {
            par->lthread = true;
            par->lChild = ptr->lChild;
        }
        else 
        {
            par->rthread = true;
            par->rChild = ptr->rChild;
        }

        // Free memory and return new racine
        free(ptr);
        return racine;
    }

    // Here 'par' is pointer to parent ThBiTri and 'ptr' is
    // pointer to current ThBiTri.
    ThBiTri* case2(ThBiTri* racine, ThBiTri* par,
        ThBiTri* ptr)
    {
        ThBiTri* child;

        // Initialize child ThBiTri to be deleted has
        // lChild child.
        if (ptr->lthread == false)
        {
            child = ptr->lChild;
        }

        // ThBiTri to be deleted has rChild child.
        else
        {
            child = ptr->rChild;
        }

        // ThBiTri to be deleted is racine ThBiTri.
        if (par == nullptr)
        {
            racine = child;
        }

        // ThBiTri is lChild child of its parent.
        else if (ptr == par->lChild)
        {
            par->lChild = child;
        }
        else
        {
            par->rChild = child;
        }

        // Find successor and predecessor
        ThBiTri* s = inSucc(ptr);
        ThBiTri* p = inPred(ptr);

        // If ptr has lChild subtree.
        if (ptr->lthread == false)
        {
            p->rChild = s;
        }

        // If ptr has rChild subtree.
        else 
        {
            if (ptr->rthread == false)
            {
                s->lChild = p;
            }
        }

        free(ptr);
        return racine;
    }

    // Here 'par' is pointer to parent ThBiTri and 'ptr' is
    // pointer to current ThBiTri.
    ThBiTri* case3(ThBiTri* racine, ThBiTri* par,
        ThBiTri* ptr)
    {
        // Find inorder successor and its parent.
        ThBiTri* parsucc = ptr;
        ThBiTri* succ = ptr->rChild;

        // Find leftmost child of successor
        while (succ->lthread == false) 
        {
            parsucc = succ;
            succ = succ->lChild;
        }

        ptr->val = succ->val;

        if (succ->lthread == true && succ->rthread == true)
        {
            racine = case1(racine, parsucc, succ);
        }
        else
        {
            racine = case2(racine, parsucc, succ);
        }

        return racine;
    }

    // Deletes a key from threaded BST with given racine and
    // returns new racine of BST.
    ThBiTri* deleteFromThreadedBst(ThBiTri* racine, int target)
    {
        // Initialize parent as nullptr and
        // ThBiTri as racine.
        ThBiTri* par = nullptr, * ptr = racine;

        // Set true if key is found
        int found = 0;

        // Search key in BST : find ThBiTri and its
        // parent.
        while (ptr != nullptr) 
        {
            if (target == ptr->val) 
            {
                found = 1;
                break;
            }
            par = ptr;
            if (target < ptr->val) 
            {
                if (ptr->lthread == false)
                {
                    ptr = ptr->lChild;
                }
                else
                {
                    break;
                }
            }
            else 
            {
                if (ptr->rthread == false)
                {
                    ptr = ptr->rChild;
                }
                else
                {
                    break;
                }
            }
        }

        if (found == 0)
        {
            printf("target not present in tree\n");
        }

        // Two Children
        else if (ptr->lthread == false && ptr->rthread == false)
        {
            racine = case3(racine, par, ptr);
        }

        // Only Left Child
        else if (ptr->lthread == false)
        {
            racine = case2(racine, par, ptr);
        }

        // Only Right Child
        else if (ptr->rthread == false)
        {
            racine = case2(racine, par, ptr);
        }

        // No child
        else
        {
            racine = case1(racine, par, ptr);
        }

        return racine;
    }


    ThBiTri2* leftMostNode2(ThBiTri2* node)
    {
        if (node == nullptr) 
        {
            return nullptr;
        }
        else 
        {
            while (node->lChild != nullptr) 
            {
                node = node->lChild;
            }
            return node;
        }
    }
    void convert2(ThBiTri2* root)
    {
        inorder2(root, nullptr);
    }
    void inorder2(ThBiTri2* root, ThBiTri2* previous)
    {
        if (root == nullptr) 
        {
            return;
        }
        else 
        {
            inorder2(root->rChild, previous);
            if (root->rChild == nullptr && previous != nullptr) 
            {
                root->rChild = previous;
                root->rthread = true;
            }
            inorder2(root->lChild, root);
        }
    }
    void print2(ThBiTri2* root)
    {
        //first go to most left node
        ThBiTri2* current = leftMostNode2(root);
        //now travel using right pointers
        while (current != nullptr) 
        {
            std::cout << " " << current->val;
            //check if node has a right thread
            if (current->rthread)
            {
                current = current->rChild;
            }
            else // else go to left most node in the right subtree
            {
                current = leftMostNode2(current->rChild);
            }
        }
        std::cout << std::endl;
    }

}