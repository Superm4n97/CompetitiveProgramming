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
    map < pii , int > mm;
    for (int i=0;i<n;i++){
        int a;
        cin >> a ;
        mp[a]++;
        v.pb(a);
    }
    for (int i=0;i<n;i++){
        if (mp[i]>k || k>n){
            cout << "NO" << endl;
            return 0;
        }
    }
    vii vans;
    for (int i=0;i<n;i++){
        int temp = i+1;
        while(1){
            temp%=k;
            if (temp==0)temp=k;
            if (!mm[mk(v[i],temp)]){
                vans.pb(temp);
                mm[mk(v[i],temp)]=1;
                break;
            }
            temp++;
        }
    }
    cout << "YES" << endl;
    for (int i=0;i<n;i++)cout << vans[i] << " ";

    return 0;
}
