#include <iostream>
#include <stdlib.h>
using namespace std;
int pthat(int *a, int N){
	int flag=0;
	for(int i=0;i<N;i++){
		if(a[i]!=-1){
		for(int j=i+1;j<N;j++){
			if(a[i]==a[j]){
				a[i]=-1;
				a[j]=-1;
				flag=1;
				break;
			}

		}
		/*if(flag==1){
			i=i+1;
		}*/
	}
	}
	for(int i=0;i<N;i++){
		if(a[i]!=-1){
			cout<<a[i]<<" ";
		}
	}
	return 0;

}
int main(){
	int T, N;
	int flag=0;
	cin>>T>>N;
	int a[T][N];
	for(int i=0;i<T;i++){
		flag=0;
		for(int j=0;j<N;j++){
			cin>>a[i][j];

		}

	}
	//output taken
	for(int i=0;i<T;i++){
		pthat(a[i],N);
	}
	return 0;
}