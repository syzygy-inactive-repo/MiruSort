#include <iostream>

using namespace std;

int main()
{
    long long k,i,t,x,r;
    cin >> k;
    for(i=0;i<k;i++){
        cin >>t>>x;
        if(x>=0){
            r=(t-x)%2;
            if(t-x<0)
                cout << "impossible" <<endl;
            else if(r==1){
                cout << "left"<<endl;
            }
            else if(r==0){
                cout << "right"<<endl;
            }
        }
        else if(x<0){
            r=(t+x-1)%2;
            if(t+x-1<0)
                cout << "impossible" <<endl;
            else if(r==1){
                cout << "right"<<endl;
            }
            else if(r==0){
                cout << "left"<<endl;
            }
        }
    }
    return 0;
}
