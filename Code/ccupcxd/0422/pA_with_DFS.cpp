/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-04-22 08:45:04
 */

#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
#define mp make_pair
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define loop(i, n) for(int i = 0; i < n; ++i)

const ld pi = atan2(0, -1);
const ld eps = 1e-4;
vector<int> graph[1005];
bool vis[1005] = {0};

void DFS(int s)
{
    vis[s] = true;
    for(auto it: graph[s])
        if(!vis[it])
            DFS(it);
}

void sol()
{
    int n, m;
    cin >> n >> m;
    int u, v, ans = 0;
    loop(i, m)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    loop(i, n)
    {
        if(!vis[i + 1])
        {
            DFS(i + 1);
            ans++;
        }
    }
    (ans == 1) ? cout << "0\n" : cout << ans << '\n';
}

signed main()
{
    MiruSort
    sol();
    return 0;
}