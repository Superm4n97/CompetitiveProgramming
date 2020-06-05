#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n, A[maxn] , P[maxn], root = 0 , subroot = 0;

ll findParent(ll a)
{
      if (P[a] == a)return a;
      return P[a] = findParent(P[a]);
}

void makeParent(ll a, ll b)
{
      a = findParent(a);
      b = findParent(b);

      if (a != b)P[a] = b;
      else {
            subroot = a;
      }
}

int main()
{
      for (int i=0 ; i<maxn ; i++)P[i] = i;

      cin >> n;
      for (int i = 1 ; i<=n ; i++){
            cin >> A[i];
            if (A[i] == i)root = A[i];
            else makeParent(i,A[i]);
      }
      set < ll > st;

      for (int i=1 ; i<=n ; i++)st.insert(findParent(i));

      ll temp = st.size() - 1;

      if (root == 0)root == subroot;

      cout << temp << endl;
      for (int i = 1 ; i<=n; i++){
            if (A[i] == findParent(A[i]))cout << root << " ";
            else cout << A[i] << " ";
      }
      cout << endl;


      return 0;
}
/*
2 3 4 5 2
*/

