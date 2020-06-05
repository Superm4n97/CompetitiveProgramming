#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;
#define maxn 1000006

using namespace std;

bool cheack[maxn];
vector < ll > prime;
ll cnt = 0;

void seive()
{
    for (int i=2 ; i*i<maxn-4 ; i++){
        if (!cheack[i]){
            for (int j = i+i ; j<maxn-4 ; j+=i)cheack[j] = true;
        }
    }
    for (int i=2 ; i<maxn-4 ; i++){
        if (!cheack[i])prime.push_back(i);
    }
    //show(prime.size());
}

int main()
{
    seive();

    ll tc;
    scanf("%lld",&tc);

    for (int _t =1 ; _t<=tc ; _t++){
        ll a, b;
        scanf("%lld %lld",&a,&b);
        //memset(cheack,false,sizeof(cheack));
        for (int i=0;i<=(b-a)+3;i++)cheack[i] = false;

        if (a==1)cheack[0] = true;

        for (int i = 0 ; prime[i]*prime[i]<=b ; i++){
            ll start = a / prime[i];
            start*=prime[i];
            if (start<a)start+=prime[i];
            if (start==prime[i])start+=prime[i];

            for (ll j = start ; j<=b ; j+=prime[i]){
                cheack[j-a] = true;
            }
        }

        cnt = 0;

        for (int i=0 ; i<=b-a ; i++){
            if (!cheack[i])cnt++;
        }

        printf("Case %d: %lld\n",_t,cnt);
    }


    return 0;
}
