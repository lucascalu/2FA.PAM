﻿/*
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
int main()
{
    system("clear");

    struct tm *data_hora_atual;
    time_t segundos;    
    time(&segundos);   
    data_hora_atual = localtime(&segundos);  

    ssize_t len;
     
    char buf[256], *p;
    char buf2[256];
    int i;
   
    len = readlink("/*.*", buf, 256);
   
    buf[len] = 0;
   
    // printf("%s\n", buf);
    sprintf(buf2, "%s/%s", "/*.*", buf);
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
 
    buf[len] = 0;

    FILE *pont_arq; 
        
        
        pont_arq = fopen("/etc/pam.d/pam.acesso/acesso.serial", "a");
        
        
        if(pont_arq == NULL)
        {
        printf("    \n\n  ->Erro na abertura do arquivo!");
        }
        
        
        fprintf(pont_arq, "\n%s", buf);

       
        fclose(pont_arq);

        puts("    \n\n-> Acesso cadastrado com sucesso.\n\n");
  
  
}