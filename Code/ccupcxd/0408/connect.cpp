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
int w[1005] = {0};
bool visited[1005];
int ans = 0;

vector<int> edge[1005];
void DFS(int root)
{
	visited[root] = true;
    for(auto it: edge[root])
    {
        if(visited[it] != true)
        {
            ans += w[it];
            DFS(it);
        }
    }
}

void sol()
{
    int n, m, s;
    cin >> n >> m;
    loop(i, n)
        cin >> w[i];
    int u, v;
    loop(i, m)
    {   
        cin >> u >> v;
        edge[u - 1].push_back(v - 1);
        edge[v - 1].push_back(u - 1);
    }
    vector<int> ac;
    for(int i = 0; i < n; ++i)
    {
        if(!visited[i])
        {
            DFS(i);
            ans += w[i];
            ac.push_back(ans);
            ans = 0;   
        }
    }
    sort(all(ac));
    for(auto it: ac)
        cout << it << " ";
}

signed main()
{
    MiruSort
    sol();
    return 0;
}