#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>



#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



void Cifrar(char *mensaje, int Llave, char *Cifrado){
		//CIFRAR
        
	int i ;
        srand(Llave);
        printf("Cifrado: \n");
	for (i = 0; i<strlen(mensaje); ++i){
                
		Cifrado[i] =(mensaje[i] ^ rand());
               printf("%c",Cifrado[i]);
        }
        printf("\n");
        
      
     
}


 int main(int argc, char* argv[])
{
       
	int Llave = atoi(argv[1]);
	
        char mensaje[40];
        printf("Ingrese el mensaje a cifrar\n");
        scanf("%s",&mensaje);
        
        char Cifrado[strlen(mensaje)];
        char Descifrado[strlen(mensaje)];
        
        Cifrar(mensaje,Llave,Cifrado);
       
        
       
        
        
        FILE* fd;
        fd = fopen(argv[2],"w");
        fwrite(Cifrado,sizeof(char),strlen(mensaje),fd);
        fclose(fd);
        
        
	return 0;
}

