#include<bits/stdc++.h>

using namespace std;

int m, n;
// n nodes and m edges
vector<vector<int>> g;

vector<int> vis;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
	while(t--)
	{
		cin >> m >> n ;
		//assign each time based on your context
		//base template includes

		g.resize(n+1);
		for(int i = 0 ; i < n ; i++)
		{
			int a,b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		vis.assign(n+1,0);


		algo();


        	for(int i=0;i<vis.length();i++)
        	{
                	if(vis[i] != 0)
        	        {
                        cout << i << " ";
                	}
        	        cout << endl;
	        }


	}


	return 0;

}
