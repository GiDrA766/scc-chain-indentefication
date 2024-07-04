#ifndef PROJECT__GRAPH_HEADER_H
#define PROJECT__GRAPH_HEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <set>
#include <Windows.h>
#include "MMSystem.h"
#pragma (lib, "winmm.lib")

class Name_Index
{
    std::vector<std::string> index_to_name;
    std::map<std::string, int> name_to_index;
public:
    explicit Name_Index(int N);
    std::string get_name(int i);
    int  get_index(const std::string& name);
};

class Graph
{
protected:
    std::vector<std::vector<int>> g;
public:
    Graph();
    explicit Graph(int N);
    int size() const;
    std::vector<int> operator[](int i) const;
    std::vector<int> operator[](int i);
};

class ReverseGraph : public Graph
{
public:
    ReverseGraph();
    explicit ReverseGraph(const Graph& grp);
};


#endif //PROJECT__GRAPH_HEADER_H
