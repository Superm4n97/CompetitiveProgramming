#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

string s;
ll L,R , n;

bool solve(ll l , ll r)
{
      while(l>L && r<R){
            if (s[l]==s[r]){
                  l-- , r++;
            }
            else return false;
      }
      return true;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> s;
            L = 0 , R = s.size()-1, n = s.size();

            while(L<=R){
                  if (s[L]==s[R])L++ , R--;
                  else{
                        L-- , R++;
                        break;
                  }
            }

            show(L);
            show(R);

            ll b =  1 , e = R - L - 1 , ans = 0, midL , midR;

            while(b<=e){
                  ll mid = (b+e)/2;
                  ll l = L + (mid+1)/2 , r ;

                  show(mid);

                  if (mid%2)r = l;
                  else r = l+1;

                  show(l);
                  show(r);

                  bool temp1 = solve(l,r);

                  if (temp1 && mid>ans){
                        ans = mid;
                        midL = l , midR = r;
                  }

                  r = R - (mid+1)/2;

                  if (mid%2)l = r;
                  else l = r-1;

                  bool temp2 = solve(l,r);
                  if (temp2 && mid>ans){
                        ans = mid;
                        midL = l , midR = r;
                  }

                  if (temp1|temp2)b = mid+1;
                  else e = mid-1;
            }

            show(midL);
            show(midR);
            show(ans);

            for (int i=0 ; i<=R ; i++)cout << s[i];
            for (int i=midL - (ans-1)/2 ; i <= midR + (ans-1)/2 ; i++)cout << s[i];
            for (int i=R ; i<n;i++)cout << s[i];
            cout << endl;
      }
}
