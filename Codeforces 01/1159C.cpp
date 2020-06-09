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
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;scl(a);v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf8            100000008

using namespace std;

priority_queue < pair < ll , ll > > pqPair;
priority_queue < ll > pq1 , pq2;

int main()
{
    ll n,m , mx=0;
    scll(n,m);
    bool b = true;
    for (int i=0;i<n;i++){
        ll a;
        scl(a);
        pq1.push(a);
        mx = max(mx,a);
    }
    for (int i=0;i<m;i++){
        ll a;
        scl(a);
        if (a<mx){
            b = false;
            continue;
        }
        if (a==mx)continue;
        pq2.push(a);
    }

    if (!b){
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    while(!pq1.empty()){
        ll u = pq1.top();
        pq1.pop();
        //cout << "1->  " << ans << endl;
        if (pq2.empty()){
            ans+=(u*m);
            //cout << "2->  " << ans << endl;
        }
        else {
            ans+=u;
            for (int i=1;i<m;i++){
                ll v = pq2.top();
                pq2.pop();
                ans+=v;
               // cout << "3->  " << ans << endl;

                if (pq2.empty()){
                    ans+=((m-1-i)*u);
                    //cout << "4->  " << ans << endl;
                    break;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}

