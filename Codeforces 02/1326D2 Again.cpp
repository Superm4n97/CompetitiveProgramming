#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x <<  endl

using namespace std;

ll modifiedKMP(string st)
{
      ll nn = st.size();
      ll failure[nn+5];


      failure[0] = failure[1] = 0;

      for (int i = 2 ; i<nn ; i++){
            ll j = failure[i-1];

            while(true){
                  if (st[j] == st[i]){
                        failure[i] = j+1;
                        break;
                  }

                  if (j==0){
                        failure[i] = 0;
                        break;
                  }

                  j = failure[j];
            }
      }

      ll _i = 0 , _j = nn-1;
      while(true){
            if (st[_i] == st[_j]){

                  if (_i+1 == _j)return (_i+1)*2;
                  if (_i == _j)return _i*2 +1;

                  _i++;
                  _j--;
            }
            else {
                  _i = failure[_i];

                  if (st[_i]==st[_j]){
                        if (_i+1 == _j)return (_i+1)*2;
                        if (_i == _j)return _i*2 +1;

                        _i++ , _j--;
                  }

                  if (_i == 0)_j--;
            }
      }
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            string s;
            cin >> s;

            ll n = s.size();
            ll x = -1 , y = n; //x==y they are palindrome

            while(x<y){
                  if (s[x+1] == s[y-1]){
                        x++ , y--;

                        if (x==y || x+1==y)break;
                  }
                  else break;
            }

            if (x==y || x+1 == y){
                  cout << s << endl;
                  continue;
            }

            string st = "" , ss = "";
            for (int i= x+1 ; i < y ; i++)st = st+s[i];
            for (int i= y-1 ; i > x ; i--)ss = ss+s[i];

            //ss = st;
            //reverse(ss.begin() , ss.end());

            ll len1 = modifiedKMP(st) , len2 = modifiedKMP(ss);

            /*show(len1);
            show(len2);
            show(st);
            show(ss);*/



            for (int i=0 ; i<=x ; i++)cout << s[i];

            if (len1>len2){
                  for (int i=0 ; i<len1 ; i++)cout << st[i];
            }
            else {
                  for (int i=0 ; i<len2 ; i++)cout << ss[i] ;
            }

            for (int i=y ; i<n ; i++)cout << s[i];
            cout << endl;
      }


      return 0;
}
