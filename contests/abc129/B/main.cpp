#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto const &it: a) cout << it << ' ';
#define DEBUGVV(a) for(auto const &it: a) { DEBUGV(it); cout << endl; };
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

void solve(long long N, std::vector<long long> W)
{
    const long long INF = 1LL << 60;
    // prefix sum
    VLL p1 = VLL(N + 1, 0);
    VLL p2 = VLL(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        p1[i + 1] = p1[i] + W[i];
    }
    for (int i = N - 1; i >= 0; i--)
    {
        p2[i] = p2[i + 1] + W[i];
    }

    LL ans = INF;
    for (int i = 0; i < N; i++)
    {
        chmin(ans, abs(p1[i] - p2[i]));
    }
    cout << ans << endl;
}

int main()
{
    long long N;
    std::scanf("%lld", &N);
    std::vector<long long> W(N);
    for (int i = 0; i < N; i++)
    {
        std::scanf("%lld", &W[i]);
    }
    solve(N, std::move(W));
    return 0;
}
