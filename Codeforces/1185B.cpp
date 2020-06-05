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
    int n;
    cin  >> n;
    while(n--){
        string s1,s2,s3="",s4="";
        cin >> s1 >> s2 ;

        s1 = "*"+s1+"*";
        s2 = "*"+s2+"*";

        bool temp = true;
        int i = 1 , j = 1;
        while(i<s1.size()-1 || j<s2.size()-1){
            if (s1[i]==s2[j]){
                s3+=s2[j];
                i++, j++;
            }
            else {
                if (s2[j]!=s1[i-1])temp = false;
                j++;
            }
        }
        if (!temp || s1!=s3)cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}
