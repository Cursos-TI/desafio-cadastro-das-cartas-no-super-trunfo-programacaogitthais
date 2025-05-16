#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar os dados da carta
struct Carta {
    char estado;
    char codigo[4]; // Exemplo: A01, B03
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Função para ler os dados da carta
void lerCarta(struct Carta *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);

    printf("Estado (A-H): \n");
    scanf(" %c", &carta->estado); // espaço antes de %c para ignorar o '\n'

    printf("Código da Carta: \n");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: \n");
    scanf(" %[^\n]", carta->nomeCidade); // lê até nova linha

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para exibir os dados da carta
void exibirCarta(struct Carta carta, int numero) {
    printf("\n--- Informações da Carta %d ---\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

int main() {
    struct Carta carta1, carta2;

    // Ler os dados das duas cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    // Exibir os dados cadastrados
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0;
}
