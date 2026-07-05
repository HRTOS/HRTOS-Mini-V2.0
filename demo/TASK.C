
#include<os_coop.h>
sfr P0M0 = 0x94;
sfr P0M1 = 0x93;
void task_0(void)
{
    while(1)
    {
        P0=0;
		os_task_yield();
    }
}
void task_1(void)
{
    while(1)
    {
        P0=1;
		os_task_yield();
    }
}
void task_2(void)
{
    while(1)
    {
        P0 = 0x3;
		os_task_yield();
    }
}
void task_3(void)
{
    while(1)
    {
        P0 = 7;
		os_task_yield();
    }
}
void task_4(void)
{
    while(1)
    {
        P0 = 15;
		os_task_yield();
    }
}
void hrtos_main(void)
{
    P0M0 = 0;
	P0M1 = 0;

    os_task_create(task_0,1,0,0);
    os_task_create(task_1,2,0,0);
    os_task_create(task_2,3,0,0);
    os_task_create(task_3,4,0,0);
    os_task_create(task_4,5,0,0);
	
    
}
