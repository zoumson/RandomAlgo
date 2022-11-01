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
                neig.push_back(minMaxC[i - 1][j]);

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
                    capacityWithoutCurrItem = currentCapacity - wt[currentItem - 1];

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

                allPair.push_back({ currNum, currNumComplToSum });

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
                        allQuad.push_back({ arr[i], arr[j], arr[ind1], arr[ind2] });
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
    void BellMan(std::vector < std::tuple<std::string, std::string, int>>& g, std::vector<std::string> nodes, std::string s)
    {
        std::map<std::string, int> dist;
        int n = nodes.size();
        for (auto& nd : nodes)
        {
            dist[nd] = INT_MAX;
        }
        dist[s] = 0;
        std::string src = "", dst = "";
        int w = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (auto& ed : g)
            {
                std::tie(src, dst, w) = ed;
                dist[dst] = dist[src] == INT_MAX ? dist[dst] : std::min(dist[dst], dist[src] + w);
                //std::cout << "dest: [" << dst << "] -->" << dist[dst] << std::endl;
            }
        }
        std::cout << "Shortest Distance: BellMan\n";
        std::cout << "Graph: edges\n";
        std::cout << "Time complexity: number of vertices * number of edges\n";
        std::cout << "Advantage: can be used with negative weight\n";
        for (auto& el : dist)
        {
            std::cout << "dest: [" << el.first << "] -->" << el.second << std::endl;
        }

    }
    void Dijkstra(std::map <std::string, std::vector<std::pair<std::string, int>>> g, std::vector<std::string> nodes, std::string s)
    {
        typedef std::pair<std::string, int> dt;
        std::map<std::string, int> dist;
        std::map<std::string, bool> process;
        int n = nodes.size();
        for (auto& nd : nodes)
        {
            dist[nd] = INT_MAX;
            process[nd] = false;
        }
        dist[s] = 0;
        std::priority_queue<dt, std::vector<dt>, std::greater<dt>>q;
        q.push({ s, dist[s] });

        while (!q.empty())
        {
            auto src = q.top();
            q.pop();
            if (process[src.first])
            {
                continue;
            }
            process[src.first] = true;

            for (auto& dst : g[src.first])
            {
                if (src.second == INT_MAX)
                {

                }
                else
                {
                    if (src.second + dst.second < dist[dst.first])
                    {
                        dist[dst.first] = src.second + dst.second;
                        q.push({ dst.first , dist[dst.first] });
                    }
                }

                std::cout << "dest: [" << dst.first << "] -->" << dist[dst.first] << std::endl;


            }

        }
        std::cout << "Shortest Distance: Dijkstra\n";
        std::cout << "Graph: adjacent list\n";
        std::cout << "Time complexity: number of vertices * number of edges\n";
        std::cout << "Advantage: faster\n";
        std::cout << "Disadvantage: can't use negative weight\n";
        for (auto& el : dist)
        {
            std::cout << "dest: [" << el.first << "] -->" << el.second << std::endl;
        }
    }
    void FloydWarshall(std::map <std::string, std::map <std::string, int>> g, std::vector<std::string> nodes, std::string s)
    {
        std::map <std::string, std::map <std::string, int>> dist = g;
        std::string src = "";
        std::string dst = "";
        std::string transit = "";
        int n = nodes.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                src = nodes[i];
                dst = nodes[j];
                if (src == dst)
                {
                    dist[src][dst] = 0;
                }
                else if (src != dst && g[src][dst] == 0)
                {
                    dist[src][dst] = INT_MAX;
                }
                else
                {
                    dist[src][dst] = g[src][dst];
                }


            }
        }
        for (int inter = 0; inter < n; inter++)
        {
            for (int i = 0; i < n; i++)
            {

                for (int j = 0; j < n; j++)
                {
                    src = nodes[i];
                    dst = nodes[j];
                    transit = nodes[inter];

                    if (dist[src][transit] == INT_MAX || dist[transit][dst] == INT_MAX)
                    {
                        dist[src][dst] = dist[src][dst];
                    }
                    else
                    {
                        dist[src][dst] = std::min(dist[src][dst], dist[src][transit] + dist[transit][dst]);
                    }


                }
            }
        }

        std::cout << "Shortest Distance : FloydWarshall\n";
        std::cout << "Graph: adjacent matrix\n";
        std::cout << "Time complexity: number of vertices * number of vertices * number of vertices\n";
        std::cout << "Advantage: Shortest Path between all vertices\n";
        for (int i = 0; i < n; i++)
        {
            std::cout << "dest: [" << nodes[i] << "] -->" << dist[s][nodes[i]] << std::endl;
        }



    }
    void DFSStack(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices, std::string s)
    {
        int n = vertices.size();
        std::map<std::string, bool> visited;
        for (auto& vertex : vertices)
        {
            visited[vertex] = false;
        }
        std::stack<std::string> st;
        st.push(s);
        std::string vertexNow = "";
        while (!st.empty())
        {
            vertexNow = st.top();
            st.pop();
            std::cout << vertexNow << std::endl;
            visited[vertexNow] = true;
            for (auto& adj : g[vertexNow])
            {
                if (!visited[adj])
                {
                    st.push(adj);
                }
            }


        }

        std::cout << "Done\n";
    }
    void DFSRecursion(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& nodes, std::string s, std::map < std::string, bool>& vis)
    {
        if (vis[s])
        {
            return;
        }
        std::cout << s << std::endl;
        vis[s] = true;
        for (auto& adj : g[s])
        {
            DFSRecursion(g, nodes, adj, vis);
        }
    }
    void BFSQueue(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices, std::string s)
    {
        int n = vertices.size();
        std::map<std::string, bool> vis;
        for (auto& ver : vertices)
        {
            vis[ver] = false;
        }
        std::queue<std::string> qt;
        std::string vertexNow = "";
        qt.push(s);

        while (!qt.empty())
        {
            vertexNow = qt.front();
            qt.pop();
            if (!vis[vertexNow])
            {
                std::cout << vertexNow << std::endl;
                vis[vertexNow] = true;

                for (auto& adj : g[vertexNow])
                {
                    if (!vis[adj])
                    {
                        qt.push(adj);
                    }
                }
            }

        }

        std::cout << "Done\n";
    }
    void IsGConnected(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices)
    {
        int n = vertices.size();
        std::map<std::string, bool> visited;
        for (auto& vertex : vertices)
        {
            visited[vertex] = false;
        }
        std::stack<std::string> st;
        // start at a random vertex
        st.push(vertices[0]);
        std::string vertexNow = "";
        int numVisVertices = 0;
        while (!st.empty())
        {
            vertexNow = st.top();
            st.pop();
            //std::cout << vertexNow << std::endl;
            numVisVertices++;
            visited[vertexNow] = true;
            for (auto& adj : g[vertexNow])
            {
                if (!visited[adj])
                {
                    st.push(adj);
                }
            }


        }
        if (numVisVertices == n)
        {
            std::cout << "connected[YES]\n";
        }
        else
        {
            std::cout << "connected[NO]\n";
        }


    }
    void NumGConnected(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices)
    {
        int n = vertices.size();
        std::map<std::string, bool> visited;
        for (auto& vertex : vertices)
        {
            visited[vertex] = false;
        }
        std::stack<std::string> st;

        auto dfsAt = [&](std::string s)
        {
            st.push(s);
            std::string vertexNow = "";
            int numConnected = 0;
            while (!st.empty())
            {
                vertexNow = st.top();
                st.pop();
                visited[vertexNow] = true;
                for (auto& adj : g[vertexNow])
                {
                    if (!visited[adj])
                    {
                        st.push(adj);
                    }
                }

            }
        };

        int numConnected = 0;
        // start at a random vertex
        for (auto& vertex : vertices)
        {
            if (!visited[vertex])
            {
                dfsAt(vertex);
                ++numConnected;
            }
        }

        std::cout << "Number of components: " << numConnected << std::endl;

    }
    void HasGCycle(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices)
    {
        int n = vertices.size();
        std::map<std::string, bool> visited;
        for (auto& vertex : vertices)
        {
            visited[vertex] = false;
        }
        std::stack<std::string> st;

        //random vertex for dfs
        st.push(vertices[0]);
        std::string vertexNow = "";
        int numNeigVisited = 0;
        bool hasCycle = false;
        while (!st.empty())
        {
            vertexNow = st.top();
            st.pop();
            visited[vertexNow] = true;
            numNeigVisited = 0;
            for (auto& adj : g[vertexNow])
            {
                if (!visited[adj])
                {
                    st.push(adj);
                }
                else
                {
                    ++numNeigVisited;
                }
            }

            if (numNeigVisited = g[vertexNow].size())
            {
                hasCycle = true;
            }


        }

        if (hasCycle)
        {
            std::cout << "Cycle[YES]\n";
        }
        else
        {
            std::cout << "Cycle[NO]\n";
        }
    }
    void CanColorRedBlue(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices)
    {
        int n = vertices.size();
        std::map<std::string, bool> visited;
        std::map<std::string, std::string> couleur;
        const std::string RED = "RED", BLUE = "BLUE";
        for (auto& vertex : vertices)
        {
            visited[vertex] = false;
            couleur[vertex] = "";
        }
        bool bipartite = true;
        std::stack<std::string> st;
        st.push(vertices[0]);
        std::string vertexNow = "";
        while (!st.empty())
        {
            vertexNow = st.top();
            st.pop();

            visited[vertexNow] = true;
            couleur[vertexNow] = RED;
            for (auto& adj : g[vertexNow])
            {
                if (!visited[adj])
                {
                    st.push(adj);
                    couleur[adj] = BLUE;
                }

                if (couleur[vertexNow] == couleur[adj])
                {
                    bipartite = false;
                    break;
                }
            }


        }

        if (bipartite)
        {
            std::cout << "Bipartite[YES]\n";
        }
        else
        {
            std::cout << "Bipartite[NO]\n";
        }


        std::cout << "Done\n";
    }
    void TopologicalSortKahn(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices)
    {
        size_t n = vertices.size();
        std::map<std::string, int> indegree;

        //Count indegrees
        for (auto& src : vertices)
        {
            if (indegree.find(src) == indegree.end())
            {
                indegree.insert({ src, 0 });
            }
            auto allDest = g[src];
            for (auto& dst : allDest)
            {
                indegree[dst]++;
            }
        }
        std::stack<std::string> s;
        std::vector<std::string>l;
        //indegree 0
        for (auto& vertex : vertices)
        {
            if (indegree[vertex] == 0)
            {
                s.push(vertex);
            }
        }

        std::string prerequisite = "";
        while (!s.empty())
        {
            prerequisite = s.top();
            s.pop();
            l.push_back(prerequisite);
            for (auto& prerequisiteNext : g[prerequisite])
            {
                --indegree[prerequisiteNext];
                if (indegree[prerequisiteNext] == 0)
                {
                    s.push(prerequisiteNext);
                }
            }



        }

        std::cout << "Topologival sort\n";

        for (auto& el : l)
        {

            std::cout << el << std::endl;
        }

    }
    void DFSArrivalDepartureRecur(std::map <std::string, std::vector<std::string>>& g, std::string s, std::map<std::string, std::tuple<bool, int, int>>& visArrDep, int& t)
    {
        std::get<0>(visArrDep[s]) = true;
        std::get<1>(visArrDep[s]) = ++t;

        for (auto& adj : g[s])
        {
            if (!std::get<0>(visArrDep[adj]))
            {
                DFSArrivalDepartureRecur(g, adj, visArrDep, t);
            }
        }

        std::get<2>(visArrDep[s]) = ++t;

    }
    void DFSArrivalDepartureT(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices)
    {
        size_t n = vertices.size();
        int t = -1;
        std::map<std::string, std::tuple<bool, int, int>> visArrDep;
        for (auto& vertex : vertices)
        {
            visArrDep[vertex] = { false, -1, -1 };
        }
        for (auto& vertex : vertices)
        {

            if (!std::get<0>(visArrDep[vertex]))
            {
                DFSArrivalDepartureRecur(g, vertex, visArrDep, t);
            }
        }

        std::cout << "\tArrival Departure\n";
        std::cout << "\tDFS\n";
        std::cout << "\tVertices\tArrival\t\tDeparture\n";

        for (auto& vertex : vertices)
        {
            std::cout << "\t" << vertex << "\t\t" << std::get<1>(visArrDep[vertex]) << "\t\t" << std::get<2>(visArrDep[vertex]) << std::endl;
        }


    }
    void TopologicalSortDFS(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices)
    {
        size_t n = vertices.size();
        int t = -1;
        std::map<std::string, std::tuple<bool, int, int>> visArrDep;
        for (auto& vertex : vertices)
        {
            visArrDep[vertex] = { false, -1, -1 };
        }
        for (auto& vertex : vertices)
        {

            if (!std::get<0>(visArrDep[vertex]))
            {
                DFSArrivalDepartureRecur(g, vertex, visArrDep, t);
            }
        }



        typedef std::pair<std::string, std::tuple<bool, int, int>> mp;

        std::vector< mp> mapToVector;
        for (auto& mel : visArrDep)
        {
            mapToVector.push_back(mel);
        };

        std::sort(mapToVector.begin(), mapToVector.end(), [=](mp& m1, mp& m2)
            {
                return std::get<2>(m1.second) > std::get<2>(m2.second);
            });
        std::cout << "\tTopological Sort\n";
        std::cout << "\tDFS\n";
        for (auto& vertexInfo : mapToVector)
        {
            std::cout << "\t" << vertexInfo.first << ", ";
            std::cout << std::get<1>(vertexInfo.second) << ", ";
            std::cout << std::get<2>(vertexInfo.second) << std::endl;
        }


    }
    bool DFS3statesTopologicalSort(std::map <std::string, std::vector<std::string>>& g, std::string s, std::map<std::string, int>& state, std::deque<std::string>& topSort)
    {
        if (state[s] == 1)
        {
            return false;
        }
        if (state[s] == 2)
        {
            return true;
        }
        //under processing
        state[s] = 1;
        for (auto& adj : g[s])
        {

            if (!DFS3statesTopologicalSort(g, adj, state, topSort))
            {
                return false;
            }

        }
        state[s] = 2;
        topSort.push_front(s);
        return true;
    }
    void TopologicalSortDFS3States(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices)
    {
        //DFS3statesTopologicalSort
        size_t n = vertices.size();
        int t = -1;
        std::map<std::string, int> state;
        for (auto& vertex : vertices)
        {
            state[vertex] = 0;
        }
        std::cout << "\tTopological Sort\n";
        std::cout << "\tDFS 3 states\n";
        std::deque<std::string> topSort;
        for (auto& vertex : vertices)
        {

            if (state[vertex] == 0)
            {
                DFS3statesTopologicalSort(g, vertex, state, topSort);
            }
            else if (state[vertex] == 1)
            {
                std::cout << "\tThere is a cycle\n";
                return;
            }
        }


        for (auto& vertexInfo : topSort)
        {
            std::cout << "\t" << vertexInfo << std::endl;
        }
    }
    void TreeDiameter(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices)
    {
        auto bfs = [=](std::map <std::string, std::vector<std::string>>& graph, std::string startNode)
        {
            std::map <std::string, bool> visited;
            std::map <std::string, int> dist;
            std::queue <std::string> q;
            std::string maxNode;
            int maxNodeDist;
            visited[startNode] = true;
            maxNode = startNode;
            dist[startNode] = 0;
            maxNodeDist = dist[startNode];
            q.push(startNode);
            std::string parentNode;
            while (!q.empty())
            {
                parentNode = q.front();
                q.pop();
                if (dist[parentNode] > maxNodeDist)
                {
                    maxNode = parentNode;
                    maxNodeDist = dist[parentNode];
                }
                // process node s
                for (auto childNode : graph[parentNode])
                {
                    if (visited[childNode])
                    {
                        continue;
                    }
                    visited[childNode] = true;
                    dist[childNode] = dist[parentNode] + 1;
                    q.push(childNode);
                }
            }
            return std::make_pair(maxNode, maxNodeDist);
        };
        //std::string x = vertices[0];
        std::string x = vertices[1];
        auto dist1 = bfs(g, x);
        std::string a = dist1.first;
        auto dist2 = bfs(g, a);
        std::string b = dist2.first;
        std::cout << "\nDiameter nodes\n";
        std::cout << "\nStart: " << a << "\n";
        std::cout << "\End: " << b << "\n";
        std::cout << "\Length: " << dist2.second << "\n";



    }
    void SpanningTreeKruskal(std::map <std::string, std::vector<std::pair<std::string, int>>>& g, std::vector<std::string>& vertices)
    {
        std::map<std::string, std::string> leader;
        std::map<std::string, int> followers;
        std::vector < std::string> tri;

        typedef std::tuple<std::string, std::string, int> edgT;
        std::vector <edgT> edg;

        for (auto& vertex : vertices)
        {
            for (auto& adj : g[vertex])
            {
                edg.push_back({ vertex , adj.first, adj.second });
            }
            leader[vertex] = vertex;
            followers[vertex] = 1;
        }


        std::sort(edg.begin(), edg.end(), [=](edgT ed1, edgT ed2) {
            return std::get<2>(ed1) < std::get<2>(ed2); }
        );

        for (auto& edg_ : edg)
        {
            //std::cout << std::get<0>(edg_) << "--> " << std::get<1>(edg_) << " : " << std::get<2>(edg_) << std::endl;
        }

        auto findLeader = [&](std::string follower)
        {

            while (follower != leader[follower])
            {
                follower = leader[follower];
            }
            std::string myLeader = follower;
            return myLeader;
        };

        auto sameParty = [&](std::string followerA, std::string followerB)
        {
            return findLeader(followerA) == findLeader(followerB);
        };

        auto uniteParty = [&](std::string followerA, std::string followerB)
        {
            std::string leaderA, leaderB;
            leaderA = findLeader(followerA);
            leaderB = findLeader(followerB);
            if (followers[leaderA] < followers[leaderB])
            {
                std::string tmp = leaderA;
                leaderA = leaderB;
                leaderB = tmp;
            }

            followers[leaderA] += followers[leaderB];
            leader[leaderB] = leaderA;
        };


        std::vector<std::pair<std::string, std::string>> edges;
        for (auto& ed : edg)
        {
            auto& a = std::get<0>(ed);
            auto& b = std::get<1>(ed);

            if (!sameParty(a, b))
            {
                edges.push_back({ a, b });
                uniteParty(a, b);

            }
        }
        //Minimum spanning tree
        std::cout << "Minimum spanning tree Kruskal:" << std::endl;
        for (auto& edg_ : edges)
        {
            std::cout << edg_.first << "--> " << edg_.second << std::endl;
        }

    }



}

