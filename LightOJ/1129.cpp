#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

struct node
{
      bool endmark;
      node* next[12];

      node()
      {
            endmark = false;
            for (int i=0 ; i<12 ; i++)next[i] = NULL;
      }
};

node* root;

bool insertTrie(string st)
{
      node* curr = root;
      bool res = false;
      int cnt = 0;

      for (int i=0 ; i<st.size();i++){
            int id = st[i] - '0';

            if (curr->next[id] == NULL)curr->next[id] = new node() , cnt++;
            curr = curr->next[id];

            res |= curr->endmark;
      }
      curr->endmark = true;

      if (cnt == 0)res = true;

      return res;
}

void deleteTrie(node * curr)
{
      for (int i=0 ; i<12 ; i++){
            if (curr->next[i] != NULL)deleteTrie(curr->next[i]);
      }
      delete(curr);
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            root = new node();

            int n;
            scanf("%d",&n);
            bool ans = false;

            while(n--){
                  string s;
                  cin >> s;

                  ans |= insertTrie(s);
            }

            if (ans)printf("Case %d: NO\n",_t);
            else printf("Case %d: YES\n",_t);


            deleteTrie(root);
      }

      return 0;
}
