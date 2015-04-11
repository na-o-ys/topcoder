#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;

int main()
{
    vector<string> S;
    {
        string s; getline(cin, s);
        istringstream ss(s);
        string word;
        while (getline(ss, word, ' ')) S.push_back(word);
    }

    while (1) {
        int i = 0, count = 0, ck = 0;
        for (; i < S.size(); i++) {
            if (S[i] == "not") count++;
            else {
                if (count >= 2) {
                    S.erase(S.begin()+(i-2), S.begin()+i);
                    ck = 1;
                }
                count = 0;
            }
        }
        if (!ck) break;
    }

    for (int i = 0; i < S.size(); i++) {
        cout << S[i];
        if (i != S.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}
