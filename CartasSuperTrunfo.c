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
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para ler os dados da carta
void lerCarta(struct Carta *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);

    printf("Estado: \n");
    scanf(" %c", &carta->estado); // espaço antes do %c para ignorar o '\n'

    printf("Código da Carta: \n");
    scanf("%s", carta->codigo); 
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade); 

    printf("Digite a população: \n");
    scanf("%d", &carta->populacao); 

    printf("Área (km²): \n");
    scanf("%f", &carta->area) 

    printf("PIB (em bilhões): \n");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos) 

    // Cálculo da densidade populacional
    carta->densidadePopulacional = carta->populacao / carta->area;

    // Cálculo do PIB per capita (transforma PIB de bilhões para reais)
    carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;
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

    // Exibir cálculos adicionais
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
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
