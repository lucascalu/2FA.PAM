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

    struct tm *data_hora_atual;
    time_t segundos;    
    time(&segundos);   
    data_hora_atual = localtime(&segundos);  

    ssize_t len;
     
    char buf[256], *p;
    char buf2[256];
    int i;
   
      len = readlink("/sys/block/sdb", buf, 256);
   
    buf[len] = 0;
   
    // printf("%s\n", buf);
    sprintf(buf2, "%s/%s", "/sys/block/", buf);
    for (i=0; i<6; i++) {
        p = strrchr(buf2, '/');
        *p = 0;
    }
   
    // printf("%s\n", buf2);
    strcat(buf2, "/serial");
    // printf("opening %s\n", buf2);

    int f = open(buf2, 0);
    len = read(f, buf, 256);
    if (len <= 0) {
        
    }
 
    buf[len - 1 ] = 0;


      FILE *g= fopen("/etc/pam.d/pam.acesso/acesso.serial", "r");
    size_t serial = 100; 
    char *linha = malloc(serial);
    int estado;
    if (!g)
      {
        perror("/etc/pam.d/pam.acesso/acesso.serial");
        exit(1);
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
        
                FILE *log;

                log = fopen("/etc/pam.d/pam.acesso/log/login", "a");
                fprintf(log, "%s", "-> Serial: ");
                fprintf(log, "%s | ", buf);
                fprintf(log, "%d/", data_hora_atual->tm_mday);
                fprintf(log, "%d/", data_hora_atual->tm_mon+1);
                fprintf(log, "%d ", data_hora_atual->tm_year+1900);
                fprintf(log, "%d:", data_hora_atual->tm_hour);
                fprintf(log, "%d:", data_hora_atual->tm_min);
                fprintf(log, "%d\n ", data_hora_atual->tm_sec);

          printf("\n\n  -> Acesso Liberado!");
          printf("\n          -> Logando..\n\n");
          sleep(2);
          return PAM_SUCCESS;
      }else{
        system("clear");
          printf("\n\n  -> Acesso bloqueado!");
          printf("\n          ->  Tente novamente.\n\n");
          sleep(2);
          return PAM_AUTH_ERR;
      }
}
    
