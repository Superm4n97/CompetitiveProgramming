#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
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
#define pll             pair < ll , ll >
#define mk              make_pair
#define inf8            100000008
#define maxn            100005
#define maxX            10000007

using namespace std;

string s;
ll Div[10000007];
ll NODE[maxn][30];

void makeTree(ll b, ll e, ll node)
{

}

void update(ll b, ll e , char val)
{

}

int main()
{
    memset(Div,-1,sizeof(Div));

    for (int i=2;i<maxX;i++){
        if (Div[i]==-1){
            Div[i] = i;

            for (int j = i*i ; j<maxX;j+=i){
                if (Div[j]==-1)Div[j] = i;
            }
        }
    }

    cin >> s;
    ll q;
    scl(q);

    //makeTree()

    for (int i=0;i<q;i++){
        string tt;
        cin >> tt;
        if (tt=="Update"){
            ll x;
            scl(x);
            char ch ;
            scanf("%c",&ch);

            ll d = Div[x];
            ll temp = d;
            while(d<=n){
                update(d,ch);
                d *= temp;
            }
        }
        else {

        }
    }


    return 0;
}
