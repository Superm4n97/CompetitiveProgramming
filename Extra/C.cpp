#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

vector < pair < ll, ll > > vp;

ll NOD(ll a)
{
      ll cnt = 0;
      for (int i=1;i*i<=a;i++){
            if (a%i==0){
                  if (i == a/i)cnt++;
                  else cnt+=2;
            }
      }
      return cnt;
}

int main()
{
      for (int i=1 ; i<=1000 ; i++){
            vp.pb({NOD(i),i*-1});
      }

      sort(vp.begin(),vp.end());

      int tc;
      cin >>tc;

      for (int _t = 1 ; _t<=tc ; _t++){
            ll n;
            cin >> n;

            cout << "Case "<< _t<< ": " << vp[n-1].second*-1 << endl;
      }


      return 0;
}

