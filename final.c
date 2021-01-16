



// Librerias usadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// CONSTANTES usadas
#define TAM_VECTOR 22241         // Longitud total del array
#define NUM_ENTERO 1             // Longitud solo de la parte de entero

//VARIABLES GLOBALES usadas
int carry = 0;                  // Variable usada para saber si se produce acarreo en la operacione

// ==============================================================================================================================================           FUNCIONA BIEN
// Funcion que suma dos cadena 
int funcion_suma_bien (int cadena1_buena[], int cadena2_buena[], int resultado[]){
    //Funcion para sumar dos numeros ordenados como se nos indica en el enunciado
    // Tenemos la VARIABLE global carry que nos indica si hay acarreo en la operacion realizada. Siempre se debe poner a 0 al acabar.
    // La operaciones se hacen en el orden "normal", por lo tanto hay que utilizar la funcion invertir array
    int i, j;
    int cadena1[TAM_VECTOR], cadena2[TAM_VECTOR];

    // Copiamos los vectores en unos auxiliares para no modificarlos
    for(i=0; i< TAM_VECTOR; i++){
        cadena1[i] = cadena1_buena[i];
        cadena2[i] = cadena2_buena[i];
    }

    carry = 0;

    for(i = TAM_VECTOR; i >= 0; i--){          // Recordamos que el ultimo "bit" o numero es el reservado para el signo
        resultado[i] = cadena1[i]+cadena2[i];
        if(carry == 1){                         // Comprbamos si hay acarreo en la operacion anterior
            resultado[i] = resultado[i] + 1;    // Si hay acarreo le sumamos uno al resultado
            carry = 0;                          // Ponemos a 0 el acarreo
        }
        if(resultado[i] > 9){                   // Si el numero que hemos obtenido es mayor a 1, ponemos un 1 y aumentamos el acarreo
            resultado[i] = 0;                      // Ponemos un 1
            carry = 1;                          // Ponemos un 1 en el acarreo
        }
    }   
    carry = 0;

}

// ==============================================================================================================================================


// ==============================================================================================================================================       FUNCIONA BIEN
// Funcion para restar dos numeros guardados en cadenas de enteros.
//Tiene en cuenta el acarreo con la variable local carry, la cual esta a 1 cuando hay acarreo y a 0 cuando no lo hay.
// La operaciones se hacen en el orden "normal", por lo tanto hay que utilizar la funcion invertir array
int funcion_resta_bien (int cadena1_buena[], int cadena2_buena[], int resultado[]){
    int i, j;
    int cadena1[TAM_VECTOR], cadena2[TAM_VECTOR];

    // Copiamos los vectores en unos auxiliares para no modificarlos
    for(i=0; i< TAM_VECTOR; i++){
        cadena1[i] = cadena1_buena[i];
        cadena2[i] = cadena2_buena[i];
    }

    carry = 0;                                  // SIEMPRE debemos comprabar que el acarreo este a 0, si no la operacion no sera valida

    for(i = TAM_VECTOR; i > 0; i--){          // Recordamos que el 'ultimo "bit" o numero es el reservado para el signo
        
        if(cadena1[i] < cadena2[i]){
            cadena1[i-1] = cadena1[i-1] -1; // Restamos 1 al siguiente numero
            cadena1[i]= cadena1[i] + 10;
            resultado[i] = cadena1[i] - cadena2[i];

        }
        else
        {
            resultado[i] = cadena1[i] - cadena2[i];
        }
        

    }
    
    carry = 0;
}
// ==============================================================================================================================================


// ==============================================================================================================================================
// Funcion para multiplicar como las personas normales en vez de al reves

void funcion_multiplica_bien(int cadena1_buena[], int cadena2_buena[], int resultado[]){
    int i, j;
    int cadena1[TAM_VECTOR], cadena2[TAM_VECTOR];
    int matriz_intermedia[TAM_VECTOR][TAM_VECTOR];


    // Copiamos los vectores en unos auxiliares para no modificarlos
    for(i=0; i< TAM_VECTOR; i++){
        cadena1[i] = cadena1_buena[i];
        cadena2[i] = cadena2_buena[i];
    }

    // Vamos a multplicar como lo hariamos de forma normal, y guardarlo en una matriz cuadrada de TAM_VECTOR X TAM_VECTOR
    for(i = 0; i < TAM_VECTOR ; i++){

        for(j = 0; j < TAM_VECTOR; j++){
            resultado[i][j] = cadena1[i] * cadena2[j];
        }
    }    
    // Tenemos que sumar los numeros de la siguiente forma>>> 
    /*
            1 1 1 1
          1 1 1 1  
        1 1 1 1
      ---------------    
        1 2 3 3 2 1
    */

}


// ==============================================================================================================================================


// ==============================================================================================================================================
// Funcion que invierte un array con ayuda de un array auxiliar.
// Es decir, copia el primer elemento y lo pone en el ultimo del auxiliar. Luego lo que hace es copiar auxiliar al array original (Pasado por ref.)
int invertir_array(int *cadena1){
    int i, array_auxiliar[TAM_VECTOR];
    //Copiamos de forma inversa 
    for(i=0; i<TAM_VECTOR; i++){
        array_auxiliar[TAM_VECTOR-1-i] = cadena1[i];
    }
    // Cuando acabemos copiamos el array invertido en cadena de nuevo
    for(i=0; i<TAM_VECTOR; i++){
        cadena1[i] = array_auxiliar[i];
    }

}
// ==============================================================================================================================================


// ==============================================================================================================================================
// Limpiamos los vectores, introduciendo todo 0s 
int limpieza_vector(int vector[]){
    int i;
    for(i=0; i<TAM_VECTOR; i++){   // Recorremos el vector que nos pase por parametro
        vector[i] = 0;             // Le asignamos un 0
    }
}

// ==============================================================================================================================================



// ==============================================================================================================================================
// Funcion de Gauss Legendre a la cual le pasamos el numero de decimales, y todos los posibles vectores usados
// ; 

int gauss_legendre (int an[], int bn[], int tn[], int pn[], int xn[], int yn[], int pi[]){
    int temporal;
    long double pi_normal; // Lo usaremos para almacenar PI en el caso de alcanzar la precisiond eseada.

    printf("\n Se procede a un iteraccion de Gauss-Legendre\n");

    // La variables numero_de_numeros almacena la precision que deseamos obtener
    
    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // Vamos a repetir las siguientes instrucciones hasta que queramos la precision deseada
    // La cual es el numero que le pasamos por parametro a esta funcion 
    // (Numer de decimales)



    /*
    xn = ( (an + bn) / 2 );
    yn = sqrt(an*bn);
    // Para elevar al cuadrado usamos pow(numero,potencia)
    tn = tn - pn*(pow((an-xn),2));
    an = xn;
    bn = yn;
    pn = 2*pn;

    printf("\n++++++++++++++++++++++++++++++++");
    printf("\n xn = %lf", xn);
    printf("\n yn = %lf", yn);
    printf("\n tn = %lf", tn);
    printf("\n an = %lf", an);
    printf("\n bn = %lf", bn);
    printf("\n pn = %lf", pn);
    pi = ((pow((an + bn), 2)) / (4*tn));
    printf("\nPOSIBLE VALOR DE PI >> %Lf", pi);
    printf("\n++++++++++++++++++++++++++++++++\n");

    // Comprobamos si la iteraccion cumple con el requisitos de decimales.
    // "Repetir las siguientes instrucciones hasta que la diferencia entre an y bn se encuentre dentro de la precisión deseada"
    if((an-bn) >= numero_de_numeros){
        //Se ha alcanzado la precision deseada y por lo tanto el algoritmo puede terminar
        // Procedemos a calcular pi
        
        pi = (pow((an + bn), 2)) / (4*tn);

        printf("\n PI >> %Lf\n", pi);
        return 0;
    }
    else{
        // Volvemos a llamar a la funcion para calcular la siguiente iteraccion del algoritmo.
        gauss_legendre(numero_de_numeros, an, bn, tn, pn, xn, yn);
           
    }
    
    */

}


// ==============================================================================================================================================


// ==============================================================================================================================================
int numero_a_cadena(double numero, int cadena[]){
    if(numero < 0){ // Si es menor a cero entonces sabemos que el primer numero va a ser un 0
        cadena[0]=0;

    }
}

// ==============================================================================================================================================

// ==============================================================================================================================================
void inicializacion_de_variables(int an[], int bn[], int tn[], int pn[]){

    int i;
    // Vamos a inicializar el valor de AN, que es 1
    for(i = 0; i < TAM_VECTOR; i++){
        if(i == 0){
            an[i] = 1;
        }
        else{
            an[i] = 0;
        }
    }

    // Vamos a inicializar el valor de bn, el cual es 0.70710678118
    for(i = 0; i < TAM_VECTOR; i++){
        if(i == 0){
            bn[i] = 0;
        }
        if(i == 1){
            bn[i] = 7;
        }
        if(i == 2){
            bn[i] = 0;
        }
        if(i == 3){
            bn[i] = 7;
        }
        if(i == 4){
            bn[i] = 1;
        }
        if(i == 5){
            bn[i] = 0;
        }
        if(i == 6){
            bn[i] = 6;
        }
        if(i == 7){
            bn[i] = 7;
        }
        if(i == 8){
            bn[i] = 8;
        }
        if(i == 9){
            bn[i] = 1;
        }
        if(i == 10){
            bn[i] = 1;
        }
        if(i == 11){
            bn[i] = 8;
        }
        if(i > 11){
            bn[i] = 0;
        }   
    }   // FIN de bn

    // Vamos a inicializar el valor de TN, que es 1/4 = 0.25
    for(i = 0; i < TAM_VECTOR; i++){
        if(i == 0){
            tn[i] = 0;
        }
        if(i == 1){
            tn[i] = 2;
        }
        if(i == 2){
            tn[i] = 5;
        }
        if(i > 2){
            tn[i] = 0;
        }
        
    } // FIN DE TN

    // Vamos a inicializar el valor de PN, que es 1
    for(i = 0; i < TAM_VECTOR; i++){
        if(i == 0){
            pn[i] = 1;
        }
        else{
            pn[i] = 0;
        }
    }

}

// ==============================================================================================================================================


// ==============================================================================================================================================
void mostrar_vector_bien(int vector[]){
    int i;
    printf("\n");
    for(i=0; i< TAM_VECTOR; i++){
        if(i == 1){
            printf(".");
        }
        printf("%d", vector[i]);
    }
    printf("\n");
}
// ==============================================================================================================================================


// ==============================================================================================================================================
void mostrar_vector_inverso(int vector[]){
    int i;
    printf("\n");
    for(i=0; i< TAM_VECTOR; i++){
        if(i == (TAM_VECTOR - 1)){
            printf(".");
        }
        printf("%d", vector[i]);
    }
    printf("\n");
}
// ==============================================================================================================================================

// ==============================================================================================================================================
// Funcion principal en la que ejecutamos el programa.
int main (int argv, char *argc[]){

    int numero_decimales, numero_de_iteracciones, i;
    int an[TAM_VECTOR], bn[TAM_VECTOR], tn[TAM_VECTOR], pn[TAM_VECTOR], xn[TAM_VECTOR], yn[TAM_VECTOR], pi[TAM_VECTOR], vector_auxiliar[TAM_VECTOR]; 

    // Vemos si se ha introducido el parametro de forma correcta.
    if((argv < 2) || (argv > 2)){       // 2 porque 1 es la propia llamada al programa, 2 es el primer parametro, 3 seria el segundo, etc                           
        printf("\n\n\tNumero de parametros incorrectos\n\tSaliendo del programa\n\n");      // Mostramos mensaje de error
        return 1;   // Retornamos un 1 si hay error para que no se ejecute nada mas

    }

    // En el caso de que no haya error, pasamos el primer parametro a int y lo guardamos en la variable de numero de iteracciones.
    numero_decimales = atoi(argc[1]);;
    printf("\n Se van a calcular la iteracciones para %d decimales de PI\n\n", numero_decimales);

    // limpiamos los vectores, ya que puede haber datos resuduales dentro de ellos, nos aseguramos de que solom haya 0s
    // Pasamos estos vectores por referencia para que puedan ser modificados.
    limpieza_vector(an); 
    limpieza_vector(bn);
    limpieza_vector(tn);
    limpieza_vector(pn);
    limpieza_vector(xn);
    limpieza_vector(yn);
    limpieza_vector(pi);
    limpieza_vector(vector_auxiliar);
    
    //  Inicializamos las variables tal y como se indica en el algoritmo.
    inicializacion_de_variables(an, bn, tn, pn);

    // "Damos la vuelta" al vector
    invertir_array(an); 
    invertir_array(bn);
    invertir_array(tn);
    invertir_array(pn);
    invertir_array(xn);
    invertir_array(yn);
    invertir_array(pi);


    // Mostramos las variables que se muestran en el algoritmo para ver si se han inicializado bien
    //mostrar_vector_inverso(an);
    //mostrar_vector_inverso(bn);
    //mostrar_vector_inverso(tn);
    //mostrar_vector_inverso(pn);
    
    

     // Llamamos a la funcionde GAUSS LEGENDRE 
    gauss_legendre(an, bn, tn, pn, xn, yn, pi);



    
    
    
}
