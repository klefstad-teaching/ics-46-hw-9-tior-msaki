#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    vector<int> distances;
    distances.resize(G.numVertices, INF);
    distances[source] = 0;
    int current = source;
    cout<< "SOURCE: " << source<< " PREVIOUS[SOURCE]: "<< previous[source] << endl;
    priority_queue<Vertex> pq;
    for (auto edge : G[current]) {
        if (distances[edge.dst]> edge.weight) {
            distances[edge.dst] = edge.weight;
            pq.push(Vertex(edge.dst, distances[edge.dst]));
            }
    }
    previous[pq.top().vertex] = current;

    return distances;
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