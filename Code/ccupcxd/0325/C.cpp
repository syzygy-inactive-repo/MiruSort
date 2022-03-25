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

int comtime(vector<int> arr, int m)
{
    priority_queue<int, vector<int>, greater<int>>pq;
	loop(i, m)
        pq.push(0);
    int ans = -1;
    loop(i, arr.size())
    {
        int tmp = arr[i] + pq.top();
        pq.pop();
        pq.push(tmp);
        ans = max(tmp, ans);
    }
    return ans;
}

void sol()
{
	int n, m, maxx = -1, sum = 0;
	cin >> n >> m;
    vector<int> arr(n);
	loop(i, n)
    {
        cin >> arr[i];
        sum += arr[i];
        maxx = max(maxx, arr[i]);
    }
    int ans = -1;
    if(maxx > m)
        cout << ans << '\n';
    else
    {
        int l = sum / m, r = n, mid;
        while(l < r)
        {
            mid = (l + r) >> 1;
            int k = comtime(arr, mid);
            if(k <= m)
                r = mid;
            else
                l = mid + 1;
        }
        cout << r << '\n';
    }
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