#include<bits/stdc++.h>
#define ll long long int

using namespace std;


int main()
{
      ll n,k;
      cin >> n >> k;
      if (n>k)cout << -1 << endl;
      else if (k==0){
            cout <<  0 << endl;
      }
      else if (n==k){
            cout << 1 << endl;
            cout << k << endl;
      }
      else {
            if ((k-n)%2)cout << -1 << endl;
            else {
                  vector < ll > v;
                  ll temp = (k-n)/2;
                  v.push_back(temp);

                  if ((temp&n)==0)v.push_back(temp|n);
                  else {
                        v.push_back(temp);
                        v.push_back(n);
                  }

                  cout << v.size() << endl;
                  for (int i=0;i<v.size();i++)cout << v[i] << " ";
                  cout << endl;
            }
      }

      return 0;
}
