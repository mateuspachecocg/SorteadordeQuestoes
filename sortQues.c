#include <stdio.h>  
#include <stdlib.h>  
#include <time.h> // use time.h header file to use time  
      
int main()  
{  
	int i, j, k, nmemb, nquest, questAleat, conBoo, qOm, qExt;
	
	time_t t1;
	conBoo = 1;
	int questoes[4][5];
	
	
	//Inserindo Componentes da equipe
	printf("DIGITE A QUANTIDADE DE MEMBROS DA EQUIPE: ");
	scanf("%d", &nmemb);
	char equipe[nmemb][150];
	
	for(i = 0; i < nmemb; i++){
		printf("DIGITE O NOME DO INTEGRANTE %d: ", (i+1));
		scanf(" %s", equipe[i]);
	}	
	
	//Inserindo Componentes da equipe
	printf("DIGITE A QUANTIDADE DE QUESTÕES DO TRABALHO: ");
	scanf("%d", &nquest);
	int arrayQts[nquest];
	
	
	//Configurando Parâmetros da Função Randômica
	srand((unsigned) time(&t1));
	printf("\n");
	
	
	// Sorteando OS números de forma aleatoria;
	for(i = 0;i < nquest;i++){
		int isNew = 1;
		while(isNew) {
			questAleat = rand()%nquest + 1;
			
	
			for(k = i;k >= 0; k--){
				if(arrayQts[k] == questAleat){
					isNew = 1;
					break;
				} else {
					isNew = 0;
				}
			}
		}
		arrayQts[i] = questAleat;
	}
	
	/*printf("VETOR QUESTOES: { ");
	for(i = 0; i < nquest; i++){
		printf("%d, ", arrayQts[i]);
	}
	printf("}\n");*/
	
	// Atribuindo as questões a cada membro da equipe:
	// qOm = questions over member
	
	qOm = nquest/nmemb;
	qExt = nquest%nmemb;
	
	
	int pos = 0;
	for(k = 0; k < nmemb; k++){

		printf("QUESTOES %s: ", equipe[k]);
		
		for(j = 0 + pos;j < qOm+pos ;j++){
			printf("%d \t", arrayQts[j]);
		}
		pos = pos + qOm;
		printf("\n");	
	}
	
	// Caso não der para dividir uma quantidade exata de 
	// de questões para cada aluno.
	if (qExt > 0){
		printf("QUESTAO(OES) EXTRA: ");
		for(i = nquest - qExt; i < nquest;i++ ){
			printf("%d \t", arrayQts[i]);
		}
	}
	
	
	return 0;
}

