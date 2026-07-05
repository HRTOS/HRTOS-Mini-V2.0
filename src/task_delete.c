#include "os.h"

char os_task_delete(unsigned char id)
{
    if(id == 0)//0号任务不能删除
	{
		return -1;
	}
	if(os_task_rdy_tbl & os_map_tbl[id])//可删除
	{
		os_tcb[id].os_task_wait_tick = 0;//时间片清零，避免误触发
		os_task_rdy_tbl &= (~(1 << (id)));
	}
	return -1;
}
