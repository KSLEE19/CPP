#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M,X;
vector<vector<pair<int, int>>> arr;
vector<vector<pair<int,int>>> reverse_arr;
int time_arr[1001];
int reverse_time_arr[1001];
bool check[1001];
bool reverse_check[1001];

struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if (a.second >= b.second) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> X;
    fill(time_arr+1,time_arr+N+1,INT32_MAX);
    fill(reverse_time_arr+1,reverse_time_arr+N+1,INT32_MAX);
    for (int i = 0; i <= N; i++) {
        vector<pair<int,int>> temp;
        vector<pair<int,int>> reverse_temp;
        arr.push_back(temp);
        reverse_arr.push_back(reverse_temp);
    }
    for (int i = 0; i < M; i++) {
        int src, dst, time;
        cin >> src >> dst >> time;
        arr[src].emplace_back(dst, time);
        reverse_arr[dst].emplace_back(src, time);
    }
    reverse_time_arr[X] = 0;
    time_arr[X] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, compare> q;
    q.push(make_pair(X, 0));
    while (!q.empty()) {
        pair<int, int> now = q.top();
        q.pop();
        if (check[now.first]) {
            continue;
        }
        check[now.first] = true;
        for (pair<int, int> p: arr[now.first]) {
            if (time_arr[p.first] > time_arr[now.first] + p.second) {
                time_arr[p.first] = time_arr[now.first] + p.second;
                q.push(make_pair(p.first, time_arr[p.first]));
            }
        }
    }
    q.push(make_pair(X, 0));
    while (!q.empty()) {
        pair<int, int> now = q.top();
        q.pop();
        if (reverse_check[now.first]) {
            continue;
        }
        reverse_check[now.first] = true;
        for (pair<int, int> p: reverse_arr[now.first]) {
            if (reverse_time_arr[p.first] > reverse_time_arr[now.first] + p.second) {
                reverse_time_arr[p.first] = reverse_time_arr[now.first] + p.second;
                q.push(make_pair(p.first, reverse_time_arr[p.first]));
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (i == X) {
            continue;
        }
        result = max(result, time_arr[i] + reverse_time_arr[i]);
    }
    cout << result;
}