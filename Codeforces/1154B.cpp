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
    cin >> n;
    set < int > st;
    map < int , int > mp;
    vii v;
    for (int i=0;i<n;i++) {
        int a;
        cin >> a ;
        mp[a]++;
        st.insert(a);
        v.pb(a);
    }
    srt(v);
    if (st.size()==1){
        cout << 0 << endl;
        return 0;
    }
    if (st.size()==2){
        if ((v[n-1]+v[0])%2==0)
        cout << (v[n-1] - v[0])/2 << endl;
        else cout << v[n-1] -v[0] << endl;
        return 0;
    }
    if (st.size()==3 && mp[(v[0]+v[n-1])/2] && ((v[0]+v[n-1]))%2==0){
           // cout << v[0] << " " << v[n-1] << endl;
        cout << v[n-1]-((v[0]+v[n-1])/2) << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}
