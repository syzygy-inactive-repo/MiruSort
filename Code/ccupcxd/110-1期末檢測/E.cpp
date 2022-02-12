#include <bits/stdc++.h>

using namespace std;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);

signed main()
{
    MiruSort
    int n, m;
    char arr[1010][1010], xy[3];
    bool flag = false;
    cin >> n >> m;
    for(int i = 0 ; i <= n + 1; ++i)
        for(int j = 0; j <= m + 1; ++j)
            arr[i][j] = '0';
    for(int i = 1 ; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin  >> arr[i][j];
    cin >> xy[0] >> xy[1];
    for(int i = 1 ; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(arr[i][j] == '2')
            {
                if(arr[i][j + 1] == xy[0] && arr[i][j - 1] == xy[1])
                {
                    cout << i << " " << j << '\n';
                    flag = true;
                }
                else if(arr[i + 1][j] == xy[1] && arr[i - 1][j] == xy[0])
                {
                    cout << i << " " << j << '\n';
                    flag = true;
                }
            }
        }
    }
    if(!flag)
        cout << "GoodBye baby goodbye ;<\n";

    return 0;
}