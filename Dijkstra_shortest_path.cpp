#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to perform Dijkstra's algorithm to find the shortest distances from the source node.
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // Create an adjacency list representation of the graph.
    vector<pair<int, int>> adj[vertices];
    
    // Fill the adjacency list.
    for (int i = 0; i < edges; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];
        
        // Undirected graph, so we add edges in both directions.
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Initialize an array to store the shortest distances from the source to each node.
    vector<int> dis(vertices, INT_MAX);

    // Priority queue to select the node with the minimum distance.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize the priority queue with the source node and distance 0.
    pq.push({0, source});
    dis[source] = 0;

    // Dijkstra's algorithm
    while (!pq.empty()) {
        int currDis = pq.top().first;   // Current distance
        int currNode = pq.top().second; // Current node
        pq.pop();

        // Explore neighbors of the current node
        for (auto neigh : adj[currNode]) {
            int neighNode = neigh.first;  // Neighbor node
            int neighDis = neigh.second;  // Distance to the neighbor

            // If a shorter path is found to the neighbor, update the distance and push it to the queue.
            if (currDis + neighDis < dis[neighNode]) {
                dis[neighNode] = currDis + neighDis;
                pq.push({dis[neighNode], neighNode});
            }
        }
    }

    // Return the array of shortest distances from the source node to all other nodes.
    return dis;
}

int main() {
    int vertices, edges, source;
    
    // Read the number of vertices, edges, and source node.
    cin >> vertices >> edges >> source;
    
    // Initialize the 'edge' vector with 'edges' number of {u, v, distance} vectors.
    vector<vector<int>> edge(edges, vector<int>(3));
    
    // Read edge information.
    for (int i = 0; i < edges; i++) {
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
    }

    // Call Dijkstra's algorithm to compute the shortest distances.
    vector<int> shortestDistances = dijkstra(edge, vertices, edges, source);

    // Print the shortest distances from the source node to all other nodes.
    for (int i = 0; i < vertices; i++) {
        cout << "Shortest distance from source to node " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
