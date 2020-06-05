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
    string s;
    cin >> s;
    int n= s.size();
    int x=0,y=0,index1=n,index2=0;

    for (int i=0;i<n;i++){
        if (s[i]=='[')x=1;
        if (s[i]==':' && x){
            index1=i;
            break;
        }
    }
    for (int i=n-1;i>=0;i--){
        if (s[i]==']')y=1;
        if (s[i]==':' && y){
            index2 = i;
            break;
        }
    }
    if (index1>=index2){
        cout  << -1 << endl;
        return 0;
    }
    int cnt=0;
    for (int i=index1;i<=index2;i++){
        if (s[i]=='|')cnt++;
    }
    cout << cnt+4 << endl;

    return 0;
}
