#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf8            1000000000008
#define printCaseAnsInt(t,ans)  printf("Case %d: %d",t,ans)
#define printCaseAnsLL(t,ans)  printf("Case %lld: %lld",t,ans)

using namespace std;

ll n,m,l,r,ans=0;
vll A,B;

int main()
{
    scll(n,m);
    for (int i=0;i<n;i++){
        ll a;
        scl(a);
        A.pb(a);
    }
    for (int i=0;i<m;i++){
        ll a;
        scl(a);
        B.pb(a);
    }
    srt(B);
    scll(l,r);
    for (int i=0;i<n;i++){
        ll a = A[i];

        /// ************
        ll b = 0 , e = m-1, left = inf8 , right = -1;
        while(b<=e){
            ll mid = (b+e)/2;
            //cout << "  " << mid << endl;
            if (B[mid]+a>=l){
                e = mid-1;
                left = min(left , mid);
            }
            else b = mid+1;
        }
        b = 0 , e = m-1;
        while(b<=e){
            ll mid = (b+e)/2;
            if (B[mid]+a <= r){
                b = mid+1;
                right = max(right,mid);
            }
            else e = mid-1;
        }
        //cout << "   " << a << " " << right << " " << left << endl;
        ans+= max(0LL,right-left+1);
    }
    cout << ans << endl;

    return 0;
}

