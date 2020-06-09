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

map < char , int > fst , lst;
vector < string > v;
int ar[400];
map < string , int> mp;

int main()
{
    for (int i=0;i<400;i++)ar[i]=0;
    int n;
    cin >> n;
    char fc,lc;
    for (int i=0;i<n*2-2;i++){
        string s;
        cin >> s;
        v.pb(s);
        int t = s.size()-1;
        fst[s[0]]++;
        lst[s[t]]++;
        if (fst[s[0]]>=n-1)fc=s[0];
        if (lst[s[t]]>=n-1)lc=s[t];
    }
    for (char i='a';i<='z';i++){
        if (lst[i]>=n-1 && i!=fc){lc=i;break;
            //cout << "ok" << endl;
        }
    }
    for (char i='a';i<='z';i++){
        if (fst[i]>=n-1 && i!=lc){fc=i;break;
            //cout << "ok" << endl;
        }
    }

    int cnt =0 ;
    for (int i=0;i<v.size();i++){
        string s = v[i];
        int t = s.size()-1;
        if (s[0]==fc && s[t]!=lc && mp[s]==0){
            ar[i]=1;
            cnt++;
            mp[s]++;
        }
        if (cnt==n-1)break;
    }
    for (int i=0;i<v.size();i++){
        if (cnt==n-1)break;
        string s = v[i];
        int t = s.size()-1;
        if (s[0]==fc && ar[i]==0 && mp[s]==0){
            ar[i]=1;
            cnt++;
            mp[s]++;
        }
    }
    for (int i=0;i<v.size();i++){
        if (ar[i]==0)cout << 'S';
        else cout << 'P';
    }
    cout <<endl;

    return 0;
}
