#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]){
    
    char mensaje[40];
    char Cifrado[40];
    int Llave = 3;
    FILE *fd;
    printf("\nIngrese el mensaje a cifrar: \n");
    scanf("%s",&mensaje);
    int i;
    srand(Llave);
    for (i = 0; i<40; ++i)
            if(mensaje[i]==10)
                i=40;
            else                     
		Cifrado[i] =(mensaje[i] ^ rand());
    fd = popen("./B_ver2 3","w");
    fprintf(fd,Cifrado);
    fclose(fd);
    return 0;
        
    
    
    
}

