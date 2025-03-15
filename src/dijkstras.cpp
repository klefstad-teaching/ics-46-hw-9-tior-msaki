#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int n = G.numVertices;
    vector<int> distances;
    distances.assign(n, INF);
    distances[source] = 0;
    previous.assign(n, -1); previous[source] = source;
    vector<bool> visited;
    visited.assign(n, false);
    priority_queue<Vertex> pq;
    pq.push(Vertex(source, 0));
    Vertex current;
    int u, v, weight;
    while (!pq.empty()) {
        current = pq.top();
        u = current.vertex;
        pq.pop();
        if (visited[u]) break;
        visited[u] = true;
        for (auto edge : G[u]) {
            v = edge.dst;
            weight = edge.weight;

            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push(Vertex(v, distances[v]));
            }
        }
    }
    return distances;
    // vector<int> distances;
    // distances.resize(G.numVertices, INF);
    // distances[source] = 0; previous[source] = source;
    // int current = source;
    // // cout<< "SOURCE: " << source<< " PREVIOUS[SOURCE]: "<< previous[source] << endl;
    // for (int i = 0; i<G.numVertices; i++){
    //     priority_queue<Vertex> pq;
    //     for (auto edge : G[current]) {
    //         if (distances[edge.dst]> edge.weight) {
    //             distances[edge.dst] = edge.weight;
    //             pq.push(Vertex(edge.dst, distances[edge.dst]));
    //             }
    //     }
    //     if (pq.empty()){
    //         return distances;
    //     }
    //     previous[pq.top().vertex] = current;
    //     current = pq.top().vertex;
    // }
    // return distances;
}
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> short_path;
    if (distances.size() == 0 || previous.size() == 0) return short_path;
    short_path.push_back(destination);
    while (short_path.size()<previous.size()) {
        short_path.push_back(previous[short_path.back()]);
    }
    return short_path;
}
void print_path(const vector<int>& v, int total){
    for (auto vertex : v) cout << vertex << ' ';
    cout << "\nTotal cost is " << total << endl;
}