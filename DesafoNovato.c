#include <stdio.h>


// Estrutura para armazenar os dados da carta
struct Carta {
    char estado[3]; // Ex: "SP", "RJ"
    char codigo[4]; // Ex: "A01"
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

    printf("Estado: ");
    scanf(" %2s", carta->estado);

    printf("Código da Carta: ");
    scanf(" %3s", carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("População: ");
    while (scanf("%lu", &carta->populacao) != 1 || carta->populacao <= 0) {
        printf("Digite o numero da população: ");
        while (getchar() != '\n');
    }

    printf("Área (km²): ");
    (scanf("%f", &carta->area) != 1 || carta->area <= 0);

    printf("PIB: ");
    while (scanf("%f", &carta->pib) != 1 || carta->pib <= 0) {
        printf("Digite o PIB: ");
        while (getchar() != '\n');
    }

    printf("Número de Pontos Turísticos: ");
    while (scanf("%d", &carta->pontosTuristicos) != 1 || carta->pontosTuristicos < 0) {
        printf("Digite o numero de pontos turisticos: ");
        while (getchar() != '\n');
    }

    // Cálculos
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000.0f) / carta->populacao;

    // Super Poder: Combina atributos. Quanto menor a densidade, maior o poder.
    carta->superPoder = carta->populacao +
                        carta->area +
                        (carta->pib * 1000000000.0f) +
                        carta->pontosTuristicos +
                        carta->pibPerCapita +
                        (1.0f / carta->densidadePopulacional);
}

// Função para exibir os dados da carta
void exibirCarta(struct Carta carta, int numero) {
    printf("\n--- Informações da Carta %d ---\n", numero);
    printf("Estado: %s\n", carta.estado);
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
    printf("\n--- Comparação de Cartas ---\n");

    // População
    printf("\n[População] %s: %lu vs %s: %lu\n", c1.nomeCidade, c1.populacao, c2.nomeCidade, c2.populacao);
    if (c1.populacao > c2.populacao)
        printf("Vencedor: %s (Carta 1)\n", c1.nomeCidade);
    else if (c2.populacao > c1.populacao)
        printf("Vencedor: %s (Carta 2)\n", c2.nomeCidade);
    else
        printf("Empate!\n");

    // Área
    printf("\n[Área] %s: %.2f km² vs %s: %.2f km²\n", c1.nomeCidade, c1.area, c2.nomeCidade, c2.area);
    if (c1.area > c2.area)
        printf("Vencedor: %s (Carta 1)\n", c1.nomeCidade);
    else if (c2.area > c1.area)
        printf("Vencedor: %s (Carta 2)\n", c2.nomeCidade);
    else
        printf("Empate!\n");

    // PIB
    printf("\n[PIB] %s: R$ %.2f bi vs %s: R$ %.2f bi\n", c1.nomeCidade, c1.pib, c2.nomeCidade, c2.pib);
    if (c1.pib > c2.pib)
        printf("Vencedor: %s (Carta 1)\n", c1.nomeCidade);
    else if (c2.pib > c1.pib)
        printf("Vencedor: %s (Carta 2)\n", c2.nomeCidade);
    else
        printf("Empate!\n");

    // Pontos turísticos
    printf("\n[Pontos Turísticos] %s: %d vs %s: %d\n", c1.nomeCidade, c1.pontosTuristicos, c2.nomeCidade, c2.pontosTuristicos);
    if (c1.pontosTuristicos > c2.pontosTuristicos)
        printf("Vencedor: %s (Carta 1)\n", c1.nomeCidade);
    else if (c2.pontosTuristicos > c1.pontosTuristicos)
        printf("Vencedor: %s (Carta 2)\n", c2.nomeCidade);
    else
        printf("Empate!\n");

    // PIB per capita
    printf("\n[PIB per capita] %s: R$ %.2f vs %s: R$ %.2f\n", c1.nomeCidade, c1.pibPerCapita, c2.nomeCidade, c2.pibPerCapita);
    if (c1.pibPerCapita > c2.pibPerCapita)
        printf("Vencedor: %s (Carta 1)\n", c1.nomeCidade);
    else if (c2.pibPerCapita > c1.pibPerCapita)
        printf("Vencedor: %s (Carta 2)\n", c2.nomeCidade);
    else
        printf("Empate!\n");

    // Densidade populacional (MENOR vence)
    printf("\n[Densidade Populacional] %s: %.2f hab/km² vs %s: %.2f hab/km²\n", c1.nomeCidade, c1.densidadePopulacional, c2.nomeCidade, c2.densidadePopulacional);
    if (c1.densidadePopulacional < c2.densidadePopulacional)
        printf("Vencedor: %s (Carta 1)\n", c1.nomeCidade);
    else if (c2.densidadePopulacional < c1.densidadePopulacional)
        printf("Vencedor: %s (Carta 2)\n", c2.nomeCidade);
    else
        printf("Empate!\n");

    // Super poder
    printf("\n[Super Poder] %s: %.2f vs %s: %.2f\n", c1.nomeCidade, c1.superPoder, c2.nomeCidade, c2.superPoder);
    if (c1.superPoder > c2.superPoder)
        printf("Vencedor: %s (Carta 1)\n", c1.nomeCidade);
    else if (c2.superPoder > c1.superPoder)
        printf("Vencedor: %s (Carta 2)\n", c2.nomeCidade);
    else
        printf("Empate!\n");
}

int main() {
    struct Carta carta1, carta2;

    // Ler dados das cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    // Exibir dados das cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Comparar cartas
    compararCartas(carta1, carta2);

    return 0;
}
