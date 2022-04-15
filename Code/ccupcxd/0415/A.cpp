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

const int maxn = 100005;
struct Edge
{
    ll v, w;
    bool operator < (const Edge &cmp) const
    {
        return cmp.w < w;
    }
};
vector<Edge> Graph[maxn];
ll dis[maxn];
void dijkstra(int s)
{
    memset(dis, -1, sizeof(dis));
    priority_queue<Edge> pq;
    pq.push({s, 0});
    while(!pq.empty())
    {
        auto node = pq.top(); pq.pop();
        if(dis[node.v] != -1)
            continue;
        dis[node.v] = node.w;
        for(auto k: Graph[node.v])
            if(dis[k.v] == -1)
                pq.push({k.v, node.w + k.w});
    }
}

void sol()
{
	int n, m;
    int u, v, w;
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v >> w;
        Graph[u].push_back({v, w});
    }
    dijkstra(1);
    for(int i = 1; i <= n; ++i)
        cout << dis[i] << " \n"[i == n];
}

signed main()
{
    MiruSort
    sol();
    return 0;
}