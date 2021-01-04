#include <bits/stdc++.h>
using namespace std;

uint64_t solve(long long N, vector<uint64_t> &memo)
{
    if (N == 0)
        return 2;
    if (N == 1)
        return 1;
    if (memo.at(N) != 0)
        return memo.at(N);
    memo.at(N) = solve(N - 1, memo) + solve(N - 2, memo);
    return memo.at(N);
}

int main()
{
    long long N;
    scanf("%lld", &N);
    vector<uint64_t> memo(N + 1);
    auto res = solve(N, memo);
    cout << res << endl;
    return 0;
}
