#define pb push_back
#define ff first
#define ss second
#define ll long long int
#define maxn 2000005
#define mod 10000007
#include <bits/stdc++.h>
#define inf 10000000000013
using namespace std;

ll A[maxn];
ll n, sum =0 , mx = -100000000000000 , len = 0;

int main()
{

    cin >> n;
    ll cnt = 0;
    for (int i=1;i<=n;i++){
        cin >> A[i];
        mx = max(mx,A[i]);
        if (A[i-1]>0) A[i] += A[i-1];
        if (A[i]<=0)cnt = 0;
        else cnt++;
        if (sum<=A[i]){
            if (sum==A[i])len = min(cnt,len);
            else len = cnt;
            sum =  A[i];
        }
    }
    //cout << "sum : " << sum << endl;
    if (mx<0)cout << 0 << endl;
    else {
        cout << mx << endl;
//        double res = (double)sum/(double)len*1.0;
//        cout << setprecision(20) << res << endl;
    }

    return 0;
}
