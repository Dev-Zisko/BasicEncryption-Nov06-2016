#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>

#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void Descifrar(char *Cifrado, int Llave, char *Descifrado)
{
	int i;
        srand(Llave);
        printf("Descifrado: \n");
	for (i = 0; i<strlen(Cifrado); ++i){
            
		Descifrado[i] =(Cifrado[i] ^ rand());
                printf("%c",Descifrado[i]);
        }
        printf("\n");
}   
int main(int argc, char* argv[])
{
    char Cifrado[40];
    
    FILE *fd;
    fd=fopen(argv[2],"r");
    fread(Cifrado,sizeof(char),40,fd); 
    fclose(fd);
    int Llave = atoi (argv[1]);
    char Descifrado[40];
    
    Descifrar(Cifrado,Llave,Descifrado);
    
    
   

}

