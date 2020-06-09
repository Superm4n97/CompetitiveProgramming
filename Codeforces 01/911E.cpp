#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define inf 2000000000012
#define right _right
#define left _left

using namespace std;

bool solution = true;
ll A[maxn] , n,k , S[20][maxn] , mp[maxn] , mm[maxn];

void build(ll depth , ll b, ll e)
{
      if (b == e){
            S[depth][b] = A[b];
            return;
      }

      ll mid = (b+e)/2;
      build(depth+1,b,mid);
      build(depth+1 , mid+1,e);


      /// merge

      ll i = b , j = mid+1 , id = b;

      while(true){
            if (i>mid && j>e)break;

            if (i>mid){
                  S[depth][id] = S[depth+1][j];
                  j++ , id++;
            }
            else if (j>e){
                  S[depth][id] = S[depth+1][i];
                  i++,id++;
            }
            else {
                  if (S[depth+1][i] < S[depth+1][j]){
                        S[depth][id] = S[depth+1][i];
                        i++ , id++;
                  }
                  else {
                        S[depth][id] = S[depth+1][j];
                        j++ , id++;
                  }
            }
      }
}

ll query(ll depth , ll b, ll e, ll x, ll y, ll val)
{
      if (x>e || y<b)return inf;

      if (b>=x && e<=y){
            ll st = b , ed = e , res = b-1;

            while(st<=ed){
                  ll md = (st+ed)/2;

                  if(S[depth][md] < val){
                        st = md+1;
                        res = max(res,md);
                  }
                  else ed = md-1;
            }
            if (res == b-1)return inf;
            return S[depth][res];
      }

      ll mid = (b+e)/2;

      ll t1 = query(depth+1,b,mid,x,y,val) , t2 = query(depth+1,mid+1,e,x,y,val);

      if (t1 == inf)return t2;
      if (t2 == inf)return t1;

      return max(t1,t2);
}

/*
7 2
6 4

1 2 3 5 7

6 4   3 2 1   5   7
*/

int main()
{
      cin >> n >> k;

      for (int i=1 ; i<=k; i++){
            cin >> A[i];
            mp[A[i]]++;
      }
      mp[0] = 1;

      build(1,1,k);

      ll right = 1;

      mm[A[1]]++;

      for (int i = 2 ; i<= k ; i++){
            mm[A[i]]++;

            while(mm[right]){
                  right++;
            }

            ll tL = query(1,1,k,1,i-1,A[i]) , tR = right;

            if (tL<A[i] && tR<A[i] && tL>tR){
                  solution = false;
            }
      }

      if (!solution)cout << -1 << endl;
      else {
            priority_queue < ll > pq;
            for (int i=1 ; i<=k;i++){
                  pq.push(A[i]*-1);
                  cout << A[i] << " ";
            }

            while(!pq.empty()){
                  ll x = pq.top()*-1;
                  pq.pop();

                  x--;

                  while(mp[x]==0){
                        cout << x << " ";
                        x--;
                  }
            }
            ll y = n;
            while(mp[y]==0){
                  cout << y << " ";
                  y--;
            }
            cout << endl;
      }



      return 0;
}
