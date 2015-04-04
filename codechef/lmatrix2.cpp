#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define multi_cin(n, array) loop(n,i){cin>>array[i];}
#define assign_if_smaller(var, val) if(var>val)var=val;
#define assign_if_larger(var, val) if(var<val)var=val;
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

using namespace std;

struct Move {
  int y1, y2, x1, x2, k;
};

const int MAX_SIZE = 99;

int p[MAX_SIZE][MAX_SIZE];
int a[MAX_SIZE][MAX_SIZE];
Move moves[MAX_SIZE*MAX_SIZE];
int moves_count;

int gcd(int a, int b) {
  if (b>a) swap(a,b);
  while(b) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

void one_by_one(int x1, int y1, int x2, int y2) {
  loop_from_to(x1,x2,i) loop_from_to(y1,y2,j) {
    if (a[i][j] == 0) continue;
    moves[moves_count].y1 = j;
    moves[moves_count].y2 = j;
    moves[moves_count].x1 = i;
    moves[moves_count].x2 = i;
    moves[moves_count].k  = p[i][j]-a[i][j];
    moves_count++;
  }
}

void calc_four_cells(int x, int y) {
  // horizontal
  bool horizontal = true;
  loop(2,i) {
    int g = gcd(p[x+i][y], p[x+i][y+1]);
    if (a[x+i][y]%g != a[x+i][y+1]) horizontal = false
  }
  // all
 
  // horizontal

  // vertical
}

void calc_area(int x1, int y1, int x2, int y2) {
  // incapability
  loop_from_to(x1,x2,i1) loop_from_to(y1,y2,j1) {
    loop_from_to(x1,x2,i2) loop_from_to(y1,y2,j2) {
      if (i1>=i2 || j1>=j2) continue;

      // each pair must have same a mod gcd(p)
      int g = gcd(p[i1][j1], p[i2][j2]);
      if (a[i1][j1]%g != a[i2][j2]%g) {
        ;
        one_by_one(x1, y1, x2, y2);
        return;
      }
    }
  }

  bool ng;
  loop(2520,k) {
    ng = false;
    loop_from_to(x1,x2,i) loop_from_to(y1,y2,j)
      if ((a[i][j]+k)%p[i][j]) {
        ng = true; break;
      }

    if(!ng) {
      moves.
    }
  }
  return -1;
}

int calc_k(int y1, int x1, int y2, int x2) {
  // incapability
  loop_from_to(x1,x2,i1) loop_from_to(y1,y2,j1) {
    loop_from_to(x1,x2,i2) loop_from_to(y1,y2,j2) {
      if (i1>=i2 || j1>=j2) continue;

      // each pair must have same a mod gcd(p)
      int g = gcd(p[i1][j1], p[i2][j2]);
      if (a[i1][j1]%g != a[i2][j2]%g) return -1;
    }
  }

  bool ng;
  loop(2520,k) {
    ng = false;
    loop_from_to(x1,x2,i) loop_from_to(y1,y2,j)
      if ((a[i][j]+k)%p[i][j]) {
        ng = true; break;
      }

    if(!ng) return k;
  }
  return -1;
}

int main(int argc, char const* argv[])
{
  int n,m; cin>>n>>m;

  loop(n,i) loop(m,j) scanf("%d", &(p[i][j]));
  loop(n,i) loop(m,j) scanf("%d", &(a[i][j]));

  moves_count = 0;

  // main
  for(int i=0;i<n;i+=2)
    for(int j=0;j<m;j+=2) {
      int y1=j, x1=i, y2=min(j+1,m-1), x2=min(i+1,n-1);
      // cout << "y1,x1: "<<y1<<","<<x1<<" y2,x2: "<<y2<<","<<x2<<endl;

      // 4 cells at once
      int k = calc_k(y1,x1,y2,x2);

      if(k == -1) {
        // each 4 cells
        loop_from_to(x1,x2,i) loop_from_to(y1,y2,j) {
          if (a[i][j] == 0) continue;
          moves[moves_count].y1 = j;
          moves[moves_count].y2 = j;
          moves[moves_count].x1 = i;
          moves[moves_count].x2 = i;
          moves[moves_count].k  = p[i][j]-a[i][j];
          moves_count++;
        }
      } else {
        // 4 cells at once
        moves[moves_count].y1 = y1;
        moves[moves_count].y2 = y2;
        moves[moves_count].x1 = x1;
        moves[moves_count].x2 = x2;
        moves[moves_count].k  = k;
        moves_count++;
      }
    }

  cout << moves_count << endl;
  loop(moves_count,i)
    cout<<moves[i].x1+1<<" "<<moves[i].y1+1<<" "<<moves[i].x2+1<<" "<<moves[i].y2+1
    <<" "<<moves[i].k<<endl;
  return 0;
}
