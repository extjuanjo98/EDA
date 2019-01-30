#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p)
{
   	*p=NULL;
	return 0;   
    
}

int pilaVacia(Pila *p)
{
    	if(*p==NULL)
		return 1;
	return 0;
    
    
}

int pilaInserta(tipoElemento elemento, Pila *p)
{
    	Pila aux=*p;
	Pila nuevo= (Pila) malloc(sizeof (tipoCelda));

	if(nuevo == NULL)
		return -1;
	
	nuevo->sig=NULL;
	nuevo->elemento= elemento;

	if(pilaVacia(p)){
		*p=nuevo;

	}else{
		nuevo->sig=*p;
		*p=nuevo;
	}
	return 0;
    
    
}

tipoElemento pilaSuprime(Pila *p)
{
    	tipoElemento element;
	Pila aux=*p;

	if(aux==NULL)
		 exit(-1);
	element=aux->elemento;
	*p=aux->sig;	
	free(aux);
	return element;    
}
