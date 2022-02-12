#include <bits/stdc++.h>

using namespace std;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
using ll = long long;
ll ans = 1;

void solve(ll a, ll b)
{
    if(a == b)
        return;
    ans++;
    a -= b;
    return solve(max(a, b), min(a, b));
}   

signed main()
{
    MiruSort
    int n;
    cin >> n;
    while(n--)
    {
        ll a, b;
        cin >> a >> b;
        solve(max(a, b), min(a, b));
        cout << ans << '\n';
        ans = 1;
    }
    return 0;
}