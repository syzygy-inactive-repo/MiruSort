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
    int n;
    cin >> n;
    vector<int> arr(n);
    loop(i, n)
        cin >> arr[i];
    vector<int> dp(n + 1);
    vector<int> v;
    dp[0] = 1;
    v.push_back(arr[0]);
    int L = 1;
    for(int i = 1; i < n; ++i)
    {
        if(arr[i] > v.back())
        {
            v.push_back(arr[i]);
            L++;
            dp[i] = L;
        }
        else
        {
            auto it = lower_bound(v.begin(), v.end(), arr[i]);
            *it = arr[i];
            dp[i] = (int)(it - v.begin() + 1);
        }
    }
    cout << L << "\n";
}

signed main()
{
    MiruSort
    sol();
    return 0;
}