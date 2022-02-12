#include <bits/stdc++.h>

using namespace std;
using ld = long double;
#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
#define x first
#define y second
const ld eps = 1e-9;

bool checker(ld a)
{
    return abs(a - round(a)) < eps;
}

signed main()
{
    MiruSort
    double n, xy[2][2], k;
    cin >> n;
    while(n--)
    {
        cin >> xy[0][0] >> xy[0][1];
        cin >> xy[1][0] >> xy[1][1];
        cin >> k;
        if(xy[0][0] == xy[1][0] && xy[0][1] == xy[1][1])
        {
            if(k == 0)
                cout << "1\n";
            else
            {
                int ans = 2;
                //y = +-sqrt(k^2 - (x - a)^2) + b
                for(int i = xy[0][0] - k + 1; i < xy[0][0] + k; ++i)
                {
                    if(checker(sqrt(pow(k, 2) - pow((i - xy[0][0]),2)) + xy[0][1]))
                        ans++;
                    if(checker(-sqrt(pow(k, 2) - pow((i - xy[0][0]),2)) + xy[0][1]))
                        ans++;
                }
                cout << ans << '\n';
            }
            continue;
        }
        ld check = pow(xy[0][0] - xy[1][0], 2) + pow(xy[0][1] - xy[1][1], 2);
        pair<ld, ld> mp(xy[1][0] + ((xy[0][0] - xy[1][0]) / 2), xy[1][1] + ((xy[0][1] - xy[1][1]) / 2));
        if((k * k * 4) < check)
            cout << "0\n";
        else if((k * k * 4) == check)
        {
            if(checker(mp.x) && checker(mp.y))
                cout << "1\n";
            else
                cout << "0\n";
        }
        else
        {
            ld dist = sqrt(check) / 2;
            ld h = sqrt(k * k - dist * dist);
            ld xc = mp.x + (h / (dist * 2)) * (xy[1][1] - xy[0][1]);
            ld yc = mp.y - (h / (dist * 2)) * (xy[1][0] - xy[0][0]);
            int ans = 0;
            if(checker(xc) && checker(yc))
                ans++;
            xc = mp.x - (h / (dist * 2)) * (xy[1][1] - xy[0][1]);
            yc = mp.y + (h / (dist * 2)) * (xy[1][0] - xy[0][0]);
            if(checker(xc) && checker(yc))
                ans++;
            cout << ans << "\n";
        }
    }
    return 0;
}
