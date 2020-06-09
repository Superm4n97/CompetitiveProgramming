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
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf8            100000008

#define maxn            100005

using namespace std;

ll n , ans = 0;
ll  A[maxn];
vector < ll > MX,MN;
int main()
{
    cin >> n ;
    ll rem = n-1;
    for (int i=0;i<n;i++){
        ll t;
        vll v , v2;
        cin >> t;
        ll mn = inf8 , mx = -1;
        for (int j=0;j<t;j++){
            ll a;
            cin >> a;
            v.pb(a);
            v2.pb(a);
            mn = min(a,mn);
            mx = max(a,mx);
        }
        rsrt(v2);

//        for (int j=0;j<t;j++)cout << v[j]<< " ";
//            cout << endl;
//            for (int j=0;j<t;j++)cout << v2[j]<< " ";
//            cout << endl;

        if (v==v2){
            A[i] = 1;



//            show(i);

        }
        else {
            ans+=2*rem+1;
            rem--;
            A[i] = 0;
        }
        if (A[i]){
            MN.pb(mn);
            MX.pb(mx);
        }
    }

//    show(ans);

    srt(MN);

    for (int i=0;i<MX.size();i++){


            ll b  = 0 , e = MN.size()-1 , ind = -1;

            while(b<=e){
                ll mid = (b+e)/2;
                if (MN[mid]<MX[i]){
                    ind = max(ind,mid);
                    b = mid+1;
                }
                else e = mid-1;
            }
//
//            show(i);
//            show(ind);

            ans += (ind+1);

    }
    cout << ans << endl;


    return 0;
}

