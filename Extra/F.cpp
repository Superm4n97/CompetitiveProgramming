#include <bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define pp pair < ll , pair < ll, ll > >

using namespace std;

vector < pair < ll , ll > > v;
vector < pair < ll , pair < ll , ll > > > vp;

void clean()
{
      v.clear();
      vp.clear();
}

ll length(pair <ll ,ll> a, pair <ll, ll> b)
{
      ll temp = (a.first - b.first) * (a.first - b.first) + (a.second-b.second)*(a.second-b.second);
      return temp;
}

pair <ll , ll> angle(pair <ll , ll> a, pair <ll, ll> b)
{
      ll x = a.first - b.first , y = a.second - b.second;

      ll g = __gcd(x,y);

      x/=g , y/=g;

      if (x<0)x*=-1 , y*=-1;


      return {x,y};
}

bool eql(pp a, pp b)
{
      if (a.first==b.first && a.second.first==b.second.first && a.second.second==b.second.second)return true;
      return false;
}

ll cal(ll a)
{
      return a*(a-1)/2;
}

int main()
{
      int tc;
      scanf("%d",&tc);
      for (int _t = 1 ; _t<=tc ; _t++){
            ll n;
            scanf("%lld",&n);

            for (int i=0;i<n;i++){
                  ll a, b;
                  scanf("%lld %lld",&a,&b);
                  v.push_back({a,b});
            }

            for (int i=0;i<n;i++){
                  for (int j=i+1 ; j<n; j++){

                        pair < ll , ll > a = angle(v[i],v[j]);

                        vp.push_back({a.first ,{a.second , length(v[i],v[j])}});


                        cout << "  " <<  a.first << " " << a.second << " " << length(v[i],v[j]) ;
                        cout << " - " << i+1 << " " << j+1 << endl;

                  }
            }
            sort(vp.begin(),vp.end());

            ll cnt = 1 , ans = 0;

            for (int i=0;i<vp.size();i++){
                  cout << "    " << vp[i].first << " " << vp[i].second.first << " ";
                  cout << vp[i].second.second << endl;
            }

            for (int i=1;i<vp.size();i++){
                  if (eql(vp[i],vp[i-1]))cnt++;
                  else {
                        ans += cal(cnt);
                        cnt = 1;
                  }
            }
            ans += cal(cnt);

            printf("Case %d: %llu\n",_t,ans);
      }

     return 0;
}
