#include "os.h"

void os_enter_critical()
{
    EA=0;
    os_en_cr_count++;
}

