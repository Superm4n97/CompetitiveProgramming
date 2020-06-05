#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

int main()
{
    ll tc;
    scanf("%lld",&tc);
    for (int _t=1;_t<=tc;_t++){
        ll x,y;
        scanf("%lld %lld",&x,&y);
        if (x==1 || y==1){
            printf("Case %d: %lld\n",_t,max(x,y));
        }
        else if (x==2 || y==2){
            ll temp = max(y,x)/4LL *4 + min(max(y,x)%4LL,2LL)*2;
            printf("Case %d: %lld\n",_t,temp);
        }
        else {
            printf("Case %d: %lld\n",_t,(x*y+1)/2);
        }
    }


    return 0;
}
