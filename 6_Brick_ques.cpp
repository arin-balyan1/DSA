#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// n = length of array
// m = number of colours
// k = exact number of colour changes

int n, m, k;

// DP: dp[level][changes_left]
vector<vector<int>> dp;

// Recurrence: solve(level, changes_left)
int solve(int level, int changes_left) {
    if (level == n) {
        // All positions filled
        if (changes_left == 0) return 1; // Valid sequence
        else return 0;                   // Invalid, too many changes left
    }

    if (dp[level][changes_left] != -1) return dp[level][changes_left];

    long long ans = 0;

    // Option 1: Keep same colour -> no new change
    ans += solve(level + 1, changes_left);

    // Option 2: Change colour -> (m - 1) choices
    if (changes_left > 0) {
        ans += (m - 1) * 1LL * solve(level + 1, changes_left - 1);
    }

    return dp[level][changes_left] = ans % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        cin >> n >> m >> k;

        // Initialize DP for each test case
        dp.assign(n + 1, vector<int>(k + 1, -1));

        // First position has m choices:
        long long result = (m * 1LL * solve(1, k)) % MOD;

        cout << result << '\n';
    }

    return 0;
}