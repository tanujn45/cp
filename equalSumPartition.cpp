#include <bits/stdc++.h>

using namespace std;

class equalSumPartition {
   private:
    bool recHelp(vector<int> arr, int sum, int idx) {
        if (sum == 0) {
            return true;
        }

        if (idx >= static_cast<int>(arr.size()) || sum < 0) {
            return false;
        }

        return recHelp(arr, sum, idx + 1) |
               recHelp(arr, sum - arr[idx], idx + 1);
    }

    bool memHelp(vector<int> arr, int sum, int idx, vector<vector<int>>& dp) {
        if (sum == 0) {
            return true;
        }

        if (idx >= static_cast<int>(arr.size()) || sum < 0) {
            return false;
        }

        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }

        dp[idx][sum] =
            recHelp(arr, sum, idx + 1) | recHelp(arr, sum - arr[idx], idx + 1);
        return dp[idx][sum];
    }

   public:
    bool recursive(vector<int> arr) {
        int total = 0;
        for (int s : arr) {
            total += s;
        }
        if (!total % 2) {
            return false;
        }

        return recHelp(arr, total / 2, 0);
    }

    bool memoized(vector<int> arr) {
        int total = 0;
        for (int s : arr) {
            total += s;
        }
        if (!total % 2) {
            return false;
        }

        vector<vector<int>> dp(arr.size() + 1, vector<int>(total / 2 + 1, -1));
        return memHelp(arr, total / 2, 0, dp);
    }

    bool bottomUp(vector<int> arr) {
        int total = 0;
        for (int s : arr) {
            total += s;
        }
        if (!total % 2) {
            return false;
        }

        vector<vector<bool>> dp(arr.size() + 1,
                                vector<bool>(total / 2 + 1, false));

        dp[0][0] = true;
        for (int i = 1; i < arr.size() + 1; i++) {
            dp[i][0] = true;
            for (int j = 1; j < total / 2 + 1; j++) {
                if (arr[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] | dp[i - 1][j];
                }
            }
        }

        return dp[arr.size()][total / 2];
    }
};

int main() {
    vector<int> arr = {2, 3, 7};
    equalSumPartition esp;

    cout << "Recursive: " << esp.recursive(arr) << endl;
    cout << "Memoized: " << esp.memoized(arr) << endl;
    cout << "Bottom Up: " << esp.bottomUp(arr) << endl;
}
