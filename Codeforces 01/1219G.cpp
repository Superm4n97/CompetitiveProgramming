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
#define ss              second
#define ff              first

using namespace std;

ll n,m,ans=0;
///                     f          s.f   s.s
priority_queue < pair < ll , pair < ll , ll > > > pq;


int main()
{
    scll(n,m);
    ll A[n+3][m+3];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)scl(A[i][j]);
    }

    vll v1,v2;
    /// makePQ 1
    priority_queue < pair < ll , pair < ll , ll > > > pq1;
    for (int i=0;i<n;i++){
        ll sum = 0;
        for (int j=0;j<m;j++){
            sum+=A[i][j];
        }
        v1.pb(sum);
        pq1.push({sum,{ 1 , i} });
    }
    rsrt(v1);
    for (int j=0;j<m;j++){
        ll sum = 0;
        for (int i=0;i<n;i++){
            sum+=A[i][j];
        }
        v2.pb(sum);
        pq1.push({ sum , {2,j} });
    }
    rsrt(v2);
    ///**********************

    ll M1 = 0 , M2 = 0;
    for (int i=0;i<4 && i<v1.size();i++)M1 +=v1[i];
    for (int i=0;i<4 && i<v2.size();i++)M2 +=v2[i];

    ///delete pq 1
    if (pq1.top().ss.ff==1){
        int i = pq1.top().ss.ss;
        for (int j=0;j<m;j++){
            ans+=A[i][j];
            A[i][j] = 0;
        }
    }
    else {
        int j = pq1.top().ss.ss;
        for (int i=0;i<n;i++){
            ans+=A[i][j];
            A[i][j] = 0;
        }
    }
    ///**************

    priority_queue < pair < ll , pair < ll , ll > > > pq2;

    ///\\end

    /// makePQ 2
    for (int i=0;i<n;i++){
        ll sum = 0;
        for (int j=0;j<m;j++){
            sum+=A[i][j];
        }
        pq2.push({sum,{ 1 , i} });
    }
    for (int j=0;j<m;j++){
        ll sum = 0;
        for (int i=0;i<n;i++){
            sum+=A[i][j];
        }
        pq2.push({ sum , {2,j} });
    }
    ///**********************

    ///delete pq 2
    if (pq2.top().ss.ff==1){
        int i = pq2.top().ss.ss;
        for (int j=0;j<m;j++){
            ans+=A[i][j];
            A[i][j] = 0;
        }
    }
    else {
        int j = pq2.top().ss.ss;
        for (int i=0;i<n;i++){
            ans+=A[i][j];
            A[i][j] = 0;
        }
    }
    ///**************

    priority_queue < pair < ll , pair < ll , ll > > > pq3;


    /// makePQ 3
    for (int i=0;i<n;i++){
        ll sum = 0;
        for (int j=0;j<m;j++){
            sum+=A[i][j];
        }
        pq3.push({sum,{ 1 , i} });
    }
    for (int j=0;j<m;j++){
        ll sum = 0;
        for (int i=0;i<n;i++){
            sum+=A[i][j];
        }
        pq3.push({ sum , {2,j} });
    }
    ///**********************

    ///delete pq 3
    if (pq3.top().ss.ff==1){
        int i = pq3.top().ss.ss;
        for (int j=0;j<m;j++){
            ans+=A[i][j];
            A[i][j] = 0;
        }
    }
    else {
        int j = pq3.top().ss.ss;
        for (int i=0;i<n;i++){
            ans+=A[i][j];
            A[i][j] = 0;
        }
    }
    ///**************

    priority_queue < pair < ll , pair < ll , ll > > > pq4;

    /// makePQ 4
    for (int i=0;i<n;i++){
        ll sum = 0;
        for (int j=0;j<m;j++){
            sum+=A[i][j];
        }
        pq4.push({sum,{ 1 , i} });
    }
    for (int j=0;j<m;j++){
        ll sum = 0;
        for (int i=0;i<n;i++){
            sum+=A[i][j];
        }
        pq4.push({ sum , {2,j} });
    }
    ///**********************

    ///delete pq 4
    if (pq4.top().ss.ff==1){
        int i = pq4.top().ss.ss;
        for (int j=0;j<m;j++){
            ans+=A[i][j];
            A[i][j] = 0;
        }
    }
    else {
        int j = pq4.top().ss.ss;
        for (int i=0;i<n;i++){
            ans+=A[i][j];
            A[i][j] = 0;
        }
    }
    ///**************
    //cout << M1 << "  " << M2 << endl;
    cout << max(ans,max(M1,M2)) << endl;


    return 0;
}
