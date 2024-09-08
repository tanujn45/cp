#include <bits/stdc++.h>

using namespace std;

class subsetSum {
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
    bool recursive(vector<int> arr, int sum) {
        return recHelp(arr, sum, 0);
    }

    bool memoized(vector<int> arr, int sum) {
        vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1, -1));
        return memHelp(arr, sum, 0, dp);
    }

    bool bottomUp(vector<int> arr, int sum) {
        vector<vector<bool>> dp(arr.size() + 1, vector<bool>(sum + 1, false));
        
        dp[0][0] = true;

        for (int i = 1; i < arr.size() + 1; i++) {
            dp[i][0] = true;
            for (int j = 1; j < sum + 1; j++) {
                if (arr[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] | dp[i - 1][j];
                }
            }
        }

        return dp[arr.size()][sum];
    }
};

int main() {
    vector<int> arr = {2, 3, 7, 8, 10};
    int sum = 4;
    subsetSum sm;

    cout << "Recursive: " << sm.recursive(arr, sum) << endl;
    cout << "Memoized: " << sm.memoized(arr, sum) << endl;
    cout << "Bottom Up: " << sm.bottomUp(arr, sum) << endl;

    sum = 11;
    cout << "Recursive: " << sm.recursive(arr, sum) << endl;
    cout << "Memoized: " << sm.memoized(arr, sum) << endl;
    cout << "Bottom Up: " << sm.bottomUp(arr, sum) << endl;
}
