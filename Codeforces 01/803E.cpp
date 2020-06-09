#define show(x) cout << #x << " : " << x << endl
#define pb      push_back
#define ll      long long int

#include<bits/stdc++.h>


using namespace std;

ll n,k;
string s , t = "";
ll dp[1005][2005];

ll recurtion(ll pos, ll val)
{
//    cout << "   ";show(pos);///
//    cout << "   ";show(val);///

    if (dp[pos][val] != -1)return dp[pos][val];

    if (pos==n-1){
        //show(val);///
        if (val==2*k || val==0){
            //t = s[pos];
            return dp[pos][val] = 1;
        }
        return dp[pos][val] = 0;
    }
    if (val==0 || val==2*k)return dp[pos][val] = 0;


    if (s[pos+1]!='?'){
        ll temp = 0;
        if (s[pos+1] == 'L'){
            temp = recurtion(pos+1 , val-1);
        }
        else if(s[pos+1]=='W'){
            temp = recurtion(pos+1,val+1);
        }
        else {
            temp = recurtion(pos+1,val);
        }
        if (temp==1){
            t = s[pos+1]+t;
        }
        return dp[pos][val] = temp;
    }
    else {
        ll temp = 0;
        temp = recurtion(pos+1, val+1);
        if (temp==1){
            t = 'W'+t;
            return dp[pos][val] = 1;
        }

        temp = recurtion(pos+1, val-1);
        if (temp==1){
            t = 'L'+t;
            return dp[pos][val] = 1;
        }

        temp = recurtion(pos+1, val);
        if (temp==1){
            t = 'D'+t;
            return dp[pos][val] = 1;
        }
        return dp[pos][val] = temp;
    }
}

int main()
{
    scanf("%I64d %I64d",&n,&k);
    cin >> s;

    memset(dp,-1,sizeof(dp));

    ll temp = -1;
    if (s[0]!='?'){
        if (s[0] == 'W')temp = recurtion(0,k+1);
        else if (s[0]=='L')temp = recurtion(0,k-1);
        else temp = recurtion(0,k);
        t = s[0]+t;
    }
    else {
        temp = recurtion(0,k+1);
        if (temp==1){
            t = 'W'+t;
            cout << t << endl;
            return 0;
        }

        temp = recurtion(0,k-1);
        if (temp==1){
            t = 'L'+t;
            cout << t << endl;
            return 0;
        }

        temp = recurtion(0,k);
        if (temp==1){
            t = 'D'+t;
            cout << t << endl;
            return 0;
        }
    }

    //show(temp);///
    if (temp==0){
        cout << "NO" <<endl;
    }
    else cout << t << endl;

    return 0;
}
