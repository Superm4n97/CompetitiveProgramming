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

ll A[100005][4] , n;

int main()
{
    scl(n);
    for (int i=0;i<n;i++)scl(A[i][0]);
    for (int i=0;i<n;i++)scl(A[i][1]);

    priority_queue < ll > pq;
    pq.push(A[0][0]);
    pq.push(A[0][1]);
    ll ans = max(A[0][0] , A[0][1]);

    for (int i=1;i<n;i++){
//
//        for (int i=0;i<n;i++)cout << A[i][0]  << " ";
//        cout << endl;
//
//        for (int i=0;i<n;i++)cout << A[i][1]  << " ";
//        cout << endl;
        cout << endl;


        ll a = 0 , b = 0;
        if (pq.top()==A[i-1][0]){
            a = pq.top();
            pq.pop();
            A[i][0] += pq.top();
            pq.push(a);
        }
        else {
            A[i][0] += pq.top();
        }

        if (pq.top()==A[i-1][1]){
            b = pq.top();
            pq.pop();
            A[i][1] += pq.top();
            pq.push(b);
        }
        else {
            A[i][1] += pq.top();
        }
        pq.push(A[i][0]);
        pq.push(A[i][1]);
    }
    cout << pq.top() << endl;

    return 0;
}

