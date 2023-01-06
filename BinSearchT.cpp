#include "BinSearchT.h"

namespace za
{


    /* A utility function to insert a new node with given key in BST */
    BinSearchT* insert(BinSearchT* racine, int key) 
    {
        if (racine == nullptr)
        {
            return new BinSearchT(key);
        }
        else
        {
            BinSearchT* cur;
            if (key <= racine->val)
            {
                cur = insert(racine->l, key);
                racine->l = cur;
            }
            else
            {
                cur = insert(racine->r, key);
                racine->r = cur;
            }
        }
            return racine;
    }
    BinSearchT* search(BinSearchT* racine, int key)
    {
        if (racine == nullptr || racine->val == key)
        {
            return racine;
        }

        // Key is greater than root's data 
        if (racine->val < key)
        {
            return search(racine->r, key);
        }

        // Key is smaller than root's data 
        return search(racine->l, key);
    }

    BinSearchT* deletenode(BinSearchT* root, int k)
    {
        // Base case 
        if (root == nullptr)
        {
            return root;
        }
        //If root->data is greater than k then we delete the root's subtree
        if (root->val > k) 
        {
            root->l = deletenode(root->l, k);
            return root;
        }
        else if (root->val < k) 
        {
            root->r = deletenode(root->r, k);
            return root;
        }


        // If one of the children is empty 
        if (root->l == nullptr) 
        {
            BinSearchT* temp = root->r;
            delete root;
            return temp;
        }
        else if (root->r == nullptr) 
        {
            BinSearchT* temp = root->l;
            delete root;
            return temp;
        }
        else 
        {
            BinSearchT* Parent = root;
            // Find successor of the node
            BinSearchT* succ = root->r;
            while (succ->l != nullptr) 
            {
                Parent = succ;
                succ = succ->l;
            }

            if (Parent != root)
            {
                Parent->l = succ->r;
            }
            else
            {
                Parent->r = succ->r;
            }

            // Copy Successor Data  
            root->val = succ->val;

            // Delete Successor and return root 
            delete succ;
            return root;
        }
};

    void inorder(BinSearchT* root, std::vector<int> & values)
    {
        if (root == NULL)
        {
            return;
        }

        //First recur on left subtree 
        inorder(root->l, values);
        //Then read the data of child
        values.push_back(root->val);
        // Recur on the right subtree
        inorder(root->r, values);
    }
    void preorder(BinSearchT* root, std::vector<int>& values)
    {
        if (root == nullptr)
        {
            return;
        }

        //First read the data of child
        values.push_back(root->val);
        //cout << root->val << " ";
        //Then recur on left subtree 
        preorder(root->l, values);
        //Then Recur on the right subtree
        preorder(root->r, values);
    }
    void postorder(BinSearchT* root, std::vector<int>& values)
    {
        if (root == nullptr)
        {
            return;
        }

        //Then recur on left subtree 
        postorder(root->l, values);
        //Then Recur on the right subtree
        postorder(root->r, values);
        //First read the data of child
        values.push_back(root->val);
        //cout << root->val << " ";

    }
    BinSearchT* sortedArrayToBST1(std::vector<int>& arr,
        int start, int end)
    {
        //If starting index goes beyond end index then return NULL
        if (start > end)
        {
            return nullptr;
        }

        //Compute the middle index and make it as root.
        int mid = (start + end) / 2;
        BinSearchT* root = new BinSearchT(arr[mid]);

        //Recursively create left and right subtrees.
        root->l = sortedArrayToBST1(arr, start, mid - 1);
        root->r = sortedArrayToBST1(arr, mid + 1, end);

        //Return the root element which is the middle element of the list
        return root;
    }

    BinSearchT* sortedArrayToBST2(std::vector<int>& arr)
    {

        typedef struct BinSearchTLH_ 
        {
            int idxLow;
            int idxHigh;
            BinSearchT* node;

            BinSearchTLH_(int _idxLow, int _idxHigh, BinSearchT* _node)
            {
                this->idxLow = _idxLow;
                this->idxHigh = _idxHigh;
                node = _node;
            }

            BinSearchTLH_() : BinSearchTLH_(0, 0, nullptr) {};

        }BinSearchTLH;

        int n = arr.size();

        if (n == 0)
        {
            return nullptr;
        }
        
        std::stack<BinSearchTLH*> st;

        BinSearchT* racine = new  BinSearchT(arr[(n - 1) / 2]);

        BinSearchTLH* nodeLeftRight = new BinSearchTLH(0, n - 1, racine);
        st.push(nodeLeftRight);

        while (!st.empty())
        {
            BinSearchTLH* tmp = st.top();
            st.pop();
            int mid = tmp->idxLow + (tmp->idxHigh - tmp->idxLow) / 2;

            if (mid > tmp->idxLow)
            {
                BinSearchT* nodeLeft = new BinSearchT(arr[tmp->idxLow + (mid - 1 - tmp->idxLow) / 2]);
                //BinSearchT* node = new BinSearchT(A[(mid - 1 ) / 2]);
                //tmp.node.left_idx = node;
                tmp->node->l = nodeLeft;
                nodeLeftRight = new BinSearchTLH(tmp->idxLow, mid - 1, nodeLeft);
                st.push(nodeLeftRight);
            }

            if (mid < tmp->idxHigh) 
            {
                BinSearchT* nodeRight = new BinSearchT(arr[mid + 1 + (tmp->idxHigh - mid - 1) / 2]);
                //BinSearchT* node = new BinSearchT(A[tmp->high_idx / 2]);

                tmp->node->r = nodeRight;
                nodeLeftRight = new BinSearchTLH(mid + 1, tmp->idxHigh, nodeRight);
                st.push(nodeLeftRight);
            }

        }
        return racine;
    }
    // Function returns the minimum number of swaps 
    // required to sort the array 
    int minSwaps(BinSearchT* racine)
    {
        std::vector<int> arr;
        inorder(racine, arr);
        int n = arr.size();
        // Create an array of pairs where first 
        // element is array element and second element 
        // is position of first element 
        std::vector<std::pair<int, int>> arrPos;
        for (int i = 0; i < n; i++)
        {
            arrPos.push_back({ arr[i] , i });
            //arrPos[i].first = arr[i];
            //arrPos[i].second = i;
        }

        // Sort the array by array element values to 
        // get right position of every element as second 
        // element of pair. 
        //std::sort(arrPos, arrPos + n);
        std::sort(arrPos.begin(), arrPos.end());

        // To keep track of visited elements. Initialize 
        // all elements as not visited or false. 
        std::vector<bool> vis(n, false);

        // Initialize result 
        int ans = 0;

        // Traverse array elements 
        for (int i = 0; i < n; i++)
        {
            // already swapped and corrected or 
            // already present at correct pos 
            if (vis[i] || arrPos[i].second == i)
            {
                continue;
            }

            // find out the number of  node in 
            // this cycle and add in ans 
            int cycle_size = 0;
            int j = i;
            while (!vis[j])
            {
                vis[j] = true;
                j = arrPos[j].second;
                cycle_size++;
            }

            // Update answer by adding current cycle.  
            if (cycle_size > 0)
            {
                ans += (cycle_size - 1);
            }
        }

        return ans;
    }

    /* 
    Given a non-empty binary search tree,
    return the minimum data value found in that
    tree. Note that the entire tree does not need
    to be searched. 
    */
    int minValue(BinSearchT* node)
    {
        BinSearchT* current = node;

        /* loop down to find the leftmost leaf */
        while (current->l != NULL)
        {
            current = current->l;
        }
        return(current->val);
    }
    /* 
    Given a non-empty binary search tree,
    return the maximum data value found in that
    tree. Note that the entire tree does not need
    to be searched. 
    */
    int maxValue(BinSearchT* node)
    {
        BinSearchT* current = node;

        /* loop down to find the leftmost leaf */
        while (current->r != nullptr)
        {
            current = current->r;
        }
        return(current->val);
    }

    /* This function traverse the skewed binary tree and
   stores its nodes pointers in vector nodes[] */
    void buildInorderNodes(BinSearchT* racine, std::vector<BinSearchT*>& nodes)
    {
        // Base case 
        if (racine == nullptr)
        {
            return;
        }

        // Store nodes in Inorder (which is sorted 
        // order for BST) 
        buildInorderNodes(racine->l, nodes);
        nodes.push_back(racine);
        buildInorderNodes(racine->r, nodes);
    }

    /* Recursive function to construct binary tree */
    BinSearchT* buildBalancedBinaryTreeUtil(std::vector<BinSearchT*>& nodes, int start,
        int end)
    {
        // base case 
        if (start > end)
        {
            return nullptr;
        }

        /* Get the middle element and make it root */
        int mid = (start + end) / 2;
        BinSearchT* racine = nodes[mid];

        /* Using index in Inorder traversal, construct
           left and right subtress */
        racine->l = buildBalancedBinaryTreeUtil(nodes, start, mid - 1);
        racine->r = buildBalancedBinaryTreeUtil(nodes, mid + 1, end);

        return racine;
    }

    // This functions converts an unbalanced BST to 
    // a balanced BST 
    BinSearchT* buildBalancedBinaryTree(BinSearchT* racine)
    {
        // Store nodes of given BST in sorted order 
        std::vector<BinSearchT*> nodes;
        buildInorderNodes(racine, nodes);

        // Constucts BST from nodes[] 
        int n = nodes.size();
        return buildBalancedBinaryTreeUtil(nodes, 0, n - 1);
    }

    // This functions find Kth Minimum Element in BST
    int findKthMinimumElement(BinSearchT* racine, int k)
    {
        // Store nodes of given BST in sorted order 
        std::vector<BinSearchT*> nodes;
        buildInorderNodes(racine, nodes);

        return nodes[k - 1]->val;
    }



    // function return sum of all element smaller than 
    // and equal to Kth smallest element 
    int ksmallestElementSumUtil(BinSearchT* racine, int k, int& count)
    {
        //in order trasversal
        // Base cases 
        if (racine == nullptr)
        {
            return 0;
        }
        if (count > k)
        {
            return 0;
        }

        // Compute sum of elements in left subtree 
        int res = ksmallestElementSumUtil(racine->l, k, count);
        if (count >= k)
        {
            return res;
        }

        // Add root's data 
        res += racine->val;
        // Add current Node 
        count++;

        if (count == k)
        {
            return res;
        }
        //res +=  ksmallestElementSumUtil(racine->r, k, count);
        // If count is less than k, return right subtree Nodes 
        return res + ksmallestElementSumUtil(racine->r, k, count);
    }

    //for recursive function need a wrapper
    // Wrapper over ksmallestElementSumUtil() 
    int ksmallestElementSum(BinSearchT* racine, int k)
    {
        int count = 0;
        int kSum = ksmallestElementSumUtil(racine, k, count);
        //no return before
        //check
        return kSum;
    }


}