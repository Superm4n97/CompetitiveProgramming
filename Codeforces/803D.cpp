#define show(x) cout << #x << " : " << x << endl
#define pb      push_back
#define ll      long long int

#include<bits/stdc++.h>

using namespace std;

ll row , ans = 1000006;
string s;

int main()
{
    scanf("%I64d",&row);
    getchar();
    getline(cin,s);
    ll n = s.size();

    ll st = 1 , ed = n+1;

    while(st <= ed){
        ll mid = (st+ed)/2;

        bool solution = true;
        ll previous = -1 , letest = -1 , cnt = 0;

        for (int i=0;i<n;i++){
            if (s[i]==' ' || s[i]=='-' || i==n-1)letest = i;

            if (i-previous==mid){
                if (letest==previous){
                    solution = false;
          //          if (mid==10)show(i) , show(previous) ;///
                }
                cnt++;
                previous = letest;
                if (i==n-1)previous = n-1;
            //    if (mid==10)show(previous);///
            }
            if (i==n-1 && previous != n-1){
                cnt++;
            }
        }

        //if (mid==10)show(cnt);///

        if (!solution){
            st = mid+1;
            continue;
        }

        if (cnt<=row){
            ans = min(ans,mid);
            ed = mid-1;
        }
        else st = mid+1;

    }
    cout << ans << endl;


    return 0;
}

