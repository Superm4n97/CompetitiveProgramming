#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair

using namespace std;

vll v;

int main()
{
    ll n,cnt=0,t,mn=1e9+5;
    scll(n,t);
    for (int i=0;i<n;i++){
        ll a;
        scl(a);
        v.pb(a);
        mn=min(a,mn);
    }
    while(t>=mn){
        ll sum=0,tut=0;
        for (int i=0;i<n;i++){
            if (v[i]<=t){
                sum+=v[i];
                t-=v[i];
                tut++;
            }
        }
        cnt+=(tut*(t/sum+1));
        t%=sum;
    }
    cout << cnt << endl;

    return 0;
}
