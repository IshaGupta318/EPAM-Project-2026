#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<long long> points(N + 1);

    // Input learning points
    for (int i = 1; i <= N; i++) {
        cin >> points[i];
    }

    // DP array
    vector<long long> dp(N + 1, 0);

    // Base cases
    dp[0] = 0;

    if (N >= 1) {
        dp[1] = points[1];
    }

    // Fill DP table
    for (int i = 2; i <= N; i++) {

        // Option 1: Skip current topic
        long long skip = dp[i - 1];

        // Option 2: Select current topic
        long long take = dp[i - 2] + points[i];

        dp[i] = max(skip, take);
    }

    // Maximum learning points
    cout << dp[N] << endl;

    return 0;
}
