#ifndef FUNCTIONS_H
#define FUNCTIONS_H


unsigned long long __ull_rshift(unsigned long long a0, unsigned long long a1);
unsigned long long __ull_rem(unsigned long long a0, unsigned long long a1);
unsigned long long __ull_div(unsigned long long a0, unsigned long long a1);
unsigned long long __ll_lshift(unsigned long long a0, unsigned long long a1);
long long __ll_rem(unsigned long long a0, long long a1);
long long __ll_div(long long a0, long long a1);
unsigned long long __ll_mul(unsigned long long a0, unsigned long long a1);
void __ull_divremi(unsigned long long *div, unsigned long long *rem, unsigned long long a2, unsigned short a3);
long long __ll_mod(long long a0, long long a1);

// core/string.c
u16  strlen_sssv(u8 *s);
void strcat(u8 *dst, u8 *src);
void strcpy(u8 *dst, u8 *src);
void strncpy(u8 *dst, u8 *src, s16 num);
s32  strcmp(u8 *str1, u8 *str2);
void bzero_sssv(u8 *addr, s32 len);
s32 *memset_words(s32* dst, s32 c, u32 len);
u8  *memset_bytes(u8 *dst, u8 c, u32 len);
u16  rand(void);
u8  *memcpy_sssv(u8 *src, u8 *dst, u32 len);

// main_4910.c
void read_rom_header(void);
void set_region(void);
void dma_read(u8 *devAddr, void *vAddr, s32 nbytes);

// main_4A00
void load_segments(Gfx **arg0, DisplayList *ddl);

// main_51D0
void init(void);
void clear_framebuffer(void);
void end_display_lists(void);

// thread6
void thread6(s32);
void thread7(void);
void end_display_lists(void);
void no_controller_message(void);

// tv
void set_tv_mode_widescreen(void);
void set_tv_mode_normal(void);
void draw_rectangle(Gfx **dl, s16 x0, s16 y0, s16 x1, s16 y1, u8 r, u8 g, u8 b, u8 a);

// main_7770.c
void load_overlay(u8);

// main_78F0
void load_default_display_list(Gfx**);
void set_menu_text_color(u8 r, u8 g, u8 b, u8 a);
void select_font(u8, u8, u8, u8);
void select_comic_sans_font(void);
void select_lcd_font(void);
u8   convert_text_to_int(s16 *arg0);
void draw_glyph(Gfx **arg0, s16 *arg1, u16 x, u16 y, f32 width, f32 height);
s16 display_text_wrapped(Gfx **dl, s16 *text, u16 xStart, u16 yStart, f32 fontWidth, f32 fontHeight, u16 maxWidth, u8 lineHeight);
void load_glyph(Gfx **arg0, s16 arg1);
void display_score(Gfx **arg0, u8 *arg1, u16 x_offset, u16 y_offset);
void prepare_text(u8 *src, s16 *dst);
s16  load_level_text_data(s16 language, s16 level, u16 *msg_lengths, s16 *dst);
s16* get_message_address_by_id(s16 arg0); // load message id
s16  get_raw_message_length(s16 *arg0);

void display_text_centered(Gfx **, s16*, u16, u16, f32, f32);
void display_text(Gfx **, s16*, u16, u16, f32, f32);

// core/fontinit.c
void font_init(void);

// core/eeprom.c
s16  write_eeprom(s16 arg0);
s32  read_eeprom(s16 slot);
s32  eeprom_checksum(u8 *arg0);

// core/audiomgr
void initialise_audio(s32*);
struct017 *get_sound_by_slot(s16 slot);
struct017 *get_sound_by_id(u16 id);
s16  get_used_sound_count(void);
void play_sound_effect(s16 id, s16 arg1, s16 volume, f32 pitch, u8 pan);
void play_sound_by_id_with_volume(u8 id, s16 vol);
void play_sound_by_id(u8 id);
void play_sound_by_slot(s16 slot);
void stop_all_sounds(void);
void set_sfx_volume(s16 arg0);
void set_music_volume(s16 arg0);
void load_sequence(s32 seqArrayIndex, s8 destIndex);
s32  get_seqp_state(s8 arg0);

// main_10CB0
void init2(void);
void thread1(void);

// main_10DC0
void draw_sprite(Gfx **dl, uSprite *sprite, u16 width, u16 height, u16 scale_x, u16 scale_y, u8 flip_x, u8 flip_y, u16 p_screen_x, u16 p_screen_y, u8 depth);
void draw_chunked_image(u32 startX, u32 startY, u32 width, u32 height, Gfx **dl, u8 *img);

// main_123E0.c
s32  init_controllers(void);
void thread9(void);
void do_rumble(s16, s16, s16, s16, s32);

// overlay1_6384F0.c
void black_out_screen(Gfx **dl);

// overlay1_63C660
s16 language_select_menu(s16 arg0);

// overlay2_6A6500.c
s32  get_evo_suit_color(void);

// overlay2_6AB090.c
void set_fog_factor_and_color(Gfx **dl, u8 r, u8 g, u8 b);
void set_fog_position_and_color(Gfx **dl);

// overlay2_6AC360
s16  distance_from_player(s16 x, s16 z, s16 y);

// overlay2_6D9330
Animal2 *spawn_animal(s16 x, s16 z, s16 y, s16 rotation, s16 health, s16 id, s8 arg6);

// overlay2_6D9AF0
struct071 *spawn_object(u8 id, s16 x, s16 z, s16 y, s32 xVel, s32 zVel, s32 yVel, s16 zRotation, s16 yRotation, u16 scale);

// overlay2_6DCA10
s32  create_particle_effect(s32 x, s32 z, s32 y, s16 id, s32, s32, s32, s16 size, u16 color1, u16 color2, u16); // TBD

// sssv/animals/fox (overlay2_6F66B0)
void fire_fox_fire_missile(Animal *animal);
void fox_warp(void);

// sssv/animals/flying_dog (overlay2_6FBEA0)
void racing_dog_fire_missile(Animal *animal);
void dog_bite(void);
void flying_dog_fire_gun(s32 arg0, s32 arg1, s32 arg2);
void flying_dog_drop_bomb(s32 arg0, s32 arg1, s32 arg2);
void racing_dog_turbo(s16 arg0);

// sssv/animals/hippo (overlay2_700770)
void drop_sticky_mine(void);
void hippo_spit(s32 arg0, s32 arg1, s32 arg2);

// overlay2_701E80
void reset_screen_transition(void);
void trigger_screen_transition(s16 arg0);
void perform_screen_transition(void);

// sssv/animals/lion (overlay2_702DE0)
void lion_roar(void);

// overlay2_7041D0
void add_multiple_lights(void);
void add_single_light(Gfx** dl);

// overlay2_7070A0
void fire_homing_missile(s16 x, s16 z, s16 y, s16 arg3, s16 rotation, Animal* target, s16 arg6, s16 arg7, f32 scale, s16 lifetime, s16 argA, s16 xVel, s16 zVel, s16 yVel, Animal* owner);
void spawn_temporary_object(s16 x, s16 z, s16 y, s16 scale, u8 lifetime, Animal *owner, s16 arg6, u8 id);

// sssv/animals/rabbit (overlay2_7118C0)
void heli_rabbit_drop_bomb(s32 arg0, s32 arg1, s32 arg2);

// sssv/animals/frog
void frog_croak(void);

// overlay2_716900
void animal_jump(void);

// sssv/animals/parrot
void parrot_fly(void);

// overlay2_725D10
void set_game_state(Animal *arg0, s16 arg1, s32 arg2);
s32 get_game_state(Animal *arg0, s32 arg1);

// overlay2_72B100
u16  get_closest_waypoint_index(WaypointData *arg0, s16 x, s16 z, s16 y);

// overlay2_72C680
u32  get_uncompressed_size(u8 *arg0);
s32  get_compressed_size(u8 *arg0);
s32  copy_or_extract(u8 *src, u8 *dst, s32 unused);
void load_level_data(u8);
void load_level_data_sections(void);

// sssv/animals/mouse (overlay2_72DE50)
void racing_mouse_turbo(s16 arg0);

// overlay2_732A60
void apply_recoil(s16 arg0);

// overlay2_739290.c
void load_animal(s16 id);
void check_and_set_species_encountered(s16 arg0);
void set_species_as_encountered(s16);
void play_sound_effect_at_location(s16 id, s16 volume, s16 arg2, s16 x, s16 y, s16 z, f32 pitch);

// overlay2_73EA30
void vector_add(Vertex *x, Vertex *y, Vertex *res);
void vector_subtract(Vertex *x, Vertex *y, Vertex *res);
void vector_multiply_by(Vertex *x, f32 c, Vertex *res);
void vector_divide_by(Vertex *x, f32 c, Vertex *res);
f32  get_magnitude(Vertex *v);
void normalize_vector(Vertex *x, Vertex *res);
f32  dot_product(Vertex *x, Vertex *y);
void cross_product(Vertex *x, Vertex *y, Vertex *res);
s16  get_angle_between_vectors(Vertex *x, Vertex *y);

// sssv/camera.c
void fix_camera_to_angle_offset(u8 id, f32 angle);

// sssv/osd.c
void show_osd(void);
void hide_osd(void);
void osd_draw_timer(s16 arg0);

// overlay2_76D850
void load_ingame_objects(void); // load display list segment
void load_water_texture(void); // load water texture?

// tortoise
void racing_tortoise_turbo(s16 arg0);

// overlay2_767AC0
void load_1_tile(u8 *tlut, u8 *timg);
void load_2_tiles(u8 *tlut1, u8 *tlut2, u8 *timg);
void load_3_tiles(u8 *tlut1, u8 *tlut2, u8 *tlut3, u8 *arg3);

// sssv/animals/hyena (overlay2_768B90)
void biker_hyena_fire_missile(Animal *animal);

// overlay2_76F7D0
void recharge_skill(s16 arg0);

// sssv/animals/rat
void rat_drop_mine(void);
void rat_bite(void);
void king_rat_bugel_call(s16 arg0);
void king_rat_fart(s16 arg0);

// sssv/animals/sheep
void ram_headbutt(void);

// overlay2_7741B0
s32 can_swim(Animal *a);
s32 water_hurts(Animal *a);
s32 can_fly(Animal *a);

// sssv/animals/penguin (overlay2_775E30)
void penguin_throw_snowball(Animal *arg0);

// sssv/animals/polar_bear (overlay2_7775C0)
void polar_tank_drop_mine(void);
void polar_tank_fire_cannon(void);
void polar_bear_jump_thump(void);

// sssv/animals/husky (overlay2_77A480)
void ski_husky_fire_missile(Animal *arg0);
void ski_husky_turbo(s16 arg0);

// sssv/animals/camel (overlay2_77EDB0)
void cannon_camel_fire_cannon(Animal *arg0);

// sssv/animals/walrus (overlay2_786320)
void walrus_fire_missile(Animal * arg0);
void walrus_turbo(s16 arg0);

// sssv/animinit.c
void load_data_section(u8 arg0);

// sssv/credits (overlay2_79CEF0)
void reset_credits_counters(void);
s32  display_credits(void);

// sssv/cheats.c
void reset_cheats(void);
void check_cheats(OSContPad *contPad);
s32  check_cheat_code(const u8 *buttonPresses, const char *cheatCode);

// overlay2_794EE0
void perform_behavior_armed_desert_fox(void);
void perform_behavior_bear_attacking(void);
void perform_behavior_bear(void);
void perform_behavior_boxing_kangaroo(void);
void perform_behavior_camel(void);
void perform_behavior_cannon_camel(void);
void perform_behavior_chameleon(void);
void perform_behavior_cod(void);
void perform_behavior_cool_cod(void);
void perform_behavior_crazy_husky(void);
void perform_behavior_crow_diver(void);
void perform_behavior_crow(void);
void perform_behavior_desert_fox(void);
void perform_behavior_dog(void);
void perform_behavior_elephant(void);
void perform_behavior_evo(void);
void perform_behavior_fire_fox(void);
void perform_behavior_flying_dog(void);
void perform_behavior_fox(void);
void perform_behavior_frog(void);
void perform_behavior_gorilla(void);
void perform_behavior_hard_mouse(void);
void perform_behavior_heli_mouse(void);
void perform_behavior_heli_rabbit(void);
void perform_behavior_hippo(void);
void perform_behavior_husky(void);
void perform_behavior_hyena_biker(void);
void perform_behavior_hyena(void);
void perform_behavior_king_penguin(void);
void perform_behavior_king_rat(void);
void perform_behavior_lion(void);
void perform_behavior_mouse(void);
void perform_behavior_mouse2(void);
void perform_behavior_mystery_bear(void);
void perform_behavior_parrot_attacking(void);
void perform_behavior_parrot(void);
void perform_behavior_penguin(void);
void perform_behavior_pirana(void);
void perform_behavior_pogo_kangaroo(void);
void perform_behavior_polar_bear_defending(void);
void perform_behavior_polar_bear(void);
void perform_behavior_polar_tank(void);
void perform_behavior_rabbit(void);
void perform_behavior_racing_dog(void);
void perform_behavior_racing_fox(void);
void perform_behavior_racing_hippo(void);
void perform_behavior_racing_mouse(void);
void perform_behavior_racing_tortoise_defending(void);
void perform_behavior_racing_tortoise(void);
void perform_behavior_ram(void);
void perform_behavior_rat(void);
void perform_behavior_scorpion(void);
void perform_behavior_seagull(void);
void perform_behavior_seagull2(void);
void perform_behavior_sheep(void);
void perform_behavior_ski_husky(void);
void perform_behavior_sneaky_chameleon(void);
void perform_behavior_springy_ram(void);
void perform_behavior_springy_thingy(void);
void perform_behavior_tortoise_tank_defending(void);
void perform_behavior_tortoise_tank(void);
void perform_behavior_vulture(void);
void perform_behavior_vulture2(void);
void perform_behavior_walrus(void);

// overlay2_7A0DA0
void trigger_pause_menu(void);
void trigger_mission_brief_screen(void);
void trigger_level_failed(void);
void load_demo_level(s16 arg0);
void load_intro(void);
void load_pause_menu(s32 arg0, s16 arg1);
void load_mission_brief_screen(s16 vertical_offset);
void render_tv_body(Gfx **arg0, s16 arg1, s16 arg2, s16 arg3);
void render_tv_glass(Gfx **arg0, s16 arg1, s16 arg2, s16 arg3);
void render_spaceship_interior(Gfx **arg0);

// overlay2_7A9CE0
void get_player_progress(PlayerEeprom *e, s16 *arg1);
void determine_available_levels(void);
void render_stars(Gfx **arg0);
void generate_stars(void);
void determine_available_levels(void);
s16  get_next_available_level(s16 current_level, s16 offset);
void seconds_to_mins_secs(const s16 seconds, s16 *mins, s16 *secs);
void load_level_title(void);
s16  get_biome_for_level(s16 arg0);
void display_zone_select_screen(void);

// trails
void reset_trails(void);
Trail *add_regular_trail(Animal *arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB, u8 argC, u8 argD, u8 argE, u8 argF, u8 arg10, u8 arg11, s32 arg12);
Trail *add_walrus_wake(Animal *arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB, u8 argC, u8 argD, u8 argE, s32 argF);
Trail *add_simple_trail(Animal *arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB, u8 argC, u8 argD);
void display_trails(void);

#endif
