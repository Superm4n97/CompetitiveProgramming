#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll A[15][15] , B[15][15];
ll k,a,b;
ll Profit1[15] , Profit2[15];

ll win(ll x, ll y)
{
    if (x==y)return 0;
    if ((x==1 && y==3)||(x==2&&y==1)|| (x==3&&y==2))return 1;
    return 2;
}

int main()
{
    cin >> k >> a >> b;

    for (int i=1;i<=3;i++){
        for (int j=1;j<=3;j++)cin >> A[i][j];
    }
    for (int i=1;i<=3;i++){
        for (int j=1;j<=3;j++)cin >> B[i][j];
    }

    map < pair < ll , ll > , ll > mp;

    mp[{a,b}] = 1;
    if (win(a,b)==1)Profit1[1]++;
    if (win(a,b)==2)Profit2[1]++;

    while(1){
        ll t1 = A[a][b] , t2 = B[a][b];

        if (mp[{t1,t2}]){
            ll node1 = mp[{t1,t2}] , node2 = mp[{a,b}];

            if (k<node2){
                cout << Profit1[k] << " " << Profit2[k] << endl;
                break;
            }
            ll cnt1 = 0 , cnt2 = 0, cycle = (node2-node1+1);

            k -= (node1-1);
            cnt1 += (Profit1[node1-1]) , cnt2 += Profit2[node1-1];

            ll temp = k/cycle;
            cnt1 += (Profit1[node2] - Profit1[node1-1])*temp;
            cnt2 += (Profit2[node2] - Profit2[node1-1])*temp;

            temp = k%cycle;

            a=-1 , b=-1;

            for (int i=1;i<=3;i++){
                for (int j=1;j<=3;j++){
                    if (mp[{i,j}]==node1){
                        a = i , b = j;
                        break;
                    }
                }
            }

            while(temp--){
                if (win(a,b)==1)cnt1++;
                if (win(a,b)==2)cnt2++;
                ll a1 = A[a][b] , b1 = B[a][b];
                a = a1, b = b1;
            }

            cout << cnt1 << " " << cnt2 << endl;

            break;
        }
        else {
            mp[{t1,t2}] = mp[{a,b}]+1;
            ll temp = win(t1,t2) , node = mp[{t1,t2}];
            Profit1[node] = Profit1[mp[{a,b}]];
            Profit2[node] = Profit2[mp[{a,b}]];

            if (win(t1,t2)==1)Profit1[node]++;
            if (win(t1,t2)==2)Profit2[node]++;

            a = t1 , b = t2;
        }
    }

    return 0;
}
