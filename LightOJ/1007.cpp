#include<bits/stdc++.h>
#define ll unsigned long long
#define maxn 5000006

using namespace std;

ll PHI[maxn];
bool MARK[maxn];

void initialization()
{
    for (ll i=0;i<maxn-3;i++)PHI[i] = i;
    for (ll i=2;i<maxn-3;i++){
        if (!MARK[i]){
            MARK[i] = true;
            PHI[i] = i-1;

            for (ll j = 2*i ; j<=maxn-3 ; j+=i){
                PHI[j] = PHI[j] / i * (i-1);
                MARK[j] = true;
            }
        }
    }
    for (ll i = 2 ; i<maxn-3 ; i++)PHI[i] = PHI[i-1] + PHI[i]*PHI[i];
    //cout << cSUM[5000000] << endl;
}



int main()
{
    initialization();
    ll tc;
    scanf("%lld",&tc);
    for (int _t=1;_t<=tc;_t++){
        ll a, b;
        scanf("%llu %llu",&a,&b);
        if (a>b)swap(a,b);
        printf("Case %d: %llu\n",_t,PHI[b] - PHI[a-1]);
    }


    return 0;
}
