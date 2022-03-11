/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-03-11 00:25:10
 */

#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);

ll inv(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if(m == 1)
        return 0;
    while(a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if(x1 < 0)
        x1 += m0;
    return x1;
}

ll CRT(vector<ll> num, vector<ll> rem, int n, ll product)
{
    ll res = 0;
    for(int i = 0; i < n; ++i)
    {
        ll Mi = product / num[i];
        res += rem[i] * inv(Mi, num[i]) * Mi;
    }
    return res % product;
}

ll __lcm(vector<ll> arr, int n)
{
    ll ans = arr[0];
    for(int i = 1; i < n; ++i)
        ans = (((arr[i] * ans)) / (__gcd(arr[i], ans)));
    return ans;
}

int main()
{
    MiruSort
    int n;
    cin >> n;
    vector<ll> num(n), rem(n);
    ll product = 1;
    for(int i = 0; i < n; ++i)
    {
        cin >> num[i] >> rem[i];
        product *= num[i];
    }
    ll ans = CRT(num, rem, n, product);
    ll lcm = __lcm(num, n); 
    while(ans < product)
    {
        cout << ans << '\n';
        ans += lcm;
    }
    return 0;
}