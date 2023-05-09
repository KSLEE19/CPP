#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int* arr=new int[1000000];
    int count;
    cin>>count;
    for(int i=0;i<count;i++){
        cin>>arr[i];
    }

    sort(arr,arr+count);

    for(int i=0;i<count;i++){
        cout<<arr[i]<<"\n";
    }
    return 0;
}
