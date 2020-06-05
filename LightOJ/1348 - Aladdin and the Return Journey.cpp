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

int n;
int S[1000003][25],A[1000003],P[1000003],L[1000003],C[1000003];
vector < int > G;

void update(int i, int v)
{
    C
}

int main()
{
    int tc;
    scd(tc);
    for (int _t=1;_t<=tc;_t++){
        scd(n);
        for (int i=0;i<=n+1;i++){
            A[i]=0,P[i]=0,L[i]=0,C[i]=0;
        }
        for (int i=0;i<n;i++)scd(A[i]);///TLE khaile %I64 change koris

        for (int i=0;i<n;i++){
            int a,b;
            scdd(a,b);
            G[a].pb(b);
            G[b].pb(a);
        }

        int q;
        scd(q);
        printf("Case %d:\n",_t);
        while(q--){
            int c, a,b;
            scdd(c);
            scdd(a,b);
            if (c==1)upate(a,b);
            else {
                printf("%d\n",query(a,b));
            }
        }
    }

    return 0;
}
