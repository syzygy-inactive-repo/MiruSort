#include <bits/stdc++.h>

using namespace std;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
using ll = long long;

signed main()
{
    MiruSort
    int n, k, c;
    unordered_map<string, int> arr;
    deque<string> ans;
    string str;
    cin >> n >> k >> c;
    for(int i = 0; i < n; ++i)
    {
        cin >> str;
        if(arr.find(str) == arr.end())
        {
            if((ans.size() == k))
            {
                arr[ans.front()]--;
                ans.pop_front();
            }
            arr[str] = 1;
            ans.emplace_back(str);
        }
        else if(arr[str] < c)
        {
            if(ans.size() == k)
            {
                arr[ans.front()]--;
                ans.pop_front();
            }
            arr[str]++;
            ans.emplace_back(str);
        }
    }
    for(auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << '\n';
    return 0;
}