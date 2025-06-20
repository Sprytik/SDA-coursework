#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "MemoryNFilling.h"


int main() //Головна функція, викликає меню
{
    srand(time(NULL));
    menu();
    return 0;
}
