
#include <stdio.h>
#include <stdlib.h>
#define MAXnome 50
#define MAXproduto 49

//NÃO PRECISA DE PONTEIRO!!!!!!


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
//Leitura de strings
void ler_string ()
{
     while(getchar()!='\n');
}


//Cadastrar o produto
void cadastrar_produto (struct produto item[], int n_produto)
{

    if (n_produto >=MAXproduto) //Limite na quantidade de produtos cadastrados
    {
        printf("\n\n\tO LIMITE DE PRODUTOS FOI ATINGIDO\n");
        system("pause");

    }

    else
    {


        printf("\n\t==== CADASTRO DE PRODUTO ====\n");

        //Codigo
        item[n_produto].codigo = n_produto; //Ter a quantidade de produtos
        printf("\tCodigo gerado: %d\n", item[n_produto].codigo);

        //Nome --------------------------------- PROBLEMA!!!!!!!!!
        printf("\n\tNome: ");

         ler_string();
//        while(getchar()!='\n'); // CRIAR UMA FUNCAO PRA CHAMAR ESSE TRECO!!!!!

       // fflush(stdin); //Limpar
        fgets(item[n_produto].nome,50,stdin);



        //Quantidade em estoque
        printf("\n\tQuantidade em estoque: ");
        scanf("%d", &item[n_produto].Qestoque);

        //Preco de venda
        printf("\n\tPreco de venda: ");
        scanf("%f", &item[n_produto].Pvenda);

        printf("\n\n\tCADASTRO REALIZADO\n\n");
        system("pause");
    }
}
//Registrar venda
void registrar_venda ()
{


}

//Listar produtos disponivveis
void listar_produtos_disp (struct produto item[],int n_produto)
{

    printf("\n\t\tLISTA DE PRODUTOS DISPONIVEIS\n\n");
    printf("Codigo | Nome | Quantidade disp | P. venda\n");
    for (int i=1; i <= n_produto; i++)
    {
        printf("    %d  |   %s  |   %d  |   %.2f", item[i].codigo, item[i].nome, item[i].Qestoque, item[i].Pvenda);

    }
    system ("pause");

}
//Listar vendas
void listar_vendas ()
{

}

//Listar produtos em falta
void listar_produtos_falt ()
{

}

//Relatorio
void relatorio ()
{

}


int main()
{

    int opcao, n_produto=0;
    struct produto item[MAXproduto];

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
           n_produto++;
           cadastrar_produto(item, n_produto); //Enviar a posição com ponteiro, o "&" envia a posição da informação

           break;

        case 2:
            registrar_venda();
            break;

        case 3:
            listar_produtos_disp(item, n_produto);
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
  }while (opcao!=7); // Repetir enquanto a opcao 7 for escolhidda

	return 0;
}
