#include <bits/stdc++.h>

using namespace std;
#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);

signed main()
{
    MiruSort
    int n;
    cin >> n;
    while(n--)
    {
        int m, p;
        cin >> m >> p;
        if((p - 1)% 2 != 0)
            cout << "NO\n";
        else
        {
            int counter = 0;
            p -= 1;
            while(p % 2 == 0)
            {
                p /= 2;
                counter++;
            }
            if(pow(2, counter) > m)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
