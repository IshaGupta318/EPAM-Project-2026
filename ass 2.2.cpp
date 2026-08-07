#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int N, M, D;
    cin >> N >> M >> D;

    // Adjacency list
    vector<vector<int>> graph(N + 1);

    // Read roads
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Distance array
    vector<int> dist(N + 1, -1);

    // BFS queue
    queue<int> q;

    // Start from City 1
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {

        int current = q.front();
        q.pop();

        for (int next : graph[current]) {

            // If city is not visited
            if (dist[next] == -1) {

                dist[next] = dist[current] + 1;

                q.push(next);
            }
        }
    }

    // Count efficiently reachable cities
    int count = 0;

    for (int i = 1; i <= N; i++) {

        if (dist[i] <= D) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}