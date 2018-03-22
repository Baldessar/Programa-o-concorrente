#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{	
		int paiPid = getpid();
		int status;
		int pid = fork();//1-filho
		wait(&status);
		

		if (pid > 0)//pai
		{	printf("processo pai de todos %d \n",getpid());
			pid = fork();//2-filho
			wait(&status);
			if (pid == 0)//filho-1
			{	printf("processo %d filho de %d \n",getpid(),getppid() );
				pid = fork();//1-neto
				wait(&status);
				if (pid > 0)//filho-1
				{	
					pid = fork();//2-neto
					wait(&status);

					if (pid > 0)//filho-1
					{
						pid = fork();
						wait(&status);
						if (pid == 0)//neto
						{
							execl("/bin/date", "date", "+%H:%M:%S:%N", NULL);
							sleep(5);
						}
					}
					else if (pid == 0)//neto
					{
						execl("/bin/date", "date", "+%H:%M:%S:%N", NULL);
						sleep(5);
					}
				}
				else if (pid == 0)//neto
				{
					execl("/bin/date", "date", "+%H:%M:%S:%N", NULL);
					sleep(5);
				}

			}
			
		}
		else if (pid == 0)//filho 2
		{	printf("processo %d filho de %d \n",getpid(),getppid() );
			pid = fork();//neto4
			wait(&status);

			if (pid > 0)//filho2
			{
				pid = fork();//neto5
				wait(&status);

				if (pid > 0)//filho2
				{
					pid = fork();//neto6
					wait(&status);
					if (pid == 0)
					{
						execl("/bin/date", "date", "+%H:%M:%S:%N", NULL);
						sleep(5);
					}
				}
				else if (pid == 0)
				{
					execl("/bin/date", "date", "+%H:%M:%S:%N", NULL);
					sleep(5);
				}
			}
			else if (pid == 0)
			{
				execl("/bin/date", "date", "+%H:%M:%S:%N", NULL);
				sleep(5);
			}
			
		}
		if (getpid() == paiPid)
		{
			printf("pocesso principal finalizado\n");
		}
		else {
			printf("pocesso %d finalizado\n",getpid());
		}
		


		
	return 0;
}