// Prueba algoritmo Gaus Legendre simple, calcula los primeros decimales de pi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gauss_legendre (int numero_de_numeros, double an, double bn, double tn, double pn, double xn, double yn){
    int temporal;
    long double pi; // Lo usaremos para almacenar PI en el caso de alcanzar la precisiond eseada.

    printf("\n Se procede a un iteraccion de Gauss-Legendre\n");

    // La variables numero_de_numeros almacena la precision que deseamos obtener
    
    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // Vamos a repetir las siguientes instrucciones hasta que queramos la precision deseada
    // La cual es el numero que le pasamos por parametro a esta funcion 
    // (Numer de decimales)

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
    


}


int main (int argc, char *argv[]){
    // Variables iniciales para el algoritmo de Gauss-Legendre
    int numero_de_numeros;
    double a0 = 1;
    double b0 = (1/ ( sqrt(2) ) ); 
    double t0 = ( 0.25 );
    double p0 = 1;
    double xn = 0;
    double yn = 0;

    if(argc != 2){
        printf("\n No se ha introducido el parametro correctamente\n");
        exit;
    }

    numero_de_numeros = atoi(argv[1]);
    printf("\n El numero de decimales a calcular es >> %d\n", numero_de_numeros);
    gauss_legendre(numero_de_numeros, a0, b0, t0, p0, xn, yn);


}
