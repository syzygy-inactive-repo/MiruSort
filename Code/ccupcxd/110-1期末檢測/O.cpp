#include <bits/stdc++.h>

using namespace std;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
using ll = long long;

signed main()
{
    MiruSort
    int n;
    string str;
    vector<char> ans;
    cin >> n;
    cin.ignore();
    while(n--)
    {
        getline(cin, str);
        bool flag = false, flag2 = true;
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] == '*')
            {
                if(flag)
                    continue;
                ans.pop_back();
                flag2 = false;
            }
            else if(str[i] == '~')
            {
                if(flag)
                    continue;
                ans.emplace_back(ans.back());
            }
            else if(str[i] == '?')
            {
                if(flag)
                    continue;
                char tmp = *ans.rbegin();
                *ans.rbegin() = str[i + 1];
                ans.emplace_back(tmp);
                i++;
            }
            else if(str[i] == '@')
            {
                if(flag)
                    continue;
                flag = true;
            }
            else
            {
                if(flag2)
                {
                    ans.emplace_back(str[i]);
                }
                else
                    flag2 = true;
            }
        }
        for(auto i:ans)
            cout << i;
        cout << '\n';
        ans.clear();
    }
    return 0;
}