#ifndef FUNCTIONS_US_H
#define FUNCTIONS_US_H

#include "functions.h"


// main_1050
void func_80125950(s32 arg0);


// mtx
void func_80125980(Mtx *, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s32 arg7, s32 arg8, s32 arg9);
void func_80125FE0(Mtx *, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6, s32 arg7, s32 arg8);

void func_8012635C(s32 arg0, s32 arg1, Mtx *arg2);
s32  func_80126388(u16 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, Mtx *arg9);
s32  func_80126FD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, Mtx *arg8);
void func_80127640(Mtx *arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s32 arg5, s32 arg6, s32 arg7, s16 arg8, s32 arg9);
s32  func_80127994(s32 arg0, s32 arg1, s32 arg2, Mtx *arg3);
void func_80127D30(Mtx*, s16);
void func_80127ED4(Mtx*, s16);
void func_80128078(Mtx *arg0, s16 arg1, s16 arg2);

// core/controller.c
u32  func_80128200(void);
void func_8012822C(s32 time);
u16  func_8012826C(void);
s32  func_801282C4(void);
s16  func_8012835C(s16 idx);
s16  func_801283AC(s16 arg0);
s8   func_8012840C(u8 idx);
s8   func_80128424(u8 idx);
s16  func_8012844C(s16 arg0);
s16  func_801284B8(s16 arg0, s16 arg1);
f32  func_801286B8(f32 arg0, f32 arg1);
s16  func_80128C10(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

// core/string.c
s16  func_80129198(s16 arg0);
u8  *func_801291A4(u8 *x);

// main_4A00
void func_80129430(Gfx **arg0);
void func_80129594(Gfx **dl, DisplayList *ddl);
void func_80129784(Gfx **dl, DisplayList *ddl);
void func_8012991C(Gfx **dl, DisplayList *ddl);

// thread6
void func_80129DC0(void);
void func_8012A400(void);
void func_8012A588(void);

// tv
void func_8012A870(void);
void func_8012AB94(void);
void func_8012AC8C(void);
void func_8012AD08(void);

// main_78F0
s16  func_8012C314(f32 arg0);
s16  func_8012C3D8(s16 *arg0);
s16  func_8012C678(s16 *arg0, u16 arg1, u16 arg2);
s16  func_8012E724(s16 *arg0, u16 arg1, u16 arg2);
s16  func_8012E78C(s16*, f32, f32, u8);
void func_8012FA78(Gfx **arg0);
void func_8012FAD4(Gfx **dl, s32 arg1);

void func_8012C214(s32, s32, s32, s32);
void func_8012D374(Gfx **arg0, s16 *arg1, u16 arg2, u16 arg3, f32 arg4, f32 arg5, s16 arg6);
void func_8012EB4C(Gfx **, s16*, u16, u16, f32, f32, u8);

// main_C2A0
void func_80130BA0(void);
void func_80130BC4(void); // junk eeprom
void func_80130C04(void); // clear eeprom

// main_C770
void func_8013107C(struct018 *arg0, s32 arg1, s32 arg2, s8 arg3, s32 arg4, s32 arg5);

// core/eeprom.c
void func_80130E44(void);

// core/audio

void func_80131070(void);
void func_80132044(s32 arg0);
struct017 *func_801320EC(void);
void func_801322EC(struct017 *arg0, struct017 **arg1, struct017 **arg2);
void func_80132394(void);
struct017 *func_80132474(void);
struct017 *func_80132568(void);
struct017 *func_80132580(s32 arg0, s16 id);
void func_801325E8(s32 arg0, s8 arg1);
s32  func_8013266C(s8 arg0); // get_seqp_state
void func_801326A8(s8 arg0, s8 arg1);
void func_801328F8(void);
void func_80132C48(s8 idx);

// core/audio2
void func_80132CC0(s32 arg0);
s32  func_80132D84(ALSndPlayer *sndp);
s16  func_8013328C(Animal *arg0, s16 arg1, s16 arg2, f32 arg3, s16 arg4, s16 arg5);
void func_80133528(u8 arg0, s16 vol);
void func_8013359C(u8 arg0);
void func_80133608(s16 arg0);
void func_8013364C(void);
void func_801337BC(s8 arg0, s32 arg1);
void func_801337DC(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8013385C(f32 arg0, f32 arg1, f32 arg2);
void func_801338A8(s16 arg0);
void func_801339F8(void);
void func_80133BE4(void);
void func_80133C50(void);
void func_80133E44(void);
void func_80133E84(void);

// main_10DC0
void func_801356C0(s32 x, s32 y, s32 x_size, s32 y_size, Gfx **arg4, u8 *arg5, f32 arg6, f32 arg7, u8 arg8);
void func_80135CD8(u32 arg0, u32 arg1, u32 arg2, u32 arg3, Gfx **arg4, u8 *arg5);
void func_801360C8(Gfx **dl, uSprite *arg1, u16 width, u16 height, u16 scale_x, u16 scale_y, u8 flip_x, u8 flip_y, u16 p_screen_x, u16 p_screen_y, u16 z);
void func_80136418(Gfx **dl, u8 color);
void func_801366BC(Gfx **dl, u8 r, u8 g, u8 b, u8 a);

// main_123E0.c
void func_80136F64(void);
void func_801370A4(void);
void func_801370F4(void);
void func_8013713C(void);
void func_80137168(void);
void func_80137204(s16 arg0);
void func_8013724C(s16 arg0);
void func_801375E8(s16 arg0);
void func_80137840(void);

void func_80139200(f32);
void func_80139330(f32);

void func_80296544_6A7BF4(void);
void func_8029726C_6A891C(struct063 arg0[73][129]);
void func_80297628_6A8CD8(struct063 arg0[73][129], DisplayList *arg1);
void func_80296C8C_6A833C(struct063**);

// overlay1_6384F0.c
void func_80294E50(void);

void func_80294E50_6384F0(void); // overlay1 entrypoint
void func_80294E70_638510(Gfx **dl, u8 alpha);
void func_80294EB8_638558(Gfx **dl);
void func_802950B8_638758(void);
void func_80295234_6388D4(void);
void func_8029548C_638B2C(void);
void func_80295494_638B34(Gfx **arg0, u16 arg1);
void func_8029597C_63901C(uSprite *arg0, u8 arg1);
void func_80295C38_6392D8(u8 arg0, u8 arg1);
void func_80295EB0_639550(s32 arg0);
void func_80295FAC_63964C(struct018*);

s16  func_80298818_6A9EC8(s16, s16);
void func_802988E8_63BF88(void);
void func_80298AC0_63C160(void);
void func_80298C70_63C310(u8 arg0);

// overlay2_6A6500.c
void func_80294E50_6A6500(void); // overlay2 entrypoint
void func_8029614C_6A77FC(void);
void func_8029619C_6A784C(void);
void func_802961D4_6A7884(void);
void func_80296310_6A79C0(void);
void func_802963D0_6A7A80(DisplayList * arg0); // struct018*

// overlay2_6A7A80
void func_80296544_6A7BF4(void);
void func_802985AC_6A9C5C(Gfx **dl);
void func_8029877C_6A9E2C(void);
s16  func_80298B70_6AA220(s16 arg0, s16 arg1);
void func_80298D44_6AA3F4(Animal *arg0);
s32  func_80298E08_6AA4B8(s16 arg0, s16 arg1);
s16  func_80298E98_6AA548(s16 arg0, s16 arg1);
s16  func_80298F78_6AA628(s16 arg0, s16 arg1);
s16  func_802990A4_6AA754(s16 arg0, s16 arg1);
void func_80299140_6AA7F0(void);
void func_80299640_6AACF0(s16, s16, s16*, s16*, s16*, s16*);

// overlay2_6AB090.c
void func_802999E0_6AB090(DisplayList *arg0);
void func_80299AA8_6AB158(DisplayList *arg0, Gfx **arg1);
void func_80299B68_6AB218(s32 arg0);
void func_80299E84_6AB534(s32 arg0);
void func_8029A32C_6AB9DC(s32 arg0);
s32  func_8029A334_6AB9E4(s32 arg0, s32 arg1, s32 arg2);
void func_8029A3B0_6ABA60(s32 arg0, s32 arg1, s32 arg2);
u16  func_8029A52C_6ABBDC(u8 arg0);
s32  func_8029A568_6ABC18(s16 arg0);
void func_8029A720_6ABDD0(void);
void func_8029ABCC_6AC27C(void);

// overlay2_6AC360
// u8 func_8029B000_6AC6B0(s16 arg0, s16 arg1, s32 arg2, Animal *arg3, Animal *arg4, s32 *arg5, s32 *arg6, Animal *arg7, s32 *arg8, s32 *arg9);
void func_8029ACB0_6AC360(void);
s32  func_8029ACB8_6AC368(s32 arg0, s32 arg1); // function does nothing but return 1, types can be changed

// overlay2_6ACF20
void func_8029B870_6ACF20(Animal *arg0, Animal *arg1);
void func_8029B9B8_6AD068(Animal *arg0, Animal *arg1);
void func_8029BA70_6AD120(Animal *arg0, Animal *arg1);
void func_8029BB94_6AD244(void);
void func_8029CEF0_6AE5A0(s32 arg0, s32 arg1, s32 arg2, u16 arg3, u8 arg4, struct059 *arg5, s8 arg6, u8 arg7, u8 arg8, u8 arg9);
void func_8029D0A8_6AE758(void);
void func_8029D89C_6AEF4C(void);
void func_8029D8D8_6AEF88(Gfx **arg0, s16 arg1);
void func_8029DB20_6AF1D0(u8 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6, s32 arg7);
void func_8029DD84_6AF434(void);
void func_8029E100_6AF7B0(void);
void func_8029E3CC_6AFA7C(void);
void func_8029EAAC_6B015C(void);
void func_8029EF20_6B05D0(struct025*, Gfx**);
void func_8029F3CC_6B0A7C(void);
void func_8029F464_6B0B14(struct025 *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, s32 arg8);
void func_8029F65C_6B0D0C(Animal *arg0, u16 arg1, u16 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, s32 arg8);
void func_8029F7D4_6B0E84(DisplayList *arg0, s32 arg1);

// overlay2_6B5380
void func_802A3CD0_6B5380(void);
void func_802A3E70_6B5520(Animal *arg0, s32 *arg1, s32 *arg2);
void func_802A3F68_6B5618(s32 *arg0, s32 *arg1);
void func_802A403C_6B56EC(Animal *arg0, s16 arg1);
void func_802A40EC_6B579C(void);
void func_802A4184_6B5834(void);
void func_802A4220_6B58D0(s32 *xVel, s32 *zVel, u16 arg2);
void func_802A4278_6B5928(u16 arg0, u16 arg1, s16 arg2);
void func_802A467C_6B5D2C(s8 arg0);
void func_802AC158_6BD808(u16 arg0, s32 *arg1, s32 *arg2);
void func_802A4390_6B5A40(void);
void func_802A43E4_6B5A94(u16 rotation, s8 arg1);
void func_802A44C4_6B5B74(u16 rotation, s8 arg1);
void func_802A459C_6B5C4C(u16 rotation, s8 arg1);
void func_802A4CB8_6B6368(void);
void func_802A4D0C_6B63BC(u16 rotation, s8 arg1);
void func_802A4D80_6B6430(u16 rotation, s8 arg1);
void func_802A4DF4_6B64A4(u16 rotation, s8 arg1);
void func_802A4E74_6B6524(void);
void func_802A4EC8_6B6578(u16 rotation, s8 arg1);
void func_802A4F68_6B6618(u16 rotation, s8 arg1);
void func_802A5008_6B66B8(u16 rotation, s8 arg1);
void func_802A50A8_6B6758(void);
void func_802A5300_6B69B0(void);
void func_802A5558_6B6C08(void);
void func_802A55AC_6B6C5C(u16 rotation, s8 arg1);
void func_802A5620_6B6CD0(u16 rotation, s8 arg1);
void func_802A5694_6B6D44(u16 rotation, s8 arg1);
void func_802A5708_6B6DB8(s16 arg0, s16 arg1, s8 arg2);
void func_802A5778_6B6E28(s16, u8);
void func_802A5C80_6B7330(void);
void func_802A5CF4_6B73A4(void);
void func_802A5D64_6B7414(void);
void func_802A5DD0_6B7480(void);
void func_802A5E1C_6B74CC(u16 rotation);
void func_802A5E64_6B7514(void);
void func_802A5EA4_6B7554(void);
void func_802A5EF8_6B75A8(u16 rotation, s8 arg1);
void func_802A5F9C_6B764C(u16 rotation, s8 arg1);
void func_802A6044_6B76F4(u16 rotation, s8 arg1);
void func_802A60C4_6B7774(void);
void func_802A6100_6B77B0(void);
void func_802A613C_6B77EC(u16 rotation);
void func_802A6198_6B7848(u16 rotation);
void func_802A61EC_6B789C(u16 rotation);
void func_802A623C_6B78EC(s16 arg0, s16 arg1);
void func_802A628C_6B793C(void);
void func_802A6390_6B7A40(void);
void func_802A63C0_6B7A70(void);
void func_802A6400_6B7AB0(void);
s32  func_802A64B0_6B7B60(void);
void func_802A78CC_6B8F7C(void);
void func_802A935C_6BAA0C(void);
void func_802AA0A0_6BB750(void);
void func_802AA1EC_6BB89C(void);
void func_802AA424_6BBAD4(void);
void func_802AA444_6BBAF4(void);
void func_802AA5C0_6BBC70(void);
void func_802AA85C_6BBF0C(void);
void func_802AAAB0_6BC160(void);
void func_802AB8EC_6BCF9C(u8 arg0, s8 arg1, s16 arg2);
void func_802ABB10_6BD1C0(u16 arg0, s32 *arg1, s32 *arg2);
void func_802AC484_6BDB34(u16 arg0, s32 *arg1, s32 *arg2);
void func_802AC5CC_6BDC7C(s32 *arg0, s32 *arg1);
void func_802AC8A0_6BDF50(s32 *arg0, s32 *arg1);
s32  func_802AC928_6BDFD8(s32 arg0, s32 arg1);
void func_802AC980_6BE030(void);
void func_802AC9FC_6BE0AC(void);
void func_802AD0FC_6BE7AC(void);
void func_802AD49C_6BEB4C(void);
void func_802AD63C_6BECEC(void);
void func_802AD87C_6BEF2C(void);
void func_802ADDD0_6BF480(void);
void func_802AE278_6BF928(void);
void func_802AE488_6BFB38(void);
void func_802AE698_6BFD48(void);
void func_802AE9C4_6C0074(void);
void func_802AEBB0_6C0260(void);
void func_802AEE18_6C04C8(void);
void func_802AF308_6C09B8(void);
void func_802AF7E4_6C0E94(void);
void func_802AF9FC_6C10AC(void);
void func_802B066C_6C1D1C(void);
void func_802B0B00_6C21B0(s16 arg0, s16 arg1);
void func_802B0D4C_6C23FC(s16 arg0, s16 arg1);
void func_802B0F4C_6C25FC(s16 arg0, s16 arg1);
void func_802B10B0_6C2760(s16 rotation, s16 arg1);
void func_802B1210_6C28C0(s16 rotation, s16 arg1);
void func_802B1374_6C2A24(s16, s16, s16);
void func_802B1654_6C2D04(s16, s16, s16);
void func_802B1918_6C2FC8(s16, s16, s16);
void func_802B1B98_6C3248(s16 rotation, s16 arg1);
void func_802B1D00_6C33B0(s16 rotation, s16 arg1);
void func_802B1E28_6C34D8(s16 arg0, s16 arg1, s16 arg2);
s16  func_802B25B4_6C3C64(u8);
s16  get_distance_from_ground(void);
void func_802B2834_6C3EE4(void);
void func_802B2964_6C4014(void);
s32  func_802B2AF0_6C41A0(s32 arg0, s32 arg1);
s32  func_802B2C20_6C42D0(s16 xPos, s16 zPos);
void func_802B2EA8_6C4558(void);
void func_802B3230_6C48E0(void);
void func_802B33D0_6C4A80(Animal *a);
void func_802B3400_6C4AB0(Animal *a);
void func_802B342C_6C4ADC(void);
void func_802B3474_6C4B24(void);
void func_802B34B8_6C4B68(Animal *a);
void func_802B34DC_6C4B8C(void);
void func_802B3518_6C4BC8(void);
void func_802B3530_6C4BE0(void);
void func_802B3540_6C4BF0(void);
void func_802B356C_6C4C1C(Animal *arg0, s16 arg1, s16 arg2, u8 arg3);
void func_802B38FC_6C4FAC(Animal *arg0, s16 arg1, s16 arg2, u8 arg3);
void func_802B3B48_6C51F8(Animal *arg0, Animal *arg1, s16 *arg2);
s16  func_802B3C9C_6C534C(s16 arg0, Animal *arg1);
s16  func_802B3D68_6C5418(void);

// overlay2_6C5570
void func_802B2FF4_6C46A4(void);
void func_802B315C_6C480C(void);
void func_802B3EC0_6C5570(Gfx **arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void func_802B3FAC_6C565C(void);
void func_802B4148_6C57F8(Gfx **arg0);

// collision.c
void func_802B4D20_6C63D0(void);

s32  func_802B5E48_6C74F8(Animal *arg0, Animal *arg1, s32 (**arg2)(Animal *arg0, Animal *arg1, struct043**, struct043**, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z3), u8 *arg3);

u8   func_802B750C_6C8BBC(Animal *arg0, Animal *arg1, struct043 **arg2, struct043 **arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9);
s32  func_802B75B4_6C8C64(Animal *arg0, Animal *arg1, struct043 ** arg2, struct043 ** arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9);
u8   func_802B6088_6C7738(Animal *arg0, Animal *arg1, struct043 **arg2, struct043 **arg3, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2);
s32  func_802B6948_6C7FF8(Animal *arg0, Animal *arg1, struct043 **arg2, struct043 **arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9);
s32  func_802B6B5C_6C820C(Animal *arg0, Animal *arg1, struct043 **arg2, struct043 **arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9);
s32  func_802B6F6C_6C861C(Animal *arg0, Animal *arg1, struct043 **arg2, struct043 **arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9);

s32  func_802B75CC_6C8C7C(Animal *arg0, Animal *arg1, s32 x, s32 y, s32 z, u8*, u16);
u8   func_802B7BC8_6C9278(Animal *arg0, Animal *arg1);
void func_802B8304_6C99B4(Animal *arg0, Animal *arg1);

// overlay2_6C9DD0
void func_802B8720_6C9DD0(void);
void func_802B8790_6C9E40(void);
void func_802B8810_6C9EC0(void);
void func_802B8890_6C9F40(void);
void func_802B8918_6C9FC8(void);
void func_802B8978_6CA028(void);
void func_802B89D8_6CA088(void);
void func_802B8A48_6CA0F8(void);
void func_802B8AD8_6CA188(void);
void func_802B8B1C_6CA1CC(void);
u16  func_802B8B74_6CA224(void);
s32  func_802B8C50_6CA300(s16 arg0, s16 arg1);
s32  func_802B901C_6CA6CC(u8 arg0, s16 *arg1, s16 *arg2);
void func_802B90A0_6CA750(u8 arg0, s32 *arg1, s32 *arg2);
void func_802B9130_6CA7E0(struct061 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_802B964C_6CACFC(void);
void func_802B96D0_6CAD80(s16 *arg0, s16 arg1, s16 arg2, s32 arg3);
void func_802B975C_6CAE0C(s16 *arg0, s16 arg1, s16 arg2);
void func_802B9A5C_6CB10C(s16 *arg0, s16 arg1);
void func_802B9D20_6CB3D0(s16 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_802BAA38_6CC0E8(u16 arg0, u16 arg1);
void func_802BAC24_6CC2D4(u16 arg0, u16 arg1);
void func_802BAD60_6CC410(u16 arg0, u16 arg1);
void func_802BAE24_6CC4D4(s16 *arg0, s16 *arg1, s16 arg2);
void func_802BB70C_6CCDBC(s16 arg0, s16 arg1);
void func_802BB1F0_6CC8A0(u16 arg0, u16 arg1);

// overlay2_6CCEF0
void func_802BB840_6CCEF0(u16 arg0);
void func_802BB870_6CCF20(u16 arg0);
void func_802BB938_6CCFE8(u16 arg0);
void func_802BBA10_6CD0C0(u16 arg0);
void func_802BBC90_6CD340(u16 arg0);
void func_802BBFA0_6CD650(u16 arg0);
void func_802BC1F4_6CD8A4(u16 arg0); // tbd
void func_802BC350_6CDA00(s16 *arg0, s16 *arg1, u16 arg2, u16 arg3, s16 arg4);
void func_802BC628_6CDCD8(s16 *arg0, s16 *arg1, u16 arg2, u16 arg3, s16 arg4);
void func_802BC900_6CDFB0(struct077 *arg0, u16 arg1, u16 arg2, s16 *arg3, s16 *arg4, s16 *arg5);
void func_802BCC50_6CE300(s16 arg0, u16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 *arg8, s16 *arg9, s16 *argA);
void func_802BCDA0_6CE450(struct103 *arg0, s16 *arg1, s16 *arg2, s16 *arg3);
void func_802BCF38_6CE5E8(u16, u16, struct061*);
void func_802BD21C_6CE8CC(u16 arg0, struct061 *arg1);
void func_802BD358_6CEA08(s16 *arg0);
void func_802BD40C_6CEABC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 *arg8, s16 *arg9, s16 *argA, s16 argB, s16 argC, s16 argD, s16 argE, s16 argF, s16 arg10, s16 arg11, s16 arg12, s16 *arg13, s16 *arg14, s16 *arg15, struct061 *arg16, s16 arg17); // tbd
void func_802BE1A0_6CF850(struct103 *arg0, s16 arg1, u16 arg2, u8 arg3, u16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, struct077 *arg9, struct077 *argA, struct077 * argB, s8 argC);
void func_802BEAB0_6D0160(struct103 *arg0, s16 arg1, u16 arg2, u16 arg3, u16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, struct077 *arg9, struct077 *argA, struct077 *argB, s8 argC);
void func_802BF3C0_6D0A70(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s32 arg6, struct077 *arg7, struct077 *arg8, s16 arg9, s16 argA, s16 argB, s16 argC, s16 argD, s16 argE, s32 argF, s32 arg10, s32 arg11, struct061 *arg12);
void func_802BFF84_6D1634(struct103 *arg0, s16 arg1, u16 arg2, u16 arg3, u16 arg4, s16 arg5, s16 arg6, struct077 *arg7, struct077 *arg8, struct077 *arg9, s8 argA);
void func_802C0364_6D1A14(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s32 arg6, s32 arg7, s32 arg8, s16 arg9, s16 argA, s16 argB, s16 argC, s16 argD, s16 argE, struct077 *argF, struct077 *arg10, struct077 *arg11, struct061 *arg12);
void func_802C13E4_6D2A94(struct103 *arg0, s16 arg1, u16 arg2, u16 arg3, u16 arg4, s16 arg5, s16 arg6, struct077 *arg7, struct077 *arg8, struct077 *arg9, s8 argA);
void func_802C1830_6D2EE0(u16 arg0, struct061 *arg1);
void func_802C18FC_6D2FAC(u16 arg0, u16 arg1, struct061 *arg2);
void func_802C19CC_6D307C(struct103 *arg0, s16 arg1, u16 arg2, u16 arg3, s32 arg4, u16 arg5);
void func_802C1A44_6D30F4(u16 arg0, u16 arg1, s32 arg2);
void func_802C23F8_6D3AA8(s16 arg0);
void func_802C287C_6D3F2C(struct103 *arg0, u16 arg1, u16 arg2, u16 arg3, s16 arg4, s16 arg5);
void func_802C2D98_6D4448(s16 arg0, s16 arg1);
void func_802C3188_6D4838(struct103 *arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4, s16 arg5, s16 arg6, s32 arg7);
void func_802C353C_6D4BEC(s16 arg0, s16 arg1, s16 arg2, struct077 *arg3, struct077 *arg4, struct077 *arg5, struct061 *arg6);
void func_802C3C64_6D5314(s16 arg0, s16 arg1, s16 arg2);
void func_802C3F58_6D5608(struct103*, u16, u16, u16, s16, s16, s16);
void func_802C4448_6D5AF8(s16 arg0);
void func_802C44E8_6D5B98(s16 arg0, s16 arg1, s16 arg2, s16 arg3); // tbd

// overlay2_6D6120
void func_802C4A70_6D6120(s16 arg0, s16 arg1, u8 arg2);
void func_802C56D0_6D6D80(s16);
void func_802C5824_6D6ED4(s16 arg0, s16 arg1, s16 arg2);
void func_802C58E4_6D6F94(s16 arg0, s16 arg1);
void func_802C5EF4_6D75A4(s16 arg0, s16 arg1);
void func_802C5F34_6D75E4(s16 arg0, s16 arg1, u8 arg2);
void func_802C6468_6D7B18(s16 arg0, s16 arg1, s16 arg2); // tbd
void func_802C64E0_6D7B90(s16 arg0);
void func_802C71BC_6D886C(s16*, s16*, s16*, s16);
void func_802C652C_6D7BDC(s16 arg0, s16 arg1);
void func_802C6C00_6D82B0(s16 arg0, s16 arg1);
void func_802C7310_6D89C0(void);
void func_802C75A4_6D8C54(s16 arg0);
void func_802C7600_6D8CB0(s16 arg0, s16 arg1);
void func_802C78B0_6D8F60(u16 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, Gfx *arg9);
void func_802C79E0_6D9090(struct061 *arg0, s16 arg1);
// void func_802C7A7C_6D912C(struct061 *arg0, s16 arg1); // not ok
void func_802C7B18_6D91C8(struct061 *arg0, s16 arg1);

void func_802C7BB4_6D9264(u16 arg0);
void func_802C7C80_6D9330(void);

// overlay2_6D9330
void func_802C83CC_6D9A7C(Animal *arg0);

// overlay2_6D9AF0
void func_802C85EC_6D9C9C(void);
void func_802C87E0_6D9E90(void);
void func_802C8878_6D9F28(void);
void func_802C8FC0_6DA670(OSContPad *cont);
s32  func_802C9340_6DA9F0(void);
// struct071 *func_802C93E8_6DAA98(u16 arg0); // helps load_level_data_sections?
void func_802C941C_6DAACC(void);
struct071 *func_802C9488_6DAB38(void);
void func_802C9500_6DABB0(struct071 *obj);
struct071 *func_802C9564_6DAC14(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6, s16 arg7, s16 arg8, u16 arg9);
void func_802C9834_6DAEE4(void);
void func_802C985C_6DAF0C(void);
void func_802C9884_6DAF34(void);
void func_802C9900_6DAFB0(struct071 *arg0, struct071 *arg1, u8 arg2);
void func_802C9918_6DAFC8(Animal *arg0, s16 arg1, s16 arg2);
void func_802C9BA4_6DB254(struct071 *arg0);

// overlay2_6DB610
void func_802C9F60_6DB610(Animal *arg0);
void func_802CA8D4_6DBF84(Animal *arg0);
void func_802CAACC_6DC17C(Animal *arg0, s16 arg1);
void func_802CAB20_6DC1D0(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7);

// overlay2_6DCA10
void func_802CB360_6DCA10(void);
void func_802CB394_6DCA44(s32);
void func_802D5AD8_6E7188(s16 arg0, s16 arg1);
s32  func_802D5B88_6E7238(s32 arg0, s32 arg1, s32 arg2, s16 id, s16 arg4, u16 arg5, u16 arg6, u16 arg7);
void func_802D6738_6E7DE8(void);
void func_802D760C_6E8CBC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
s16  func_802D7434_6E8AE4(s16 arg0, s16 arg1);
void func_802D7AD4_6E9184(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_802D7BE0_6E9290(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, u16 arg6);
void func_802D9C64_6EB314(s16 x, s16 z, s16 y, s16 arg3, u16 color);
void func_802D9FC4_6EB674(s16 x, s16 z, s16 y, s16 arg3);

// collist2
void func_802DA7F0_6EBEA0(void);
void func_802DA90C_6EBFBC(Animal *arg0);
void func_802DAD18_6EC3C8(Animal *arg0);
void func_802DADA0_6EC450(Animal *arg0);
void func_802DAE5C_6EC50C(struct071 *arg0);
void func_802DAF5C_6EC60C(void);
void func_802DAFAC_6EC65C(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd);

// overlay2_6EC720
void func_802DB070_6EC720(u16 arg0, u16 arg1, s16 arg2, s16 arg3, u16 arg4, u16 arg5);
void func_802DB494_6ECB44(u16 arg0, u16 arg1, s16 arg2, s16 arg3, u16 arg4);
void func_802DB5C0_6ECC70(s16 arg0, s16 arg1, s16 arg2, u16 arg3);
void func_802DB670_6ECD20(u8 *arg0, u8 *arg1, s16 *arg2, s16 *arg3);
void func_802DB7C4_6ECE74(u8 *arg0, u8 *arg1, s16 *arg2, s16 *arg3);
void func_802DB8DC_6ECF8C(void);
void func_802DB940_6ECFF0(s16 *arg0, s16 arg1, u16 arg2);
void func_802DB9E8_6ED098(s16 *arg0, s16 arg1, u16 arg2);
void func_802DBA58_6ED108(u8 arg0, Animal *animal);
void func_802DBB64_6ED214(u8 *arg0, u16 *arg1, u16 arg2);

// overlay2_6ED230
void func_802DBB80_6ED230(u16 arg0);
void func_802DBCDC_6ED38C(u16 arg0);
void func_802DBED8_6ED588(u16 arg0);
void func_802DC0D4_6ED784(u16 arg0);
void func_802DC2AC_6ED95C(u16 arg0);
void func_802DC3F4_6EDAA4(u16 arg0, s16 *arg1, s16 *arg2);
void func_802DC6A4_6EDD54(u16 arg0);
void func_802DC854_6EDF04(s16 arg0, u16 arg1);
void func_802DC968_6EE018(u16 arg0, s16 arg1);
void func_802DCA28_6EE0D8(u16 arg0);
void func_802DCAD4_6EE184(u16 arg0);
void func_802DCB90_6EE240(u16 arg0);
void func_802DCCAC_6EE35C(u16 arg0);
void func_802DCD70_6EE420(u16 arg0, u8 arg1);
void func_802DD004_6EE6B4(u16 arg0);
void func_802DD040_6EE6F0(s32 arg0);
s16  func_802DD090_6EE740(s16 numSegments, s32 length, u8 arg2, s8 arg3, s8 arg4, s32 arg5, s32 arg6, s32 arg7, u8 arg8, u8 arg9, Animal *argA, Animal *argB, s16 argC, s16 argD, s16 argE, s16 argF, s16 arg10, s16 arg11);
void func_802DE770_6EFE20(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_802DE7F4_6EFEA4(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_802DE890_6EFF40(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void func_802DE914_6EFFC4(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4);
void func_802DE950_6F0000(void);
void func_802E072C_6F1DDC(s8);
void func_802E497C_6F602C(s16 arg0, s32 *arg1, s32 *arg2, s32 *arg3);
void func_802E4A78_6F6128(s16 arg0);
void func_802E4AB8_6F6168(void);
s32  func_802E4B0C_6F61BC(s16 arg0);
void func_802E4EB4_6F6564(s16 arg0);
void func_802E4F20_6F65D0(u8 *img);
void func_802DD244_6EE8F4(s16, struct118*);
void func_802DD548_6EEBF8(s16 arg0, struct118 *arg1, s16 arg2, s16 arg3);
void func_802DD994_6EF044(s16 arg0, struct118 *arg1, s16 arg2, s16 arg3, s16 arg4);
// overlay2_6EFE20
s32 func_802E414C_6F57FC(s16 arg0, s16 arg1, s16 arg2, s16 *arg3, s8 *arg4);

// sssv/animals/fox (overlay2_6F66B0)
void func_802E5000_6F66B0(void);
void func_802E620C_6F78BC(void);
void func_802E7394_6F8A44(void);
void func_802E84E0_6F9B90(void);
void func_802E8500_6F9BB0(void);
void func_802E864C_6F9CFC(void);
void func_802E86C8_6F9D78(void);
void func_802E8760_6F9E10(void);
void func_802E88C0_6F9F70(s16 arg0);

// overlay2_6FA0A0
s32 func_802E89F0_6FA0A0(s32 x, s32 y, s32 z, s32 arg3, u8 arg4, s16 arg5, s16 arg6, s16 arg7, s8 arg8, u8 arg9);
s32 func_802E8BBC_6FA26C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s16 arg5, s16 arg6, s16 arg7, s8 arg8, u8 arg9);
s32 func_802E8CF4_6FA3A4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s16 arg5, s16 arg6, s16 arg7, s8 arg8, u8 arg9);
s32 func_802E9B90_6FB240(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
s32 func_802EA004_6FB6B4(s32 arg0, s32 arg1, s32 arg2, s8 arg3);

// src/sssv/aidata
s16 func_802EA3E0_6FBA90(u16 X, u16 Y);

// sssv/animals/dog (overlay2_6FBEA0)
void func_802EA7F0_6FBEA0(void);
void func_802EBB34_6FD1E4(void);
void func_802ED108_6FE7B8(void);
void func_802EE89C_6FFF4C(void);
void func_802EE9EC_70009C(void);
void func_802EEA18_7000C8(void);
void func_802EEA54_700104(void);
void func_802EEA7C_70012C(void);
void func_802EEC44_7002F4(void);

// sssv/animals/hippo (overlay2_700770)
void func_802EF0C0_700770(void);
void func_802F036C_701A1C(void);
void func_802F0374_701A24(void);
void func_802F03B8_701A68(void);

// overlay2_701E80
s16  func_802F1388_702A38(void);
void func_802F13B8_702A68(void);

// sssv/animals/lion (overlay2_702DE0)
void func_802F1730_702DE0(void);
void func_802F2A2C_7040DC(void);

// overlay2_7041D0
void clear_used_lights(void);
void add_light_at_location(s16, s16, s16, s16, s16 r, s16 g, s16 b);
void func_802F2DF8_7044A8(void);
void func_802F2EEC_70459C(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6);
void func_802F301C_7046CC(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6, u16 arg7);
void func_802F30A4_704754(void);

// demo
void get_controller_input(void);

// overlay2_707310
void func_802F5C60_707310(Animal *arg0);
void func_802F5F44_7075F4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, struct077 *arg5);
void func_802F603C_7076EC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u16 arg5, struct077 *arg6); // tbd
struct071 *func_802F62E4_707994(s16 x, s16 z, s16 y, u8 id, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s32 scale);
s16  func_802F63F8_707AA8(s16 arg0, s16 arg1, s16 arg2);
s16  func_802F649C_707B4C(s16 arg0, s16 arg1, s16 arg2);
void func_802F657C_707C2C(Animal *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_802F65BC_707C6C(Animal *arg0);
void func_802F6750_707E00(Animal *arg0);
void func_802F68A0_707F50(Animal *arg0);
s16  func_802F8160_709810(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, f32 arg8);
void func_802F6DEC_70849C(Animal *arg0, s16 arg1);
void func_802F7054_708704(s32 arg0);
void func_802F705C_70870C(Animal *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, u16 arg7); // tbd
s32  func_802F804C_7096FC(u8 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
struct071 *func_802F8994_70A044(struct071 *arg0);
s32  func_802F8918_709FC8(Animal *arg0, Animal *arg1);
void func_802F8DCC_70A47C(struct071 *arg0);
void func_802F9084_70A734(s32 arg0);
void func_802F908C_70A73C(struct071 *arg0);
void func_802F90A8_70A758(struct071 *arg0);
void func_802F9104_70A7B4(struct071 *arg0);
s32  func_802F9178_70A828(struct071 *arg0);
void func_802F951C_70ABCC(Animal *arg0);
void func_802F9624_70ACD4(Animal *arg0);
void func_802F9880_70AF30(Animal *arg0);
void func_802F9A08_70B0B8(Animal *arg0);
void func_802F9C50_70B300(struct071 *arg0);
void func_802F9E10_70B4C0(Animal *arg0, u8 arg1, u8 arg2, s8 arg3, u8 arg4, u8 arg5);
void func_802F9EB8_70B568(s32 *arg0, s32 *arg1, s32 *arg2, WaypointData *arg3, s16 arg4, u8 arg5);
void func_802FA4F8_70BBA8(Animal *arg0);
void func_802FA6D8_70BD88(void);
void func_802FA730_70BDE0(Animal *arg0);
void func_802FB270_70C920(Animal *arg0);
void func_802FB49C_70CB4C(struct071 *arg0);
void func_802FB4C0_70CB70(Animal *arg0);
void func_802FB680_70CD30(Animal *arg0);
void func_802FB85C_70CF0C(Animal *arg0);
void func_802FBA40_70D0F0(Animal *arg0);
void func_802FBBF8_70D2A8(Animal *arg0);
void func_802FBDA8_70D458(Animal *arg0);
void func_802FBF58_70D608(Animal *arg0);
void func_802FC108_70D7B8(Animal *arg0);
void func_802FC2B8_70D968(s16 x, s16 z, s16 y);
void func_802FC438_70DAE8(s16 x, s16 z, s16 y);
void func_802FC5C0_70DC70(Animal *arg0);
void func_802FC6E4_70DD94(Animal *arg0);
void func_802FC808_70DEB8(Animal *arg0);
void func_802FC8F4_70DFA4(Animal *arg0);
void func_802FC970_70E020(Animal *arg0);
void func_802FC990_70E040(Animal *arg0);
void func_802FCA08_70E0B8(Animal *arg0, s16 arg1);
void func_802FD190_70E840(u8 arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4);
void func_802FD26C_70E91C(u8 arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4);
s32  func_802FD348_70E9F8(Animal *arg0, u16 arg1);
s32  func_802FD3B8_70EA68(Animal *arg0);
s32  func_802FD40C_70EABC(Animal *arg0, Animal *arg1);
s32  func_802FD468_70EB18(Animal *arg0);
s32  func_802FD4D0_70EB80(Animal *arg0);
s32  func_802FD538_70EBE8(Animal *arg0); // tbd
s16  func_802FD5DC_70EC8C(Animal *arg0);
void func_802FD674_70ED24(Animal *arg0, Animal *arg1);
void func_802FD8CC_70EF7C(void);
void func_802FD94C_70EFFC(s16 min, s16 max, u8 r, u8 g, u8 b, s16 arg5);
void func_802FD9C4_70F074(s16 min, s16 max, u8 r, u8 g, u8 b, s16 arg5, s16 arg6);
void func_802FDA44_70F0F4(void);
void func_802FE4C4_70FB74(void);
void func_802FE560_70FC10(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, s16 arg6, u8 arg7, s16 arg8);
void func_802FE5E8_70FC98(void);
void func_802FED68_710418(struct071 *arg0, Animal *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s16 argA, f32 argB, u8 argC);
void func_802FF140_7107F0(void);
void func_802FF184_710834(Animal *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9);
void func_802FF25C_71090C(void);
void func_802FF540_710BF0(struct071 *arg0);
void func_802FF7D4_710E84(struct071 *arg0);
void func_802FF828_710ED8(struct071 *arg0);
void func_802FFA20_7110D0(struct071 *arg0);
void func_802FFC34_7112E4(struct071 *arg0);
void func_802FFD50_711400(struct071 *arg0);
void func_802FFE94_711544(struct071 *arg0);
void func_802FFED0_711580(struct071 *arg0);
void func_802FFEFC_7115AC(struct071 *arg0);
void func_802FFF50_711600(struct071 *arg0);

// overlay2_7117E0
void func_80300130_7117E0(s16 *arg0, s16 *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7);

// sssv/animals/rabbit (overlay2_7118C0)
void func_80300210_7118C0(void);
void func_80301248_7128F8(void);
void func_80302018_7136C8(void);
void func_80302080_713730(void);
void func_803021A8_713858(void);

// sssv/animals/frog
void func_80302200_7138B0(void);
void func_80302D5C_71440C(void); // also frog_croak

// overlay2_714500
void func_80302E50_714500(s16, s16, s16); // tbd
void func_8030322C_7148DC(s16 arg0, s16 arg1); // tbd
void func_803032DC_71498C(s16 arg0, s16 arg1, s16 arg2);
void func_803033D4_714A84(s16 arg0, s16 arg1, s16 arg2);

// overlay2_714B80
void func_803034D0_714B80(Animal *arg0, u16 arg1, s16 arg2, u16 arg3); // tbd
void func_80303820_714ED0(Animal *arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4);
void func_80303990_715040(Animal *arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, u16 arg6);
void func_80303B18_7151C8(Animal *arg0, u16 arg1, s16 arg2, u16 arg3, u16 arg4);
void func_80303C44_7152F4(Animal *arg0, u16 arg1, s16 arg2, s16 arg3);
void func_80303D00_7153B0(Animal *arg0, u16 arg1, u16 arg2);
void func_80303D50_715400(Animal *arg0, u16 arg1);
void func_80303D68_715418(Animal *arg0, u16 arg1, DisplayList *arg2);
void func_80303F90_715640(Animal *arg0, DisplayList *arg1);
s32  func_8030400C_7156BC(Animal*, s16, s16, s32*, s32*);

// overlay2_715820
void func_80304170_715820(void);
void func_80304194_715844(void);
void func_803041FC_7158AC(void);

// overlay2_716530
s32  func_80304E80_716530(struct039 *arg0);
void func_80304EC4_716574(struct039 *arg0, struct039 *arg1);
void func_80304F70_716620(struct039 *arg0, struct039 *arg1, struct039 *arg2);
s16  func_80304F94_716644(struct039 *arg0, struct039 *arg1);
s16  func_80305084_716734(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
s16  func_80305194_716844(s16 arg0, s16 arg1);
s16  func_803051F0_7168A0(s16 arg0, s16 arg1);

// overlay2_716900

void func_80305250_716900(struct079_inner *arg0, Animal *animal, s16 distance, u8 arg3);
s32  func_80305DA4_717454(s16 arg0, s16 arg1, s32 arg2, s16 arg3, u8 arg4);
s32  func_80305A70_717120(s16 arg0, s16 arg1, s32 arg2, s16 arg3, u8 arg4);
s16  func_803064BC_717B6C(s16 arg0, s16 arg1, s32 arg2, s16 arg3, s16 arg4);
s32  func_803065F0_717CA0(s16 arg0, s16 arg1, s32 arg2, s16 arg3, u16 arg4);
s32  func_80309798_71AE48(Animal *arg0);
s32  func_80309868_71AF18(void);
s32  func_803098F0_71AFA0(void);
s32  func_803099BC_71B06C(void);
s32  func_80309ACC_71B17C(void);
s32  func_80309B40_71B1F0(void);
void func_80309C8C_71B33C(void);
s32  func_80309DC4_71B474(void);
void func_80309E4C_71B4FC(Animal *arg0);
void func_80309EDC_71B58C(Animal *arg0);
void func_80309F38_71B5E8(void);
void func_8030A8EC_71BF9C(void);
s32  func_8030AA08_71C0B8(Animal *arg0, Animal *arg1);
s32  func_8030AA90_71C140(struct071 *arg0);
s32  func_8030B494_71CB44(void);
s32  func_8030BC50_71D300(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *arg4);
s32  func_8030BD50_71D400(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *arg4);
s16  func_8030BE20_71D4D0(s16 arg0, s16 arg1, s16 arg2);
void func_8030DD34_71F3E4(void);
void func_8030E208_71F8B8(void);
void func_8030E69C_71FD4C(void);
s16  func_8030E8AC_71FF5C(struct071 *arg0);
s32  func_8030EA98_720148(void);
s32  func_8030EB88_720238(s16 arg0, s16 arg1);
s32  func_8030EBF0_7202A0(void);
s32  func_80310030_7216E0(void);
s16  func_803102BC_72196C(void);
s32  func_80310E10_7224C0(s16 arg0, s16 arg1);
s32  func_80310EE4_722594(s16 x, s16 z, u8 arg2);
s32  func_80310F58_722608(s16, s16);
s32  func_8031124C_7228FC(s16, s16);
void func_80311554_722C04(s16, s16, s32*, s32*);
void func_80311A2C_7230DC(s16 xPos, s16 zPos, s16 *xVel, s16 *zVel, u8 arg4);
void func_80311AA8_723158(s16 arg0, s16 arg1, s16 *arg2, s16 *arg3);
void func_80311BF8_7232A8(s16 arg0, s16 arg1, s16 *arg2, s16 *arg3);
s16  func_80311D48_7233F8(Animal *arg0);
s32  func_80312054_723704(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s8 arg4, u8 arg5);
s32  func_803123A4_723A54(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s8 arg4, u8 arg5);
s32  func_803126F4_723DA4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s8 arg4, u8 arg5);
s32  func_80312A44_7240F4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s8 arg4, u8 arg5);
void func_80312D94_724444(void);
void func_80313064_724714(void);
void func_80313334_7249E4(void);
s32  func_80313448_724AF8(Animal *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_803135FC_724CAC(Animal *arg0);
void func_803136B0_724D60(Animal *arg0);
u8   func_803136FC_724DAC(s16 x, s16 z, s16 y);

// sssv/animals/parrot
void func_80313790_724E40(void);
void func_803144F8_725BA8(void);
void func_80314590_725C40(void);

// overlay2_725D10
void func_80314660_725D10(void);
void func_80314788_725E38(void);
s32  func_80314F0C_7265BC(Animal*, s32);
s32  func_803152A4_726954(s32 arg0, u8 arg1, s32 arg2);
void copy_command_struct(struct112 *arg0, struct112 *arg1);
void load_commands_into_object(Animal *arg0, struct112 arg1[], u8 arg2);
Animal *func_8031540C_726ABC(s16, u8);
// s32  func_80315658_726D08(s16 arg0, s32 arg1(Animal *, s16), s16 arg2); // tbd
s32  func_80315870_726F20(Animal *arg0, s16 arg1);
s32  func_80315880_726F30(s16 arg0);
s32  func_803158B4_726F64(Animal *arg0, s16 arg1);
s32  func_803158E4_726F94(s16 arg0, s16 arg1);
s32  func_80315924_726FD4(Animal *arg0, s16 arg1);
s32  func_80315950_727000(s16 arg0);
s32  func_80315984_727034(Animal *arg0, s16 arg1);
s32  func_803159B0_727060(s16 arg0);
// u8   func_803159E4_727094(Animal *arg0, void *arg1);
s32  func_80316408_727AB8(Animal *arg0);
void func_803190FC_72A7AC(Animal *arg0);
void func_803191B0_72A860(Animal *arg0);

// overlay2_72A930
s32  func_80319280_72A930(Animal *arg0, Vertex *arg1, Vertex *arg2, Animal *arg3, Vertex *arg4, Vertex *arg5, f32 arg6, f32 arg7);
void func_8031977C_72AE2C(s32 arg0, f32 *arg1, s32 arg2, f32 *arg3, f32 arg4, s16 arg5, s16 arg6);
void func_803198B0_72AF60(void);

// overlay2_72B100
void func_80319A50_72B100(void);
void func_80319AA0_72B150(u8 *arg0, u8 arg1);
void func_80319AC4_72B174(u8 *arg0, u8 arg1);
void func_80319C38_72B2E8(u8 arg0, u8 arg1, u8 arg2, u8 *arg3, u8 *arg4, u8 arg5);
u8   func_80319E1C_72B4CC(u8 x, u8 z, u8 y, u8 arg3, u8 arg4);
u16  func_80319F58_72B608(struct105 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 *arg5, u8 *arg6);

// overlay2_72B800
void func_8031A150_72B800(s16 arg0, s16 *leftEye, s16 *rightEye);
void func_8031A278_72B928(s16 *arg0, s16 *arg1, s16 *arg2);
void func_8031A370_72BA20(void);
void func_8031A4E0_72BB90(void);
void func_8031AA0C_72C0BC(struct058 *arg0); // more like *Animal
void func_8031AE7C_72C52C(Animal *arg0);

// overlay2_72C680
void func_8031B174_72C824(u8 arg0, u8 arg1);
void func_8031C304_72D9B4(void);
void func_8031C32C_72D9DC(void);
void func_8031C374_72DA24(void);
void func_8031C3C0_72DA70(u8 *arg0, s16 arg1);

// sssv/animals/mouse (overlay2_72DE50)
void func_8031C7A0_72DE50(void);
void func_8031D624_72ECD4(void);
void func_8031E6A0_72FD50(void);
void func_8031F858_730F08(void); // load_helimouse
void func_8031F87C_730F2C(void); // load_mouse2
void func_8031F89C_730F4C(void); // load_mouse
void func_8031F8BC_730F6C(void);
void func_8031FA84_731134(void); // load_racing_mouse_attack
void func_8031FAD8_731188(void);
void func_8031FB30_7311E0(s16 arg0);
void func_8031FB78_731228(s16 arg0);

// overlay2_7312E0
void func_80320C84_732334(s16 arg0, s16 arg1);
void func_80320DF8_7324A8(s16 arg0, s16 arg1);
void func_80321224_7328D4(void *arg0, u16 arg1, u16 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6);

// overlay2_732A60
void func_80321920_732FD0(Animal *arg0, s16 arg1, s16 arg2);
Animal *func_803213B0_732A60(void);
Animal *func_803215DC_732C8C(s16 arg0, s16 arg1);
Animal *func_803218D8_732F88(Animal *arg0);
void func_80321B70_733220(s16 arg0, s16 arg1, s16 arg2);
void func_80321D74_733424(s16 arg0, s16 arg1);
// void func_80321E60_733510(s32, s32, s32, s32, s32, s32, s32, s32);  // fire/drop cannonball?
void func_80321E60_733510(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7);
void func_80322064_733714(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8);
s16  func_803224C4_733B74(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7);
u8   func_80322A58_734108(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 damage, Animal **arg5, Animal *arg6, u8 arg7);
s32 func_80322D68_734418(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 *arg6, s16 *arg7, s16 *arg8, s16 arg9, s16 argA, u8 argB, u8 argC); // tbd
Animal *func_80323040_7346F0(void);

s32  func_803233A0_734A50(s16, s16, s16, s16, s16, s16);

// sssv/animals/bear (overlay2_734D30)
void func_80323680_734D30(void);
void func_803250A8_736758(void);
void func_80326260_737910(void);
void func_803277B4_738E64(void);
void func_8032786C_738F1C(void);
void func_803278D4_738F84(void);
void func_80327908_738FB8(void);
void func_803279BC_73906C(void);
void func_80327B84_739234(s32 arg0, s32 arg1, s32 arg2);
void func_80327B94_739244(s16 arg0);

// overlay2_739290.c
void func_80327BE0_739290(void);
void func_80327DA0_739450(void);
void func_80327DA8_739458(void);
void func_80328258_739908(s16 arg0);
void func_803283DC_739A8C(void);
Camera* func_803284C4_739B74(void);
void func_80328520_739BD0(void);
void func_80328918_739FC8(void);
s32  func_80329BAC_73B25C(s16 arg0, s16 arg1);
void func_80329F44_73B5F4(void);
s16  func_8032A164_73B814(s16, s16);
void func_8032A710_73BDC0(void);
void func_8032AA94_73C144(void);
void func_8032AC98_73C348(void);
void func_8032AE34_73C4E4(void);
void func_8032AEA0_73C550(void);
void func_8032B084_73C734(void);
void func_8032B1C8_73C878(void);


// overlay2_73C890
s32  func_8032B1E0_73C890(Animal*, s16, s16, s32*, s32*);
u8   func_8032BCF8_73D3A8(s32 arg0, s16 arg1);
s32  func_8032BD5C_73D40C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5);
void func_8032C0EC_73D79C(Animal *arg0, s16 x, s16 y, s16 z, s16 r, s16 g, s16 b);


void func_8032C2D0_73D980(s16 arg0, s16 arg1, f32 arg2);
void func_8032C508_73DBB8(s16 arg0, s16 arg1, s16 arg2, f32 arg3); // sound effect helper?
void func_8032C5A8_73DC58(u16 mass, u16 animalId, s16 x, s16 y, s16 z, u8 arg5);
void func_8032CA90_73E140(u16 mass, u16 animalId, s16 xPos, s16 zPos, s16 yPos);
void func_8032CD20_73E3D0(void* arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4);
void func_8032CD70_73E420(void* arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4, s16 arg5, s16 arg6, s16 arg7);
void func_8032CED0_73E580(void*, s16, s16, f32, s16, s16 /* u8 */, s16, s16, s16, s32, s32, s32); // maybe

// overlay2_73ED30
void func_8032E150_73F800(Gfx **arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6); // tbd
void func_8032F8C8_740F78(s16 arg0, s16 arg1, s16 arg2, s16 arg3);

// overlay2_741000
void func_8032F950_741000(void);
void func_8032FD0C_7413BC(u8 cameraID, u8 arg1);
void func_8032FF94_741644(u8);
void func_80332444_743AF4(u8);
void func_80334470_745B20(u8, u8);
void func_8033641C_747ACC(u8, u8, u8);
void func_803378BC_748F6C(u8);
void func_80337ECC_74957C(u8);
void func_80338E1C_74A4CC(u8);
void func_803391D0_74A880(u8 arg0);
void func_80339238_74A8E8(u8 arg0);
void func_803392A0_74A950(u8 arg0);
void func_80339308_74A9B8(u8 arg0);
void func_803394E4_74AB94(u8, u8);
void func_80339B84_74B234(u8, f32);
void func_8033AAC8_74C178(u8 cameraID);
void func_8033AC68_74C318(f32 *arg0, f32 *arg1, f32 *arg2, WaypointData *arg3, s16 arg4); // TBD
void func_8033B118_74C7C8(u8);
void func_8033B440_74CAF0(u8 arg0);
void func_8033B594_74CC44(u8);
void func_8033B9B8_74D068(u8);
void func_8033C054_74D704(u8);
void func_8033C320_74D9D0(u8);
void func_8033C334_74D9E4(void);
s32  func_8033C814_74DEC4(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, u8 arg8);
s32  func_8033C8EC_74DF9C(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
s32  func_8033C9CC_74E07C(s16 arg0, s16 arg1, s16 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9);
s32  func_8033D604_74ECB4(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
s16  func_8033DF88_74F638(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9); // tbd
void func_8033E430_74FAE0(void);
void func_8033E6B8_74FD68(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5);
void func_8033E7C8_74FE78(OSContPad *cont);
void func_8033EF94_750644(OSContPad *cont, u16 arg1);
void func_8033F23C_7508EC(s16 arg0);
void func_8033F294_750944(s16 arg0);
void func_8033F2EC_75099C(void);
void func_8033F300_7509B0(void);
void func_8033F380_750A30(void);
void func_80340E08_7524B8(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, s8 arg5, s8 arg6, u8 arg7, s16 arg8);
void func_80340EA4_752554(struct062*, s16);
void func_803415BC_752C6C(void);
void func_803421E0_753890(s16 arg0);
void func_80342550_753C00(Camera *arg0);
void func_8034220C_7538BC(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_803423C4_753A74(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80342318_7539C8(s32 arg0, s32 arg1, s32 arg2);
void func_80343438_754AE8(void);
void func_80343720_754DD0(s16*, s16*, s16*);
void func_80343A50_755100(void);
void func_80343AE0_755190(u8 arg0, s16 arg1, s16 arg2, struct071 *arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, s16 argA, u8 argB, s8 argC, s8 argD, u8 argE);
void func_80343C44_7552F4(s16 arg0, u16 *arg1, u16 *arg2);
void func_80343C74_755324(s16 arg0, s8 arg1, s8 arg2, s8 arg3, u8 arg4);
void func_80343D44_7553F4(struct071 *arg0, s8 arg1);
void func_80343DC0_755470(void);
void func_80343F58_755608(s16 arg0);
void func_80343F68_755618(void);
void func_80343F78_755628(void);
void func_8034401C_7556CC(void);
s16  func_80344158_755808(s16 arg0);
void func_8034419C_75584C(struct071 *arg0);
void func_803441FC_7558AC(void);

// overlay2_7558F0
void func_803458B8_756F68(Gfx **arg0, Vtx *vtx, s16 num);
void func_80346878_757F28(Gfx **arg0, u8 arg1);
void func_803469D4_758084(Gfx **arg0, u16 arg1);
void func_80346AB0_758160(Gfx **arg0, u8 arg1);

// sssv/osd.c
void func_80348230_7598E0(s32 arg0);
void func_803491F0_75A8A0(void);
void func_80349278_75A928(void);
void func_80349280_75A930(Animal *arg0, s16 arg1);
void func_803493C8_75AA78(void);
void func_8034967C_75AD2C(void);
void func_80349720_75ADD0(void);
void func_803497DC_75AE8C(void);
u8   func_80349874_75AF24(void);
void func_80349900_75AFB0(s16 *arg0, u16 arg1);
u8   func_80349A14_75B0C4(void); // dupe of func_80349874_75AF24
void func_80349AA0_75B150(u16 arg0);
void func_80349CA4_75B354(s16 arg0);
void func_80349D34_75B3E4(void);
void func_80349DCC_75B47C(s16 arg0);

// overlay2_75BC80
void func_8034A320_75B9D0(void);
void func_8034A5D0_75BC80(void);
void func_8034A60C_75BCBC(void);
void func_8034A648_75BCF8(void);
void func_8034A684_75BD34(void);
void func_8034A914_75BFC4(void);
void func_8034ABA4_75C254(void);
void func_8034AE34_75C4E4(s32 arg0, s32 arg1);
void func_8034AF0C_75C5BC(s32 arg0, s32 arg1);
void func_8034AFE0_75C690(void);
void func_8034AFE8_75C698(s32 arg0, Animal *arg1);
void func_8034AFF4_75C6A4(s32 arg0, Animal *arg1);
void func_8034B000_75C6B0(s32 arg0);
void func_8034B008_75C6B8(s32, s32, s32, s32*, s32*, s32*); // tbd
void func_8034B298_75C948(s16 arg0);
void func_8034B3A8_75CA58(s16 arg0);
void func_8034B45C_75CB0C(void);
void func_8034B64C_75CCFC(s16 arg0, s16 arg1, s16 arg2);
void func_8034B848_75CEF8(s16 arg0);
void func_8034BB38_75D1E8(u8 arg0);

// overlay2_75D3D0
void func_8034BD20_75D3D0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *img, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s16 argA, s16 argB, u8 argC);
void func_8034C8F8_75DFA8(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *img, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s16 argA, s16 argB, u8 argC);
void func_8034CCBC_75E36C(struct061 *arg0, s16 numVtxs, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6);
void func_8034CE88_75E538(struct061 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7);
void func_8034D830_75EEE0(struct061 *arg0, struct061 *arg1, struct061 *arg2, s16 arg3, s16 *arg4, s16 *arg5, s16 arg6, s16 arg7, s32 arg8, s8 arg9);
void func_8034F3EC_760A9C(struct061 *arg0, struct061 *arg1, struct061 *arg2, s16 numVtxs, s16 *arg4, s16 *arg5, s16 arg6);
void func_80350600_761CB0(s16 numVtxs, struct061 *vtxs, s16 alpha, s16 arg3, s16 arg4, s32 arg5, u8 arg6, u8 arg7, s16 red, s16 green, s16 blue, s32 argB, s32 argC, s32 argD, s32 argE);
void func_80351390_762A40(s16 numVtxs, struct061 arg1[], s16 alpha, s16 arg3, s16 arg4, s32 arg5, s16 red, s16 green, s16 blue, s32 arg9, s32 argA, s32 argB, s32 argC);
void func_80351A44_7630F4(s16 numVtxs, struct061 arg1[], s16 alpha, s16 arg3, s16 arg4, s16 red, s16 green, s16 blue);
void func_80351EE8_763598(s16 numVtxs, struct061 arg1[], s16 arg2, s16 alpha, s16 red, s16 green, s16 blue);
void func_80355918_766FC8(void);

// chameleon
void func_8035A5F0_76BCA0(void);
void func_8035BDC0_76D470(void);
void func_8035C018_76D6C8(void);
void func_8035C08C_76D73C(void);
void func_8035C0CC_76D77C(void);
void func_8035C10C_76D7BC(void);
void func_8035C180_76D830(s16 arg0);

// overlay2_76D850
void func_8035C1A0_76D850(void);
void func_8035D120_76E7D0(void);
void func_8035D6A0_76ED50(void);
void func_8035D6D0_76ED80(void);
void func_8035D734_76EDE4(void);
void func_8035DA60_76F110(void);
void func_8035DEC4_76F574(void);

// tortoise
void func_80352380_763A30(void);
void func_80354188_765838(void);
void func_80355130_7667E0(void);
void func_80355E14_7674C4(void);
void func_80355EDC_76758C(void);
void func_80355EFC_7675AC(void);
void func_80355F64_767614(void);
void func_80355FFC_7676AC(void);
void func_80356064_767714(void);
void func_803560CC_76777C(void);
void func_80356134_7677E4(Animal *arg0);
void func_803562C8_767978(s16 arg0);
void func_80356348_7679F8(s16 arg0);

// overlay2_767AC0
void func_80356BD8_768288(u8 *arg0, u8* arg1, s16 arg2);
void func_80356D84_768434(u8 *arg0, s32 arg1);
void func_80356F64_768614(u8 *arg0, u8* arg1, s32 arg2);

// overlay2_7689A0
void func_80357200_7688B0(void);
void set_music_track(s8 arg0);
s32  func_803572C0_768970(void);

// overlay2_7689A0
void func_803572F0_7689A0(void);
void func_8035739C_768A4C(void);
void func_80357438_768AE8(void);
void func_80357480_768B30(void);

// sssv/animals/hyena (overlay2_768B90)
void func_803574E0_768B90(void);
void func_80358E3C_76A4EC(void);

void func_8035A130_76B7E0(void);
void func_8035A170_76B820(void);
void func_8035A2A8_76B958(void);
void func_8035A590_76BC40(s16 arg0);
void func_8035A5A4_76BC54(s16 arg0);

// overlay2_76F7D0
void func_8035E120_76F7D0(void);
void func_8035E200_76F8B0(void);
s32  func_8035E344_76F9F4(Animal2 *arg0, s16 arg1);

// rat
void func_8035E430_76FAE0(void);

// void *func_8035E200_76F8B0(void);
void func_8035F92C_770FDC(void);
void func_8035FA5C_77110C(void);
void func_8035FA84_771134(void);
void func_8035FAEC_77119C(void);
void func_8035FB10_7711C0(void);
void func_8035FC08_7712B8(void);

// sheep
void func_8035FE90_771540(void);
void func_80360D94_772444(void);


void func_803622DC_77398C(void);

void func_80362618_773CC8(void);
void func_80362964_774014(void);

void func_803629B0_774060(void);
void func_80362A00_7740B0(void);
void func_80362A08_7740B8(void);
void func_80362A10_7740C0(void);

//overlay2_7741B0
s32  func_80362B00_7741B0(Animal *a);
s32  func_80362B60_774210(Animal *a);
s32  func_80362BEC_77429C(Animal *a);
void func_80362C10_7742C0(Animal *arg0);
void func_80363738_774DE8(Animal *arg0, Animal *arg1, u16 arg2);
void func_8036379C_774E4C(Animal *arg0);
void func_803637D4_774E84(Animal *arg0, Animal *arg1, u16 arg2);
void func_80363844_774EF4(Animal *arg0, s16 arg1);
void func_80363880_774F30(Animal *arg0, Animal *arg1);
void func_803638A8_774F58(Animal *arg0, Animal *arg1, s16 arg2);
void func_803638E8_774F98(Animal *arg0);
void func_80363B34_7751E4(Animal *arg0, u16 arg1);
void func_8036390C_774FBC(Animal *arg0, u8 pathId, u8 arg2, s8 arg3, u8 arg4, u8 arg5);
void func_80363A0C_7750BC(Animal *arg0, u8 pathId, u8 arg2, s8 arg3, u8 arg4, u8 arg5);
void func_80363B98_775248(Animal *arg0, s16 xPos, s16 zPos, s16 arg3, s8 arg4, u8 arg5);
void func_80363C0C_7752BC(Animal *arg0, u8 arg1);
void func_80363C48_7752F8(Animal *arg0, s16 xPos, s16 zPos, s16 arg3, s8 arg4, u8 arg5);
void func_80363CC8_775378(Animal *arg0);
void func_80363DB4_775464(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3);
void func_80363CE0_775390(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3);
void func_80363E88_775538(Animal *arg0, Animal *arg1);
void func_80363EDC_77558C(Animal *arg0, s16 arg1, Animal *arg2);
void func_80363FB8_775668(Animal *arg0, u16, s16, s16);
void func_80363FF0_7756A0(Animal *arg0);
void func_80364120_7757D0(u8 arg0, s16 arg1, s16 arg2, Animal *arg3);

// sssv/animals/penguin (overlay2_775E30)
void func_80364780_775E30(void);
void func_80365954_777004(void);
void func_80365C28_7772D8(void);
void func_80365C7C_77732C(void);
void func_80365D74_777424(void);
void func_80365E70_777520(s16 arg0);

// sssv/animals/polar_bear (overlay2_7775C0)
void func_80365F10_7775C0(void);
void func_803677C4_778E74(void);
void func_80368840_779EF0(s16 arg0);
void func_80368AC4_77A174(void);
void func_80368B04_77A1B4(void);
void func_80368B78_77A228(void);
void func_80368BA0_77A250(void);

void func_80368D60_77A410(s16 arg0);

// sssv/animals/husky (overlay2_77A480)
void func_80368DD0_77A480(void);
void func_8036A05C_77B70C(void);
void func_8036BBB8_77D268(void);
void func_8036BBE8_77D298(void);
void func_8036BCF8_77D3A8(void);
void func_8036BE70_77D520(void);
void func_8036C014_77D6C4(s16);

// sssv/animals/vulture (overlay2_77D760)
void func_8036C0B0_77D760(void);
void func_8036D30C_77E9BC(void);
void func_8036D5CC_77EC7C(void);

// sssv/animals/camel (overlay2_77EDB0)
void func_8036D700_77EDB0(void);
void func_8036F3AC_780A5C(void);
void func_8036F404_780AB4(void);
void func_8036F4CC_780B7C(void);
void func_8036F50C_780BBC(Animal *arg0);
void func_8036F5F4_780CA4(Animal *arg0);
void func_8036F740_780DF0(u16 arg0);

// sssv/animals/kangaroo (overlay2_780E50)
void func_8036F7A0_780E50(void);
void func_80370C84_782334(void);
void func_80372510_783BC0(void);
void func_803725A4_783C54(void);
void func_80372604_783CB4(void);
void func_80372698_783D48(void);

// sssv/animals/desert_fox (overlay2_783D90)
void func_803726E0_783D90(void);
void func_80373788_784E38(void);
void func_80374470_785B20(void);
void func_803744C4_785B74(void);
void func_80374518_785BC8(void);
void func_803745BC_785C6C(void);
void func_803745C4_785C74(s16 arg0);
void func_8037460C_785CBC(void);

// overlay2_785D10
void func_80374660_785D10(s16 arg0, s16 arg1, s16 arg2);
void func_803747CC_785E7C(void);
void func_803747F4_785EA4(void);
void func_80374C38_7862E8(s16 arg0, s16 arg1, s16 arg2);

// sssv/animals/walrus (overlay2_786320)
void func_80374C70_786320(void);
void func_803766E8_787D98(void);
void func_803769E0_788090(void);


// sssv/animals/scorpion (overlay2_7883F0)
void func_80376D40_7883F0(void);
void func_80378FF8_78A6A8(void);
void func_80379048_78A6F8(void);
void func_80379070_78A720(void);
void func_80379148_78A7F8(Animal *a);
void func_803791AC_78A85C(void);

// sssv/animals/gorilla (overlay2_78A890)
void func_803791E0_78A890(void);
void func_8037B590_78CC40(void);
void func_8037B660_78CD10(void);
void func_8037B70C_78CDBC(void);
void func_8037B754_78CE04(Animal *arg0, Animal *arg1);
void func_8037B784_78CE34(Animal *arg0);

// sssv/animals/elephant (overlay2_78CEB0)
void func_8037B800_78CEB0(void);
void func_8037D06C_78E71C(void);
void func_8037D0EC_78E79C(void);
void func_8037D138_78E7E8(void);
void func_8037D268_78E918(s16 arg0);

// overlay2_78E970
void func_8037D2C0_78E970(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8037D340_78E9F0(s16 arg0, s16 arg1);
void func_8037D2D4_78E984(s32 arg0, s32 arg1, s32 arg2);
void func_8037D2E4_78E994(s32 arg0);
void func_8037D310_78E9C0(s32 arg0, s32 arg1, s32 arg2);
void func_8037D320_78E9D0(s32 arg0, s32 arg1);
void func_8037D32C_78E9DC(s32 arg0, u8 arg1, s32 arg2, u16 arg3, s32 arg4);
void func_8037D994_78F044(s8 arg0);
void func_8037D9D4_78F084(void);
void func_8037E6DC_78FD8C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4);
Animal *func_8037E9AC_79005C(void);
Animal *func_8037ED1C_7903CC(void);
void func_8037E1C4_78F874();
s16  func_8037F07C_79072C(s16 arg0, s16 arg1);
u8   func_8037FBBC_79126C(void);
void func_8037FCA8_791358(void);
void func_8037FE24_7914D4(void);
void func_8037FEDC_79158C(void);

// sssv/animinit.c
void func_80380490_791B40(Gfx **arg0, DisplayList *arg1);
void func_80380620_791CD0(Animal *arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4);
void func_80380644_791CF4(Animal *arg0);
void func_8038064C_791CFC(void);

// sssv/animals/seagull (overlay2_791FD0)
void func_80380920_791FD0(void);
void func_80381C60_793310(void);
void func_80381F14_7935C4(void);

// sssv/animals/pirana (overlay2_793700)
void func_80382050_793700(void);
void func_80382C9C_79434C(void);
void func_80382CB0_794360(void);
void func_80382CC0_794370(s16 arg0);
void func_80382CE4_794394(void);

// sssv_animals_cool_cod
void func_80382CF0_7943A0(void);

// overlay2_794EE0
void func_80383804_794EB4(void);
s32  func_80383830_794EE0(u16 arg0);
s32  func_803838C8_794F78(u16 rotation, u16 arg1);
s16  func_8038395C_79500C(void);
void func_80385078_796728(void);
void func_803852B8_796968(void);
void func_803852C8_796978(void);
void func_80385480_796B30(void);
void func_80385488_796B38(void);
void func_80385490_796B40(void);
void func_80385710_796DC0(void);
void func_803859D4_797084(void);
void func_80385A0C_7970BC(void);
void func_80385BE0_797290(void);
void func_803865A0_797C50(void);
void func_803867B8_797E68(void);
void func_803867C0_797E70(void);
void func_80386BB8_798268(void);
void func_80386D80_798430(void);
void func_80386F84_798634(void);
void func_8038710C_7987BC(void);
void func_80387114_7987C4(void);
void func_80387330_7989E0(void);
void func_8038754C_798BFC(void);
void func_80387780_798E30(void);
void func_803879A4_799054(void);
void func_80387BF4_7992A4(void);
void func_80387DE0_799490(void);
void func_8038801C_7996CC(void);
void func_80388248_7998F8(void);
void func_80388B0C_79A1BC(void);
void func_80388CC8_79A378(void);
void func_80388F10_79A5C0(void);
void func_80389150_79A800(void);
void func_80389158_79A808(void);
void func_80389160_79A810(void);
void func_803892D4_79A984(void);
void func_803892DC_79A98C(void);
void func_803892E4_79A994(void);
void func_803892EC_79A99C(void);
void func_8038951C_79ABCC(void);
void func_80389524_79ABD4(void);
void func_8038974C_79ADFC(void);
void func_80389754_79AE04(void);
void func_8038975C_79AE0C(void);
void func_80389764_79AE14(u8 arg0);
s32  func_803897B0_79AE60(u8 arg0);
void func_803899E0_79B090(Animal *arg0);

// evo
void func_80389B30_79B1E0(void);

void func_8038C230_79D8E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4);
void func_8038C484_79DB34(s16 arg0, s16 arg1, s16 arg2, f32 arg3, s16 arg4);

// overlay2_79B1E0
void func_8038B330_79C9E0(void);
void func_8038B730_79CDE0(void);
void func_8038B774_79CE24(void);

// overlay2_79DE10
void func_8038C760_79DE10(void);
void func_8038C768_79DE18(void);
void func_8038C98C_79E03C(void);
s16  func_8038CC28_79E2D8(void);
s16  func_8038CC50_79E300(void);
s16  func_8038CCA4_79E354(void);
s16  func_8038CCC0_79E370(void);
s16  func_8038CCF0_79E3A0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);

// sssv/terminal_background (overlay2_79E640)
void func_8038CF90_79E640(void);
void func_8038D004_79E6B4(Gfx **arg0, u16 intensity);
void func_8038D258_79E908(void);
void func_8038D920_79EFD0(u8 arg0);
void func_8038DA70_79F120(void);
void func_8038DBE0_79F290(s32 arg0, s32 arg1);
void func_8038E504_79FBB4(u16 arg0);
void func_8038E9F8_7A00A8(void);
void func_8038F414_7A0AC4(void);
void func_8038F5F8_7A0CA8(Animal *arg0);
void func_8038F694_7A0D44(void);

// overlay2_7A0DA0
void func_8038F6F0_7A0DA0(void);
void func_8038F708_7A0DB8(void);
void func_8038F968_7A1018(void);
void func_8038FAB4_7A1164(void);
void func_8038FB68_7A1218(void);
void func_8038FC58_7A1308(void);
void func_8038FCF8_7A13A8(void);
void func_8038FD74_7A1424(void);
void func_8038FF48_7A15F8(void);
void func_8038FF68_7A1618(void);
void func_80391A38_7A30E8(void);
void func_803925D0_7A3C80(u16 *src, u16 *dst);
void func_8039264C_7A3CFC(void);
void func_80392668_7A3D18(void);
void func_80395074_7A6724(s32 debug);
void func_80395088_7A6738(Gfx **arg0, s16 ulx, s16 uly, s16 lrx, s16 lry, u8 color);
void func_8039546C_7A6B1C(Gfx **arg0, s16 arg1, s16 arg2, s16 arg3);
void func_80395480_7A6B30(void);
void func_80395854_7A6F04(void);
void func_80395B58_7A7208(void);
void func_80395E98_7A7548(Gfx **arg0);
void func_803962EC_7A799C(Gfx **dl, s16 p_screen_x, s16 p_screen_y, s16 arg3, s16 arg4, u8* img, u16 width, u16 height);
void func_8039661C_7A7CCC(s16 arg0, s16 arg1, s16 arg2);
s32  func_80396714_7A7DC4(void);
s32  func_80396748_7A7DF8(void);
// void func_803967D4_7A7E84(u16 arg0, s16 arg1, u8 r, u8 g, u8 b, s16 head, s16 torso, s16 arms, s16 legs, s16 arg9);

// overlay2_7A8A50
void func_803973A0_7A8A50(s16);
void func_80397414_7A8AC4(u8 push, f32 x_amt, f32 y_amt, f32 z_amt, f32 x_angle, f32 y_angle, f32 z_angle);
void func_803976E0_7A8D90(void);
void func_80397734_7A8DE4(s16 arg0, u8 arg1);
void func_80397840_7A8EF0(void);
void func_80397B84_7A9234(void);
void func_80397C58_7A9308(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s16 arg7, u8 arg8);
void func_80397D1C_7A93CC(u8 arg0);
void func_80397F5C_7A960C(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4, s32 arg5, u8 arg6, u8 arg7);

// overlay2_7A9CE0
void func_80398630_7A9CE0(void);
void func_8039884C_7A9EFC(void);
void func_8039895C_7AA00C(void);
void func_80398A00_7AA0B0(void);
void func_8039A2DC_7AB98C(void);
void func_8039BBB8_7AD268(void);
void func_8039BE98_7AD548(u8 arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, PlayerEeprom *arg6, s16 arg7, s16 arg8, f32 arg9, u8 argA);
void func_8039C5F8_7ADCA8(s16 arg0, s16 arg1, f32 arg2, PlayerEeprom *arg3, s16 arg4);
void func_8039C834_7ADEE4(Gfx **dl, u8 *src, u16 width, u16 height, f32 scale_x, f32 scale_y, u8 flip_x, u8 flip_y, u16 p_screen_x, u16 p_screen_y);
void func_8039CAB8_7AE168(s16 arg0);
f32  func_8039CDE8_7AE498(f32 arg0, f32 arg1);
void func_8039CE38_7AE4E8(Gfx **arg0);
void func_8039D034_7AE6E4(Gfx **arg0, s16 arg1);

// overlay2_7AF410

void func_8039DD90_7AF440(Trail *arg0);
void func_8039E33C_7AF9EC(WalrusWake *arg0);
void func_8039E6D4_7AFD84(RegularTrail *arg0);

#endif
