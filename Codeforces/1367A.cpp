#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            string s;
            cin >> s;
            cout << s[0];
            for (int i=1 ; i<s.size()-1 ; i+=2)cout << s[i];
            cout << s[s.size()-1] << endl;
      }

      return 0;
}
