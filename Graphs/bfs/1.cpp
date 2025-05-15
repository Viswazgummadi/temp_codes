#include<bits/stdc++.h>

using namespace std;


int m,n;

// n nodes m edges


vector<vector<int>> g;
vector<vector<int>> components;
vector<int> comp_size;
vector<int> vis;
int size_this = 0;

// vis[node] = 1/0



// void dfs(int node, int comp)
// {
// 	vis[node] = 1;
// 	components[comp].push_back(node);
// 	size_this ++;

// 	for(auto v : g[node])
// 	{
// 		if(!vis[v])
// 		{
// 			dfs(v,comp);
// 		}
// 	}
// }



void bfs(int sc_node,int comp)
{
	queue<int> q ;
	q.push(sc_node);
	vis[sc_node] = 1;
	components[comp].push_back(sc_node);
	size_this++;
	while(!q.empty())
	{
	    // to see the order of nodes into the queue .. you can  directly use this pop this also will be in the same order as traversal
		int top = q.front();
		q.pop();
		for(auto v : g[top])
		{
			if(!vis[v])
			{
				vis[v] = 1;
				size_this++;
				q.push(v);
				components[comp].push_back(v);


			}
		}
	}
}


int main()
{
	cin >> n >> m;

	g.resize(n+1);
	components.resize(n+1);

	for(int i =0 ; i < m ; i++)
	{
		int a,b;
		cin >> a >> b ;
		g[a].push_back(b);
		g[b].push_back(a);


	}
	vis.assign(n+1,0);
	comp_size.assign(n+1,0);


	int comp = 0;

	for(int i = 1 ; i < n+1 ; i++)
	{
		if(!vis[i])
		{
			// dfs(i,comp);
			bfs(i, comp);
			comp++;
			comp_size[comp] = size_this;
			size_this = 0;
		}

	}

	cout << "no of components : " << comp << endl;

	cout << "components :" << endl;


	for(int i = 0; i < comp; i++)
	{
		for(auto k : components[i])
		{
			cout << k << ",";
		}
		cout << endl;
	}
// 	for(auto i : components)
// 	{
// 		for(auto k : i)
// 		{
// 			cout << k << ",";
// 		}
// 		cout << endl;
// 	}
// 	cout << endl;


	cout << "size of the components : " << endl;

	for(int i = 0 ; i < n+1 ; i++)
	{
		if(comp_size[i])
		{
			cout << i << " : " << comp_size[i] << endl;
		}
	}

	return 0;
}
