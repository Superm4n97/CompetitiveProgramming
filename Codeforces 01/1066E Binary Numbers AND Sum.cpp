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
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair

using namespace std;

ll arr[200005] , power[200005];

void powerof2(ll MOD, ll sizeofPowerArrey)
{
    power[0]=1;
    ll temp=1;
    for (ll i=1;i<sizeofPowerArrey;i++){
        temp=(temp*2)%MOD;
        power[i]=temp;
    }
}

ll multiply(ll i, ll mm)
{
    return (power[i]*mm)%998244353;
}

int main()
{
    powerof2(998244353,200005);
    ll n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    reverse(a.begin() , a.end());
    reverse(b.begin() , b.end());
    for (int i=m-1;i>=0;i--){
        if (b[i]=='1')arr[i]=arr[i+1]+1;
        else arr[i]=arr[i+1];
    }
    ll temp = 0;
    for (int i=0;i<n;i++){
        if (a[i]=='1'){
            temp+=multiply(i,arr[i]);
            temp%=998244353;
        }
    }
    cout << temp << endl;


    return 0;
}
