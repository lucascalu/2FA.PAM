﻿

pam_acesso2.o: pam_acesso2.c
	gcc -fPIC -lcurl -fno-stack-protector -c pam_acesso2.c

install: pam_acesso2.o
	ld -lcurl -x --shared -o /lib64/security/pam_acesso2.so pam_acesso2.o
	sed -i "4s/^/	auth	  required  pam_acesso2.so\n/" /etc/pam.d/system-auth
	gcc criar_arquivos.c -o criar_arquivos
	gcc addacesso3.c -o add_acesso3
	./criar_arquivos

uninstall:
	rm -f /lib64/security/pam_acesso2.so
	rm -rf /etc/pam.d/pam.acesso
	sed -i '/pam_acesso2/d' /etc/pam.d/system-auth
	clear
	@echo "\n\n -> Módulo de autenticação  removido com sucesso.\n\n"

addpendrive:
	./add_acesso3