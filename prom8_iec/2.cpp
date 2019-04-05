#include <iostream>
//traverse ip
using namespace std;
int get2(int a[], int n1){
	if(a[0]==n1){
		return a[1];
	}
	else if(a[1]==n1)
		return a[0];
	else 
		return n1;
}
int getl(int a[3][2], int n){
	int n1=n;
	for(int i=0;i<3;i++){
		n1=get2(a[i],n1);
		//cout<<"\n got "<<n1;
	}
	cout<<n1<<endl;
	return 0;

}
int main(){
	int T;
	cin>>T;
	int a[3][2],n;
	for(int i=0;i<T;i++){
		cin>>n;
		for(int i=0;i<3;i++){
			for(int j=0;j<2;j++){
				cin>>a[i][j];
			}
		}
		getl(a,n);
	}
}