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
#define mk              make_pair
#define inf8            100000008


using namespace std;

int main()
{
    ll tc;
    scl(tc);
    while(tc--){
        stack < pair < char , ll > > st , st2;
        queue < pair < char , ll > > q1, q2;
        string s;
        ll n;
        cin >> n;
        cin >> s;


        for (int i=0;i<n;i++){
            if (st.empty()){
                st.push({s[i],i});
                continue;
            }
            if (!q1.empty() && q1.front().first<s[i]){
                q1.push({s[i],i});
                //cout << "     B  " << s[i] << endl;
                continue;
            }

            //if (s[i]<st.top().first){
                while(!st.empty() && st.top().first>s[i]){
                      // cout << st.size() << q1.size()<<"     A " << st.top().first << "  si " <<  s[i] << endl;
                    //q1.push(st.top());
                    st2.push(st.top());
                    st.pop();
                }
                while(!st2.empty()){
                    q1.push(st2.top());
                    st2.pop();
                }
                      // cout << "     A " << st.top().first << "  si " << s[i]  << endl;
                st.push({s[i],i});
            //}
            //else st.push({s[i],i});
        }
        string t = "";
        q2 = q1;

        priority_queue < ll > pq;
        while(!q2.empty()){
            t+=q2.front().first;
            //cout << "   R " << q2.front().second << endl;
            pq.push(q2.front().second*-1);
            q2.pop();
        }
        //cout << q1.size() << "    t  " << t << endl;
        string y = t;
        srt(y);

        if (y!=t){
            cout << "-" << endl;
        }
        else {
            for (int i=0;i<n;i++){
                if(!pq.empty() && i==pq.top()*-1){
                       // cout << "    q1.front().second  " << q1.front().second << endl;
                    cout << "2";
                    pq.pop();
                }
                else cout << "1";
            }
            cout << endl;
        }

    }

    return 0;
}
