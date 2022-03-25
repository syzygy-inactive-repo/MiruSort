/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-03-24 21:19:17
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
    int n, d, num;
    cin >> n >> d;
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i = 0; i < n; ++i)
    {
        cin >> num;
        pq.push(num);
    }
    int sum = 0, ans = 0, cnt = 0;
    while(!pq.empty())
    {
        sum = sum + pq.top();
        ans += sum;
        if(ans > d)
        {
            ans -= sum;
            break;
        }
        pq.pop();
        cnt++;
    }
    cout << cnt << " " << ans << '\n';
}

signed main()
{
    MiruSort
    sol();
    return 0;
}