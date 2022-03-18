/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-03-18 13:19:35
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
ll t;

bool cmp(pair<ll, ll>a, pair<ll, ll>b)
{
    if(a.y != b.y)
        return a.y < b.y;
    return a.x < b.x;
}

void sol()
{
    ll n;
    cin >> n;
	vector<pair<ll, ll>> arr(n);
    loop(i, n)
        cin >> arr[i].x;
    loop(i, n)
        cin >> arr[i].y;
    sort(all(arr), cmp);
    ll now = 0;
    loop(i, n)
    {
        if(now + arr[i].x <= arr[i].y)
            now += arr[i].x;
        else
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main()
{
    MiruSort
    cin >> t;
    while(t--)
    	sol();
    return 0;
}