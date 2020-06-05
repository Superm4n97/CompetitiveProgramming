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

map < ll , string > mp;

void make(ll a)
{
    //cout << a << endl;
    ll tut = a;
    string s = "";
    while(a){
        ll b = a%2;
        a/=2;
        char ch = b+'0';
        s=ch+s;
    }
    ll temp = s.size();
    mp[tut-temp] = s;
}

ll con(string s)
{
    ll ans = 0;
    for (int i=0;i<s.size();i++){
        ans*=2;
        ans+=s[i]-'0';
    }
    return ans;
}

int main()
{
    ll tc;
    cin >> tc;
    for (int i=3;i<200000;i++){
        make(i);
    }
    //cout << mp[1] << endl;
    while(tc--){
        string s;
        cin >> s;
        s = "*"+s+"*";
        ll ans = 0;
        ll A[s.size()+5] , n = s.size();
        for (int i=0;i<n;i++)A[i] = 0;
        for (int i=1;i<n-1;i++){
            if (s[i]=='0')A[i] = A[i-1]+1;

            if (s[i]=='1'){
                ans++;
               // if (s[i+1]=='0')ans++;

                for (int j=1;j+i<n;i++){
                    string ss = s.substr(i,j);
                    ll temp = con(ss);
                    cout << temp << " " << A[i] << " "<< j  << " "<<  i << endl;
                    if (temp-j<=A[i-1])ans++;
                    else break;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}

