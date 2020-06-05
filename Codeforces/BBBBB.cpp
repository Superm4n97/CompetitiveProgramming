#include <bits/stdc++.h>
#define ll long long unsigned
using namespace std;
int main()
{
    ll x, y, gcd, mul;
    cin >>  x >> y;
    gcd = __gcd(x, y);
    x /= gcd;
    y /= gcd;
    if(x % 2 == 0 || y%2 == 0){
        cout << 0 << endl;
    }
    else{
        cout << gcd << endl;
    }

    return 0;
}
