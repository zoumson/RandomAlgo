#pragma once
#include <algorithm>
#include <iomanip>
#include <iostream>

#include <numeric>
#include <random>
#include <limits>
#include <chrono>
#include <thread>


//multimap
#include <map>
#include <unordered_map>

//multiset
#include <set>
#include <unordered_set>

//dfs//bfs
#include <stack>
#include <queue>

//c array like
#include <vector>
#include <array>

//link list
#include <deque>
#include <list>


#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include <tuple>
#include <cmath>
#include <functional>
#include <memory>

namespace za
{




	extern std::vector<int> subset;
	extern std::vector < std::vector<int>> setOfSubset;	
	extern std::vector<int> permutation;
	extern std::vector<bool> chosenPermutation;
	extern std::vector < std::vector<int>> setOfPermutation;
    enum class CSVState
        {
            UnquotedField,
            QuotedField,
            QuotedQuote
        };
    std::vector<std::string> readCSVRow(const std::string& row);
    const std::vector<std::vector<std::string>> readCSV(std::istream& in);
    template<typename TupleType, typename FunctionType>
    void for_each(TupleType&&, FunctionType
            , std::integral_constant<size_t, std::tuple_size<typename std::remove_reference<TupleType>::type >::value>) {}

    template<std::size_t I, typename TupleType, typename FunctionType
            , typename = typename std::enable_if<I != std::tuple_size<typename std::remove_reference<TupleType>::type>::value>::type >
    void for_each(TupleType&& t, FunctionType f, std::integral_constant<size_t, I>)
        {
            f(std::get<I>(std::forward<TupleType>(t)));
            for_each(std::forward<TupleType>(t), f, std::integral_constant<size_t, I + 1>());
        }

    template<typename TupleType, typename FunctionType>
    void for_each(TupleType&& t, FunctionType f)
        {
            for_each(std::forward<TupleType>(t), f, std::integral_constant<size_t, 0>());
        }

	int NumberOfSetBits(uint32_t i);
	void GenerateSubsetIdxBit(unsigned int n, std::vector < std::vector<unsigned int>>& subset);
	void GenerateSubsetIdxRecursion(unsigned int k, unsigned int n);
	int fact(int);
	void PermutationIdxSTL(unsigned int n, std::vector < std::vector<unsigned int>>& permutation);
	void PermutationIdxRecursion(unsigned int n);
	int MinNumCToSumRecursionBrute(int n, std::vector<int>& c);
	int MinNumCToSumRecursionMeMo(int n, std::vector<int>& c, std::vector<int>& m);
	int MinNumCToSumIterative(int n, std::vector<int>& c);
	std::tuple<int, std::vector<int>> MinNumCToSumIterativeReturnC(int n, std::vector<int>& c);
    int MaxNumWawToSumIterative(int n, std::vector<int>& c);
    int LongIncrSubSeqIterativeBrute(std::vector<int>& s);
    std::vector<int> LongIncrSubSeqIterativeBruteReturnS(std::vector<int>& s);
    int GridCostPathRightDownDiag(std::vector<std::vector<int>>& c, bool maxx, bool diag);
    int GridNumPathRightDownDiag(std::vector<std::vector<bool>>&o,  bool diag);
    int GridNumPathRightDownDiag(std::vector<std::vector<bool>>&o,  bool diag);
    int Knap01(std::vector<int> v, std::vector<int> wt, int w);
    int EditDist(std::string s1, std::string s2);
    std::vector<int> SubArrSum2Ptr(std::vector<int> arr, int s);
    std::vector<std::pair<int, int>> SubArr2SumHash(std::vector<int> arr, int s);
    std::vector<std::tuple<int, int, int>> SubArr3SumHash(std::vector<int> arr, int s);
    std::vector<std::tuple<int, int, int, int>> SubArr4SumHash(std::vector<int> arr, int s);
    //void BellMan(std::vector < std::tuple<int, int, int>>& g, int n);    
    void BellMan(std::vector < std::tuple<std::string, std::string, int>>& g, std::vector<std::string> nodes, std::string s);
    void Dijkstra(std::map <std::string, std::vector<std::pair<std::string, int>>> g, std::vector<std::string> nodes, std::string s);

    void FloydWarshall(std::map <std::string, std::map <std::string, int>> g, std::vector<std::string> nodes, std::string s);
    void DFSStack(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& nodes, std::string s);
    void DFSRecursion(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& nodes, std::string s, std::map < std::string, bool>& vis);
    void BFSQueue(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& nodes, std::string s);
    void IsGConnected(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices);
    void NumGConnected(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices);
    void HasGCycle(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices);
    void CanColorRedBlue(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices);
    void TopologicalSortKahn(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices);
    void DFSArrivalDepartureRecur(std::map <std::string, std::vector<std::string>>& g, std::string s, std::map<std::string, std::tuple<bool, int, int>>& visArrDep, int& t);
    bool DFS3statesTopologicalSort(std::map <std::string, std::vector<std::string>>& g, std::string s, std::map<std::string, int>& state, std::deque<std::string>& topSort);
    void DFSArrivalDepartureT(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices);
    void TopologicalSortDFS(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices);
    void TopologicalSortDFS3States(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices);
    void TreeDiameter(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices);
    //void ArrivalDepartureG(std::map <std::string, std::vector<std::string>>& g, std::vector<std::string>& vertices, std::string s);
   
}