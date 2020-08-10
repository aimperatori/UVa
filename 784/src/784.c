#include <stdio.h>

/* #define debug */

#ifndef debug
#define out stdout
#endif

char mapa[31][81];

void dfs(int x, int y){
	int pos = mapa[x][y];
	if(mapa[x][y] == ' ' || mapa[x][y] == '*'){
		mapa[x][y] = '#';
		dfs(x+1, y);
		dfs(x, y+1);
		dfs(x-1, y);
		dfs(x, y-1);
	}
}

void inicializa(){
	int i, j;
	for(i=0; i<31; i++){
		for (j=0; j<81; j++){
			mapa[i][j] = ' ';
		}
	}
}

int main(void) {

	int n, aux, i, j;

	#ifdef debug
		FILE *out = fopen("out.txt","w+");
	#endif

	fscanf(stdin, "%d\n", &n);

	while(n--){
		inicializa();
		aux=0;
		while (fgets(mapa[aux], sizeof(mapa[aux]), stdin)){
			if (mapa[aux++][0] == '_'){
				break;
			}
		}

		for (i = 0; i < 81; i++)
			mapa[aux][i] = 0;

		for (i=0; mapa[i][0]!='_'; i++){
			for (j=0; mapa[i][j]; j++){
				if (mapa[i][j] == '*'){
					dfs(i, j);
				}
			}
		}

		for (i=0; i<aux; i++){
			fprintf(out, "%s", mapa[i]);
		}

	}

	fclose(out);

  	return 0;
}
