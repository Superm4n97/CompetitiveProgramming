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

int main()
{
    int n,k,mx=0;
    string s;
    cin >> n >> k;
    cin >> s;
    map < char , int > mp;
    for (int i=0;i<n;i++){
            //cout << i << "    " << "ok" << endl;
        bool x=true;
        for (int j=i+1;j-i<k;j++){
            //cout << j << endl;
            if (s[i]!=s[j]){
                i=j-1;
                x=false;
                break;
            }
            if (j-i==k-1){
                i=j;
                break;
            }
        }
        if (x){
       // cout << s[i] << "  " << i << endl;
            mp[s[i-1]]++;
            mx = max(mp[s[i-1]],mx);
        }
    }
    cout << mx << endl;

    return 0;
}
