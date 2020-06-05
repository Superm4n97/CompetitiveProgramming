#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define ull             unsigned long long
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

int main()
{
    int n,mn=10000,ans = 0,sum=0;
    cin >> n;
    vii v;
    input(v,n);
    srt(v);
    mn = v[0];
    for (int i=0;i<n;i++)sum+=v[i];
    for (int i=n-1;i>=0;i--){
        for (int j=2;j<v[i];j++){
            if (v[i]%j==0){
                int k= v[i]/j;
                ans = max(ans,v[i]+mn - mn*j-k);
               // cout << v[i] << "   " << j << endl;
            }
        }
    }
    cout << sum - ans << endl;


    return 0;
}
