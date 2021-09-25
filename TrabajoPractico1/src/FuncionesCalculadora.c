/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1
 Descripcion: Trabajo Practico 1
 ============================================================================
 */

float suma(float A, float B)
{
    return A + B;
}

float resta(float A, float B)
{
    return A - B;
}

float division(float A, float B)
{
    return A / B;
}

float multiplicacion(float A, float B)
{
    return A * B;
}

unsigned int factoreo(int A)
{
    unsigned int factoreo = 1;

    for( int i = A ; i > 1 ; i-- )
    {
       factoreo = factoreo * i ;
    }

    return factoreo;
}
