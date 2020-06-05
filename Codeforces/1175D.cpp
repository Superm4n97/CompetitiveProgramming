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

ll n,k;
ll A[300005];
ll ind , ans = 0;

void fun(ll numberOfSequence , ll index)
{
    //cout << "   ok 1" << endl;
    ll value = 0;
    if (numberOfSequence==1){
        for (int i=index ; i>=1;i--)value+=A[i];
    }
    else {
        ll mx = A[index] , cnt = 0;
        ind  = index-1;
        for (int i=index ; i>=numberOfSequence ; i--){
            cnt+=A[i];
            //cout << "       cnt " << cnt << "  numberofse " << numberOfSequence <<endl;
            if (cnt>mx){
                cnt = mx ;
                ind = i-1;
            }
        }
        for (int i=index;i>ind;i--)value+=(A[i]*numberOfSequence);
    }
    ans+=value;
}

int main()
{
    scll(n,k);
    for (int i=1;i<=n;i++)scl(A[i]);

    ind = n;
    for (int i=0;i<k;i++){
        //cout << "  " << ind << endl;
        fun(k-i , ind);
    }
    cout << ans << endl;

    return 0;
}
