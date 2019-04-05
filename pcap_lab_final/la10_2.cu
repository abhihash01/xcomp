#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
__global__ cudas(char* pA, char pB, int n){

	idx= threadIdx.x;
	pB[n-idx-1]=pA[idx];
}
int main(){
	char a[50];
	char b[50];
	char *pA;
	char *pB;
	printf("enter the string\n");
	scanf("%s",a);
	int n=strlen(a);
	cudaMalloc((void**)&pA,n*sizeof(char));
	cudaMalloc((void**)&pB,n*sizeof(char));
	cudaMemcpy(pA,a,n*sizeof(char),cudaMemcpyHostToDevice);
	dim3_t dim;
	dim=n;
	cudas<<<1,dim>>>(pa,pb,n);
	cudaMemcpy(pb,b,n*sizeof(char,cudaMemcpyDeviceToHost);
	printf("after revers, %s",b);
	cudaFree(pA);
	cudaFree(pB);
	return 0;

}