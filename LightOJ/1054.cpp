#include<bits/stdc++.h>
#define ll long long int
#define maxn 1000005
#define show(x) cout << #x << " : " << x << endl;
#define mod 1000000007

using namespace std;

bool M[maxn];
vector < ll > PRIME;

void initialization()
{
    for (ll i = 2 ; i<maxn ; i++){
        if (!M[i]){
            PRIME.push_back(i);
            for (int j = i ; j < maxn ; j+=i)M[i] = true;
        }
    }
}

ll bigmod(ll a, ll p)
{
    if (p==0)return 1;
    if (p==1)return a%mod;
    ll temp = bigmod(a,p/2);
    temp*=temp;
    temp%=mod;

    if (p%2){
        temp*=a;
        temp%=mod;
    }
    return temp;
}

int main()
{
    initialization();
    int tc;
    scanf("%lld",&tc);

    for (int _t = 1 ; _t<=tc ; _t++){
        ll n,m , ans = 1;
        scanf("%lld %lld",&n,&m);

        for (int i=0;PRIME[i]*PRIME[i]<=n ; i++){
            if (n%PRIME[i]==0){
                ll cnt = 0;
                while(n%PRIME[i]==0){
                    cnt++;
                    n/=PRIME[i];
                }
                cnt*=m;

                ll temp = bigmod(PRIME[i],cnt+1) - 1;
                if(temp<0)temp+=mod;
                temp*=bigmod(PRIME[i]-1,mod-2);
                temp%=mod;

                ans*=temp;
                ans%=mod;
            }
        }
//        show(ans);
        if (n>1){
            ll temp = bigmod(n,m+1) - 1;
            if(temp<0)temp+=mod;
//            show(temp);
//            show(n);
//            show(bigmod(n-1 , mod-2))
            temp*=bigmod(n-1 , mod-2);
            temp%=mod;

            ans*=temp;
            ans%=mod;
        }
        printf("Case %d: %lld\n",_t,ans);
    }


    return 0;
}
