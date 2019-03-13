/* print current date and time */

#include <time.h>
#include <stdio.h>

int main(void){
    time_t current = time(NULL);

    printf("current date and time: %s", asctime(localtime(&current)));
    printf("current local date and time: %s", ctime(&current));
    
    return(0);
}
