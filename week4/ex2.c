#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define to_string(x) #x


int main() {
    
    for (int i = 0;  i < 3; i++) {
<<<<<<< HEAD
        fork();
        sleep(1);
=======
        pid = fork();
        //printf("%d\n", pid);
        sleep(5);
>>>>>>> f0100611613d1191b70bc721d06031cde74487a1
     }

    
<<<<<<< HEAD
  system("pstree $!");
=======
    //system("pstree");
>>>>>>> f0100611613d1191b70bc721d06031cde74487a1
}

/* 47752
 0
 47753
 0
 47754
 0
 47755
 47756
 0
 0
 47757
 0
 47758 */
