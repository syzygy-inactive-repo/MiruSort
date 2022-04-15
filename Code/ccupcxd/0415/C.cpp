/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-04-15 00:04:11
 */

#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
#define mp make_pair
#define eb emplace_back
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define loop(i, n) for(int i = 0; i < n; ++i)

const ld pi = atan2(0, -1);
const ld eps = 1e-4;
const ll INF = 1e18;
const int vertex = 505;

ll dist[vertex][vertex];

void sol()
{
	int n, m, q;
    ll u, v, w;
    cin >> n >> m >> q;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
            dist[i][j] = INF;
        dist[i][i] = 0;
    }
    while(m--)
    {
        cin >> u >> v >> w;
        u--, v--;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = dist[u][v];
    }
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    int a, b;
    while(q--)
    {
        cin >> a >> b;
        a--, b--;
        (dist[a][b] == INF) ? cout << "-1\n" : cout << dist[a][b] << '\n';
    }
}

signed main()
{
    MiruSort
    sol();
    return 0;
}