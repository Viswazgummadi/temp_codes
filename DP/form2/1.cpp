#include <bits/stdc++.h>

using namespace std;
int arr[10010];
int dp[10010];


int rec(int level)
{
	// returns the LIS ending at this level



	//pruniung

	if(level <0)
	{
		return 0;
	}
	//base case
	// same as above so np

	//cache check
	if(dp[level] != -1)
	{
		return dp[level];
	}

	// computations
	int ans =1;


	for(int prev_taken =0;prev_taken < level ; prev_taken++)
	{

		if (arr[prev_taken] < arr[level])
		{
			ans = max(ans , 1+rec(prev_taken));
		}
	}


	// return and save
	return dp[level]=ans;
}



int solve(int n)
{
	int fin = 1;

	memset(dp,-1,sizeof(dp));

	for(int i =0;i<n;i++)
	{

		fin = max(fin,rec(i));
	}
	return fin;
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

    int n;
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = solve(n);

    cout << ans << endl;

    return 0;
}
