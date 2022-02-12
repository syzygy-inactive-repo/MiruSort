#include <bits/stdc++.h>

using namespace std;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
using ll = long long;

signed main()
{
    MiruSort
    int t;
    string str;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        getline(cin, str);
        cout << str << " ";
        string tmp1 = str;
        ll last = 1e11;
        unordered_set<ll> check;
        check.insert(atoll(str.c_str()));
        sort(tmp1.begin(), tmp1.end());
        string tmp2 = tmp1;
        reverse(tmp2.begin(), tmp2.end());
        while(true)
        {
            ll now = atoll(tmp2.c_str()) - atoll(tmp1.c_str());
            if(check.find(now) != check.end())
            {
                if(now != last)
                    cout << now;
                cout << "\n";
                break;
            }
            else
                cout << now << ' ';
            check.insert(now);
            last = now;
            tmp1 = to_string(now);
            while(tmp1.size() != str.size())
                tmp1 += "0";
            sort(tmp1.begin(), tmp1.end());
            tmp2 = tmp1;
            reverse(tmp2.begin(), tmp2.end());
        }
    }
    return 0;
}