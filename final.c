



// Librerias usadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// CONSTANTES usadas
#define TAM_VECTOR 22241         // Longitud total del array
#define NUM_ENTERO 1             // Longitud solo de la parte de entero
#define BASE 10

//VARIABLES GLOBALES usadas
int carry = 0;                  // Variable usada para saber si se produce acarreo en la operacione

// ==============================================================================================================================================           FUNCIONA BIEN
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

    invertir_array(cadena1);        // Colocamos los arrays en el orden normal para realizar las operaciones
    invertir_array(cadena2);;

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

    invertir_array(resultado);
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

    invertir_array(cadena1);        // Colocamos los arrays en el orden normal para realizar las operaciones
    invertir_array(cadena2);

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
    invertir_array(resultado);
    carry = 0;
}
// ==============================================================================================================================================


// ==============================================================================================================================================
// Funcion para realizar multiplicaciones de numeros grandes.
/*
void karatsuba(int cadena1_buena[], int cadena2_buena[], int resultado[]){
    int i, j, mitad_redondeado_arriba;
    int a[TAM_VECTOR], b[TAM_VECTOR];
    
    if((TAM_VECTOR%2) >= 1){
        mitad_redondeado_arriba = ((TAM_VECTOR/2) +1);
        //printf("\nMitad redondeado %d\n", mitad_redondeado_arriba);
    }
    else{
        mitad_redondeado_arriba = (TAM_VECTOR/2);
        //printf("\nMitad redondeado %d\n", mitad_redondeado_arriba);
    }
    
    // VARIABLES USADAS POR EL ALGORITMO DE KARATSUBA
    int c[TAM_VECTOR*2];
    int a1[mitad_redondeado_arriba], a2[mitad_redondeado_arriba], b1[mitad_redondeado_arriba], b2[mitad_redondeado_arriba];
    int c1[mitad_redondeado_arriba], c2[mitad_redondeado_arriba], c3[mitad_redondeado_arriba], c4[mitad_redondeado_arriba];
    int s; // Signo
    //--------

    // Copiamos los vectores en unos auxiliares para no modificarlos
    for(i=0; i< TAM_VECTOR; i++){
        a[i] = cadena1_buena[i];
        b[i] = cadena2_buena[i];
    }

    invertir_array(a);        // Colocamos los arrays en el orden normal para realizar las operaciones
    invertir_array(b);

    // Algoritmo de KARATSUBA
    if(n == 1){
        c[0] = a[0] * b[0];
        c[1] = c[0] / BASE;
        c[0] = c[0] % BASE;
    }
    else
    {
        
    }
    




    invertir_array(resultado);
}

*/

// Karatsuba >> Es un algortimo para multuplicar numeros grandes de forma eficiente.

unsigned long long pe;

unsigned long long mem,maxmem;

//Funcion para pedir memoria
int *pidemem(int n)
{
	mem+n;
	return (int *)calloc(n,sizeof(int));
}
// Funcion para liberar memoria
int liberamem(int *p,int k)
{
	mem-=k;
	free(p);
}


void sumal(int *a, int n, int *b, int m, int k)
{

	int l,carry=0;
	for(l=0;l<m;++l)
	{
		a[l+k]+=b[l]+carry;
		carry=a[l+k]/BASE;
		a[l+k]%=BASE;
	}
	if(carry>0) a[m+k]+=carry;
}
//de el resultado en a , devuelve el acarreo
int restal(int *a, int n, int *b, int m, int k)
{

	int l,carry=0;
	for(l=0;l<m;++l)
	{
		a[l+k]-=b[l]+carry;
		if(a[l+k]<0)
		{
			a[l+k]+=BASE;
			carry=1;
		}
		else carry=0;
		++l;
	}
	return carry;
}
// Compara
int compara(int *a, int *b, int n)
{
	int i;
  	for(i=n-1;i>=0;--i)
  	{
    	if(a[i]>b[i]) return 1;
   		if(a[i]<b[i]) return -1;
   	}
  	return 0;
}
int *copia(int *a, int i, int j, int k)
{	
	int l,*b=(int *)calloc(k,sizeof(int));
	for(l=i;l<=j;++l) b[l-i]=a[l];
	return b;

}
int *producto(int *a, int *b, int n)
{

	int *c=(int *)calloc(2*n,sizeof(int));
	if(n==1)
	{
		c[0]=a[0]*b[0];
		c[1]=c[0]/BASE;
		c[0]=c[0]%BASE;
		++pe;

	}
	else
	{
		int k=(n+1)/2;
		int *a1,*a2,*b1,*b2,*c1,*c2,*c3,*c4;
		a1=copia(a,0,k-1,k);
		a2=copia(a,k,n-1,k);
		b1=copia(b,0,k-1,k);
		b2=copia(b,k,n-1,k);
		// productos
		c1=producto(a1,b1,k);
		c2=producto(a1,b2,k);
		c3=producto(a2,b1,k);
		c4=producto(a2,b2,n-k);
		// sumas
		sumal(c,2*n,c1,2*k,0);
		sumal(c,2*n,c2,2*k,k);
		sumal(c,2*n,c3,2*k,k);
		sumal(c,2*n,c4,2*(n-k),2*k);
		// liberamos la memoria no necesaria
		free(a1);free(a2);free(b1);free(b2);
		free(c1);free(c2);free(c3);free(c4);
	}


	return c;
}

int *karatsuba(int *a,int *b, int n)
{
    //int n = TAM_VECTOR;
	int *c=(int *)calloc(2*n,sizeof(int));
	if(n==1)
	{
		c[0]=a[0]*b[0];
		c[1]=c[0]/BASE;
		c[0]=c[0]%BASE;
		++pe;

	}
	else
	{
		int k=(n+1)/2,s=1;
		int *a1,*a2,*b1,*b2,*c1,*c2,*c3;
		a1=copia(a,0,k-1,k);
		a2=copia(a,k,n-1,k);
		b1=copia(b,0,k-1,k);
		b2=copia(b,k,n-1,k);

		c1=karatsuba(a1,b1,k);
		c2=karatsuba(a2,b2,n-k);

		sumal(c,2*n,c1,2*k,0);
		sumal(c,2*n,c2,2*(n-k),2*k);
		sumal(c,2*n,c1,2*k,k);
		sumal(c,2*n,c2,2*(n-k),k);
		free(c1),free(c2);

		if(compara(a1,a2,k)>=0)
		{
			restal(a1,k,a2,n-k,0);
			free(a2);
		}
		else
		{
			restal(a2,k,a1,k,0);
			free(a1);
			a1=a2;
			s=-s;
		}
		if(compara(b1,b2,k)>=0)
		{
			restal(b1,k,b2,n-k,0);
			free(b2);
		}
		else
		{
			restal(b2,k,b1,k,0);
			free(b1);
			b1=b2;
			s=-s;
		}
		c3=karatsuba(a1,b1,k);
		if(s>0) restal(c,2*n,c3,2*k,k);
		else sumal(c,2*n,c3,2*k,k);

		free(a1);free(b1);free(c3);
	}
	return c;
}



// ==============================================================================================================================================


// ==============================================================================================================================================
// Funcion para dividir

void karatsuba_dividir(int cadena1_buena[], int numero_dividir, int resultado[]){
    int i, j;
    int cadena1[TAM_VECTOR], cadena2[TAM_VECTOR];

    // Copiamos los vectores en unos auxiliares para no modificarlos
    for(i=0; i< TAM_VECTOR; i++){
        cadena1[i] = cadena1_buena[i];
        
    }

    invertir_array(cadena1);        // Colocamos los arrays en el orden normal para realizar las operaciones
   
    if(numero_dividir == 2){

    }





    invertir_array(resultado);

}


// ==============================================================================================================================================

// ==============================================================================================================================================
// Funcion para dividir

void karatsuba_dividir_array(int cadena1_buena[], int cadena2_buena[], int resultado[]){
    int i, j;
    int cadena1[TAM_VECTOR], cadena2[TAM_VECTOR];

    // Copiamos los vectores en unos auxiliares para no modificarlos
    for(i=0; i< TAM_VECTOR; i++){
        cadena1[i] = cadena1_buena[i];
        cadena2[i] = cadena2_buena[i];
    }

    invertir_array(cadena1);        // Colocamos los arrays en el orden normal para realizar las operaciones
    invertir_array(cadena2);





    invertir_array(resultado);

}


// ==============================================================================================================================================

// ==============================================================================================================================================
// Funcion para raiz cuadrada

void sqrt_arrays(int array[], int resultado[]){
    int i, j;
    int cadena1[TAM_VECTOR], cadena2[TAM_VECTOR];

    // Copiamos los vectores en unos auxiliares para no modificarlos
    /*
    for(i=0; i< TAM_VECTOR; i++){
        cadena1[i] = cadena1_buena[i];
        cadena2[i] = cadena2_buena[i];
    }
    */
    invertir_array(cadena1);        // Colocamos los arrays en el orden normal para realizar las operaciones
    invertir_array(cadena2);





    invertir_array(resultado);

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
// Copia el array 1 en el array 2
int copia_array(int array1[], int array2[]){
    // No es necesario invertir aqui.
    int i;
    for(i=0; i<TAM_VECTOR; i++){   // Recorremos el vector que nos pase por parametro
        array2[i] = array2[i];
    }
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
void mostrar_vector_bien(int vector[]){
    invertir_array(vector);        // Colocamos los arrays en el orden normal para realizar las operaciones
    
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
    invertir_array(vector);        // Colocamos los arrays en el orden normal para realizar las operaciones
    
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


// ==========================================================================================================================================
int multiplicacion_por_numero(int cadena1_buena[], int numero){
    int i, acarreo, suma=0, resultado[TAM_VECTOR];
    for(i = 0; i < TAM_VECTOR; i++){
        resultado[i] = numero * cadena1_buena[i];
        resultado[i] = resultado[i] + acarreo;
        if(resultado[i] > 9){
            resultado[i] = resultado[i] / 10; 
        }else{
            resultado[i] = 0;
        } 
        suma=suma +  resultado[i];
    }
    return suma;
}
// ==========================================================================================================================================

// ==========================================================================================================================================
void inverso_de_a(int cadena1_buena[], int resultado[],int dos[]){
    int i,j;
    int cadena1[TAM_VECTOR], auxiliar1, auxiliar2, auxiliar3;
  
    // Copiamos los vectores en unos auxiliares para no modificarlos
    for(i=0; i< TAM_VECTOR; i++){
        cadena1[i] = cadena1_buena[i];
        
    }
    invertir_array(cadena1);

    // Realizamos los calculos
    resultado[0] = cadena1[0];
    for(i = 0; i< TAM_VECTOR-1; i++){
        auxiliar1 = multiplicacion_por_numero(cadena1, cadena1[i]);   // Multiplicamos toda la cadena por el numero i de la cadena y lo guardamos en auxiliar1 
         auxiliar2 = 2 - auxiliar1;   //funcion_resta_bien(dos, auxiliar1, auxiliar2);        // Restamos a 2 el dato que hay en auxiliar1 y lo guardamos en auxiliar2
        // ya solo nos queda multiplicar xn por auxiliar2
        auxiliar3 = cadena1[i] * auxiliar2;
        // Ya tenemos el resultado en auxiliar3
        resultado[i+1] = auxiliar3;
    }

    invertir_array(resultado);
}
// ==========================================================================================================================================

// ==========================================================================================================================================
void inverso_de_a_raiz(int cadena1_buena[], int resultado[],int dos[]){
    int i,j;
    int cadena1[TAM_VECTOR], auxiliar1, auxiliar2, auxiliar3;
  
    // Copiamos los vectores en unos auxiliares para no modificarlos
    for(i=0; i< TAM_VECTOR; i++){
        cadena1[i] = cadena1_buena[i];
        
    }
    invertir_array(cadena1);

    // Realizamos los calculos
    resultado[0] = cadena1[0];
    for(i = 0; i< TAM_VECTOR-1; i++){
        auxiliar1 = multiplicacion_por_numero(cadena1, ((cadena1[i])^2));   // Multiplicamos toda la cadena por el numero i de la cadena y lo guardamos en auxiliar1 
         auxiliar2 = 3 - auxiliar1;   //funcion_resta_bien(dos, auxiliar1, auxiliar2);        // Restamos a 2 el dato que hay en auxiliar1 y lo guardamos en auxiliar2
        // ya solo nos queda multiplicar xn por auxiliar2
        auxiliar3 = cadena1[i] * auxiliar2 / 2;
        // Ya tenemos el resultado en auxiliar3
        resultado[i+1] = auxiliar3;
    }

    invertir_array(resultado);
}
// ==========================================================================================================================================

// ==============================================================================================================================================
// Funcion de Gauss Legendre a la cual le pasamos el numero de decimales, y todos los posibles vectores usados
// ; 

int gauss_legendre (int an[], int bn[], int tn[], int pn[], int xn[], int yn[], int pi[], int numero_decimales, int dos[], int cuatro[], int cero_cinco[], int *numero_de_iteracciones){
    int *c;
    int temporal, array_auxiliar1[TAM_VECTOR], array_auxiliar2[TAM_VECTOR], array_auxiliar3[TAM_VECTOR], array_auxiliar4[TAM_VECTOR];   // Variables auxiliares.
    long double pi_normal; // Lo usaremos para almacenar PI en el caso de alcanzar la precisiond eseada.

    int n = TAM_VECTOR;
    printf("\n Se procede a un iteraccion de Gauss-Legendre\n");


    // La variables numero_decimales almacena la precision que deseamos obtener (Numero de decimales requerido)
    
    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // Vamos a repetir las siguientes instrucciones hasta que queramos la precision deseada
    // La cual es el numero que le pasamos por parametro a esta funcion 
    // (Numerp de decimales)
    // La primera iteraccion la vamos a realizar si o si.


// Pasos de GAUSS LEGENDRE
    // xn = ( (an + bn) / 2 );
    (*numero_de_iteracciones) = (*numero_de_iteracciones) + 1;
    funcion_suma_bien(an,bn, array_auxiliar1);                  // // Sumamos an y bn y lo guardamos en el array auxiliar1
    // Lo siguiente en realidad es una division entre dos
    c = karatsuba(array_auxiliar1, cero_cinco, n);     // Dividimos el resultado anterior entre 2 (multiplicamos por 0.5) y lo guardamos en el puntero c
    copia_array(c, xn);                           // Copiamos el valor de c en el array xn.
    // Podiamos haber pasado a la funcion karatsuba_dividir el valor de xn como "resultado". Seria igual de correcto

    // yn = sqrt(an*bn);
    limpieza_vector(array_auxiliar1);                   // Limpiamos el array auxiliar que vamos a usar ahora.
    limpieza_vector(array_auxiliar2);                   // Limpiamos el array auxiliar que vamos a usar ahora.
    c = karatsuba(an, bn, n);                 // Multiplicamos an por bn y lo guardamos en array auxiliar 1
    copia_array(c, array_auxiliar1);
    inverso_de_a_raiz(array_auxiliar1, array_auxiliar2, dos);// Calculamos la raiz
    inverso_de_a(array_auxiliar2, array_auxiliar3, dos);     //Hacemos el inverso del calculo de la raiz para obtener el resultado
    //sqrt_arrays(array_auxiliar1, array_auxiliar2);      // calculamos la raiz cuadrada del calculo anterior y la guardamos en array auxiliar2
    copia_array(array_auxiliar3, yn);

    //tn = tn - pn*(pow((an-xn),2));
    limpieza_vector(array_auxiliar1);                   // Limpiamos el array auxiliar que vamos a usar ahora.
    limpieza_vector(array_auxiliar2);                   // Limpiamos el array auxiliar que vamos a usar ahora.
    funcion_resta_bien(an, xn, array_auxiliar1);        // Realizamos la resta y la guardamos en array auxiliar 1
    c = karatsuba(array_auxiliar1, array_auxiliar1, n); // Para elevar al cuadrado, multiplicamos el numero por el mismo, y lo guaramos el array auxiliar 2
    copia_array(c, array_auxiliar2);
    c = karatsuba(pn, array_auxiliar2, n);    // Multiplicamos pn * auxiliar 2 y lo guardamos en auxiliar 3
    copia_array(c, array_auxiliar3);
    funcion_resta_bien(tn, array_auxiliar3, array_auxiliar4);   // Restamos a tn, el array auxiliar 3 y lo guardamos en auxiliar 4
    copia_array(array_auxiliar4, tn);

    // an = xn;
    limpieza_vector(array_auxiliar1);                   // Limpiamos el array auxiliar que vamos a usar ahora.
    limpieza_vector(array_auxiliar2);                   // Limpiamos el array auxiliar que vamos a usar ahora.
    limpieza_vector(array_auxiliar1);                   // Limpiamos el array auxiliar que vamos a usar ahora.
    limpieza_vector(array_auxiliar2);                   // Limpiamos el array auxiliar que vamos a usar ahora.
    copia_array(xn, an);        // Copiamos el array xn en el array an

    //bn = yn;
    copia_array(yn, bn);        // Copiamos el array yn en el array bn

    //pn = 2*pn;
    c = karatsuba(pn, dos, n);          // Hacemos la multiplicacion y 
    copia_array(c, array_auxiliar1);    // Guardamos el resultado anterior en auxiliar 1
    copia_array(array_auxiliar1, pn);   // Guardamos el resultado en pn
    limpieza_vector(array_auxiliar1);                   // Limpiamos el array auxiliar que vamos a usar ahora.

    // Ya tenemos todos los calculos realizados, ahora tenemos que comprobar si se ha alcanzado la precision deseada o si por el contrario, necesitamos una nueva iteraccion del algoritmo. 
    // Para ello (an-bn) tiene que ser mayor o igual al numero de decimales requeridos
    // Primero realizamos la resta fuera del if, para una mayor claridad del codigo
    funcion_resta_bien(an,bn, array_auxiliar1);
    if(array_auxiliar1[0] >= numero_decimales){     // Si la parte entera del array de la resta (an-bn) es mayor o igual al numero de decimales de precision requerido
        // Entonces hemos acabado, procedemos a calcular pi
        limpieza_vector(array_auxiliar1);
        //an+bn
        funcion_suma_bien(an, bn, array_auxiliar1);                     // Sumamos an + bn
        //(an+bn)^2
        c = karatsuba(array_auxiliar1, array_auxiliar1, n);   // Multiplicamos al resultado de la suma de an+bn por el mismo.
        copia_array(c, array_auxiliar2);                      // Guardamos el resultado en auxiliar 2
        //4*tn  
        c = karatsuba(tn, cuatro, n);                         // Multiplicamos tn por 4
        copia_array(c, array_auxiliar3);                      // Guardamos el resultado en auxiliar 3
        // auxiliar2 entre auxiliar 3
        karatsuba_dividir_array(array_auxiliar2, array_auxiliar3, array_auxiliar4);
        // Copiamos el resultado al array de pi
        copia_array(array_auxiliar4, pi);

        printf("\n\n\tSe ha calculado PI\n");

        // Retornamos un 0 como senial de que no hay ningun error.
        return 0;
    }
    else{
        // Si no se cumple la condicion, entonces es que necesitamos mas precision, lo llamamos de forma recursiva.
        gauss_legendre(an, bn, tn, pn, xn, yn, pi, numero_decimales, dos, cuatro, cero_cinco, numero_de_iteracciones);

    }





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
void inicializacion_de_variables(int an[], int bn[], int tn[], int pn[], int dos[], int cuatro[], int cero_cinco[]){

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

    // Vamos a inicializar el valor de dos, que como su nombre nos indica, es dos
    for(i = 0; i < TAM_VECTOR; i++){
        if(i == 0){
            dos[i] = 2;
        }
        else{
            dos[i] = 0;
        }
    }

    // Vamos a inicializar el valor de cuatro, que como su nombre nos indica, es cuatro
    for(i = 0; i < TAM_VECTOR; i++){
        if(i == 0){
            cuatro[i] = 4;
        }
        else{
            cuatro[i] = 0;
        }
    }

    // Vamos a inicializar el valor de cero coma 5, que como su nombre nos indica, es 0.5
    for(i = 0; i < TAM_VECTOR; i++){
        if(i == 0){
            cero_cinco[i] = 0;
        }
        if(i == 1){
            cero_cinco[i] = 5;
        }
        if(i > 1){
            tn[i] = 0;
        }
        
        
    }

}

// ==============================================================================================================================================




// ==============================================================================================================================================
// Funcion principal en la que ejecutamos el programa.
int main (int argv, char *argc[]){

    int numero_decimales, numero_de_iteracciones = 0, i;
    int an[TAM_VECTOR], bn[TAM_VECTOR], tn[TAM_VECTOR], pn[TAM_VECTOR], xn[TAM_VECTOR], yn[TAM_VECTOR], pi[TAM_VECTOR], vector_auxiliar[TAM_VECTOR], dos[TAM_VECTOR], cuatro[TAM_VECTOR], cero_cinco[TAM_VECTOR]; 

    // Vemos si se ha introducido el parametro de forma correcta.
    if((argv < 2) || (argv > 2)){       // 2 porque 1 es la propia llamada al programa, 2 es el primer parametro, 3 seria el segundo, etc                           
        printf("\n\n\tNumero de parametros incorrectos\n\tSaliendo del programa\n\n");      // Mostramos mensaje de error
        return 1;   // Retornamos un 1 si hay error para que no se ejecute nada mas

    }

    // En el caso de que no haya error, pasamos el primer parametro a int y lo guardamos en la variable de numero de iteracciones.
    numero_decimales = atoi(argc[1]);
    if(numero_decimales < 1){
         printf("\n\n\tNumero demasiado bajo. Saliendo del programa\n\n");      // Mostramos mensaje de error
	 return 1;
    }
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
    inicializacion_de_variables(an, bn, tn, pn, dos, cuatro, cero_cinco);

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
    gauss_legendre(an, bn, tn, pn, xn, yn, pi, numero_decimales, dos, cuatro, cero_cinco, &numero_de_iteracciones);

    // Si se ejecuta hasta aqui es que ya se ha calculado pi. Podemos guardarlo en un archivo para comprobar la exactitud
    printf("\n\n Se ha ejecutado con un total de %d iteracciones\n", numero_de_iteracciones);
}
