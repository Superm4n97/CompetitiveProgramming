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

int n,l=0,r=0;
string s;

int main()
{
   // while(1){
    cin >> n;
    cin >> s;
    for (int i=0;i<n;i++){
        if (s[i] == '(')l++;
        if (s[i] == ')')r++;
    }
    if (n%2){
        cout << ":(" << endl;
        return 0;
        //continue;///***
    }

    for (int i=0;i<n;i++){
        if (s[i]=='?'){
            if  (l<n/2)s[i]='(' , l++;
            else s[i] = ')' , r++;
        }
    }
    bool ans = true;
    l = 0 , r = 0;
    for (int i=0;i<n-1;i++){
        if(s[i]=='(')l++;
        if (s[i]==')')r++;
        if (r>=l)ans = false;
    }
    //cout << s << endl;
    if (s[n-1]!=')' || s[n-2]!=')')ans = false;
    if (!ans)cout << ":(" << endl;
    else cout << s << endl;
   // }

    return 0;
}
