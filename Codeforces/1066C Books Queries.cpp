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
    char ch;
    int a,n;
    cin >> n;
    cin >> ch >> a;
    map < int , int > mp;
    int left=0,right=0;
    mp[a]=0;
    for (int i=1;i<n;i++){
        cin >> ch >> a;
        if (ch=='L'){
            left--;
            mp[a]=left;
        }
        else if (ch=='R'){
            right++;
            mp[a]=right;
        }
        else {
            //cout << left << " " << right << endl;
            int x = abs(mp[a]-left) , y = abs(mp[a]-right);
            cout << min(x,y) << endl;
        }
    }

    return 0;
}
