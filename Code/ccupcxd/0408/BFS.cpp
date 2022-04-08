#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define miruSort ios_base::sync_with_stdio(0); cin.tie(0);
#define mp make_pair
#define eb emplace_back
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define loop(i, n) for(int i = 0; i < n; ++i)

const ld pi = atan2(0, -1);
const ld eps = 1e-4;
char ma[1005][1005];
const int vertex = 1005;
int level[vertex][vertex];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void init()
{
    for(int i = 0; i < vertex; ++i)
        for(int j = 0; j < vertex; ++j)
            level[i][j] = -1;
}

void sol()
{
    
    int n, m;
    pair<int, int>start, end;
    cin >> n >> m;
    init();
    
    for(int i = 0 ;i <= n + 1; ++i)
        for(int j = 0; j <= m + 1; ++j)
            ma[i][j] = '#';
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> ma[i][j];
            if(ma[i][j] == 'A')
                start = {i, j};
            else if(ma[i][j] == 'B')
                end = {i, j};
        }
    }
    queue<pair<int, int>> q;
    q.push(start);
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int row = cur.first;
        int col = cur.second;
        if(row == end.x && col == end.y)
        {
            cout << "YES\n" << level[end.x][end.y] + 1 << '\n'; 
            return;
        }
        for(int i = 0; i < 4; ++i)
        {
            int new_row = row + dx[i];
            int new_col = col + dy[i];
            if(new_row <= 0|| new_row > n || new_col <= 0 || new_col > m)
                continue;
            if(ma[new_row][new_col] == '#')
                continue;
            if(level[new_row][new_col] != -1)
                continue;
            level[new_row][new_col] = level[row][col] + 1;
            pair<int, int> next = make_pair(new_row, new_col);
            q.push(next);
        }
    }
    cout << "NO\n";
}

signed main()
{
    miruSort
    sol();
    return 0;
}
