#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
using ll = long long;
#define miru ios_base::sync_with_stdio(0); cin.tie(0);
ll n, ans = 1e9, target, num, sum = 0;
vector<ll> arr, subset;
bool used[21] = {false};

void DFS(ll count, ll now)
{
    if(count == n)
    {
        subset.emplace_back(now);
        return;
    }
    used[count] = false;
    DFS(count + 1, now);
    used[count] = true;
    DFS(count + 1, now + arr[count]);
}
int main()
{
    miru
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> num;
        arr.emplace_back(num);
        sum += num;
    }
    DFS(0, 0);
    for(int i = 0; i < subset.size(); i++)
    {
        if(subset[i] == sum)
            continue;
        else
        {
            ll check = abs(subset[i] - (sum - subset[i]));
            if(check < ans)
                ans = check;
        }
    }
    cout << ans << '\n';
    return 0;
}
