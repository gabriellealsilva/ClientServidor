# ClientServidor

Garanta que o Qt5 e o C++11 estão instalados!

Programa que troca mensagens entre servidor e cliente via protocolo TCP ou UDP

Para conseguir executar cliente e servidor ao mesmo tempo, executar o programa em dois terminais diferentes!

Para exeutar:

qmake
make
./ClientServer

Assim que o programa executa deve-se escolher a função principal do programa, cliente ou servidor.

Logo em seguida, abrirá uma janela em que pede a escolha do protocolo, TCP ou UDP.

No programa em questão, apenas o servidor envia e o cliente recebe. Lembre-se de configurar os dois com o mesmo protocolo.

Se Servidor foi escolhido: Coloque úm número de porta entre 1024 e 65535 para se conectar a porta desejada. Insira a mensagem no campo indicado e clique em Enviar para enviar a mensagem pra porta selecionada.

Se Cliente foi escolhido: Selecione o IP (que por padrão será o da sua máquina) e a porta do servidor desejado, depois clique em Conectar para se conectar a ele. As mensagens enviadas pelo servidor serão mostradas na tela branca.


Funções não-implementadas: CRC e Checksum.
