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
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf             10000000

using namespace std;

int S[100002][25];
int A[100002],n,lg=0;

void makeSparseTable()
{
    for (int i=0;(1<<i)<=n;i++)S[n+1][i]=inf;
    for (int i=1;i<=n;i++)S[i][0] = min(A[i],A[i+1]);
    for (int j=1;(1<<j)<=n;j++){
        for (int i=1;i<=n;i++)
            S[i][j] = min(S[i][j-1],S[i+1][j-1]);
    }
}

int query(int a, int b)
{
    int mn = inf;
    if (a>b)swap(a,b);
    for (int i=lg ;i>=0;i--){
        //cout << "K";
        if (a+(1<<i) <= b){
            mn = min(S[a][i],mn);
            a+=(1<<i);
        }
    }
    return mn;
}

int main()
{
    int tc;
    //cin >> tc;
    scd(tc);
    for (int _t=1;_t<=tc;_t++){
        int q;
        //cin >> n >> q;
        scdd(n,q);

        while(1){
            if ((1<<lg)>n)break;
            lg++;
        }

//        for (int i=0;i<=n+1;i++){
//            for (int j=0;j<25;j++)S[i][j]=inf;
//        }

        for (int i=1;i<=n;i++)//cin >> A[i];
            scd(A[i]);
        A[n+1]=inf;
        makeSparseTable();
//        for (int i=1;i<=n;i++){
//            for (int j=0;j<4;j++)cout << S[i][j] << " ";
//            cout << endl;
//        }
        //cout << "Case " << _t << ":" << endl;
        printf("Case %d:\n",_t);
        while(q--){
            int a,b;
            cin >> a >> b;
            if (a==b)//cout << A[a] << endl;
                printf("%d\n",A[a]);
            else //cout << query(a,b) << endl;
                printf("%d\n",query(a,b));
        }
    }

    return 0;
}
