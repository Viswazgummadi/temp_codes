#include<bits/stdc++.h>

using namespace std;

int p[1001];  // item weights (or values)
int dp[1001][1001];  // memoization table
int taken2D[1001][1001];  // 2D array for decision tracking
int n;

int rec(int i, int s) {
    if (i == n) return 0;  // Base case: no more items to consider

    // If already computed, return from memoization
    if (dp[i][s] != -1) return dp[i][s];

    int t1 = 0, t2 = 0;

    // If we can take this item
    if (p[i] <= s) {
        t1 = p[i] + rec(i + 1, s - p[i]);  // Try taking the item
    }

    // Try skipping this item
    t2 = rec(i + 1, s);

    // Memoize the result and record the decision
    if (t1 > t2) {
        dp[i][s] = t1;
        taken2D[i][s] = 1;  // Mark this item as taken
    } else {
        dp[i][s] = t2;
        taken2D[i][s] = 0;  // Mark this item as not taken
    }

    return dp[i][s];
}

int main() {
    n = 5;
    int sum = 7;

    // Initializations
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    // Initialize dp and taken2D arrays
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            dp[i][j] = -1;
            taken2D[i][j] = 0;
        }
    }

    // Call rec() to fill dp and taken2D
    rec(0, sum);

    // Backtrack from the decision table to print the selected items
    int i = 0, s = sum;
    while (i < n) {
        if (taken2D[i][s]) {
            cout << i << " : " << p[i] << endl;  // Print the selected item
            s -= p[i];  // Decrease the remaining sum
        }
        i++;
    }

    cout << "ans should be taken indexes 2, 3 with a sum of 7" << endl;

    return 0;
}
