// Description : Write a program to display the environmental variable of the user (use environ).

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	extern char **environ;//environ is a pointer to a NULL-terminated array of pointers to strings called the "environment".
	int i = 0;
	while(environ[i] != NULL){
		if(environ[i][0] == 'U'){ //The environment variable USER is used to get the name of the user.
			printf("%s\n", environ[i]);
		}
		i++;
	}
	return 0;
}