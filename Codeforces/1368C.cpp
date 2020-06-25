#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;

      cout << n*3+4 << endl;
      for (int i=0 ; i<=n;i++){
            cout << i << " " << i << endl;
            cout << i+1 << " " << i << endl;
            cout << i << " " << i+1 << endl;
      }
      cout << n+1 << " " << n+1 << endl;
}
