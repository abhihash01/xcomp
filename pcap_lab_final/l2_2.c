#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
	int rank,size;
	double start,end;
	int l;
	char* w1;
	char* w2;
	int l1;
	//this program send  the s t
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank==0){
		printf("\n enter the number");
		scanf("%s",w1);
		l1=strlen(w1);
		MPI_Barrier(MPI_COMM_WORLD);
		MPI_Bcast(&l1,1,MPI_INT,0,MPI_COMM_WORLD);
			MPI_Ssend(w1,l1,MPI_CHAR,1,0,MPI_COMM_WORLD);
	
	}
	MPI_Recv(w2,l1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
	MPI_Barrier(MPI_COMM_WORLD);
	printf("\n process %d received %s",rank,w2);
	MPI_Finalize();
	return 0;
}