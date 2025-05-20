#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar os dados da carta
struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

// Função para ler os dados da carta
void lerCarta(struct Carta *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);

    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%3s", carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("População: ");
    while (scanf("%lu", &carta->populacao) != 1 || carta->populacao <= 0) {
        printf("Entrada inválida. Digite um número positivo: ");
        while (getchar() != '\n');
    }

    printf("Área (km²): ");
    while (scanf("%f", &carta->area) != 1 || carta->area <= 0) {
        printf("Entrada inválida. Digite um número positivo para a área: ");
        while (getchar() != '\n');
    }

    printf("PIB (em bilhões): ");
    while (scanf("%f", &carta->pib) != 1 || carta->pib <= 0) {
        printf("Entrada inválida. Digite um valor positivo para o PIB: ");
        while (getchar() != '\n');
    }

    printf("Número de Pontos Turísticos: ");
    while (scanf("%d", &carta->pontosTuristicos) != 1 || carta->pontosTuristicos < 0) {
        printf("Entrada inválida. Digite um número inteiro não-negativo: ");
        while (getchar() != '\n');
    }

    // Cálculos
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000.0f) / carta->populacao;
    carta->superPoder = (float)carta->populacao +
                        carta->area +
                        (carta->pib * 1000000000.0f) +
                        carta->pontosTuristicos +
                        carta->pibPerCapita +
                        (1.0f / carta->densidadePopulacional); // quanto menor a densidade, maior o poder
}

// Função para exibir os dados da carta
void exibirCarta(struct Carta carta, int numero) {
    printf("\n--- Informações da Carta %d ---\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

// Função para comparar atributos e imprimir vencedores
void compararCartas(struct Carta c1, struct Carta c2) {
    printf("\n--- Resultados das Comparações ---\n");

    int resultado;

    // População
    resultado = c1.populacao > c2.populacao ? 1 : 0;
    printf("População: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // Área
    resultado = c1.area > c2.area ? 1 : 0;
    printf("Área: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // PIB
    resultado = c1.pib > c2.pib ? 1 : 0;
    printf("PIB: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // Pontos turísticos
    resultado = c1.pontosTuristicos > c2.pontosTuristicos ? 1 : 0;
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // PIB per capita
    resultado = c1.pibPerCapita > c2.pibPerCapita ? 1 : 0;
    printf("PIB per capita: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // Densidade populacional (menor vence)
    resultado = c1.densidadePopulacional < c2.densidadePopulacional ? 1 : 0;
    printf("Densidade Populacional: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // Super poder
    resultado = c1.superPoder > c2.superPoder ? 1 : 0;
    printf("Super Poder: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);
}

int main() {
    struct Carta carta1, carta2;

    // Ler dados
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    // Exibir cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Comparar cartas
    compararCartas(carta1, carta2);

    return 0;
}

