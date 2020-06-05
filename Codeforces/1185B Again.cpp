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
        bool ans = true;
        string s1,s2;
        cin >> s1 >> s2;
        s1 = "*"+s1+"*";
        s2 = "*"+s2+"*";

        if (s1.size()>s2.size())ans = false;
        ll i = 1 , j = 1;
        for (i=1;i<s1.size()-1;i++){
            bool temp = false;

            while(j<s2.size()-1){
                if (s1[i] == s2[j]){
                    temp = true;
                    j++;
                    break;
                }
                if (s2[j] != s1[i-1])ans = false;
                j++;
            }
            if (!temp)ans = false;
        }
        while(j<s2.size()-1){
            if (s2[j] != s2[j-1])ans = false;
            j++;
        }
        cout << (ans?"YES":"NO") << endl;
    }

    return 0;
}
