#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define ull             unsigned long long
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

vector < string > vs;
int mn = 3e6,ans;

int main()
{
    string s="";
    for (int i=0;i<66668;i++)s+="RGB";
    vs.pb(s),s="";

    for (int i=0;i<66668;i++)s+="RBG";
    vs.pb(s),s="";

    for (int i=0;i<66668;i++)s+="GRB";
    vs.pb(s),s="";

    for (int i=0;i<66668;i++)s+="GBR";
    vs.pb(s),s="";

    for (int i=0;i<66668;i++)s+="BRG";
    vs.pb(s),s="";

    for (int i=0;i<66668;i++)s+="BGR";
    vs.pb(s),s="";

    int n;
    cin >> n;
    cin >> s;

    for (int i=0;i<6;i++){
        int cnt=0;
        for (int j=0;j<n;j++){
            if (s[j] != vs[i][j])cnt++;
        }
        if (cnt<mn){
            mn = cnt;
            ans = i;
        }
    }
    cout << mn << endl;
    for (int i=0;i<n;i++)cout << vs[ans][i];
    cout << endl;

    return 0;
}
