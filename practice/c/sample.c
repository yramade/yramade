#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int i;

    srand( (unsigned) time (NULL) );
   
    FILE *fp;
    fp = fopen("rand.dat", "w+");
    for( i=0; i<6; i++ )
    {
        //printf( "random %d : %d \n", i, rand()%45+1 );
        fprintf(fp, "%d\n", rand()%45+1);
    }
    fclose(fp);
    system("gnuplot -e \"p 'rand.dat' with lines; pause -1\"");
    
    return 0;
}