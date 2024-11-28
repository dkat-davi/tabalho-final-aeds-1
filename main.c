#include <stdio.h>
#include <stdlib.h>

#define MAX_VEICULOS 2

struct Veiculo
{
    int renavam;
    char nomeProprietario[51];
    int anoFabricacao;
    char cor[4];
    char marca[5];
    double preco;
};

void mostrarMenu()
{
    printf("\n==============================================================\n");
    printf("                       MENU PRINCIPAL                        \n");
    printf("==============================================================\n");
    printf("1. Adicionar Veículo\n");
    printf("2. Listar Veículos\n");
    printf("3. Atualizar Dados de Veículo\n");
    printf("4. Listar Veículos por Cor\n");
    printf("5. Listar Veículos por Marca\n");
    printf("6. Remover Veículo\n");
    printf("7. Consultar Veículo por Renavam\n");
    printf("8. Estatísticas de Veículos\n");
    printf("9. Sair\n");
    printf("--------------------------------------------------------------\n");
    printf("Escolha uma opção: ");
}

void limparTela()
{
    // Se estiver em ambiente Windows use o cls
    // system("cls");

    // Caso contrário use clear
    system("clear");
}

void adicionarVeiculo(struct Veiculo veiculos[], int *contador)
{
    if (*contador >= MAX_VEICULOS)
    {
        limparTela();
        printf("\n");
        printf("=================================================\n");
        printf("        🚨 ATENÇÃO: LIMITE ATINGIDO 🚨           \n");
        printf("=================================================\n");
        printf("      O limite de veículos foi atingido!         \n");
        printf("    Remova um veículo para adicionar um novo.    \n");
        printf("=================================================\n");
        printf("\n");
        return;
    }

    limparTela();
    struct Veiculo novoVeiculo;

    printf("======================= NOVO VEÍCULO =======================\n");
    printf("=> Digite o nº do Renavam: ");
    scanf("%d", &novoVeiculo.renavam);

    getchar();

    printf("=> Digite o nome do proprietário (máximo 50 caracteres): ");
    fgets(novoVeiculo.nomeProprietario, 50, stdin);

    printf("=> Digite o ano de fabricação: ");
    scanf("%d", &novoVeiculo.anoFabricacao);

    printf("=> Digite a cor do veículo (3 caracteres): ");
    scanf("%s", novoVeiculo.cor);

    printf("=> Digite a marca do veículo (4 caracteres): ");
    scanf("%s", novoVeiculo.marca);

    printf("=> Digite o preço de compra: ");
    scanf("%lf", &novoVeiculo.preco);
    printf("==============================================================\n");

    veiculos[*contador] = novoVeiculo;
    (*contador)++;

    printf("\n==============================================================\n");
    printf("                 VEÍCULO ADICIONADO COM SUCESSO!                  ");
    printf("\n==============================================================\n");
}

void listarVeiculos(struct Veiculo veiculos[], int contador)
{
    if (contador == 0)
    {
        printf("Nenhum veículo cadastrado.\n");
        return;
    }

    limparTela();
    printf("==============================================================\n");
    printf("                     LISTAGEM DE VEÍCULOS                     \n");
    printf("==============================================================\n");

    for (int i = 0; i < contador; i++)
    {
        printf("Veículo %d:\n", i + 1);
        printf("Renavam: %d\n", veiculos[i].renavam);
        printf("Nome do Proprietário: %s\n", veiculos[i].nomeProprietario);
        printf("Ano de Fabricação: %d\n", veiculos[i].anoFabricacao);
        printf("Cor: %s\n", veiculos[i].cor);
        printf("Marca: %s\n", veiculos[i].marca);
        printf("Preço de Compra: R$%.2lf\n", veiculos[i].preco);
        printf("==============================================================\n");
    }
}

void atualizarVeiculo()
{
    printf("Você escolheu a opção de atualizar veículo");
}

void filtrarVeiculosPorCor()
{
    printf("Você escolheu a opção de filtrar veículos por cor");
}

void filtrarVeiculosPorMarca()
{
    printf("Você escolheu a opção de filtrar veículos por marca");
}

void filtrarVeiculoPorRenavam()
{
    printf("Você escolheu a opção de filtrar veículos por número do Renavam");
}

void removerVeiculo()
{
    printf("Você escolheu a opção de remover veiculo");
}

void estatisticasDosVeiculos()
{
    printf("Você escolheu a opção de estatísticas dos veículos");
}

void sair()
{
    printf("\n");
    printf("============================================\n");
    printf("         ✅ PROGRAMA FINALIZADO ✅         \n");
    printf("============================================\n");
    printf("      Obrigado por usar nosso sistema!      \n");
    printf("                 Até logo!                  \n");
    printf("============================================\n");
    printf("\n");
}

int main()
{
    int opcao;
    int count = 0;
    struct Veiculo veiculos[MAX_VEICULOS];

    // printf("Nome do veiculo: ");
    // fgets(veiculos.nomeProprietario, 20, stdin);

    // printf("Este é o nome do veiculo: %s", veiculos.nomeProprietario);

    do
    {
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionarVeiculo(veiculos, &count);
            break;
        case 2:
            listarVeiculos(veiculos, count);
            break;
        case 3:
            atualizarVeiculo();
            break;
        case 4:
            filtrarVeiculosPorCor();
            break;
        case 5:
            filtrarVeiculosPorMarca();
            break;
        case 6:
            filtrarVeiculoPorRenavam();
            break;
        case 7:
            removerVeiculo();
            break;
        case 8:
            estatisticasDosVeiculos();
            break;
        case 9:
            limparTela();
            sair();
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }

        if (opcao != 9)
        {
            printf("\nPressione qualquer tecla para voltar ao menu...");
            getchar();
            getchar();
            limparTela();
        }
    } while (opcao != 9);

    return 0;
}