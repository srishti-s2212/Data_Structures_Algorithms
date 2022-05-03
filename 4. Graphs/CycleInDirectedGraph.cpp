#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph
{
public:
    bool DFSRec(vector<int> adj[], vector<bool> visited, vector<bool> disVisited, int node)
    {
        visited[node] = true;
        disVisited[node] = true;

        for (auto it : adj[node])
        {
            if (visited[it] == false)
            {
                if (DFSRec(adj, visited, disVisited, it))
                    return true;
            }
            else if (disVisited[it] == true)
                return true;
        }
        disVisited[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        // bool visited[V];
        // bool disVisited[V];
        // for(int i=0;i<V;i++)
        // {
        //          visited[i]=false;
        //          disVisited[i]=false;
        // }
        vector<bool> visited(V, false);
        vector<bool> disVisited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                if (DFSRec(adj, visited, disVisited, i))
                    return true;
            }
        }
        return false;
    }
};