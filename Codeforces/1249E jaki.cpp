#include<bits/stdc++.h>
#define ll long long int
#define srt(v) sort(v.begin(),v.end())
#define scf2(a,b) scanf("%lld%lld",&a,&b)
#define scf(a) scanf("%lld",&a)
#define pb push_back
using namespace std;

ll n,k;
ll arr[200005][3];

ll a[200005] , b[200005];

ll dp(ll i , ll wh , ll ag , ll value)
{
        if(i==1)return min(a[1],b[1]+k);
    cout << i << endl;
    if(arr[i][wh]!=-1)return arr[i][wh];
    if(wh == 1 )
    {
        ll res=min(dp(i-1 , 1 , ag , value+a[i]) , dp(i-1 , 2 , ag, value + a[i]));
        return arr[i][wh]= res;
    }
    else
    {
        if(ag==1)
        {
            ll res1 = min( dp (i - 1, 1 , ag, value + a[i] + k) , dp (i - 1, 2 , ag, value + a[i] + k));
            ll res2 =min(dp(i - 1 , 1 , ag , value + a[i]) ,dp (i - 1, 2 , ag, value + a[i] ) );
            return arr[i][wh]= min(res1 , res2);
        }
    }
}


int main()
{
    scf2(n,k);
    n=n-1;

    memset(arr , -1 , sizeof(arr));
    for(ll i=1;i<=n;i++)scf(a[i]);

    for(ll i=1;i<=n;i++)scf(b[i]);

    dp(n , 1 , 1 , 0);
    dp(n , 2 , 1 , 0);
    dp(n , 1 , 2 , 0);
    dp(n , 2 , 2 , 0);

    cout << 0 << " ";

    for(ll i=2;i<=n+1;i++)
    {
        cout << min(arr[i][1] , arr[i][2]) << " ";
    }
}
