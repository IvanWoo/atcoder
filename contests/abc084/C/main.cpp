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

void solve(LL N, VLL C, VLL S, VLL F)
{
    VLL ans(N);
    forn(i, 0, N)
    {
        LL total = 0;
        forn(j, i, N - 1)
        {
            chmax(total, S.at(j));
            if (total % F.at(j) != 0)
            {
                total += F.at(j) - total % F.at(j);
            }
            total += C.at(j);
        }
        ans[i] = total;
    }
    forn(i, 0, N)
    {
        cout << ans[i] << endl;
    }
}

int main()
{
    LL N;
    scanf("%lld", &N);
    VLL C(N - 1);
    VLL S(N - 1);
    VLL F(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%lld", &C[i]);
        scanf("%lld", &S[i]);
        scanf("%lld", &F[i]);
    }
    solve(N, C, S, F);
    return 0;
}
