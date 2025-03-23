#include <bits/stdc++.h>

using namespace std;
int arr[100][100];
int dp[100][100];


int rec(int row, int col)
{
	// returns the LIS ending at this level


       // check boundary cases like n=0 passes -1, -1
	//pruniung

	if(col <0 || row <0)
	{
		return 0;
	}
	//base case
	// same as above so np

	//cache check
	if(dp[row][col] != -1)
	{
		return dp[row][col];
	}

	// computations
	int ans =arr[row][col];

	int x = rec(row,col-1);
	int y = rec(row-1,col);

	ans += max(x,y);

	// return and save
	return dp[row][col]=ans;
}



int solve(int n)
{
    // Correctly initialize the dp array
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;


	return rec(n-1,n-1);
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

    int n;
    cin >> n;


    for (int i = 0; i < n; i++)
    {
	for(int j=0;j<n;j++)
	{
	        cin >> arr[i][j];
        }
    }

    int ans = solve(n);

    cout << ans << endl;

    return 0;
}
