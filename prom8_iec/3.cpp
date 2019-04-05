#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int chk(string a, string b){
	int n=b.size();
	int N=a.size();
	int n1=0;
	int flag=0;
	int j=0;
	for(int i=0;i<N;i++){
		if(a[i]!=b[j]){
			continue;
		}
		n1++;
		j++;
	}
	if(n1==n){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}

int checkit(string a[], int n, string b){
	string a1;
	for(int i=0;i<n;i++){
        a1=a[i];
        chk(a1,b);
	}
	return 0;

}
int main(){
	int n;
	cin>>n;
	string b;
	string a[n];
	//gets(b);
	cin>>b;
	for(int i=0;i<n;i++){
		//gets(a[i]);
		cin>>a[i];
		//cout<<"output ****";
		//cout<<a[i];
    }
    checkit(a,n,b);
}
