#define pb push_back
#define ff first
#define ss second
#define ll long long int
#define maxn 100005
#define mod 10000007
#include <bits/stdc++.h>
#define inf 10000000000013
using namespace std;

int visited[2005], n, root, cur;

int nxt(){
    for(int i=1;i<=n;i++){
        if(!visited[i]) {
            visited[i] = 1;
            return i;
        }
    }
    return 0;

}

int main() {
    cin >> n;
    root = nxt();
    cur  = nxt();
    while(1){
        while(1){
            int x, t;
            x = nxt();
            if(x == 0){
                cout << "! "<< cur << endl;
                break;
            }
            cout <<"? "<< root<<" " << cur<<" " << x << endl;
            cin >> t;
            if(t == 0){

            }
            else{
                cur = x;
            }
        }
        break;
    }


    return 0;
}


