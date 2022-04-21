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
int level[MAXN], n;

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
int getDiameter()
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
    return maxLevel;
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
    cout << getDiameter() << '\n';
}

signed main()
{
    MiruSort
    sol();
    return 0;
}