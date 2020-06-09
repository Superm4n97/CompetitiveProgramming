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
#define inf8            100000008

using namespace std;

ll n,cnt=0,pre=0;
vector < ll > v;

int main()
{
    cin >> n;
    v.pb(0);
    inputll(v,n);
    for (ll i=1;i<=n;i++){
        cnt += (v[i]/3);
        ll temp = v[i]%3;
        if (temp==2){
            if (pre){
                pre--;
                cnt++;
            }
            else {
                pre+=2;
            }
        }
        else pre++;
    }
    cout << cnt << endl;

    return 0;
}
