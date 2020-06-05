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

int main()
{
    int n,k;
    cin >> n >> k;
    vii v;
    map < int , int > mp;
    for (int i=0;i<n;i++){
        int a;
        cin >> a ;
        v.pb(a);
        mp[a]++;
    }
    for (int i=0;i<n;i++){
        if (mp[v[i]]>k || n<k){
            cout << "NO" << endl;
            return 0 ;
        }
    }
    queue < int > q;
    for (int i=k;i>1;i--)q.push(i);

    cout << "YES" << endl;
    for (int i=0;i<n;i++){
        v[i] = mp[v[i]];
        mp[v[i]]--;
    }
    mp.clear();
    for (int i=0;i<n;i++){
        mp[v[i]]=1;
    }
    for (int i=0;i<n;i++){
        if (v[i]==1 && mp[v[i]] && !q.empty()){
            v[i]=q.front();
            q.pop();
            mp[v[i]]=0;
        }
        else {
            mp[v[i]]=0;
        }
    }
    for (int i=0;i<n;i++)cout << v[i] << " ";
    cout << endl;

    return 0;
}
