#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    unordered_map<int, list<int>> addEdge(int u, int v, int direction = 0)
    {
        // 0: undirected
        // directed
        adj[u].push_back(v);
        if (direction == 0)
            adj[v].push_back(u);
        return adj;
    }

    void printAdjList()
    {
        for (auto it : adj)
        {
            cout << it.first << "->";
            for (auto i : it.second)
                cout << i << ",";
            cout << endl;
        }
    }

    bool isCycle(vector<int> adj[], int V)
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                if (DFSRec(adj, visited, i, -1))
                    return true;
            }
        }
        return false;
    }
    bool DFSRec(vector<int> adj[], vector<bool> visited, int node, int parent)
    {
        visited[node] = true;
        for (auto it : adj[node])
        {
            if (visited[it] == false)
            {
                if (DFSRec(adj, visited, it, node))
                    return true;
            }
            else if (it != parent)
                return true;
        }
        return false;
    }
};

int main()
{
    Graph g;
    unordered_map<int, list<int>> adj;
    adj = g.addEdge(1, 0);
    adj = g.addEdge(0, 2);
    adj = g.addEdge(2, 1);
    adj = g.addEdge(0, 3);
    adj = g.addEdge(3, 4);
}
