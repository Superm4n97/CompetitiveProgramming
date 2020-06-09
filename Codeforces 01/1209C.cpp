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
    scl(tc);
    while(tc--){
        ll n;
        scl(n);
        ll A[n+4];
        memset(A,0,sizeof(A));

        string s;
        cin >> s;
        char brkPoint = '9' , hi = '9'+1 , lw = '0';
        for (int i=0;i<n-1;i++){
            if (s[i]>s[i+1]){
                hi = min(hi,s[i]);
            }
        }


        string t = "";
        for (int i=0;i<n;i++){
            if (s[i]<hi)t+=s[i];
        }
        for (int i=0;i<n;i++){
            if (s[i]>=hi)t+=s[i];
        }

        cout << "   " << t << endl;

        string y = t;
        sort(t.begin(),t.end());
        if (t!=y){

            cout << "-" << endl;
        }
        else{
            for (int i=0;i<n;i++){
                if (s[i]<hi)cout << 1 ;
                else cout << 2 ;
            }
        }
        cout << endl;
    }

    return 0;
}
