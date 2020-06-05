#include<bits/stdc++.h>
#define ll long long int
#define gama 0.57721566490

using namespace std;

double A[1000006];

int main()
{
    A[1] = 1;
    for (int i=2;i<=1000000;i++){
        A[i]+=A[i-1]+(1.0/i);
    }

    ll tc;
    scanf("%lld",&tc);

    for (int ii = 1 ; ii<=tc ; ii++){
        ll n;
        scanf("%lld",&n);

        if (n<=1000000)printf("Case %d: %.10lf\n",ii,A[n]);
        else {
            double k = (double)n + 0.5;
            double ans = log(k)+gama;
            printf("Case %d: %.10lf\n",ii,ans);
        }
    }


    return 0;
}
