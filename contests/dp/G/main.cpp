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

int dfs(int u, VVI &graph, VI &cache)
{
    if (cache[u] != -1)
        return cache[u];

    int res = 0;
    for (auto v : graph[u])
        chmax(res, dfs(v, graph, cache) + 1);
    cache[u] = res;
    return cache[u];
};

void solve(int N, int M, VI x, VI y)
{
    VI cache(N + 1, -1);
    VVI graph(N + 1, VI());
    for (int i = 0; i < M; i++)
    {
        graph[x[i]].push_back(y[i]);
    }

    int res = 0;
    for (int u = 1; u <= N; u++)
        chmax(res, dfs(u, graph, cache));
    cout << res << endl;
}

int main()
{
    int N;
    std::scanf("%d", &N);
    int M;
    std::scanf("%d", &M);
    VI x(M);
    VI y(M);
    for (int i = 0; i < M; i++)
    {
        std::scanf("%d", &x[i]);
        std::scanf("%d", &y[i]);
    }
    solve(N, M, std::move(x), std::move(y));
    return 0;
}
