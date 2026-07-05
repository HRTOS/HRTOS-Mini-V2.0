#include "os.h"

int main(void)
{
    char i;
	EA = 0;
    ET0 = 1;
    TMOD|=0X01;
    TH0 = 0x00;
    TL0 = 0x00;
    os_task_rdy_tbl = 0;////任务状态清零
    os_stack=(unsigned char)os_hrtos_stack;//获取堆栈初始值
	os_stack--;
	SP=os_stack;
    os_hrtos_wait=1;//wait机制支持
    os_en_cr_count = 0;//中断嵌套层数清零
	for(i=0; i<MAX_TASKS ;i++)//时间片清零防止触发
	{
		os_tcb[i].os_task_wait_tick = 0;
	}
	
	os_task_create(os_idle_task,0,0,0);//注册IDLE
	
	hrtos_main();

	os_task_running_id = MAX_TASKS;//任务号MAX_TASKS，系统自动加载0号任务
	
    os_hrtos_stack[0]=os_task_stack[0][0];//加载0号任务地址到data
    os_hrtos_stack[1]=os_task_stack[0][1];
	
    EA = 1;
    TR0 = 1;
	while(1);

}
