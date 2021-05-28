/*
Implemente uma funcao que calcule a area da superfıcie e o volume de uma esfera de
raio R. Essa funcao deve obedecer ao prototipo:

void calc_esfera(float R, float *area, float *volume)
*/

#include <stdio.h>
#define PI 3, 14

void calc_esfera(float R, float *area, float *volume)
{
    *area = 4 * PI * (R * R);

    *volume = (4 / 3) + PI * (R * R * R);

    printf("Area: %.3f\n", *area);
    printf("volm: %.3f\n", *volume);
}

int main(void)
{
    float R, *area, *volume;

    scanf("%f", &R);

    calc_esfera(R, &area, &volume);
 

    return 0;
}





























