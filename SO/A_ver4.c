#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>



#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>




 int main(int argc, char* argv[])
{

	int Llave = atoi (argv[1]);
	char *mensaje = argv[2]; 
        char Cifrado[40];
        int i;
        srand(Llave);
        for (i=0;i<40; ++i){
            
            if(mensaje[i] == 10){ // Si llega al salto de linea
              i=40;
            }
            else
                Cifrado[i] = mensaje[i] ^ rand();
            printf("%c",Cifrado[i]);
            
        }
        printf("\n");
	return 0;
}

