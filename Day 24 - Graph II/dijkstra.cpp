#include <bits/stdc++.h> 

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
   // Create an adjacency list to represent the weighted graph.
   unordered_map<int, list<pair<int, int>>> adj;
   for (int i = 0; i < vec.size(); i++) {
       int u = vec[i][0]; // Source node of the edge.
       int v = vec[i][1]; // Destination node of the edge.
       int w = vec[i][2]; // Weight of the edge.
       adj[u].push_back(make_pair(v, w)); // Add the edge to the adjacency list.
       adj[v].push_back(make_pair(u, w)); // Since it is an undirected graph, add the reverse edge as well.
   }

   // Initialize the distances from the source node to all other nodes as infinity.
   vector<int> dist(vertices, INT_MAX);
   dist[source] = 0; // Distance from the source node to itself is 0.

   // Create a set to store nodes and their distances, sorted by distance.
   set<pair<int, int>> st;
   st.insert(make_pair(0, source)); // Insert the source node with distance 0.

   // Perform Dijkstra's algorithm.
   while (!st.empty()) {
       auto top = *(st.begin()); // Get the node with the minimum distance from the set.
       int curr = top.second; // Current node.
       int currDist = top.first; // Current distance from the source node.
       st.erase(top); // Remove the current node from the set.

       // Explore the neighbors of the current node.
       for (auto i : adj[curr]) {
           // Update the distance if a shorter path is found.
           if (dist[i.first] > currDist + i.second) {
               // Find and erase the previous distance of the neighbor node from the set.
               auto record = st.find(make_pair(dist[i.first], i.first));
               if (record != st.end()) {
                   st.erase(record);
               }
               // Update the distance of the neighbor node and insert it into the set.
               dist[i.first] = currDist + i.second;
               st.insert(make_pair(dist[i.first], i.first));
           }
       }
   }
   return dist; // Return the vector containing the shortest distances from the source node to all other nodes.
}
