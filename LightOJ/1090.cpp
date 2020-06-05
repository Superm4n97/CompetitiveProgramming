#include<bits/stdc++.h>
#define ll long long int
#define maxn 1000006
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

ll factorialFive[maxn] , factorialTwo[maxn];

void preCalculation()
{
    for (int i=2 ; i<maxn ; i++){
        ll temp = i , f = 0 , t = 0;
        while(temp%5==0){
            f++;
            temp/=5;
        }
        while(temp%2==0){
            t++;
            temp/=2;
        }
        factorialFive[i] = f;
        factorialTwo[i] = t;
        factorialFive[i] += factorialFive[i-1];
        factorialTwo[i] += factorialTwo[i-1];
    }
    //cout << "ok" <<endl;
}

int main()
{
    preCalculation();

    int tc;
    scanf("%d",&tc);

    for (int _t = 1 ; _t<=tc ; _t++){
        ll n,r,p,q;
        scanf("%lld %lld %lld %lld",&n,&r,&p,&q);

        ll totalFive = factorialFive[n] , totalTwo = factorialTwo[n];

        ll a = p , f = 0 , t = 0;
        while(a%5==0){
            f++;
            a/=5;
        }
        while(a%2==0){
            t++;
            a/=2;
        }
        totalFive += f*q;
        totalTwo += t*q;
        totalFive = totalFive - factorialFive[r] - factorialFive[n-r];
        totalTwo = totalTwo - factorialTwo[r] - factorialTwo[n-r];
        printf("Case %d: %lld\n",_t,max(0LL,min(totalTwo,totalFive)));
    }


    return 0;
}
