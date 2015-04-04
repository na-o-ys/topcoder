#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

vector<string> rec(vector<string> S)
{
    int seq = 0, i;
    for (i = 0; i < S.size(); i++) {
        if (S[i] == "not") seq++;
        else {
            if (seq >= 2) {
                S.erase(S.begin() + (i - 2), S.begin() + i);
                return rec(S);
            }
            seq = 0;
        }
    }
    return S;
}

int main()
{
    vector<string> S;
    {
        string s;
        getline(cin, s);
        {
            string f;
            istringstream ss(s);
            while(getline(ss, f, ' ')) {
                S.push_back(f);
            }
        }
    }
    for (auto s : rec(S)) cout << s << " ";
    cout << endl;
    return 0;
}
