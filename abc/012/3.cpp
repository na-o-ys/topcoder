#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int N; cin >> N;
    int S = 0;
    loop (9, i) loop (9, j) S += (i+1)*(j+1);
    loop (9, i) loop (9, j)
        if (!((i+1)*(j+1)-S+N))
            cout << (i+1) << " x " << (j+1) << endl;
    return 0;
}
