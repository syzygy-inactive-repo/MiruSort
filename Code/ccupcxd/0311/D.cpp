/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-03-11 01:25:10
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);

signed main()
{
    MiruSort
    ll a, b;
    cin >> a >> b;
    (__gcd(a, b) == 1) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
