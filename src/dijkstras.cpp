#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    vector<int> distances;
    distances.resize(G.numVertices, INF);
    // distances[source] = 0;
    priority_queue<Vertex> pq;

    for (auto edge : G[source]) {
        if (distances[edge.dst]> edge.weight) {
            distances[edge.dst] = edge.weight;
            pq.push(Vertex(edge.dst, distances[edge.dst]));
            }
    }
    previous[pq.top().vertex] = source;
    // distances[source] = 0;
    return distances;


    // size_t graph_size = G.size();
    // vector<int> distances, vertices;
    // vector<bool> visited;

    // vertices.push_back(source);
    // distances.resize(graph_size, INF);
    // previous.resize(graph_size, -1);
    // visited.resize(graph_size, false);

    // priority_queue pq;
    // pq.push(Vertex(source,0));
    // distances[source] = 0;
    // Vertex current;
    // int vertex, destination, weight;
    // while (!pq.empty()) {
    //     current = pq.top();
    //     pq.pop();
    //     vertex = current.vertex;
    //     if (visited[vertex] == false) {
    //         visited[vertex] = true;
            
    //         for(auto edge: G) {
    //             destination = edge.dst;
    //             weight = edge.weight;

    //             if (!visited[destination] && (distances[vertex]+weight < distances[destination])) {
    //                 distances[destination] = distances[vertex] + weight;
    //                 previous[destination] = vertex;
    //                 pq.push(Vertex(destination, distances[destination]));
    //                 vertices.push_back(destination);
    //             }
    //         }
    //     }
    // }

}
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> short_path;
    if (distances.size() == 0) return short_path;
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