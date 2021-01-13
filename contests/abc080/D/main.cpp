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

// いもす法: https://imoz.jp/algorithms/imos_method.html
void solve(long long N, long long C, std::vector<long long> s, std::vector<long long> t, std::vector<long long> c)
{
    int width = pow(10, 5) + 1;
    VVI imos(C, VI(width, 0));
    forn(i, 0, N)
    {
        imos[c[i] - 1][s[i] - 1] += 1;
        imos[c[i] - 1][t[i]] -= 1;
    }

    forn(i, 0, C)
    {
        forn(j, 1, width)
        {
            imos[i][j] += imos[i][j - 1];
        }
    }

    int ans = 0;
    VI imosans(width, 0);
    forn(i, 0, C)
    {
        forn(j, 0, width)
        {
            imosans[j] += (imos[i][j] >= 1 ? 1 : 0);
            chmax(ans, imosans[j]);
        }
    }
    printf("%d\n", ans);
}

int main()
{
    long long N;
    scanf("%lld", &N);
    long long C;
    scanf("%lld", &C);
    std::vector<long long> s(N);
    std::vector<long long> t(N);
    std::vector<long long> c(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &s[i]);
        scanf("%lld", &t[i]);
        scanf("%lld", &c[i]);
    }
    solve(N, C, std::move(s), std::move(t), std::move(c));
    return 0;
}
