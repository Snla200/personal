#include "BASEDATOS.c"  //incluya la base de datos
#include "func.c"

#define CARACTERES 8


int main(void){
/*
    char PATENTE[CARACTERES];   //vector en el cual se almacena la patente ingresada
    char *p;                    //puntero para  PATENTE[CARACTERES] 
    
    
    p= &PATENTE[0];
    
    printf("INGRESE PATENTE (TIPO AB123CD) A BUSCAR: ");
    fgets(PATENTE, CARACTERES, stdin);  //ingresa la patente
   
    for(int i=0;i<CARACTERES;i++){
        
        printf("coductor[%d]\npatente:[%s]\nnombre:[%s]\nDNI:[%s]\n",i,conductor[i].vecPat[i][1,conductor[i].vecNom[i][1],conductor[i].vecDni[i]);
    
    }
 
    printf("PATENTE INGRESADA:[%s]\n",p);   //impŕime la patente indicada en el puntero
 */
    
    asignarBBDD(struct BBDD V);
    printf("En BBDD:\n");
    printf("NOMBRE DEL CONDUCTOR:[%s]\n",vehiculo.vecNom[0]);
    printf("DNI DEL CONDUCTOR:[%d]\n",vehiculo.vecDni[0]);
    printf("PATENTE DEL VEHICULO:[%s]\n",vehiculo.vecPat[0]);
    return 0;
}


