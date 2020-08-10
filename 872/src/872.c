#include <stdio.h>

#define N 30

int matriz[N][N];

int vars[N];
int qtdVars;

int lista[N];
int count = -1;

void orden_topo2(){
	int i, j;

	int graus[N];

	for(j=1;j<N;j++){
		graus[j] = vars[j];
	}
	for(i=1;i<N;i++){
		for(j=1;j<N;j++){
			if(matriz[j][i] == 1) ++graus[i];
		}
	}
	int t=0;
	for(i=0;i<=count;i++){
		t = lista[i];
		graus[t] = -1;
		for(j=1;j<N;j++){
			if(matriz[t][j] == 1) --graus[j];
		}
	}

	for(i=1;i<N;i++){
		if(graus[i] == 0) {
			graus[i] = -1;

			lista[++count] = i;

			orden_topo2(i);

		}
	}

	if(count+1 == qtdVars){
		for(i=0;i<qtdVars-1;i++){
			printf("%c ", lista[i]+64);
		}
		printf("%c\n", lista[i]+64);		
	}
	count--;
}


int main(void) {
	int i, j;

	int test;

	char a, b, var;	

	fscanf(stdin, "%d", &test);
	
	while(test--){
		fscanf(stdin, "\n");

		for(i=1;i<N;i++){
			for(j=i;j<N;j++){
				matriz[i][j] = matriz[j][i] = -1;
			}
			vars[i] = -1;
			lista[i]=0;
		}
		qtdVars=0;
		count=-1;
		
		do{
			fscanf(stdin, "%c", &var);
			if(var != ' ' && var != '\n'){
				vars[var-64] = 0;
				qtdVars++;
			}
		}while(var != '\n');


		do{
			fscanf(stdin, "%c", &a);
			if(a == '\n') break;
			if(a == ' ') continue;
			else{
				fscanf(stdin, "<%c", &b);

				matriz[a-64][b-64] = 1;
			}
		}while(1);


		orden_topo2();


		int set;
		set = 0;
		for(j=1;j<N;j++){
			if(lista[j]) set = 1;
		}
		if(set==0) printf("NO\n");

		if(test) printf("\n");
	}

	return 0;
}
