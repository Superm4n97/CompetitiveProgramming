#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

string s;
stack < char > st;
char NEXT[maxn];

int main()
{
      cin >> s;

      NEXT[s.size()-1] = 'z'+2;
      for (int i=s.size()-2 ; i>=0 ; i--)NEXT[i] = min(NEXT[i+1],s[i+1]);

      for (int i=0 ; i<s.size() ; i++){
            if (i==s.size()-1){
                  st.push(s[i]);
            }
            else {
                  if (NEXT[i]<s[i]){
                        st.push(s[i]);
                  }
                  else {
                        cout << s[i] ;
                        while(!st.empty()){
                              if (st.top() <= NEXT[i]){
                                    cout << st.top() ;
                                    st.pop();
                              }
                              else {
                                    break;
                              }
                        }
                  }
            }
      }
      while(!st.empty()){
            cout << st.top();
            st.pop();
      }
      cout << endl;

      return 0;
}
