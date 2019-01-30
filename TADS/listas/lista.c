#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"



int
creaVacia(Lista *l)
{
    if (l == NULL)
        return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda))))
        return -1;
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}


int
vacia(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig == NULL)
        return 1;
    else
        return 0;
}

int
destruye(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig != NULL){
        return -2;
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}


void
imprime(Lista *l)
{
    tipoCelda *aImprimir;
    int posicion;
    
    if (l == NULL || l->raiz == NULL) {
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            printf("Valor: %d en posición: %d\n",aImprimir->elemento, posicion++);
            aImprimir = aImprimir->sig;
        }
        printf("%d valores en la lista\n",posicion-1);
    }
}

tipoPosicion
anterior(tipoPosicion p, Lista *l)
{
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->raiz){
        return l->raiz;
    }
    else {
        anterior = l->raiz;
        while (anterior->sig != p)
            anterior = anterior->sig;
        return anterior;
    }
}


tipoPosicion
primero(Lista *l)
{
    tipoPosicion primer=l->raiz;
    if(l->raiz==NULL){
    	printf("Error: La Lista no se ha creado correctamente");
    }
    return l->raiz;    
}



tipoPosicion
fin(Lista *l)
{	
	tipoPosicion tp;
	if(l==NULL){
    	printf("ERROR: La lista no existe\n");
    	return NULL;
    }
    tp=l->ultimo;
	while(tp->sig!=NULL){
		tp=tp->sig;
	}
    return tp;    
}




int
inserta(tipoElemento x, tipoPosicion p, Lista *l)
{
	tipoPosicion tp;
    if(p==NULL){
    	printf("ERROR: El puntero esta vacio\n");
    	return -1;
    }
    if(l==NULL){
    	printf("ERROR: La lista no existe\n");
    	return -2;
    }
    tp=(tipoCelda *)malloc(sizeof(tipoCelda));
    tp->elemento=x;
    if(p==fin(l)){
    	tp->sig=NULL;
    	(fin(l))->sig=tp;
    	l->ultimo=tp;
    }else{
    	tp->sig=(p->sig);
    	p->sig=tp;
    }
    return 0;
}


int
suprime (tipoPosicion p, Lista *l)
{
	tipoPosicion temp;
    if(p==NULL){
    	printf("ERROR: El puntero esta vacio\n");
    	return -1;
    }
    if(l==NULL){
    	printf("ERROR: La lista no existe\n");
    	return -2;
    }
    temp=p->sig;
    p->sig=temp->sig;
    free(temp);
    return 0;
}



tipoPosicion
siguiente(tipoPosicion p,Lista *l)
{
    if(p==NULL){
    	printf("ERROR: El puntero esta vacio\n");
    	return -1;
    }
    if(l==NULL){
    	printf("ERROR: La lista no existe\n");
    	return -2;
    }
    if(p==fin(l)){
    	return fin(l);
    }
    return p->sig;    
}




tipoPosicion
localiza (tipoElemento x, Lista *l)
{	
	tipoPosicion tp;
	if(l==NULL){
    	printf("ERROR: La lista no existe\n");
    	return -2;
    }
    tp=(l->raiz);
    while(tp->sig!=NULL){
    	if((tp->sig)->elemento==x){
    		return tp;
    	}
    }
	return fin(l);
}



tipoElemento
recupera(tipoPosicion p, Lista *l)
{
	if(p==NULL){
    	printf("ERROR: El puntero esta vacio\n");
    	return -1;
    }
    if(l==NULL){
    	printf("ERROR: La lista no existe\n");
    	return -2;
    }
    if(p=fin(l)){
    	return fin(l)->elemento;
    }
    return (p->sig)->elemento;    
}


int
anula(Lista *l)
{
	tipoPosicion tp,temp;
    if(l==NULL){
    	printf("ERROR: La lista no existe\n");
    	return -2;
    }
    tp=(l->raiz)->sig;
    while(tp!=NULL){
    	temp=tp;
    	tp=tp->sig;
    	free(temp);
    }
    l->ultimo=l->raiz;
    return 0;    
}



