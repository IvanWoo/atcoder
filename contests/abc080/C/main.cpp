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

// bit全探索
void solve(int N, VVI F, VVI P)
{
    int ans = INT_MIN;
    forn(bit, 1, 1 << 10)
    {
        VI check(N, 0);
        forn(i, 0, 10)
        {
            if (bit & (1 << i))
            {
                forn(j, 0, N)
                {
                    check[j] += F[j][i];
                }
            }
        }
        int score = 0;
        forn(i, 0, N)
        {
            score += P[i][check[i]];
        }
        chmax(ans, score);
    }
    printf("%d\n", ans);
}

int main()
{
    int N;
    scanf("%d", &N);
    VVI F(N, VI(10));
    forn(i, 0, N)
    {
        forn(j, 0, 10)
        {
            scanf("%d", &F[i][j]);
        }
    }
    VVI P(N, VI(11));
    forn(i, 0, N)
    {
        forn(j, 0, 11)
        {
            scanf("%d", &P[i][j]);
        }
    }
    solve(N, F, P);
    return 0;
}
