#include <iostream>
using namespace std;
int* ascd(int* A, int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(A[i]<A[j]){
                int temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
    return A;
}

int main() {
	//code
	int T,N;
	int A[50]={0};
	int *B;
	cin>>T;
	for(int i=0;i<T;i++){
	    cin>>N;
	    for(int j=0;j<N;j++){
	        cin>>A[j];
	    }
	    B=ascd(A,N);
	    for(int j=0;j<N;j++){
	        cout<<B[j]<<" ";
	    }
	    cout<<"\n";
	    
	}
	return 0;
}