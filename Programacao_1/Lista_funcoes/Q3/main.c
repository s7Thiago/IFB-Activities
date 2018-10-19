#include <stdio.h>
#include <stdlib.h>

int tempoFabrica(int segundos) {
    //valores[0] = horas
    //valores[1] = minutos
    //valores[2] = segundos
    int valores[2];
    int hora, minutos, minuto, segundo;

    minutos = segundos/60;
    minuto = minutos % 60;
    segundo = segundos % 60;
    hora = minutos/3600;

    valores[0] = hora;
    valores[1] = minutos;
    valores[2] = segundos;

    return valores;
}

int main()
{
    int tempoS;
    int resultado[2];

    printf("Digite o tempo de duração em segundos: ");
    scanf("%d", &tempoS);

    resultado = tempoFabrica(tempoS);

    printf("Resultado: %d horas, %d minutos e %d segundos", resultado[0], resultado[1], resultado[2]);

    return 0;
}
