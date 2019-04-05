#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
	int rank,size;
	double start,end;
	int l;
	//this program send  the s t
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank==0){
		printf("\n root reached");
		for(int i=1;i<size;i++){
			MPI_Ssend(&i,1,MPI_INT,i,i,MPI_COMM_WORLD);
		}
	}
	MPI_Recv(&l,1,MPI_INT,0,rank+1,MPI_COMM_WORLD,&status);
	printf("\n process %d received %d",rank,l);
	MPI_Finalize();
	return 0;
}