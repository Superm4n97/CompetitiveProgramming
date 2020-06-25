#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll k,sum = 1;
string s = "codeforces";
priority_queue < ll > pq;

int main()
{
      for (int i=1 ; i<=10 ; i++)pq.push(-1);

      cin >> k;

      while(sum<k){
            ll a = pq.top()*-1;
            pq.pop();

            sum/=a;
            a++;
            sum*=a;

            pq.push(-a);
      }
      for (int i=0;i<10;i++){
            ll a = pq.top()*-1;
            pq.pop();

            for (int j=0 ; j<a ; j++)cout << s[i];
      }
      cout << endl;
}
