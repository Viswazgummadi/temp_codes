#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> g;

vector<int> vis;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
	while(t--)
	{
		solve();
	}
	algo();



	for(int i=0;i<vis.length();i++)
	{
		if(vis[i] != 0)
		{
			cout << i << " ";
		}
		cout << endl;
	}


	return 0;

}
