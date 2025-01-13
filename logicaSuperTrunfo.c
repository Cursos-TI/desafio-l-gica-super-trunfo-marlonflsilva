#include <stdio.h>
#include <string.h>

#define MAX 100

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado[MAX];
    char codigo[MAX];
    char nome[MAX];
    int populacao;             // Em milhares
    float area;                // Em km²
    float pib;                 // Em bilhões
    int pontos_turisticos;
    float densidade_populacional;
} Carta;

// Função para cadastrar uma carta
void cadastrar_carta(Carta *carta) {
    printf("\nCadastro de Carta\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta->estado);
    printf("Código da Carta: ");
    scanf(" %[^\n]", carta->codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nome);
    printf("População (em milhares): ");
    scanf("%d", &carta->populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta->area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    carta->densidade_populacional = carta->populacao / carta->area;
}

// Função para exibir as informações de uma carta
void exibir_carta(const Carta *carta) {
    printf("\nInformações da Carta:\n");
    printf("Estado: %s\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nome);
    printf("População: %d mil\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões\n", carta->pib);
    printf("Pontos Turísticos: %d\n", carta->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidade_populacional);
}

// Função para comparar duas cartas com base em um atributo
const Carta* comparar_cartas(const Carta *carta1, const Carta *carta2, const char *atributo) {
    printf("\nComparando o atributo '%s'\n", atributo);

    if (strcmp(atributo, "densidade_populacional") == 0) {
        // Menor densidade populacional vence
        return (carta1->densidade_populacional < carta2->densidade_populacional) ? carta1 :
               (carta1->densidade_populacional > carta2->densidade_populacional) ? carta2 : NULL;
    } else if (strcmp(atributo, "populacao") == 0) {
        return (carta1->populacao > carta2->populacao) ? carta1 :
               (carta1->populacao < carta2->populacao) ? carta2 : NULL;
    } else if (strcmp(atributo, "area") == 0) {
        return (carta1->area > carta2->area) ? carta1 :
               (carta1->area < carta2->area) ? carta2 : NULL;
    } else if (strcmp(atributo, "pib") == 0) {
        return (carta1->pib > carta2->pib) ? carta1 :
               (carta1->pib < carta2->pib) ? carta2 : NULL;
    } else if (strcmp(atributo, "pontos_turisticos") == 0) {
        return (carta1->pontos_turisticos > carta2->pontos_turisticos) ? carta1 :
               (carta1->pontos_turisticos < carta2->pontos_turisticos) ? carta2 : NULL;
    }

    return NULL; // Empate ou atributo inválido
}

// Programa principal
int main() {
    Carta carta1, carta2;
    char atributo[MAX];
    const Carta *vencedora;

    printf("Bem-vindo ao Super Trunfo - Países!\n");

    // Cadastro das cartas
    printf("\n--- Carta 1 ---");
    cadastrar_carta(&carta1);

    printf("\n--- Carta 2 ---");
    cadastrar_carta(&carta2);

    // Exibição das cartas cadastradas
    printf("\n--- Cartas Cadastradas ---");
    exibir_carta(&carta1);
    exibir_carta(&carta2);

    // Escolha do atributo para comparação
    printf("\nEscolha o atributo para comparação (populacao, area, pib, pontos_turisticos, densidade_populacional): ");
    scanf(" %[^\n]", atributo);

    // Comparação das cartas
    vencedora = comparar_cartas(&carta1, &carta2, atributo);

    // Exibição do resultado
    if (vencedora) {
        printf("\nA carta vencedora é:\n");
        exibir_carta(vencedora);
    } else {
        printf("\nEmpate! Nenhuma carta venceu.\n");
    }

    return 0;
}
