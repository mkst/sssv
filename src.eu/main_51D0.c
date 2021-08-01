#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/clear_framebuffer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_80129B10.s")

void func_80129DC0(void) {
    s8 phi_s1;

    D_801D9EE8 = 0;
    D_801D9EE9 = 0;
    D_80152ED8 = 0U;
    D_80152EDC = 0U;
    D_802042C8 = 0;

    phi_s1 = 0;

    while (TRUE) {
        if ((D_802042A4 != 2) && (D_802042A4 != 1) && (D_802042A4 != 5) && (D_802042A4 != 8)) {
            func_80133758();
            func_80132918();
            D_802042B0 = 1;
            D_8028647C = 0;

            phi_s1 = 1;
            switch (D_802042A4) {
            case 3:
                func_8012AC60();
                D_802042A4 = 5;
                break;
            case 4:
                D_802042A4 = 2;
                break;
            case 7:
                D_802042A4 = 8;
                break;
            }
        }

        if (phi_s1 == 3) {
            phi_s1 = 0;
            D_8020429C = 1;
            D_80152EB8 = 1;
            func_80132918();
            func_80132918();
            func_80132918();
            func_80132918();
            func_8012C090(D_80152EB0);
            func_80132918();
            func_80132918();
            func_80132918();
            func_80132918();
        }
        osRecvMesg(&D_8028D080, &D_802042B8, OS_MESG_BLOCK);

        switch (D_802042B8.unk0->unk0) {
        case 1:
            D_802042B2 += 1;
            if (phi_s1 != 0) {
                phi_s1 += 1;
            }
            if (D_801D9EF0 != 0) {
                D_801D9EF0 -= 1;
            }
            if ((D_80152EDC < 2) && (phi_s1 == 0) && (D_802042B2 >= D_802042B0)) {
                func_80136F84();
                if (D_802912F8 != 0) {
                    func_80137114();
                    osContStartReadData(&D_8028D0C8);
                    osRecvMesg(&D_8028D0C8, &D_8020430C, OS_MESG_BLOCK);
                    func_8013715C();
                    osContGetReadData(&D_80291108);
                    D_802912F0 = 1;
#ifdef VERSION_US
                    gControllerInput = &D_80291108;
#else
                    gControllerInput = &D_80291108[D_80151448];
#endif
                }
                D_802042B2 = 0;
                D_802042AC = &D_80162678[D_80152ED8];
                osSendMesg(&D_80291080, D_80291074, OS_MESG_BLOCK);
                osRecvMesg(&D_80291098, D_80291074, OS_MESG_BLOCK);
                D_80152EC0 = (1 - D_80152EC0);
                func_8012A770();
                end_display_lists();
                D_801D9EE8 = 0;
                func_80131090();

                func_8013109C(
                    &D_80162678[D_80152ED8],
                    D_80162678[D_80152ED8].unk4E0,
                    (D_801D9E9C - D_80162678[D_80152ED8].unk4E0) * sizeof(Gfx),
                    3,
                    &D_80162678[D_80152ED8].unk3BBC8,
                    99);

                D_80152EDC += 1;
                D_80152ED8 ^= 1;
            }

            if (++D_802042C8 >= 16) {
                D_802042C8 = 0;
            }
            if (D_80152EBC < 16) {
                func_80132918();
            }
            break;
        case 2:
            if (D_802042B0 == 1) {
                func_8012ABB4();
            } else if (D_802042B2 >= (D_802042B0 - 1)) {
                func_8012ABB4();
            }
            D_80152EC4 = 0;
            D_802042C8 = 0;
            D_801D9EE9 = 0;
            D_80152EDC -= 1;
            break;
        case 4:
            if (D_80152EBC == 0) {
                D_80152EBC = 1;
            }
            break;
        case 6:
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012A280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012A420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/end_display_lists.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012A5A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012A770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012A890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012ABB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012AC10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012AC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012ACAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012AD28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012AD50.s")
