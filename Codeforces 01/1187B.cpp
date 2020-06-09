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

string s;
int A[28][200005];

int main()
{
    int n;
    cin >> n;
    cin >> s;
    map < char , int > mm;
    for (int i=0;i<n;i++){
        mm[s[i]]++;
        int t = s[i]-'a';
        A[t][mm[s[i]]] = i+1;
    }

    int tc;
    cin >> tc;
    while(tc--){
        string ss;
        cin >> ss;
        map < char , int >mp;
        for (int i=0;i<ss.size();i++){
            mp[ss[i]]++;
        }
        int ans = 0 , tut = ss.size();

        for (int i=0;i<28;i++){
            ans = max(ans,A[i][mp[i+'a']]);
        }

        cout << ans << endl;
    }

    return 0;
}

