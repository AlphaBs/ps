// 재미로 chatgpt 한테 풀어달라고했는데 진짜 맞음
// 제출 하면 안됨

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> gms_numbers;

// Function to generate all GMS numbers up to 1,000,000
void generate_gms_numbers() {
    queue<int> q;
    q.push(4);
    q.push(7);

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        if (num > 1000000) continue;

        gms_numbers.push_back(num);

        // Generate next GMS numbers
        q.push(num * 10 + 4);
        q.push(num * 10 + 7);
    }

    // Sort GMS numbers for lexicographical order
    sort(gms_numbers.begin(), gms_numbers.end());
}

// Function to solve the problem
void solve(int N) {
    vector<int> dp(N + 1, -1);
    vector<int> trace(N + 1, -1);
    dp[0] = 0;

    // Dynamic Programming to find the sum representation
    for (int i = 0; i <= N; ++i) {
        if (dp[i] == -1) continue;  // Skip if no valid representation

        for (int gms : gms_numbers) {
            if (i + gms <= N && (dp[i + gms] == -1 || dp[i + gms] > dp[i] + 1)) {
                dp[i + gms] = dp[i] + 1;
                trace[i + gms] = gms;
            }
        }
    }

    // If there's no solution, print -1
    if (dp[N] == -1) {
        cout << -1 << endl;
        return;
    }

    // Backtrack to find the sequence of GMS numbers
    vector<int> result;
    while (N > 0) {
        result.push_back(trace[N]);
        N -= trace[N];
    }

    // Output the result in lexicographical order
    sort(result.begin(), result.end());
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    generate_gms_numbers();
    solve(N);

    return 0;
}
