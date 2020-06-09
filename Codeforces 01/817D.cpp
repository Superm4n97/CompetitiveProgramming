#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define maxn 1000006
#define inf 10000000000000016

ll mxLeft[maxn] , mxRight[maxn], mnLeft[maxn] , mnRight[maxn];
ll n , A[maxn];

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)cin >> A[i];

    for (int i=1;i<=n;i++){
        ll j = i-1;
        mxLeft[i] = j;
        while(A[j]<A[i] && j>0){
            j = mxLeft[j];
            if (A[j]>=A[i] || j==0){
                mxLeft[i] = j;
                break;
            }
        }

        j = i-1;
        mnLeft[i] = j;
        while(A[j]>A[i] && j>0){
            j = mnLeft[j];
            if (A[j]<=A[i] || j==0){
                mnLeft[i] = j;
                break;
            }
        }
    }

    for (int i=n;i>=1;i--){
        ll j = i+1;
        mxRight[i] = j;
        while(A[j]<=A[i] && j<=n){
            j = mxRight[j];
            if (A[j]>A[i] || j>n){
                mxRight[i] = j;
                break;
            }
        }
        j = i+1;
        mnRight[i] = j;
        while(A[j]>=A[i] && j<=n){
            j = mnRight[j];
            if (A[j]<A[i] || j>n){
                mnRight[i] = j;
                break;
            }
        }
    }
    ll sumMX = 0, sumMN = 0;

    for (int i=1;i<=n;i++){
        ll lft = i - (mxLeft[i] + 1) + 1 , rht = (mxRight[i] - 1) - i + 1;
        sumMX +=  (lft*rht)*A[i];

        lft = i - (mnLeft[i] + 1) + 1 , rht = (mnRight[i] - 1) - i + 1;
        sumMN += (lft*rht)*A[i];
        sumMX -= sumMN;
        sumMN = 0;
    }
    cout << sumMX << endl;

    return 0;
}
