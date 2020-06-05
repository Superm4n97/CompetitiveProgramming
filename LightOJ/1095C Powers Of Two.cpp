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

ll A[61];

int main()
{
    for (int i=0;i<=60;i++)A[i]=0;
    ll n,k;
    cin >> n >> k;
    ll a = n, cnt =0;
    //cout << a << endl;
    for (int i=30;i>=0;i--){
        ll tut = (1<<i);
        //cout << "tut " << tut <<endl;
        if (tut<=a){
            A[i]=1;
            cnt++;
            a-=tut;
        }
    }
    //for (int i=0;i<30;i++)cout << i << " " << A[i] << endl;
    if (k<cnt || k>n){
        cout << "NO" << endl;
        return 0;
    }

    for (ll i=30;i>=0;i--){
        if (cnt==k)break;
        if (A[i]!=0){
           // cout << A[i] << " " << cnt << endl;
            if (A[i]*2 + (cnt-A[i]) <= k ){
                A[i-1]+= A[i]*2;
                cnt = A[i]*2 + (cnt-A[i]);
                A[i]=0;
            }
            else {
                ll temp = k-cnt;
                A[i]-=temp;
                A[i-1]+=temp*2;
                cnt = k;
            }
        }
    }
    cout << "YES" << endl;
    for (ll j=0;j<=30;j++){
        for (ll i=0;i<A[j];i++){
            cout << (1<<j) << " ";
        }
    }
    cout << endl;

    return 0;
}
