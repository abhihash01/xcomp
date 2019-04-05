#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		int n1=strlen(a);
		for(int i=0;i<n1;i++){
			MPI_Send(&a[i],1,MPI_CHAR,i,i,MPI_COMM_WORLD);
		}

		for(int i=0;i<n1;i++){
			MPI_Recv(&a[i],1,MPI_CHAR,i,i*2,MPI_COMM_WORLD,&status);
		}
		

	}
	MPI_Recv(&b,1,MPI_CHAR,0,rank,MPI_COMM_WORLD,&status);
	
	printf("process %d received %c",rank,b);
	if(b>'a'){
		b=b-32;

	}
	else{
		b=b+32;
	}
	MPI_Send(&b,1,MPI_CHAR,0,rank*2,MPI_COMM_WORLD);
	if(rank==0){
		printf("\n the output string is\n");
		printf("%s",a);
	}
	MPI_Finalize();
	return 0;

} 