#include <stdio.h>

struct X {
	int ini;
	int fim;
};


struct X atividades[1000];
struct X atividadesNovo[1000];

void imprimeAtividades(int n, struct X x[]) {
	int i;
	int j = 0;
	for( i = 0; i < n ; i++ ){
		if(x[i].ini != 0 && x[i].fim != 0){
			printf("atividade %d - inicio: %d, fim: %d\n",j,x[i].ini,x[i].fim);
			j++;
		}
	}
}

void adicionaAtividade (int i, int start, int end, struct X x[]){
	x[i].ini = start;
	x[i].fim = end;
}

void ordenaCrescenteTermino(int n, struct X x[]){
	int i, j, k = n - 1, aux, aux1;
	
	for( j = 1; j < n; j++ ){
		for( i = 0; i < k; i++ ){
			if( x[i].fim > x[i+1].fim ){
	            aux = x[i].fim;
	            aux1 = x[i].ini;
	            x[i].fim = x[i+1].fim;
	            x[i].ini = x[i+1].ini;
	            x[i+1].fim = aux;
	            x[i+1].ini = aux1;
	        }
		}	
	}
}

void SelecaoAtividades(int n, struct X x[],struct X y[]){
	int i = 0;
	int j;
	
	y[0] = x[0];
	
	for ( j = 1; j < n; j++ ){
		if(y[i].fim <= x[j].ini){
//			printf("compativeis %d <= %d\n", y[i].fim, x[j].ini);
			y[j]=x[j];
			i = j;
//			printf("i: %d j: %d\n",i,j);
		}
	}
}

int main(){
	int inicio;
	int final;
	int n;
	int imprime;
	int continuar;
	int mais;
	
	printf("Digite o numero de tarefas que serão executadas: ");
    scanf("%d", &n);
    
	int i = 0;
    
    while(i < n){
    	printf("Digite o horario de inicio da tarefa: ");
    	scanf("%d", &inicio);
    	printf("Digite o horario de termino da tarefa: ");
    	scanf("%d", &final);
		adicionaAtividade(i,inicio,final,atividades);
		i++;
	}
	
	while(continuar !=0){
		printf("\n");
		printf("Digite 1 para imprimir suas tarefas, 2\npara ordena-las por ordem do horario de termino,\n3 para selecionar a melhor ordem para os horarios\nou 4 para adicionar mais tarefas: ");
	    scanf("%d", &imprime);
	    
	    switch (imprime){
		   case 1:
		     imprimeAtividades(n,atividades);
		   break;
		   
		   case 2:
		     ordenaCrescenteTermino(n,atividades);
		     imprimeAtividades(n,atividades);
		   break;
		   
		   case 3:
		   	 printf("como suas tarefas estavam\n");
		   	 imprimeAtividades(n,atividades);
		   	 ordenaCrescenteTermino(n,atividades);
		   	 SelecaoAtividades(n,atividades,atividadesNovo);
		   	 printf("como elas ficaram\n");
		   	 imprimeAtividades(n,atividadesNovo);
		   break;
		   
		   case 4:
		   	 printf("Digite quantas tarefas vao ser aicionadas a mais: ");
             scanf("%d", &mais);
             n=n+mais;
             
             while(i < n){
		    	printf("Digite o horario de inicio da tarefa: ");
		    	scanf("%d", &inicio);
		    	printf("Digite o horario de termino da tarefa: ");
		    	scanf("%d", &final);
				adicionaAtividade(i,inicio,final,atividades);
				i++;
			 }
		   break;
		   
		   default:
		     printf("Codigo ivalido pograma encerrado");
		}
		
		printf("\n");
		printf("Digite 1 para continuar ou 0\npara sair: ");
	    scanf("%d", &continuar);
	}
	
	return 0;
}
