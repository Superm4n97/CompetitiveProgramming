#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;

            if (n<3){
                  if (n==1)cout << "FastestFinger" << endl;
                  else cout << "Ashishgup" << endl;
                  continue;
            }
            if (n%2){
                  cout << "Ashishgup"<< endl;
                  continue;
            }

            ll temp = n , two = 0;
            vector < ll > D;

            for (ll i=2 ; i*i<=temp;i++){
                  while(temp%i==0){
                        temp/=i;
                        D.push_back(i);
                        if (i==2)two++;
                  }
            }
            if (temp>1)D.push_back(temp);

            if (two==D.size()){
                  cout << "FastestFinger" << endl;
                  continue;
            }

            if (two>1){
                  cout << "Ashishgup" << endl;
            }
            else {
                  if (D.size()==2)cout << "FastestFinger" << endl;
                  else cout << "Ashishgup" << endl;
            }
      }


      return 0;
}
