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
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair

using namespace std;

string s;
int a[1000000],b[1000000];
map < char , int > mp;

int main()
{
    int n;
    cin >> n;
    cin >> s;
    ll temp = 0;
    for (int i=0;i<n;i++){
        mp[s[i]]++;
        if (s[i]=='G')temp++;
        else {
            a[i]=temp;
            temp = 0;
        }
    }
    temp = 0;
    for (int i=n-1;i>=0;i--){
        if (s[i]=='G')temp++;
        else b[i]=temp , temp = 0;
    }
    int ans = 0;
    for (int i=0;i<n;i++){
        ans = max(ans,a[i]+b[i]+1);
    }
    if (mp['S']==0){
        cout << n << endl;
        return 0;
    }
    if (ans>mp['G'])ans--;
    cout << ans << endl;

    return 0;
}
