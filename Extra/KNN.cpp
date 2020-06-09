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

int X[100] , Y[100];
map < pii , int > mp;

int main()
{
    cout << "Insert the number of point: " ;
    int n,k;
    cin >> n;
    cout << "Input K: ";
    cin >> k;

    for (int i=1;i<=n;i++){
        cin >> X[i] >> Y[i];
        string s;
        cin >> s;
        int a;
        if (s=="yes")a = 2;
        else a = 1;
        mp[mk(X[i],Y[i])] = a;
    }
    cout << "Input number of new data: ";
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        int yes = 0, no = 0;

        for (int i=1;i<=n;i++){
            int dis = sqrt((X[i]-a)*(X[i]-a) + (Y[i]-b)*(Y[i]-b));
            if (dis<=k){
                if (mp[mk(X[i],Y[i])]==1)no++;
                else yes++;
            }

        }
       // cout << "        " << yes << " "<< no << endl;
        if (yes==no)cout << "OUTPUT NOT FOUND!!!!!" << endl;
        else {
            n++;
            X[n] = a , Y[n] = b;
            if (yes>no){
                cout << "RESULT IS YES!!" << endl;
                mp[mk(a,b)] = 2;
            }
            else {
                cout << "RESULT IS NO!!" << endl;
                mp[mk(a,b)] = 1;
            }
        }
    }

    return 0;
}

