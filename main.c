#include <stdio.h>
#include <stdlib.h>
#define MAXnome 49

//Variaveis globais:
int n_produtos=0;


//Estrutura do produto
struct produto
{
    char nome [MAXnome];
    int codigo;
	int Qestoque;
    float Pvenda;
	int Cvenda;
	float Vtotal;
};

//Cadastrar o produto
void cadastrar_produto ()
{
    struct produto item;
    printf("\n\t==== CADASTRO DE PRODUTO ====\n");

    //Código
    item.codigo = n_produtos +1; //Ter a quantidade de produtos
    printf("\tCodigo gerado: %d\n", item.codigo);

    //Nome --------------------------------- PROBLEMA!!!!!!!!!
    printf("\n\tNome: ");
    fflush(stdin); //Limpar
    gets(item.nome); // Ler string


    //Quantidade em estoque
    printf("\n\tQuantidade em estoque: ");
    scanf("%d", &item.Qestoque);

    //Preço de venda
    printf("\n\tPreco de venda: ");
    scanf("%f", &item.Pvenda);

    printf("\n\n\tCADASTRO REALIZADO\n\n");
    system("pause");

}
//Registrar venda
void registrar_venda ()
{


}
//Listar produtos
void listar_produtos ()
{

}
//Listar vendas
void listar_vendas ()
{

}
//Relatório
void relatorio ()
{

}


int main()
{
    int opcao;

    do {

        printf("\n\n\t\tBEM VINDO!!");
        printf("\n\t1 - Cadastrar um Produto");
        printf("\n\t2 - Registrar uma Venda");
        printf("\n\t3 - Lista de Produtos Disponiveis");
        printf("\n\t4 - Lista de Vendas");
        printf("\n\t5 - Relatorio");
        printf("\n\t6 - Fechar o programa");

        printf("\n\n\t\tEscolha uma das opcoes: ");
        scanf("%d", &opcao);

        switch(opcao)
        {

        case 1:
           cadastrar_produto();
           break;

        case 2:
            registrar_venda();
            break;

        case 3:
            listar_produtos();
            break;

        case 4:
            listar_vendas();
            break;

        case 5:
            relatorio();
            break;



        }


    system("cls");

    }while (opcao!=6); // Repetir enquanto a opção 6 for escolhidda



	return 0;
}
