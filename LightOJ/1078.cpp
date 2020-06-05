#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

int main()
{
    ll tc;
    scanf("%lld",&tc);
    for (int _t = 1 ; _t<=tc; _t++){
        ll n , d , temp , cnt = 1;
        scanf("%lld %lld",&n,&d);
        temp = d;

        while(1){
            if (d%n==0){
                printf("Case %d: %lld\n",_t,cnt);
                break;
            }
            d*=10;
            d+= temp;
            d%=n;
            cnt++;
        }
    }


    return 0;
}
