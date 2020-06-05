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
    int tc;
    cin >> tc;
    while(tc--){
        vii v;
        int n , x[100005],y[100005];
        cin >> n;
        map < int , int > mp ,mp_check;
        for (int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            x[i]=a,y[i]=b;
            if (mp_check[a]==0)v.pb(a);
            mp_check[a]=1;
            mp[a]=max(mp[a],b);
        }
        srt(v);
        int temp = mp[v[0]] , tut = -1;
        for (int i=0;i<v.size();i++){
            int a = v[i];
            if (temp<a){
                tut=a;
                break;
            }
            temp = max(temp,mp[a]);
        }
        //cout << "  " << tut << endl;
        if (tut==-1){
            cout << -1 << endl;
            continue;
        }
        for (int i=0;i<n;i++){
            if (x[i]<tut)cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << endl;
    }

    return 0;
}
