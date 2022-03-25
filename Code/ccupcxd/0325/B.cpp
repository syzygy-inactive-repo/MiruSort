/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-03-24 22:01:15
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
	int n, m, num;
	cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>>pq;
	loop(i, m)
        pq.push(0);
    int ans = -1;
    loop(i, n)
    {
        cin >> num;
        int tmp = num + pq.top();
        pq.pop();
        pq.push(tmp);
        ans = max(tmp, ans);
    }
    cout << ans << '\n';
}

signed main()
{
    MiruSort
    int t;
    cin >> t;
    while(t--)
    	sol();
    return 0;
}