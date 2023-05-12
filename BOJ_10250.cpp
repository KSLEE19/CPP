#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int H,W,N;
        cin>>H>>W>>N;
        int floor=N%H;
        if(floor==0)
            floor=H;
        int room;
        if(N%H==0)
            room=N/H;
        else
            room=N/H+1;
        if(room<10)
            cout<<floor<<"0"<<room;
        else
            cout<<floor<<room;
        cout<<"\n";
    }
    return 0;
}
