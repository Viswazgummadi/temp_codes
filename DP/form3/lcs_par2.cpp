#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

class ParallelLCS {
private:
    string a, b;
    int m, n;
    vector<vector<atomic<int>>> dp;
    
    int rec(int i, int j) {
        if (i >= m || j >= n) {
            return 0;
        }
        
        // Check if already computed
        int stored = dp[i][j].load();
        if (stored != -1) return stored;
        
        // Compute the result
        int ans1 = rec(i+1, j);
        int ans2 = rec(i, j+1);
        int ans = max(ans1, ans2);
        
        if (a[i] == b[j]) {
            int ans3 = 1 + rec(i+1, j+1);
            ans = max(ans, ans3);
        }
        
        // Use compare_exchange to atomically update dp[i][j]
        int expected = -1;
        // Keep trying until we successfully update or someone else updates first
        while (!dp[i][j].compare_exchange_weak(expected, ans)) {
            // If another thread has already computed this value, use it
            if (expected != -1) {
                return expected;
            }
            expected = -1;  // Reset for next attempt
        }
        
        return ans;
    }
    
public:
    int solve(const string& a_str, const string& b_str) {
        a = a_str;
        b = b_str;
        m = a.size();
        n = b.size();
        
        // Initialize dp table with all -1
        dp.resize(m, vector<atomic<int>>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j].store(-1);
            }
        }
        
        int result = 0;
        #pragma omp parallel
        {
            #pragma omp single
            {
                result = rec(0, 0);
            }
        }
        
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    ParallelLCS solver;
    
    while (t--) {
        string a, b;
        cin >> a >> b;
        int ans = solver.solve(a, b);
        cout << ans << endl;
    }
    
    return 0;
}
