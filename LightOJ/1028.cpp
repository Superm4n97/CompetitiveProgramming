#include<bits/stdc++.h>
#define ll long long int
#define maxn 1000006
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

bool mark[1000006];
vector < ll > PRIME;

void seive()
{
    for (int i=2;i<maxn;i++){

        if (!mark[i]){
            PRIME.push_back(i);
            for (int j= 2*i ; j<maxn ; j+=i)mark[j] = true;
        }
    }
    return;
}

int main()
{
    seive();
    int tc;
    scanf("%lld",&tc);
    for (int _t = 1 ; _t<=tc; _t++){
        ll n;
        scanf("%lld",&n);
        ll ans = 1;
        for (int i=0; PRIME[i]*PRIME[i] <= n ;i++){
            if (n%PRIME[i]==0){
                ll cnt = 0;
                while(n%PRIME[i]==0){
                    cnt++;
                    n/=PRIME[i];
                }
                ans*=(cnt+1);
                //show(cnt);
            }
        }
        if (n>1){
            ans*=2;
        }
        //if (ans>1)ans--;

        printf("Case %d: %lld\n",_t,ans-1);
    }


    return 0;
}
