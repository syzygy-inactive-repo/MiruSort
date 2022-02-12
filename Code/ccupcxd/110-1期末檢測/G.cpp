#include <bits/stdc++.h>

using namespace std;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
using ll = long long;

signed main()
{
    MiruSort
    ll m, n, max = -1;
    while(cin >> m >> n)
    {
        if(m == 0 && n == 0)
            return 0;
        ll ans = 0;
        cout << m << " " << n << " ";
        if(m > n)
            swap(m, n);
        
        for(int i = m; i <= n; ++i)
        {
            int tmp = i;
            while(1)
            {
                if(tmp == 1)
                {
                    ans++;
                    break;
                }
                else if(tmp % 2 == 1)
                    tmp = 3 * tmp + 1;
                else
                    tmp /= 2;
                ans++;
            }
            if(ans > max)
                max = ans;
            ans = 0;
        }
        cout << max << '\n';
        max = -1;
    }
    return 0;
}