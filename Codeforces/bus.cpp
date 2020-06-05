#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " : " << x << endl;


int main ()
{
    int t;
    cin >> t;
    cin.ignore(1, '\n');
    while(t--)
    {
        string s, cont, goes = "";
        getline(cin, s);
        stringstream ss(s);
        map < string, int > mp;
        vector < string > v;
        while(ss >> cont)
        {
           /// show(cont);
            mp[cont]++;
            v.push_back(cont);
        }
        while(getline(cin, goes))
        {
            if(goes == "what does the fox say?") break;
            stringstream ss(goes);
            int cnt = 0;
            while(ss >> cont)
            {
                cnt++;
                if(cnt == 3)
                {
                    mp[cont] = 0;
                   /// show(cont);
                }
            }
        }
        for(int i = 0; i < v.size(); i++)
        {
            if(mp[v[i]] > 0)
            {
                cout << v[i] << ' ';
                mp[v[i]]--;
            }
        }
    }
}
