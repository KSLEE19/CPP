#include<iostream>
#include<algorithm>
using namespace std;

class Point{
public:
    int x;
    int y;
    Point(){};
};
bool compare(Point a,Point b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    return a.x<b.x;
}
int main(){
    int count;
    cin>>count;
    Point* arr=new Point[count];
    for(int i=0;i<count;i++){
        cin>>arr[i].x>>arr[i].y;
    }
    sort(arr,arr+count, compare);
    for(int i=0;i<count;i++){
        cout<<arr[i].x<<" "<<arr[i].y<<"\n";
    }
}
