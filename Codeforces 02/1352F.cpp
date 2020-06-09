#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

/*
0 1 2
2 5 2
1110101000

2 4 2
111010001
*/

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll a , b , c;
            cin >> a >> b >> c;

            if (c>0) for (int i=0;i<=c ; i++)cout << 1;

            if (b){
                  if (c==0)b++;
                  if (b%2){
                        for (int i=1 ; i<b;i++){
                              if (i%2)cout << 0 ;
                              else cout << 1;
                        }
                        if (a==0)cout << 0;
                        else {
                              for (int i=0;i<=a ; i++)cout << 0;
                        }
                  }
                  else {
                        if (a==0){
                              for (int i=1;i<=b ; i++){
                                    if (i%2)cout << 0;
                                    else cout << 1;
                              }
                        }
                        else {
                              /*
                              1 2 1
                              11001
                              */
                              for (int i=1 ; i<b-1 ; i++){
                                    if (i%2)cout << 0;
                                    else cout << 1;
                              }
                              for (int i=0 ; i<=a ; i++)cout << 0;
                              cout << 1;
                        }
                  }
            }
            else {
                  if (a){
                        for (int i=0 ; i<=a ; i++)cout << 0;
                  }
            }
            cout << endl;
      }

      return 0;
}
