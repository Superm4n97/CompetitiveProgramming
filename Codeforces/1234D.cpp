#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            100006

using namespace std;

string s;
ll n , ST[27][4*maxn];

void build(ll node, ll b, ll e, ll val)
{
      if (b==e){
            ll temp = s[b] - 'a';
            if (temp==val)ST[val][node] = 1;

            return;
      }

      ll mid = (b+e)/2;

      build(node*2 , b, mid, val);
      build(node*2+1,mid+1 , e, val);

      ST[val][node] = ST[val][node*2] + ST[val][node*2+1];
      return;
}

void update(ll node, ll b, ll e, ll type , ll pos , ll val)
{
      if (b>pos || e<pos)return;
      if (b==e){
            ST[type][node] = val;
            return;
      }

      ll mid = (b+e)/2;

      update(node*2,b,mid,type,pos,val);
      update(node*2+1,mid+1,e, type,pos,val);

      ST[type][node] = ST[type][node*2] + ST[type][node*2+1];

      return;
}

ll query(ll node, ll b, ll e, ll x, ll y , ll type)
{
      if (b>y || e<x)return 0;

      if (b>=x && e<=y){
            return ST[type][node];
      }

      ll mid = (b+e)/2;

      return query(node*2 ,b,mid,x,y,type) + query(node*2+1,mid+1,e,x,y,type);
}

int main()
{
      cin >> s;
      n = s.size();

      ll q;
      //cin>>q;
      scl(q);

      for (int i=0 ; i<26 ; i++){
            build(1,0,n-1,i);
      }

      while(q--){
            ll type;
            //cin >> type;
            scl(type);

            if (type==1){
                  ll pos;
                  char ch;
                  //cin >> pos >> ch;
                  scl(pos);
                  //scanf("%c",ch);
                  cin >> ch;

                  //show(ch);

                  char pre = s[pos-1];
                  s[pos-1] = ch;

                  ll t1 = pre - 'a' , t2 = ch - 'a';

                  update(1,0,n-1,t1,pos-1,0);
                  update(1,0,n-1,t2,pos-1,1);
            }
            else {
                  ll l,r;
                  //cin >> l >> r;
                  scll(l,r);

                  ll cnt = 0;

                  for (int i=0 ; i<26 ; i++){
                        if (query(1,0,n-1,l-1,r-1,i))cnt++;
                  }

                  //cout << cnt << endl;
                  printf("%I64d\n",cnt);
            }
      }




      return 0;
}
