#include <stdio.h>
int main(void) {
  FILE *arq, *arq2;
  int i;
  char data[9],nome[50],aux[100],opc;
  float valor,total=0,desconto;
  arq = fopen("Boleto.txt","r");
  arq2 = fopen("Valores.txt","w");
  if( arq == NULL || arq2 == NULL)
  {
    printf("Arquivo não aberto");
  }
  else{
  do{
      fgets(data,6,arq);
      fgets(nome,41,arq);
      fscanf(arq,"%f",&valor);
      total+=valor;
  
      fprintf(arq2,"Nome: %s \n",nome);
      fprintf(arq2,"Valor: R$ %.2f \n",valor);
      fprintf(arq2,"Dia: %s \n",data); 
      fprintf(arq2, "\n");
    
    }while(fgets(aux,100,arq) != NULL);
    total=total+(38.02); //Netflix jonathas
    total=total-(152);
    fprintf(arq2,"Valor Total %.2f \n",total);

    printf("Algum deconto? (s/n): ");
    scanf("%c",&opc);
    if(opc == 's'){
      printf("Valor do desconto: ");
      scanf("%f",&desconto);
      total=total-desconto;
      fprintf(arq2,"Valor Total com desconto: %.2f \n",total);
    }
  }
  fclose(arq);
  fclose(arq2);
  return 0;
}