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

// https://img.atcoder.jp/arc089/editorial.pdf
// https://www.cnblogs.com/8023spz/p/8409399.html

// prefix sum vector
VVI v(2001, VI(2001, 0));
int num(int x1, int y1, int x2, int y2)
{
    return v[x2][y2] - v[x2][y1] - v[x1][y2] + v[x1][y1];
};

void solve(int N, int K, vector<int> x, vector<int> y, vector<char> c)
{
    // move all points to the 2K * 2K square
    for (int i = 0; i < N; i++)
    {
        x[i] %= 2 * K;
        y[i] %= 2 * K;
        // x and y are interchangeable, black and white are interachangeable
        x[i] += c[i] == 'W' ? K : 0;
        v[x[i] % (2 * K) + 1][y[i] % (2 * K) + 1]++;
    }

    // prefix sum
    for (int i = 1; i <= 2 * K; i++)
    {
        for (int j = 1; j <= 2 * K; j++)
        {
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }

    // get the answer
    int ans = 0, sum;
    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            // 5 possible cases
            sum = num(0, 0, i, j) + num(i, j, i + K, j + K) + num(i + K, j + K, 2 * K, 2 * K) + num(0, j + K, i, 2 * K) + num(i + K, 0, 2 * K, j);
            // black and white can swap
            ans = max(ans, max(sum, N - sum));
        }
    }

    printf("%d\n", ans);
}

int main()
{
    IOS;
    int N, K;
    scanf("%d %d", &N, &K);
    vector<int> x(N);
    vector<int> y(N);
    vector<char> c(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %c", &x[i], &y[i], &c[i]);
    }
    solve(N, K, x, y, c);
    return 0;
}
