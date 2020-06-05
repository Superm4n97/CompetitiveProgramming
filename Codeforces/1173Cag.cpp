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

int A[200005] , B[200005] , n , mx = 0;
map < int , int > mp;

int main()
{
    scd(n);
    for (int i=1;i<=n;i++)scd(A[i]);
    for (int i=1;i<=n;i++)scd(B[i]);

    bool ans = true;
    for (int i=1;i<=n;i++){
        if (B[i]!=i)ans = false;
    }
    if (ans){
        cout << 0 << endl;
        return 0;
    }

    for (int i=1;i<=n;i++){
        if (B[i]==0){
            continue;
        }
        int tut  = i-B[i];
        if (tut<=0){///sorted
            tut = i+(n-B[i]+1);
        }
        mp[B[i]] = tut;
    }
    temp = true;
    mx = mp[1];
    vii v;
    for (int i=1;i<=n;i++){
        if (mx<mp[i]){
            mx = mp[i];
            v.pb(mp[i]);
            temp = false;
        }
    }
    srt(v);
    if (!temp)
    cout << << endl;

    return 0;
}

