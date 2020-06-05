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
    int n;
    cin >> n;
    vii v;
    input(v,n);
    int mn = 100000000,cnt,index;
    for (int j=1;j<=105;j++){
        int cnt=0;
        for (int i=0;i<n;i++){
            int temp=0;
            if (v[i]<j)temp=j-1-v[i];
            else if (v[i]>j )temp = v[i]-1-j;
            cnt+=temp;
        }
        if (cnt<mn){
            mn=cnt;
            index = j;
        }
    }
    cout << index << " " << mn<< endl;

    return 0;
}
