#include <stdio.h>
#include <stdlib.h>
#define MAXnome 49
#define MAXproduto 49

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
    if (n_produtos >=MAXproduto) //Limite na quantidade de produtos cadastrados
    {
        printf("\n\n\tO LIMITE DE PRODUTOS FOI ATINGIDO\n");
        system("pause");

    }

    else
    {

        struct produto item[n_produtos];
        printf("\n\t==== CADASTRO DE PRODUTO ====\n");

        //Código
        item[n_produtos].codigo = n_produtos; //Ter a quantidade de produtos
        printf("\tCodigo gerado: %d\n", item[n_produtos].codigo);

        //Nome --------------------------------- PROBLEMA!!!!!!!!!
        printf("\n\tNome: ");
        fflush(stdin); //Limpar
        gets(item[n_produtos].nome); // Ler string


        //Quantidade em estoque
        printf("\n\tQuantidade em estoque: ");
        scanf("%d", &item[n_produtos].Qestoque);

        //Preço de venda
        printf("\n\tPreco de venda: ");
        scanf("%f", &item[n_produtos].Pvenda);

        printf("\n\n\tCADASTRO REALIZADO\n\n");
        system("pause");
    }
}
//Registrar venda
void registrar_venda ()
{


}
//Listar produtos disponivveis
void listar_produtos_disp ()
{

}
//Listar vendas
void listar_vendas ()
{

}

//Listar produtos em falta
void listar_produtos_falt ()
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
        printf("\n\t5 - Listar Produtos em Falta");
        printf("\n\t6 - Relatorio");
        printf("\n\t7 - Fechar o programa");

        printf("\n\n\t\tEscolha uma das opcoes: ");
        scanf("%d", &opcao);

        switch(opcao)
        {

        case 1:
            n_produtos+1;
           cadastrar_produto();
           break;

        case 2:
            registrar_venda();
            break;

        case 3:
            listar_produtos_disp();
            break;

        case 4:
            listar_vendas();
            break;

        case 5:
            listar_produtos_falt();
            break;


        case 6:
            relatorio();
            break;



        }


    system("cls");

    }while (opcao!=7); // Repetir enquanto a opção 6 for escolhidda

	return 0;
}
