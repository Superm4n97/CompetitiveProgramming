#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll N,failure[maxn];

void build_failure_function(string pattern)
{
      ll M = pattern.size();
      failure[0] = failure[1] = 0;

      for (int i=2 ; i<= M ; i++){

            ll j = failure[i-1];

            while(true){
                  if (pattern[j] == pattern[i-1]){
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
}

bool KMP(string text ,string pattern)
{
      build_failure_function(pattern);

      ll N = text.size() , M = pattern.size();
      ll i = 0 , j = 0;

      while(true){
            if (i == N)return false;

            if (text[i] == pattern[j]){
                  i++  , j++;
                  if (j == M)return true;
            }
            else {
                  if (j==0)i++;
                  else j = failure[j];
            }
      }

      return false;
}

int main()
{
      string s,t;
      cin >> s >> t;

      cout << (KMP(s,t)?"YES":"NO") << endl;
}
