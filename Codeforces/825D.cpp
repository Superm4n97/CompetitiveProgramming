#include<bits/stdc++.h>

#define ll long long int

using namespace std;

map < char , ll > mpS,mpT;

int main()
{
    string s,t;
    cin >> s >> t;
    for (int i=0;i<s.size();i++){
        if (s[i] != '?')mpS[s[i]]++;
    }
    for (int i=0;i<t.size();i++)mpT[t[i]]++;

    for (int i=0;i<s.size();i++){
        if (s[i]=='?'){
            char ch;
            ll mn = 1000000000;

            for (char j = 'a' ; j<='z' ; j++){
                if (mpT[j] != 0){
                    ll temp = mpS[j] / mpT[j];
                    if (temp<mn){
                        ch = j;
                        mn = temp;
                    }
                    //cout << i << " " << j << " " << temp << endl;
                }
            }
            s[i] = ch;
            mpS[ch]++;
        }
    }
    cout << s << endl;


    return 0;
}
