#include<iostream>
using namespace std;

int arr_of_degree[501];
int matrix[501][501];
int min(int,int);

int main(){
    int number_of_matrix;
    cin>>number_of_matrix;
    for(int i=0;i<number_of_matrix;i++){
        int temp;
        cin>>temp>>arr_of_degree[i+1];
        if(i==0){
            arr_of_degree[0]=temp;
        }
    }

    for(int i=1;i<=number_of_matrix;i++){
        matrix[i][i]=0;
    }
    for(int i=1;i<number_of_matrix;i++){
        int j=i+1;
        matrix[i][j]=arr_of_degree[i-1]*arr_of_degree[i]*arr_of_degree[i+1];
    }
    for(int gap_i_j=2;gap_i_j<number_of_matrix;gap_i_j++){
        for(int i=1;i<=number_of_matrix-gap_i_j;i++){
            int j=i+gap_i_j;
            matrix[i][j]=2147483647;
            for(int k=i;k<j;k++){
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k+1][j]+arr_of_degree[i-1]*arr_of_degree[k]*arr_of_degree[j]);
            }
        }
    }
    cout<<matrix[1][number_of_matrix]<<"\n";
}

int min(int a,int b){
    return a>b?b:a;
}

