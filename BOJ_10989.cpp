#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int arr[10001]={0,};
    int count;cin>>count;
    for(int i=0;i<count;i++){
        int n;
        cin>>n;
        arr[n]++;
    }
    for(int i=1;i<10001;i++){
        if(arr[i]==0) continue;
        for(int j=0;j<arr[i];j++){
            cout<<i<<"\n";
        }
    }
}