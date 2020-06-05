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

ll T[200005] , A[200005][4], ANS[200005], Update[200005] , n , q;

int main()
{
    scl(n);
    for (int i=0;i<n;i++)scl(ANS[i]);
    scl(q);
    for (int i=0;i<q;i++){
        scl(A[i][0]);
        if (A[i][0]==1)scll(A[i][1],A[i][2]);
        else scl(A[i][1]);
    }
    for (int i=q-1;i>=0;i--){
        ll tut = T[i+1];
        if (A[i][0]==2)tut = max(A[i][1],tut);
        T[i] = tut;
    }
    for (int i=0;i<q;i++){
        if (A[i][0]==1){
            ANS[A[i][1]-1] = max(A[i][2],T[i]);
            Update[A[i][1]-1] = 1;
        }
    }
    for (int i=0;i<n;i++){
        if (!Update[i]){
            ANS[i] = max(T[0],ANS[i]);
        }
        cout << ANS[i] << " ";
    }


    return 0;
}
