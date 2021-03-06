/*
* Algoritmo ILS para solução da Mochila 0-1
* Autor: Valmir Monteiro Júnior
*/
#define LIMITE_ITERACOES_SEM_MELHORA 100
#define GRAU_PERTURBACAO 0.3 // Portentagem da solução que será perturbada
#define RESET_PERTURBACAO 0.3
#define MODIFICADOR_RAIO_VIZINHANCA 16
/* Modificador de vizinhança
	* Se for muito pequeno, as soluções da vizinhança não vão ter itens suficiente para adicionar
	* Se for muito grande, muitas soluções da vizinhança ficam iguais
	* Deve ser ajustado de acordo com a densidade dos pontos no plano
	* (Levar em consideração que as distâncias estão ao quadrado)
*/

typedef struct _item Item;
typedef struct _itemNode ItemNode;
typedef struct _mochila Mochila;
typedef struct _vetor2 Vetor2;

struct _item{
	int indice; 
	int peso;
	int valor;	
	float proporcao;
	int quantVizinhos;
};

struct _itemNode{
	Item* itemPtr;
	ItemNode* proximo;
};

struct _mochila{
	int id;
	int itensTotal;
	int valorTotal;
	int pesoTotal;
	ItemNode* listaItens;
};

struct _vetor2{
	int x;
	int y;
};

// Protótipos ILS_Main
int NumeroAleatorio();

// Protótipos ILS_Base
Item* LerArquivo(FILE* arquivo, int quantidade, float* mediaPeso);
void CopiarItem(Item* destino, Item* origem);
void AdicionarItem(Mochila* mochila, Item* item);
void DestruirMochila(Mochila* mochila);
void DestruirMemoria(Mochila** mem, int quant);
Mochila* CriarMochila(int indicePivo);
void ImprimirMochila(Mochila* mochila);

//Protótipos Quicksort
void OrdenarCandidatos(Item *vet, int quant, Vetor2* vetorMedia);
void Quicksort(Item *vet, int ini, int fim);
int Particiona(Item *vet, int ini, int fim);

// Protótipos ILS_Simples
int DistanciaQuadrada(Vetor2 v1, Vetor2 v2);
Mochila* SolucaoInicalGulosa(Item* candidatos, Mochila** memoria, int quantidade, int capacidade);
Mochila* SolucaoInicialAleatoria(Item* candidatos, int quantidade, int capacidade);
unsigned char** CriarMatrizAdjacencia(int quantidade);
unsigned char** GerarVizinhanca(Item* candidatos, float raioMax, int quant);
Mochila* BuscaLocal(Mochila* solucaoMelhor, Item* conjuntoCandidatos, unsigned char** matrizAdj, Mochila** memoria, int quantidadeItens, int capacidadeMochila);
static void _imprimirMatriz(unsigned char** mat, int quant); // Somente para teste
Mochila* Pertubacao(Mochila* solucao, Mochila** memoria, int capacidade);
void BuscaNoVizinho(Item* conjuntoCandidatos, int indicePivo, unsigned char** matrizAdj, Mochila** memoria, int quantidadeItens, int capacidadeMochila);


