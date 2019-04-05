//take array send and find the square and send it back
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[]){
	int rank,size;
    char ss[50];
    char sa[50];
    int len=0;
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    printf("sent\n");
    if(rank==0){
    	printf("\n enter string");
    	scanf("%s",ss);
        len=strlen(ss);
        MPI_Ssend(ss,len,MPI_CHAR,1,1,MPI_COMM_WORLD);
        MPI_Recv(ss,len,MPI_CHAR,1,2,MPI_COMM_WORLD,&status);

    }
    else{
        MPI_Recv(sa,len,MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
        int len=strlen(ss);
        for(int i=0;i<len;i++){
            if(ss[i]>='a'){
                sa[i]=ss[i]-32;
            }
            else{
                sa[i]=ss[i]+32;
            }
        }
        MPI_Ssend(sa,len,MPI_CHAR,0,2,MPI_COMM_WORLD);


        
    }
    MPI_Finalize();
    return 0;
}

