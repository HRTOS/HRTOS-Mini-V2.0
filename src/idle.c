#include "os.h"

void os_idle_task(void)
{
    while(1)
	{
		os_task_yield();
	
	}
}
