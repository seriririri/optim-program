#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
typedef long long LL;
using namespace std;
const LL Mod = 998244353;

// AtCoder Beginner Contest 238
// C - digitnum

int main() {
    LL N;
    cin >> N;
    LL digit = 0;
    LL n = N;
    for(int i = 0; n != 0; i++) {
        n /= 10;
        digit++; 
    }
    LL ans = 0;
    LL sum = 9;
    for (int i = 1; i < digit; i++) {
        ans += sum * (sum + 1) / 2;
        ans %= Mod;
        sum *= 10;
        sum %= Mod;
    }
    LL k = pow(10, digit - 1);
    k %= Mod;
    sum = N - k + 1;
    sum %= Mod;
    ans += sum * (sum + 1) / 2;
    ans %= Mod;
    cout << ans << endl;
}