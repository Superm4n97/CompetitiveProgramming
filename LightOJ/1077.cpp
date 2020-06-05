#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);

    for (int _t = 1 ; _t<=tc ; _t++){
        ll a, b, c, d;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        printf("Case %d: %lld\n",_t,__gcd(abs(a-c) , abs(b-d))+1);
    }


    return 0;
}
