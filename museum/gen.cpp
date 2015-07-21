#include <bits/stdc++.h>
using namespace std;

const int h = 170, w = 230, b = 128;
const int di[] = {-8,1,8,-1}, dj[] = {1,8,-1,-8}; // nesw

struct node { int i, j, f; };

inline bool in(int i, int j) { return 0<=i+b and i<h and 0<=j+b and j<w; }

bool checked[512][512];
bool iswall[256][256];

inline void paint_sub(int i, int j) { if(in(i-b,j-b)) iswall[i][j] = 1; }

void paint(int i, int j, int f)
{
    paint_sub(i+1,j);
    paint_sub(i,j+1);
    paint_sub(i+4,j);
    paint_sub(i,j+4);
    paint_sub(i+5,j+1);
    paint_sub(i+1,j+5);
    paint_sub(i+5,j+4);
    paint_sub(i+4,j+5);
    if(f) {
        paint_sub(i+2,j+2);
        paint_sub(i+3,j+3);
    }
}

void generate()
{
    memset(iswall,0,sizeof(iswall));
    memset(checked,0,sizeof(checked));
    queue<node> q;
    q.push((node){3,0,0});
    while(!q.empty()) {
        node v = q.front(); q.pop();
        if(checked[v.i+b][v.j+b]) continue;
        checked[v.i+b][v.j+b] = 1;
        paint(v.i,v.j,v.f);
        for (int d = 0; d < 4; d++) {
            const int ni = v.i+di[d], nj = v.j+dj[d];
            if(in(ni,nj)) q.push((node){ni,nj,1-v.f});
        }
    }
}

void show()
{
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(iswall[i][j]) cout << "#";
            else cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    generate();
    show();
    return 0;
}
