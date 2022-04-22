/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-04-21 23:45:04
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
const int MAXN = 2e5 + 5;
vector<int> Graph[MAXN];
int level[MAXN], n, m, diameter = 0;
vector<int> longest, record;
bool vis[MAXN] = {false};
void init()
{
    memset(level, -1, sizeof(level));
}

void BFS(int s)
{
    queue<int> q;
    q.push(s); level[s] = 0;
    while(q.size())
    {
        int u = q.front();q.pop();
        for(int v: Graph[u])
        {
            if(level[v] != -1)
                continue;
            level[v] = level[u] + 1;
            q.push(v);
        }   
    }
}

void DFS(int root, int tail)
{
    record.push_back(root);
    vis[root] = true;
    if(root == tail)
    {
        int ans = record[diameter / 2] + 1;
        if(diameter % 2 == 1)
            ans = min(record[diameter / 2 + 1] + 1, record[diameter / 2] + 1);
        cout << ans << '\n';
        exit(0);
    }
    for(auto it: Graph[root])
    {
        if(!vis[it])
        {
            DFS(it, tail);
            record.pop_back();
        }
    }
}

void getDiameter()
{
    init();
    BFS(0);
    int maxLevel = -1, maxIndex = -1;
    for(int i = 0; i < n; ++i)
    {
        if(maxLevel < level[i])
        {
            maxLevel = level[i];
            maxIndex = i;
        }
    }
    init();
    longest.push_back(maxIndex);
    BFS(maxIndex);
    maxLevel = -1, maxIndex = -1;
    for(int i = 0; i < n; ++i)
    {
        if(maxLevel < level[i])
        {
            maxLevel = level[i];
            maxIndex = i;
        }
    }
    longest.push_back(maxIndex);
    diameter = maxLevel;
}

void sol()
{
    cin >> n;
    int u, v;
    loop(i, n - 1)
    {
        cin >> u >> v;
        u--, v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    getDiameter();
    loop(i, n + 1)
        vis[i] = false;
    DFS(longest[1], longest[0]);   
}

signed main()
{
    MiruSort
    sol();
    return 0;
}


