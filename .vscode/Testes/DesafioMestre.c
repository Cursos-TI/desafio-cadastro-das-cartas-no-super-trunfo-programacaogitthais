#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Carta {
    char nomePais[50];
    char codigo[4];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Cadastro da carta
void lerCarta(struct Carta *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);
    printf("Nome do País: ");
    scanf(" %[^\n]", carta->nomePais);

    printf("Código da Carta: ");
    scanf(" %3s", carta->codigo);

    printf("População: ");
    while (scanf("%lu", &carta->populacao) != 1 || carta->populacao <= 0) {
        printf("Digite um valor válido: ");
        while (getchar() != '\n');
    }

    printf("Área (km²): ");
    while (scanf("%f", &carta->area) != 1 || carta->area <= 0) {
        printf("Digite um valor válido: ");
        while (getchar() != '\n');
    }

    printf("PIB (em bilhões): ");
    while (scanf("%f", &carta->pib) != 1 || carta->pib <= 0) {
        printf("Digite um valor válido: ");
        while (getchar() != '\n');
    }

    printf("Número de Pontos Turísticos: ");
    while (scanf("%d", &carta->pontosTuristicos) != 1 || carta->pontosTuristicos < 0) {
        printf("Digite um valor válido: ");
        while (getchar() != '\n');
    }

    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000.0f) / carta->populacao;
}

// Exibir informações da carta
void exibirCarta(struct Carta carta, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("País: %s\n", carta.nomePais);
    printf("Código: %s\n", carta.codigo);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
}

// Retorna o valor do atributo
float obterValor(struct Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontosTuristicos;
        case 5: return carta.densidadePopulacional;
        case 6: return carta.pibPerCapita;
        default: return 0.0f;
    }
}

// Nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per capita";
        default: return "Desconhecido";
    }
}

// Menu dinâmico de seleção de atributo
int escolherAtributo(int bloqueado) {
    int escolha;
    do {
        printf("\nEscolha um atributo para comparação:\n");
        if (bloqueado != 1) printf("1. População\n");
        if (bloqueado != 2) printf("2. Área\n");
        if (bloqueado != 3) printf("3. PIB\n");
        if (bloqueado != 4) printf("4. Pontos Turísticos\n");
        if (bloqueado != 5) printf("5. Densidade Populacional\n");
        if (bloqueado != 6) printf("6. PIB per capita\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        if (escolha < 1 || escolha > 6 || escolha == bloqueado) {
            printf("Opção inválida ou já selecionada. Tente novamente.\n");
        }
    } while (escolha < 1 || escolha > 6 || escolha == bloqueado);
    return escolha;
}

// Comparação final de dois atributos
void compararDuasCaracteristicas(struct Carta c1, struct Carta c2) {
    int attr1 = escolherAtributo(0);        // Primeiro atributo
    int attr2 = escolherAtributo(attr1);    // Segundo atributo (diferente)

    float valor1_c1 = obterValor(c1, attr1);
    float valor2_c1 = obterValor(c1, attr2);
    float valor1_c2 = obterValor(c2, attr1);
    float valor2_c2 = obterValor(c2, attr2);

    // Mostrar comparação por atributo
    printf("\n--- Comparação Atributo 1: %s ---\n", nomeAtributo(attr1));
    printf("%s: %.2f\n", c1.nomePais, valor1_c1);
    printf("%s: %.2f\n", c2.nomePais, valor1_c2);
    int menorVence1 = (attr1 == 5);
    const char* vencedor1 = (valor1_c1 == valor1_c2) ? "Empate" :
                            (menorVence1 ? (valor1_c1 < valor1_c2 ? c1.nomePais : c2.nomePais)
                                         : (valor1_c1 > valor1_c2 ? c1.nomePais : c2.nomePais));
    printf("Vencedor do Atributo 1: %s\n", vencedor1);

    printf("\n--- Comparação Atributo 2: %s ---\n", nomeAtributo(attr2));
    printf("%s: %.2f\n", c1.nomePais, valor2_c1);
    printf("%s: %.2f\n", c2.nomePais, valor2_c2);
    int menorVence2 = (attr2 == 5);
    const char* vencedor2 = (valor2_c1 == valor2_c2) ? "Empate" :
                            (menorVence2 ? (valor2_c1 < valor2_c2 ? c1.nomePais : c2.nomePais)
                                         : (valor2_c1 > valor2_c2 ? c1.nomePais : c2.nomePais));
    printf("Vencedor do Atributo 2: %s\n", vencedor2);

    // Soma dos atributos
    float soma_c1 = (menorVence1 ? -valor1_c1 : valor1_c1) + (menorVence2 ? -valor2_c1 : valor2_c1);
    float soma_c2 = (menorVence1 ? -valor1_c2 : valor1_c2) + (menorVence2 ? -valor2_c2 : valor2_c2);

    printf("\n--- Resultado Final ---\n");
    printf("%s - Soma dos Atributos: %.2f\n", c1.nomePais, soma_c1);
    printf("%s - Soma dos Atributos: %.2f\n", c2.nomePais, soma_c2);

    if (soma_c1 == soma_c2) {
        printf("Resultado: Empate!\n");
    } else {
        const char* vencedor = soma_c1 > soma_c2 ? c1.nomePais : c2.nomePais;
        printf("Vencedor Geral: %s\n", vencedor);
    }
}

int main() {
    struct Carta carta1, carta2;

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    compararDuasCaracteristicas(carta1, carta2);

    return 0;
}
