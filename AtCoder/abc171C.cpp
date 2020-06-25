#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll n;
      cin >> n;
      vector < ll > v;
      while(n){

            ll temp = n%26;
            n/=26;

            if (temp==0)n--;

            v.push_back(temp);
      }

//      for (int i=0 ; i<v.size() ; i++){
//            cout << v[i] << endl;
//      }

      for (int i = v.size()-1 ; i>=0 ; i--){

            char ch = 'a';
            if (v[i]==0)cout << 'z';
            else {
                  v[i]--;
                  ch+=v[i];
                  cout << ch;
            }
      }
      cout << endl;

      return 0;
}

