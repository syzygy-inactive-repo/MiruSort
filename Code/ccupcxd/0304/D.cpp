/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-03-04 09:25:10
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);

bool sol(ll n)
{
    if(n < 4)
        return n == 2 || n == 3;
    for(ll i = 2; i * i <= n; ++i)
        if(n % i == 0)
            return false;
    return true;
}

signed main()
{
    MiruSort
    ll n;
    while(cin >> n)
    	(sol(n)) ? cout << "isprime\n" : cout << "oh no\n";
    return 0;
}