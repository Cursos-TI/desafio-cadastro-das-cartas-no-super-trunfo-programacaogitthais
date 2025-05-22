#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da carta (cidade/país)
struct Carta {
    char nomePais[50];
    char codigo[4];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para ler os dados da carta
void lerCarta(struct Carta *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);

    printf("Nome do País: ");
    scanf(" %[^\n]", carta->nomePais);

    printf("Código da Carta: ");
    scanf(" %3s", carta->codigo);

    printf("População: ");
    while (scanf("%lu", &carta->populacao) != 1 || carta->populacao <= 0) {
        printf("Digite um número positivo: ");
        while (getchar() != '\n');
    }

    printf("Área (km²): ");
    while (scanf("%f", &carta->area) != 1 || carta->area <= 0) {
        printf("Digite um número positivo: ");
        while (getchar() != '\n');
    }

    printf("PIB (em bilhões): ");
    while (scanf("%f", &carta->pib) != 1 || carta->pib <= 0) {
        printf("Digite um valor positivo: ");
        while (getchar() != '\n');
    }

    printf("Número de Pontos Turísticos: ");
    while (scanf("%d", &carta->pontosTuristicos) != 1 || carta->pontosTuristicos < 0) {
        printf("");
        while (getchar() != '\n');
    }

    // Cálculo dos indicadores
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000.0f) / carta->populacao;
}

// Função para exibir as informações da carta
void exibirCarta(struct Carta carta, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("Nome do País: %s\n", carta.nomePais);
    printf("Código: %s\n", carta.codigo);
    printf("População: %lu habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
}

// Função para comparar dois valores
void comparar(char atributo[], float valor1, float valor2, char nome1[], char nome2[], int menorVence) {
    printf("\n--- Comparação: %s ---\n", atributo);
    printf("%s: %.2f\n", nome1, valor1);
    printf("%s: %.2f\n", nome2, valor2);

    if (valor1 == valor2) {
        printf("Resultado: Empate!\n");
    } else if ((menorVence && valor1 < valor2) || (!menorVence && valor1 > valor2)) {
        printf("Resultado: %s venceu!\n", nome1);
    } else {
        printf("Resultado: %s venceu!\n", nome2);
    }
}

// Menu de comparação com switch
void menuComparacao(struct Carta c1, struct Carta c2) {
    int opcao;

    do {
        printf("\n===== MENU DE COMPARAÇÃO =====\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("5. Densidade Populacional\n");
        printf("6. PIB per capita\n");
        printf("0. Sair\n");
        printf("Escolha um atributo para comparar: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                comparar("População", (float)c1.populacao, (float)c2.populacao, c1.nomePais, c2.nomePais, 0);
                break;
            case 2:
                comparar("Área", c1.area, c2.area, c1.nomePais, c2.nomePais, 0);
                break;
            case 3:
                comparar("PIB", c1.pib, c2.pib, c1.nomePais, c2.nomePais, 0);
                break;
            case 4:
                comparar("Pontos Turísticos", (float)c1.pontosTuristicos, (float)c2.pontosTuristicos, c1.nomePais, c2.nomePais, 0);
                break;
            case 5:
                comparar("Densidade Populacional", c1.densidadePopulacional, c2.densidadePopulacional, c1.nomePais, c2.nomePais, 1); // menor vence
                break;
            case 6:
                comparar("PIB per capita", c1.pibPerCapita, c2.pibPerCapita, c1.nomePais, c2.nomePais, 0);
                break;
            case 0:
                printf("Encerrando comparação.\n");
                break;
            default:
                printf("Opção inválida! Escolha entre 0 e 6.\n");
        }

    } while (opcao != 0);
}

int main() {
    struct Carta carta1, carta2;

    // Cadastro das cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    // Exibição das cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Menu para comparação
    menuComparacao(carta1, carta2);

    return 0;
}
