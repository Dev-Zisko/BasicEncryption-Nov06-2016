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
   
    int Llave = atoi(argv[1]);
   
    char Descifrado[40];
    
    int longitud=buffer[0];
    
    //Programa
       
    srand(Llave);
    printf("Descifrado: \n");
    int i ;
    for (i = 1; i<=longitud; ++i){
              
	Descifrado[i-1] =(buffer[i] ^ rand());
        printf("%c",Descifrado[i-1]);
              
    }
    printf("\n");
      
    /* Free the shared memory */
   shmdt ((char *)buffer);
   shmctl (id_zone, IPC_RMID, (struct shmid_ds *)NULL);
   return 0;
   
   
 }