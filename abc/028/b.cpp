#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    string S; cin >> S;
    int ans[6] = {};
    for (char c : S) {
        ans[c - 'A']++;
    }
    cout << ans[0];
    loop (5, i) cout << " " << ans[i+1];
    cout << endl;
    return 0;
}
