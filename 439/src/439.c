#include <stdio.h>

int nivel[1001][1001];

int valida(int x){
	if(x <= 8 && x >= 1)
		return 1;
	return 0;
}

// vi = vértice inicial
void bfs(int x, int y){
	int fila[1001][2],PA=1,TD=0,i; // PA = Põe aqui TD = Tira daqui
	fila[0][0]=x;
	fila[0][1]=y;
	nivel[x][y]=0; // vetor global com o nı́vel de cada vértice	
	while (PA!=TD){
		int s1=fila[TD][0];
		int s2=fila[TD++][1];
		int w1, w2;

		// busca vértices adjacentes a s1, s2

		// CIMA E DIREITA [s1+2][s2+1]
		w1 = s1+2; w2=s2+1;
		if(valida(w1) && valida(w2) && nivel[w1][w2]==-1){
			fila[PA][0]=w1;
			fila[PA++][1]=w2;
			nivel[w1][w2]=nivel[s1][s2]+1;
		}

		// CIMA E ESQUERDA [s1+2][s2-1]		
		w1 = s1+2; w2=s2-1;
		if(valida(w1) && valida(w2) && nivel[w1][w2]==-1){
			fila[PA][0]=w1;
			fila[PA++][1]=w2;
			nivel[w1][w2]=nivel[s1][s2]+1;
		}
		
		// BAIXO E DIREITA [s1-2][s2+1]
		w1 = s1-2; w2=s2+1;
		if(valida(w1) && valida(w2) && nivel[w1][w2]==-1){
			fila[PA][0]=w1;
			fila[PA++][1]=w2;
			nivel[w1][w2]=nivel[s1][s2]+1;
		}
		
		// BAIXO E ESQUERDA [s1-2][s2-1]
		w1 = s1-2; w2=s2-1;
		if(valida(w1) && valida(w2) && nivel[w1][w2]==-1){
			fila[PA][0]=w1;
			fila[PA++][1]=w2;
			nivel[w1][w2]=nivel[s1][s2]+1;
		}		

		// DIREITA E CIMA [s1+1][s2+2]
		w1 = s1+1; w2=s2+2;
		if(valida(w1) && valida(w2) && nivel[w1][w2]==-1){
			fila[PA][0]=w1;
			fila[PA++][1]=w2;
			nivel[w1][w2]=nivel[s1][s2]+1;
		}

		// DIREITA E BAIXO [s1-1][s2+2]
		w1 = s1-1; w2=s2+2;
		if(valida(w1) && valida(w2) && nivel[w1][w2]==-1){
			fila[PA][0]=w1;
			fila[PA++][1]=w2;
			nivel[w1][w2]=nivel[s1][s2]+1;
		}		

		// ESQUERDA E CIMA [s1+1][s2-2]
		w1 = s1+1; w2=s2-2;
		if(valida(w1) && valida(w2) && nivel[w1][w2]==-1){
			fila[PA][0]=w1;
			fila[PA++][1]=w2;
			nivel[w1][w2]=nivel[s1][s2]+1;
		}		

		// ESQUERDA E BAIXO [s1-1][s2-2]
		w1 = s1-1; w2=s2-2;
		if(valida(w1) && valida(w2) && nivel[w1][w2]==-1){
			fila[PA][0]=w1;
			fila[PA++][1]=w2;
			nivel[w1][w2]=nivel[s1][s2]+1;
		}
	}
}

int main(void) {
	int N, M;
    int i, j;

    char c1, c2, c3, c4;
    int x1, x2;
    int y1, y2;

    // LE ORIGEM E DESTINO
	while(fscanf(stdin, "%c%c %c%c\n", &c1, &c2, &c3, &c4) != EOF){
		// TRANSFORMA EM INTEIRO
		x1=c1-96;
		x2=c2-48;		
		y1=c3-96;
		y2=c4-48;

		// ZERA NIVEL
		for(i=0;i<1001;i++){
			for(j=0;j<1001;j++){
				nivel[i][j] = -1;
			}				
		}	

		bfs(x1, x2);	
		
		printf("To get from %c%d to %c%d takes %d knight moves.\n", x1+96, x2, y1+96, y2, nivel[y1][y2]);
	}

	// DEBUG
	// for(i=1;i<TAM;i++){
	// 	for(j=1;j<TAM;j++){
	// 		printf("%d ", matriz[i][j]);
	// 	}		
	// 	printf("\n");
	// }
	// // nivel
	// for(i=1;i<TAM;i++){
	// 	for(j=1;j<TAM;j++){
	// 		printf("%d %d: %d \n", i, j, nivel[i][j]);
	// 	}				
	// }

    return 0;
}
