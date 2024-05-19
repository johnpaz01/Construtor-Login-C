#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

void recebe_nome(char nome[MAX]){
printf("digite seu nome completo: ");
fgets(nome,MAX,stdin);
printf("\nnome original: %s", nome);
}

void conta_palavras(char nome[MAX], int *cont){
int i;
for(i=0;nome[i]!='\0';i++){
    if (nome[i]==' ' || nome[i]=='\n'){
        if(nome[i+1]!=' '&& nome[i+1]!='\n'){
(*cont)++;
              }
         }
     }
     if (*cont>=3){
      (*cont)=3;
     }
}

void tudo_minusculo(char nome[]){
int i;
for(i=0;nome[i]!='\0';i++){
nome[i]= tolower(nome[i]);
}
}

void nome_final(char nome[MAX],char final[MAX]){
int i = strlen(nome)-1;
int j = 0;
while((i>0)&&(nome[i]!=' ')){
  final[j]=nome[i];
    i--;
      j++;
 }
  final[j] = '\0';
}

void inverte_nome(char final[MAX]){
int i, j;
int tamanho = strlen(final);
char temp;
    for (i = 0, j = tamanho - 1; i < j; i++, j--) {
        temp = final[i];
        final[i] = final[j];
        final[j] = temp;
    }printf("%s",final);
}

void letras_iniciais(char nome[MAX],char *letra1,char *letra2, int op){
int i=0;
int cont=0;
while(cont==0){
  if(nome[i]==' '){
      i++;
}else{
  cont++;
        }
    }
(*letra1) = nome[i];
cont=0;
if(op>1){
  while(cont==0){
    if((nome[i]!=' ')){
      i++;
}else{
    cont++;
    }
}
cont=0;
while(cont==0){
  if(nome[i]==' '){
      i++;
}else{
  cont++;
        }
    }
(*letra2) = nome[i];
  }
}

void cria_login(char nome[MAX], int op, char l1, char l2){
switch(op){
  case 1:
    printf("login: %s", nome);
  break;

case 2: 
printf("login: %c%s",l1,nome);
break;

case 3:
printf("login: %c%c%s",l1,l2,nome);
break;
}
}

int main(){
char nome[MAX];
int cont=0;
char final[MAX];
char l1= ' ';
char l2= ' ';

recebe_nome(nome);
conta_palavras(nome,&cont);
tudo_minusculo(nome);
nome_final(nome, final);
inverte_nome(final);
letras_iniciais(nome, &l1, &l2, cont);
cria_login(final, cont, l1, l2);
return 0;
}

/* não tinha muito o que comentar nesse codigo, mas ele basicamente recebe o nome,
conta quantas palavras tem para verificar os casos possiveis, depois transforma o nome
em minúsculo, apos isso pega o nome final, inverte ele para ficar na ordem correta,
roda a palavra pegando as primeiras letras, depois cria o login apartir de casos separados
que dependem de quantas palavras são digitadas;*/
