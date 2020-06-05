#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

struct node
{
      int counter;
      node* next[5];

      node()
      {
            counter = 0;
            for (int i=0 ; i<5 ; i++)next[i] = NULL;
      }
};
node * root;
int a,b , ans;

int check(char ch)
{
      if (ch == 'A')return 0;
      if (ch == 'C')return 1;
      if (ch == 'G')return 2;
      if (ch == 'T')return 3;
}

void init(string s)
{
      int res = 0;


      node *cur = root;
      for (int i=0 ; i<s.size() ; i++){
            int id = check(s[i]);

            if (cur->next[id] == NULL)cur->next[id] = new node();

            cur = cur->next[id];
            cur->counter++;
            if (cur->counter > 0)res++;

            ans = max(ans,cur->counter * res);
      }
}

void del(node* cur)
{
      for (int i=0 ;i<5 ;i++){
            if (cur->next[i] != NULL)del(cur->next[i]);
      }
      delete(cur);
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            int n ;
            ans = 0 , a = 0 , b = 0;

            scanf("%d",&n);

            root = new node();

            while(n--){
                  string s;
                  cin >> s;
                  init(s);
            }
            printf("Case %d: %d\n",_t,ans);

            del(root);
      }

      return 0;
}
