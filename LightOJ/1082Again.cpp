#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl;
#define ll long long int
#define pb push_back
#define maxn 100005
#define inf 1000000000000;

using namespace std;

ll n,q;
ll A[maxn] , S[maxn][30];

int main()
{
    int tc;
    cin >> tc;

    for (int _t=1 ; _t<=tc ; _t++){
        scanf("%lld %lld",&n,&q);
        for (int i=1;i<=n;i++)cin >> A[i];

        A[0]=A[n+1]=inf;

        for (int i=0;i<maxn;i++){
            for (int j=0;j<29;j++)S[i][j] = inf;
        }

        for (int i=1;i<=n;i++)S[i][0] = A[i];

        for (int j=0;j<28;j++){
            for (int i=1;i<=n;i++){
                S[i][j+1] = min(S)
            }
        }
    }


    return 0;
}
