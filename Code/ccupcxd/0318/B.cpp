/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-03-18 13:19:35
 */

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define loop(i, n) for(int i = 0; i < n; ++i)
int t;

void sol()
{
    int ans = 0, num;
    vector<int> arr, arr2;
    for(int i = 0; i < t; ++i)
    {
        cin >> num;
        arr.emplace_back(num);
    }
    for(int i = 0; i < t; ++i)
    {
        cin >> num;
        arr2.emplace_back(num);;
    }
    sort(all(arr2));
    for(auto el: arr)
    {
        auto it = upper_bound(arr2.begin(), arr2.end(), el);
        if(it != arr2.end())
        {
            arr2.erase(it);
            ans++;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    MiruSort
    while(cin >> t)
    {
        if(t == 0)
            break;
    	sol();
    }
    return 0;
}