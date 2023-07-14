#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, k, result;
    cin >> N >> k;
    int start = 1;
    int last = k;
    while (start <= last) {
        int mid = (start + last) / 2;
        int sum = 0;
        for (int i = 1; i <= N; i++) {
            int line_value = mid / i;
            if (line_value > N) {
                sum += N;
            }
            else{
                sum += line_value;
            }
        }
        if (sum < k) {
            start = mid + 1;
        } else {
            result = mid;
            last = mid - 1;
        }
    }
    cout << result << "\n";
}