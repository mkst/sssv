#include <ultra64.h>
#include "common.h"

#include "sched.h"


void reset_task_list(void) {
    D_8023F3E0 = 0;
}

void func_8013107C(struct018 *arg0, s32 data_ptr, s32 data_size, s8 type, s32 msg, s32 flags) {
    struct OSScTask_s *task;

    D_801D9E7C = arg0->unk4E0;
    task = &arg0->unk0[D_8023F3E0];

    switch (type) {
        case 0:
            task->list.t.data_ptr = (u64*)data_ptr;
            task->list.t.data_size = data_size;
            task->list.t.flags = 0;
            task->list.t.ucode = (u64*)gspSprite2DTextStart;
            task->list.t.ucode_data = (u64*)gspSprite2DDataStart;
            task->list.t.output_buff = NULL;
            task->list.t.output_buff_size = NULL;
            task->list.t.yield_data_ptr = NULL;
            task->list.t.yield_data_size = 0;
            break;
        case 2:
            task->list.t.data_ptr = (u64*)data_ptr;
            task->list.t.data_size = data_size;
            task->list.t.flags = OS_SC_DRAM_DLIST|OS_SC_NEEDS_RSP;
            task->list.t.ucode = (u64*)gspF3DEX_fifoTextStart;
            task->list.t.ucode_data = (u64*)gspF3DEX_fifoDataStart;
            task->list.t.output_buff = &D_800EF0D0[0];
            task->list.t.output_buff_size = &D_800EF0D0[GFX_RDP_OUTPUT_SIZE];
            task->list.t.yield_data_ptr = &D_802043E0;
            task->list.t.yield_data_size = 0xC00;
            break;
        case 3:
            // function is only called with type=3
            task->list.t.data_ptr = (u64*)data_ptr;
            task->list.t.data_size = data_size;
            task->list.t.flags = OS_SC_DRAM_DLIST|OS_SC_NEEDS_RSP;
            task->list.t.ucode = (u64*)gspF3DEX_fifoTextStart;
            task->list.t.ucode_data = (u64*)gspF3DEX_fifoDataStart;
            task->list.t.output_buff = &D_800EF0D0[0];
            task->list.t.output_buff_size = &D_800EF0D0[GFX_RDP_OUTPUT_SIZE];
            task->list.t.yield_data_ptr = &D_802043E0;
            task->list.t.yield_data_size = 0xC00;
            break;
    }

    task->list.t.type = 1;

    task->list.t.ucode_boot = (u64*)rspbootTextStart;
    task->list.t.ucode_boot_size = (u8*)rspbootTextEnd - (u8*)rspbootTextStart;

    task->list.t.ucode_size = SP_UCODE_SIZE;
    task->list.t.ucode_data_size = SP_UCODE_DATA_SIZE;

    task->list.t.dram_stack = D_800DEE20;
    task->list.t.dram_stack_size = SP_DRAM_STACK_SIZE64;

    task->next = NULL;
    task->flags = flags;  // 99 => OS_SC_SWAPBUFFER | OS_SC_LAST_TASK | OS_SC_PARALLEL_TASK | OS_SC_DRAM_DLIST | OS_SC_NEEDS_RSP | OS_SC_NEEDS_RDP
    task->msgQ = &D_8028D060;
    task->msg = msg;
    task->framebuffer = arg0->framebuffer;

    osDpSetStatus(DPC_CLR_CLOCK_CTR | DPC_CLR_CMD_CTR | DPC_CLR_PIPE_CTR | DPC_CLR_TMEM_CTR); // 0x3C0
    osSendMesg(osScGetCmdQ(&sc), task, 1);
    D_8023F3E0++;
}
