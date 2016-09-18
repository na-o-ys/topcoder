#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    int n; cin >> n;
    vector<int> A(n);
    loop (n, i) cin >> A[i];

    set<int> S;
    loop (n, i) S.insert(A[i]);
    vector<int> idx(all(S));

    for (int v : A) {
        auto itr = lower_bound(all(idx), v);
        cout << distance(idx.begin(), itr) << endl;
    }
    return 0;
}
