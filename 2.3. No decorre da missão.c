
2.3.	No decorre da missão, o Viajante e desbravador de segredos terá que fazer a modularização utilizada em cada conjunto texto base/texto pergunta que segue abaixo:


__________________________________________________________________________________________________________________________________________________________________________
__________________________________________________________________________________________________________________________________________________________________________



/*
  viajante_rede_ip.c
  Modularização em C das 21 situações descritas.
  Cada situação é implementada como uma função separada que recebe um
  ponteiro para o viajante (Traveler) e um módulo com texto_base / texto_pergunta.

  Compilar: gcc -o viajante_rede_ip viajante_rede_ip.c -std=c11
  Executar: ./viajante_rede_ip

  Observações:
  - Este código é uma simulação textual: cada "situação" imprime o que faria
    ou devolve respostas simuladas.
  - Está escrito em Português para facilitar leitura.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG 1024
#define MAX_MODULES 32

typedef enum {FALSE=0, TRUE=1} bool;

typedef struct {
    char ip_address[64];
    char network_name[64];
} IPInfo;

typedef struct {
    char name[64];
    IPInfo current_ip;
    char inventory[5][64];
    int inventory_count;
    char log[MAX_LOG];
    int backups_made;
    bool infected;
} Traveler;

typedef struct {
    const char *base_text;
    const char *question_text;
    void (*action)(Traveler *t);
} Module;

/* Utilitários */
void append_log(Traveler *t, const char *txt) {
    strncat(t->log, txt, sizeof(t->log)-strlen(t->log)-1);
    strncat(t->log, "\n", sizeof(t->log)-strlen(t->log)-1);
}

void random_wait_short() {
    /* Simula algum processamento curto */
    int wait = rand() % 10000000;
    volatile int i; for (i=0;i<wait;i++); /* busy wait leve */
}

/* Funções de cada situação (1..21) */
void situacao1(Traveler *t) {
    printf("[1] Você está na rede de IP. Três redes do pensamento são acessadas.\n");
    append_log(t, "Acesso inicial: redes do pensamento A, B, C detectadas.");
}

void situacao2(Traveler *t) {
    printf("[2] Visualiza um acesso de IP diferente de outra rede.\n");
    snprintf(t->current_ip.ip_address, sizeof(t->current_ip.ip_address), "203.0.%d.%d", rand()%256, rand()%256);
    strcpy(t->current_ip.network_name, "Rede-Remota-Exotica");
    char buffer[128];
    snprintf(buffer, sizeof(buffer), "Saltou para IP: %s (%s)", t->current_ip.ip_address, t->current_ip.network_name);
    append_log(t, buffer);
}

void situacao3(Traveler *t) {
    printf("[3] Você tem um sinal de bit e byte.\n");
    append_log(t, "Sinal detectado: 10101100 01101001 (amostra)");
}

void situacao4(Traveler *t) {
    printf("[4] Tecnologias avançadas observadas.\n");
    append_log(t, "Catalogadas: holo-arquitetura, qubits de roteamento, tecido inteligente.");
}

void situacao5(Traveler *t) {
    printf("[5] Visualiza e/ou ouve um sinal de rádio.\n");
    append_log(t, "Sinal rádio: portadora modulada com pulso irregular (possível mensagem).");
}

void situacao6(Traveler *t) {
    printf("[6] Ouço um Código Morse e outros tipos.\n");
    append_log(t, "Código Morse decodificado: 'SORTE' (simulação). Outros: tonalidades complexas.");
}

void situacao7(Traveler *t) {
    printf("[7] Outros tipos de visão futuras.\n");
    append_log(t, "Visão futura: overlay de camadas de tempo e dependências tecnológicas.");
}

void situacao8(Traveler *t) {
    printf("[8] Tipos de audição futuras.\n");
    append_log(t, "Audição: espectro ultrassônico traduzido em padrões semânticos.");
}

void situacao9(Traveler *t) {
    printf("[9] Você sente paladar (sintético).\n");
    append_log(t, "Paladar digital: detectado gosto metálico de dados; intensidade 7/10.");
}

void situacao10(Traveler *t) {
    printf("[10] Usabilidade do tato.\n");
    append_log(t, "Tato: texturas de pacotes percebidas como rugosidade alta.");
}

void situacao11(Traveler *t) {
    printf("[11] Sentido vestibular em uso.\n");
    append_log(t, "Vestibular: sensação de rotação quando mudando entre redes.");
}

void situacao12(Traveler *t) {
    printf("[12] Tecnologia da propriocepção ativada.\n");
    append_log(t, "Propriocepção digital: posição relativa na malha de IP estimada.");
}

void situacao13(Traveler *t) {
    printf("[13] Tentativa de erro de rota (destino).\n");
    append_log(t, "Erro de rota: pacote enviado para gateway incorreto; iniciando correção.");
}

void situacao14(Traveler *t) {
    printf("[14] Feedback do planeta de origem solicitado.\n");
    append_log(t, "Feedback recebido: requisitar mais telemetria e amostras.");
}

void situacao15(Traveler *t) {
    printf("[15] Início de passar mal (simulado). O que você faz?\n");
    append_log(t, "Ação tomada: reduzir taxa de amostragem, ativar auto-checks de integridade.");
}

void situacao16(Traveler *t) {
    printf("[16] Nas horas vagas, você tenta fazer o que?\n");
    append_log(t, "Lazer: mapear padrões estéticos na topologia da rede e compor breves melodias.");
}

void situacao17(Traveler *t) {
    printf("[17] Tentativa de invasão no seu sistema operacional pelo seu IP de navegação.\n");
    if (rand()%4==0) {
        t->infected = TRUE;
        append_log(t, "Ataque bem-sucedido: backdoor leve instalado (simulado).");
    } else {
        append_log(t, "Ataque impedido: sandbox ativado e sessão isolada.");
    }
}

void situacao18(Traveler *t) {
    printf("[18] Encontra um código que reage aos seus sentidos naturais.\n");
    append_log(t, "Código reativo: altera saída conforme microgestos detectados.");
}

void situacao19(Traveler *t) {
    printf("[19] Você precisa definir o protocolo de segurança de IP.\n");
    append_log(t, "Protocolo definido: autenticação mutua + integridade de pacotes + backups periódicos.");
}

void situacao20(Traveler *t) {
    printf("[20] Chega ao destino programado (núcleo da rede). Há três caminhos.\n");
    int choice = rand()%3 + 1;
    char buffer[128];
    snprintf(buffer, sizeof(buffer), "Escolheu o caminho %d no núcleo da rede.", choice);
    append_log(t, buffer);
}

void situacao21(Traveler *t) {
    printf("[21] Descoberta do IP desconhecido e realização de três backups para análise.\n");
    for (int i=0;i<3;i++) {
        t->backups_made++;
        char buffer[128];
        snprintf(buffer, sizeof(buffer), "Backup %d efetuado para análise científica.", i+1);
        append_log(t, buffer);
        random_wait_short();
    }
    append_log(t, "Decisão futura: analisar e decidir implementar ou deletar a tecnologia.");
}

/* Cria módulos com texto base e pergunta (modularização) */
void init_modules(Module modules[], int *count) {
    *count = 21;
    modules[0] = (Module){"Você está na rede de Ip (Protocolo de Internet). Três redes do pensamento são acessadas:", "O que fará perante múltiplas redes de pensamento?", situacao1};
    modules[1] = (Module){"Você visualiza um acesso de Ip diferente de outra rede.", "Que ações toma ao ver um IP desconhecido?", situacao2};
    modules[2] = (Module){"Você tem um sinal de bit e byte.", "Como interpreta o sinal?", situacao3};
    modules[3] = (Module){"Tecnologias avançadas",
                              "Como catalogar tecnologias avançadas detectadas?", situacao4};
    modules[4] = (Module){"Você visualiza e ouve um sinal de rádio.", "Qual a prioridade de análise?", situacao5};
    modules[5] = (Module){"Ouço um Código Morse e outros tipos.", "Como decodificar e reagir?", situacao6};
    modules[6] = (Module){"Outros tipos de visão futuras.", "Que informações adiante a visão revela?", situacao7};
    modules[7] = (Module){"Tipos de audição futuras:", "Que padrões sonoros procurar?", situacao8};
    modules[8] = (Module){"Você sente paladar", "O que o paladar digital revela?", situacao9};
    modules[9] = (Module){"Você faz usabilidade do tato", "Que ações o tato guia?", situacao10};
    modules[10] = (Module){"Você faz usabilidade do Sentido Vestibular", "Como estabilizar movimentos?", situacao11};
    modules[11] = (Module){"Você usa tecnologia da Propriocepção", "Como mapear sua posição?", situacao12};
    modules[12] = (Module){"Acontece uma tentativa de erro de rota (destino)", "Qual a estratégia de correção?", situacao13};
    modules[13] = (Module){"Alguém do Planeta de origem pede o feedback de sua viagem", "Que dados enviar?", situacao14};
    modules[14] = (Module){"Inicio de passar mal, o que você faz", "Quais medidas de auto-cuidado tomar?", situacao15};
    modules[15] = (Module){"Nas horas vagas, você tenta fazer o que", "Que atividades recreativas realizar?", situacao16};
    modules[16] = (Module){"Tentativa de invasão no seu sistema operacional pelo seu Ip de navegação para desviar da rota", "Como defender?", situacao17};
    modules[17] = (Module){"Encontra um código que reage aos seus sentidos naturais", "O que fazer com esse código?", situacao18};
    modules[18] = (Module){"Você precisa definir o protocolo de segurança de Ip.", "Quais regras mínimas?", situacao19};
    modules[19] = (Module){"Você chega ao destino programado (núcleo da rede). Há três caminhos:", "Como escolher o melhor caminho?", situacao20};
    modules[20] = (Module){"Descoberta do Ip desconhecido... três backup para fazer uma análise...", "Implementar ou deletar?", situacao21};
}

/* Inicializa viajante */
void init_traveler(Traveler *t, const char *name) {
    memset(t, 0, sizeof(Traveler));
    strncpy(t->name, name, sizeof(t->name)-1);
    strcpy(t->current_ip.ip_address, "0.0.0.0");
    strcpy(t->current_ip.network_name, "Origem");
    t->inventory_count = 0;
    t->backups_made = 0;
    t->infected = FALSE;
    t->log[0] = '\0';
}

/* Executa todos os módulos em sequência (simulação) */
void run_modules(Traveler *t, Module modules[], int count) {
    for (int i=0;i<count;i++) {
        printf("\n--- Módulo %02d ---\nBase: %s\nPergunta: %s\n", i+1, modules[i].base_text, modules[i].question_text);
        modules[i].action(t);
        random_wait_short();
    }
}

/* Exibe um relatório resumido */
void report(Traveler *t) {
    printf("\n=== Relatório do Viajante: %s ===\n", t->name);
    printf("IP atual: %s (%s)\n", t->current_ip.ip_address, t->current_ip.network_name);
    printf("Backups feitos: %d\n", t->backups_made);
    printf("Infectado: %s\n", t->infected?"Sim":"Não");
    printf("Log: \n%s\n", t->log);
}

int main(void) {
    srand((unsigned)time(NULL));
    Traveler t;
    init_traveler(&t, "Viajante-01");

    Module modules[MAX_MODULES];
    int module_count = 0;
    init_modules(modules, &module_count);

    printf("Iniciando missão do Viajante...\n");
    run_modules(&t, modules, module_count);

    report(&t);
    printf("Missão concluída (simulação).\n");
    return 0;
}
