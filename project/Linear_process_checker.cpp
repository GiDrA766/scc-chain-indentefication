#include "Linear_process_checker.h"

constexpr int NOT_VISITED = 0;
constexpr int VISITED = 1;
LinearProcessChecker::LinearProcessChecker() = default;

LinearProcessChecker::LinearProcessChecker(const Kosaraju& k)
{
    final_graph = k.get_final_graph();
}

void LinearProcessChecker::Kahn()
{
    auto graph = final_graph;
    std::map<int, int> indegree;
    for (const auto& it : graph)
    {
        indegree[it.first];
        for (auto jt : it.second)
        {
            ++indegree[jt];
        }
    }

    bool linear = true;

    std::queue<int> q;
    for (const auto& it : graph)
        if (indegree[it.first] == 0)
             q.push(it.first);
   
    while (!q.empty())
    {
        if (q.size() > 1) 
        {
            linear = false;
            break;
        }

        int node = q.front();
        q.pop();
        result.push_back(node);
        for (auto it : graph[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
            
        }
    }

    if (linear)
    {
        std::cout << "The process is linear" << std::endl;
        print();
    }
    else
        std::cout << "The process is not linear" << std::endl;

}

void LinearProcessChecker::print()
{
    for (int i : result)
        std::cout << i + 1 << " ";
}
