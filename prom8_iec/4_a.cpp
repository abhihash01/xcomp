#include <iostream>
#include <cstring>
using namespace std;
int chk(int* a, int n){
	for(int i=0;i<n;i++){
		if(a[i]!=-1){
			return 1;
		}
	}
	return 0;

}
int check(int *a, int n){
	int highest;
	highest=a[0];
	int sum=0;
	int k=0;
	while(chk(a,n)){
	for(int i=0;i<n;i++){
		if(a[i]!=-1){
			if(a[i]>highest){
				highest=a[i];
				k=i;
			}
		}
	}
	if(k==0){
					a[k]=a[k+1]=-1;
					continue;
				}
				else if(k==n-1){
					a[k]=a[k-1]=-1;
					continue;
				}
				a[k]=a[k-1]=a[k+1]=-1;
				sum=sum+highest;
}
cout<<sum;
return 0;

}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	check(a,n);
	return 0;
}