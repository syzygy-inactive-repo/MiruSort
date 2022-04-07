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

void sol()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> edge[n + 1];
    int u, v, ask;
    loop(i, m)
    {
        cin >> u >> v;
        edge[u].push_back(v);
    }
    loop(i, q)
    {
        cin >> ask;
        if(edge[ask].empty())
            cout << "-1\n";
        else
        {
            set<int>ans;
            for(auto it: edge[ask])
                ans.insert(it);
            for(auto it: ans)
                cout << it << " ";
            cout << '\n';
        }
    }
}

signed main()
{
    MiruSort
    sol();
    return 0;
}
