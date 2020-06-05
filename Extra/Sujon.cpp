#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    map<string,int>mmap;
    for(;;)
    {
        cin >> s;
        if(s[1]=='t' && s[2]=='o' && s[3]=='p')
        {
            string first,second;
            cin >> first >> second;
            cout << s << " "<< first << " "<< second;
            map<string,int>::iterator it;
            for(it=mmap.begin();it!=mmap.end();it++)
            {
                string ans=it->first;
                int an=it->second;
                cout << ans << " " << an << endl;
            }
            mmap.clear();
        }
        if(s!="<text>" && s!="</text>")
        {
            mmap[s]++;
        }
    }
}
