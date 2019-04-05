#include <iostream>
using namespace std;
int checkn(int a[], int n){
	int k;
	for(int i=0;i<n;i++){
		if(a[i]!=-1){
			return -1;
		}
	}
	return 0;
}
int high(int a[],int n){
	int sum=0;
	int highest=a[0];
	int k;
	int check=0;
	while(checkn(a,n)!=0){
		k=0;
		for(int i=0;i<n;i++){
			if(a[i]>highest){
				highest=a[i];
				
				k=i;
			}
		}
		sum=sum+highest;
		cout<<"\n this made zero"<<a[k];
		if(k==0){
			a[k]=-1;
			a[k]=+1;
			continue;

		}
		else if(k==n){
			a[k]=-1;
			a[k-1]=-1;
			continue;
		}
		else {
		a[k]=-1;
		
		a[k-1]=-1;
		a[k+1]=-1;
	}
		check++;
		if(check>n){
			break;
		}


	}
	cout<<sum<<" ";
    
	
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	high(a,n);
	return 0;
}