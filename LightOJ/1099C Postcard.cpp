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
    int n,k,cnt=0;
    string s,ss="";
    cin >> s;
    cin >> k;
    n=s.size();
    s+='&';
    for (int i=0;i<n;i++){
        if (s[i]>='a' && s[i]<='z')cnt++;
    }
    //cout << cnt  << "   " << k << endl;
    for (int i=0;i<n;i++){
        if (s[i]=='?'){
            if (k>=cnt){
                ss+=s[i-1];
                //cout << s[i-1] << " " << k << " " << cnt << endl;
            }
            else {
                cnt--;
            }
        }
        else if (s[i]=='*'){
            if (k>cnt){
                ss+=s[i-1];
                while(k>cnt){
                    ss+=s[i-1];
                    cnt++;
                }
            }
            else if (k<cnt)cnt--;
            else ss+=s[i-1];
        }
        else if (s[i+1]!='?' && s[i+1]!='*') ss+=s[i];
    }
    if (ss.size()!=k)cout << "Impossible" << endl;
    else
        cout << ss << endl;

    return 0;
}
