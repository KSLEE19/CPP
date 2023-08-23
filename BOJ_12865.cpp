#include <iostream>
#include <algorithm>
using namespace std;

int bag[101][100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> bag_arr;
    for (int i = 0; i < N; i++) {
        int W, V;
        cin >> W >> V;
        bag_arr.push_back(make_pair(W, V));
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            bag[i][j] = bag[i - 1][j];
            if (bag_arr[i-1].first <= j) {
                bag[i][j] = max(bag_arr[i-1].second + bag[i - 1][j - bag_arr[i-1].first],
                                bag[i][j]);
            }
        }
    }
    cout << bag[N][K];
}