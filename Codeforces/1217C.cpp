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
    int tc;
    scd(tc);
    while(tc--){
        string s;
        cin >> s;
        s = "*"+s;
        ll n = s.size() , ans = 0;
        ll A[n+3];
        memset(A,0,sizeof(A));
        for (int i=1;i<n;i++){
            if (s[i]=='0')A[i] = A[i-1]+1;
            else {
                ll val = 0;
                for (ll j=i;j<n;j++){
                    val*=2;
                    val +=s[j] - '0';

                    if (val - (j-i+1) <= A[i-1]){
                        //cout << "  " << val << endl;
                        ans++;

                    }
                    else break;
                }
            }
        }
        cout << ans << endl;
    }


    return 0;
}

