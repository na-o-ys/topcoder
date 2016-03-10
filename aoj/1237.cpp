#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    while (1) {
        int t;
        string num;
        cin >> t >> num;
        if (!t && num == "0") break;

        int len = num.length();
        int as = -1;
        int r = 0;
        vector<int> av;
        loop (1<<(len-1), i) {
            string s = num;
            vector<int> n;
            int idx = 0;
            loop (len-1, j) {
                if ((i>>j) & 1) {
                    string q = num.substr(idx, j+1-idx);
                    n.push_back(stoi(q));
                    idx = j+1;
                }
            }
            n.push_back(stoi(num.substr(idx)));
            int sum = 0;
            for (int v : n) sum += v;
            if (t >= sum && sum > as) {
                as = sum;
                av = n;
                r = 0;
            } else if (sum == as) {
                r = 1;
            }
        }
        if (as == -1) {
            cout << "error" << endl;
        } else if (r) {
            cout << "rejected" << endl;
        } else {
            cout << as;
            for (int v : av) cout << " " << v;
            cout << endl;
        }
    }
    return 0;
}
