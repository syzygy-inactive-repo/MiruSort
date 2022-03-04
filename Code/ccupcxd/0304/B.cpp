/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-03-04 09:18:35
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);

ll fpow(ll a, ll b, ll p)
{
    a %= p;
    b %= p;
    ll res = 1;
    if(a == 0)
        return 0;
    while(b)
    {
        if(b & 1)
            res = (res % p) * (a % p) % p;
        a = (a % p) * (a % p) % p;
        b >>= 1;
    }
    return res % p;
}

signed main()
{
    MiruSort
    ll a, b, p;
    cin >> a >> b >> p;
    cout << fpow(a, b, p) << '\n';
    return 0;
}