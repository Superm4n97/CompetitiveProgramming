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

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        ll n;
        scl(n);
        ll A[n+5];
        ll r,p,ss;
        cin >> r >> p >> ss;
        string s;
        cin >> s;
        queue < ll > R,P,S;
        for (int i=0;i<n;i++){
            if (s[i]=='R')R.push(i);
            else if (s[i]=='P')P.push(i);
            else S.push(i);
        }
        for (int i=0;i<n;i++)s[i] = '*';

        ll win = 0;
        while(!R.empty()){
            if (p==0)break;
            ll temp = R.front();
            R.pop();
            s[temp] = 'P';
            p--;
            win++;
        }
        while(!P.empty()){
            if (ss==0)break;
            ll temp = P.front();
            //show(temp);
            P.pop();
            s[temp] = 'S';
            //cout << s << endl;
            ss--;
            win++;
        }
        while(!S.empty()){
            if (r==0)break;
            ll temp = S.front();
            S.pop();
            s[temp] = 'R';
            r--;
            win++;
        }
        //cout << s << endl;
        for (int i=0;i<n;i++){
            if (s[i]=='*'){
                if (ss){
                    s[i] = 'S';
                    ss--;
                }
                else if (p){
                    s[i] = 'P';
                    p--;
                }
                else {
                    s[i] = 'R';
                    r--;
                }
            }
        }
        ll temp = n/2;
        if(n%2)temp++;
        if (win>=temp){
            cout << "YES" << endl;
            cout << s << endl;
        }
        else cout << "NO" << endl;
    }



    return 0;
}
