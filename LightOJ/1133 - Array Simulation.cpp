#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define ull             unsigned long long
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
    for (int t=1;t<=tc;t++){
        int n,m;
        cin >> n >> m;
        vii v;
        input(v,n);

        for (int j=0;j<m;j++){
            char ch;
            cin >> ch;

            if (ch=='S'){
                int d;
                cin >> d;
                for (int i=0;i<n;i++)v[i]+=d;
            }
            else if (ch=='M'){
                int d;
                cin >> d;
                for (int i=0;i<n;i++)v[i]*=d;
            }
            else if (ch=='D'){
                int d;
                cin >> d;
                for (int i=0;i<n;i++)v[i]/=d;
            }
            else if (ch=='R')reverse(v.begin(),v.end());
            else if (ch=='P'){
                int a,b;
                cin >> a >> b;
                swap(v[a],v[b]);
            }
        }

        cout << "Case "<< t<<":" << endl;
        for (int i=0;i<n;i++){
            cout << v[i];
            if (i==n-1)break;
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
