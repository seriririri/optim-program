#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
typedef long long LL;
using namespace std;
const int MOD = 1000000007;

// AtCoder Regular Contest 138
// B - 01 Generation

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    
    bool flag = true;
    int l = 0, r = N - 1;
    while (l <= r) {
        
        bool F = false;
        if (flag  == true) {
            
            while (A[r] == 0) {
                F = true;
                r--;
            }
            if (A[l] == 0) {
                l++;
                flag = false;
                F = true;
            }
            
        } else if (flag == false) {
            
            while (A[r] == 1) {
                F = true;
                r--;
            }
            if (A[l] == 1) {
                l++;
                flag = true;
                F = true;
            }
            
        }
        if (F == false) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;

}