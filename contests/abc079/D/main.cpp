#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) (a + b - 1) / b
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

// DP(Floyd–Warshall algorithm)
void solve(int H, int W, VVI c, VVI A)
{
    forn(k, 0, 10)
    {
        forn(i, 0, 10)
        {
            forn(j, 0, 10)
            {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    int ans = 0;
    forn(i, 0, H)
    {
        forn(j, 0, W)
        {
            if (A[i][j] != -1)
            {
                ans += c[A[i][j]][1];
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    int H;
    scanf("%d", &H);
    int W;
    scanf("%d", &W);
    VVI c(10, VI(10));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    VVI A(H, VI(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    solve(H, W, c, A);
    return 0;
}
