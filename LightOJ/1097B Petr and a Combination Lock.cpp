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

int main()
{
    int n;
    cin  >> n;
    vii v;
    input(v,n);
    bool ans= false;
    for (int i=0;i<(1<<n);i++){
        int t = i,tut=n , temp=0;
        //cout << i << endl;
        for (int j=0;j<n;j++){
            if (t%2){
                temp+=v[j];
            }
            else temp-=v[j];
            if (temp<0)temp+=360;
            t/=2;
            //if (i==6)cout <<  "   " << temp << endl;
        }
        temp%=360;
        if (temp==0)ans=true;
    }
    cout << (ans ? "YES":"NO") << endl;

    return 0;
}
