#include "Kosaraju_Dfs.h"

constexpr int NOT_VISITED = 0;
constexpr int VISITED = 1;
void DFS::dfs(const Graph& graph, std::stack<int>& st, std::vector<char>& visited, int start)
{
    visited[start] = VISITED;

    for (int i = 0; i < graph[start].size(); ++i) 
        if (visited[graph[start][i]] == NOT_VISITED)
              dfs(graph, st, visited, graph[start][i]);

    st.push(start);
}

std::stack<int> DFS::topological_sort(const Graph& graph)
{
    std::stack<int> sort;
    std::vector<char> visited(graph.size(), NOT_VISITED);
    for (int i = 0; i < visited.size(); ++i)
        if (visited[i] == NOT_VISITED)
            dfs(graph, sort, visited, i);
    return sort;
}

Kosaraju::Kosaraju(const Graph& graph)
{
    gph = graph;
    sorted = dfs.topological_sort(graph);
    strongly_connected_components(ReverseGraph(graph));
    components_graph();
}
std::map<int, std::set<int>> Kosaraju::get_final_graph() const
{
    return final_graph;
}

void Kosaraju::dfs_SCC(int i, const ReverseGraph& graph, std::vector<char>& visited, int leader)
{
    visited[i] = VISITED;
    leaders[i] = leader;

    for (int j = 0; j < graph[i].size(); ++j)
        if (visited[graph[i][j]] == NOT_VISITED)
            dfs_SCC(graph[i][j], graph, visited, leader);

}

void Kosaraju::strongly_connected_components(const ReverseGraph& graph)
{
    leaders.resize(graph.size());
    std::vector<char> visited(graph.size(), NOT_VISITED);
    int k;
    while (!sorted.empty())
    {
        k = sorted.top();
        sorted.pop();
        if (visited[k] == VISITED)
        {
            continue;
        }
        dfs_SCC(k, graph, visited, k);
        final_graph[k] = std::set<int>();
    }

}

void Kosaraju::components_graph()
{
    for (int i = 0; i < gph.size(); i++)
    {
        for (int j = 0; j < gph[i].size(); j++)
        {
            if (leaders[i] != leaders[gph[i][j]])
            {
                final_graph[leaders[i]].insert(leaders[gph[i][j]]);
                final_graph[leaders[gph[i][j]]]; //?
            }
        }
    }
}


void Kosaraju::print_leaders(Name_Index& names)
{
    std::cout << "Number of irrevocable phases: ";
    std::cout << final_graph.size() << std::endl;
    std::cout << "Irrevocable phases: \n";
    for (auto& it : final_graph)
        std::cout << it.first + 1 << ": " << names.get_name(it.first) << "  ";
    std::cout << std::endl;
}

void Kosaraju::print_rest() {
    for (auto& it : final_graph)
    {
        std::cout << "Revocables for irrevocable " << it.first + 1 << ": ";

        for (int j = 0; j < leaders.size(); j++)
            if (leaders[j] == it.first && j != it.first)
                std::cout << j + 1 << " ";

        std::cout << std::endl;
    }
    std::cout << std::endl;
}


