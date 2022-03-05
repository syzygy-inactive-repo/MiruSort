/* 
 * Author: D1stance || Bey0nd
 * Time: 2022-03-04 09:25:10
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);
const int N = 1000010;
bool notprime[N + 5];
set<ll> prime;

void linear_sieve()
{
    for(int i = 2; i <= N; ++i)
    {
        if(!notprime[i]) 
            prime.insert(i);
        for(auto p1 : prime)
        {
            if(p1 * i > N)
                break; 
            notprime[p1 * i] = true;
            if(i % p1 == 0)
                break;
        }
    }
}
signed main()
{
    MiruSort
    ll n;
    linear_sieve();
    while(cin >> n)
    {
        if(n <= 1000000)
    	    (prime.find(n) != prime.end()) ? cout << "isprime\n" : cout << "oh no\n";
        else
        {
            int flag = 1;
            for(auto i: prime)
            {
                if(n % i == 0)
                {
                    cout << "oh no\n";
                    flag--;
                    break;
                }
            }
            if(flag)
                cout << "isprime\n";
        }
    }
    return 0;
}