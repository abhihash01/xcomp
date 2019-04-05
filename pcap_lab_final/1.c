//sender sends and receiever prints
#include "mpi.h"
#include <stdio.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	int rank, size,a;
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	//int a[]={1,2,3,4,5,6,7,8,9,10,11,12};
	if(rank==0){
		printf("\nenter\n");
		scanf("%d",&a);
		MPI_Send(&a,1,MPI_INT,1,1,MPI_COMM_WORLD);
		fprintf(stdout,"\nsent %d from process %d\n", a,rank);
		fflush(stdout);
	}
	else{
		MPI_Recv(&a,1,MPI_INT,0,1,MPI_COMM_WORLD, &status);
		fprintf(stdout, "\n received %d in procss %d",a,rank);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;

}