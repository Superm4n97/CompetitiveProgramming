#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,a,b,p,q;
ll sum = 0;
int main()
{
    cin >> n >> a >> b >> p >> q ;
    sum+=(n/a)*p + (n/b)*q;
    ll lcm = (a*b / __gcd(a,b));
    sum-=(n/lcm)*min(p,q);
    cout << sum << endl;
}
