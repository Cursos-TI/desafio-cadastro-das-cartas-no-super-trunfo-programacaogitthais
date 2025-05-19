#include <stdio.h>

int main() {
    /*
    Soma (+)
    Subtração (-)
    Multiplicação (*)
    Divisão (/)
    */

    int numero1, numero2;
    int soma, subtracao, multiplicacao, divisao;

    printf("Entre com o numero 1: \n");
    scanf("%d", &numero1); // Correção: "%d" e &numero1 fora das aspas

    printf("Entre com o numero 2: \n");
    scanf("%d", &numero2);

    // operação soma
    soma = numero1 + numero2;

    // operação subtração
    subtracao = numero1 - numero2;

    // operação multiplicação
    multiplicacao = numero1 * numero2;

    // operação divisão com verificação de zero
    if (numero2 != 0) {
        divisao = numero1 / numero2;
    } else {
        printf("Erro: divisão por zero!\n");
        divisao = 0; // valor padrão para evitar erro
    }

    printf("A soma é: %d \n", soma);
    printf("A subtração é: %d \n", subtracao);
    printf("A multiplicação é: %d \n", multiplicacao);
    
    if (numero2 != 0) {
        printf("A divisão é: %d \n", divisao);
    }

    return 0;
}

#include <stdio.h>

int main() {
    
    int nota1, nota2, nota3;
    int media;


    printf("***Programa de calculo de média***\n");

    printf("Digite a sua primeira nota: \n");
    scanf("%d", &nota1);

    printf("Digite sua segunda nota: \n");
    scanf("%d", &nota2);

    printf("Digite sua terceira nota: \n");
    scanf("%d", &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    printf("A média é: %d", media);
    

    return 0;
}