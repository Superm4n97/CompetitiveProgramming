#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

struct node
{
      ll endmark;
      node* next[28];

      node()
      {
            endmark = 0;
            for (int i=0 ; i<27 ; i++)next[i] = NULL;
      }
};

node * root;

void insertTrie(string st)
{
      node* curr = root;

      for (int i = 0 ; i<st.size(); i++){
            ll id = st[i]-'a';

            //show(id);

            if (curr->next[id] == NULL)curr->next[id] = new node();

            curr = curr -> next[id];
      }
      curr -> endmark = 1;
}

bool searchTrie(string st)
{
      node* curr = root;
      for (int i=0;i<st.size() ; i++){
            ll id = st[i] - 'a';

            if (curr->next[id] == NULL)
                  return false;

            curr = curr->next[id];
      }

      return curr -> endmark;
}

void deleteTrie(node * curr)
{
      for (int i=0 ; i<28 ; i++){
            if (curr->next[i] != NULL)
                  deleteTrie(curr->next[i]);
      }
      delete(curr);
}

int main()
{
      int tc;
      scanf("%d",&tc);

            root = new node();

            ///*******
            ll n,q;
            cin >> n >> q;

            for (int i=0 ; i<n;i++){
                  string s;
                  cin >> s;

                  insertTrie(s);
            }

            while(q--){
                  string s;
                  cin >> s;

                  if (searchTrie(s))cout << "YES" << endl;
                  else cout << "NO" << endl;
            }
            ///********

            deleteTrie(root);

      return 0;
}
