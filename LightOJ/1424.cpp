#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;
#define maxn 2003

using namespace std;

ll A[maxn][maxn];

void clean()
{
    memset(A,0,sizeof(A));
}

int main()
{
    int tc;
    scanf("%lld",&tc);
    for (int _t = 1 ; _t<=tc ; _t++){
        clean();
        ll m ,n;
        scanf("%lld %lld",&n,&m);

        for (int i=1 ; i<=n ; i++){
            string s;
            cin >> s;
            for (int j = 0 ; j<m ; j++){
                if (s[j]=='0')A[i][j+1] = 1;
            }
        }


        for (int j = 1 ; j<=m ; j++){
            for (int i= 2; i<=n ; i++){
                if (A[i][j]!=0){
                    A[i][j] = A[i-1][j]+1;
                }
            }
        }

        ll ans = 0;

        for (int i=1;i<=n; i++){
            stack < pair < ll , pair < ll, ll > > > st;
            for (int j=1 ; j<= m ; j++){
                if (st.empty())st.push({A[i][j] , {j,j}});
                else {
                    if (st.top().first<=A[i][j])st.push({A[i][j],{j,j}});
                    else {
                        ll cnt = 0 , temp = j;
                        while(!st.empty() && st.top().first>A[i][j]){
                            ll length = j - st.top().second.first;
                            ans = max(ans,length*st.top().first);
                            temp = st.top().second.first;
                            st.pop();
                        }
                        ll length  = j;
                        if (!st.empty()){
                            length = j - st.top().second.second;
                        }
                        ll tut = ans;
                        ans = max(ans,A[i][j]*length);
                        st.push({A[i][j],{temp,j}});
                    }
                }
            }

            int j = 0;
            if (!st.empty())j = st.top().second.first;
            while(!st.empty()){
                ll length = j - st.top().second.first+1;
                ans = max(ans,length*st.top().first);
                st.pop();
            }
        }
        printf("Case %d: %lld\n",_t,ans);
    }



    return 0;
}
