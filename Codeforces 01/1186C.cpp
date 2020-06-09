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

int main()
{
    int n1=0,n2=0 , ans = 0;
    string s1,s2;
    cin >> s1 >> s2;
    for (int i=0;i<s2.size();i++){
        if (s2[i]=='1')n2++;
    }
    for (int i=0;i<s1.size();i++){
        if (i>=s2.size()-1){
            if (s1[i]=='1')n1++;
            if (i>=s2.size() && s1[(i-s2.size())]=='1')n1--;
            if (n1%2 == n2%2)ans++;
        }
        else{
            if (s1[i]=='1')n1++;
        }
    }
    cout << ans << endl;

    return 0;
}

