#include <bits/stdc++.h>

using namespace std;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
using ll = long long;

signed main()
{
    MiruSort
    ll a, b, target, num;
    unordered_set<ll> arr1, arr2;
    cin >> a >> b >> target;
    for(int i = 0; i < a; ++i)
    {
        cin >> num;
        arr1.insert(num);
    }
    for(int i = 0; i < b; ++i)
     {
        cin >> num;
        arr2.insert(num);
    }
    for(int i: arr1)
    {
        if(arr2.find(target - i) != arr2.end())
        {
            cout << "Yes\n";
            return 0;
        }
  
    }
    cout << "No\n";
    return 0;
}