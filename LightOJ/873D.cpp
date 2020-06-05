#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005

using namespace std;

ll  n, k , mp[maxn];
vector < ll > v;

void rec(ll l , ll r)
{
    if (k==0 || l==r || r<l)return;
    ll mid = (l+r+1)/2;
    mp[mid] = 1;
    k-=2;
    rec(l,mid);
    rec(mid+1,r);
}

int main()
{
    cin >> n >> k;
    k--;
    if (k%2){
        cout << -1 << endl;
        return 0;
    }

    rec(1,n);

    if (k){
        cout << -1 << endl;
        return 0;
    }

    ll temp = n;
    while(temp>0){
        stack < ll > st;
        while(temp>0){
            if (mp[temp]){
                st.push(temp);
                temp--;
                break;
            }
            st.push(temp);
            temp--;
        }
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
    }
    cout << endl;

    return 0;
}
