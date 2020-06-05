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
        string s,t,p;
        cin >> s >> t >> p;
        bool ans = true;
        int A[105];
        for (int i=0;i<104;i++)A[i] = 0;

        int j=0;
        for (int i=0;i<s.size();i++){
            bool tut = true;
            for (;j<t.size();j++){
                if (s[i]==t[j] && A[j]==0){
                    A[j] = 1;
                    tut = false;
                    break;
                }
            }
            if (tut){
                ans = false;
                //cout << "   1" << endl;
            }
        }
        map < char , int > mp;
        for (int i=0;i<p.size();i++)mp[p[i]]++;

        for (int i=0;i<t.size();i++){
            if (A[i]==0){
                if (mp[t[i]]==0){
                    ans = false;
                    //cout << "    " << s[i] << endl;
                }
                else mp[t[i]]--;
            }
        }
        if (ans)cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
