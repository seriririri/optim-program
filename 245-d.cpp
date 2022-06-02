#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
typedef long long LL;
using namespace std;

// Atcoder Beginner Contest 245
// D - Polynomial division

int main() {
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N + 1), B(M + 1), C(N + M + 1);
    for (int i = 0; i <= N; i++) cin >> A[i];
    for (int i = 0; i <= N + M; i++) cin >> C[i];
    
    for (int i = M; 0 <= i; i--) {

        B[i] = C[N + i] / A[N];
        
        for (int j = 0; j <= N; j++) {
            C[i + j] -= A[j] * B[i];
        }

    }

    for (int i = 0; i <= M; i++) cout << B[i] << " " << flush;
    cout << endl;
    
}