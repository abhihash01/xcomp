#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
int main(int argc, char* argv[]){
	int rank,size;
	char b;
	char a[50];
	
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank==0){
		printf("\n enter the string");
		scanf("%s",a);
		printf("\n the string received in root is %s",a);
		

	}
	MPI_Scatter(a,1,MPI_CHAR,&b,1,MPI_CHAR,0,MPI_COMM_WORLD);
	printf("process %d received %c",rank,b);
	if(b>'a'){
		b=b-32;

	}
	else{
		b=b+32;
	}
	MPI_Gather(&b,1,MPI_CHAR,a,1, MPI_CHAR,0,MPI_COMM_WORLD);
	if(rank==0){
		printf("\n the output string is\n");
		printf("%s",a);
	}
	MPI_Finalize();
	return 0;

} 