# 2FA.PAM
Projeto Desenvolvido em Sala de Aula FATEC AMERICANA


Sistemas Operacionais II<br>
Professor: Rossano Pablo Pinto<br>
Alunos: 
        <li>Alan Vidal</li>
        <li>Daniel Evaldo</li>
        <li>Leonardo B Rodrigues</li>
        <li>Lucas S Calu</li>
       
<hr>

Esse projeto é uma das soluções para quem precisa de um modulo de autenticação via ssh, Seu funcionamento se da através da instalação do módulo e algumas configurações básicas.
<br>
<br>


<hr>

<h4> >> Instalação</h4>

  Para instalar inicie o terminal no diretório dos arquivos do módulo:<br>
  Como usuário root digite:<br>
    
    $ make
    $ make install
    
  
  Pronto, o seu módulo está instalado.<br>
  Abaixo segue a descrição do funcionamento do programa de instalação.
<hr>
<h4> >> Programa de Instalação</h4>

  O instalador cria duas pastas e dois arquivos necessários<br>
  para o funcionamento do móulo:<br>
    <br><li>/etc/pam.d/pam.acesso</li>
      <b>login</b> : Aqui ficam localizados os seriais de acesso instalados, apenas com o usuário root se tem acesso.<br>
    <br><li>/etc/pam.d/pam.acesso/log</li>
      <b>log</b> : Aqui fica localizado o arquivo de log, onde registra data e hora de todos os logins efetuados, e o serial que foi utilizado.<br>
<hr>
<h4> >> Demais funcionalidades</h4>
    <li>Desinstalar 
        
       $ make uninstall
        
        
        
        
        
        
        
        
    
    
    
    
    
 Remove todos os diretórios e arquivos e desativa o módulo.</li>
    
<hr>

    
 <hr>
 <h4> >> Observações</h4>
    <li>Controle de acesso 
        
       O Controle de acesso se dá através da exclusão o permanência do arquivo 
       acesso.serial na pasta etc/pam.d/pam.acesso 
        
        
        
        
        
        
        
        
    
    
    
    
    
 É necessário dar permissões ao usuario que irá manipular o arquivo no diretório etc/pam.d através do comando chmod 777 pam.acesso.</li>
    
<hr>
<h4> >> Requisitos</h4>
    <li>Putty ou Win Scp e Open SSH</li>
        
       
    
<hr>

    
 



