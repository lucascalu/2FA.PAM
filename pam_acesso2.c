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
PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) 
{



      FILE *g= fopen("/etc/pam.d/pam.acesso/acesso.serial", "r");
   
    
    
    if (!g)
      {
        perror("acesso negado");
		sleep(2);
		return PAM_AUTH_ERR;
		
       
      }
	
   else
	   return PAM_SUCCESS;
	   
     
      

       fclose(g);

     
}
    
