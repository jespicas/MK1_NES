// NES MK1 v0.5
// Copyleft Mojon Twins 2013, 2015

unsigned char i, gpit, gpjt, gpaux;
unsigned char half_life, frame_counter;

unsigned char n_pant, on_pant;

unsigned char *gp_gen, *gp_tmap;
unsigned int gp_addr;
unsigned char rdx, rdy, rdt, rdit;
unsigned char rda, rdb, rdc;
unsigned char rdct;

unsigned char olife, okeys, oobjs, oammo, okilled;

// Enemies
unsigned char en_x [3], en_y [3];
unsigned char en_x1 [3], en_y1 [3];
unsigned char en_x2 [3], en_y2 [3];
signed char en_mx [3], en_my [3];
unsigned char en_t [3], en_s [3], en_facing;
unsigned char en_life [3], en_alive [3], en_status [3], en_rawv [3], en_ct [3];
#ifdef ENABLE_GENERATORS
unsigned char en_generator_life [3], gen_was_hit [3];
#endif
unsigned char en_fr, etx1, etx2, ety1, ety2;
unsigned char en_collx, en_colly;
unsigned char touched;
unsigned char en_cttouched [3];
#if defined (ENABLE_FANTY) || defined (ENABLE_HOMING_FANTY)
signed int enf_x [3], enf_vx [3];
#endif
#if defined (ENABLE_FANTY) || defined (ENABLE_HOMING_FANTY) || defined (ENABLE_PEZONS)
signed int enf_y [3], enf_vy [3];
#endif

// Main player
signed int px, py, pvx, pvy;
unsigned char pfacing, pfr, pctfr, psprid;
#ifdef PLAYER_MOGGY_STYLE
unsigned char pfacinghlast;
#endif
unsigned char pj, pctj, pjb, pgotten, ppossee, psprint;
//#ifndef DEACTIVATE_OBJECTS
unsigned char pobjs;
//#endif
// CUSTOM {
unsigned char ppodewwwr;
unsigned char ppodewwwr_on;
unsigned char ppodewwwr_ct;
signed int player_vx_max;
// } END_OF_CUSTOM
unsigned char plife, pcontinues;
#ifndef DEACTIVATE_KEYS
unsigned char pkeys;
#endif
#ifdef PLAYER_STEPS_ON_ENEMIES
unsigned char pkilled;
#endif
unsigned char pammo, pfiring;
#ifdef PLAYER_TURRET
unsigned char pfixct;
#endif
unsigned char pushed_any;
unsigned char pstate, pctstate;
unsigned char phit;
signed int pgtmx, pgtmy;
#ifdef CARRY_ONE_HS_OBJ
unsigned char pinv;
#endif

// Aux player
unsigned char prx, pry, ptx1, ptx2, pty1, pty2;
#ifdef PLAYER:PLAYER_MOGGY_STYLE
unsigned char pfacingv, pfacingh;
#endif
unsigned char wall, hitv, hith;
#ifdef ENABLE_PROPELLERS
unsigned char ppropelled;
#endif

// Bullets
#ifdef PLAYER_CAN_FIRE
unsigned char bst [MAX_BULLETS], bx [MAX_BULLETS], by [MAX_BULLETS], bmx [MAX_BULLETS], bmy [MAX_BULLETS];
unsigned char btx, bty;
#endif

// Hotspots
unsigned char hrx, hry, hrt;

// Process breakable?
#ifdef BREAKABLE_ANIM
unsigned char do_process_breakable;
#endif

unsigned char ft;

// Gfx sets
//char **spr_enems, **spr_player;

// Level control

// Current level
unsigned char **c_map;
unsigned char **c_decos;
unsigned char *c_locks;
unsigned char *c_enems;
unsigned char *c_hotspots;
unsigned char *c_pal_bg;
unsigned char *c_pal_fg;

unsigned char *tileset_pals;
unsigned char *tsmap;

// KINDA CUSTOM {
unsigned char no_ct, use_ct, tt_ct, guay_ct;
// } END_OF_CUSTOM