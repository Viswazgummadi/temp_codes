#include <bits/stdc++.h>
using namespace std;

int m,n;

string a,b;

int dp[1001][1001];

int rec(int i , int j)
{
    //pruning
    if(i>=m || j>=n)
    {
        return 0;
    }
    
    // dp check 
    
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    
    // computations
    
    int ans = 0;
    ans = max(rec(i+1,j),ans);
    ans = max(rec(i,j+1),ans);
    if(a[i]==b[j])
    {
        ans = max(1 + rec(i+1,j+1), ans);
    }
    
    return dp[i][j] = ans;
}

void solve()
{
    cin >> m >> n;
    cin >> a >> b;
    
    memset(dp,-1,sizeof(dp));
    cout << rec(0,0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t = 1 ;
    
    while(t--)
    {
        solve();
    }
}
