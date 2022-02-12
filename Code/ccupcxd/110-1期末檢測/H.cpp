#include <bits/stdc++.h>

using namespace std;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
using ll = long long;

signed main()
{
    MiruSort
    ll a, b, n;
    cin >> a >> b >> n;
    if(a <= n && b <= n)
        cout << min(a, b) << '\n';
    else if(a <= n)
        cout << a << '\n';
    else if(b <= n)
        cout << b << '\n';
    else
        cout << "maypoo:<\n";
    
    return 0;
}