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
			std::cout << "Found" << std::endl;
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
		while (curr != nullptr || !s.empty())
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
			if (summ == target)
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
			return;
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

	void TriEnCoding(TNodeI* racine, std::deque<bool>& enCodeBitList, std::deque<int>& enCodeDataList)
	{
		if (racine == nullptr)
		{
			enCodeBitList.push_back(0);
			return;
		}
		else
		{
			enCodeBitList.push_back(1);
			enCodeDataList.push_back(racine->val);
			TriEnCoding(racine->l, enCodeBitList, enCodeDataList);
			TriEnCoding(racine->r, enCodeBitList, enCodeDataList);

		}
	}

	//try use deque
	TNodeI* TriDeCoding(std::deque<bool>& encodeBitList, std::deque<int>& encodeDataList)
	{
		if (encodeBitList.size() == 0)
		{
			return nullptr;
		}
		else
		{
			bool currBit = encodeBitList.front();
			encodeBitList.pop_front();

			if (currBit == 1)
			{
				int nodeVal = encodeDataList.front();
				encodeDataList.pop_front();
				TNodeI* racine = new TNodeI(nodeVal);
				racine->l = TriDeCoding(encodeBitList, encodeDataList);
				racine->r = TriDeCoding(encodeBitList, encodeDataList);
				return racine;
			}

		}
		return nullptr;
	}

	std::string SerializeArray(std::string s[], int l)
	{
		std::string encodedStr = "";
		for (int i = 0; i < l; i++)
		{
			int l = s[i].length();
			//same as std::to_string(l)
			encodedStr.push_back('0' + l);
			encodedStr = encodedStr + "-" + s[i];
		}
		return encodedStr;
	}

	std::string DeserializeArray(std::string s, std::string d[], int l)
	{
		int length, position = 0;
		std::string t = "";
		int i = 0;
		while (position > -1)
		{
			position = s.find("-", position + 1);
			if (position > 0)
			{
				length = s[position - 1] - 48;
				t.append(s, position + 1, length);
				d[i++] = t;
				t = "";
			}
		}
		//no return value before
		//check
		return t;
	}

	void TriSerializeHelper1(std::stringstream& ss, TNodeI* racine)
	{
		if (racine == nullptr)
		{
			ss << "#";
			return;
		}
		ss << racine->val;
		TriSerializeHelper1(ss, racine->l);
		TriSerializeHelper1(ss, racine->r);
	}
	std::string TriSerialize1(TNodeI* racine)
	{
		std:: stringstream ss;
		TriSerializeHelper1(ss, racine);
		return ss.str();
	}

	void TriDeSerializeHelper1(std::stringstream& ss, TNodeI* cur)
	{
		std::string Node;
		ss >> Node;
		if (Node == "" || Node == "#") 
		{
			cur = nullptr;
			return;
		}
		std::stringstream sss(Node);
		int data;
		sss >> data;
		cur = new TNodeI(data);
		cur->l = cur->r = nullptr;
		TriDeSerializeHelper1(ss, cur->l);
		TriDeSerializeHelper1(ss, cur->r);
	}
	TNodeI* TriDeSerialize1(std::string data)
	{
		std::stringstream ss(data);
		TNodeI* racine = nullptr;
		TriDeSerializeHelper1(ss, racine);
		return racine;
	}

	void TriSerializeHelper2(TNodeI* racine, std::ostringstream& os)
	{
		if (racine == nullptr) 
		{
			os << "X" << " ";
			return;
		}
		os << racine->val;
		os << " ";
		TriSerializeHelper2(racine->l, os);
		TriSerializeHelper2(racine->r, os);
	}
	std::string TriSerialize2(TNodeI* racine)
	{
		std::ostringstream oss;
		TriSerializeHelper2(racine, oss);
		return oss.str();
	}
	TNodeI* TriDeSerializeHelper2(std::istringstream& is)
	{
		std::string val;
		is >> val;
		if (val == "X")
		{
			return nullptr;
		}
		TNodeI* racine = new TNodeI(stoi(val));
		racine->l = TriDeSerializeHelper2(is);
		racine->r = TriDeSerializeHelper2(is);
		return racine;
	}
	TNodeI* TriDeSerialize2(std::string data)
	{
		std::istringstream is(data);
		return TriDeSerializeHelper2(is);
	}

	void TriZigZag1(TNodeI* racine, std::vector<int>& dat)
	{

		if (racine == nullptr)
		{
			return;
		}



		std::stack<TNodeI*> current;
		std::stack<TNodeI*> next;
		current.push(racine);
		bool lefttoright = true;
		while (!current.empty()) 
		{
			TNodeI* temp = current.top();
			current.pop();
			if (temp) 
			{
				dat.push_back(temp->val);
				if (lefttoright) 
				{
					if (temp->l)
					{
						next.push(temp->l);
					}
					if (temp->r)
					{
						next.push(temp->r);
					}
				}
				else 
				{
					if (temp->r)
					{
						next.push(temp->r);
					}
					if (temp->l)
					{
						next.push(temp->l);
					}
				}
			}
			if (current.empty()) 
			{
				lefttoright = !lefttoright;
				std::swap(current, next);
			}
		}
	}
	void TriZigZag2(TNodeI* racine, std::vector<int>& dat)
	{
		std::deque<TNodeI*> q;
		q.push_back(racine);
		dat.push_back(racine->val);
		TNodeI* temp;
		int l = 1; //level
		while (!q.empty()) 
		{
			int n = q.size();
			for (int i = 0; i < n; i++) 
			{
				if (l % 2 == 0) 
				{
					temp = q.back();
					q.pop_back();
				}
				else 
				{
					temp = q.front();
					q.pop_front();
				}
				if (l % 2 != 0) 
				{
					if (temp->r) 
					{
						q.push_back(temp->r);
						dat.push_back(temp->r->val);
					}
					if (temp->l) 
					{
						q.push_back(temp->l);
						dat.push_back(temp->l->val);
					}
				}
				else if (l % 2 == 0) 
				{
					if (temp->l) 
					{
						q.push_front(temp->l);
						dat.push_back(temp->l->val);
					}
					if (temp->r) 
					{
						q.push_front(temp->r);
						dat.push_back(temp->r->val);
					}
				}
			}
			l++;
		}
	}
	void TriZigZag3Level(TNodeI* racine, int level, bool l, std::vector<int>& dat)
	{
		if (racine == nullptr)
		{
			return;
		}
			
		if (level == 1)
		{
			dat.push_back(racine->val);
		}
		else if (level > 1)
		{
			if (l)
			{
				TriZigZag3Level(racine->l, level - 1, l, dat);
				TriZigZag3Level(racine->r, level - 1, l, dat);
			}
			else
			{
				TriZigZag3Level(racine->r, level - 1, l, dat);
				TriZigZag3Level(racine->l, level - 1, l, dat);
			}
		}
	}
	int TriZigZag3Height(TNodeI* racine)
	{
		if (racine == nullptr)
		{
			return 0;
		}
		else
		{
			int left = TriZigZag3Height(racine->l);
			int right = TriZigZag3Height(racine->r);
			if (left > right)
			{
				return (left + 1);
			}
			else
			{
				return (right + 1);
			}
		}
	}
	void TriZigZag3(TNodeI* racine, std::vector<int>& dat)
	{
		int h = TriZigZag3Height(racine);
		int i;
		bool ltr = false;
		for (i = 1; i <= h; i++)
		{
			TriZigZag3Level(racine, i, ltr, dat);
			ltr = !ltr;
		}
	}
	void TriZigZag4(TNodeI* racine, std::vector<int>& dat)
	{
		if (racine == nullptr)
		{
			return;
		}
		std::stack<TNodeI*> s1;
		std::stack<TNodeI*> s2;
		s1.push(racine);
		while (!s1.empty() || !s2.empty()) 
		{
			while (!s1.empty()) 
			{
				TNodeI* temp = s1.top();
				s1.pop();
				dat.push_back(temp->val);
				if (temp->r)
				{
					s2.push(temp->r);
				}
				if (temp->l)
				{
					s2.push(temp->l);
				}
			}
			while (!s2.empty()) 
			{
				TNodeI* temp = s2.top();
				s2.pop();
				dat.push_back(temp->val);
				if (temp->l)
				{
					s2.push(temp->l);
				}
				if (temp->r)
				{
					s2.push(temp->r);
				}
			}
		}
	}
	void TriFoldable1Mirror(TNodeI* racine)
	{
		if (racine == nullptr)
		{
			return;
		}
		else 
		{
			TNodeI* temp;
			TriFoldable1Mirror(racine->l);
			TriFoldable1Mirror(racine->r);

			temp = racine->l;
			racine->l = racine->r;
			racine->r = temp;
		}
	}
	bool TriFoldable1Same(TNodeI* node1, TNodeI* node2)
	{
		if (node1 == nullptr && node2 == nullptr)
		{
			return true;
		}
		if (node1 != nullptr && node2 != nullptr &&
			TriFoldable1Same(node1->l, node2->l) &&
			TriFoldable1Same(node1->r, node2->r))
		{
			return true;
		}

		return false;
	}
	bool TriFoldable1(TNodeI* racine)
	{
		bool res;
		if (racine == nullptr)
		{
			return true;
		}
		TriFoldable1Mirror(racine->l);
		res = TriFoldable1Same(racine->l, racine->r);
		TriFoldable1Mirror(racine->l);
		return res;
	}
	bool TriFoldable2Check(TNodeI* node1, TNodeI* node2)
	{
		if (node1 == nullptr && node2 == nullptr) 
		{
			return true;
		}
		if (node1 == nullptr || node2 == nullptr) 
		{
			return false;
		}
		return TriFoldable2Check(node1->l, node2->r)
			&& TriFoldable2Check(node1->r, node2->l);
	}
	bool TriFoldable2(TNodeI* racine)
	{
		if (racine == nullptr) 
		{
			return true;
		}

		return TriFoldable2Check(racine->l, racine->r);
	}
	bool TriIsomorphic1(TNodeI* racine1, TNodeI* racine2)
	{
		if (racine1 == nullptr && racine2 == nullptr)
		{
			return true;
		}
		if (racine1 == nullptr || racine2 == nullptr)
		{
			return false;
		}
		if (racine1->val != racine2->val)
		{
			return false;
		}
		return
			(TriIsomorphic1(racine1->l, racine2->l) 
				&& TriIsomorphic1(racine1->r, racine2->r)) 
			|| (TriIsomorphic1(racine1->l, racine2->r)
			&& TriIsomorphic1(racine1->r, racine2->l));
	}
	bool TriIsomorphic2(TNodeI* racine1, TNodeI* racine2)
	{
		if (racine1 == nullptr && racine2 == nullptr)
		{
			return true;
		}
		else if (racine1 == nullptr || racine2 == nullptr)
		{
			return false;
		}
		std::queue<TNodeI*> q1, q2;

		q1.push(racine1);
		q2.push(racine2);

		int level = 0, size;
		std::vector<int> v2;
		std::unordered_map<int, int> mp;

		while (!q1.empty() && !q2.empty()) 
		{
			if (q1.size() != q2.size())
			{
				return false;
			}
			size = q1.size();
			level++;
			v2.clear();
			mp.clear();
			while (size--) 
			{
				TNodeI* temp1 = q1.front();
				TNodeI* temp2 = q2.front();
				q1.pop();
				q2.pop();

				if (mp.find(temp1->val) == mp.end())
				{
					mp[temp1->val] = 1;
				}
				else
				{
					mp[temp1->val]++;
				}

				v2.push_back(temp2->val);
				if (temp1->l)
				{
					q1.push(temp1->l);
				}
				if (temp1->r)
				{
					q1.push(temp1->r);
				}
				if (temp2->l)
				{
					q2.push(temp2->l);
				}

				if (temp2->r)
				{
					q2.push(temp2->r);
				}
			}
			for (auto i : v2) 
			{
				if (mp.find(i) == mp.end())
				{
					return false;
				}
				else 
				{
					mp[i]--;
					if (mp[i] < 0)
					{
						return false;
					}
					else if (mp[i] == 0)
					{
						mp.erase(i);
					}
				}
			}
			if (mp.size() != 0)
			{
				return false;
			}
		}
		return true;
	}


	TNodeI* TriConvertCircularDoublyLinkedList2(TNodeI* racine, TNodeI** head, TNodeI** tail)
	{
		if (racine == nullptr)
		{
			return nullptr;
		}
		TNodeI* left = racine->l;
		TNodeI* right = racine->r;
		TriConvertCircularDoublyLinkedList2(racine->l, head, tail);

		if (*head == nullptr) 
		{
			*head = racine;
		}
		racine->l = *tail;

		if (*tail != NULL) 
		{
			(*tail)->r = racine;
		}

		*tail = racine;
		TriConvertCircularDoublyLinkedList2(racine->r, head, tail);
		return racine;
	}
	TNodeI* TriCircularDoublyLinkedList2(TNodeI* racine)
	{
		if (racine == nullptr)
		{
			return racine;
		}
		TNodeI* head = NULL;
		TNodeI* tail = NULL;
		TriConvertCircularDoublyLinkedList2(racine, &head, &tail);
		return head;
	}
	void TriCircularDoublyLinkedList4(TNodeI* racine, TNodeI** head)
	{
		if (racine == nullptr)
		{
			return;
		}
		static TNodeI* prev = nullptr;

		TriCircularDoublyLinkedList4(racine->l, head);
		if (prev == nullptr)
		{
			*head = racine;
		}
		else
		{
			racine->l = prev;
			prev->r = racine;
		}
		prev = racine;
		TriCircularDoublyLinkedList4(racine->r, head);
	}

	void TriLeftSkewed(TNodeI* racine, std::vector<int> values)
	{
		TNodeI* prev, * curr;
		prev = racine;
		for (auto val : values)
		{
			curr = new TNodeI(val);
			prev->l = curr;
		}
	}
	void TriRightSkewed(TNodeI* racine, std::vector<int> values)
	{
		TNodeI* prev, *curr;
		prev = racine;
		for (auto val : values)
		{
			curr = new TNodeI(val);
			prev->r = curr;
		}
	}

	bool TriSkewedCheck(TNodeI* racine)
	{
		//This condition checks if the given is null node or leaf node
		if (racine == nullptr || (racine->l == nullptr &&
			racine->r == nullptr))
		{
			return true;
		}

		//Now, we check if the node has two children, if yes then we return false 
		if (racine->l && racine->r)
		{
			return false;
		}

		//If the node has only one left child node then we check its left child node 
		//else we check its right root node
		if (racine->l)
		{
			return TriSkewedCheck(racine->l);
		}
		return TriSkewedCheck(racine->r);
	}
	void TriSkewedConv(TNodeI* racine, int k)
	{
		// Base Case
		if (!racine)
		{
			return;
		}

		// To check the order in which the skewed tree should be made
		if (k)
		{
			TriSkewedConv(racine->r, k);
		}
		else
		{
			TriSkewedConv(racine->l, k);
		}

		TNodeI* rightNode = racine->r;
		TNodeI* leftNode = racine->l;

		// To check if the root Node of the skewed tree is not defined
		// //double check
		//if (!headNode)
		//{
		//	headNode = racine;
		//	racine->l = nullptr;
		//	prevNode = racine;
		//}
		//else
		//{
		//	prevNode->r = racine;
		//	root->l = nullptr;
		//	prevNode = racine;
		//}

		// Now we will Recurse for the left or right subtree on the basis of the order
		if (k)
		{
			TriSkewedConv(leftNode, k);
		}
		else
		{
			TriSkewedConv(rightNode, k);
		}
	}
}
