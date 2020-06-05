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

string ss= "021";

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map < char , int > mp;
    for (int i=0;i<n;i++){
        mp[s[i]]++;
    }

    int temp = n/3;

    for (int k=0;k<3;k++){
        char j = ss[k];
        if (mp[j]<temp){
            for (int i=0;i<n;i++){
                if (mp[s[i]]>temp && s[i]>j){
                    mp[s[i]]--;
                    s[i]=j;
                    mp[j]++;
                }
                if (mp[j]==temp)break;
            }
        }
        if (mp[j]<temp){
            for (int i=n-1;i>=0;i--){
                if (mp[s[i]]>temp){
                    mp[s[i]]--;
                    s[i]=j;
                    mp[j]++;
                }
                if (mp[j]==temp)break;
            }
        }
    }
    cout << s << endl;

    return 0;
}
