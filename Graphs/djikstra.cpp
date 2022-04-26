#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// class Solution
// {
//     public:

//     //vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
//     vector <int> dijkstra(int V, int adj[9][9], int S)
//     {
//         //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//         priority_queue<
//             pair<int,int>,
//             vector<pair<int,int>>,
//             greater<pair<int,int>>
//             >pq;
//         vector<int> dist(V, INT_MAX);
//         dist[S]=0;

//         //pq stores dist, node
//         pq.push(make_pair(0,S));
//         while(pq.empty() == false)
//         {
//             int Nodedist = pq.top().first;
//             int Nodeprev = pq.top().second;
//             pq.pop();
//             for(auto it: adj[Nodeprev])
//             {
//                 int nextNode = it[0];
//                 int nextdist = it[1];
//                 if(nextdist + dist[Nodeprev] < dist[nextNode])
//                 {
//                     dist[nextNode]=nextdist + dist[Nodeprev];
//                     pq.push(make_pair(dist[nextNode], nextNode));
//                 }
//             }
//         }
//         return dist;
//     }
// };

// int main()
// {
//     /* Let us create the example graph discussed above */
//     vector<vector<int>> graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
//                         { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
//                         { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
//                         { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
//                         { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
//                         { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
//                         { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
//                         { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
//                         { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

//     Solution obj;
//     obj.dijkstra(9, graph, 0);

//     return 0;
// }

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

#define V 9

int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];

    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}
