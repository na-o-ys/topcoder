#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;

int main()
{
    int N; cin >> N;
    cout << N / 2 + (N % 2) << endl;
    if (N % 2) cout << 1 << endl;
    loop (N / 2, i) cout << 2 << endl;
    return 0;
}
