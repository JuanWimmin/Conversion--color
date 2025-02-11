#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MIN_RESISTANCE 10
#define MAX_RESISTANCE 99999999

// Estructura que asocia valores con colores
typedef struct {
    int value;
    const char* color;
} ColorBand;

// Tabla de colores para los dígitos significativos
const ColorBand colorBands[] = {
    {0, "Negro"},  {1, "Marron"}, {2, "Rojo"},
    {3, "Naranja"}, {4, "Amarillo"}, {5, "Verde"},
    {6, "Azul"}, {7, "Violeta"}, {8, "Gris"}, {9, "Blanco"}
};

// Tabla de colores para los multiplicadores
const ColorBand multiplierBands[] = {
    {1, "Negro"}, {10, "Marron"}, {100, "Rojo"}, 
    {1000, "Naranja"}, {10000, "Amarillo"}, {100000, "Verde"},
    {1000000, "Azul"}, {10000000, "Violeta"}
};

/**
 * Obtiene el color correspondiente a un dígito significativo.
 * @param value El valor del dígito (0 a 9).
 * @return El color asociado al dígito o "Valor inválido" si está fuera del rango.
 */
const char* getColor(int value) {
    return (value >= 0 && value < 10) ? colorBands[value].color : NULL;
}

/**
 * Obtiene el color correspondiente a un multiplicador.
 * @param exponent El exponente de la base 10 (0 a 7).
 * @return El color asociado al multiplicador o "Multiplicador inválido" si está fuera del rango.
 */
const char* getMultiplierColor(int exponent) {
    return (exponent >= 0 && exponent < 8) ? multiplierBands[exponent].color : NULL;
}

int main() {
    int resistance;

    while (true) {
        printf("Introduce el valor de la resistencia (entre 10 y 99,999,999 ohms, 0 para salir): ");
       

        // Validación robusta de entrada
        if (scanf("%d", &resistance) != 1) {
            printf("Entrada inválida\n");
            while (getchar() != '\n'); // Limpiar el buffer
            continue;
        }
        // Verificar si el usuario quiere salir
        if (resistance == 0) {
            printf("Saliendo del programa...\n");
            break;
        }

        // Verificar si el valor está dentro del rango permitido
        if (resistance < MIN_RESISTANCE || resistance > MAX_RESISTANCE) {
            printf("Valor fuera de rango.\n");
            continue;
        }

        // Obtener el primer y segundo dígito significativo
        int firstDigit = resistance / (int)pow(10, (int)log10(resistance));
        int secondDigit = (resistance / (int)pow(10, (int)log10(resistance) - 1)) % 10;

        // Calcular el exponente del multiplicador
        int exponent = (int)log10(resistance) - 1;

        // Mostrar el valor de la resistencia y su código de colores
        printf("Valor de la resistencia: %d ohms\n", resistance);
        printf("Código de colores:\n");
        printf("Banda 1 (primera cifra): %s\n", getColor(firstDigit));
        printf("Banda 2 (segunda cifra): %s\n", getColor(secondDigit));
        printf("Banda 3 (multiplicador): %s\n", getMultiplierColor(exponent));
    }

    return 0;
}
