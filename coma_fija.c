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



*/


