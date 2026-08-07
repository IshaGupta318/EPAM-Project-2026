#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int N;
    long long K;

    cin >> N >> K;

    // Security keys
    vector<long long> key(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> key[i];
    }

    // Adjacency list
    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int trusted = 0;

    // stack contains:
    // node, parent, XOR from root to node
    stack<pair<int, pair<int, long long>>> st;

    // Start from root Server 1
    st.push({1, {0, key[1]}});

    while (!st.empty()) {
        auto current = st.top();
        st.pop();

        int node = current.first;
        int parent = current.second.first;
        long long currentXor = current.second.second;

        // Check whether current server is trusted
        if (currentXor >= K) {
            trusted++;
        }

        // Visit children
        for (int child : graph[node]) {
            if (child == parent)
                continue;

            long long childXor = currentXor ^ key[child];

            st.push({child, {node, childXor}});
        }
    }

    cout << trusted << endl;

    return 0;
}