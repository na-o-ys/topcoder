#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int eval(string d)
{
    d = d.substr(1, d.length()-2);
    if (d[0] >= '0' && d[0] <= '9') {
        return stoi(d) / 2 + 1;
    }
    vector<int> vs;
    int i = 0;
    while (i < d.length()) {
        int j = i, cnt = 1;
        while (cnt) {
            j++;
            if (d[j] == '[') cnt++;
            if (d[j] == ']') cnt--;
        }
        vs.push_back(eval(d.substr(i, j-i+1)));
        i = j + 1;
    }
    sort(all(vs));
    int ans = 0;
    loop (vs.size()/2+1, i) ans += vs[i];
    return ans;
}

int main()
{
    int n; cin >> n;
    while (n--) {
        string d; cin >> d;
        cout << eval(d) << endl;
    }
    return 0;
}
