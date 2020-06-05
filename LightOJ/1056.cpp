#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    for (int _t = 1 ; _t<=tc ; _t++){
        double a,b , xx , yy;
        scanf("%lf : %lf",&a,&b);

        double st = 0 , ed = 1005.0 , ans;

        for (int i=0;i<100;i++){
            double mid = (st+ed)/2.0;
            double x = a*mid , y = b*mid;
            double R = sqrt(x*x + y*y);
            double A = acos(y/R);
            double thita = acos(-1.0) - 2.0*A;
            double s = R*thita/2.0;
            ans = 2.0*(s+x);
            xx = x , yy = y;

            if (ans<=400.00)st = mid;
            else ed = mid;
        }
        printf("Case %d: %.8f %.8f\n",_t,xx,yy);
    }

    return 0;
}
