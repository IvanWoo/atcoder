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

LL get_index(LL target, LL N, VLL a)
{
    LL idx = 0;
    forn(i, 0, N)
    {
        if (a[i] == target)
        {
            idx = i;
            break;
        }
    }
    return idx;
}

void solve(LL N, VLL a)
{
    vector<PLL> ans;
    LL ma = INT_MIN;
    LL mi = INT_MAX;
    forn(i, 0, N)
    {
        chmax(ma, a[i]);
        chmin(mi, a[i]);
    }
    if (abs(mi) > abs(ma))
    {
        LL idx = get_index(mi, N, a);
        forn(i, 0, N)
        {
            if (i != idx && a[i] > 0)
            {
                ans.push_back(make_pair(idx, i));
            }
        }
        for (int i = N - 2; i >= 0; i--)
        {
            ans.push_back(make_pair(i + 1, i));
        }
    }
    else
    {
        LL idx = get_index(ma, N, a);
        forn(i, 0, N)
        {
            if (i != idx && a[i] < 0)
            {
                ans.push_back(make_pair(idx, i));
            }
        }
        for (int i = 1; i < N; i++)
        {
            ans.push_back(make_pair(i - 1, i));
        }
    }
    cout << ans.size() << endl;
    forn(i, 0, ans.size())
    {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
}

int main()
{
    LL N;
    scanf("%lld", &N);
    VLL a(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
