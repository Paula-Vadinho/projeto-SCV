
#include <stdio.h>
#include <stdlib.h>
#define MAXnome 50
#define MAXproduto 49

//Variaveis globais:
int n_produtos=0; // SUBISTITUIR POR PONTEIROS!!!!!!!


//Estrutura do produto
struct produto
{
    char nome[MAXnome];
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

        struct produto item;
        printf("\n\t==== CADASTRO DE PRODUTO ====\n");

        //C�digo
        item.codigo = n_produtos +1; //Ter a quantidade de produtos
        printf("\tCodigo gerado: %d\n", item.codigo);

        //Nome --------------------------------- PROBLEMA!!!!!!!!!
        printf("\n\tNome: ");

        while(getchar()!='\n'); // CRIAR UMA FUNCAO PRA CHAMAR ESSE TRECO!!!!!

       // fflush(stdin); //Limpar
        fgets(item.nome,50,stdin);



        //Quantidade em estoque
        printf("\n\tQuantidade em estoque: ");
        scanf("%d", &item.Qestoque);

        //Preco de venda
        printf("\n\tPreco de venda: ");
        scanf("%f", &item.Pvenda);

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

//Relat�rio
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
  }while (opcao!=7); // Repetir enquanto a op��o 7 for escolhidda

	return 0;
}
