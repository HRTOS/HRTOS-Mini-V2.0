#include "os.h"

char os_task_create(unsigned int task_point,unsigned char task_id ,unsigned char pr,unsigned char sd)          /*进程注册 地址，编号，优先级，层数*///void os_task(unsigned char task_id ,unsigned int task_point)
{
    os_enter_critical();
	pr = pr;
	sd = sd;
    os_task_stack[task_id][0] = task_point;//地址
    os_task_stack[task_id][1] = task_point>>8;
	
    os_tcb[task_id].os_task_stack_top = os_stack+11;//11;//系统9，进中断2
	
    os_task_rdy_tbl |= os_map_tbl[task_id];//生效
    os_tcb[task_id].os_task_wait_tick = 0; //延时
    os_exit_critical();
	return 0;
}