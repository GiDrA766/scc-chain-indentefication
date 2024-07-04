#ifndef PROJECT__KOSARAJU_DFS_H
#define PROJECT__KOSARAJU_DFS_H

#include "graph.h"
#include <stack>

class DFS
{
public:
    std::stack<int> topological_sort(const Graph& graph);
    void dfs(const Graph& graph, std::stack<int>& st, std::vector<char>& visited, int start);
};

class Kosaraju
{
    std::stack<int> sorted;
    DFS dfs;
    Graph gph;
    std::vector<int> leaders;
    std::map<int, std::set<int>> final_graph;
public:
    Kosaraju(const Graph& graph);
    std::map<int, std::set<int>> get_final_graph() const;
    void strongly_connected_components(const ReverseGraph& graph);
    void dfs_SCC(int i, const ReverseGraph& graph, std::vector<char>& visited, int leader); //poxel _dfs anuny
    void components_graph();
    void print_leaders(Name_Index& names);
    void print_rest();
};



#endif //PROJECT__KOSARAJU_DFS_H
