#define show(x) cout << #x << " : " << x << endl
#define pb      push_back
#define ll      long long int

#include<bits/stdc++.h>

ll n,k;

using namespace std;

ll divisor[100005];

int main()
{
    scanf("%I64d %I64d",&n,&k);
    if (k>1000000000){
        printf("-1\n");
        return 0;
    }

    if (k*(k+1)/2>n){
        printf("-1\n");
        return 0;
    }

    //vector < ll > divisor;
    ll mark = 0;

    //show(n);
    //show(k);
    for (ll i=1;i*i<=n;i++){
        //cout << i << endl;
        if (n%i==0){
            divisor[mark] = i;
            mark++;
            if (i*i != n){
                divisor[mark] = n/i;
            }
        }
    }
    //show(mark);
    sort(divisor,divisor+mark);
    //ll t = divisor.size()-1;

    for (ll i=mark-1 ; i>=0 ; i--){
        ll tut = divisor[i]*(k*(k+1))/2;
        if (tut>n)continue;
        if ((n - tut)%divisor[i] ==0){
            ll temp = divisor[i];
            //show(divisor[i]);
            for (ll j=1;j<k;j++){
                printf("%I64d ",temp);
                n-=temp;
                temp+=divisor[i];
            }
            printf("%I64d\n",n);


            return 0;
        }
    }



    return 0;
}
