#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,s;

ll sod(ll a)
{
    ll ans = 0;
    while(a)
    {
        ans += a%10;
        a/=10;
    }
    return ans;
}

int main()
{
    cin >> n >> s;
    ll b = 0, e = n , ans = 0;

    while(b<=e){
        ll mid = (b+e)/2;
        if (mid - sod(mid)<s){
            b = mid+1;
            ans = max(ans,mid);
        }
        else e = mid-1;
    }
    cout << n-ans << endl;


    return 0;
}
