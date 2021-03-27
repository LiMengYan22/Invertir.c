#include <stdio.h>
#include <stdlib.h>
#define LONG_MAX_CADENA 10


char *invertirCadena(char const *cadena);
int main(void)
{
   char cadena[LONG_MAX_CADENA];
   char *cad_inv;
   
   puts("Introduce la cadena a invertir:");
   if (fgets(cadena, LONG_MAX_CADENA, stdin) == NULL)
   return EXIT_FAILURE;
   
   cad_inv = invertirCadena(cadena);
   printf("Cadena invertida:%s\n", cad_inv);
   free(cad_inv);
   return EXIT_SUCCESS;
}
char *invertirCadena(char const *cadena)
{
   size_t num_chars;
   char *cad_inv;
   size_t i;
   
   /* Calcular el numero de caracteres en la cadena */
   for (num_chars = 0; cadena[num_chars] != '\0'; num_chars++)
      ;
   
   /* Reservar el bloque de memoria */
   if ((cad_inv = malloc(num_chars + 1)) == NULL)
      exit(EXIT_FAILURE);
   
   /* Copiar los caracteres en el orden inverso */
   for (i = 0; i < num_chars; i++)
      cad_inv[i] = cadena[num_chars - 1 - i];
   cad_inv[i] = '\0';
   
   return cad_inv;
}
