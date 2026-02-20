#include <stdio.h>

void enteroABinario(int n, char *cadena) {
    for (int i = 31; i >= 0; i--) {
        *(cadena + (31 - i)) = (n >> i & 1) ? '1' : '0';
    }
    *(cadena + 32) = '\0';
}

int main() {
    int num, unos = 0;                           //"num" guarda el número que elegimos y "unos" es el contador de 1
    char bin[33], *p = bin;                      // El arreglo de texto es "bin" y "p" es el apuntador que apunta al principio de "bin"
    
    printf("Ingresa un entero positivo: ");      //Pide que ingresemos un número positivo
    scanf("%d", &num);                           //El número se guarda en "num"
    if(num<0){                                   //Si el número el menor a 0 
        printf("El número debe ser positivo");   //Imprime que el número debe ser positivo
        return 1;                                //Se termina el porgrama
    }
    enteroABinario(num, bin);                    //Trae a la función enteroABinario para llnar el arreglo "bin" con 0 y 1.
    printf("Binario: %s\n", bin);                //Se imprime el texto que resultó.

    // --- TU CÓDIGO AQUÍ ---
    // Usa 'p' para recorrer 'bin' y contar los '1's
    while(*p!='\0') {                            //Mientras lo que está en la dirección de "p" no sea el fin de esa cadena.
        if(*p== '1'){                            //Si el caracter actual es el dibujo de 1 
            unos=unos+1;                         //Si hay, se suma al contador
        } 
        p=p+1;                                    //"p" se va a la siguiente dirección de memoria
    }

    printf("Total de bits '1': %d\n", unos);       //Se imprimen cuantos unos había
    return 0;                                      //Se caba el programa
}

// PREGUNTA: En la función enteroABinario, estamos pasando un int (4 bytes) y un apuntador char *. 
// Si un int ya vive en la memoria como una secuencia de bits, 
// ¿por qué es necesario 'convertirlo' a una cadena de caracteres para contarlos con el apuntador?
//RESPUESTA: Porque los apuntadores no ven bits y solo se puede enfocar en un byte (un grupo de 8 bits) y no puede apuntar a un bit individual. Cuando se transforma en cadena lo que se hace es tomar un bit del número y se pone dentro de su propio espacio (byte). Así, p ya puede ir avanzando para ver qué hay en cada espacio.
