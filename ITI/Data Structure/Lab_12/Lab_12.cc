#include <iostream>
#include <vector>
#include <queue>
class graph
{
private:
    std::vector<std::vector<int>> v;
    std::vector<bool> visited;
    int start;

public:
    graph(std::vector<std::vector<int>> vect) : v{vect}
    {
        if (v.size() != 0)
        {
            start = 0;
        }
        else
        {
            start = -1;
        }
        visited.resize(v.size(), false);
    }
    std::vector<int> BFS_Traverse()
    {
        std::queue<int> q;
        std::vector<int> BFS;
        if (start == -1)
        {
            return BFS;
        }
        visited[start] = true;
        q.push(start);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            BFS.push_back(u + 1);
            for (int i = 0; i < v[u].size(); i++)
            {
                if (v[u][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        return BFS;
    }
    void DFS_Traverse(int current)
{
    visited[current] = 1;
    std::cout << current + 1 << " ";
    for (int next = 0; next < v.size(); next++)
    {
        if (v[current][next] == 1 && !visited[next])
        {
            DFS_Traverse(next);
        }
    }
}
};
int main(void)
{
    std::vector<std::vector<int>> vect{
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    graph g(vect);
    // std::vector<int> bfs = g.BFS_Traverse();
    // for (int i : bfs)
    // {
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl;
    g.DFS_Traverse(0);
}