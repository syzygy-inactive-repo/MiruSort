#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
using ll = long long;
#define miru ios_base::sync_with_stdio(0); cin.tie(0);
ll n, ans = 0, target, num, m;
vector<ll> arr[2], subset[2];
bool used[2][21] = {false};
 
void DFS(ll count, ll now, ll index)
{
    if(count == arr[index].size())
    {
        subset[index].emplace_back(now);
        return;
    }
    used[index][count] = false;
    DFS(count + 1, now, index);
    used[index][count] = true;
    DFS(count + 1, now + arr[index][count], index);
}
 
int main()
{
    miru
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        cin >> num;
        if(i < n / 2)
            arr[0].emplace_back(num);
        else
            arr[1].emplace_back(num);
    }
    DFS(0, 0, 0);
    DFS(0, 0, 1);
    sort(subset[0].begin(), subset[0].end());
    sort(subset[1].begin(), subset[1].end());
    for(int i = 0; i < m; ++i)
    {
        cin >> num;
        bool flag = true;
        for(ll j: subset[0])
        {
            auto it = lower_bound(subset[1].begin(), subset[1].end(), num - j);
            if(it != subset[1].end() && *it == num - j)
            {
                cout << "yes\n";
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "no\n";
    }
    return 0;
}
