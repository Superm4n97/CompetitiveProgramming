#define show(x) cout << #x << " : " << x << endl
#define pb      push_back
#define ll      long long int
#define inf     10000000010
#define maxn    300005

#include<bits/stdc++.h>

using namespace std;


int main()
{
    map < ll , ll > mp;
    mp[1]++;
    mp[3]++;
    mp[6]++;
    mp[1]++;

    cout << mp.size() << endl;
    map < ll , ll >::iterator it;
    for (it=mp.begin();it!=mp.end();it++)cout << it->first << " : " << it->second << endl;

    return 0;
}
