# DoS Attack Script - FTP Port Flooder

Este script implementa um **ataque de negação de serviço (DoS)** com o objetivo de tornar o serviço FTP (porta 21) de um servidor alvo indisponível. Este ataque funciona enviando repetidas tentativas de conexão a um servidor FTP na porta 21, sobrecarregando a capacidade do servidor de processar novas conexões.

## O que é um ataque de negação de serviço (DoS)?

Um **ataque de negação de serviço (Denial of Service, DoS)** é uma técnica utilizada para indisponibilizar um serviço, sobrecarregando-o com uma quantidade excessiva de tráfego ou requisições, de forma que ele não consiga responder a requisições legítimas. O objetivo de um ataque DoS é interromper temporariamente ou permanentemente os serviços de uma máquina conectada à rede, fazendo com que os usuários não consigam acessá-los.

Os ataques de negação de serviço podem ser usados por invasores maliciosos, mas também são estudados por pesquisadores de segurança e profissionais para desenvolverem defesas contra essas ameaças.

## Funcionalidade do Script

Este script foi criado para realizar um ataque DoS simples na porta 21 (FTP) de um servidor alvo. Ele repetidamente tenta conectar à porta do servidor alvo, causando uma sobrecarga no serviço FTP, potencialmente levando à indisponibilidade temporária do serviço.

### Uso do Script

#### Compilação

Para compilar o script, utilize o compilador **gcc**:

```gcc DoS.c -g -o dos```

#### Execução

Para executar o script, forneça o endereço IP do servidor alvo como argumento:

```./dos <IP do destino>```

Exemplo:

```./dos 192.168.1.100```

O script começará a realizar tentativas contínuas de conexão à porta FTP (21) do servidor alvo. As tentativas continuarão indefinidamente até que o programa seja interrompido manualmente (Ctrl + C).

### Validação de Argumentos

Se nenhum IP for passado ao script, ele exibirá uma mensagem explicando o modo de uso correto:

Uso: ./dos <IP do destino>


## ⚠️ **Aviso Legal**

**Este script foi desenvolvido apenas para fins educacionais e de pesquisa.**

- **Não deve ser utilizado em sistemas ou redes sem a devida autorização.**
- Realizar ataques de negação de serviço sem permissão é ilegal e pode resultar em severas penalidades legais.
- Utilize este script exclusivamente em ambientes controlados e com a devida autorização, como laboratórios de teste ou sistemas sob sua propriedade.

O uso indevido deste script em redes ou sistemas de terceiros sem autorização é contra a lei e não incentivamos qualquer forma de atividade maliciosa.
