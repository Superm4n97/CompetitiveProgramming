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

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        ll n;
        bool ans = false;
        priority_queue < ll > pq;
        cin >>n;
        for (int i=0;i<n;i++){
            ll a;
            cin >> a;
            pq.push(a*-1);
        }
        while(!pq.empty()){
            ll a = pq.top()*-1;
            //cout << "   " << a << endl;
            pq.pop();
            if (a==2048)ans = true;
            if (pq.empty())break;

            if (a==pq.top()*-1){
                ll b = pq.top()*-1;
                pq.pop();
                pq.push((a+b)*-1);
            }
        }
        cout << (ans?"YES":"NO") << endl;
    }


    return 0;
}

