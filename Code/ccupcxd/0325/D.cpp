/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-03-24 22:33:21
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

void sol()
{
	ll n, ans = 0;
	cin >> n;
    vector<ll> arr(n);
    loop(i, n)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    while(n > 3)
    {
        ans += min(2 * arr[1] + arr[n - 1] + arr[0], 2 * arr[0] + arr[n - 1] + arr[n - 2]);
        n -= 2;
    }
    if(n == 3)
        ans += arr[0] + arr[1] + arr[2];
    else if(n == 2)
        ans += arr[1];
    else if(n == 1)
        ans += arr[0];
    cout << ans << '\n';
}

signed main()
{
    MiruSort
    sol();
    return 0;
}