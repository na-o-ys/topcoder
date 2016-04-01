#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

vector<string> split(char d, string s)
{
    istringstream iss(s); string tmp; vector<string> res;
    while(getline(iss, tmp, d)) res.push_back(tmp);
    return res;
}

unordered_map<string, vector<string>> gs;
unordered_map<string, vector<string>> memo;

vector<string> dfs(string r)
{
    if (memo.find(r) != memo.end()) return memo[r];
    unordered_set<string> ans;
    for (auto name : gs[r]) {
        if (gs.find(name) == gs.end()) ans.insert(name);
        else {
            for (auto m : dfs(name)) ans.insert(m);
        }
    }
    memo[r] = vector<string>(all(ans));
    return memo[r];
}

int main()
{
    while (1) {
        int n; cin >> n;
        if (!n) break;
        gs.clear();
        memo.clear();

        string root;
        loop (n, i) {
            string l; cin >> l;
            auto vs = split(':', l);
            auto mems = split(',', vs[1]);
            auto lst = mems.back();
            mems[mems.size()-1] = lst.substr(0, lst.length()-1);
            if (!i) root = vs[0];
            gs[vs[0]] = mems;
        }

        cout << dfs(root).size() << endl;
    }
    return 0;
}
