/*
La representación de coma fija es una forma de notación científica que consiste en destinar una cantidad fija de dígitos para la parte entera y otra para la parte fraccionaria. 
La cantidad de dígitos destinados a la parte fraccionaria indica en definitiva la posición de la coma dentro del número. Esta posición, que es siempre fija, 
la podemos indicar con un factor de escala implícito que ubica la coma en el lugar requerido. Es decir, podemos representar un número fraccionario como un número entero multiplicado 
por un factor de escala. En general, el factor de escala puede ser arbitrario e indica cuál es la longitud del intervalo que separa dos representaciones consecutivas, 
por ejemplo: dn-1dn-2…d0,d-1d-2…d-m=dn+m-1…d0 · b-m. 

Esta longitud es siempre fija para cualquier par de representaciones consecutivas en todo el rango de representación. En este sistema, el programador debe modificar el factor de escala 
cuando alguna operación produce un resultado fuera del rango de representación.

Con este sistema se representan los enteros desde el − ( 2 n − 1 − 1 )  hasta el ( 2 n − 1 − 1 ), siendo n el número de bits. Por tanto el rango de representación es
[ − 2 n − 1 + 1 , 2 n − 1 − 1 ] y la resolución es de “1″. El “cero” presenta las dos representaciones 000…00 y 100…00, lo que a veces genera dificultades.

Por ejemplo, el valor de los siguientes números, todos ellos representados con 8 bits:

    10101,110 = 1×24 + 0×23 + 1×22 + 0×21 + 1×20 + 1×2-1 + 1×2-2 + 0×2-3 = 21,75base10

    01001,011 = 0×24 + 1×23 + 0×22 + 0×21 + 1×20 + 0×2-1 + 1×2-2 + 1×2-3 = 9,375base10

De los 8 bits hemos fijado y reservado 5 para la parte entera y 3 para la fraccionaria. En los anteriores ejemplos la coma está fija y sirve para separar la parte entera de la parte fraccionaria. 



+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
El  programa  utilizar ́a  n ́umeros  en  coma  fija,  representando  los  n ́umeros  como  enteros  enuna base dada (10, 100, 1000, etc.),
en los que la cifra menos significativa sea la primera, y la ́ultima sea la parte entera.

=======================

Vamos a usar al menos vectores de enteros de al menos 22241 elementos (el ejemplo .txt)
En realidad vamos a usar 32.728 elementos de tipo int lo que cada numero constara de un tamanio de 32.728 x 2 bytes de 65.536 bytes o 524.288 bites

contando con que vamos a representar 7 numeros con este metodo >> 
65.536bytes x 7numeros = 458.752 bytes ocuparan estos numeros

Los numeros son representados de forma inversa, es decir la parte entera se encuentra a la derecha del numero y de forma inversa.

Para representar 3.14 -> 41.3 (en decimal)
Pero nosotros vamos a representarlo en forma binaria (suponemos un vector de 8 elementos)
00000.000
Quedando como resultado
3 / 2 = 1 /2 1
por lo tanto la parte entera es 11 siendo el de la derecha el mas significativo
para 2. (...) seria 02 

14 en binario es 01110
por lo que el numero final es 
01110.110 -> 01110110 = 3.14

En nuestro caso la 'ultima posicion (empezando a contar por la izquierda), esta reservada para el signo, las diez anteriores para la parte entera
el resto se usara para la parte decimal.
La cifra mas significativa es la de la derecha del vector, y la menos significativa la de la izquierda.


*/

// Librerias usadas
#include <stdlib.h>
#include <stdio.h>

// CONSTANTES usadas
#define TAM_VECTOR 1000         // Longitud total del array
#define NUM_ENTERO 10           // Longitud solo de la parte de entero
#define NUM_SIGNO 1             // Longitud solo del signo, el "mas a la derecha" 
#define NUM_DECIMAL 989         // Longitud solo de los decimales 

//VARIABLES GLOBALES usadas
int carry = 0;                  // Variable usada para saber si se produce acarreo en la operaciones

// ==============================================================================================================================================
// Funcion que suma dos cadena 
int funcion_suma (int *num1, int *num2, int *resultado){
    //Funcion para sumar dos numeros ordenados como se nos indica en el enunciado
    // Tenemos la VARIABLE global carry que nos indica si hay acarreo en la operacion realizada. Siempre se debe poner a 0 al acabar.
    // La operaciones se hacen en el orden "normal", por lo tanto hay que utilizar la funcion invertir array
    int i, j;
    

    carry = 0;

    for(i = TAM_VECTOR; i > 0; i--){          // Recordamos que el ultimo "bit" o numero es el reservado para el signo
        resultado[i] = num1[i]+num2[i];
        if(carry == 1){                         // Comprbamos si hay acarreo en la operacion anterior
            resultado[i] = resultado[i] + 1;    // Si hay acarreo le sumamos uno al resultado
            carry = 0;                          // Ponemos a 0 el acarreo
        }
        if(resultado[i] > 1){                   // Si el numero que hemos obtenido es mayor a 1, ponemos un 1 y aumentamos el acarreo
            resultado[i] = 1;                      // Ponemos un 1
            carry = 1;                          // Ponemos un 1 en el acarreo
        }
    }   
    carry = 0;

}
// ==============================================================================================================================================


// ==============================================================================================================================================
// Funcion para restar dos numeros guardados en cadenas de enteros en forma binaria.
//Tiene en cuenta el acarreo con la variable local carry, la cual esta a 1 cuando hay acarreo y a 0 cuando no lo hay.
// La operaciones se hacen en el orden "normal", por lo tanto hay que utilizar la funcion invertir array
int funcion_resta (int *num1, int *num2, int *resultado){
    int i, j;

    carry = 0;                                  // SIEMPRE debemos comprabar que el acarreo este a 0, si no la operacion no sera valida

    for(i = TAM_VECTOR; i > 0; i--){          // Recordamos que el 'ultimo "bit" o numero es el reservado para el signo
        
        if(carry == 1){
            num1[i] = num1[i] - 1;              // Si en la operacion anterior ha habido acarreo entonces restamos uno al primer numero
            carry = 0;                          // Ponemos a cero el acarreo
        }
        resultado[i] = num1[i]-num2[i];         // Realizamos la resta entre ambos numeros
        if( resultado[i] < 0){                  // Si el numero es menor de 0 entonces lo ponemos a cero
            resultado[i] == 0;  
            carry = 1;                          // Y ponemos a 1 el acarreo
        }

    }
    
    carry = 0;
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
// Funcion para convertir numeros de decimal a binario, para poder tratarlos con nuestro programa
int convertir_decimal_a_binario(int numero, int *cadena1){
    // El numero que recibimos por parametro se trata del numero que vamos a tratar 
    // La cadena es un puntero al string de TAM_VECTOR elementos en el cual vamos a almacenar el numero

    int i,t,q=0;
    int numero_numeros;
    numero_numeros = cuenta_cifras(numero);
    int cadena_numero[numero_numeros];
    int resto, divisor;
    int cadena_aux[TAM_VECTOR];
    

    // Lo primero es poner a 0 todo la cadena en la cual vamos a escribir, para asegurarnos de que todos los "bits" estan a cero
    for( i = 0; i < TAM_VECTOR; i++){
        cadena1[i] = 0;
    }

    divisor = numero;                           // Guardamos el numero como divisor
    i = 0;                                      // Usaremos el indice i como posicion para guardar el resto
    do{                                         // hacemos un bucle con do-while
        divisor = divisor / 2;                  // dividimos divisor entre dos y lo guardamos en divisor para la siguiente iteraccion
        resto = divisor % 2;                    // Calculamos el resto para guardarlo como parte del numero
        if((resto == 1) || (resto == 0)){       // If que nos sirve de control para ver que no pase nada raro 
            cadena1[i] = resto;                 // Si todo va bien guardamos el numero en la cadena
        }else{
            printf("\nERROR\n");                // Si hay algun problema imprimimos el error
            
        }
        i++;                                    // Incrementamos el contador del indice

    }while(resto >= 1);

    // Como el numero puede no ser del mismo tamanio maximo, tenemos que completarlo.

    for(t=i;t==0;t--){                          // Si al pasar de decima a binario hemos tenido X iteracciones, entonces vamos a la posicion X del vector para empezar ahi hasta la posicion 0
        cadena_aux[q] = cadena1[t];              // q empieza en la 0, porque al pasar de decimal a binario se va calculando "del reves"

        q++;                                    // Incrementamos q para avanzar en el vector
        if(t==0){                               // Cuando llegamos a la primera posicion del vector, el resto de posiciones, desde q hasta TAM_VECTOR son 0
            for(i=q;i<TAM_VECTOR;i++){          // FOR para poner a 0 el resto del vector
                cadena_aux[i] = 0;
            }
        }
    }

    // Ahora vamos a copiar la cadena aux en la cadena que nos han pasado
    printf("\n");
    for(i=0; i<TAM_VECTOR; i++){                // For para copiar un vector a otro
        cadena1[i] = cadena_aux[i];
        printf(" %d", cadena1[i]);            // Lo vamos mostrando por pantalla a la vez
    }
    printf("\n");

}

// ==============================================================================================================================================


// ==============================================================================================================================================
// Funcion para calcular el numero de cifras de un numero
int cuenta_cifras(int num){
    int i=10, t=0;
    
    do{
        t++;                    //El numero de cifras
        if((num / i) == 0){     // Si la division entre el numero y un multiplo de 10 es 0 entonces es que hemos llegado al maximo de cifras
            return t;           // Retornamos el numero de cifras
            
        }else{                  // Si no
            i=i*10;             // Seguimos incrementando en un multiplo de 10 el numero i
        }
    }
    while(1);                    // Bucle infinito

}

// ==============================================================================================================================================


// ==============================================================================================================================================
// Funcion principal en la que ejecutamos el programa.
int main (int argv, char *argc[]){
    
    int num_cinco[TAM_VECTOR], num_parametro[TAM_VECTOR];
    int num_dos[2] = {1,2};
    int i,j;

    int num1[TAM_VECTOR];


    convertir_decimal_a_binario(argc[1], num_cinco);
    //Guardamos el numero cinco en el vector
    //for(i = 0; i<TAM_VECTOR;i++){
       
    //    if((i == 0) || (i == 1) || (i == 3)){
    //        num_cinco[i] = 1; 
    //    }
    //    else{
    //        num_cinco[i] = 0;
    //    }
    //}
    
    //Lo mostramos por pantalla
    //printf("\nNumero 5 >>");
    //printf("\nEl tam es de: %ld\n", sizeof(num_cinco));
    //for(i = 0; i < TAM_VECTOR-1; i++){
    //    printf("%d  ", num_cinco[i]);
    //}



    //invertir_array(num_cinco);
    //printf("\nEl tam es de: %ld\n", sizeof(num_cinco));
    //for(i = 0; i < TAM_VECTOR; i++){
    //    printf("%d  ", num_cinco[i]);
    //}

    
}
