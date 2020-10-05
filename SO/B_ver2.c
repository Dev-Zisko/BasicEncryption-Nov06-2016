#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
        int Llave= atoi(argv[1]);
        char Cifrado[40];
        char Descifrado[40];
        fgets(Cifrado,40,stdin);    
        srand(Llave);
        int i;
        printf("\nCifrado: %s\n",Cifrado);
        printf("Descifrado: ");
        for ( i=0; i<40; i++){
        
            if(Cifrado[i]==10) //Salto de linea
                i=40;
            
            else            
                Descifrado[i] = Cifrado[i] ^ rand();
           
        }
       
        
        printf("%s",Descifrado);
        printf("\n");
	return 0;

}
 
