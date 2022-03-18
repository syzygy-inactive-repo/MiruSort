/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-03-18 13:32:14
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

void sol(int n, int m)
{
    int ans = 0;
    vector<int> arr(n);
    loop(i, n)
        cin >> arr[i];
    sort(rall(arr));
    for(auto i: arr)
    {
        if(m == 0)
            break;
        if(m >= i)
        {
            ans += m / i;
            m %= i;
        }
    }
    (ans == 0) ? cout << "-1\n" : cout << ans << '\n';
}

signed main()
{
    MiruSort
    int n, m;
    cin >> n >> m;
    sol(n, m);
    return 0;
}