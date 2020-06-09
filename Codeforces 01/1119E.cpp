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

int main()
{
    ll n,cnt=0,pre=0;
    cin >> n;
    for (int i=0;i<n;i++){
        ll a;
        cin >> a;
        pre = 3-pre;
        if (a>=pre){
            a-=pre;
            cnt++;
        }
        cnt+=(a/3);
        pre = a%3;
    }
    cout << cnt << endl;

    return 0;
}

//100
//5 5 2 4 5 4 4 4 4 2 5 3 4 2 4 4 1 1 5 3 2 2 1 3 3 2 5 3 4 5 1 3 5 4 4 4 3 1 4 4 3 4 5 2 5 4 2 1 2 2 3 5 5 5 1 4 5 3 1 4 2 2 5 1 5 3 4 1 5 1 2 2 3 5 1 3 2 4 2 4 2 2 4 1 3 5 2 2 2 3 3 4 3 2 2 5 5 4 2 5
