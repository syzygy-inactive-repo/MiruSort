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
#define mp make_pair
#define eb emplace_back
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define loop(i, n) for(int i = 0; i < n; ++i)

const ld pi = atan2(0, -1);
const ld eps = 1e-4;

ll _gcd(ll a, ll b, ll* x, ll* y) // 擴展歐基里德算法
{
    if(a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}
    ll x1, y1;
	ll gcd = _gcd(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
}

void modInverse(ll a, ll m)
{
	ll x, y;
	ll g = _gcd(a, m, &x, &y);
	ll res = (x % m + m) % m;
	cout << res;
}

int main()
{
	ll a, m;
    cin >> a >> m;
	modInverse(a, m);
	return 0;
}

