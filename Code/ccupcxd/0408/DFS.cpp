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
struct Graph
{
    int u;
    int w;
};

void init(int n)
{
    for(int i = 1; i <= n; ++i)
        visited[i] = false;
}

bool cmp(Graph a, Graph b)
{
    if(a.w != b.w)
        return a.w < b.w;
    return a.u < b.u;
}
vector<struct Graph> edge[1005];
void DFS(int root)
{
	visited[root] = true;
    sort(all(edge[root]), cmp);
    for(auto it: edge[root])
    {
        if(visited[it.u] != true)
        {
            cout << it.u << " ";
            DFS(it.u);
        }
    }
}

void sol()
{
    int n, m, s;
    cin >> n >> m >> s;
    init(n);
    loop(i, n)
        cin >> w[i];
    int u, v;
    loop(i, m)
    {   
        cin >> u >> v;
        edge[u].push_back({v, w[v - 1]});
        edge[v].push_back({u, w[u - 1]});
    }
    cout << s << " ";
    DFS(s);
}

signed main()
{
    MiruSort
    sol();
    return 0;
}
