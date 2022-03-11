/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-03-11 01:25:10
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
const int N = 1000010;
vector<int> lp(N + 5, 0);
vector<int> prime;

void linear_sieve()
{
    for(int i = 2; i <= N; ++i)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j = 0; j < (int)prime.size() && prime[j] <= lp[i] && i * prime[j] <= N; ++j)
            lp[i * prime[j]] = prime[j];
    }
}   

signed main()
{
    MiruSort
    int n;
    ll num;
    lp[1] = 0;
    linear_sieve();
    cin >> n;
    while(n--)
    {
        cin >> num;
        if(num <= N)
        {
            if(lp[num] == num)
                cout << num << " 1\n";
            else
            {
                map<int, int> power;
                while(num != 1)
                {
                    power[lp[num]]++;
                    num /= lp[num];
                }
                cout << '\n';
                for(auto i: power)
                    cout << i.first << " " << i.second << " ";
                cout << '\n';
            }
        }
        else
        {
            int div = 0;
            for(ll el: prime)
            {
                if(num % el == 0)
                {
                    int cnt = 0;
                    while(num % el == 0)
                    {
                        num /= el;
                        cnt++;
                    }
                    cout << el << " " << cnt << " ";
                    div++;
                }
            }
            if(!div || num != 1)
                cout << num << " " << "1\n";
            else
                cout << '\n';
        }
    }
    return 0;
}
