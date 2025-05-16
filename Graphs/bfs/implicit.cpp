#include<bits/stdc++.h>

using namespace std;

using state = pair<int,int>;

#define F first
#define S second


vector<vector<char>> g;
vector<vector<state>> par;
vector<vector<int>> vis;
vector<vector<int>> dist;
vector<vector<int>> ways;

bool is_reachable = false;


int m,n;
state st,en;



//easier way to write the nieghs function .. split into 2 funcs

bool is_valid(int x, int y)
{
	if(x>=0 && x<n&& y>=0 && y < m && g[x][y] != '#')
	{
		return 1;
	}
	return 0;
}

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
vector<state> neighs(state node)
{
	vector<state> neighbours;
	for(int i=0; i<4; i++)
	{
		int x = node.F+dx[i];
		int y = node.S+dy[i];

		if(is_valid(x,y))
		{
			neighbours.push_back({x,y});
		}

	}

	return neighbours;
}

/*

vector<state> neighs(state node)
{
	vector<state> neighbours;

	if(node.F+1<m)
	{
		if(g[node.F+1][node.S] != '#')
		{
			neighbours.push_back({node.F+1,node.S});
		}
	}
	if(node.S+1<n)
	{
		if(g[node.F][node.S+1] != '#')
		{
			neighbours.push_back({node.F,node.S+1});
		}
	}
	if(node.F-1>=0)
	{
		if(g[node.F-1][node.S] != '#')
		{
			neighbours.push_back({node.F-1,node.S});
		}
	}
	if(node.S-1>=0)
	{
		if(g[node.F][node.S-1] != '#')
		{
			neighbours.push_back({node.F,node.S-1});
		}
	}

	return neighbours;

}

*/
void bfs(state node)
{
	vis[node.F][node.S] = 1;

	queue<state> q;
	q.push(node);

	ways[node.F][node.S] = 1;

	dist[node.F][node.S] = 0;

	while(!q.empty())
	{
		state top = q.front();
		q.pop();


		for(auto v : neighs(top))
		{
			if(!vis[v.F][v.S])
			{
				par[v.F][v.S]=top;
				dist[v.F][v.S] = dist[top.F][top.S]+1;
				vis[v.F][v.S] = 1;
				q.push(v);
				if(v==en)
				{
					is_reachable = true;
				}

			}
			else
			{
				ways[top.F][top.S] += ways[v.F][v.S];

			}
		}
	}
}


void print_sol(state node)
{
	if(node!=st)
	{
		print_sol(par[node.F][node.S]);
	}
	cout << "(" << node.F << "," << node.S << ")" << ",";
}



int main()
{
	int a,b;

	int t;
	t = 1;
	while(t--)
	{
		cin >> n  >> m ;
		g.resize(n+1);

		dist.assign(n + 1, vector<int>(m + 1, -1));
		ways.assign(n + 1, vector<int>(m + 1, 0));
		vis.assign(n + 1, vector<int>(m + 1, 0));
		par.assign(n + 1, vector<state>(m + 1, {-1,-1}));


		for(int i=0; i<n; i++)
		{
			g[i].resize(m+1);
			for(int j =0 ; j<m ; j++)
			{
				char x;
				cin >> x;
				if(x == 'S')
				{
					st= {i,j};
				}
				else if(x == 'F')
				{
					en = {i,j};
				}
				g[i][j]=x;
			}
		}




		bfs(st);

		if(is_reachable)
		{
			cout << dist[en.F][en.S] << endl;
		}




		for(int i=0; i<n; i++)
		{
			for(int j =0 ; j<m ; j++)
			{
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << endl;
		cout << "vis"<< endl;

		for(int i=0; i<n; i++)
		{
			for(int j =0 ; j<m ; j++)
			{
				cout << vis[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;


		cout << "sol:" << endl;
		print_sol(en);
		cout << endl;

		state temp=en;
		while(temp.F != -1 && temp.S!=-1 )
		{
			cout << "(" << temp.F << "," << temp.S << ")" << ",";
			temp = par[temp.F][temp.S];
		}
		cout << endl;

		cout << "no of shortest ways :" << endl;
		for(int i=0; i<n; i++)
		{
			for(int j =0 ; j<m ; j++)
			{
				cout << ways[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;



	}

}
