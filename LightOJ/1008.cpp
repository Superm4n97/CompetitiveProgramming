#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

int main()
{
    ll tc;
    scanf("%lld",&tc);

    for (int _t=1;_t<=tc;_t++){
        ll n;
        scanf("%lld",&n);

        ll r = sqrt(n);
        if (r*r==n){
            if (r%2)printf("Case %d: 1 %lld\n",_t,r);
            else printf("Case %d: %lld 1\n",_t,r);
        }
        else {
            ll temp = n - r*r;
            ll firstHalf = min(r+1,temp);
            ll secondHalf = temp - firstHalf;
            ll x = r+1 , y = r+1;


            if ((r+1)%2){
                y = firstHalf;
                x-=secondHalf;
            }
            else {
                x = firstHalf ;
                y -= secondHalf;
            }
            printf("Case %d: %lld %lld\n",_t,x,y);
        }
    }


    return 0;
}
