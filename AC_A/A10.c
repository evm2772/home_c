#include <stdio.h>
#include <inttypes.h>

typedef union 
{
    float data;
    unsigned int integer;

} floatData_t;

int extractExp(float f)
{
    floatData_t float_u;
    float_u.data = f;
    uint32_t temp;

    // remove sign
    temp  = float_u.integer << 1;
    //get exponenta
    temp  >>= 24;
    return temp;
}   

int main()
{
    float f;
    scanf("\n%f", &f);
    printf ("%d", extractExp(f));

}