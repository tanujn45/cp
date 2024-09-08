#include <bits/stdc++.h>

using namespace std;

class _01Knapsack {
   private:
    int recHelp(vector<int> wt, vector<int> val, int W, int idx) {
        if (W <= 0 || idx == static_cast<int>(wt.size())) {
            return 0;
        }

        return max(val[idx] + recHelp(wt, val, W - wt[idx], idx + 1),
                   recHelp(wt, val, W, idx + 1));
    }

    int memoHelp(vector<int> wt, vector<int> val, int W, int idx,
                 vector<vector<int>>& dp) {
        if (W <= 0 || idx == static_cast<int>(wt.size())) {
            return 0;
        }

        if (dp[idx][W] != -1) {
            return dp[idx][W];
        }
        dp[idx][W] = max(val[idx] + recHelp(wt, val, W - wt[idx], idx + 1),
                         recHelp(wt, val, W, idx + 1));
        return dp[idx][W];
    }

   public:
    // Recursive approach without memoization
    int recursive(vector<int> wt, vector<int> val, int W) {
        return recHelp(wt, val, W, 0);
    }

    // Recursion with memoization
    int memoized(vector<int> wt, vector<int> val, int W) {
        vector<vector<int>> dp(static_cast<int>(wt.size()) + 1, vector<int>(W + 1, -1));
        return memoHelp(wt, val, W, 0, dp);
    }

    // Bottom Up 
    int bottomUp(vector<int> wt, vector<int> val, int W) {
        vector<vector<int>> dp(static_cast<int>(wt.size()) + 1, vector<int>(W + 1, 0));

        for (int i = 1; i < static_cast<int>(wt.size()) + 1; i++) {
            for (int j = 1; j < W + 1; j++) {
                if (wt[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i]]);
                }
            }
        }

        return dp[static_cast<int>(wt.size())][W];
    }
};

int main() {
    _01Knapsack ks;
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;
    cout << "Recursive: " << ks.recursive(wt, val, W) << endl;
    cout << "Memoized: " << ks.memoized(wt, val, W) << endl;
    cout << "Bottom Up: " << ks.bottomUp(wt, val, W) << endl;
}
