#include <iostream>
using namespace std;
int mod(int,int);

int main(){
    int a,b;
    cin>>a>>b;
    int mod_num;
    (a>b) ? mod_num=mod(a,b):mod_num=mod(b,a);
    a/=mod_num;
    b/=mod_num;
    cout<<mod_num<<"\n";
    cout<<mod_num*a*b;
}

int mod(int a,int b){
    int ret;
    if(a%b==0) return b;
    else ret=mod(b,a%b);
    return ret;
}