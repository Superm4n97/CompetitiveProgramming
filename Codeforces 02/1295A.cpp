#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        ll n;
        cin >> n;
        if (n%2){
            cout << 7;
            n-=3;
        }
        for (int i=1;i<=n;i+=2)cout << 1;
        cout << endl;
    }



    return 0;
}
