
 #include <stdio.h>
 
 /* Печать таблицы температур по Фаренгейту и Цельсию для fahr = 0, 20, ..., 300*/
 
 int main()


 {   
    int fahr;
 


     printf("температура:");
    
        for (fahr = 300; fahr >= 250; fahr = fahr - 20)
     {
         printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
     }    
  } 