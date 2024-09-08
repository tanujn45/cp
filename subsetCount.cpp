#include <bits/stdc++.h>

using namespace std;

class SubsetCount {
   private:
    int recHelp(vector<int> arr, int sum, int idx) {
        if (sum == 0) {
            return 1;
        }

        if (idx == arr.size() || sum < 0) {
            return 0;
        }

        return recHelp(arr, sum - arr[idx], idx + 1) +
               recHelp(arr, sum, idx + 1);
    }

    int memHelp(vector<int> arr, int sum, int idx, vector<vector<int>>& dp) {
        if (sum == 0) {
            return 1;
        }

        if (idx == arr.size() || sum < 0) {
            return 0;
        }

        if (dp[idx][sum]) {
            return dp[idx][sum];
        }

        dp[idx][sum] = memHelp(arr, sum - arr[idx], idx + 1, dp) +
                       memHelp(arr, sum, idx + 1, dp);
        return dp[idx][sum];
    }

   public:
    int recursive(vector<int> arr, int sum) {
        return recHelp(arr, sum, 0);
    }

    int memoized(vector<int> arr, int sum) {
        vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1, 0));
        return memHelp(arr, sum, 0, dp);
    }

    int bottomUp(vector<int> arr, int sum) {
        vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1, 0));

        dp[0][0] = 1;
        for (int i = 1; i < arr.size() + 1; i++) {
            dp[i][0] = 1; 
            for (int j = 1; j < sum + 1; j++) {
                dp[i][j] = dp[i - 1][j];
                if (arr[i - 1] <= j) {
                    dp[i][j] += dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        return dp[arr.size()][sum];
    }
};

int main() {
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int sum = 10;

    SubsetCount sc;
    cout << "Recursive: " << sc.recursive(arr, sum) << endl;
    cout << "Memoized : " << sc.memoized(arr, sum) << endl;
    cout << "Bottom Up: " << sc.bottomUp(arr, sum) << endl;
}
