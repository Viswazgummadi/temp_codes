#include<bits/stdc++.h>

using namespace std;
int m,n;



vector<vector<int>> g;

vector<int> par,dist,vis;
vector<int> color;

// vis / col one is needed ig

bool is_cycle=0;
vector<int> any_cycle;

void dfs(int node, int parent)
{
    par[node] = parent;
	color[node] = 1;

    // par can be done in 2 ways passed as arg / set par when iterating
    		color[node] = 2;
	for(auto v : g[node])
	{


		if(color[v] == 0)
		{
			// edge is a forward edge;
			dfs(v,node);
		}
		else if(color[v] == 2)
		{
			// we found a back edge
			if(is_cycle == 0)
			{
			    int temp = node;
			    while(temp!= -1 && temp!=v)
			    {
			        any_cycle.push_back(temp);
			        temp = par[temp];
			    }
			    any_cycle.push_back(v);
			    reverse(any_cycle.begin(),any_cycle.end());
			}
			is_cycle = 1;

		}


	}
	color[node] = 3;
}








int main()
{
	cin >> n >> m;


	vis.assign(n+1,0);
	par.assign(n+1, -1);
	dist.assign(n+1,-1);
	color.assign(n+1,0);

	g.resize(n+1);

	for(int i=0; i<m; i++)
	{
		int a,b;


		cin >> a >> b;

		g[a].push_back(b);
		// g[b].push_back(a);
	}


	for(int i =1 ; i< n+1 ; i++)
	{
		if(color[i] == 0)
		{
			dfs(i,-1);
		}
	}

	cout << "visited :" << endl;

	for(int i=0; i<n; i++)
	{
		cout << vis[i] << " " ;
	}

	cout << endl;

	cout << "distance :" << endl;

	for(int i=0; i<n; i++)
	{
		cout << dist[i] << " " ;
	}

	cout << endl;

	cout << "parents :" << endl;

	for(int i=1; i<n+1; i++)
	{
		cout << par[i] << " " ;
	}

	cout << endl;


    cout << "cycle" << endl;
    
    for(auto v : any_cycle)
    {
        cout << v << ",";
    }
    cout << endl;


	return 0;

}
