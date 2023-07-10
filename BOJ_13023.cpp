#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> arr;
void dfs(int,int,bool[]);
bool ok = false;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        vector<int> temp;
        arr.push_back(temp);
    }
    for (int i = 0; i < M; i++) {
        int src, dst;
        cin >> src >> dst;
        arr[src].push_back(dst);
        arr[dst].push_back(src);
    }
    for (int i = 0; i < N; i++) {
        bool check[2000]={false,};
        dfs(i,0,check);
        if(ok) {
            cout << 1 << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
}

void dfs(int start,int depth,bool check[]){
    if(depth==4){
        ok = true;
        return;
    }
    check[start] = true;
    for (int i : arr[start]) {
        if(!check[i])
            dfs(i,depth+1,check);
    }
    check[start] = false;
}