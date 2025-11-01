#include <stdio.h>
#include <string.h>

struct Carta {
    char nome[50];
    float populacao;
    float area;
    float pib;
    float densidade;
};

int main() {
    // Cartas pré-cadastradas
    struct Carta carta1 = {"Brasil", 213.0, 8516.0, 22000.0, 25.0};
    struct Carta carta2 = {"Canadá", 38.0, 9976.0, 18000.0, 4.0};

    int atributo1, atributo2;
    float valor1_c1, valor2_c1;
    float valor1_c2, valor2_c2;
    float soma1, soma2;

    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n\n");
    printf("Carta 1: %s\nCarta 2: %s\n\n", carta1.nome, carta2.nome);

    // --- MENU DE ATRIBUTOS ---
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    // Verifica validade da primeira opção
    if (atributo1 < 1 || atributo1 > 4) {
        printf("Opção inválida!\n");
        return 0;
    }

    // --- MENU DINÂMICO (remove o atributo já escolhido) ---
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    switch (atributo1) {
        case 1:
            printf("2 - Área\n3 - PIB\n4 - Densidade Demográfica\n");
            break;
        case 2:
            printf("1 - População\n3 - PIB\n4 - Densidade Demográfica\n");
            break;
        case 3:
            printf("1 - População\n2 - Área\n4 - Densidade Demográfica\n");
            break;
        case 4:
            printf("1 - População\n2 - Área\n3 - PIB\n");
            break;
    }

    printf("Opção: ");
    scanf("%d", &atributo2);

    // Impede repetir atribu
    if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 4) {
        printf("Opção inválida ou repetida!\n");
        return 0;
    }

    // --- OBTENDO VALORES DOS ATRIBUTOS ---
    switch (atributo1) {
        case 1: valor1_c1 = carta1.populacao; valor1_c2 = carta2.populacao; break;
        case 2: valor1_c1 = carta1.area; valor1_c2 = carta2.area; break;
        case 3: valor1_c1 = carta1.pib; valor1_c2 = carta2.pib; break;
        case 4: valor1_c1 = carta1.densidade; valor1_c2 = carta2.densidade; break;
    }

    switch (atributo2) {
        case 1: valor2_c1 = carta1.populacao; valor2_c2 = carta2.populacao; break;
        case 2: valor2_c1 = carta1.area; valor2_c2 = carta2.area; break;
        case 3: valor2_c1 = carta1.pib; valor2_c2 = carta2.pib; break;
        case 4: valor2_c1 = carta1.densidade; valor2_c2 = carta2.densidade; break;
    }

    // --- EXIBE OS VALORES ---
    printf("\n=== Comparação ===\n");
    printf("Atributo 1: %d\n", atributo1);
    printf("%s: %.2f | %s: %.2f\n", carta1.nome, valor1_c1, carta2.nome, valor1_c2);

    printf("\nAtributo 2: %d\n", atributo2);
    printf("%s: %.2f | %s: %.2f\n", carta1.nome, valor2_c1, carta2.nome, valor2_c2);

    // --- APLICA REGRAS (ternário + exceção densidade) ---
    float resultado1 = (atributo1 == 4) ? 
        (valor1_c1 < valor1_c2 ? 1 : 0) : (valor1_c1 > valor1_c2 ? 1 : 0);

    float resultado2 = (atributo2 == 4) ? 
        (valor2_c1 < valor2_c2 ? 1 : 0) : (valor2_c1 > valor2_c2 ? 1 : 0);

    // Soma dos atributos
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f | %s: %.2f\n", carta1.nome, soma1, carta2.nome, soma2);

    // --- RESULTADO FINAL ---
    printf("\n=== Resultado Final ===\n");
    if (soma1 > soma2)
        printf("Vencedor: %s!\n", carta1.nome);
    else if (soma2 > soma1)
        printf("Vencedor: %s!\n", carta2.nome);
    else
        printf("Empate!\n");

    return 0;
}
