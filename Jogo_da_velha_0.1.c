   #include <stdio.h>
   #include <stdlib.h>
   #define true 1
   #define false 0
   
   // ****** funcao tabuleiro ****************
   // Desenha o tabuleiro
   // entrada : vetor de posicoes de tamanho 9
   // ****************************************
      void desenhaTabuleiro(char tab[9])
	  {
        system("cls");
		printf("\n -----------------------------");
		printf("\n |    %c    |   %c     |   %c   |",tab[0], tab[1], tab[2]);
		printf("\n -----------------------------");
		printf("\n |    %c    |   %c     |   %c   |",tab[3], tab[4], tab[5]);
		printf("\n -----------------------------");
		printf("\n |    %c    |   %c     |   %c   |",tab[6], tab[7], tab[8]);
		printf("\n -----------------------------");	  	
	  } 
	  
   // ****** funcao temGanhador ****************
   //  identifica se tem ganhador
   //  entrada : vetor de posicoes de tamanho 9
   //            e a ficha do jogador '0' ou 'X'
   // ****************************************
      int temGanhador(char tab[9],char fichaJogador)
	  {
	   if (
            (tab[0] == fichaJogador && tab[1] == fichaJogador && tab[2] == fichaJogador) ||
            (tab[3] == fichaJogador && tab[4] == fichaJogador && tab[5] == fichaJogador) ||
            (tab[6] == fichaJogador && tab[7] == fichaJogador && tab[8] == fichaJogador) ||
            (tab[0] == fichaJogador && tab[3] == fichaJogador && tab[6] == fichaJogador) ||
            (tab[1] == fichaJogador && tab[4] == fichaJogador && tab[7] == fichaJogador) ||
            (tab[2] == fichaJogador && tab[5] == fichaJogador && tab[8] == fichaJogador) ||
            (tab[0] == fichaJogador && tab[4] == fichaJogador && tab[8] == fichaJogador) ||
            (tab[2] == fichaJogador && tab[4] == fichaJogador && tab[6] == fichaJogador)
          ) 
		  {
                return true;
          } 
		  else {
                return false;   
          }
      }
      
      // ****** funcao casa livre ****************
      //  identifica se a casa está
      //  entrada : vetor de posicoes de tamanho 9
      //            e a ficha do jogador '0' ou 'X'
      // ****************************************
      int casaLivre(char tab[9],int numCasa)
      {
      	if(tab[numCasa-1]!='0' && tab[numCasa-1]!='X')
      	    return true;
      	else 
      	    return false;
	  }
	  
	  
	  // ___________ funcao principal ______________
	  int main(){
	  	char tab[9]={'1','2','3','4','5','6','7','8','9'};
	  	  	
	  	// 1.- passo. desenhar o tabuleiro
	  	       desenhaTabuleiro(tab);
	  	// 2.- passo. 
		//       2.1 numero de jogadas -> total de 4 x jogador
		//       2.2 perguntar a cada um deles a posição de sua jogada                   
		int numJogada=0;
		int posEscolhidaJogador1, posEscolhidaJogador2;
		
		//  3.- passo                             
		//      3.1 .......................................
		//      3.2 ---------------------------------------
		int posJG1[4];   // guardar as posicoes escolhidas do Jog 1
	  	int posJG2[4];   // guardar as posicoes escolhidas do Jog 2
	  	
		do{
			
		  printf("\n  +++++      Vez do Jogador 1     +++++++++ ");
		  do{
		     printf("\n Escolha sua casa  ?? "); 
		     scanf("%d",&posEscolhidaJogador1);
		  }
		  while(posEscolhidaJogador1==posEscolhidaJogador2);
		     
		  tab[posEscolhidaJogador1-1]='X';
		  desenhaTabuleiro(tab); 	
		  posJG1[numJogada]=posEscolhidaJogador1-1;
		  
		  //  Verificar se já tem jogador
		   if(temGanhador(tab, 'X')){
			     printf("\n\n Ganhador : JOGADOOR 1 !!");    
			     break;
			 }
		  
	//-------------------------------------------------------------	  
		  printf("\n             Vez do Jogador 2              ");
		  do{
		    printf("\n Escolha sua casa  ?? "); 
		    scanf("%d",&posEscolhidaJogador2);
		  }
		  while(posEscolhidaJogador2==posEscolhidaJogador1);
		  
		  tab[posEscolhidaJogador2-1]='0';
		  desenhaTabuleiro(tab); 	
		  posJG2[numJogada]=posEscolhidaJogador2-1;
		  
		  //  Verificar se já tem jogador
		   if(temGanhador(tab, '0')){
			     printf("\n\n Ganhador : JOGADOOR 2 !!"); 
			     break;
			 }
	//-------------------------------------------------------------	  	  
	     
		  // Proxima Jogada 	
		  numJogada++;	
		}
		while(numJogada<4);
		
	  	
	    return 0;	
	  }






