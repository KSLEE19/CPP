#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int numerator=1;
    int denominator=1;
    if(k>(n/2)){
        k=n-k;
    }
    for(int i=0;i<k;i++){
        numerator*=n;
        n--;
    }
    for(int i=1;i<=k;i++){
        denominator*=i;
    }
    cout<<numerator/denominator<<endl;
}