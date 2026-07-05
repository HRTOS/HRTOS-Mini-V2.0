#include "os.h"

u8 os_wait(u8 type, u8 obj, u16 tick)//void os_wait(unsigned char ticks)
{
    os_enter_critical();
	type=type;
	obj=obj;
    os_tcb[os_task_running_id].os_task_wait_tick = tick;
    os_task_rdy_tbl &= ~os_map_tbl[os_task_running_id];//在就绪队列中清除
    os_exit_critical();
    os_task_exit();
	return 0;
}
