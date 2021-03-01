#ifndef FUNCTIONS_US_H
#define FUNCTIONS_US_H

#include "functions.h"


// main_1050.c
void func_80125950(s32 arg0);
void func_80125980(Mtx *, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s32 arg7, s32 arg8, s32 arg9);
void func_8012635C(s32 arg0, s32 arg1, s32 arg2[]);
void func_80125FE0(Mtx *, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6, s32 arg7, s32 arg8);
void func_80128078(Gfx *arg0, s16 arg1, s16 arg2);

// core/controller.c
u32  func_80128200(void);
void func_8012822C(s32 time);
u16  func_8012826C(void);
void func_801282C4(void);
s16  func_8012835C(s16 idx);
s16  func_801283AC(s16 arg0);
s8   func_8012840C(u8 idx);
s8   func_80128424(u8 idx);
s16  func_8012844C(s16 arg0);
s16  func_801284B8(s16 arg0, s16 arg1);
f32  func_801286B8(f32 arg0, f32 arg1);
s16  func_80128C10(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

// core/string.c
u16  string_length(u8 *s);
void strcat(u8 *dst, u8 *src);
void strcpy(u8 *dst, u8 *src);
void fancy_bzero(u8 *addr, s32 len);

// main_4790.c
u8  *strncpy(u8 *src, u8 *dst, u32 len);
u8  *func_80129090(u8 *arg0, u8 arg1, u32 len);
s32  func_80129198(s16 *arg0);

// main_4910.c
void read_rom_header(void);
void set_region(void);
void dma_read(u8 *devAddr, void *vAddr, s32 nbytes);
void func_80129300(Gfx **arg0, DisplayList *ddl);
void func_80129430(Gfx **arg0);
void func_80129594(Gfx **dl, DisplayList *ddl);
void func_80129784(Gfx **dl, DisplayList *ddl);
void func_8012991C(Gfx **dl, DisplayList *ddl);
void init(void);
void func_80129B10(s32);
void func_80129DC0(void);
void func_8012A260(void);
void func_8012A400(void);
void func_8012A490(void);
void func_8012A588(void);
void func_8012A750(void);
void func_8012A870(void);
void func_8012AB94(void);
void func_8012ABF0(void);
void func_8012AC40(void);
void func_8012AC8C(void);
void func_8012AD08(void);
void draw_rectangle(Gfx **arg0, s16 x0, s16 y0, s16 x1, s16 y1, u8 r, u8 g, u8 b, u8 a);

// core/rnc.c
u16  rnc_decompress(u8 *src, u8* dst);

// main_7770.c
void func_8012C070(u8);

// main_78F0
void load_default_display_list(Gfx**);
void set_menu_text_color(u8 r, u8 g, u8 b, u8 a);
void select_font(u8, u8, u8, u8);
void select_comic_sans_font(void);
void select_lcd_font(void);
s16  func_8012C314(f32 arg0);
void draw_glyph(Gfx **arg0, s16 *arg1, u16 x, u16 y, f32 width, f32 height);
s32  func_8012E724(u16 *arg0, s32 arg1, s32 arg2);
s32  func_8012E78C(s32, f32, f32, s32);
void func_8012FA78(Gfx **arg0);
void func_8012FAD4(Gfx **dl, s32 arg1);
void load_glyph(Gfx **arg0, s16 arg1);
void func_801304EC(Gfx **arg0, char*, u16, u16);
void func_801308B4(u8 *src, s16 *dst);
s16  func_801308E8(s16 arg0, s16 arg1, u16 *arg2, s16 *arg3);
s16* func_80130A90(s16 arg0);
s16  func_80130AC0(s16 *arg0);

void func_8012C214(s32, s32, s32, s32);
void func_8012C978(Gfx **, s16*, u16, u16, f32, f32);
void func_8012DEF8(Gfx **, u16*, u16, s32, f32, f32);
void func_8012EB4C(Gfx **, s16*, u16, u16, f32, f32, u8);
void func_80131070(void);
void func_80131BF0(s32*);
void func_80130C04(void);


// core/fontinit.c
void font_init(void);

// core/eeprom.c
s16  write_eeprom(s16 arg0);
s32  read_eeprom(s16 slot);
s32  eeprom_checksum(u8 *arg0);
void func_80130E44(void);

// core/audio.c
void func_80131290(ALSynConfig *c, s32 priority);
void *func_80131AA0(s32 *arg0);
void func_801322EC(struct026 *arg0, struct026 *arg1, struct026 *arg2);
void func_80132394(void);
struct017 *func_801323B8(s16 slot); // get_sound_by_slot
struct017 *func_80132414(u16 id);   // get_sound_by_id
struct017 *func_80132568(void);
void *func_80132580(s32 arg0, s16 id);
void func_801325E8(s32 arg0, s8 arg1);
s32  func_8013266C(s8 arg0); // get_seqp_state

// main_E3C0.c
void func_80132CC0(s32 arg0);
s16  func_80132D54(void);
s32  func_80132D84(ALSndPlayer *sndp);
void play_sound_effect(s16, s16, s16, f32, u8);
s16  func_8013328C(s32 arg0, s16 arg1, s16 arg2, f32 arg3, s16 arg4, s16 arg5);
void func_80133528(u8 arg0, s16 vol);
void func_8013359C(u8 arg0);
void func_80133608(s16 arg0);
void func_8013364C(void);
void func_80133738(void);
void func_801337BC(s8 arg0, s32 arg1);
void func_801337DC(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8013385C(f32 arg0, f32 arg1, f32 arg2);
void func_801338A8(s16 arg0);
void func_801339F8(void);
void func_80133B74(s16 arg0);
void func_80133BA0(s16 arg0);
void func_80133BE4(void);
void func_80133C50(void);
void func_80133E44(void);
void func_80133E84(void);

// main_10CB0.c
void func_801355B0(void);
void func_80135604(void);
void func_801356C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Gfx **arg4, u8 *arg5, f32 arg6, f32 arg7, u8 arg8);
void func_80135CD8(u32 arg0, u32 arg1, u32 arg2, s32 arg3, Gfx **arg4, u8 *arg5);
void func_80136418(Gfx **dl, u8 color);
void func_801366BC(Gfx **dl, u8 r, u8 g, u8 b, u8 a);
void func_80136938(Gfx **dl, u8 *arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, u8 arg6, u8 arg7, u16 arg8, u16 arg9, u8 argA);

// main_123E0.c
s32  func_80136CE0(void); // initialise controllers?
void func_80136F64(void);
void func_801370A4(void);
void func_801370F4(void);
void func_8013713C(void);
void func_80137204(s16 arg0);
void func_8013724C(s16 arg0);
void func_80137840(void);



void func_80137294(void);
void func_801373CC(s32, s32, s32, s32, s32);
void func_80139200(f32);
void func_80139330(f32);

void func_80296544_6A7BF4(void);

void func_802B3FAC_6C565C(void);
void func_802B8790_6C9E40(void);
void func_802B8810_6C9EC0(void);
void func_802B8918_6C9FC8(void);
void func_802B8978_6CA028(void);
void func_802B8A48_6CA0F8(void);

// overlay1_6384F0.c
void func_80294E50_6384F0(void); // overlay1 entrypoint
void func_80294E70_638510(Gfx **dl, u8 alpha);
void func_80294EB8_638558(Gfx **dl);
void func_802950B8_638758(void);
void func_80295234_6388D4(void);
void func_8029548C_638B2C(void);
void func_80295494_638B34(Gfx **arg0, u16 arg1);
void func_802958B8_638F58(Gfx **dl);
void func_80298C70_63C310(u8 arg0);
void func_80295C38_6392D8(u8 arg0, u8 arg1);
void func_80295EB0_639550(s32 arg0);
void func_802988E8_63BF88(void);

void func_802C79E0_6D9090(s16*, s16);
void func_802C9340_6DA9F0(void);
void func_802C9834_6DAEE4(void);
void func_802CB360_6DCA10(void);

s32  func_802F8160_709810(Animal*, Animal*, s32, s32, s32, s32, s32, s32, f32);
void func_802FF0A4_710754(s16, s16, s16, s16, s16, Animal*, s16, s16);

// overlay2_6A6500.c
void func_80294E50_6A6500(void); // overlay2 entrypoint
void func_8029614C_6A77FC(void);
void func_8029619C_6A784C(void);
void func_802961D4_6A7884(void);
void func_80296310_6A79C0(void);
s32  func_80296320_6A79D0(void);

// overlay2_6A7A80
void func_8029877C_6A9E2C(void);
s32  func_80298E08_6AA4B8(s16 arg0, s16 arg1);
s16  func_80298F78_6AA628(s16 arg0, s16 arg1);
void func_80299640_6AACF0(s16, s16, s16*, s16*, s16*, s16*);

// overlay2_6AB090.c
void func_802999E0_6AB090(DisplayList *arg0);
void func_80299AA8_6AB158(DisplayList *arg0, Gfx **arg1);
void func_8029A32C_6AB9DC(s32 arg0);
void func_8029A3B0_6ABA60(s32, s32, s32);
u16  func_8029A52C_6ABBDC(u8 arg0);
u16  func_8029A568_6ABC18(s16 arg0);
void func_8029A5B4_6ABC64(Gfx **dl, u8 r, u8 g, u8 b);
void func_8029A624_6ABCD4(Gfx **dl);
void func_8029ABCC_6AC27C(void);

void func_802A3CD0_6B5380(void);

s16  func_8029B7D0_6ACE80(s16, s16, s16);

// overlay2_6ACF20
void func_8029B870_6ACF20(Animal *arg0, Animal *arg1);
void func_8029B9B8_6AD068(Animal *arg0, Animal *arg1);
void func_8029BA70_6AD120(Animal *arg0, Animal *arg1);
void func_8029D89C_6AEF4C(void);
void func_8029D8D8_6AEF88(Gfx **arg0, s16 arg1);
void func_8029DD84_6AF434(void);
void func_8029E3CC_6AFA7C(void);

// overlay2_6B5380
void func_802A3E70_6B5520(Animal *arg0, u32 *arg1, u32 *arg2);
void func_802A4CB8_6B6368(void);
void func_802A4D0C_6B63BC(u16 rotation, s8 arg1);
void func_802A4D80_6B6430(u16 rotation, s8 arg1);
void func_802A4DF4_6B64A4(u16 rotation, s8 arg1);
void func_802A4E74_6B6524(void);
void func_802A4EC8_6B6578(u16 rotation, s8 arg1);
void func_802A4F68_6B6618(u16 rotation, s8 arg1);
void func_802A5008_6B66B8(u16 rotation, s8 arg1);
void func_802A5558_6B6C08(void);
void func_802A55AC_6B6C5C(u16 rotation, s8 arg1);
void func_802A5620_6B6CD0(u16 rotation, s8 arg1);
void func_802A5694_6B6D44(u16 rotation, s8 arg1);
void func_802A5708_6B6DB8(s16 arg0, s16 arg1, s8 arg2);
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

s16  func_802B2580_6C3C30(void);
void func_802B2EA8_6C4558(void);
void func_802B2FF4_6C46A4(void);
void func_802B33D0_6C4A80(Animal *a);
void func_802B34B8_6C4B68(Animal *a);
void func_802B34DC_6C4B8C(void);
void func_802B3518_6C4BC8(void);
void func_802B3530_6C4BE0(void);
void func_802B3540_6C4BF0(void);
s16  func_802B3D68_6C5418(void);

// collision.c
s32  func_802B5E48_6C74F8(Animal *arg0, Animal *arg1, s32 (**arg2)(), u8 *arg3);
s32  func_802B750C_6C8BBC(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9);
s32  func_802B75B4_6C8C64(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

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
void func_802B964C_6CACFC(void);
void func_802BAA38_6CC0E8(u16 arg0, u16 arg1);

void func_802E87B8_6F9E68(Animal *arg0);
void func_802F2B54_704204(s16, s16, s16, s32, s32, s32, s32);
void func_802FEE98_710548(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, Animal* arg5, s16 arg6, s16 arg7, f32 arg8, s16 arg9, s16 argA, s16 argB, s16 argC, s16 argD, Animal* argE);

// overlay2_7117E0
void func_80300130_7117E0(s16 *arg0, s16 *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7);

void func_80304170_715820(void);
void func_80304194_715844(void);

// overlay2_716530
s32  func_80304E80_716530(struct039 *arg0);
void func_80304EC4_716574(struct039 *arg0, struct039 *arg1);
void func_80304F70_716620(struct039 *arg0, struct039 *arg1, struct039 *arg2);
s16  func_80305084_716734(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
s16  func_80305194_716844(s16 arg0, s16 arg1);
s16  func_803051F0_7168A0(s16 arg0, s16 arg1);

s32  func_80310EE4_722594(s16, s16, s16, s16);

void func_8031B390_72CA40(s32);
void func_80322064_733714(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_803223F4_733AA4(s32);
void func_80327B94_739244(s16 arg0);
void func_8032AC48_73C2F8(s16);

// overlay2_739290.c
void func_8032AA94_73C144(void);
struct025* func_803284C4_739B74(void);
void func_8032AAF0_73C1A0(s16 id); // pick new animal? load 2nd state model?
void func_8032AE34_73C4E4(void);
void func_8032AC98_73C348(void);
void func_8032AEA0_73C550(void);
void func_8032B084_73C734(void);
void func_8032B1C8_73C878(void);
u8   func_8032BCF8_73D3A8(s32 arg0, s16 arg1);
s32  func_8032BD5C_73D40C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5);
void func_8032C0EC_73D79C(s32 arg0, s16 x, s16 y, s16 z, s16 r, s16 g, s16 b);
void func_8032C2D0_73D980(s16 arg0, s16 arg1, f32 arg2);
void func_8032C360_73DA10(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, f32 arg6);
void func_8032C508_73DBB8(s16 arg0, s16 arg1, s16 arg2, f32 arg3);
void func_8032CD20_73E3D0(s32 arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4);

// overlay2_73EA30
void vector_add(Vertex *x, Vertex *y, Vertex *res);
void vector_subtract(Vertex *x, Vertex *y, Vertex *res);
void vector_multiply_by(Vertex *x, f32 c, Vertex *res);
void vector_divide_by(Vertex *x, f32 c, Vertex *res);
f32  get_magnitude(Vertex *v);
void func_8032D494_73EB44(Vertex *x, Vertex *res);
f32  dot_product(Vertex *x, Vertex *y);
void cross_product(Vertex *x, Vertex *y, Vertex *res);
s16  func_8032D5A4_73EC54(Vertex *x, Vertex *y);


void func_8031B390_72CA40(s32);
void func_80322064_733714(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_80327B94_739244(s16 arg0);
void func_8032AC48_73C2F8(s16);

void func_8032CD70_73E420(Animal *arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4, s16 arg5, s16 arg6, s16 arg7);

s32  func_8033C9CC_74E07C(s16, s16, s16, s16, s16, s16, s16, s32, s32, s32); // tbd

void func_8034220C_7538BC(s32, s32, s32, s32);
void func_803421E0_753890(s32);
void func_8034A320_75B9D0(void);

// sssv/osd.c
void func_80348230_7598E0(s32 arg0);
void func_803491F0_75A8A0(void);
void func_80349278_75A928(void);
void func_80349280_75A930(Animal *arg0, s16 arg1);
void func_803493C8_75AA78(void);
void func_8034967C_75AD2C(void);
void func_80349720_75ADD0(void);
void func_80349748_75ADF8(void);
void func_80349778_75AE28(void);
void func_803497DC_75AE8C(void);
u8   func_80349874_75AF24(void);
void func_80349900_75AFB0(s32 arg0, u16 arg1);
u8   func_80349A14_75B0C4(void); // dupe of func_80349874_75AF24
void func_80349AA0_75B150(u16 arg0);
void func_80349B84_75B234(u16 arg0);
void func_80349CA4_75B354(u16 arg0);
void func_80349D34_75B3E4(void);

void func_80352280_763930(void); // load display list segment
void func_80352310_7639C0(void); // load water texture?
void func_80355EDC_76758C(void);
void func_80355EFC_7675AC(void);
void func_80355F64_767614(void);
void func_80355FFC_7676AC(void);
void func_80356064_767714(void);
void func_803560CC_76777C(void);
void func_80356134_7677E4(Animal *arg0);
void func_803562C8_767978(s16 arg0);
void func_80356348_7679F8(s16 arg0);
void func_803563C8_767A78(s16 arg0);

// load 1 tile(?)
void func_80356410_767AC0(s32 arg0, s32 arg1);
void func_803565D4_767C84(s32 arg0, s32 arg1, s32 arg2);
void func_80356870_767F20(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80356BD8_768288(s32 arg0, s32 arg1, s16 arg2);
void func_80356D84_768434(s32 arg0, s32 arg1);
void func_80356F64_768614(s32 arg0, s32 arg1, s32 arg2);

// overlay2_7689A0
void func_803572F0_7689A0(void);
void func_8035739C_768A4C(void);

// overlay2_76F7D0
void func_8035E120_76F7D0(void);
void func_8035E200_76F8B0(void);
void func_8035E3E8_76FA98(s16 arg0);
void func_8035F92C_770FDC(void);
void func_8035FA5C_77110C(void);
void func_8035FA84_771134(void);
void func_8035FAEC_77119C(void);
void func_8035FB10_7711C0(void);
void func_8035FC08_7712B8(void);
void func_8035FC2C_7712DC(void);
void func_8035FD4C_7713FC(void);
void func_8035FDC0_771470(s16 arg0);
void func_8035FE6C_77151C(s16 arg0);

void func_803629B0_774060(void);
void func_80362A00_7740B0(void);
void func_80362A08_7740B8(void);
void func_80362A10_7740C0(void);
void func_80362A84_774134(void);

//overlay2_7741B0
s32  func_80362B00_7741B0(Animal *a);
s32  func_80362B38_7741E8(Animal *a);
s32  func_80362B60_774210(Animal *a);
s32  func_80362B9C_77424C(Animal *a);
s32  func_80362BC4_774274(Animal *a);
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
void func_80363B98_775248(Animal *arg0, s16 xPos, s16 zPos, s16 arg3, s8 arg4, u8 arg5);
void func_80363C0C_7752BC(Animal *arg0, u8 arg1);
void func_80363C48_7752F8(Animal *arg0, s16 xPos, s16 zPos, s16 arg3, s8 arg4, u8 arg5);
void func_80363CC8_775378(Animal *arg0);
void func_80363DB4_775464(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3);
void func_80363CE0_775390(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3);
void func_80363E88_775538(Animal *arg0, Animal *arg1);
void func_80363EDC_77558C(Animal *arg0, s16 arg1, Animal *arg2);
void func_80363FB8_775668(Animal *arg0, u16, s16, s16);


void func_8036F50C_780BBC(Animal *);
void func_8036F5F4_780CA4(Animal *);
void func_8036F740_780DF0(u16);


// overlay2_775E30
void func_80365954_777004(void);
void func_80365C28_7772D8(void);
void func_80365C7C_77732C(void);
void func_80365D74_777424(void);
void func_80365D8C_77743C(Animal *arg0);
void func_80365E70_777520(s16 arg0);
void func_80368AC4_77A174(void);
void func_80368B04_77A1B4(void);
void func_80368B78_77A228(void);
void func_80368BA0_77A250(void);
void func_80368C50_77A300(void);
void func_80368CF0_77A3A0(void);
void func_80368D18_77A3C8(void);
void func_80368D60_77A410(s16 arg0);
void func_8036BBB8_77D268(void);
void func_8036BBE8_77D298(void);
void func_8036BCF8_77D3A8(void);
void func_8036BE70_77D520(void);
void func_8036BEA4_77D554(Animal *arg0);
void func_8036C014_77D6C4(s16);
void func_8036C05C_77D70C(s16 arg0);

// overlay2_77D760
void func_8036D30C_77E9BC(void);
void func_8036D5CC_77EC7C(void);

// overlay2_77EDB0
void func_8036F3AC_780A5C(void);
void func_8036F404_780AB4(void);
void func_8036F4CC_780B7C(void);
void func_8036F50C_780BBC(Animal *arg0);
void func_8036F5F4_780CA4(Animal *arg0);
void func_8036F740_780DF0(u16 arg0);

// overlay2_780E50
void func_80372510_783BC0(void);
void func_803725A4_783C54(void);
void func_80372604_783CB4(void);
void func_80372698_783D48(void);

// overlay2_783D90
void func_80374470_785B20(void);
void func_803744C4_785B74(void);
void func_80374518_785BC8(void);
void func_803745BC_785C6C(void);
void func_803745C4_785C74(s16 arg0);
void func_8037460C_785CBC(void);

// overlay2_786320
void func_80376CF8_7883A8(s16 arg0);
void func_80378FF8_78A6A8(void);
void func_80379048_78A6F8(void);
void func_80379070_78A720(void);
void func_80379148_78A7F8(Animal *a);
void func_803791AC_78A85C(void);

// overlay2_78A890
void func_8037B590_78CC40(void);
void func_8037B660_78CD10(void);
void func_8037B70C_78CDBC(void);
void func_8037B754_78CE04(Animal *arg0, Animal *arg1);
void func_8037B784_78CE34(Animal *arg0);

// overlay2_78CEB0
void func_8037D06C_78E71C(void);
void func_8037D0EC_78E79C(void);
void func_8037D138_78E7E8(void);
void func_8037D268_78E918(s16 arg0);

// overlay2_78E970
void func_8037D2C0_78E970(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8037D2D4_78E984(s32 arg0, s32 arg1, s32 arg2);
void func_8037D2E4_78E994(s32 arg0);
void func_8037D310_78E9C0(s32 arg0, s32 arg1, s32 arg2);
void func_8037D320_78E9D0(s32 arg0, s32 arg1);
void func_8037D32C_78E9DC(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8037D994_78F044(s8 arg0);
void func_8037D9D4_78F084(void);

Animal *func_8037E9AC_79005C(void);
Animal *func_8037ED1C_7903CC(void);

void func_8037FE24_7914D4(void);

// sssv/animinit.c
void func_80380620_791CD0(Animal *arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4);
void func_80380644_791CF4(Animal *arg0);
void func_8038064C_791CFC(void);

// overlay2_793700
void func_80382C9C_79434C(void);
void func_80382CB0_794360(void);
void func_80382CC0_794370(s16 arg0);
void func_80382CE4_794394(void);

// overlay2_79CEF0
void func_8038B840_79CEF0(void);
s32  func_8038B854_79CF04(void);

// sssv/cheats.c
void reset_cheats(void);
void check_cheats(u16 *buttonMaskPtr);
s32  check_cheat_code(const u8 *buttonPresses, const char *cheatCode);

void func_8038D258_79E908(void);

// overlay2_794EE0
s32  func_80383830_794EE0(u16 arg0);
s32  func_803838C8_794F78(u16 rotation, u16 arg1);
s16  func_8038395C_79500C(void);
void func_803839F0_7950A0(void);
void func_80383BE4_795294(void);
void func_80383E38_7954E8(void);
void func_80383E40_7954F0(void);
void func_80384060_795710(void);
void func_8038448C_795B3C(void);
void func_803846BC_795D6C(void);
void func_80384858_795F08(void);
void func_80384A8C_79613C(void);
void func_80384CB8_796368(void);
void func_80384F14_7965C4(void);
void func_80384F1C_7965CC(void);
void func_80385078_796728(void);
void func_80385080_796730(void);
void func_80385088_796738(void);
void func_803852B8_796968(void);
void func_803852C0_796970(void);
void func_803852C8_796978(void);
void func_80385480_796B30(void);
void func_80385488_796B38(void);
void func_80385490_796B40(void);
void func_80385710_796DC0(void);
void func_803859D4_797084(void);
void func_80385A0C_7970BC(void);
void func_80385BE0_797290(void);
void func_80385DF0_7974A0(void);
void func_80385F90_797640(void);
void func_80386454_797B04(void);
void func_803865A0_797C50(void);
void func_803867B8_797E68(void);
void func_803867C0_797E70(void);
void func_80386A48_7980F8(void);
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
void func_80388480_799B30(void);
void func_80388744_799DF4(void);
void func_803888F0_799FA0(void);
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
void func_803892F4_79A9A4(void);
void func_8038951C_79ABCC(void);
void func_80389524_79ABD4(void);
void func_8038974C_79ADFC(void);
void func_80389754_79AE04(void);
void func_8038975C_79AE0C(void);
void func_80389764_79AE14(u8 arg0);
s32  func_803897B0_79AE60(u8 arg0);
void func_803899E0_79B090(void *arg0);

// overlay2_79E640
void func_8038CF90_79E640(void);
void func_8038D920_79EFD0(u8 arg0);
void func_8038DA70_79F120(void);
void func_8038F694_7A0D44(void);


// overlay2_7A0DA0
void func_8038F6F0_7A0DA0(void);
void func_8038F708_7A0DB8(void);
void func_8038F794_7A0E44(void);
void func_8038F8C8_7A0F78(void);
void func_8038F968_7A1018(void);
void func_8038FA00_7A10B0(void);
void func_8038FAB4_7A1164(void);
void func_8038FB68_7A1218(void);
void func_8038FB94_7A1244(s16 arg0);
void func_8038FC04_7A12B4(void);
void func_8038FC58_7A1308(void);
void func_8038FCF8_7A13A8(void);
void func_8038FD74_7A1424(void);
void func_8038FF48_7A15F8(void);
void func_8039264C_7A3CFC(void);
void func_80395074_7A6724(s32 arg0);
void func_80395088_7A6738(Gfx **arg0, s16 ulx, s16 uly, s16 lrx, s16 lry, u8 color);
void func_803951BC_7A686C(Gfx **arg0, s16 arg1, s16 arg2, s16 arg3);
void func_80395314_7A69C4(Gfx **arg0, s16 arg1, s16 arg2, s16 arg3);
void func_8039546C_7A6B1C(Gfx **arg0, s16 arg1, s16 arg2, s16 arg3);
void func_80395480_7A6B30(void);
void func_80395854_7A6F04(void);
void func_80395B58_7A7208(void);
void func_80395E98_7A7548(Gfx **arg0);
void func_803960F4_7A77A4(Gfx **arg0);
void func_8039661C_7A7CCC(s16 arg0, s16 arg1, s16 arg2);
s32  func_80396714_7A7DC4(void);
s32  func_80396748_7A7DF8(void);

// overlay2_7A8A50
void func_803973A0_7A8A50(s16);
void func_803976E0_7A8D90(void);
void func_80397734_7A8DE4(s16 arg0, u8 arg1);
void func_80397C58_7A9308(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s16 arg7, u8 arg8);

// overlay2_7A9CE0
void func_80398630_7A9CE0(void);
void func_8039884C_7A9EFC(void);
void func_8039895C_7AA00C(void);
void func_80398A00_7AA0B0(void);
void func_8039BE98_7AD548(u8 arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, struct052 *arg6, s16 arg7, s16 arg8, f32 arg9, u8 argA);
// void func_8039BE98_7AD548(u8, u8, u8, u8, u8, u8, s32, s32, s32, f32, u8);
void func_8039C5F8_7ADCA8(s16 arg0, s16 arg1, f32 arg2, void *arg3, s16 arg4);
void func_8039C834_7ADEE4(Gfx *arg0, s32 arg1, u16 arg2, u16 arg3, f32 arg4, f32 arg5, u8 arg6, u8 arg7, u16 arg8, u16 arg9);
f32  func_8039CDE8_7AE498(f32 arg0, f32 arg1);
void func_8039CE38_7AE4E8(Gfx **arg0);
void func_8039D034_7AE6E4(Gfx **arg0, s16 arg1);
void render_stars(Gfx **arg0);
void generate_stars(void);
void seconds_to_mins_secs(const s16 seconds, s16 *mins, s16 *secs) ;
void func_8039DBC8_7AF278(void);
s32  func_8039DCC0_7AF370(s16 arg0);

#endif
