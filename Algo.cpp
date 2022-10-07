#include "Algo.h"




namespace za
{

	std::vector<int> subset;
	std::vector < std::vector<int>> setOfSubset;
	std::vector<int> permutation;
	std::vector<bool> chosenPermutation;
	std::vector < std::vector<int>> setOfPermutation;
	int NumberOfSetBits(uint32_t i)
	{
		// Java: use int, and use >>> instead of >>. Or use Integer.bitCount()
		// C or C++: use uint32_t
		i = i - ((i >> 1) & 0x55555555);        // add pairs of bits
		i = (i & 0x33333333) + ((i >> 2) & 0x33333333);  // quads
		i = (i + (i >> 4)) & 0x0F0F0F0F;        // groups of 8
		return (i * 0x01010101) >> 24;          // horizontal sum of bytes
	}
	void GenerateSubsetIdxBit(unsigned int n, std::vector < std::vector<unsigned int>>& subset)
	{
		auto NumOfSetBits = [&](uint32_t i) -> int
		{
			// Java: use int, and use >>> instead of >>. Or use Integer.bitCount()
			// C or C++: use uint32_t
			i = i - ((i >> 1) & 0x55555555);        // add pairs of bits
			i = (i & 0x33333333) + ((i >> 2) & 0x33333333);  // quads
			i = (i + (i >> 4)) & 0x0F0F0F0F;        // groups of 8
			return (i * 0x01010101) >> 24;          // horizontal sum of bytes
		};
		unsigned int maxSubset = 1 << n;
		subset.resize(maxSubset);
		unsigned int currSubsetSize = 0;
		std::vector<unsigned int>currSubset;
		unsigned int idxSubsetEl = 0;
		for (int idxSubset = 0; idxSubset < maxSubset; idxSubset++)
		{
			currSubsetSize = NumOfSetBits(idxSubset);
			currSubset.resize(currSubsetSize);
			idxSubsetEl = 0;
			for (int el = 0; el < n; el++)
			{
				if (idxSubset & (1 << el))
				{
					currSubset[idxSubsetEl++] = el;
				}
			}
			subset[idxSubset] = currSubset;
		}
	}
	void GenerateSubsetIdxRecursion(unsigned int k, unsigned int n)
	{
		if (k == n)
		{
			setOfSubset.push_back(subset);
		}
		else
		{
			// include k in the subset
			subset.push_back(k);
			GenerateSubsetIdxRecursion(k + 1, n);
			subset.pop_back();
			// don't include k in the subset
			GenerateSubsetIdxRecursion(k + 1, n);
		}
	}
	int fact(int i)
	{
		if (i == 0 || i == 1)
		{
			return 1;
		}
		else
		{
			return i * fact(i - 1);
		}
	}
	void PermutationIdxSTL(unsigned int n, std::vector < std::vector<unsigned int>>& permutation)
	{
		std::vector<unsigned int> initialSet(n);
		unsigned int maxPermutationSize = fact(n);
		permutation.resize(maxPermutationSize);
		unsigned int permutationIdx = 0;
		std::iota(initialSet.begin(), initialSet.end(), 0);
		std::vector<unsigned int> currSet = initialSet;
		do
		{
			permutation[permutationIdx++] = currSet;
		} while (std::next_permutation(currSet.begin(), currSet.end()));

	}
	void PermutationIdxRecursion(unsigned int n)
	{
		if (permutation.size() == n)
		{
			setOfPermutation.push_back(permutation);

		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (chosenPermutation[i])
				{
					continue;
				}
				chosenPermutation[i] = true;
				permutation.push_back(i);

				PermutationIdxRecursion(n);

				chosenPermutation[i] = false;
				permutation.pop_back();
			}
		}
	}
	int MinNumCToSumRecursionBrute(int n, std::vector<int>& allC)
	{
		if (n < 0)
		{
			return INT_MAX;
		}
		if (n == 0)
		{
			return 0;
		}

		int bestMinNumCToSum = INT_MAX;
		int remainderAftC = bestMinNumCToSum;
		int currNumCToSum = bestMinNumCToSum;
		for (auto& c : allC)
		{
			remainderAftC = n - c;
			if (remainderAftC >= 0)
			{
				currNumCToSum = MinNumCToSumRecursionBrute(remainderAftC, allC) + 1;
				if (currNumCToSum < bestMinNumCToSum)
				{
					bestMinNumCToSum = currNumCToSum;
				}
			}
			
		}

		return bestMinNumCToSum;
	}
	int MinNumCToSumRecursionMeMo(int n, std::vector<int>& allC, std::vector<int>& m)
	{
		if (n < 0)
		{
			return INT_MAX;
		}
		if (m[n] != INT_MAX)
		{
			return m[n];
		}
		if (n == 0)
		{
			return 0;
		}

		int bestMinNumCToSum = INT_MAX;
		int remainderAftC = bestMinNumCToSum;
		int currNumCToSum = bestMinNumCToSum;
		for (auto& c : allC)
		{
			remainderAftC = n - c;
			if (remainderAftC >= 0)
			{
				currNumCToSum = MinNumCToSumRecursionBrute(remainderAftC, allC) + 1;
				if (currNumCToSum < bestMinNumCToSum)
				{
					bestMinNumCToSum = currNumCToSum;
				}
			}

		}
		m[n] = bestMinNumCToSum;
		return bestMinNumCToSum;
	}
	int MinNumCToSumIterative(int defSum, std::vector<int>& allC)
	{
		if (defSum < 0)
		{
			return INT_MAX;
		}

		std::vector<int> m(defSum + 1, INT_MAX);
		m[0] = 0;

		int remainderAftC = INT_MAX;
		int currNumCToSum = INT_MAX;

		for (int currSum = 1; currSum <= defSum; currSum++)
		{
			for (auto& c : allC)
			{
				currNumCToSum = INT_MAX;
				remainderAftC = currSum - c;
				if (remainderAftC >= 0)
				{
					currNumCToSum = m[remainderAftC] + 1;
					if (currNumCToSum < m[currSum])
					{
						m[currSum] = currNumCToSum;
					}
				}

			}
		}

		return m[defSum];
	}
	std::tuple<int, std::vector<int>> MinNumCToSumIterativeReturnC(int defSum, std::vector<int>& allC)
	{
		//if (defSum < 0)
		//{
		//	return INT_MAX;
		//}

		std::vector<int> m(defSum + 1, INT_MAX);
		std::vector<int> first(defSum + 1, INT_MAX);
		m[0] = 0;

		int remainderAftC = INT_MAX;
		int currNumCToSum = INT_MAX;

		for (int currSum = 1; currSum <= defSum; currSum++)
		{
			for (auto& c : allC)
			{
				currNumCToSum = INT_MAX;
				remainderAftC = currSum - c;
				if (remainderAftC >= 0)
				{
					currNumCToSum = m[remainderAftC] + 1;
					if (currNumCToSum < m[currSum])
					{
						m[currSum] = currNumCToSum;
						first[currSum] = c;
					}
				}

			}
		}
        std::vector<int>r;
        int n = defSum;
        while (n > 0) 
        {
            r.push_back(first[n]);
            n -= first[n];
        }
		return std::make_tuple(m[defSum], r);
	}
    int MaxNumWawToSumIterative(int sumDef, std::vector<int>& c)
    {
        int bigNum = 1e9 + 7;
        std::vector<int> num(sumDef + 1, 0);
        num[0] = 1;
        int sumTmp = 0;
        for (int sumI = 1; sumI <= sumDef; sumI++)
        {
            for (auto& ci : c)
            {
                sumTmp = sumI - ci;

                if (sumTmp >= 0)
                {
                    num[sumI] += num[sumTmp];
                    num[sumI] %= bigNum;
                }
            }
        }

        return num[sumDef];

    }
    int LongIncrSubSeqIterativeBrute(std::vector<int>& s)
    {
        size_t n = s.size();
        std::vector<int> l(n, 1);

        for (int endd = 1; endd < n; endd++)
        {

            for (int startt = 0; startt < endd; startt++)
            {
                if (s[endd] > s[startt])
                {
                    if (l[startt] + 1 > l[endd])
                    {
                        l[endd] = l[startt] + 1;
                    }
                }
            }
        }

        int maxSub = *std::max_element(l.begin(), l.end());

        return maxSub;

    }
    std::vector<int> LongIncrSubSeqIterativeBruteReturnS(std::vector<int>& s)
    {
        size_t n = s.size();
        std::vector<int>l(n, 1);
        std::vector<int>parent(n, -1);

        for (int endd = 1; endd < n; endd++)
        {

            for (int startt = 0; startt < endd; startt++)
            {
                if (s[endd] > s[startt])
                {
                    if (l[startt] + 1 > l[endd])
                    {
                        l[endd] = l[startt] + 1;
                        parent[endd] = startt;
                    }
                }
            }
        }

        int maxSubPos = std::distance(l.begin(), std::max_element(l.begin(), l.end()));
        
        std::deque<int>r;
        int currPos = maxSubPos;
        while (currPos != -1)
        {
            r.push_front(s[currPos]);
            currPos = parent[currPos];
        }

        return { r.begin(), r.end() };


    }
    int GridCostPathRightDownDiag(std::vector<std::vector<int>>& c, bool maxx, bool diag)
    {
        int n = c.size();

        std::vector<std::vector<int>> minMaxC(n, std::vector<int>(n, 0));
        minMaxC[0][0] = c[0][0];
        for (int i = 1; i < n; i++)
        {
            minMaxC[0][i] = minMaxC[0][i - 1] + c[0][i];
            minMaxC[i][0] = minMaxC[i - 1][0] + c[i][0];
        }

        std::vector<int> neig;
        int prevSum = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                neig.push_back(minMaxC[i][j - 1]);
                neig.push_back(minMaxC[i-1][j]);

                if (diag)
                {
                    neig.push_back(minMaxC[i - 1][j - 1]);
                }

                if (maxx)
                {
                    prevSum = *std::max_element(neig.begin(), neig.end());
                }
                else
                {
                    prevSum = *std::min_element(neig.begin(), neig.end());
                }

                minMaxC[i][j] = prevSum + c[i][j];
                neig.clear();
                
            }
        }


        return minMaxC[n - 1][n - 1];

    }
    int GridNumPathRightDownDiag(std::vector<std::vector<bool>>& o, bool diag)
    {
        int n = o.size();
        std::vector<std::vector<int>> numWay(n, std::vector<int>(n, 0));

        if (!o[0][0] || !o[n - 1][n - 1])
        {
            return 0;
        }

        numWay[0][0] = 1;
        bool blockRow = false;
        bool blockCol = false;
        for (int i = 1; i < n; i++)
        {
            if (!blockRow && o[0][i])
            {
                numWay[0][i] = numWay[0][i - 1];
            }
            else if (!o[0][i])
            {
                blockRow = true;
                numWay[0][i] = 0;
            }
            else
            {
                numWay[0][i] = 0;
            }            
            
            if (!blockCol && o[i][0])
            {
                numWay[i][0] = numWay[i - 1][0];
            }
            else if (!o[i][0])
            {
                blockCol = true;
                numWay[i][0] = 0;
            }
            else
            {
                numWay[i][0] = 0;
            }
            
        }

        std::vector<int> neig;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (!o[i][j])
                {
                    continue;
                }
                else
                {
                    if (o[i][j - 1])
                    {
                        neig.push_back(numWay[i][j - 1]);
                    }
                    if (o[i - 1][j])neig.push_back(numWay[i - 1][j]);

                    if (diag && o[i - 1][j - 1])
                    {
                        neig.push_back(numWay[i - 1][j - 1]);
                    }

                    if (neig.size() != 0) numWay[i][j] = std::accumulate(neig.begin(), neig.end(), 0.0);

                    neig.clear();
                }


            }
        }

        return numWay[n - 1][n - 1];
    }
    int Knap01(std::vector<int> v, std::vector<int> wt, int w)
    {
        int n = v.size();
        std::vector < std::vector<int>> million(n + 1, std::vector<int>(w + 1, 0));

        //Nothing in house, even if thief bring a container, what can he do? 
        for (int i = 0; i < w + 1; i++)
        {
            million[0][i] = 0;
        }

        //Thief came without a bag, even the house is full of diamond, what can he do? 
        for (int i = 0; i < n + 1; i++)
        {
            million[i][0] = 0;
        }
        int millionWihtoutCurrItem = 0;
        int millionWithCurrItem = 0;
        int capacityWithoutCurrItem = 0;
        for (int currentItem = 1; currentItem < n + 1; currentItem++)
        {
            millionWihtoutCurrItem = 0;
            millionWithCurrItem = 0;
            for (int currentCapacity = 1; currentCapacity < w + 1; currentCapacity++)
            {
                //current item weight is higher than current capacity
                if (wt[currentItem - 1] > currentCapacity)
                {
                    million[currentItem][currentCapacity] = million[currentItem - 1][currentCapacity];
                }
                else
                {
                    //Don't include current item in capacity currentCapacity
                    //Current item and previous has same weight but previous item value is higher
                    millionWihtoutCurrItem = million[currentItem - 1][currentCapacity];

                    //Include current item 
                    //Remove current item capacity from current capacity
                    //Find the million that can be made with the remaining capacity 
                    //Item count starts from 1
                    capacityWithoutCurrItem =  currentCapacity - wt[currentItem - 1] ;

                    millionWithCurrItem = million[currentItem - 1][capacityWithoutCurrItem] + v[currentItem - 1];



                    million[currentItem][currentCapacity] = millionWithCurrItem > millionWihtoutCurrItem ? millionWithCurrItem : millionWihtoutCurrItem;
                }
   

            }
        }

        return million[n][w];

    }
    int EditDist(std::string s1, std::string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        
        //Modify S1 to get S2
        std::vector < std::vector<int>> dist(n2 + 1, std::vector<int>(n1 + 1, 0));

        //Second string is empty
        //Remove all the characters from s1 to get an empty string
        for (int i = 0; i < n1 + 1; i++)
        {
            dist[0][i] = i;
        }
        
        //First string is empty
        //Add all the characters to s1 to get s2
        for (int i = 0; i < n2 + 1; i++)
        {
            dist[i][0] = i;
        }

        std::vector<int> neig;
        int currMinDist = 0;
        for (int iS2 = 1; iS2 < n2 + 1; iS2++)
        {
            for (int iS1 = 1; iS1 < n1 + 1; iS1++)
            {
                //Skip current character
                //Equal character
                if (s1[iS1 - 1] == s2[iS2 - 1])
                {
                    dist[iS2][iS1] = dist[iS2 - 1][iS1 - 1];
                }
                else
                {
                    //Diff length
                    //Deletion
                    //Remove a character from s1 to get s2
                    //Edit is 1
                    neig.push_back(dist[iS2][iS1 - 1] + 1);                    
                    
                    //Insertion
                    //Add a character to s1 to get s2
                    //Edit is 1
                    neig.push_back(dist[iS2 - 1][iS1] + 1);

                    //Substitution
                    //Same length, but different character
                    //Replace a character from s1 to get s2
                    neig.push_back(dist[iS2 - 1][iS1 - 1] + 1);

                    currMinDist = *std::min_element(neig.begin(), neig.end());

                    dist[iS2][iS1] = currMinDist;

                    neig.clear();
                }
               
            }
        }

        return dist[n2][n1];


    }
    std::vector<int> SubArrSum2Ptr(std::vector<int> arr, int s)
    {
        int runingSum = 0;
        int startPnt = 0, endPnt = 0;
        int n = arr.size();
        while (startPnt < n && endPnt < n && startPnt <= endPnt && runingSum != s)
        {
            if (runingSum < s)
            {
                ++endPnt;
                runingSum += arr[endPnt];
            }
            else 
            {
                runingSum -= arr[startPnt];
                ++startPnt;
            }
        }

        return { arr.begin() + startPnt, arr.begin() + endPnt };
        
    }
    std::vector<std::pair<int, int>> SubArr2SumHash(std::vector<int> arr, int s)
    {
        std::unordered_set<int> keepCompl;

        std::vector<std::pair<int, int>> allPair;
        int n = arr.size();
        int currNum = 0, currNumComplToSum = s - currNum;
        for (int i = 0; i < n; i++)
        {
            currNum = arr[i];
            currNumComplToSum = s - currNum;
            if (keepCompl.find(currNumComplToSum) != keepCompl.end())
            {

                allPair.push_back({currNum, currNumComplToSum });

            }
            else
            {
                keepCompl.insert(currNum);
            }
        }

        return allPair;
    }
    std::vector<std::tuple<int, int, int>> SubArr3SumHash(std::vector<int> arr, int s)
    {
        

        std::vector<std::tuple<int, int, int>> allTupl;
        int n = arr.size();

        for (int k = 0; k < n - 2; k++)
        {

            std::unordered_set<int> keepCompl;
            int currNum = 0, currNumComplToSum = s - currNum;
            for (int i = 0; i < n; i++)
            {
                currNum = arr[k] + arr[i];
                currNumComplToSum = s - currNum;
                if (keepCompl.find(currNumComplToSum) != keepCompl.end())
                {

                    allTupl.push_back({ arr[k], arr[i], currNumComplToSum });

                }
                else
                {
                    keepCompl.insert(arr[i]);
                }
            }


        }


        return allTupl;
    }
    std::vector<std::tuple<int, int, int, int>> SubArr4SumHash(std::vector<int> arr, int s)
    {
        

        std::vector<std::tuple<int, int, int, int>> allQuad;
        int n = arr.size();
        std::unordered_map<int, std::pair<int, int>> keepCompl;
      
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                keepCompl.insert({ arr[i] + arr[j], {i, j} });
            }
        }



        for (int i = 0; i < n - 1; i++)
        {

            int currNum = 0, currNumComplToSum = s - currNum;
            for (int j = i + 1; j < n; j++)
            {
                currNum = arr[i] + arr[j];
                currNumComplToSum = s - currNum;
                if (keepCompl.find(currNumComplToSum) != keepCompl.end())
                {
                    int ind1 = keepCompl[currNumComplToSum].first;
                    int ind2 = keepCompl[currNumComplToSum].second;

                    if (i != ind1 && i != ind2 && j != ind1 && j != ind2)
                    {
                        allQuad.push_back({ arr[i], arr[j], arr[ind1], arr[ind2]});

                    }                  

                }
                else
                {
                    //map already have all duplicate possible sum
                }
            }


        }


        return allQuad;
    }
}

