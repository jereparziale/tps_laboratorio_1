#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->pFirstNode=NULL;
    	this->size=0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i;
	Node* pNodo;
	if(this != NULL)
	{
		if(nodeIndex<ll_len(this) && nodeIndex >-1)
		{
			pNodo = this->pFirstNode;
			for(i=0; i<nodeIndex;i++)
			{
				pNodo = pNodo->pNextNode;
			}

		}
		else
		{
			pNodo=NULL;
		}
	}
	else
	{
		pNodo=NULL;
	}
    return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
	Node* nuevoNodo;
	Node* nodoBuffer;

	if(this != NULL && nodeIndex<=ll_len(this) &&nodeIndex >-1)
	{
		nuevoNodo=(Node*)malloc(sizeof(Node));
		if(nuevoNodo != NULL)
		{
			if(nodeIndex==0)
			{
				nuevoNodo->pNextNode= this->pFirstNode;
				this->pFirstNode=nuevoNodo;
			}
			else
			{
				nodoBuffer= getNode(this, nodeIndex-1);
				nuevoNodo->pNextNode= nodoBuffer->pNextNode;
				nodoBuffer->pNextNode=nuevoNodo;
			}
			returnAux=0;
			nuevoNodo->pElement=pElement;
			this->size++;
		}
		else
		{
			returnAux=-1;
		}
	}
	else
	{
		returnAux=-1;
	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int size=ll_len(this);
	if(this != NULL)
	{
		if(addNode(this, size, pElement)==0)
		{
			returnAux=0;
		}
	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodoAuxiliar;
   	if(this != NULL && (ll_len(this)>index && index >-1))
   	{
   		nodoAuxiliar=getNode(this, index);
   		if(nodoAuxiliar !=NULL)
   		{
   			returnAux=nodoAuxiliar->pElement;
   		}
   	}

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	int returnAux = -1;
	Node* nodoAuxiliar=NULL;
	if(this != NULL && (ll_len(this)>index && index >-1))
	{
		nodoAuxiliar=getNode(this, index);
		if(nodoAuxiliar !=NULL)
		{
			nodoAuxiliar->pElement=pElement;
			returnAux = 0;
		}
	}
return returnAux;
}
/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoAnterior;
    Node* nodoSiguiente;
    Node* nodoBorrar;
   	if(this != NULL && (ll_len(this)>index && index >-1))
   	{
   		if(index!=0)
   		{
			nodoAnterior=getNode(this, index-1);
			nodoSiguiente=getNode(this, index+1);
			nodoBorrar=getNode(this, index);
			nodoAnterior->pNextNode=nodoSiguiente;
			returnAux=0;
   		}
   		else
   		{
   			nodoSiguiente=getNode(this, index+1);
   			nodoBorrar=this->pFirstNode;
   			this->pFirstNode=nodoSiguiente;
   			returnAux=0;
   		}
   		nodoBorrar->pNextNode=NULL;
   		free(nodoBorrar);
   		this->size--;
   	}
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int size=ll_len(this);
    if(this != NULL && size>0)
	{
    	//ARRANCAR DESDE EL FINAL
    	for(i=size-1;i==0;i--)
    	{
    		ll_remove(this, i);
    	}
    	if(ll_len(this)==0)
    	{
    		returnAux=0;
    	}
	}
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
	{
    	if(ll_clear(this)==0)
    	{
    		free(this);
    		returnAux=0;
    	}
	}
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int size=ll_len(this);
    void* elementoAuxiliar=NULL;
    if(this !=NULL)
    {
    	for(i=0;i<size;i++)
    	{
    		elementoAuxiliar=ll_get(this, i);
    		if(pElement==elementoAuxiliar)
    		{
    			returnAux=i;
    			break;
    		}

    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if(ll_len(this)>0)
    	{
    		returnAux=0;
    	}
    	else
    	{
    		returnAux=1;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
	if(this != NULL &&(ll_len(this)>=index && index >-1))
	{
		if(addNode(this, index, pElement)==0)
		{
			returnAux=0;
		}
	}
    return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* nodoAnterior;
    Node* nodoSiguiente;
    Node* nodoBorrar;
   	if(this != NULL && (ll_len(this)>index && index >-1))
   	{
   		if(index!=0)
   		{
			nodoAnterior=getNode(this, index-1);
			nodoSiguiente=getNode(this, index+1);
			nodoBorrar=getNode(this, index);
			nodoAnterior->pNextNode=nodoSiguiente;
			returnAux=0;
   		}
   		else
   		{
   			nodoSiguiente=getNode(this, index+1);
   			nodoBorrar=this->pFirstNode;
   			this->pFirstNode=nodoSiguiente;
   			returnAux=0;
   		}
   		nodoBorrar->pNextNode=NULL;
   		returnAux=nodoBorrar->pElement;
   		this->size--;
   	}
    return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int size=ll_len(this);
    int i;
    int flag=0;
    if(this !=NULL)
    {
    	for(i=0;i<size;i++)
    	{
    		if(pElement==ll_get(this, i))
    		{
    			flag=1;
    			break;
    		}
    	}
    	if(flag==1)
    	{
    		returnAux=1;
    	}
    	else
    	{
    		returnAux=0;
    	}
    }
    else
    {
    	returnAux=-1;
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = 1;
    int i;
    int size2=ll_len(this2);
    if(this != NULL && this2 !=NULL)
    {
    	for(i=0;i<size2;i++)
    	{
    		//preguntar por ==0, si es caso que haya uno solo que no se encuentre rompo el bucle
    		if(ll_contains(this, ll_get(this2, i))==0)
    		{
    			returnAux=0;
    			break;
    		}
    	}
    }
    else
	{
		returnAux=-1;
	}
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* elementAux;
    int size=ll_len(this);
    if(this !=NULL && (from>=0 && size>=from) && (to>=0 && size>=to && to>from))
    {
    	cloneArray=ll_newLinkedList();
    	for(i=from;i<to;i++)
    	{
    		elementAux=ll_get(this, i);
			ll_add(cloneArray, elementAux);
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int size=ll_len(this);
    if(this !=NULL)
    {
    	cloneArray=ll_subList(this, 0, size-1);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux = -1;
	void* pElement_1 = NULL;
	void* pElement_2 = NULL;
	int flagSwap;
	int size=ll_len(this);
	int nuevoSize;

	if(this != NULL && pFunc != NULL && (order == 0 || order == 1)){
		switch(order)
		{
		case 0:
			do
			{
				flagSwap=0;
				nuevoSize= size-1;
				for (int i = 0; i < nuevoSize; i++) //hago tam-1 para que no intercambie con una varibale que no existe
				{
					pElement_1 = ll_get(this, i);
					pElement_2 = ll_get(this, i+1);
					if (pFunc(pElement_1, pElement_2)==-1)
					{
						flagSwap=1;
						ll_set(this, i, pElement_2);
						ll_set(this, i+1, pElement_1);
					}
				}
				returnAux=0;
				size--;
			}while(flagSwap==1);
		break;
		case 1:
			do
			{
				flagSwap=0;
				nuevoSize= size-1;
				for (int i = 0; i < nuevoSize; i++) //hago tam-1 para que no intercambie con una varibale que no existe
				{
					pElement_1 = ll_get(this, i);
					pElement_2 = ll_get(this, i+1);
					if (pFunc(pElement_1, pElement_2)==1)
					{
						flagSwap=1;
						ll_set(this, i, pElement_2);
						ll_set(this, i+1, pElement_1);
					}
				}
				returnAux=0;
				size--;
			}while(flagSwap==1);
		break;
		}
	}
	return returnAux;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
LinkedList* ll_Filter(LinkedList* this, int (*pFunc)(void*))
{
	LinkedList* thisAux=NULL;
	thisAux=ll_newLinkedList();
	void* pElement = NULL;
	int size=ll_len(this);
	if(this != NULL && pFunc != NULL){
		for (int i = 0; i < size; i++)
		{
			pElement = ll_get(this, i);
			if (pFunc(pElement)==1)
			{
				ll_add(thisAux, pElement);
			}
		}
	}
	return thisAux;
}

