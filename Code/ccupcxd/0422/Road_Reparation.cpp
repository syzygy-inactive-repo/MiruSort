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

struct Edge
{
    ll u, v, w;
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

vector<Edge> edgeList;

class DSU
{
    public:
        DSU(int size)
        {
            this->size = size;
            p.resize(size + 1);
            for(int i = 0; i <= size; ++i)
                p[i] = -1;
        }
        int Find(int x)
        {    
            return p[x] < 0 ? x : p[x] = Find(p[x]);
        }
        bool Union(int x, int y)
        {
            int g1 = Find(x);
            int g2 = Find(y);
            if(g1 != g2)
            {
                p[g1] += p[g2];
                p[g2] = g1;
                return true;
            }
            return false;
        }
    private:
        int size;
        vector<int> p;
};

void kruskal(int n)
{
    DSU dsu(n);
    ll weight = 0;
    sort(edgeList.begin(), edgeList.end(), cmp);
    int roads = n - 1;
    for(auto k: edgeList)
    {
        if(dsu.Union(k.u, k.v))
        {
            weight += k.w;
            roads--;
        }
    }
    if(!roads)
		cout << weight << "\n";
	else
		cout << "IMPOSSIBLE\n";
}

void sol()
{
    int n, m;
    cin >> n >> m;
    int u, v, w;
    loop(i, m)
    {
        cin >> u >> v >> w;
        edgeList.push_back({u, v, w});
    }
    kruskal(n);
}

signed main()
{
    MiruSort
    sol();
    return 0;
}