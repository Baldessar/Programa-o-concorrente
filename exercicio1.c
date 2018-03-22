#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{	
	
		int status;
		int pid = fork();
		//wait(&status);
		

		if (pid == 0)
		{
			execl("/bin/date", "date", "+%H:%M:%S:%N", NULL);

		}
		else if (pid > 0) {
			printf("processo pai criou %d \n",pid);			
			pid = fork();
			if (pid == 0)
			{	printf("\n");
				execl("/bin/date", "date", "+%H:%M:%S:%N", NULL);
				//printf("processo filho %d criado\n",getpid());

			}
			else if( pid > 0) {
				//printf("processo pai criou %d \n",pid);
			}
			else if( pid < 0) {
				//printf("deu pau2\n");
			}
		}
		else {
			//printf("deu pau\n");
		}
		

	
	return 0;
}