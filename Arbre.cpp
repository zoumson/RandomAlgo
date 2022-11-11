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
		//st.push(racine);
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

	void Inversion1(TNodeI* racine)
	{
		if (racine == nullptr)
		{
			return;
		}

		auto tmp = racine->l;
		racine->l = racine->r;
		racine->r = tmp;
		Inversion1(racine->l);
		Inversion1(racine->r);

	}
	void Inversion2(TNodeI* racine)
	{
		std::stack< TNodeI*> st;
		st.push(racine);

		while (!st.empty())
		{
			auto curr = st.top();
			st.pop();

			auto tmp = curr->l;
			curr->l = curr->r;
			curr->r = tmp;

			if (curr->l != nullptr)
			{
				st.push(curr->l);
			}

			if (curr->r != nullptr)
			{
				st.push(curr->r);
			}


		}
	}
	void Inversion3(TNodeI* racine)
	{
		std::queue<TNodeI*> q;
		q.push(racine);

		while (!q.empty())
		{
			auto curr = q.front();
			q.pop();

			auto tmp = curr->l;
			curr->l = curr->r;
			curr->r = tmp;

			if (curr->l != nullptr)
			{
				q.push(curr->l);
			}
			if (curr->r != nullptr)
			{
				q.push(curr->r);
			}

		}
	}

	TNodeI* BinTreeFromPreInorder(std::vector<int>& inOrder, std::vector<int>& preOrder, int& currPreIdx, int lIdx, int rIdx)
	{
		//static int currPreIdx = 0;
		if (lIdx > rIdx)
		{
			return nullptr;
		}
		//current root
		int currNodeVal = preOrder[currPreIdx];

		//next root
		currPreIdx++;
		TNodeI* racine = new TNodeI(currNodeVal);

		//leaf node
		if (lIdx == rIdx)
		{
			return racine;
		}


		auto currNodeValIt = std::find(inOrder.begin() + lIdx, inOrder.begin() + rIdx, currNodeVal);
		int currInIdx = std::distance(inOrder.begin(), currNodeValIt);


		racine->l = BinTreeFromPreInorder(inOrder, preOrder, currPreIdx, lIdx, currInIdx - 1);
		racine->r = BinTreeFromPreInorder(inOrder, preOrder, currPreIdx, currInIdx + 1, rIdx);

		return racine;


	}

	int HeightTree(TNodeI* racine)
	{
		if (racine == nullptr)
		{
			//return -1;
			return 0;
		}

		int lH = HeightTree(racine->l);
		int rH = HeightTree(racine->r);
		int currH = 1;
		currH += lH > rH ? lH : rH;

		return currH;


	}
	void LevelFromRoot(GTNodeI* racine)
	{
		std::queue< GTNodeI*> q;
		std::map< GTNodeI*, int> lv;

		lv[racine] = 0;
		q.push(racine);

		while (!q.empty())
		{
			auto tmp = q.front();
			q.pop();

			for (auto child : tmp->childreen)
			{
				q.push(child);
				lv[child] = lv[tmp] + 1;
			}
			// For binary tree
			/*if (tmp->l != nullptr)
			{
				lv[tmp->l] = lv[tmp] + 1;
			}

			if (tmp->r != nullptr)
			{
				lv[tmp->r] = lv[tmp] + 1;
			}*/

		}

		std::cout << "Level for each  node\n";
		std::cout << "\tval \tlevel" << std::endl;
		for (auto nod : lv)
		{
			std::cout << "\t" << nod.first->val << " \t" << nod.second << std::endl;
		}

	}
	int TriDiameter1(TNodeI* racine)
	{
		if (racine == nullptr)
		{
			return 0;
		}

		int lH = HeightTree(racine->l);
		int rH = HeightTree(racine->r);
		int diamPassRoot = lH + rH + 1;

		int lD = TriDiameter1(racine->l);
		int rD = TriDiameter1(racine->r);

		int diamDontPassRoot = lD > rD ? lD : rD;
		int diam = diamPassRoot > diamDontPassRoot ? diamPassRoot : diamDontPassRoot;

		return diam;
	}
	int TriDiameter2(GTNodeI* racine)
	{
		std::queue< GTNodeI*> st1, st2;
		std::map< GTNodeI*, bool> vis1, vis2;
		std::map< GTNodeI*, int> dist1, dist2;

		//first bfs
		st1.push(racine); 
		vis1[racine] = true;
		dist1[racine] = 1;
		int longPath1 = -1, longPath2 = -1;
		GTNodeI* s1 = racine;
		while (!st1.empty())
		{
			auto tmp = st1.front();
			st1.pop();
			if (dist1[tmp] > longPath1)
			{
				longPath1 = dist1[tmp];
				s1 = tmp;
			}
			for (auto child : tmp->childreen)
			{
				if (!vis1[child])
				{
					st1.push(child);
					vis1[child] = true;
					dist1[child] = dist1[tmp] + 1;
				}
			}

		}
		

		//second bfs
		GTNodeI* s2 = s1;
		st2.push(s2);
		vis2[s2] = true;
		dist2[s2] = 1;

		while (!st2.empty())
		{
			auto tmp = st2.front();
			st2.pop();
			if (dist2[tmp] > longPath2)
			{
				longPath2 = dist2[tmp];
				s2 = tmp;
			}
			for (auto child : tmp->childreen)
			{
				if (!vis2[child])
				{
					st2.push(child);
					vis2[child] = true;
					dist2[child] = dist2[tmp] + 1;
				}
			}

		}

		std::cout << "from node " << s1->val << " to node " << s2->val << std::endl;
		return longPath2;

	}
	bool TriUniversal(TNodeI* racine, int& count)
	{
		if (racine == nullptr)
		{
			return true;
		}

		bool isL = TriUniversal(racine->l, count);
		bool isR = TriUniversal(racine->r, count);

		if (!isL || !isR)
		{
			return false;
		}

		if (racine->l != nullptr && racine->l->val != racine->val)
		{
			return false;
		}
		
		if (racine->r != nullptr && racine->r->val != racine->val)
		{
			return false;
		}

		count++;

	}
	int TriCountSubtreesum(TNodeI* racine, int sumVal)
	{


		auto postOrder = [&](TNodeI* root)
		{
			std::stack<TNodeI*> s1, s2;

			s1.push(root);

			while (!s1.empty())
			{
				auto tmp = s1.top();
				s1.pop();

				if (tmp->l != nullptr)
				{
					s1.push(tmp->l);
				}
				if (tmp->r != nullptr)
				{
					s1.push(tmp->r);
				}

				s2.push(tmp);
			}
			return s2;

		};

		auto mainPostOrder = postOrder(racine);
		int count = 0;
		//std::cout << "Post order start" << std::endl;
		while (!mainPostOrder.empty())
		{
			auto tmp = mainPostOrder.top();
			mainPostOrder.pop();
			if (tmp->l == nullptr && tmp->r == nullptr)
			{
				if (tmp->val == sumVal)
				{
					count++;
				}
			}
			else
			{
				auto subPostOrder = postOrder(tmp);
				int subSumVal = 0;
				while (!subPostOrder.empty())
				{
					auto subTmp = subPostOrder.top();
					subPostOrder.pop();
					subSumVal += subTmp->val;
				}

				if (subSumVal == sumVal)
				{
					count++;
				}


			}
		}
		//std::cout << "Post order end" << std::endl;
		return count;
	}
	bool TriSubTriOfEachOther(TNodeS* source, TNodeS* target)
	{
		auto  iSub = [](std::vector<std::string> const& group,
			std::vector<std::string> const& subGroup)
		{
			std::size_t const     subSize = subGroup.size();
			int                   i = 0;

			int iGroupOffset = 0;
			int iGroup = 0;


			for (int i = 0; i < subGroup.size(); i++)
			{
				auto itemPos = std::find(group.begin(), group.end(), subGroup[i]);
				if (itemPos == group.end())
				{
					return false;
				}
				else
				{
					auto idx = std::distance(group.begin(), itemPos);
					if (i == 0)
					{
						iGroupOffset = idx;
					}

					if (idx != i + iGroupOffset)
					{
						return false;
					}

				}
			}

			return true;


		};

		auto inOrderTras = [&](TNodeS* racine)
		{
			std::vector<std::string> inData;
			std::stack<TNodeS*>st;
			TNodeS* tmp = racine;
			while (tmp != nullptr || !st.empty())
			{
				if (tmp != nullptr)
				{
					st.push(tmp);
					tmp = tmp->l;
				}
				else
				{
					TNodeS* tmpSub = st.top();
					st.pop();
					inData.push_back(tmpSub->val);
					tmp = tmpSub->r;
				}


			}
			return inData;


		};
		auto preOrderTras = [&](TNodeS* racine)
		{
			std::vector<std::string> preData;
			std::stack<TNodeS*>st;
			st.push(racine);

			while (!st.empty())
			{
				auto tmp = st.top();
				st.pop();
				preData.push_back(tmp->val);

				if (tmp->r != nullptr)
				{
					st.push(tmp->r);
				}
				if (tmp->l != nullptr)
				{
					st.push(tmp->l);
				}
			}

			return preData;

		};



		auto inOrderSource = inOrderTras(source);
		auto inOrderTarget = inOrderTras(target);

		auto preOrderSource = preOrderTras(source);
		auto preOrderTarget = preOrderTras(target);


		//std::cout << "source inorder: ";
		//for (auto d : inOrderSource)
		//{
		//	std::cout << d << ", ";
		//}
		//std::cout << std::endl;
		//std::cout << "target inorder: ";
		//for (auto d : inOrderTarget)
		//{
		//	std::cout << d << ", ";
		//}

		//
		//std::cout << std::endl;
		//std::cout << "source preorder: ";
		//for (auto d : preOrderSource)
		//{
		//	std::cout << d << ", ";
		//}
		//std::cout << std::endl;
		//std::cout << "target preorder: ";
		//for (auto d : preOrderTarget)
		//{
		//	std::cout << d << ", ";
		//}
		//std::cout << std::endl;



		return (iSub(inOrderTarget, inOrderSource) && iSub(preOrderTarget, preOrderSource));
	}
	int TriBalance(TNodeI* racine)
	{
		if (racine == nullptr)
		{
			return 0;
		}

		int lH = TriBalance(racine->l);
		if (lH == -1)
		{
			return -1;
		}
		int rH = TriBalance(racine->r);
		if (rH == -1)
		{
			return -1;
		}

		int diff = lH > rH ? lH - rH : rH - lH;

		if (diff > 1)
		{
			return -1;
		}
		int triH = lH > rH ? lH + 1 : rH + 1;
		return triH;


	}
	bool TriDuplicate1(TNodeI* racine, std::unordered_set<int>& vis)
	{
		if (racine == nullptr)
		{
			return false;
		}
		// If current node's data is already present.
		if (vis.find(racine->val) != vis.end())
		{
			return true;
		}

		// Insert current node
		vis.insert(racine->val);

		return (TriDuplicate1(racine->l, vis) || TriDuplicate1(racine->r, vis));

	}
	bool TriDuplicate2(TNodeI* root)
	{
		auto inOrderTras = [&](TNodeI* racine)
		{
			std::vector<int> inData;
			std::stack<TNodeI*>st;
			TNodeI* tmp = racine;
			while (tmp != nullptr || !st.empty())
			{
				if (tmp != nullptr)
				{
					st.push(tmp);
					tmp = tmp->l;
				}
				else
				{
					TNodeI* tmpSub = st.top();
					st.pop();
					inData.push_back(tmpSub->val);
					tmp = tmpSub->r;
				}


			}
			return inData;


		};
		auto preOrderTras = [&](TNodeI* racine)
		{
			std::vector<int> preData;
			std::stack<TNodeI*>st;
			st.push(racine);

			while (!st.empty())
			{
				auto tmp = st.top();
				st.pop();
				preData.push_back(tmp->val);

				if (tmp->r != nullptr)
				{
					st.push(tmp->r);
				}
				if (tmp->l != nullptr)
				{
					st.push(tmp->l);
				}
			}

			return preData;

		};		
		auto postOrderTras = [&](TNodeI* racine)
		{
			std::stack<TNodeI*> s1, s2;
			std::vector<int> postOrder;
			s1.push(racine);

			while (!s1.empty())
			{
				auto tmp = s1.top();
				s1.pop();

				if (tmp->l != nullptr)
				{
					s1.push(tmp->l);
				}
				if (tmp->r != nullptr)
				{
					s1.push(tmp->r);
				}

				s2.push(tmp);
			}
			while (!s2.empty())
			{
				auto curr = s2.top();
				s2.pop();
				postOrder.push_back(curr->val);
			}

			return postOrder;

		};		
		auto levelOrderTras = [&](TNodeI* racine)
		{
			std::queue<TNodeI*>q;
			q.push(racine);
			std::vector<int> levelOrderData;
			while (!q.empty())
			{
				auto tmp = q.front();
				q.pop();

				levelOrderData.push_back(tmp->val);

				if (tmp->l != nullptr)
				{
					q.push(tmp->l);
				}
				if (tmp->r != nullptr)
				{
					q.push(tmp->r);
				}

			}
			return levelOrderData;
		};

		auto levelOrderDatVec = levelOrderTras(root);

		std::set<int>levelOrderDatSet(levelOrderDatVec.begin(), levelOrderDatVec.end());

		return !(levelOrderDatSet.size() == levelOrderDatVec.size());

	}

	void TriNodesAtDistanceKFromRoot1(TNodeI* racine, int k, std::vector< TNodeI*>& levelKNodes)
	{
		if (racine == nullptr)
		{
			return;
		}

		if (k == 0)
		{
			levelKNodes.push_back(racine);
		}
		else
		{
			TriNodesAtDistanceKFromRoot1(racine->l, k - 1, levelKNodes);
			TriNodesAtDistanceKFromRoot1(racine->r, k - 1, levelKNodes);
		}
	}

	void TriNodesAtDistanceKFromRoot2(TNodeI* racine, int k, std::vector< TNodeI*>& levelKNodes)
	{


		auto NodesPerLevel = [&](TNodeI* root)
		{
			std::map<int, std::vector< TNodeI*>> m;
			std::queue<TNodeI*> q;
			q.push(root);
			int level = 0;
			while (!q.empty())
			{
				int levelSize = size(q);
				std::vector< TNodeI*> currLevelData;
				for (int i = 0; i < levelSize; i++)
				{
					auto tmp = q.front();
					q.pop();
					if (tmp->l != nullptr)
					{
						q.push(tmp->l);
					}

					if (tmp->r != nullptr)
					{
						q.push(tmp->r);
					}
					currLevelData.push_back(tmp);


				}
				m[level] = currLevelData;
				++level;
			};

			return m;
		};
		auto allLevelData = NodesPerLevel(racine);
		levelKNodes = allLevelData[k];

	}
	void Levelorder2(TNodeI* racine, std::vector<int>& dat)
	{
		int h = HeightTree(racine);

		for (int i = 0; i < h; i++)
		{
			std::vector< TNodeI*> levelKNodes;
			TriNodesAtDistanceKFromRoot1(racine, i, levelKNodes);
			for (auto d : levelKNodes)
			{
				dat.push_back(d->val);
			}
			
		}

	}

	void Levelorder3(TNodeI* racine, std::map<int, std::vector<TNodeI*>>& m)
	{
			std::queue<TNodeI*> q;
			q.push(racine);
			int level = 0;
			while (!q.empty())
			{
				int levelSize = size(q);
				std::vector< TNodeI*> currLevelData;
				for (int i = 0; i < levelSize; i++)
				{
					auto tmp = q.front();
					q.pop();
					if (tmp->l != nullptr)
					{
						q.push(tmp->l);
					}

					if (tmp->r != nullptr)
					{
						q.push(tmp->r);
					}
					currLevelData.push_back(tmp);


				}
				m[level] = currLevelData;
				++level;
			};


	}
	void Levelorder4(TNodeI* racine, std::map<int, std::vector<TNodeI*>>& m)
	{
		int h = HeightTree(racine);

		for (int i = 0; i < h; i++)
		{
			std::vector< TNodeI*> levelKNodes;
			TriNodesAtDistanceKFromRoot1(racine, i, levelKNodes);
			m[i] = levelKNodes;
		}
	}

	void TriAncestor1(TNodeI* racine, TNodeI* node, std::vector< TNodeI*>& ances)
	{
		auto myParent = [&]()
		{
			std::stack< TNodeI*> st;
			std::map< TNodeI*, TNodeI*> parent;
			st.push(racine);

			while (!st.empty())
			{
				auto tmp = st.top();
				st.pop();
				if (tmp->r != nullptr)
				{
					st.push(tmp->r);
					parent[tmp->r] = tmp;
				}				
				if (tmp->l != nullptr)
				{
					st.push(tmp->l);
					parent[tmp->l] = tmp;
				}
			}

			return parent;

		};

		auto parTable = myParent();
		auto curr = node;
		while (true)
		{
			auto par = parTable[curr];
			curr = par;
			ances.push_back(par);
			if (par == racine)
			{
				break;
			}
		}
	}
	bool TriAncestor2(TNodeI* racine, TNodeI* node, std::vector< TNodeI*>& ances)
	{
		if (racine == nullptr)
		{
			return false;
		}

		if (racine == node)
		{
			return true;
		}


		bool isNodeInLeftSubTri = TriAncestor2(racine->l, node, ances);
		bool isNodeInRightSubTri = false;

		if (!isNodeInLeftSubTri)
		{
			isNodeInRightSubTri = TriAncestor2(racine->r, node, ances);
		}

		if (isNodeInLeftSubTri || isNodeInRightSubTri)
		{
			ances.push_back(racine);
		}
	}
}