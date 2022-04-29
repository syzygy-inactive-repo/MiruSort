/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-04-29 10:17:48
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
    int n, m;
    cin >> n >> m;
    vector<int> v(n), w(n), dp(m + 1, 0);
    for(int i = 0; i < n; ++i)
        cin >> w[i] >> v[i];
    for(int i = 0; i < n; ++i)
        for(int j = m; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[m] << '\n';
}

signed main()
{
    MiruSort
    sol();
    return 0;
}