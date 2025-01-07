#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <string.h>
#define BUFFER_SIZE 32

int main(int argc,char *argv[])
{
	int  MyRank,Numprocs, Destination;
	int  tag = 0;
	int  Root = 0, temp = 1;
	char Message[BUFFER_SIZE];
	MPI_Init(&argc,&argv);
	MPI_Status status;
 
	MPI_Comm_rank(MPI_COMM_WORLD,&MyRank);
	MPI_Comm_size(MPI_COMM_WORLD,&Numprocs);

	/* print host name, and send message from process with rank 0 to all other processes */
	if(MyRank == 0)        {
		system("hostname");
		strcpy(Message, "Hello India"); 
		for (temp=1; temp<Numprocs;temp++)
		{
			MPI_Send(Message, BUFFER_SIZE, MPI_CHAR, temp, tag,MPI_COMM_WORLD);
		}
	}
 	else {          
		system("hostname");
	   	MPI_Recv(Message, BUFFER_SIZE, MPI_CHAR, Root, tag,MPI_COMM_WORLD, &status);
		printf("\n%s in process with rank %d from Process with rank %d\n", Message,MyRank,Root);
  	}

  	MPI_Finalize();
}


/*
mpicc -o program program.c
mpirun -np 4 ./program
*/

/*
tanishka@Tanishka:~$ mpirun -np 4 ./program
Tanishka
Tanishka
Tanishka
Tanishka

Hello India in process with rank 3 from Process with rank 0

Hello India in process with rank 1 from Process with rank 0

Hello India in process with rank 2 from Process with rank 0
*/