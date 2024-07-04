#include "graph.h"

Name_Index::Name_Index(int N)
{
    std::string name;
    std::getline(std::cin, name);
    for (int i = 0; i < N; i++)
    {
        std::getline(std::cin, name);
        index_to_name.push_back(name);
        name_to_index[name] = i;
    }
}

std::string Name_Index::get_name(const int i)
{
    assert(i < index_to_name.size() && i >= 0);
    return index_to_name[i];
}

int Name_Index::get_index(const std::string& name)
{

    if (name_to_index.count(name))
        return name_to_index[name];
    
    throw std::runtime_error("Wrong name");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

Graph::Graph() = default;

Graph::Graph(int N)
{
    g.resize(N);
    int m;
    PlaySound(TEXT("third.wav"), NULL, SND_ASYNC);
    std::cout << "Enter the number of edges: ";
    std::cin >> m;
    PlaySound(TEXT("fourth.wav"), NULL, SND_ASYNC);
    std::cout << "Enter the edges: ";
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }
    std::cout << std::endl;
}

int Graph::size() const
{
    return g.size();
}

std::vector<int> Graph :: operator[](int i) const
{
    return g[i];
}
std::vector<int> Graph::operator[](int i)
{
    return g[i];
}

ReverseGraph::ReverseGraph() = default;

ReverseGraph::ReverseGraph(const Graph& grp)
{
    g.resize(grp.size());
    for (int i = 0; i < grp.size(); ++i)
        for (int j = 0; j < grp[i].size(); ++j)
            g[grp[i][j]].push_back(i);

}

