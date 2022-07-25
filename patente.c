#include "BASEDATOS.h"  //incluya la base de datos
#include "func.h"

#define CARACTERES 8


int main(void){
/*
    char PATENTE[CARACTERES];   //vector en el cual se almacena la patente ingresada
    char *p;                    //puntero para  PATENTE[CARACTERES] 
    
    
    p= &PATENTE[0];
    
    printf("INGRESE PATENTE (TIPO AB123CD) A BUSCAR: ");
    fgets(PATENTE, CARACTERES, stdin);  //ingresa la patente
 
    printf("PATENTE INGRESADA:[%s]\n",p);   //impŕime la patente indicada en el puntero
 */
    
   asignarBBDD(vehiculo);
   

    printf("En BBDD:\n");
    printf("NOMBRE DEL CONDUCTOR:[%s]\n",vehiculo.vecNom[0]);
    printf("DNI DEL CONDUCTOR:[%d]\n",vehiculo.vecDni[0]);
    printf("PATENTE DEL VEHICULO:[%s]\n",vehiculo.vecPat[0]);
    
    return 0;
}


