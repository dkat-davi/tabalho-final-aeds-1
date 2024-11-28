#include <stdio.h>

struct Veiculo
{
    int renavam;
    char nomeProprietario[21];
    int anoFabricacao;
    char cor[4];
    char marca[5];
    double preco;
};

int main()
{
    struct Veiculo veiculos;

    printf("Nome do veiculo: ");
    fgets(veiculos.nomeProprietario, 20, stdin);

    printf("Este é o nome do veiculo: %s", veiculos.nomeProprietario);

    return 0;
}