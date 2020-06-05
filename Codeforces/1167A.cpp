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

ll P[1000006] , M[1000006];

ll findParent(ll a)
{
    //cout << "Find Parent " << a << endl;
    if (P[a]==a)return a;
    return P[a] = findParent(P[a]);
}

void makeParent(ll a, ll b)
{
    //cout << "make Parent" << endl;
    ll p1 = findParent(a);
    ll p2 = findParent(b);
    if (p1 == p2)return;

    P[p2] = p1;
    M[p1]+=M[p2];
    return;
}

int main()
{
    ll n,m;
    cin >> n >> m;
    for (int i=0;i<=n+2;i++)P[i] = i , M[i] = 1;
    for (int ii=0;ii<m;ii++){
        ll nn;
        cin >> nn;
        ll node = -1;
        for (int i=0;i<nn;i++){
            ll a;
            cin >> a;
            if (i==0)node = a;
            else {
                makeParent(node,a);
            }
            //for (int i=1;i<=n;i++)cout << P[i] << " ";cout << endl;
        }
    }
    for (int i=1;i<=n;i++){
        ll p1 = findParent(i);
        cout << M[p1] << " ";
    }
    cout << endl;

    return 0;
}
