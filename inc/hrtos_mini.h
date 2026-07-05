#ifndef _HRTOS_MINI_H_
#define _HRTOS_MINI_H_

#define MAX_TASKS 8
#include <reg52.h>
#define u8 unsigned char
#define u16 unsigned int
typedef struct os_task_control_table
{
    unsigned char os_task_wait_tick;
    unsigned char os_task_stack_top;
} TCB;

extern void hrtos_main(void);
extern unsigned char xdata  os_task_stack[MAX_TASKS][8];//任务堆栈区

extern  bit os_hrtos_wait;
extern  unsigned char xdata os_en_cr_count;
extern unsigned char code os_map_tbl[];
extern TCB  xdata os_tcb[MAX_TASKS];
extern  unsigned char data os_task_running_id;
extern  unsigned char data os_task_rdy_tbl;

#define OS_STACK_INIT_SP 0x2F//#define OS_ST 0x2f	  //堆栈初始值


extern  unsigned char data os_stack;//堆栈初始值
extern  unsigned char data os_hrtos_stack[32];//HRTOS堆栈区data

extern void os_enter_critical();
extern void os_exit_critical();

//extern void os_init(void);
extern char os_task_create(unsigned int task_point,unsigned char task_id ,unsigned char pr,unsigned char sd);
extern u8 os_wait(u8 type, u8 obj, u16 tick);//extern void os_wait(unsigned char ticks);
//extern void os_start(void);
extern void os_task_exit(void);
//extern void exit_int(void);
extern void os_task_yield();
extern void os_idle_task(void);
#endif
