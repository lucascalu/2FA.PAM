/*
 * Fatec - Faculdade de Técnologia de Americana
 * Sistemas Operacionais II
 * Professor: Rossano Pablo Pinto
 * Alunos: 
    Alan Vidal
    Daniel Evaldo
    Leonardo B Rodrigues
    Lucas S Calu
    
 */
 
#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <pwd.h>
#include <security/pam_modules.h>
#include <security/pam_ext.h>

#define _GNU_SOURCE 
    

PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) 
{
	return PAM_SUCCESS;
}




      FILE *g= fopen("/etc/pam.d/pam.acesso/acesso.serial", "r");
    size_t serial = 100; 
    char *linha = malloc(serial);
    int estado;
    if (!g)
      {
        perror("/etc/pam.d/pam.acesso/acesso.serial");
        return PAM_AUTH_ERR;
      }
      while (getline(&linha, &serial, g) > 0)
      {
            if(strcmp(buf, linha) == 0){
                estado = 0;

            }else{
                estado = 1;
            }
      }
      if (linha){
        free(linha);
      }
      fclose(g);

      if(estado == 0){
	     
	    
        system("clear");
        
             
          printf("\n\n  -> Acesso Liberado!");
          printf("\n          -> Logando..\n\n");
          sleep(2);
          return PAM_SUCCESS;
      }else{
        
          return PAM_AUTH_ERR;
      }
}
    
