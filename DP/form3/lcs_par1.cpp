#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

int lcs_parallel(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    // Bottom-up DP with anti-diagonal parallelization
    for (int sum = m+n-2; sum >= 0; sum--) {
        #pragma omp parallel for schedule(dynamic)
        for (int i = max(0, sum-n+1); i <= min(sum, m-1); i++) {
            int j = sum - i;
            
            // Calculate dp[i][j] based on its dependencies
            int ans = max(dp[i+1][j], dp[i][j+1]);
            if (a[i] == b[j]) {
                ans = max(ans, 1 + dp[i+1][j+1]);
            }
            dp[i][j] = ans;
        }
    }
    
    return dp[0][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    // Set the number of threads
    #pragma omp parallel
    {
        #pragma omp master
        {
            cout << "Using " << omp_get_num_threads() << " threads\n";
        }
    }
    
    while (t--) {
        string a, b;
        cin >> a >> b;
        int ans = lcs_parallel(a, b);
        cout << ans << endl;
    }
    
    return 0;
}
