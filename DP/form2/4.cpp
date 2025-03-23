/*


max area of square of 1's

*/


#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;


int n;
int arr[1001][1001];
int dp[1001][1001];


int rec(int row, int col)
{

        // pruning
        if(row<0||col<0)
        {
                return 0;
        }

	// base case

	if(arr[row][col]==0)
	{
		return 0;
	}


	// dp check

	if(dp[row][col]!= -1) return dp[row][col];
	// computation

	int ans = 0;
	ans = 1 + min( {rec(row+1,col),rec(row,col+1), rec(row+1,col+1)} );

	//save and return

	return dp[row][col] = ans;
}



int solve()
{
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        dp[i][j]=-1;
                }
        }


	int max_area=0;

        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        max_area=max(max_area,rec(i,j));
                }
        }



	return max_area;
}




int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);


	cin >> n;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
        auto start = high_resolution_clock::now();
	int ans = solve();
	auto stop = high_resolution_clock::now();


        // ✅ Calculate duration
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Maximum Square Side Length: " << ans << endl;
	cout << "Time Taken: " << duration.count() << " microseconds" << endl;

	return 0;
}
