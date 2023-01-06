#include "Demo.h"


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
            std::vector<int> c = { 1, 2, 5, 10, 20, 50, 100, 200 };
            minNumC = MinNumCToSumIterative(n, c);
            std::cout << "min num C: " << minNumC << std::endl;
        }
        void MinNumCToSumIterativeReturnCD()
        {
            int n = 520;
            //int minNumC = 0;
            std::vector<int> c = { 1, 2, 5, 10, 20, 50, 100, 200 };
            auto minNumC = MinNumCToSumIterativeReturnC(n, c);
            std::cout << "min num C: " << std::get<0>(minNumC) << std::endl;
            std::cout << "all C: " << std::endl;
            for (auto& ci : std::get<1>(minNumC))
            {
                std::cout << ci << std::endl;
            }

        }
        void MaxNumWawToSumIterativeD()
        {
            int n = 5;
            //int minNumC = 0;

            std::vector<int> c = { 1, 3, 4 };
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
                std::cout << "\t\t" << ss << std::endl;
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
                std::cout << i << std::endl;
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
                std::cout << i.first << ", ";
                std::cout << i.second << std::endl;
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
                std::cout << std::get<0>(i) << ", ";
                std::cout << std::get<1>(i) << ", ";
                std::cout << std::get<2>(i) << "\n";
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
                std::cout << std::get<0>(i) << ", ";
                std::cout << std::get<1>(i) << ", ";
                std::cout << std::get<2>(i) << ", ";
                std::cout << std::get<3>(i) << "\n";
                //std::cout <<i.second << std::endl;
            }
        }
        void BellManD()
        {

            std::vector < std::tuple<std::string, std::string, int>> g = { {"1", "2", 5},{"1", "4", 9},{"1", "5", 1},
                                                            {"2", "1", 5},{"2", "3", 2},
                                                            {"3", "2", 2},{"3", "4", 6},
                                                            {"4", "1", 9},{"4", "3", 6},{"4", "5", 2},
                                                            {"5", "1", 1},{"5", "4", 2},
            };
            std::vector<std::string> nodes = { "1", "2", "3", "4", "5" };

            BellMan(g, nodes, "1");
        }
        void FloydWarshallD()
        {
            std::map <std::string, std::map <std::string, int>> g;
            g["1"]["1"] = 0;
            g["2"]["1"] = 5;
            g["3"]["1"] = 0;
            g["4"]["1"] = 9;
            g["5"]["1"] = 1;

            g["1"]["2"] = 5;
            g["2"]["2"] = 0;
            g["3"]["2"] = 2;
            g["4"]["2"] = 0;
            g["5"]["2"] = 0;

            g["1"]["3"] = 0;
            g["2"]["3"] = 2;
            g["3"]["3"] = 0;
            g["4"]["3"] = 7;
            g["5"]["3"] = 0;

            g["1"]["4"] = 9;
            g["2"]["4"] = 0;
            g["3"]["4"] = 7;
            g["4"]["4"] = 0;
            g["5"]["4"] = 2;

            g["1"]["5"] = 1;
            g["2"]["5"] = 0;
            g["3"]["5"] = 0;
            g["4"]["5"] = 2;
            g["5"]["5"] = 0;


            std::vector<std::string> nodes = { "1", "2", "3", "4", "5" };

            FloydWarshall(g, nodes, "1");
        }
        void DijkstraD()
        {
            std::map <std::string, std::vector<std::pair<std::string, int>>> g;

            g["1"] = { {"2", 5},{"4", 9},{"5", 1} };
            g["2"] = { {"1", 5},{"3", 2} };
            g["3"] = { {"2", 2},{"4", 6} };
            g["4"] = { {"1", 9},{"3", 6},{"5", 2} };
            g["5"] = { {"1", 1},{"4", 2} };
            std::vector<std::string> nodes = { "1", "2", "3", "4", "5" };

            Dijkstra(g, nodes, "1");
        }
        void DFSStackD()
        {
            std::map <std::string, std::vector<std::string>> g;
            g["1"] = { "2", "4" };
            g["2"] = { "1", "3", "5" };
            g["3"] = { "2", "5" };
            g["4"] = { "1" };
            std::vector<std::string> vertices = { "1", "2", "3", "4", "5" };
            DFSStack(g, vertices, "1");

        }
        void DFSRecursionD()
        {
            std::map <std::string, std::vector<std::string>> g;
            g["1"] = { "2", "4" };
            g["2"] = { "1", "3", "5" };
            g["3"] = { "2", "5" };
            g["4"] = { "1" };
            std::vector<std::string> vertices = { "1", "2", "3", "4", "5" };
            std::map<std::string, bool> vist;
            for (auto& vert : vertices)
            {
                vist[vert] = false;
            }
            DFSRecursion(g, vertices, "1", vist);

        }
        void BFSQueueD()
        {
            std::map <std::string, std::vector<std::string>> g;
            g["1"] = { "2", "4" };
            g["2"] = { "1", "3", "5" };
            g["3"] = { "2", "6" };
            g["4"] = { "1" };
            g["5"] = { "2", "6" };
            g["6"] = { "3", "5" };
            std::vector<std::string> vertices = { "1", "2", "3", "4", "5", "6" };
            BFSQueue(g, vertices, "1");
        }
        void IsGConnectedD()
        {
            std::map <std::string, std::vector<std::string>> g;
            g["1"] = { "3", "4" };
            g["2"] = { "5" };


            ////connected
            //g["1"] = { "2", "4" };
            //g["2"] = { "1", "3", "5" };
            //g["3"] = { "2", "5" };
            //g["4"] = { "1" };
            std::vector<std::string> vertices = { "1", "2", "3", "4", "5" };
            IsGConnected(g, vertices);

        }
        void NumGConnectedD()
        {
            std::map <std::string, std::vector<std::string>> g;
            g["1"] = { "3", "4" };
            g["2"] = { "5" };


            ////connected
            //g["1"] = { "2", "4" };
            //g["2"] = { "1", "3", "5" };
            //g["3"] = { "2", "5" };
            //g["4"] = { "1" };
            std::vector<std::string> vertices = { "1", "2", "3", "4", "5" };
            NumGConnected(g, vertices);

        }
        void HasGCycleD()
        {
            std::map <std::string, std::vector<std::string>> g;
            //g["1"] = { "3", "4" };
            //g["2"] = { "5" };


            //connected
            g["1"] = { "2", "4" };
            g["2"] = { "1", "3", "5" };
            g["3"] = { "2", "5" };
            g["4"] = { "1" };
            std::vector<std::string> vertices = { "1", "2", "3", "4", "5" };
            HasGCycle(g, vertices);
        }
        void CanColorRedBlueD()
        {
            std::map <std::string, std::vector<std::string>> g;



            ////no
            //g["1"] = { "2", "4" };
            //g["2"] = { "1", "3", "5" };
            //g["3"] = { "2", "5" };
            //g["4"] = { "1" };

            //yes
            g["1"] = { "2" };
            g["2"] = { "3" };
            g["3"] = { "4" };
            std::vector<std::string> vertices = { "1", "2", "3", "4" };
            CanColorRedBlue(g, vertices);
        }
        void TopologicalSortKahnD()
        {
            //{ 0, 6 }, { 1, 2 }, { 1, 4 }, { 1, 6 }, { 3, 0 }, { 3, 4 },
            //{ 5, 1 }, { 7, 0 }, { 7, 1 }
            std::map <std::string, std::vector<std::string>> g;
            g["0"] = { "6" };
            g["1"] = { "2", "4", "6" };
            g["3"] = { "0", "4" };
            g["5"] = { "1" };
            g["7"] = { "0", "1" };
            std::vector<std::string> vertices = { "0", "1", "2", "3", "4", "5", "6", "7" };
            TopologicalSortKahn(g, vertices);

        }
        void DFSArrivalDepartureTD()
        {


            std::map <std::string, std::vector<std::string>> g;
            g["0"] = { "1", "2" };
            g["2"] = { "3", "4" };
            g["3"] = { "1", "5" };
            g["4"] = { "5" };
            g["6"] = { "7" };
            std::vector<std::string> vertices = { "0", "1", "2", "3", "4", "5", "6", "7" };
            DFSArrivalDepartureT(g, vertices);

        }
        //check
        void DFSArrivalDepartureStackD()
        {


            std::map <std::string, std::vector<std::string>> g;
            g["0"] = { "1", "2" };
            g["2"] = { "3", "4" };
            g["3"] = { "1", "5" };
            g["4"] = { "5" };
            g["6"] = { "7" };
            std::vector<std::string> vertices = { "0", "1", "2", "3", "4", "5", "6", "7" };
            DFSArrivalDepartureStack(g, vertices);

        }
        void TopologicalSortDFSD()
        {

            std::map <std::string, std::vector<std::string>> g;
            ////clycle
            //g["1"] = { "2"};
            //g["2"] = { "3"};
            //g["3"] = { "5", "6"};
            //g["4"] = { "1", "5"};
            //g["5"] = { "2"};            

            //no clycle
            g["1"] = { "2" };
            g["2"] = { "3" };
            g["3"] = { "6" };
            g["4"] = { "1", "5" };
            g["5"] = { "2", "3" };

            std::vector<std::string> vertices = { "1", "2", "3", "4", "5", "6" };
            TopologicalSortDFS(g, vertices);
        }
        void TopologicalSortDFS3StatesD()
        {

            std::map <std::string, std::vector<std::string>> g;
            ////clycle
            //g["1"] = { "2"};
            //g["2"] = { "3"};
            //g["3"] = { "5", "6"};
            //g["4"] = { "1", "5"};
            //g["5"] = { "2"};            

            //no clycle
            g["1"] = { "2" };
            g["2"] = { "3" };
            g["3"] = { "6" };
            g["4"] = { "1", "5" };
            g["5"] = { "2", "3" };

            std::vector<std::string> vertices = { "1", "2", "3", "4", "5", "6" };
            TopologicalSortDFS3States(g, vertices);
        }
        void TreeDiameterD()
        {
            std::map <std::string, std::vector<std::string>> g;
            g["1"] = { "2" , "3", "4" };
            g["2"] = { "1", "5", "6" };
            g["3"] = { "1" };
            g["4"] = { "1", "7" };
            g["5"] = { "2" };
            g["6"] = { "2" };
            g["7"] = { "4" };
            std::vector<std::string> vertices = { "1", "2", "3", "4", "5", "6", "7" };
            TreeDiameter(g, vertices);
        }
        void SpanningTreeKruskalD()
        {
            std::map <std::string, std::vector<std::pair<std::string, int>>> g;
            g["1"] = { {"2", 3 },{"5", 5 } };
            g["2"] = { {"3", 5 },{"5", 6 } };
            g["3"] = { {"4", 9 },{"6", 3 } };
            g["4"] = { {"6", 7 } };
            g["5"] = { {"6", 2 } };

            std::vector<std::string> vertices = { "1", "2", "3", "4", "5", "6" };
            SpanningTreeKruskal(g, vertices);

        }
        void CreateSuccessorGraphTableD()
        {
            std::map <std::string, std::string> g;
            g["1"] = "3";
            g["2"] = "5";
            g["3"] = "7";
            g["4"] = "6";
            g["5"] = "2";
            g["6"] = "2";
            g["7"] = "1";
            g["8"] = "6";
            g["9"] = "3";

            std::vector<std::string> vertices = { "1", "2","3","4","5","6", "7", "8",  "9" };

            CreateSuccessorGraphTable(g, vertices);
        }
        void TwoSum1()
        {
            TNodeI t1, t2, t3, t4, t5, t6;
            t1.val = 5;
            t2.val = 3;
            t3.val = 6;
            t4.val = 2;
            t5.val = 4;
            t6.val = 7;

            t1.l = &t2;
            t1.r = &t3;

            t2.l = &t4;
            t2.r = &t5;

            t3.r = &t6;

            TwoSum1(t1, 13);

        }
        void TwoSum2()
        {
            TNodeI t1, t2, t3, t4, t5, t6;
            t1.val = 5;
            t2.val = 3;
            t3.val = 6;
            t4.val = 2;
            t5.val = 4;
            t6.val = 7;

            t1.l = &t2;
            t1.r = &t3;

            t2.l = &t4;
            t2.r = &t5;

            t3.r = &t6;

            TwoSum2(t1, 13);

        }
        void Inorder1D()
        {
            TNodeI* t1 = new TNodeI(30), * t2 = new TNodeI(20), * t3 = new TNodeI(40), * t4 = new TNodeI(15),
                * t5 = new TNodeI(25), * t6 = new TNodeI(35), * t7 = new TNodeI(50), * t8 = new TNodeI(5),
                * t9 = new TNodeI(18), * t10 = new TNodeI(45), * t11 = new TNodeI(60);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            t4->l = t8;
            t4->r = t9;

            t3->l = t6;
            t3->r = t7;

            t7->l = t10;
            t7->r = t11;


            std::vector<int> inorderData;

            Inorder1(t1, inorderData);

            for (auto& dd : inorderData)
            {
                std::cout << dd << std::endl;
            }
            //{ 5 , 15 , 18 , 20 , 25 , 30 , 35 , 40 , 45 , 50 , 60 }


        }
        void Preorder1D()
        {
            TNodeI* t1 = new TNodeI(30), * t2 = new TNodeI(20), * t3 = new TNodeI(40), * t4 = new TNodeI(15),
                * t5 = new TNodeI(25), * t6 = new TNodeI(35), * t7 = new TNodeI(50), * t8 = new TNodeI(5),
                * t9 = new TNodeI(18), * t10 = new TNodeI(45), * t11 = new TNodeI(60);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            t4->l = t8;
            t4->r = t9;

            t3->l = t6;
            t3->r = t7;

            t7->l = t10;
            t7->r = t11;


            std::vector<int> preorderData;

            Preorder1(t1, preorderData);

            for (auto& dd : preorderData)
            {
                std::cout << dd << std::endl;
            }
            //{30, 20, 15, 5, 18, 25, 40, 35, 50, 45, 60}
        }
        void Postorder1D()
        {
            TNodeI* t1 = new TNodeI(30), * t2 = new TNodeI(20), * t3 = new TNodeI(40), * t4 = new TNodeI(15),
                * t5 = new TNodeI(25), * t6 = new TNodeI(35), * t7 = new TNodeI(50), * t8 = new TNodeI(5),
                * t9 = new TNodeI(18), * t10 = new TNodeI(45), * t11 = new TNodeI(60);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            t4->l = t8;
            t4->r = t9;

            t3->l = t6;
            t3->r = t7;

            t7->l = t10;


            std::vector<int> postorderData;

            Postorder1(t1, postorderData);

            for (auto& dd : postorderData)
            {
                std::cout << dd << std::endl;
            }

            //{5 , 18 , 15 , 25 , 20 , 35 , 45 , 60 , 50 , 40 , 30}
        }
        void Levelorder1D()
        {
            TNodeI* t1 = new TNodeI(30), * t2 = new TNodeI(20), * t3 = new TNodeI(40), * t4 = new TNodeI(15),
                * t5 = new TNodeI(25), * t6 = new TNodeI(35), * t7 = new TNodeI(50), * t8 = new TNodeI(5),
                * t9 = new TNodeI(18), * t10 = new TNodeI(45), * t11 = new TNodeI(60);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            t4->l = t8;
            t4->r = t9;

            t3->l = t6;
            t3->r = t7;

            t7->l = t10;
            t7->r = t11;


            std::vector<int> levelorderData;

            Levelorder1(t1, levelorderData);

            std::cout << "Tree level order trasveral using queue\n";
            for (auto& dd : levelorderData)
            {
                std::cout << dd << ", ";
            }
            std::cout << std::endl;
            //{30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60}

        }
        void Inorder2D()
        {
            TNodeI* t1 = new TNodeI(30), * t2 = new TNodeI(20), * t3 = new TNodeI(40), * t4 = new TNodeI(15),
                * t5 = new TNodeI(25), * t6 = new TNodeI(35), * t7 = new TNodeI(50), * t8 = new TNodeI(5),
                * t9 = new TNodeI(18), * t10 = new TNodeI(45), * t11 = new TNodeI(60);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            t4->l = t8;
            t4->r = t9;

            t3->l = t6;
            t3->r = t7;

            t7->l = t10;
            t7->r = t11;


            std::vector<int> inorderData;

            Inorder2(t1, inorderData);

            for (auto& dd : inorderData)
            {
                std::cout << dd << std::endl;
            }
            //{ 5 , 15 , 18 , 20 , 25 , 30 , 35 , 40 , 45 , 50 , 60 }

        }
        void Preorder2D()
        {
            TNodeI* t1 = new TNodeI(30), * t2 = new TNodeI(20), * t3 = new TNodeI(40), * t4 = new TNodeI(15),
                * t5 = new TNodeI(25), * t6 = new TNodeI(35), * t7 = new TNodeI(50), * t8 = new TNodeI(5),
                * t9 = new TNodeI(18), * t10 = new TNodeI(45), * t11 = new TNodeI(60);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            t4->l = t8;
            t4->r = t9;

            t3->l = t6;
            t3->r = t7;

            t7->l = t10;
            t7->r = t11;


            std::vector<int> preorderData;

            Preorder2(t1, preorderData);

            for (auto& dd : preorderData)
            {
                std::cout << dd << std::endl;
            }
            //{30, 20, 15, 5, 18, 25, 40, 35, 50, 45, 60}
        }
        void Postorder2D()
        {
            TNodeI* t1 = new TNodeI(30), * t2 = new TNodeI(20), * t3 = new TNodeI(40), * t4 = new TNodeI(15),
                * t5 = new TNodeI(25), * t6 = new TNodeI(35), * t7 = new TNodeI(50), * t8 = new TNodeI(5),
                * t9 = new TNodeI(18), * t10 = new TNodeI(45), * t11 = new TNodeI(60);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            t4->l = t8;
            t4->r = t9;

            t3->l = t6;
            t3->r = t7;

            t7->l = t10;


            std::vector<int> postorderData;

            Postorder1(t1, postorderData);

            for (auto& dd : postorderData)
            {
                std::cout << dd << std::endl;
            }

            //{5 , 18 , 15 , 25 , 20 , 35 , 45 , 60 , 50 , 40 , 30}
        }
        void Inversion1D()
        {
            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(10), * t3 = new TNodeI(7), * t4 = new TNodeI(6),
                * t5 = new TNodeI(2), * t6 = new TNodeI(5);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            t3->r = t6;

            std::vector<int> levelorderData;

            Levelorder1(t1, levelorderData);

            std::cout << "Before Inversion Level Order" << std::endl;
            for (auto& dd : levelorderData)
            {
                std::cout << dd << std::endl;
            }

            //{1 , 10 , 7 , 6 , 2 , 5}
            levelorderData.clear();
            Inversion1(t1);

            Levelorder1(t1, levelorderData);


            std::cout << "After Inversion Level Order" << std::endl;
            for (auto& dd : levelorderData)
            {
                std::cout << dd << std::endl;
            }
            //{1 , 7 , 10 , 5 , 2 , 6}

        }
        void Inversion2D()
        {
            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(10), * t3 = new TNodeI(7), * t4 = new TNodeI(6),
                * t5 = new TNodeI(2), * t6 = new TNodeI(5);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            t3->r = t6;

            std::vector<int> levelorderData;

            Levelorder1(t1, levelorderData);

            std::cout << "Before Inversion Level Order" << std::endl;
            std::cout << std::endl;
            for (auto& dd : levelorderData)
            {
                std::cout << dd << ", ";
            }
            std::cout << std::endl << std::endl;

            //{1 , 10 , 7 , 6 , 2 , 5}
            levelorderData.clear();
            Inversion2(t1);

            Levelorder1(t1, levelorderData);


            std::cout << "After Inversion Level Order" << std::endl;
            std::cout << std::endl;
            for (auto& dd : levelorderData)
            {
                std::cout << dd << ", ";
            }
            std::cout << std::endl << std::endl;
            //{1 , 7 , 10 , 5 , 2 , 6}

        }
        void Inversion3D()
        {
            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(10), * t3 = new TNodeI(7), * t4 = new TNodeI(6),
                * t5 = new TNodeI(2), * t6 = new TNodeI(5);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            t3->r = t6;

            std::vector<int> levelorderData;

            Levelorder1(t1, levelorderData);

            std::cout << "Before Inversion Level Order" << std::endl;
            std::cout << std::endl;
            for (auto& dd : levelorderData)
            {
                std::cout << dd << ", ";
            }
            std::cout << std::endl << std::endl;

            //{1 , 10 , 7 , 6 , 2 , 5}
            levelorderData.clear();
            Inversion3(t1);

            Levelorder1(t1, levelorderData);


            std::cout << "After Inversion Level Order" << std::endl;
            std::cout << std::endl;
            for (auto& dd : levelorderData)
            {
                std::cout << dd << ", ";
            }
            std::cout << std::endl << std::endl;
            //{1 , 7 , 10 , 5 , 2 , 6}

        }
        void BinTreeFromPreInorderD()
        {

            std::vector<int> inOrder = { 4, 2, 5, 1, 6, 3 };
            std::vector<int> preOrder = { 1, 2, 4, 5, 3, 6 };
            int currIdx = 0;
            int lIdx = 0;
            int rIdx = preOrder.size() - 1;

            std::cout << "Constructing Binary Tree from Preorder and Inorder\n";
            std::cout << std::endl << std::endl;
            TNodeI* racine = BinTreeFromPreInorder(inOrder, preOrder, currIdx, lIdx, rIdx);

            //Preorder
            // { 4, 2, 5, 1, 6, 3 };

            std::vector<int> preorderData;

            Preorder1(racine, preorderData);
            std::cout << "Preorder\n";
            std::cout << std::endl << std::endl;
            for (auto& dd : preorderData)
            {
                std::cout << dd << ", ";
            }
            std::cout << std::endl << std::endl;
            //Inorder
            // { 4, 2, 5, 1, 6, 3 };
            std::vector<int> inorderData;

            Inorder1(racine, inorderData);

            std::cout << "Inorder\n";
            std::cout << std::endl << std::endl;
            for (auto& dd : inorderData)
            {
                std::cout << dd << ", ";
            }
            std::cout << std::endl << std::endl;

        }
        void HeightTreeD()
        {
            TNodeI* t1 = new TNodeI(10), * t2 = new TNodeI(20), * t3 = new TNodeI(30), * t4 = new TNodeI(40),
                * t5 = new TNodeI(28), * t6 = new TNodeI(27), * t7 = new TNodeI(50), * t8 = new TNodeI(29);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            t3->l = t6;
            t3->r = t7;

            t6->r = t8;

            std::cout << "Tree Height" << std::endl;

            std::cout << HeightTree(t1) << std::endl;


        }
        void LevelFromRootD()
        {
            GTNodeI* t1 = new GTNodeI(0), * t2 = new GTNodeI(1), * t3 = new GTNodeI(2), * t4 = new GTNodeI(3),
                * t5 = new GTNodeI(4), * t6 = new GTNodeI(5), * t7 = new GTNodeI(6), * t8 = new GTNodeI(7);

            t1->childreen = { t2, t3, t4 };
            t2->childreen = { t5, t6 };
            t3->childreen = { t7, t8 };
            t4->childreen = { t8 };



            std::cout << "Level from root" << std::endl;

            LevelFromRoot(t1);
        }
        void TriDiameter1D()
        {
            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(2), * t3 = new TNodeI(3), * t4 = new TNodeI(4),
                * t5 = new TNodeI(5);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;



            std::cout << "Tree Diameter Recursion" << std::endl;

            std::cout << TriDiameter1(t1) << std::endl;
            // 4
        }
        void TriDiameter2D()
        {

            GTNodeI* t1 = new GTNodeI(1), * t2 = new GTNodeI(2), * t3 = new GTNodeI(3), * t4 = new GTNodeI(4),
                * t5 = new GTNodeI(5);
            t1->childreen = { t2, t3 };
            t2->childreen = { t1, t4, t5 };
            t3->childreen = { t1 };
            t4->childreen = { t2 };
            t5->childreen = { t2 };




            std::cout << "Tree Diameter 2 BFS" << std::endl;

            //std::cout << TriDiameter2(t1) << std::endl;
            std::cout << TriDiameter2(t1) << std::endl;

        }
        void TriUniversalD()
        {
            //    TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(3), * t3 = new TNodeI(3), * t4 = new TNodeI(3),
            //        * t5 = new TNodeI(3);

            //    t1->l = t2;
            //    t1->r = t3;

            //    t2->l = t4;
            //    t2->r = t5;
            //    //4            

            TNodeI* t1 = new TNodeI(5), * t2 = new TNodeI(4), * t3 = new TNodeI(3), * t4 = new TNodeI(4),
                * t5 = new TNodeI(3), * t6 = new TNodeI(3);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t3->l = t5;
            t3->r = t6;
            //5


            std::cout << "Universal tree count" << std::endl;
            int cnt = 0;
            TriUniversal(t1, cnt);
            std::cout << cnt << std::endl;
            //4
        }
        void TriCountSubtreesumD()
        {

            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(3), * t3 = new TNodeI(4), * t4 = new TNodeI(2),
                * t5 = new TNodeI(6), * t6 = new TNodeI(1), * t7 = new TNodeI(11), * t8 = new TNodeI(11), * t9 = new TNodeI(1);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;


            t3->l = t6;
            t3->r = t7;

            t7->l = t8;
            t7->r = t9;
            int sumVal = 1;

            std::cout << "Number of subtree of sum " << sumVal << std::endl;
            std::cout << TriCountSubtreesum(t1, sumVal);
            std::cout << std::endl;
        }
        void TriSubTriOfEachOtherD()
        {

            TNodeS* ta = new TNodeS("a"), * tb = new TNodeS("b"), * tc = new TNodeS("c"), * td = new TNodeS("d"),
                * te = new TNodeS("e"), * tf = new TNodeS("f"), * tg = new TNodeS("g"), * th = new TNodeS("h"),
                * ti = new TNodeS("i"), * tj = new TNodeS("j"), * tk = new TNodeS("k"), * tl = new TNodeS("l");

            TNodeS* sc = new TNodeS("c"), * sf = new TNodeS("f"), * sg = new TNodeS("g"),
                * sk = new TNodeS("k"), * sl = new TNodeS("l"), * sh = new TNodeS("h");
            ta->l = tb;
            ta->r = tc;


            tb->l = td;
            tb->r = te;


            tc->l = tf;
            tc->r = tg;


            tg->l = tk;
            tg->r = tl;

            td->l = th;
            td->r = ti;


            te->r = tj;

            sc->l = sf;
            sc->r = sg;


            sg->l = sk;
            sg->r = sl;

            //not subtree
            sf->l = sh;


            std::cout << "Checking if tree A is subtree of tree B" << std::endl;
            std::cout << std::endl;
            if (TriSubTriOfEachOther(sc, ta))
            {
                std::cout << "Yes" << std::endl;
            }
            else
            {
                std::cout << "No" << std::endl;
            }


        }
        void TriBalanceD()
        {
            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(2), * t3 = new TNodeI(3), * t4 = new TNodeI(4),
                * t5 = new TNodeI(5), * t6 = new TNodeI(6);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            //not balanced
            //t5->r = t6;


            std::cout << "Tree Balanced" << std::endl;

            std::cout << std::endl;
            if (TriBalance(t1) != -1)
            {
                std::cout << "Yes" << std::endl;
            }
            else
            {
                std::cout << "No" << std::endl;
            }

        }
        void TriDuplicate1D()
        {
            /*
    6
  /   \
10      9
/  \    / \
12   6  5   4

*/

            TNodeI* t1 = new TNodeI(6), * t2 = new TNodeI(10), * t3 = new TNodeI(9), * t4 = new TNodeI(12),
                * t5 = new TNodeI(6), * t6 = new TNodeI(5), * t7 = new TNodeI(4);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;


            t3->l = t6;
            t3->r = t7;

            //duplicate
            //t2->r = t5;
            std::unordered_set<int> vis;
            std::cout << "Tree Duplicate" << std::endl;
            std::cout << std::endl;
            if (TriDuplicate1(t1, vis))
            {
                std::cout << "Yes" << std::endl;
            }
            else
            {
                std::cout << "No" << std::endl;
            }
        }
        void TriDuplicate2D()
        {
            /*
        6
      /   \
    10      9
    /  \    / \
    12   6  5   4

    */

            TNodeI* t1 = new TNodeI(6), * t2 = new TNodeI(10), * t3 = new TNodeI(9), * t4 = new TNodeI(12),
                * t5 = new TNodeI(6), * t6 = new TNodeI(5), * t7 = new TNodeI(4);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;


            t3->l = t6;
            t3->r = t7;

            //duplicate
            //t2->r = t5;
            std::cout << "Tree Duplicate 2" << std::endl;
            std::cout << std::endl;
            if (TriDuplicate2(t1))
            {
                std::cout << "Yes" << std::endl;
            }
            else
            {
                std::cout << "No" << std::endl;
            }
        }
        void TriNodesAtDistanceKFromRoot1D()
        {
            /* Constructed binary tree is
                     1
                    / \
                   2    3
                  /    / \
                 4    5   6
                /
               7
            */

            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(2), * t3 = new TNodeI(3), * t4 = new TNodeI(4),
                * t5 = new TNodeI(5), * t6 = new TNodeI(6), * t7 = new TNodeI(7);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;


            t3->l = t5;
            t3->r = t6;


            t4->l = t7;
            int k = 1;
            std::vector< TNodeI*> levelKNodes;
            std::cout << "Nodes at distance  " << k << " from root" << std::endl;
            std::cout << std::endl;
            TriNodesAtDistanceKFromRoot1(t1, k, levelKNodes);

            std::cout << std::endl;
            for (auto node : levelKNodes)
            {
                std::cout << node->val << ", ";
            }
            std::cout << std::endl;

        }
        void TriNodesAtDistanceKFromRoot2D()
        {
            /* Constructed binary tree is
                     1
                    / \
                   2    3
                  /    / \
                 4    5   6
                /
               7
            */

            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(2), * t3 = new TNodeI(3), * t4 = new TNodeI(4),
                * t5 = new TNodeI(5), * t6 = new TNodeI(6), * t7 = new TNodeI(7);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;


            t3->l = t5;
            t3->r = t6;


            t4->l = t7;
            int k = 2;
            std::vector< TNodeI*> levelKNodes;
            std::cout << "Nodes at distance  " << k << " from root" << std::endl;
            std::cout << std::endl;
            TriNodesAtDistanceKFromRoot2(t1, k, levelKNodes);

            std::cout << std::endl;
            for (auto node : levelKNodes)
            {
                std::cout << node->val << ", ";
            }
            std::cout << std::endl;

        }
        void Levelorder2D()
        {
            TNodeI* t1 = new TNodeI(30), * t2 = new TNodeI(20), * t3 = new TNodeI(40), * t4 = new TNodeI(15),
                * t5 = new TNodeI(25), * t6 = new TNodeI(35), * t7 = new TNodeI(50), * t8 = new TNodeI(5),
                * t9 = new TNodeI(18), * t10 = new TNodeI(45), * t11 = new TNodeI(60);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            t4->l = t8;
            t4->r = t9;

            t3->l = t6;
            t3->r = t7;

            t7->l = t10;
            t7->r = t11;


            std::vector<int> levelorderData;

            Levelorder2(t1, levelorderData);

            std::cout << "Tree level order trasveral using recursion\n";
            for (auto& dd : levelorderData)
            {
                std::cout << dd << ", ";
            }
            std::cout << std::endl;
            //{30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60}

        }
        void Levelorder3D()
        {
            /* Constructed binary tree is
                     1
                    / \
                   2    3
                  /    / \
                 4    5   6
                /
               7
            */

            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(2), * t3 = new TNodeI(3), * t4 = new TNodeI(4),
                * t5 = new TNodeI(5), * t6 = new TNodeI(6), * t7 = new TNodeI(7);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;


            t3->l = t5;
            t3->r = t6;


            t4->l = t7;

            std::map<int, std::vector<TNodeI*>> levelorderData;

            Levelorder3(t1, levelorderData);

            std::cout << "Tree level order trasveral nodes per level iterative\n";
            for (auto& dd : levelorderData)
            {
                std::cout << "level " << dd.first << std::endl;
                for (auto node : dd.second)
                {
                    std::cout << node->val << ", ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            //{30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60}

        }
        void Levelorder4D()
        {
            /* Constructed binary tree is
                     1
                    / \
                   2    3
                  /    / \
                 4    5   6
                /
               7
            */

            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(2), * t3 = new TNodeI(3), * t4 = new TNodeI(4),
                * t5 = new TNodeI(5), * t6 = new TNodeI(6), * t7 = new TNodeI(7);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;


            t3->l = t5;
            t3->r = t6;


            t4->l = t7;

            std::map<int, std::vector<TNodeI*>> levelorderData;

            Levelorder4(t1, levelorderData);

            std::cout << "Tree level order trasveral nodes per level recursion\n";
            for (auto& dd : levelorderData)
            {
                std::cout << "level " << dd.first << std::endl;
                for (auto node : dd.second)
                {
                    std::cout << node->val << ", ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            //{30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60}

        }
        void TriAncestor1D()
        {
            /* Constructed binary tree is
                       1
                      / \
                     2    3
                    /    / \
                   4    5   6
                  /
                 7
              */

            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(2), * t3 = new TNodeI(3), * t4 = new TNodeI(4),
                * t5 = new TNodeI(5), * t6 = new TNodeI(6), * t7 = new TNodeI(7);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;


            t3->l = t5;
            t3->r = t6;


            t4->l = t7;

            std::vector< TNodeI*> ances;
            auto node = t5;
            TriAncestor1(t1, node, ances);
            std::cout << "Ancestor of " << node->val << "  \n";
            for (auto& dd : ances)
            {

                std::cout << dd->val << ", ";
            }
            std::cout << std::endl;
            //{30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60}

        }
        void TriAncestor2D()
        {
            /* Constructed binary tree is
                       1
                      / \
                     2    3
                    /    / \
                   4    5   6
                  /
                 7
              */

            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(2), * t3 = new TNodeI(3), * t4 = new TNodeI(4),
                * t5 = new TNodeI(5), * t6 = new TNodeI(6), * t7 = new TNodeI(7);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;


            t3->l = t5;
            t3->r = t6;


            t4->l = t7;

            std::vector< TNodeI*> ances;
            auto node = t5;
            TriAncestor2(t1, node, ances);
            std::cout << "Ancestor of " << node->val << "  \n";
            for (auto& dd : ances)
            {

                std::cout << dd->val << ", ";
            }
            std::cout << std::endl;
            //{30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60}

        }
        void TriEnCodingD()
        {
            /* Constructed binary tree is
                       1
                      / \
                     4    2
                    / \    \
                   6   5     3
                  
              */

            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(4), * t3 = new TNodeI(2), * t4 = new TNodeI(6),
                * t5 = new TNodeI(5), * t6 = new TNodeI(3);
            t1->l = t2;
            t1->r = t3;
            t2->l = t4;
            t2->r = t5;
            t3->r = t6;
            std::deque<bool> enCodeBitList;
            std::deque<int> enCodeDataList;
            TriEnCoding(t1, enCodeBitList, enCodeDataList);
        
            std::cout << "Encoding Tree\n";

            std::cout << "Bits: ";
            for (int iBitVal = 0; iBitVal < enCodeBitList.size(); iBitVal++)
            {
                std::cout << enCodeBitList[iBitVal] << ", ";
            }
            std::cout << std::endl;

            std::cout << "Data: ";
            for (int iDataVal = 0; iDataVal < enCodeDataList.size(); iDataVal++)
            {
                std::cout << enCodeDataList[iDataVal] << ", ";
            }
            std::cout << std::endl;
        }
        void TriDeCodingD()
        {
            /* Constructed binary tree is
                       1
                      / \
                     4    2
                    / \    \
                   6   5     3

              */


            std::deque<bool> enCodeBitList = { 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0 };
            std::deque<int> enCodeDataList = { 1, 4, 6, 5, 2, 3 };
            
            
            TNodeI* racine = TriDeCoding(enCodeBitList, enCodeDataList);
            std::vector<int> preorderData;

            Preorder1(racine, preorderData);
            std::cout << "Decoding Tree\n";
            std::cout << "Preorder Tree: ";
            for (auto& dd : preorderData)
            {
                std::cout << dd <<", ";
            }
            std::cout << std::endl;

        }
        void TriSerialize1D()
        {
            /* Constructed binary tree is
                       5
                      / \
                     0    6
                    / \    \
                   1   2    7
                    \
                     3
              */

            TNodeI* t1 = new TNodeI(5), * t2 = new TNodeI(0), * t3 = new TNodeI(6), * t4 = new TNodeI(1),
                * t5 = new TNodeI(2), * t6 = new TNodeI(7), * t7 = new TNodeI(3);
            t1->l = t2;
            t1->r = t3;
            t2->l = t4;
            t2->r = t5;
            t3->r = t6;
            t4->r = t7;

            std::string triSerialize1Str = TriSerialize1(t1);
            std::cout << "Serialize Tree 1: \n";
            std::cout << triSerialize1Str << std::endl;
        }
        void TriSerialize2D()
        {
            /* Constructed binary tree is
                       5
                      / \
                     0    6
                    / \    \
                   1   2    7
                    \
                     3
              */

            TNodeI* t1 = new TNodeI(5), * t2 = new TNodeI(0), * t3 = new TNodeI(6), * t4 = new TNodeI(1),
                * t5 = new TNodeI(2), * t6 = new TNodeI(7), * t7 = new TNodeI(3);
            t1->l = t2;
            t1->r = t3;
            t2->l = t4;
            t2->r = t5;
            t3->r = t6;
            t4->r = t7;

            std::string triSerialize2Str = TriSerialize2(t1);
            std::cout << "Serialize Tree 2: \n";
            std::cout << triSerialize2Str << std::endl;
        }
        void TriDeSerialize1D()
        {
            /* Constructed binary tree is
                       5
                      / \
                     0    6
                    / \    \
                   1   2    7
                    \
                     3
              */

            std::string triDeSerialize1Str;
            TNodeI* racine = TriDeSerialize1(triDeSerialize1Str);
            std::cout << "DeSerialize Tree 1: \n";
            std::cout << "Level Order: \n";

            std::vector<int> levelorderData;

            Levelorder1(racine, levelorderData);

            std::cout << "Tree level order trasveral using queue\n";
            for (auto& dd : levelorderData)
            {
                std::cout << dd << ", ";
            }
            std::cout << std::endl;

        }
        void TriDeSerialize2D()
        {
            /* Constructed binary tree is
                       5
                      / \
                     0    6
                    / \    \
                   1   2    7
                    \
                     3
              */

            std::string triDeSerialize2Str;
            TNodeI* racine = TriDeSerialize1(triDeSerialize2Str);
            std::cout << "DeSerialize Tree 2: \n";
            std::cout << "Level Order: \n";

            std::vector<int> levelorderData;

            Levelorder1(racine, levelorderData);

            std::cout << "Tree level order trasveral using queue\n";
            for (auto& dd : levelorderData)
            {
                std::cout << dd << ", ";
            }
            std::cout << std::endl;
        }
        void TriZigZag1D()
        {
            /* Constructed binary tree is
                       1
                      /   \
                     5     2
                    / \   / \
                   6   7 3   4

              */

            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(2), * t3 = new TNodeI(3), * t4 = new TNodeI(4),
                * t5 = new TNodeI(5), * t6 = new TNodeI(6), * t7 = new TNodeI(7);
            t1->l = t5;
            t1->r = t2;

            t5->l = t6;
            t5->r = t7;

            t2->l = t3;
            t2->r = t4;

            std::vector<int> zigzagOrderData;
            TriZigZag1(t1, zigzagOrderData);

            std::cout << "Tree zigzag trasversal 1\n";

            for (auto& dd : zigzagOrderData)
            {
                std::cout << dd << ", ";
            }

            std::cout << std::endl;
        }
        void TriZigZag2D()
        {
            /* Constructed binary tree is
                       1
                      /   \
                     5     2
                    / \   / \
                   6   7 3   4

              */

            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(2), * t3 = new TNodeI(3), * t4 = new TNodeI(4),
                * t5 = new TNodeI(5), * t6 = new TNodeI(6), * t7 = new TNodeI(7);
            t1->l = t5;
            t1->r = t2;

            t5->l = t6;
            t5->r = t7;

            t2->l = t3;
            t2->r = t4;

            std::vector<int> zigzagOrderData;
            TriZigZag2(t1, zigzagOrderData);

            std::cout << "Tree zigzag trasversal 2\n";

            for (auto& dd : zigzagOrderData)
            {
                std::cout << dd << ", ";
            }

            std::cout << std::endl;
        }
        void TriZigZag3D()
        {
            /* Constructed binary tree is
                       1
                      /   \
                     5     2
                    / \   / \
                   6   7 3   4

              */

            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(2), * t3 = new TNodeI(3), * t4 = new TNodeI(4),
                * t5 = new TNodeI(5), * t6 = new TNodeI(6), * t7 = new TNodeI(7);
            t1->l = t5;
            t1->r = t2;

            t5->l = t6;
            t5->r = t7;

            t2->l = t3;
            t2->r = t4;

            std::vector<int> zigzagOrderData;
            TriZigZag3(t1, zigzagOrderData);

            std::cout << "Tree zigzag trasversal 3\n";

            for (auto& dd : zigzagOrderData)
            {
                std::cout << dd << ", ";
            }

            std::cout << std::endl;
        }
        void TriZigZag4D()
        {
            /* Constructed binary tree is
                       1
                      /   \
                     5     2
                    / \   / \
                   6   7 3   4

              */

            TNodeI* t1 = new TNodeI(1), * t2 = new TNodeI(2), * t3 = new TNodeI(3), * t4 = new TNodeI(4),
                * t5 = new TNodeI(5), * t6 = new TNodeI(6), * t7 = new TNodeI(7);
            t1->l = t5;
            t1->r = t2;

            t5->l = t6;
            t5->r = t7;

            t2->l = t3;
            t2->r = t4;

            std::vector<int> zigzagOrderData;
            TriZigZag4(t1, zigzagOrderData);

            std::cout << "Tree zigzag trasversal 4\n";

            for (auto& dd : zigzagOrderData)
            {
                std::cout << dd << ", ";
            }

            std::cout << std::endl;
        }
        void TriFoldable1D()
        {
            /* Constructed binary tree 1 is
                       1
                      /   \
                     4     2
                      \   / 
                       5 3   

              */            
              
              /* Constructed binary tree 2 is
                       1
                      /  \
                     2    3
                    /      \
                   4        5

              */              
              
              /* Constructed binary tree 3 is
                       1
                      /  \
                     2    3
                    / \     \
                   4   6     5

              */

            TNodeI* t11 = new TNodeI(1), * t21 = new TNodeI(1), * t31 = new TNodeI(1);
            TNodeI* t12 = new TNodeI(2), * t22 = new TNodeI(2), * t32 = new TNodeI(2);
            TNodeI* t13 = new TNodeI(3), * t23 = new TNodeI(3), * t33 = new TNodeI(3);
            TNodeI* t14 = new TNodeI(4), * t24 = new TNodeI(4), * t34 = new TNodeI(4);
            TNodeI* t15 = new TNodeI(5), * t25 = new TNodeI(5), * t35 = new TNodeI(5);
            TNodeI* t16 = new TNodeI(6), * t26 = new TNodeI(6), * t36 = new TNodeI(6);
            
            //Tree 1, foldable
            t11->l = t14;
            t11->r = t12;
            t14->r = t15;
            t12->l = t13;
            //Tree 2, foldable
            t21->l = t22;
            t22->l = t24;            
            
            t21->r = t23;
            t23->r = t25;

            //Tree 3, not foldable
            t31->l = t32;
            t32->l = t34;
            t32->r = t36;

            t31->r = t33;
            t33->r = t35;
            std::cout << " Tree Foldable 1\n";
            std::cout << " Tree 1: \n";

            if (TriFoldable1(t11))
            {
                std::cout << " Yes\n";
            }
            else
            {
                std::cout << " No\n";
            }

            std::cout << " Tree 2: \n";
            if (TriFoldable1(t21))
            {
                std::cout << " Yes\n";
            }
            else
            {
                std::cout << " No\n";
            }            
            
            std::cout << " Tree 3: \n";
            if (TriFoldable1(t31))
            {
                std::cout << " Yes\n";
            }
            else
            {
                std::cout << " No\n";
            }




        }
        void TriFoldable2D()
        {
            /* Constructed binary tree 1 is
                        1
                       /   \
                      4     2
                       \   /
                        5 3

               */

               /* Constructed binary tree 2 is
                        1
                       /  \
                      2    3
                     /      \
                    4        5

               */

               /* Constructed binary tree 3 is
                        1
                       /  \
                      2    3
                     / \     \
                    4   6     5

               */

            TNodeI* t11 = new TNodeI(1), * t21 = new TNodeI(1), * t31 = new TNodeI(1);
            TNodeI* t12 = new TNodeI(2), * t22 = new TNodeI(2), * t32 = new TNodeI(2);
            TNodeI* t13 = new TNodeI(3), * t23 = new TNodeI(3), * t33 = new TNodeI(3);
            TNodeI* t14 = new TNodeI(4), * t24 = new TNodeI(4), * t34 = new TNodeI(4);
            TNodeI* t15 = new TNodeI(5), * t25 = new TNodeI(5), * t35 = new TNodeI(5);
            TNodeI* t16 = new TNodeI(6), * t26 = new TNodeI(6), * t36 = new TNodeI(6);

            //Tree 1, foldable
            t11->l = t14;
            t11->r = t12;
            t14->r = t15;
            t12->l = t13;
            //Tree 2, foldable
            t21->l = t22;
            t22->l = t24;

            t21->r = t23;
            t23->r = t25;

            //Tree 3, not foldable
            t31->l = t32;
            t32->l = t34;
            t32->r = t36;

            t31->r = t33;
            t33->r = t35;
            std::cout << " Tree Foldable 2\n";
            std::cout << " Tree 1: \n";

            if (TriFoldable2(t11))
            {
                std::cout << " Yes\n";
            }
            else
            {
                std::cout << " No\n";
            }

            std::cout << " Tree 2: \n";
            if (TriFoldable2(t21))
            {
                std::cout << " Yes\n";
            }
            else
            {
                std::cout << " No\n";
            }

            std::cout << " Tree 3: \n";
            if (TriFoldable2(t31))
            {
                std::cout << " Yes\n";
            }
            else
            {
                std::cout << " No\n";
            }
        }
        void TriIsomorphic1D()
        {
            /* Constructed binary tree 1 is
                       1
                      /   \
                     2      3
                    / \    /
                   4   5  6
                      / \
                     7   8

              */            
              
              /* Constructed binary tree 2 is
                       1
                      /   \
                     3     2
                      \   / \
                       6 4   5
                            /  \
                           8    7

              */
            TNodeI* t11 = new TNodeI(1), * t21 = new TNodeI(1);
            TNodeI* t12 = new TNodeI(2), * t22 = new TNodeI(2);
            TNodeI* t13 = new TNodeI(3), * t23 = new TNodeI(3);
            TNodeI* t14 = new TNodeI(4), * t24 = new TNodeI(4);
            TNodeI* t15 = new TNodeI(5), * t25 = new TNodeI(5);
            TNodeI* t16 = new TNodeI(6), * t26 = new TNodeI(6);
            TNodeI* t17 = new TNodeI(7), * t27 = new TNodeI(7);
            TNodeI* t18 = new TNodeI(8), * t28 = new TNodeI(8);

            //tree 1
            t11->l = t12;
            t11->r = t13;

            t12->l = t14;
            t12->r = t15;

            t13->l = t16;

            t15->l = t17;
            t15->r = t18;

            //tree 2
            t21->l = t23;
            t21->r = t22;

       
            t23->r = t26;

            t22->l = t24;
            t22->r = t25;

            t25->l = t28;
            t25->r = t27;

            std::cout << "TriIsomorphic 1\n";
            if (TriIsomorphic1(t11, t21))
            {
                std::cout << " Yes\n";
            }
            else
            {
                std::cout << " No\n";
            }

        }
        void TriIsomorphic2D()
        {
            /* Constructed binary tree 1 is
                       1
                      /   \
                     2      3
                    / \    /
                   4   5  6
                      / \
                     7   8

              */

              /* Constructed binary tree 2 is
                       1
                      /   \
                     3     2
                      \   / \
                       6 4   5
                            /  \
                           8    7

              */
            TNodeI* t11 = new TNodeI(1), * t21 = new TNodeI(1);
            TNodeI* t12 = new TNodeI(2), * t22 = new TNodeI(2);
            TNodeI* t13 = new TNodeI(3), * t23 = new TNodeI(3);
            TNodeI* t14 = new TNodeI(4), * t24 = new TNodeI(4);
            TNodeI* t15 = new TNodeI(5), * t25 = new TNodeI(5);
            TNodeI* t16 = new TNodeI(6), * t26 = new TNodeI(6);
            TNodeI* t17 = new TNodeI(7), * t27 = new TNodeI(7);
            TNodeI* t18 = new TNodeI(8), * t28 = new TNodeI(8);

            //tree 1
            t11->l = t12;
            t11->r = t13;

            t12->l = t14;
            t12->r = t15;

            t13->l = t16;

            t15->l = t17;
            t15->r = t18;

            //tree 2
            t21->l = t23;
            t21->r = t22;


            t23->r = t26;

            t22->l = t24;
            t22->r = t25;

            t25->l = t28;
            t25->r = t27;

            std::cout << "TriIsomorphic 2\n";
            if (TriIsomorphic2(t11, t21))
            {
                std::cout << " Yes\n";
            }
            else
            {
                std::cout << " No\n";
            }
        }
        void TriBSsortedArrayToBST1D()
        {

            /* Sorted array is
             
            1, 2, 4, 5, 6, 7, 8, 9

            */
            /* Constructed binary search tree is
                   5
                  /  \
                 2     7
                / \   / \
               1   4  6  8
                          \
                           9

            */

            //std::vector<int> arr = { 2,9,6,5,7,1,8,4 };
            std::vector<int> arr = { 1, 2, 4, 5, 6, 7, 8, 9};

            //std::sort(arr.begin(), arr.end());

            //Creating a balanced binary tree and inserting elements
            //BinSearchT* root = sortedArrayToBST1(arr, 0, arr.size() - 1);
            std::cout << "Sorted array to binary search tree 1" << std::endl;
            std::cout << "Sorted Array" << std::endl;
            for (auto el : arr)
            {
                std::cout << el << ", ";
            }
            std::cout << std::endl;
            BinSearchT * racine = sortedArrayToBST1(arr, 0, arr.size() - 1);
            //BinSearchT * racine = sortedArrayToBST2(arr);
            std::cout << "Preorder of tree from Sorted Array" << std::endl;
            std::vector<int> preOrdervalues;
            preorder(racine, preOrdervalues);
            std::cout << "Preorder Tree:" << std::endl;
            for (auto el : preOrdervalues)
            {
                std::cout << el << ", ";
            }
            std::cout << std::endl;

          
        }        
        void TriBSsortedArrayToBST2D()
        {

            /* Sorted array is
             
            1, 2, 4, 5, 6, 7, 8, 9

            */
            /* Constructed binary search tree is
                   5
                  /  \
                 2     7
                / \   / \
               1   4  6  8
                          \
                           9

            */

            //std::vector<int> arr = { 2,9,6,5,7,1,8,4 };
            std::vector<int> arr = { 1, 2, 4, 5, 6, 7, 8, 9};

            //std::sort(arr.begin(), arr.end());

            //Creating a balanced binary tree and inserting elements
            //BinSearchT* root = sortedArrayToBST1(arr, 0, arr.size() - 1);
            std::cout << "Sorted array to binary search tree 2"  << std::endl;
            std::cout << "Sorted Array" << std::endl;
            for (auto el : arr)
            {
                std::cout << el << ", ";
            }
            std::cout << std::endl;
            BinSearchT * racine = sortedArrayToBST2(arr);
            std::cout << "Preorder of tree from Sorted Array" << std::endl;
            std::vector<int> preOrdervalues;
            preorder(racine, preOrdervalues);
            std::cout << "Preorder Tree:" << std::endl;
            for (auto el : preOrdervalues)
            {
                std::cout << el << ", ";
            }
            std::cout << std::endl;

          
        }
        void TriBSMinSwapsD()
        {

            /* Constructed  tree is
                   1
                  /  \
                 2     3
                / \    
               4   5    
            */
            BinSearchT* t1 = new BinSearchT(1);
            BinSearchT* t2 = new BinSearchT(2);
            BinSearchT* t3 = new BinSearchT(3);
            BinSearchT* t4 = new BinSearchT(4);
            BinSearchT* t5 = new BinSearchT(5);

            t1->l = t2;
            t1->r = t3;

            t2->l = t4;
            t2->r = t5;

            int minSwap = minSwaps(t1);

            std::cout << "Minimum swap to convert binary tree to binary search tree:\n";
            std::cout << minSwap << std::endl;

        }
        void TriBSMinValueD()
        {

            /* Constructed  tree is
                   ------------------8-------------------
                   |                                    |
             ----- 3-----                 --------------10--------------
             |          |                 |                            |
             1      ----6----             9                      -----13-----
                    |        |                                   |           |
                    4----    7                                   11----      14
                        |                                             |
                        5                                             12

            */
            BinSearchT* t1 = new BinSearchT(1);
            BinSearchT* t3 = new BinSearchT(3);
            BinSearchT* t4 = new BinSearchT(4);
            BinSearchT* t5 = new BinSearchT(5);
            BinSearchT* t6 = new BinSearchT(6);
            BinSearchT* t7 = new BinSearchT(7);
            BinSearchT* t8 = new BinSearchT(8);
            BinSearchT* t9 = new BinSearchT(9);
            BinSearchT* t10 = new BinSearchT(10);
            BinSearchT* t11 = new BinSearchT(11);
            BinSearchT* t12 = new BinSearchT(12);
            BinSearchT* t13 = new BinSearchT(13);
            BinSearchT* t14 = new BinSearchT(14);

            t8->l = t3;
            t8->r = t10;
            
            t3->l = t1;
            t3->r = t6;    

            t10->l = t9;
            t10->r = t13;

            t6->l = t4;
            t6->r = t7;

            t13->l = t11;
            t13->r = t14;
                        

            t4->r = t5;

            t11->r = t12;

            int minVal = minValue(t8);

            std::cout << "Minimum of a  binary search tree:\n";
            std::cout << minVal << std::endl;
        }        
        void TriBSMaxValueD()
        {

            /* Constructed  tree is
                   ------------------8-------------------
                   |                                    |
             ----- 3-----                 --------------10--------------
             |          |                 |                            |
             1      ----6----             9                      -----13-----
                    |        |                                   |           |
                    4----    7                                   11----      14
                        |                                             |
                        5                                             12

            */
            BinSearchT* t1 = new BinSearchT(1);
            BinSearchT* t3 = new BinSearchT(3);
            BinSearchT* t4 = new BinSearchT(4);
            BinSearchT* t5 = new BinSearchT(5);
            BinSearchT* t6 = new BinSearchT(6);
            BinSearchT* t7 = new BinSearchT(7);
            BinSearchT* t8 = new BinSearchT(8);
            BinSearchT* t9 = new BinSearchT(9);
            BinSearchT* t10 = new BinSearchT(10);
            BinSearchT* t11 = new BinSearchT(11);
            BinSearchT* t12 = new BinSearchT(12);
            BinSearchT* t13 = new BinSearchT(13);
            BinSearchT* t14 = new BinSearchT(14);

            t8->l = t3;
            t8->r = t10;
            
            t3->l = t1;
            t3->r = t6;    

            t10->l = t9;
            t10->r = t13;

            t6->l = t4;
            t6->r = t7;

            t13->l = t11;
            t13->r = t14;
                        

            t4->r = t5;

            t11->r = t12;

            int maxVal = maxValue(t8);

            std::cout << "Maximum of a  binary search tree:\n";
            std::cout << maxVal << std::endl;
        }
        void TriBSBuildBalancedBinaryTreeD()
        {
            /* Constructed  unbalanced tree is
                   1
                    \
                     2
                      \
                       3
                        \
                         4
                          \
                           5
      
            */            
            
            /* Constructed  balanced tree is

                       3
                     /  \
                    2    4
                   /      \
                  1         5
      
            */
            BinSearchT* t1 = new BinSearchT(1);
            BinSearchT* t2 = new BinSearchT(2);
            BinSearchT* t3 = new BinSearchT(3);
            BinSearchT* t4 = new BinSearchT(4);
            BinSearchT* t5 = new BinSearchT(5);

            t1->r = t2;
            t2->r = t3;
            t3->r = t4;
            t4->r = t5;

            std::cout << "Convert Binary Search Tree into Balanced Binary Search Tree\n";

            BinSearchT* balancedTriRacine = buildBalancedBinaryTree(t1);
            std::cout << "Pre order Traversal of tree" << std::endl;
            std::vector<int> preOrderData; 
            preorder(balancedTriRacine, preOrderData);

            for (auto nod : preOrderData)
            {
                std::cout << nod << ", ";
            }

            std::cout << std::endl;

        }
        void TriBSFindKthMinimumElementD()
        {
           
            
            /* Constructed  tree is

                      6
                     /  \
                    4    8
                   / \     \
                  3   5     9
      
            */
            BinSearchT* t3 = new BinSearchT(3);
            BinSearchT* t4 = new BinSearchT(4);
            BinSearchT* t5 = new BinSearchT(5);
            BinSearchT* t6 = new BinSearchT(6);
            BinSearchT* t8 = new BinSearchT(8);
            BinSearchT* t9 = new BinSearchT(9);

            t6->l = t4;
            t6->r = t8;
            t4->l = t3;
            t4->r = t5;

            std::cout << "Find k-th smallest element in Binary Search Tree\n";
            int k = 3;
            int minElem = findKthMinimumElement(t6, k);
            std::cout << "Minimum" << std::endl;
            std::cout << minElem << std::endl;

            std::cout << std::endl;
        }
        void TriBSKsmallestElementSumD()
        {


            /* Constructed  tree is

                      54
                     /  \
                    51   75
                   / \     \
                  49        85

            */
            BinSearchT* t49 = new BinSearchT(49);
            BinSearchT* t51 = new BinSearchT(51);
            BinSearchT* t52 = new BinSearchT(52);
            BinSearchT* t54 = new BinSearchT(54);
            BinSearchT* t74 = new BinSearchT(74);
            BinSearchT* t75 = new BinSearchT(75);
            BinSearchT* t85 = new BinSearchT(85);


            t54->l = t51;
            t54->r = t75;

            t51->l = t49;
            t51->r = t52;

            t75->l = t74;
            t75->r = t85;

            std::cout << "Sum of k smallest elements in Binary Search Tree\n";
            int  k = 3;
            int minSum = ksmallestElementSum(t54, k);
            std::cout << "Sum" << std::endl;

            std::cout << minSum << std::endl;

            std::cout << std::endl;
        }
    }
}
