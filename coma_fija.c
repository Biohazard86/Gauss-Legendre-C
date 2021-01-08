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
#define TAM_VECTOR 1000
#define NUM_ENTERO 10
#define NUM_SIGNO 1
#define NUM_DECIMAL 989

//VARIABLES GLOBALES usadas
int carry = 0;


int funcion_suma (int num1[TAM_VECTOR], int num2[TAM_VECTOR]){
    //Funcion para sumar dos numeros ordenados como se nos indica en el enunciado
    // Tenemos la VARIABLE global carry que nos indica si hay acarreo en la operacion realizada. Siempre se debe poner a 0 al acabar.
    int i, j;
    int num_final[TAM_VECTOR];

    carry = 0:

    for(i = 0; i < TAM_VECTOR-1; i++){          // Recordamos que el 'ultimo "bit" o numero es el reservado para el signo
        num_final[i] = num1[i]+num2[i];
        if(carry == 1){                         // Comprbamos si hay acarreo en la operacion anterior
            num_final[i] = num_final[i] + 1;    // Si hay acarreo le sumamos uno al resultado
            carry = 0;                          // Ponemos a 0 el acarreo
        }
        if(num_final[i] > 1){                   // Si el numero que hemos obtenido es mayor a 1, ponemos un 1 y aumentamos el acarreo
            num_final[i] = 1;                      // Ponemos un 1
            carry = 1;                          // Ponemos un 1 en el acarreo
        }
    }   
    carry = 0;

}

int funcion_resta (int *num1, int *num2, int *resultado){
    int i, j;

    carry = 0:

    for(i = 0; i < TAM_VECTOR-1; i++){          // Recordamos que el 'ultimo "bit" o numero es el reservado para el signo
        
        if(carry == 1){
            num1[i] = num1[i] - 1;              // Si en la operacion anterior ha habido acarreo entonces restamos uno al primer numero
            carry = 0;                          // Ponemos a cero el acarreo
        }
        num_final[i] = num1[i]-num2[i];         // Realizamos la resta entre ambos numeros
        if( num_final[i] < 0){                  // Si el numero es menor de 0 entonces lo ponemos a cero
            num_final[i] == 0;  
            carry = 1;                          // Y ponemos a 1 el acarreo
        }

    }
    
    carry = 0:
}


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


int main (int argv, char *argc[]){
    
    int num_cinco[TAM_VECTOR];
    int num_dos[2] = {1,2};
    int i,j;

    int num1[TAM_VECTOR];

    //Guardamos el numero cinco en el vector
    for(i = 0; i<TAM_VECTOR;i++){
       
        if((i == 0) || (i == 1) || (i == 3)){
            num_cinco[i] = 1; 
        }
        else{
            num_cinco[i] = 0;
        }
    }

    //Lo mostramos por pantalla
    printf("\nNumero 5 >>");
    printf("\nEl tam es de: %ld\n", sizeof(num_cinco));
    for(i = 0; i < TAM_VECTOR-1; i++){
        printf("%d  ", num_cinco[i]);
    }



    invertir_array(num_cinco);
    printf("\nEl tam es de: %ld\n", sizeof(num_cinco));
    for(i = 0; i < TAM_VECTOR; i++){
        printf("%d  ", num_cinco[i]);
    }

    
}
