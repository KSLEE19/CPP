#include <iostream>
#include <algorithm>
using namespace std;

class Member{
public:
    int age;
    string name;
};

bool compare(Member a,Member b){
    return a.age<b.age;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Member* member_list=new Member[100000];
    int count;
    cin>>count;
    for(int i=0;i<count;i++){
        int age; string name;
        cin>>age>>name;
        member_list[i].age=age;
        member_list[i].name=name;
    }

    stable_sort(member_list,member_list+count, compare);

    for(int i=0;i<count;i++){
        cout<<member_list[i].age<<" "<<member_list[i].name<<"\n";
    }
    return 0;
}
