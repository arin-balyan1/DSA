#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int x[1002];

int dp[1002][1002];

int N_POINTS;

int rec(int l, int r) {
    if (l + 1 == r) {
        return 0;
    }

    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    int min_cost = 2e9;

    for (int i = l + 1; i < r; i++) {
        min_cost = std::min(min_cost, (x[r] - x[l]) + rec(l, i) + rec(i, r));
    }

    return dp[l][r] = min_cost;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L;
    int num_internal_cuts;

    std::cin >> L >> num_internal_cuts;

    std::vector<int> cuts_positions;
    cuts_positions.push_back(0);

    for (int i = 0; i < num_internal_cuts; i++) {
        int cut_pos;
        std::cin >> cut_pos;
        cuts_positions.push_back(cut_pos);
    }
    cuts_positions.push_back(L);

    std::sort(cuts_positions.begin(), cuts_positions.end());

    for (int i = 0; i < cuts_positions.size(); ++i) {
        x[i] = cuts_positions[i];
    }
    N_POINTS = cuts_positions.size();

    memset(dp, -1, sizeof(dp));

    std::cout << rec(0, N_POINTS - 1) << std::endl;

    return 0;
}