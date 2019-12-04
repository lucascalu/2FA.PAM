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


void makeDirAcesso(){

    
    struct stat st = {0};
	
   
	if (stat("/etc/pam.d/pam.acesso", &st) == -1) {
		if(mkdir("/etc/pam.d/pam.acesso", 0700) == 0){
            printf("    Diretório criado com Sucesso: /pam.acesso\n");
		}else{
            printf("    Erro ao criar diretório: /pam.acesso\n");
        }
	}else{
            printf("    Diretório ja existente: /pam.acesso\n");
    }
}

void makeDirLog(){

        
        struct stat st = {0};
        
        
        if (stat("/etc/pam.d/pam.acesso/log", &st) == -1) {
                if(mkdir("/etc/pam.d/pam.acesso/log", 0700) == 0){
                    printf("    Diretório criado com Sucesso: /log\n");
                }else{
                    printf("    Erro ao criar diretório: /log\n");
                }
            }else{
                    printf("    Diretório ja existente: /log\n");
        }
}

void makeFileSerial(){
    FILE *acesso1_serial;
    
    acesso1_serial = fopen("/etc/pam.d/pam.acesso/acesso.serial", "a");

    if (acesso1_serial == NULL){
        printf("    Erro ao criar arquivo de seriais.\n");
    }
    else{
        printf("    Arquivo de seriais criado com sucesso.\n");
    }
}

void makeFileLog(){
    FILE *log;
    
    log = fopen("/etc/pam.d/pam.acesso/log/login", "a");

    if (log == NULL){
        printf("    Erro ao criar arquivo de histórico de logins.\n");
    }
    else{
        printf("    Arquivo de histórico de logins criado com sucesso.\n");
    }
}


int verAcesso(){
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
        printf("Erro");
    }
 
    buf[len - 1] = 0;

    int qtd = strlen(buf);

    return qtd;
    
}

char verSerial(){
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
 
    buf[len - 1] = 0;
    

    return buf;

}


void addUser( char nome[256] ){
    ssize_t len;
     
    char buf[256], *p;
    char buf2[256];
    int i;
   
    len = readlink("/*.*", buf, 256);
   
    buf[len] = 0;
   
    sprintf(buf2, "%s/%s", "/*.*", buf);
    for (i=0; i<6; i++) {
        p = strrchr(buf2, '/');
        *p = 0;
    }
   
    strcat(buf2, "/serial");

    int f = open(buf2, 0);
    len = read(f, buf, 256);
    if (len <= 0) {
        
    }
 
    buf[len - 1] = 0;

    FILE *pont_arq; 
        
       
        pont_arq = fopen("/etc/pam.d/pam.acesso/acesso.serial", "w");
        
       
        if(pont_arq == NULL)
        {
        printf("    Erro na abertura do arquivo!");
        }
        
        
        fprintf(pont_arq, "%s", buf);

        
        fclose(pont_arq);

        puts("    Acesso cadastrado com sucesso.\n");

}

int main(int argc, char *argv[]){
    system("clear");

    
    
    puts("\n-> Bem vindo.");
    system("read -p \"\nApós seguir as instruções, pressione enter para continuar...\" foo");

    system("clear"); 

     puts("\n-> Iniciando instalação:");
    puts("---------------------------------------------------");
    sleep(2);

    puts("\n-> Criando diretórios de configuração do módulo:");
    puts("   '/etc/pam.d/pam.acesso'");
    puts("   '/etc/pam.d/pam.acesso/log'");
    makeDirAcesso();
    makeDirLog();
    sleep(2);

    puts("\n-> Criando arquivo que armazena os seriais:");
    puts("   '/etc/pam.d/pam.acesso'");
    puts("   '/etc/pam.d/pam.acesso/log'");
    makeFileSerial();
    makeFileLog(); 

    char nome[100]; 

    puts("\n-> Criando primeiro acesso liberado:");

    addUser(nome);

    system("read -p \"Pressione enter para continuar...\" foo");




}
