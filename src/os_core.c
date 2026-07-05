#include "os.h"
#define OS_STACK_INIT_SP 0x2F//堆栈初始值
//#define OS_ST 9	  //


unsigned char code os_map_tbl[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};


bit os_hrtos_wait;

unsigned char data os_hrtos_stack[32] _at_ 0x30;//HRTOS堆栈区data

unsigned char data os_task_running_id _at_ 0x50;//当前运行的任务号
unsigned char data os_task_rdy_tbl _at_ 0x51;//任务状态

unsigned char data os_stack _at_ 0x52;//堆栈初始值



unsigned char xdata os_en_cr_count _at_ 0x00;//临界区保护用
unsigned char xdata  os_task_stack[MAX_TASKS][8] _at_ 0x01;//任务堆栈区xdata 8*8
TCB xdata os_tcb[MAX_TASKS] _at_ 0x41;