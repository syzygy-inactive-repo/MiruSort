#include <bits/stdc++.h>

using namespace std;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
using ll = long long;

signed main()
{
    MiruSort
    ll a, b, n;
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        if(__gcd(a, b) == 1)
            cout << "1314520\n";
        else
            cout << a * b / __gcd(a, b) << '\n';
    }
    
    return 0;
}