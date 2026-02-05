
#include <stdio.h>
#include <stdlib.h>

struct Produto {
	int codigo;
	char nome[100];
	float preco;
};

struct Cliente {
	int codigo;
	char nome[100];
};

struct Pedido {
	int codigoProduto;
	int codigoCliente;
	float quantidade;
};

struct Produto produtos[150];
int total_produtos = 0;

struct Cliente clientes[150];
int total_clientes = 0;

struct Pedido pedidos[150];
int total_pedidos = 0;

// carregarDados.

void carregarDados () {

	FILE *arq;

	// carrega produtos.

	arq = fopen("produtos.txt", "r");
	if (arq != NULL) {
		while(fscanf(arq,"%d;%99[^;]; %f",
		             &produtos[total_produtos].codigo,
		             produtos[total_produtos].nome,
		             &produtos[total_produtos].preco) != EOF) {

			total_produtos++;
		}
		fclose(arq);
	} 

	// carrega clientes.

	arq = fopen("clientes.txt", "r");
	if (arq != NULL) {
		while(fscanf(arq,"%d;%99[^\n]",
		             &clientes[total_clientes].codigo,
		             clientes[total_clientes].nome) != EOF) {

			total_clientes++;
		}
		fclose(arq);
	} 

	// carrega pedidos.

	arq = fopen("pedidos.txt", "r");
	if (arq != NULL) {
		while(fscanf(arq,"%d;%d;%f",
		             &pedidos[total_pedidos].codigoProduto,
		             &pedidos[total_pedidos].codigoCliente,
		             &pedidos[total_pedidos].quantidade) != EOF) {

			total_pedidos++;
		}
		fclose(arq);
	} 
}

// salvarDados.

void salvarDados(){
    
    FILE *arq;
    //produtos
    arq = fopen("produtos.txt", "w");
	for (int i = 0; i < total_produtos; i++){
	    fprintf(arq, "%d;%s;%.2f\n",
	        produtos[i].codigo,
		    produtos[i].nome,
		    produtos[i].preco);
	}
	fclose(arq);
    
    //clientes
    arq = fopen("clientes.txt", "w");
	for (int i = 0; i < total_clientes; i++){
	    fprintf(arq, "%d;%s\n",
	        clientes[i].codigo,
		    clientes[i].nome);
	}
	fclose(arq);
	
    //pedidos
    arq = fopen("pedidos.txt", "w");
	for (int i = 0; i < total_pedidos; i++){
	    fprintf(arq, "%d;%d;%.2f\n",
	        pedidos[i].codigoProduto,
		    pedidos[i].codigoCliente,
		    pedidos[i].quantidade);
	}
	fclose(arq);
}

// cadastrarProduto.

void cadastrarProduto() {
    
    struct Produto aux;
    
    printf("Digite o codigo: ");
    scanf(" %d", &aux.codigo);
    printf("Digite o nome: ");
    scanf(" %99[^\n]", aux.nome);
    printf("Digite o preço: ");
    scanf(" %f", &aux.preco);
    
    produtos[total_produtos++] = aux;
    salvarDados();
}

//cadastrarCliente

void cadastrarCliente() {
    
    struct Cliente aux;
    
    printf("Digite o codigo: ");
    scanf(" %d", &aux.codigo);
    printf("Digite o nome: ");
    scanf(" %99[^\n]", aux.nome);
    
    clientes[total_clientes++] = aux;
    salvarDados();
}

//realizarPedido

void realizarPedido(){
    
    struct Pedido aux;
    
    printf("Digite o codigo do Produto: ");
    scanf(" %d", &aux.codigoProduto);
    printf("Digite o codigo do Cliente: ");
    scanf(" %d", &aux.codigoCliente);
    printf("Digite a quantidade desejada: ");
    scanf(" %f", &aux.quantidade);
    
    pedidos[total_pedidos++] = aux;
    salvarDados();
}

// listarProdutos

void listarProdutos(){
    printf("PRODUTOS\n");
    for (int i = 0; i < total_produtos; i++){
        printf("%.2d | %-10s | %.2f\n",
            produtos[i].codigo,
		    produtos[i].nome,
		    produtos[i].preco);
    }
}

//listarClientes

void listarClientes(){
    printf("CLIENTES\n");
    for (int i = 0; i < total_clientes; i++){
        printf("%.2d | %-10s\n",
            clientes[i].codigo,
		    clientes[i].nome);
    }
}

//listarPedidos

void listarPedidos(){
    printf("PEDIDOS\n");
    for (int i = 0; i < total_pedidos; i++){
        printf("%.2d | %.2d | %.2f\n",
            pedidos[i].codigoProduto,
		    pedidos[i].codigoCliente,
		    pedidos[i].quantidade);
    }
}


// menu.

void menu() {
    

	int escolha;

	do {
	    printf("==========================\n");
		printf("01 - Cadastro de Produtos.\n");
		printf("02 - Cadastro de Clientes.\n");
		printf("03 - Realizar Pedido.\n");
		printf("04 - Listagem de Produtos.\n");
		printf("05 - Listagem de Clientes.\n");
		printf("06 - Listagem de Pedidos.\n");
		printf("0 - Finalizar.\n");
		printf("==========================\n");
		scanf("%d", &escolha);

		switch (escolha) {
		case 1: cadastrarProduto(); break;
		case 2: cadastrarCliente(); break;
		case 3: realizarPedido(); break;
		case 4: listarProdutos(); break;
		case 5: listarClientes(); break;
		case 6: listarPedidos(); break;
		default: printf("Opcao invalida!\n"); break;
		}

	} while (escolha != 0);
}



int main()
{

	carregarDados();

	menu();

	return 0;
}