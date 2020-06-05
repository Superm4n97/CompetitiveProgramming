#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    for (int _t=1;_t<=tc;_t++){
        double l , n , c , ans, s;

        cin >> l >> n >> c;

        if (n==0.0 || c==0.0){
            printf("Case %d: 0.0\n",_t,ans);
            continue;
        }

        s = (1.0+n*c)*l;

        double b = 0.0 , e = 1000000.0 , r , a , thita ,ss;
        for (int i=0;i<1000;i++){
            r = (b+e)/2.0;
            a = sqrt(r*r - l*l / 4.0);

            thita = asin(l/2.0/r)*2.0;
            ss = r*thita;

            ans = r-a;

            if (ss>=s)b=r;
            else e = r;
        }
        printf("Case %d: %.8f\n",_t,ans);

    }


    return 0;
}
