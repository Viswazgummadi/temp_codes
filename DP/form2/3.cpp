#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100][100];
int dp[100][100];


int rec(int row, int col)
{
	// returns max area till this block


	//pruniung

	if(col <0 || row <0 || arr[row][col]==0)
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

	int x =0, y=0;
	for(int i=row;i<n;i++)
	{
		if(arr[i][col]==1)
		{
			x ++;
		}
		else
		{
			break;
		}
	}
        for(int i=col;i<n;i++)
        {
                if(arr[row][i]==1)
                {
                        y ++;
                }
                else
                {
                        break;
                }
        }

	int ans = min(x,y);

	// return and save
	return dp[row][col]=ans;
}



int solve()
{
    // Correctly initialize the dp array
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;


	int max_area = 0;
    for (int i = 0; i < n; i++)
	{
        	for (int j = 0; j < n; j++)
		{
			max_area = max(max_area, rec(i,j));
		}
	}

	return max_area;
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

    cin >> n;


    for (int i = 0; i < n; i++)
    {
	for(int j=0;j<n;j++)
	{
	        cin >> arr[i][j];
        }
    }

    int ans = solve();

    cout << ans << endl;

    return 0;
}
