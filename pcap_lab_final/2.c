//take array send and find the square and send it back
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* arg[]){
	int rank,size,a[4],c;
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(rank==0){
    	printf("\n this is the root add integers");
    	for(int i=0;i<4;i++){
    		scanf("%d",&a[i]);
    	}
    	for(int i=0;i<4;i++){
    		MPI_Send(a,1,MPI_Int,c,1,MPI_Int,0,MPI_COMM_WORLD)

    	}

    }
}