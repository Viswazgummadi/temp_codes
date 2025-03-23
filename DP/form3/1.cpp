/*

multi seq dp


*/

#include<bits/stdc++.h>
using namespace std;


string a,b;
int m,n;

int dp[1001][1001];

int rec(int i,int j)
{



	if(i>=m||j>=n)
	{
		return 0;
	}


	if(dp[i][j] != -1) return dp[i][j];

	// computations

	int ans = 0;

	ans = max(rec(i+1,j) , rec(i,j+1));
	if(a[i]==b[j])
	{
		ans = max(ans, 1 + rec(i+1,j+1) );
	}



	// save and return



	return dp[i][j] = ans;
}



int solve()
{


        memset(dp, -1, sizeof(dp));
	return rec(0,0);
}






int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int t;
	cin >> t;
	while(t--)
	{

		cin >> a >> b;
                m = a.size(), n = b.size();
		int ans = solve();
		cout << ans << endl;

	}
	return 0;
}
