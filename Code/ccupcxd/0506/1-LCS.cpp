/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-05-06 09:33:38
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
int dp[1005][1005];

void sol()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int l1 = s1.size(), l2 = s2.size();
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= l1; ++i)
    {
        for(int j = 1; j <= l2; ++j)
        {
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    cout << dp[l1][l2] << '\n';
}

signed main()
{
    MiruSort
    sol();
    return 0;
}