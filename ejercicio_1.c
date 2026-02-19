#include <stdio.h>

void invertirCadena(char *inicio) {
    char *fin = inicio;
    char aux;

    // 1. Mover 'fin' al último carácter antes del '\0'
    while (*fin != '\0') {
        fin++;
    }
    fin--; 

    // 2. Intercambio de valores
    while (inicio < fin) {
        // --- TU CÓDIGO AQUÍ ---
        // Implementa el intercambio usando la variable 'aux'
        // Desplaza los apuntadores adecuadamente

        aux = *inicio;          // Almacena el valor actual de inicio.
        *inicio = *fin;         // Cambia el valor de inicio por el de fin.
        *fin = aux;             // Cambia el valor de fin por el que guardamos al inicio, por lo que las dos letras de esta iteracion quedan invertidas.
        inicio++;
        fin--;
    }
}

int main() {
    char palabra[] = "APUNTADORES";
    printf("Original: %s\n", palabra);
    /*printf("%p\n\n", &palabra[0]);
    printf("%p\n\n", &palabra[1]);
    printf("%p\n\n", &palabra[2]);*/
    invertirCadena(palabra);
    printf("Invertida: %s\n", palabra);
    return 0;
}

//Durante el ciclo de intercambio (swap), la condición de parada es while (inicio < fin). 
//Explica detalladamente qué es lo que se está comparando físicamente en esa instrucción (¿valores o direcciones?) 

/* 

Lo que se compara son las direcciones de memoria en que nos encontramos, por ejemplo:

inicio = 0xA05
fin = 0xA09,

Al hacer algo como inicio++, estamos desplazándonos en la "cinta" de la memoria, lo que está almacenado en ellos no altera esto.*/

// y qué sucedería si la condición fuera while (*inicio != *fin).

/* En este caso estamos comparando los valores almacenados en las direcciones de los punteros inicio o fin, como si fueran variables normales.

Usar esta condicion no hace mucho sentido, pues comprobamos que lo almacenado en inicio sea distinto a lo almacenado en fin, 
por lo que en una palabra como ASIA, el bucle no se ejecutaría. */
