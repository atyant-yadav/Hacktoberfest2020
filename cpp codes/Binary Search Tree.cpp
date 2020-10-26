#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct BSTnode{
    int data; // elemento que vai ser guardado em cada no da arvore
    struct BSTnode *left;//filho a esquerda
    struct BSTnode *right;//filho a direita
};
struct BST{
    struct BSTnode *root;
    int nodecount;
};
//Funcao para criar a minha arvore de busca binaria (BST)
struct BST* Create_BST(){
    struct BST *temp = (struct BST *)malloc(sizeof(struct BST));
    temp->root = NULL;
    temp->nodecount = 0;
    return temp;
}
//Funcao para criar um no da minha arvore de busca binaria (BST)
struct BSTnode* Create_BSTnode(int x){
    struct BSTnode *temp = (struct BSTnode* )malloc(sizeof(struct BSTnode));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
//Funcao para destruir a minha BST
void Clear_BST(struct BST* temp){
    temp->root = NULL;
    temp->nodecount = 0;
}
//Funcao que retorna o tamanho da minha BST. Ou seja a qtd de nos presentes nela
int size(struct BST* temp){
    return temp->nodecount;
}
//Funcao para encontrar se um certo elemento esta presente na minha BST
int Find(struct BST *temp, int x){
    return FindHelp(temp->root, x);
}
int FindHelp(struct BSTnode *temp, int x){
    if(temp == NULL){//Se a minha raiz estiver vazia, quer dizer que eu n tenho nenhum elemento presente na minha arvore ainda
        return NULL;
    }
    if(temp->data > x){//Tenho que procurar pelo elemento na sub-arvore da esquerda, pois ele eh menor do que o element que se encontra armazenado no meu no atual
        return FindHelp(temp->left, x);
    }
    else if(temp->data == x){//Encontrei o elemento pelo qual eu estava procurando
        return temp->data;
    }
    else{
        return FindHelp(temp->right, x);
    }
}
//Funcoes para inserir um novo elemento na minha BST
void Insert(struct BST *temp, int x){
    temp->root = InsertHelp(temp->root, x);
    temp->nodecount++;
}
struct BSTnode* InsertHelp(struct BSTnode *temp, int x){
    //Em struct BSTnode *temp eu to recebendo a raiz da minha BST
    if(temp == NULL){//Quer dizer que a minha BST ta vazia(sem elementos)
        temp = Create_BSTnode(x);
    }
    else if(temp->data > x){
        temp->left = InsertHelp(temp->left, x);
    }
    else if(temp->data <= x){
        temp->right = InsertHelp(temp->right, x);
    }
    return temp;
}
//Funcao que vai retirar um certo elemento dado da minha arvore, se ele existir
int Remove(struct BST *temp, int x){
    int Destroy = FindHelp(temp->root, x);
    if(Destroy != NULL){
        temp->root = RemoveHelp(temp->root, x);
        temp->nodecount--;
    }
    return Destroy;
}
struct BSTnode* Getmin(struct BSTnode *rt){
    if(rt->left == NULL){
        return rt;
    }
    return Getmin(rt->left);
}
struct BSTnode* Deletemin(struct BSTnode *rt){
    if(rt->left == NULL){
        return rt->right;
    }
    rt->left = Deletemin(rt->left);
    return rt;
}
struct BSTnode* RemoveHelp(struct BSTnode *temp, int x){
    if(temp == NULL){//A BST esta vazia (nao temos nenhum elemento)
        return NULL;
    }
    if(temp->data > x){
        temp->left = RemoveHelp(temp->left, x);
    }
    else if(temp->data < x){
        temp->right = RemoveHelp(temp->right, x);
    }
    else{//Achei o elemento procurado
        if(temp->left == NULL){
            return temp->right;
        }
        else if(temp->right == NULL){
            return temp->left;
        }
        else{//Esse eh o caso em que o no que vai ser deletado tem filhos na esquerda e na direita
            struct BSTnode *temp2 = Getmin(temp->right);//Temos que procurar pelo menor elemento na subarvore a direita do no que foi deletado
            //Fazendo agora a permuta dos dados
            temp->data = temp2->data;
            temp->right = Deletemin(temp->right);
        }
    }
    return temp;
}
int main(){



    return 0;
}
