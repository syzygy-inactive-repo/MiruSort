/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-04-13 18:56:35
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
const int maxn = 1005;
ll n, dist[maxn];

struct Edge
{
    int u, v, w;
};

vector<struct Edge> edgeList;
bool negative_cycle()
{
    for(int i = 0; i < maxn; ++i)
        dist[i] = INF;
    for(int i = 0; i < n; ++i)
    {
        for(auto e: edgeList)
        {
            if(dist[e.v] > dist[e.u] + e.w)
            {
                dist[e.v] = dist[e.u] + e.w;
                if(i == n - 1)
                    return true;
            }
        }
    }
    return false;
}

void sol()
{
	int m;
    cin >> n >> m;
    int u, v, w;
    while(m--)
    {
        cin >> u >> v >> w;
        edgeList.push_back({u, v, w});
    }
    (negative_cycle()) ? cout << "NO\n" : cout << "YES\n";
}

signed main()
{
    MiruSort
    sol();
    return 0;
}