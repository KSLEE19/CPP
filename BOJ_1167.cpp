#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<pair<int,int>>> tree;
vector<int> diameter;
bool check[100'001];
queue<pair<int,int>> breadth;

void bfs();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int V;
    cin >> V;
    for (int i = 0; i <= V; i++) {
        tree.emplace_back();
        diameter.push_back(0);
        check[i] = false;
    }
    for (int i = 1; i <= V; i++) {
        int idx, dst, weight;
        cin >> idx;
        while (true) {
            cin >> dst;
            if (dst == -1) break;
            cin >> weight;
            tree[idx].emplace_back(dst,weight);
        }
    }
    breadth.emplace(1,0);
    check[1] = true;
    bfs();
    int max = 0, idx = 1;
    for (int i = 1; i <= V; i++) {
        check[i] = false;
        if(max<diameter[i]) {
            max = diameter[i];
            idx = i;
        }
    }
    diameter.clear();
    for (int i = 0; i <= V; i++) {
        diameter.push_back(0);
    }
    breadth.emplace(idx,0);
    check[idx] = true;
    bfs();
    max = 0;
    for (int i = 1; i <= V; i++) {
        if(max<diameter[i]) {
            max = diameter[i];
        }
    }
    cout << max << "\n";
}

void bfs(){
    while (!breadth.empty()) {
        pair<int,int> temp = breadth.front();
        breadth.pop();
        int distance = diameter[temp.first];
        for(pair<int,int> i : tree[temp.first]) {
            if(!check[i.first]){
                check[i.first] = true;
                breadth.push(i);
                diameter[i.first]=distance+i.second;
            }
        }
    }
}