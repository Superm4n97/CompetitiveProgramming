#include<bits/stdc++.h>
#define ll long long int
#define maxn 10000005

using namespace std;

bool cheack[maxn];
vector < ll > prime;

int main()
{
    for (int i=2;i*i<maxn;i++){
        if (!cheack[i]){
            for (int j = i+i ; j<=maxn ; j+=i){
                cheack[j] = true;
            }
        }
    }
    for (int i=2;i<maxn;i++){
        if (!cheack[i])prime.push_back(i);
    }

    ll tc;
    scanf("%lld",&tc);

    for (int _t = 1 ; _t<=tc ; _t++){
        ll n , cnt = 0;
        scanf("%lld",&n);

        for(int i=0 ; prime[i]<=n/2 ; i++){
            if (!cheack[n-prime[i]])cnt++;
        }
        printf("Case %d: %lld\n",_t , cnt);
    }


    return 0;
}
