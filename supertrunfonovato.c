#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta
typedef struct {
    char estado[3];
    char codigo[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular densidade e PIB per capita
void calcularIndicadores(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para imprimir uma carta
void exibirCarta(Carta c) {
    printf("Cidade: %s (%s)\n", c.nome_cidade, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade_populacional);
    printf("PIB per capita: R$ %.2f\n\n", c.pib_per_capita);
}

int main() {
    // Definindo as duas cartas
    Carta carta1 = {
        "SP", "C001", "São Paulo", 12300000, 1521.11, 750.00, 10
    };
    Carta carta2 = {
        "RJ", "C002", "Rio de Janeiro", 6710000, 1182.30, 350.00, 8
    };

    // Cálculo dos indicadores
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibindo informações
    printf("Comparação de Cartas (Atributo: PIB per capita):\n\n");
    printf("Carta 1:\n");
    exibirCarta(carta1);
    printf("Carta 2:\n");
    exibirCarta(carta2);

    // Comparação de PIB per capita
    if (carta1.pib_per_capita > carta2.pib_per_capita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
