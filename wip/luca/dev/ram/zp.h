// NES MK1 v1.0
// Copyleft Mojon Twins 2013, 2015, 2017, 2018

// zp

// Avoid parameters using these in critical functions.

unsigned char _x, _y, _n, _t;

// General, all-purpose variables

unsigned char i, pad_this_frame, gpit, gpjt, gpitu, gpaux;
signed int rds16;

const unsigned char *gp_gen, *gp_tmap, *gp_tma2;
unsigned char *gp_ram, *gp_ram_aux;
unsigned int gp_addr;
unsigned char rdx, rdy, rdt, rdit;
unsigned char rda, rdb, rdc, rdd, rdm;
signed char rds;
unsigned char rdct;
unsigned char ticker;

// Used for two-points collision

unsigned char at1, at2, cx1, cx2, cy1, cy2, caux;
#if PLAYER_COLLISION_VSTRETCH_BG > 0
	unsigned char cy3, at3;
#endif

// Sprite related

unsigned char oam_index, oam_index_aux;

// Enemies

unsigned char en_initial;
unsigned char en_offs;

unsigned char en_fr;
unsigned char en_collx, en_colly;
unsigned char en_spr;
unsigned char touched;
unsigned char en_cttouched [3], en_flags [3], en_is_alive;
unsigned char pregotten;

unsigned char _en_t, _en_s;
unsigned char _en_x, _en_y;
unsigned char _en_x1, _en_y1, _en_x2, _en_y2;
signed char _en_mx, _en_my;
unsigned char _en_ct, _en_facing;
signed int _enf_x, _enf_y, _enf_vx, _enf_vy;

unsigned char en_life [3], en_alive [3], en_status [3], en_rawv [3], en_ct [3];

#ifdef ENEMS_RECOIL_ON_HIT
	signed char en_rmx [3];
	#ifdef PLAYER_TOP_DOWN
		signed char en_rmy [3];
	#endif
#endif

#ifdef ENABLE_COMPILED_ENEMS
	const unsigned char *en_behptr [3];
#endif

// Main player

signed int px, py, pvx, pvy;
unsigned char prx, pry;
unsigned char pfacing, pfr, pctfr, psprid;
unsigned char a_button, b_button;

#ifdef PLAYER_TOP_DOWN
	unsigned char pfacinghlast;
#endif

unsigned char pj, pctj, pjb, pgotten, ppossee, psprint;
unsigned char pstate, pctstate;
unsigned char phit;
signed int pgtmx, pgtmy;

#if defined (ENABLE_EASY_OBJECTS) || defined (ENABLE_ONLY_ONE_OBJECT)
	unsigned char pinv, opinv;
#endif

#ifdef ENABLE_LADDERS
	unsigned char ponladder, phalfladder;
	unsigned char ponladderctr;
#endif

#ifdef PLAYER_TOP_DOWN
	unsigned char pfacingv, pfacingh;
#endif

unsigned char wall, hitv, hith;

#ifdef PLAYER_CAN_FLOAT
	unsigned char pfloating;
#endif

#if defined (PLAYER_STEPS_ON_ENEMS) || defined (PLAYER_CAN_FIRE) || defined (FANTY_KILLED_BY_TILE)
	unsigned char pkilled;
#endif

unsigned char prx_old, pry_old;
unsigned char pobjs;
unsigned char plife, pcontinues;
unsigned char pkill;
unsigned char pice;
unsigned char pnotsafe;

#ifndef DEACTIVATE_KEYS
	unsigned char pkeys;
#endif

unsigned char pammo, pfiring;

#ifdef PLAYER_TURRET
	unsigned char pfixct;
#endif

#ifdef DIE_AND_RESPAWN
	unsigned char n_pant_safe;
	signed int px_safe, py_safe;
#endif

#ifdef PLAYER_PUNCHES
	unsigned char ppunching;
#endif

#ifdef PLAYER_KICKS
	unsigned char pkicking;
#endif

#if defined (PLAYER_PUNCHES) || defined (PLAYER_KICKS)
	unsigned char phitterx, phittery;
	unsigned char phitteract;
	unsigned char pfrozen;
#endif

// Bullets

#ifdef PLAYER_CAN_FIRE
	unsigned char bi;
#endif

// Cocos

#ifdef ENABLE_COCOS
	unsigned char coco_it;
#endif

// Hotspots
unsigned char hrx, hry, hrt;

// Process breakable?
#ifdef BREAKABLE_ANIM
	unsigned char do_process_breakable;
#endif

unsigned char ft;

// Current level

unsigned char c_map_w;

const unsigned char *c_ts_pals;
const unsigned char *c_ts_tmaps;
const unsigned char *c_behs;

const unsigned char * const *spr_enems;

const unsigned char *c_pal_bg;
const unsigned char *c_pal_fg;

#ifdef MAP_FORMAT_PACKED
	const unsigned char *c_map;
#endif
#if defined (MAP_FORMAT_RLE16) || defined (MAP_FORMAT_RLE53)
	const unsigned char * const *c_map;
#endif
#if defined (MAP_FORMAT_CHRROM)
	const unsigned int *c_map;
	unsigned char c_map_chr_rom_bank;
#endif
	
#ifdef MAP_WITH_DECORATIONS
	const unsigned char * const *c_decos;
#endif

const unsigned char *c_locks;

#ifdef ENEMS_IN_CHRROM
	unsigned int c_enems;
	unsigned int c_hotspots;
#else
	const unsigned char *c_enems;
	const unsigned char *c_hotspots;
#endif

unsigned char c_max_bolts;

#ifdef ACTIVATE_SCRIPTING
	unsigned char sc_x, sc_y, sc_n, sc_c;
	unsigned char *next_script;
	unsigned char *script;
	unsigned char script_result, sc_terminado, sc_continuar;
#endif
	