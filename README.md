# Sistema de Gestão de Veículos

Este projeto implementa uma aplicação em C para manipulação de dados de veículos. A aplicação utiliza vetores dinâmicos e a estrutura struct para armazenar e gerenciar os dados. Inclui funcionalidades de inclusão, listagem, e modificação de registros.

## Funcionalidades

A aplicação oferece as seguintes funcionalidades, acessadas por um menu interativo:

1. **Incluir Dados de Veículo**

   - Adiciona informações de um novo veículo no sistema:
     - Renavam
     - Nome do proprietário
     - Ano de fabricação
     - Cor (ex.: VRM, PRE, BRA, CIN, AMA)
     - Marca (ex.: FIAT, VW, GM, FORD)
     - Preço de compra

2. **Listar Veículos**

   - Lista todos os veículos cadastrados no sistema.
   - Permite listagem parcial, exibindo apenas veículos que possuem um atributo específico (ex.: veículos de uma determinada cor ou marca).

3. **Modificar Dados de um Veículo**

   - Permite alterar as informações de um veículo já cadastrado:
     - Modificação total (todos os dados do veículo).
     - Modificação parcial (apenas campos específicos).

4. **Sair**

- Encerra o programa e libera a memória alocada.

## Passos para Compilação e Execução

1. Clone o repositório:

```bash
git clone https://github.com/dkat-davi/trabalho-final-aeds-1
cd trabalho-final-aeds-1
```

2. Compile o programa:

```bash
gcc main.c -o /files/sistema-veiculos
```

3. Execute o programa

```bash
./files/sistema-veiculos
```

## Formato dos Dados

Cada veículo armazenado possui os seguintes atributos:
| Atributo | Tipo | Descrição |
|----------------------|----------|-----------------------------------------------|
| Renavam | Inteiro | Número de registro do veículo (único). |
| Nome do proprietário | Texto | Nome do proprietário do veículo. |
| Ano de fabricação | Inteiro | Ano em que o veículo foi fabricado. |
| Cor | Texto | Cor do veículo (VRM, PRE, BRA, etc.). |
| Marca | Texto | Marca do veículo (FIAT, VW, GM, etc.). |
| Preço de compra | Decimal | Valor pago pelo veículo. |

### Abreviações para inserir as cores dos veículos

| Abreviação | Cor              |
| ---------- | ---------------- |
| VRM        | Vermelho         |
| PRE        | Preto            |
| BRA        | Branco           |
| CIN        | Cinza            |
| AMA        | Amarelo          |
| AZL        | Azul             |
| VDE        | Verde            |
| ROS        | Rosa             |
| MAR        | Marrom           |
| LAR        | Laranja          |
| BEG        | Bege             |
| PRT        | Prata            |
| DOU        | Dourado          |
| ROC        | Roxo             |
| VIN        | Vinho            |
| CLR        | Colorido/Mistura |
| TRN        | Transparente     |

### Abreviações para inserir as marcas dos veículos

| Abreviação | Marca             |
| ---------- | ----------------- |
| FIAT       | Fiat              |
| VW         | Volkswagen        |
| GM         | General Motors    |
| FORD       | Ford              |
| HON        | Honda             |
| TOY        | Toyota            |
| HYU        | Hyundai           |
| CHE        | Chevrolet         |
| BMW        | BMW               |
| MER        | Mercedes-Benz     |
| AUD        | Audi              |
| KIA        | Kia Motors        |
| NIS        | Nissan            |
| JEEP       | Jeep              |
| REN        | Renault           |
| PEU        | Peugeot           |
| CIT        | Citroën           |
| VOL        | Volvo             |
| TES        | Tesla             |
| POR        | Porsche           |
| MAS        | Maserati          |
| LAM        | Lamborghini       |
| FER        | Ferrari           |
| BUG        | Bugatti           |
| MIT        | Mitsubishi        |
| SUZ        | Suzuki            |
| DOD        | Dodge             |
| CHR        | Chrysler          |
| CAD        | Cadillac          |
| MAZ        | Mazda             |
| SUB        | Subaru            |
| JAG        | Jaguar            |
| LAN        | Land Rover        |
| LEX        | Lexus             |
| AST        | Aston Martin      |
| INF        | Infiniti          |
| GEN        | Genesis           |
| GWM        | Great Wall Motors |
| CHN        | Chery             |
| BYD        | BYD               |
| GEO        | Geely             |

## Demonstração do Menu

```bash
==============================================================
                       MENU PRINCIPAL
==============================================================
1. Inclusão de Veículo
2. Listagem de Veículos
3. Modificar Dados de Veículo
4. Listagem Parcial por Cor
5. Listagem Parcial por Marca
6. Remoção de Veículo
7. Consultar Veículo por Renavam
8. Estatísticas de Veículos
99. Sair
--------------------------------------------------------------
Escolha uma opção:
```

## Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
