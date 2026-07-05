
#include "os.h"

void os_scheduler(void) interrupt 1
{
    unsigned char i,j;
	
    TF0=0;//T0中断触发清除
	
	if(os_task_running_id==MAX_TASKS)//首次进入
	{
		ET0=0;
		i=0;
		goto OS_HRT;//跳转
	}
	
    os_tcb[os_task_running_id].os_task_stack_top=SP;//记录当前堆栈栈顶
	
    j= SP-os_stack-9;
	
    if(os_hrtos_wait)//时间唤醒
    {
        for(i=0; i<MAX_TASKS; i++)
        {
            if(os_tcb[i].os_task_wait_tick)
            {
                os_tcb[i].os_task_wait_tick--;
                if(os_tcb[i].os_task_wait_tick == 0)
                {
                    os_task_rdy_tbl |= os_map_tbl[i];
                }
            }
        }
    }
    else 
	{ 
		os_hrtos_wait=1;
	}
	
    for(i=0; i<j; i++)   //保护
    {
        os_task_stack[os_task_running_id][i]=os_hrtos_stack[i];
    }
    for (i=os_task_running_id+1; i<MAX_TASKS; i++)//筛选
    {
        if(os_task_rdy_tbl&os_map_tbl[i])
        {
            break;
        }
    }
    if(i==MAX_TASKS)
    {
 		for (i=0; i<=os_task_running_id; i++)
        {
            if(os_task_rdy_tbl&os_map_tbl[i])
            {
                break;
            }
        }
    }
	OS_HRT:
	os_task_running_id = i;//选择0号
    j = os_tcb[os_task_running_id].os_task_stack_top-os_stack-9;
    for(i=0; i<j; i++)   //恢复
    {
        os_hrtos_stack[i]=os_task_stack[os_task_running_id][i];
    }
    SP = os_tcb[os_task_running_id].os_task_stack_top;
}

