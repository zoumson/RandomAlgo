﻿// RandomAlgo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Algo.h"

namespace za
{
    namespace demo
    {
        void GenerateSubsetIdxRecursionD();
        void GenerateSubsetIdxBitD();
        void PermutationIdxSTLD();
        void PermutationIdxRecursionD();
        void MinNumCToSumRecursionBruteD();
        void MinNumCToSumRecursionMemoD();
        void MinNumCToSumIterativeD();
        void MinNumCToSumIterativeReturnCD();
        void MaxNumWawToSumIterativeD();
        void LongIncrSubSeqIterativeBruteD();
        void LongIncrSubSeqIterativeBruteReturnSD();
        void GridCostPathRightDownDiagD();
        void GridNumPathRightDownDiagD();
        void Knap01D();
        void EditDistD();
        void SubArrSum2PtrD();
        void SubArr2SumHashD();
        void SubArr3SumHashD();
        void SubArr4SumHashD();


    }
}

int main()
{
    std::cout.precision(3);
    auto start1 = std::chrono::steady_clock::now();
    double msTimer1 = 0.0;
    za::demo::SubArr4SumHashD();
    auto end1 = std::chrono::steady_clock::now();
    msTimer1 += std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();
    std::scientific;
    std::cout << "Process time = " << (double)msTimer1 << std::endl;    

}



namespace za
{
    namespace demo
    {
        void GenerateSubsetIdxRecursionD()
        {
            unsigned int n = 3;
            GenerateSubsetIdxRecursion(0, n);
            std::cout << "Number of subsets: " << setOfSubset.size() << std::endl;
            std::cout << "Listing of subsets" << std::endl;

            for (int i = 0; i < setOfSubset.size(); i++)
            {
                if (setOfSubset[i].size() != 0)
                {
                    std::cout << "{ ";
                    for (int j = 0; j < setOfSubset[i].size(); j++)
                    {
                        std::cout << setOfSubset[i][j];
                        if (j != setOfSubset[i].size() - 1)
                        {
                            std::cout << ", ";
                        }
                    }
                    std::cout << " }" << std::endl;
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "{ }\n";

                }
            }

        }
        void GenerateSubsetIdxBitD()
        {
            unsigned int n = 3;
            std::vector<std::vector< unsigned int>> setOfSubset;
            za::GenerateSubsetIdxBit(n, setOfSubset);
            std::cout << "Number of subsets: " << setOfSubset.size() << std::endl;
            std::cout << "Listing of subsets" << std::endl;

            for (int i = 0; i < setOfSubset.size(); i++)
            {
                if (setOfSubset[i].size() != 0)
                {
                    std::cout << "{ ";
                    for (int j = 0; j < setOfSubset[i].size(); j++)
                    {
                        std::cout << setOfSubset[i][j];
                        if (j != setOfSubset[i].size() - 1)
                        {
                            std::cout << ", ";
                        }
                    }
                    std::cout << " }" << std::endl;
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "{ }\n";

                }
            }
        }
        void PermutationIdxSTLD()
        {
            unsigned int n = 3;
            std::vector<std::vector< unsigned int>> setOfPermutation;
            PermutationIdxSTL(n, setOfPermutation);
            std::cout << "Number of permutations: " << setOfPermutation.size() << std::endl;
            std::cout << "Listing of permutations" << std::endl;

            for (int i = 0; i < setOfPermutation.size(); i++)
            {

                    std::cout << "{ ";
                    for (int j = 0; j < setOfPermutation[i].size(); j++)
                    {
                        std::cout << setOfPermutation[i][j];
                        if (j != setOfPermutation[i].size() - 1)
                        {
                            std::cout << ", ";
                        }
                    }
                    std::cout << " }" << std::endl;
                    std::cout << std::endl;

            }
        }
        void PermutationIdxRecursionD()
        {
            unsigned int n = 3;
            std::vector<bool> chosenPermutationTmp(n, false);
            chosenPermutation = chosenPermutationTmp;
            //std::vector<std::vector< unsigned int>> setOfPermutation;
            PermutationIdxRecursion(n);
            //PermutationIdxSTL(n, setOfPermutation);
            std::cout << "Number of permutations: " << setOfPermutation.size() << std::endl;
            std::cout << "Listing of permutations" << std::endl;

            for (int i = 0; i < setOfPermutation.size(); i++)
            {

                    std::cout << "{ ";
                    for (int j = 0; j < setOfPermutation[i].size(); j++)
                    {
                        std::cout << setOfPermutation[i][j];
                        if (j != setOfPermutation[i].size() - 1)
                        {
                            std::cout << ", ";
                        }
                    }
                    std::cout << " }" << std::endl;
                    std::cout << std::endl;

            }
        }        
        void MinNumCToSumRecursionBruteD()
        {
            int n = 520;
            int minNumC = 0;
            std::vector<int> c = { 1, 2, 5, 10, 20, 50, 100, 200 };
            minNumC = MinNumCToSumRecursionBrute(n, c);

            std::cout << "min num C: " << minNumC << std::endl;
        }              
        void MinNumCToSumRecursionMemoD()
        {
            int n = 520;
            int minNumC = 0;
            std::vector<int> c = { 1, 2, 5, 10, 20, 50, 100, 200 };
            std::vector<int> m(n + 1, INT_MAX);
            minNumC = MinNumCToSumRecursionMeMo(n, c, m);

            std::cout << "min num C: " << minNumC << std::endl;
        }        
        void MinNumCToSumIterativeD()
        {
            int n = 520;
            int minNumC = 0;
            std::vector<int> c = { 1, 2, 5, 10, 20, 50, 100, 200};
            minNumC = MinNumCToSumIterative(n, c);
            std::cout << "min num C: " << minNumC << std::endl;
        }        
        void MinNumCToSumIterativeReturnCD()
        {
            int n = 520;
            //int minNumC = 0;
            std::vector<int> c = { 1, 2, 5, 10, 20, 50, 100, 200};
            auto minNumC = MinNumCToSumIterativeReturnC(n, c);
            std::cout << "min num C: " << std::get<0>(minNumC) << std::endl;
            std::cout << "all C: "<< std::endl;
            for (auto& ci : std::get<1>(minNumC))
            {
                std::cout << ci << std::endl;
            }

        }
        void MaxNumWawToSumIterativeD()
        {
            int n = 5;
            //int minNumC = 0;

            std::vector<int> c = { 1, 3, 4};
            auto minNumC = MaxNumWawToSumIterative(n, c);
            std::cout << "all way: " << minNumC << std::endl;


        }
        void LongIncrSubSeqIterativeBruteD()
        {
            std::vector<int> arr = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };

            auto longS = LongIncrSubSeqIterativeBrute(arr);
            std::cout << "Long subs: " << longS << std::endl;
        }
        void LongIncrSubSeqIterativeBruteReturnSD()
        {
            std::vector<int> arr = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };

            auto longS = LongIncrSubSeqIterativeBruteReturnS(arr);
            std::cout << "Long subs:\n";

            for (auto& ss : longS)
            {
                std::cout <<"\t\t" << ss << std::endl;
            }
        }
        void GridCostPathRightDownDiagD()
        {

            std::vector<std::vector<int>> c = { {3, 7, 9, 2, 7},
                {9, 8, 3, 5, 5},
                {1, 7, 9, 8, 5},
                {3, 8, 6, 4, 10},
                {6, 3, 9, 7, 8} };

            int maxCost = GridCostPathRightDownDiag(c, true, false);
            int minCost = GridCostPathRightDownDiag(c, false, false);

            std::cout << "Max c: " << maxCost << std::endl;
            std::cout << "Min c: " << minCost << std::endl;


            int maxCostD = GridCostPathRightDownDiag(c, true, true);
            int minCostD = GridCostPathRightDownDiag(c, false, true);

            std::cout << "Max d c: " << maxCostD << std::endl;
            std::cout << "Min d c: " << minCostD << std::endl;

           
        }
        void GridNumPathRightDownDiagD()
        {

            std::vector<std::vector<bool>> c = { {1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1},
                {1, 0, 1, 1, 0},
                {1, 1, 0, 1, 1},
                {1, 1, 1, 1, 1} };

            int wayNum = GridNumPathRightDownDiag(c, false);
            int wayNumD = GridNumPathRightDownDiag(c, true);


            std::cout << "way : " << wayNum << std::endl;
            std::cout << "way d : " << wayNumD << std::endl;
        }
        void Knap01D()
        {
            int w = 10;
            std::vector<int> wt = { 5, 4, 6, 3 };
            std::vector<int> v = { 10, 40, 30, 50 };
            int mil = Knap01(v, wt, w);


            std::cout << "way : " << mil << std::endl;
        }
        void EditDistD()
        {
            std::string s1 = "kitten";
            std::string s2 = "sitting";

            int minDist = EditDist(s1, s2);

            std::cout << "Min Dist: " << minDist << std::endl;
        }
        void SubArrSum2PtrD()
        {
            std::vector<int> arr = { 1, 3, 2, 5, 1, 1, 2, 3 };
            int s = 8;

            auto subArr = SubArrSum2Ptr(arr, s);

            std::cout << "Sub Arr: " << std::endl;

            for (auto& i : subArr)
            {
                std::cout <<i << std::endl;
            }
        }
        void SubArr2SumHashD()
        {
            std::vector<int> arr = { 2, 3, 4, 4, 7, 8, 9, 10, 12, 14, 21, 22, 100, 32 };
            int s = 33;

            auto subArr = SubArr2SumHash(arr, s);

            std::cout << "Sub Arr: " << std::endl;

            for (auto& i : subArr)
            {
                std::cout <<i.first <<", ";
                std::cout <<i.second << std::endl;
            }
        }        
        void SubArr3SumHashD()
        {
            std::vector<int> arr = { 1, 4, 45, 6, 10, 8 };
            int s = 22;

            auto subArr = SubArr3SumHash(arr, s);

            std::cout << "Sub Arr: " << std::endl;

            for (auto& i : subArr)
            {
                std::cout <<std::get<0>(i) <<", ";
                std::cout <<std::get<1>(i) <<", ";
                std::cout <<std::get<2>(i) <<"\n";
                //std::cout <<i.second << std::endl;
            }
        }        
        void SubArr4SumHashD()
        {
            std::vector<int> arr = { 10, 20, 30, 40, 1, 2 };
            int s = 91;

            auto subArr = SubArr4SumHash(arr, s);

            std::cout << "Sub Arr: " << std::endl;

            for (auto& i : subArr)
            {
                std::cout <<std::get<0>(i) <<", ";
                std::cout <<std::get<1>(i) <<", ";
                std::cout <<std::get<2>(i) <<", ";
                std::cout <<std::get<3>(i) <<"\n";
                //std::cout <<i.second << std::endl;
            }
        }
    }
}