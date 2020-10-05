#include <stdio.h>
#include <sys/types.h>  

#include <sys/ipc.h>
#include <string.h>
#include <errno.h>
#include <sys/shm.h> /* shm*  */

#define FILEKEY "/bin/cat"
#define KEY 1300



  

 int main(int argc, int* argv[]){
     
     //Creamos la llave
    int key = ftok(FILEKEY, KEY);
    if (key == -1) {
      fprintf (stderr, "Error con la llave \n");
      return -1; 
   }    
   
   //Creamos la memoria compartida
    int id_zone = shmget (key, sizeof(char)*100, 0777 | IPC_CREAT);
    if (id_zone == -1) {
      fprintf (stderr, "Error with id_zone \n");
      return -1; 
    } 
    printf ("ID zone shared memory: %i\n", id_zone);  
   
    char *buffer; //Buffer compartido
    //Se declara la zona a compartir
    buffer =shmat (id_zone, (char *)0, 0);
    if (buffer == NULL) {
      fprintf (stderr, "Error reserve shared memory \n");
      return -1; 
    }
    printf ("Pointer buffer shared memory: %p\n", buffer);
    
    //Programa
    int Llave = atoi(argv[1]);
    char mensaje[40];
    printf("Ingrese el mensaje a cifrar\n");
    scanf("%s",&mensaje);
    int longitud=strlen(mensaje);
       
    buffer[0]=longitud;
	
    srand(Llave);
    printf("Cifrado: \n");
    int i ;
    for (i = 1; i<=longitud; ++i){
                        
        buffer[i] =(mensaje[i-1] ^ rand());
        printf("%c",buffer[i]);
                
    }
    printf("\n");
        
        
 }