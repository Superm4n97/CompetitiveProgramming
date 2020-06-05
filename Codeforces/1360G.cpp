#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl

using namespace std;

/*
3 3 2 2
110
011
101

6 9 3 2       (3)        (6)
100100100  111000000  111000000
010010010  000111000  000000111
001001001  000000111  000111000
100100100  111000000  111000000
010010010  000111000  000000111
001001001  000000111  000111000

5 3 3 5
111
111
111
111

l = n*m / g(n,m)
d = l/n;

*/

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            int n,m,a,b;
            cin >> n >> m >> a >> b;

            if (n*a != m*b)cout << "NO" << endl;
            else {
                  int l = n*m / __gcd(n,m);
                  int d = l / n;

                  int tut = 0;

                  cout << "YES" << endl;
                  for (int i=0 ; i<n ; i++){
                        tut+=d;
                        tut%=m;

                        int temp = -1;
                        if (tut+a>=m)temp = tut+a - m;

                        for (int j=0;  j<m; j++){
                              if (j>=tut && j<tut+a || j<temp)cout << 1;
                              else cout << 0;
                        }
                        cout << endl;
                  }
            }
      }

      return 0;
}
