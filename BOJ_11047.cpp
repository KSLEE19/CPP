#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K, count = 0;
    vector<int> coins;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    for (int i = N - 1; i >= 0; i--) {
        if (coins[i] > K) continue;
        else {
            count += K / coins[i];
            K -= coins[i] * (K/coins[i]);
        }
    }
    cout << count << "\n";
}