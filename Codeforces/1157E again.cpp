#include <bits/stdc++.h>
#define pb              push_back
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
#define pll             pair < ll , ll >
#define mk              make_pair
#define inf8            100000008

using namespace std;

ll n;
vll A,B;
ll P[200005];
map < ll ,ll > mp;
ll returnValue;
ll findParent(ll a)
{
    //cout << "  " << a << "  mp[" << a << "] " << mp[a] << endl;
    if (P[a]!=a){
        return P[a] = findParent(P[a]);
    }
    if (mp[a]){
        returnValue = a;
        mp[a]--;
        if (!mp[a]){
            ll tut = a+1;
            if (tut==n)tut = 0;
            return P[a] = tut;
        }
        return a;
    }
    ll tut = a+1;
    if (tut==n)tut = 0;
    return P[a] = findParent(tut);
}

int main()
{
    scl(n);
    inputll(A,n);
    for (int i=0;i<n;i++){
        ll a;
        scl(a);
        mp[a]++;
        B.pb(a);
    }
    srt(B);
    for (int i=0;i<=n;i++)P[i] = i;

    for (int i=0;i<n;i++){
        if (mp[B[i]]==0){
            ll temp = B[i]+1;
            if (temp == n) temp = 0;
            P[B[i]] = temp;
        }
        else P[B[i]] = B[i];
    }

    for (int i=0;i<n;i++){
        ll temp = n - A[i];
        if (temp==n)temp = 0;
        ll tut = findParent(temp);
        cout << (A[i]+returnValue)%n << " ";
    }

    return 0;
}
