#include "Arbre.h"

namespace za
{
	void TwoSum1(TNodeI& racine, int target)
	{

		std::unordered_map<int, bool> vis;
		std::stack<TNodeI> st;
		st.push(racine);
		vis[racine.val] = true;
		std::pair<int, int> p;
		bool exist = false;
		while (!st.empty())
		{
			auto tmp = st.top();
			st.pop();
			int remain = target - tmp.val;

			if (vis[remain])
			{
				p = { tmp.val , remain };
				exist = true;
				break;
				
			}
			vis[tmp.val] = true;
			if (tmp.l != nullptr && !vis[tmp.l->val])
			{
				st.push(*tmp.l);
			}
			if (tmp.r != nullptr && !vis[tmp.r->val])
			{
				st.push(*tmp.r);
			}

		}
		std::cout << "Two Sum DFS" << std::endl;
		std::cout << "Target: " << target << std::endl;
		if (exist)
		{
			std::cout << "Found"<< std::endl;
			std::cout << "Pair: ( " << p.first << " , " << p.second << " )" << std::endl;
		}
		else
		{
			std::cout << "Not Found" << std::endl;
		}
		std::cout << "Done" << std::endl;


	}

	void TwoSum2(TNodeI& racine, int target)
	{
		std::stack<TNodeI*> s;
		TNodeI* curr = &racine;
		std::vector<int> inOrderData;
		while (curr != nullptr|| !s.empty())
		{
			/* Reach the left most Node of the
			   curr Node */
			while (curr != nullptr)
			{
				/* place pointer to a tree node on
				   the stack before traversing
				  the node's left subtree */
				s.push(curr);
				curr = curr->l;
			}

			/* Current must be NULL at this point */
			curr = s.top();
			s.pop();
			inOrderData.push_back(curr->val);
			/* we have visited the node and its
			   left subtree.  Now, it's right
			   subtree's turn */
			curr = curr->r;

		}
		bool exist = false;
		int l = 0;
		int r = inOrderData.size() - 1;
		int summ = inOrderData[l] + inOrderData[r];

		while (summ != target)
		{
			summ = inOrderData[l] + inOrderData[r];
			//expand
			if (summ < target)
			{
				l++;
			}			
			if (summ > target)
			{
				r--;
			}
			if (r < 0 || l >= r)
			{
				exist = false;
				break;
			}
			if(summ == target)
			{
				exist = true;
				break;
			}

		}
		std::cout << "Two Sum Inorder" << std::endl;
		std::cout << "Target: " << target << std::endl;
		if (exist)
		{
			std::cout << "Found" << std::endl;
			std::cout << "Pair: ( " << inOrderData[l] << " , " << inOrderData[r] << " )" << std::endl;
		}
		else
		{
			std::cout << "Not Found" << std::endl;
		}
		std::cout << "Done" << std::endl;
		

		
	}

	void Inorder1(TNodeI* racine, std::vector<int>& dat)
	{
		if (racine == nullptr)
		{
			return ;
		}

		Inorder1(racine->l, dat);
		dat.push_back(racine->val);
		Inorder1(racine->r, dat);
		
		return;
	}
	void Preorder1(TNodeI* racine, std::vector<int>& dat)
	{
		if (racine == nullptr)
		{
			return;
		}

		dat.push_back(racine->val);
		Preorder1(racine->l, dat);
		Preorder1(racine->r, dat);

		return;
	}
	void Postorder1(TNodeI* racine, std::vector<int>& dat)
	{
		if (racine == nullptr)
		{
			return;
		}

		Postorder1(racine->l, dat);
		Postorder1(racine->r, dat);
		dat.push_back(racine->val);

		return;
	}

	void Inorder2(TNodeI* racine, std::vector<int>& dat)
	{
		std::stack<TNodeI*> st;
		st.push(racine);
		auto tmp = racine;

		while (tmp != nullptr || !st.empty())
		//while (!st.empty())
		{
			while (tmp != nullptr)
			{
				st.push(tmp);
				tmp = tmp->l;
			}

			tmp = st.top();
			st.pop();
			dat.push_back(tmp->val);
			tmp = tmp->r;


		}
	}
	void Preorder2(TNodeI* racine, std::vector<int>& dat)
	{
		std::stack<TNodeI*> st;
		st.push(racine);

		while (!st.empty())
		{
			auto tmp = st.top();
			st.pop();
			dat.push_back(tmp->val);

			if (tmp->r != nullptr)
			{
				st.push(tmp->r);
			}
			if (tmp->l != nullptr)
			{
				st.push(tmp->l);
			}

		}

	}
	void Postorder2(TNodeI* racine, std::vector<int>& dat)
	{
		std::stack<TNodeI*> st;
		st.push(racine);
		std::deque<int> tmpDat;
		while (!st.empty())
		{
			auto tmp = st.top();
			st.pop();
			tmpDat.push_front(tmp->val);

			if (tmp->l != nullptr)
			{
				st.push(tmp->l);
			}

			if (tmp->r != nullptr)
			{
				st.push(tmp->r);
			}


			while (!tmpDat.empty())
			{
				dat.push_back(tmpDat.front());
				tmpDat.pop_front();
			}
		}
	}
	void Levelorder1(TNodeI* racine, std::vector<int>& dat)
	{
		std::queue<TNodeI*>q;
		q.push(racine);

		while (!q.empty())
		{
			auto tmp = q.front();
			q.pop();

			dat.push_back(tmp->val);

			if (tmp->l != nullptr)
			{
				q.push(tmp->l);
			}
			if (tmp->r != nullptr)
			{
				q.push(tmp->r);
			}

		}
	}
}