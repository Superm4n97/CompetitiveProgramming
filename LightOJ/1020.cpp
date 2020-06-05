#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    for (int _t = 1 ; _t<=tc; _t++){
        ll n;
        string s;
        cin >> n >> s;
        if (s=="Alice"){
            if ((n-1)%3==0)cout << "Case "<< _t<< ": Bob" << endl;
            else cout << "Case "<< _t<< ": Alice" << endl;
        }
        else {
            if (n%3==0)cout << "Case "<< _t<< ": Alice" << endl;
            else cout << "Case "<< _t<< ": Bob" << endl;
        }
    }


    return 0;
}
