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

int ar[500];
vector < string > v,vs;
string s;
map < char , int > fst , lst;

void fun(int n)
{
    for (int i=0;i<v.size();i++){
        if (vs[i]==v[n] && ar[i]==0){
            ar[i]=1;
            return;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int lm = n*2-2;
    char fc,lc;
    for (int i=0;i<lm;i++){
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
        }
    }
    for (char i='a';i<='z';i++){
        if (fst[i]>=n-1 && i!=lc){fc=i;break;
        }
    }
    vs = v;
    srt(v);
    for (int i=0;i<v.size();i+=2){
        string ss = v[i];
        string st = v[i+1];
        int t= s.size()-1;
        if (ss[0]==fc && ss[t]!=lc)fun(i);
        else (st[0]==fc && st[t]!=lc)fun(i+1);
    }
    for (int i=0;i<v.size();i++){
        if (ar[i]==0)cout << 'S';
        else cout << 'P';
    }
    cout <<endl;

    return 0;
}
