#include<bits/stdc++.h>
#define maxn    300005
#define ll      long long int

using namespace std;

ll A[maxn] , n , k;

int main()
{
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    int beg = 0 , ed = n , mx = 0 , index = 0;
    while(beg<=ed){
        int mid = (beg+ed)/2;

        int curr = 0 , temp;
        bool possible = false;

        //cout << " beg : " << beg << "    ed : " << ed << endl;

        for (int i = 1 ; i<=n ; i++){
            if (!A[i] && i<=mid){
                curr++;
            }
            if (i>=mid){
                //cout << "A  i : " << i << "  curr : " << curr  << endl;
                if (!A[i-mid] && i>mid)curr--;
                if (!A[i] && i > mid)curr++;
                if (curr<=k){
                    possible = true ;
                    temp = i-mid;
                    //cout << "   mid : " <<  mid << "   i : " << i << endl;
                }
            }
        }
        if (possible){
            if (mx<mid){
                mx = mid;
                index = temp+1;
            }

            beg = mid+1;
        }
        else ed = mid-1;
    }
    //cout << index << endl;
    cout << mx << endl;
    for (int i=1;i<=n;i++){
        if(i>=index && i-index<mx)cout << 1 << " ";
        else cout << A[i] << " ";
    }




    return 0;
}

