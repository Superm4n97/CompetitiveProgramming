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

int main()
{
    int t;
    cin >> t;
    for (int _t=1;_t<=t;_t++){
        string s;
        ll k,i=0;
        cin >> s >> k;
        ll n = s.size(),temp=0;
        k = abs(k);
        if (s[0]=='-')s = s.substr(1,n-1);
        n=s.size();

        while(1){
            if (i==n)break;
            temp*=10;
            temp+=(s[i]-'0');
            temp%=k;
            //cout << temp << endl;
            i++;
        }
        if (!temp)cout << "Case "<< _t << ": divisible" << endl;
        else cout << "Case "<< _t << ": not divisible" << endl;
    }

    return 0;
}
