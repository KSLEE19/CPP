#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

bool check[1001];
void dfs(int);
void bfs();
void print();

vector<vector<int>> graph;
vector<int> order;
queue<int> breadth;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, V;
    cin >> N >> M >> V;
    for (int i = 0; i <= N; i++) graph.emplace_back();
    for (int i = 0; i < M; i++) {
        int src, dst;
        cin >> src >> dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }
    dfs(V);
    print();
    cout << "\n";
    for (int i = 1; i <= N; i++) check[i] = false;
    order.clear();
    check[V] = true;
    breadth.push(V);
    bfs();
    print();
}

void dfs(int start) {
    check[start] = true;
    order.push_back(start);
    sort(graph[start].begin(),graph[start].end());
    for(int i : graph[start]) {
        if (!check[i]) {
            dfs(i);
        }
    }
}

void bfs() {
    while(!breadth.empty()){
        int temp = breadth.front();
        order.push_back(temp);
        sort(graph[temp].begin(), graph[temp].end());
        for(int i : graph[temp]) {
            if (!check[i]) {
                check[i] = true;
                breadth.push(i);
            }
        }
        breadth.pop();
    }
}

void print(){
    for(int i : order) cout<<i<<" ";
}