#ifndef PROJECT__LINEAR_PROCESS_CHECKER_H
#define PROJECT__LINEAR_PROCESS_CHECKER_H

#include "Kosaraju_Dfs.h"
#include <queue>
#include <map>

class LinearProcessChecker
{
    std::map<int, std::set<int>> final_graph;
    std::vector<int> result;
public:
    LinearProcessChecker();
    explicit LinearProcessChecker(const Kosaraju& k);
    void Kahn();
    void print();
};

#endif //PROJECT__LINEAR_PROCESS_CHECKER_H
