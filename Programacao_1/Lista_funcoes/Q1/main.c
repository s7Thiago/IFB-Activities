#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define VARPI 3.141592

float volume(float raio){

    float volume = (4 * VARPI * pow(raio, 3))/3;
    return volume;
}

int main() {
    float raio, resultado;

    printf("Digite o raio: \n");
    scanf("%f", &raio);



    printf("resultado: %.2f\n\n", volume(raio));

    return 0;
}
