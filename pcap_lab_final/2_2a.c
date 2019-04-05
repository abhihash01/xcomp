#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
	int rank,size;
	double start,end;
	int l;
	int w2;
	int l1;
	//this program send  the s t
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	printf("\n reached \n");
	printf("\n rank is %d",rank);
	if(rank==0){
		printf("\n enter the number");
		scanf("%d",&w2);
		for(int i=1;i<size;i++){
			MPI_Ssend(&w2,1,MPI_INT,i,i,MPI_COMM_WORLD);
		}
	
	}
	else{
	MPI_Recv(&w2,1,MPI_INT,0,rank,MPI_COMM_WORLD,&status);
	printf("\n process %d received %d",rank,w2);
}
	MPI_Finalize();
	return 0;
}