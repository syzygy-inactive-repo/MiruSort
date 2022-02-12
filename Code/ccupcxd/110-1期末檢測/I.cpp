#include <bits/stdc++.h>

using namespace std;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
using ll = long long;

signed main()
{
    MiruSort
    double m;
    while(cin >> m)
    {
        if(m == 0)
            break;
        double left = sqrt(((1.0 + m) / 2.0) * m);
        if((ll)left == left)
            cout << (int)left << '\n';
        else
            cout << "Loser\n";
    }
    return 0;
}