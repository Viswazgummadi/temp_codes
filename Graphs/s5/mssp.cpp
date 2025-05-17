#include <bits/stdc++.h>
using namespace std;

using state = pair<int, int>;
#define f first
#define s second

int n, m;
vector<vector<char>> g;
vector<vector<int>> dist;
vector<vector<state>> parent;
vector<vector<char>> owner;

state person;
vector<state> monsters;
vector<state> exits;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#';
}

string recover_path(state end) {
    string path;
    state curr = end;
    while (curr != person) {
        state prev = parent[curr.f][curr.s];
        if (prev.f == curr.f + 1) path += 'U';
        else if (prev.f == curr.f - 1) path += 'D';
        else if (prev.s == curr.s + 1) path += 'L';
        else if (prev.s == curr.s - 1) path += 'R';
        curr = prev;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.resize(n);
    dist.assign(n, vector<int>(m, 1e9));
    owner.assign(n, vector<char>(m, '.'));
    parent.assign(n, vector<state>(m, {-1, -1}));

    queue<state> q;

    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        g[i] = vector<char>(row.begin(), row.end());

        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'A') {
                person = {i, j};
                dist[i][j] = 0;
                owner[i][j] = 'A';
                q.push({i, j});
            }
            else if (g[i][j] == 'M') {
                dist[i][j] = 0;
                owner[i][j] = 'M';
                q.push({i, j});
            }
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && g[i][j] != '#')
                exits.push_back({i, j});
        }
    }

    while (!q.empty()) {
        state top = q.front(); q.pop();
        char cur_owner = owner[top.f][top.s];

        for (int d = 0; d < 4; ++d) {
            int nx = top.f + dx[d];
            int ny = top.s + dy[d];
            if (!is_valid(nx, ny)) continue;

            if (owner[nx][ny] == '.') {
                owner[nx][ny] = cur_owner;
                dist[nx][ny] = dist[top.f][top.s] + 1;
                if (cur_owner == 'A') parent[nx][ny] = top;
                q.push({nx, ny});
            }
        }
    }

    for (const auto& e : exits) {
        if (owner[e.f][e.s] == 'A') {
            cout << "YES\n";
            cout << dist[e.f][e.s] << "\n";
            cout << recover_path(e) << "\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
