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

int n,m,answer=0,cnt=0;
map < string , int > mp;
bool ans = false;
string s;

void bfs()
{
    queue < string > q;
    q.push(s);
    mp[s] = 1;

    while(!q.empty()){
        string ss = q.front();
        q.pop();
        cnt++;
        answer+=n-ss.size();
        if (cnt==m){
            ans = true;
            return;
        }

        for (int i=0;i<ss.size();i++){
            string s1 = ss.substr(0,i) , s2 = ss.substr(i+1,(n-i-1));
            string sss = s1+s2;
            if (mp[sss]==0){
                q.push(sss);
                mp[sss]=1;
            }
        }
    }
}

int main()
{
    cin >> n >>m;
    cin >> s;
    bfs();
    if (ans)cout << answer << endl;
    else cout << -1 << endl;

    return 0;
}

