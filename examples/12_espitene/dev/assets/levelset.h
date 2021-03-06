
// Initial screen & position, per level

const unsigned char l_scr_ini [] = 				{ 
													20, 0, 0, 	// Benny Hill Zone
													15, 24, 0, 	// Broken Fridge Zone
													19, 15, 2, 	// Bosque de Badajoz Zone
													0, 0, 0,	// Wet Ruins Zone
													15, 20, 0,  // Crap Brain Zone
													15, 19, 0, 	// Ola K Ase Zone
												};
const unsigned char l_ini_x [] = 				{ 
													3, 2, 3,	// Benny Hill Zone
													2, 12, 3, 	// Broken Fridge Zone
													3, 3, 3,	// Bosque de Badajoz Zone
													2, 3, 3, 	// Wet Ruins Zone
													3, 3, 3, 	// Crap Brain Zone
													3, 3, 3, 	// Ola K Ase Zone
												};
const unsigned char l_ini_y [] = 				{ 	
													3, 3, 3,	// Benny Hill Zone
													3, 3, 3,	// Broken Fridge Zone
													3, 3, 3, 	// Bosque de Badajoz Zone
													6, 6, 6, 	// Wet Ruins Zone
													3, 3, 3,	// Crap Brain Zone
													3, 3, 3, 	// Ola K Ase Zone
												};
const unsigned char l_map_w [] = 				{ 
													MAP_00_W, MAP_01_W, MAP_02_W,	// Benny Hill Zone 
													MAP_10_W, MAP_11_W, MAP_12_W,	// Broken Fridge Zone
													MAP_20_W, MAP_21_W, MAP_22_W,	// Bosque de Badajoz Zone
													MAP_30_W, MAP_31_W, MAP_32_W,	// Wet Ruins Zone
													MAP_40_W, MAP_41_W, MAP_42_W,	// Crap Brain Zone
													MAP_50_W, MAP_51_W, MAP_52_W,	// Ola K Ase Zone
												};
const unsigned char l_map_h [] = 				{
													MAP_00_H, MAP_01_H, MAP_02_H,	// Benny Hill Zone
													MAP_10_H, MAP_11_H, MAP_12_H, 	// Broken Fridge Zone
													MAP_20_H, MAP_21_H, MAP_22_H, 	// Bosque de Badajoz Zone
													MAP_30_H, MAP_31_H, MAP_32_H, 	// Wet Ruins Zone
													MAP_40_H, MAP_41_H, MAP_42_H,	// Crap Brain Zone
													MAP_50_H, MAP_51_H, MAP_52_H,	// Ola K Ase Zone
												};

// Ending screen & position, per level (comment if N/A)

/*
const unsigned char l_scr_end [] = 				{ 0, 0 };
const unsigned char l_end_x [] = 				{ 3, 3 };
const unsigned char l_end_y [] = 				{ 3, 3 };
*/

// # of objects. 

const unsigned char l_player_max_objects [] =	{ 
													MAX_HOTSPOTS_TYPE_1_00, MAX_HOTSPOTS_TYPE_1_01, 0, 	// Benny Hill Zone
													MAX_HOTSPOTS_TYPE_1_10, MAX_HOTSPOTS_TYPE_1_11, 0, 	// Broken Fridge Zone
													MAX_HOTSPOTS_TYPE_1_20, MAX_HOTSPOTS_TYPE_1_21, 0, 	// Bosque de Badajoz Zone
													MAX_HOTSPOTS_TYPE_1_30, MAX_HOTSPOTS_TYPE_1_31, 0, 	// Wet Ruins Zone
													MAX_HOTSPOTS_TYPE_1_40, MAX_HOTSPOTS_TYPE_1_41, 0, 	// Crap Brain Zone
													MAX_HOTSPOTS_TYPE_1_50, MAX_HOTSPOTS_TYPE_1_51, 0, 	// Ola K Ase Zone
												};

// # of killable enemies 

const unsigned char l_player_max_enems [] = 	{ 
													KILLABLE_ENEMS_00, KILLABLE_ENEMS_01, 1, // Benny Hill Zone
													KILLABLE_ENEMS_10, KILLABLE_ENEMS_11, 1, // Broken Fridge Zone
													KILLABLE_ENEMS_20, KILLABLE_ENEMS_21, 1, // Bosque de Badajoz Zone
													KILLABLE_ENEMS_30, KILLABLE_ENEMS_31, 1, // Wet Ruins Zone
													KILLABLE_ENEMS_40, KILLABLE_ENEMS_41, 1, // Crap Brain Zone
													KILLABLE_ENEMS_50, KILLABLE_ENEMS_51, 1, // Ola K Ase Zone
												};

// Palettes

const unsigned char * const l_pal_bg [] = 		{ 
													palts0, palts0, palts0,  // Benny Hill Zone
													palts1, palts1, palts1,  // Broken Fridge Zone
													palts2, palts2a, palts2, // Bosque de Badajoz Zone
													palts3, palts3, palts3,	 // Wet Ruins Zone	
													palts4, palts4, palts4a, // Crap Brain Zone
													palts5, palts5b, palts5c,  // Ola K Ase Zone
												};
const unsigned char * const l_pal_fg [] = 		{ 
													palss0, palss0, palss0,  // Benny Hill Zone
													palss1, palss1, palss0,  // Broken Fridge Zone
													palss0, palss0, palss0,	 // Bosque de Badajoz Zone
													palss0, palss0, palss0,  // Wet Ruins Zone
													palss0, palss0, palss2,  // Crap Brain Zone
													palss0, palss0, palss0,  // Ola K Ase Zone
												};

// Metatiles

const unsigned char * const l_ts_tmaps [] = 	{	
													ts0_tmaps, ts0_tmaps, ts0_tmaps, // Benny Hill Zone
													ts1_tmaps, ts1_tmaps, ts1_tmaps, // Broken Fridge Zone
													ts2_tmaps, ts2_tmaps, ts2_tmaps, // Bosque de Badajoz Zone
													ts3_tmaps, ts3_tmaps, ts3_tmaps, // Wet Ruins Zone
													ts4_tmaps, ts4b_tmaps, ts4_tmaps, // Crap Brain Zone
													ts5_tmaps, ts5b_tmaps, ts4_tmaps, // Ola K Ase Zone
												};
const unsigned char * const l_ts_pals [] = 		{ 
													ts0_pals, ts0_pals, ts0_pals, // Benny Hill Zone
													ts1_pals, ts1_pals, ts1_pals, // Broken Fridge Zone
													ts2_pals, ts2_pals, ts2_pals, // Bosque de Badajoz Zone
													ts3_pals, ts3_pals, ts3_pals, // Wet Ruins Zone
													ts4_pals, ts4b_pals, ts4_pals, // Crap Brain Zone
													ts5_pals, ts5b_pals, ts4_pals, // Ola K Ase Zone
												};
const unsigned char * const l_behs [] = 		{
													behs0, behs0, behs0, // Benny Hill Zone
													behs1, behs1, behs1, // Broken Fridge Zone
													behs2, behs2, behs2, // Bosque de Badajoz Zone
													behs3, behs3, behs3, // Wet Ruins Zone
													behs4, behs4b, behs4, // Crap Brain Zone
													behs5, behs5b, behs4, // Ola K Ase Zone
												};

// Enemy spriteset

const unsigned char * const * const l_spr_enems [] =
												{
													spr_enems1, spr_enems1, spr_enems1, // Benny Hill Zone
													spr_enems1, spr_enems1, spr_enems1, // Broken Fridge Zone
													spr_enems2, spr_enems2, spr_enems2, // Bosque de Badajoz Zone
													spr_enems3, spr_enems3, spr_enems3, // Wet Ruins Zone
													spr_enems4, spr_enems4, spr_enems4, // Crap Brain Zone
													spr_enems4, spr_enems4, spr_enems5, // Ola K Ase Zone
												};

// Map data

#ifdef MAP_FORMAT_PACKED
	const unsigned char * const l_map [] =		{ map_0, map_1 };
#endif
#if defined (MAP_FORMAT_RLE16) || defined (MAP_FORMAT_RLE53) || defined (MAP_FORMAT_RLE44)
	const unsigned char * const * const l_map [] =	
												{ map_0, map_1 };
#endif
#if defined (MAP_FORMAT_RLE53_CHRROM) || defined (MAP_FORMAT_RLE44_CHRROM)
	const unsigned char l_map_chr_rom_bank [] = { 
													MAP_00_CHRROM, MAP_01_CHRROM, MAP_02_CHRROM,  // Benny Hill Zone
													MAP_10_CHRROM, MAP_11_CHRROM, MAP_12_CHRROM,  // Broken Fridge Zone
													MAP_20_CHRROM, MAP_21_CHRROM, MAP_22_CHRROM,  // Bosque de Badajoz Zone
													MAP_30_CHRROM, MAP_31_CHRROM, MAP_32_CHRROM,  // Wet Ruins Zone
													MAP_40_CHRROM, MAP_41_CHRROM, MAP_42_CHRROM,  // Crap Brain Zone
													MAP_50_CHRROM, MAP_51_CHRROM, MAP_52_CHRROM,  // Ola K Ase Zone
												};
	const unsigned int * const l_map [] = 		{
													map_00_scr_offsets, map_01_scr_offsets, map_02_scr_offsets, // Benny Hill Zone
													map_10_scr_offsets, map_11_scr_offsets, map_12_scr_offsets, // Broken Fridge Zone
													map_20_scr_offsets, map_21_scr_offsets, map_22_scr_offsets, // Bosque de Badajoz
													map_30_scr_offsets, map_31_scr_offsets, map_32_scr_offsets, // Wet Ruins Zone
													map_40_scr_offsets, map_41_scr_offsets, map_42_scr_offsets, // Crap Brain Zone
													map_50_scr_offsets, map_51_scr_offsets, map_52_scr_offsets, // Ola K Ase Zone
												};
#endif

#ifdef MAP_WITH_DECORATIONS
	#if defined (MAP_FORMAT_PACKED) || defined (MAP_FORMAT_RLE16) 
		const unsigned char * const * const l_decos [] =
												{ map_0_decos, map_1_decos };
	#else
		// 0 = no decos in this level's map, 1 = decos.
		const unsigned char l_decos [] = 		{ 1, 1 };												
	#endif
#endif

#ifndef DEACTIVATE_KEYS
	const unsigned char * const l_locks [] = 	{ map_0_locks, map_1_locks };
	const unsigned char l_n_bolts [] = 			{ N_BOLTS_0, N_BOLTS_1 };
#endif

// Objects

#ifdef ENEMS_IN_CHRROM
	// change 'base_address' for the actual base address in CHR-ROM

	const unsigned char l_enems_chr_rombank [] = 	{ 
														1, 1, 1, // Benny Hill Zone
														1, 1, 1, // Broken Fridge Zone
														1, 1, 1, // Bosque de Badajoz Zone
														1, 1, 1, // Wet Ruins Zone
														1, 1, 1, // Crap Brain Zone
														3, 3, 3, // Ola K Ase Zone
													};
	const unsigned int l_enems [] = 				{ 
														4096 + WORK_ENEMS00_H_BIN_OFFS,	// Benny Hill Zone
														4096 + WORK_ENEMS01_H_BIN_OFFS,
														4096 + WORK_ENEMS02_H_BIN_OFFS,
														4096 + WORK_ENEMS10_H_BIN_OFFS,	// Broken Fridge Zone
														4096 + WORK_ENEMS11_H_BIN_OFFS,
														4096 + WORK_ENEMS12_H_BIN_OFFS,
														4096 + WORK_ENEMS20_H_BIN_OFFS,	// Bosque de Badajoz Zone
														4096 + WORK_ENEMS21_H_BIN_OFFS,
														4096 + WORK_ENEMS22_H_BIN_OFFS,
														4096 + WORK_ENEMS30_H_BIN_OFFS,	// Wet Ruins Zone
														4096 + WORK_ENEMS31_H_BIN_OFFS,
														4096 + WORK_ENEMS32_H_BIN_OFFS,
														4096 + WORK_ENEMS40_H_BIN_OFFS,	// Crap Brain Zone
														4096 + WORK_ENEMS41_H_BIN_OFFS,
														4096 + WORK_ENEMS42_H_BIN_OFFS,
														6144 + WORK_ENEMS50_H_BIN_OFFS,	// Ola K Ase Zone
														6144 + WORK_ENEMS51_H_BIN_OFFS,
														6144 + WORK_ENEMS52_H_BIN_OFFS,
													};
	const unsigned int l_hotspots [] = 				{ 
	 													4096 + WORK_ENEMS00_H_BIN_OFFS + HOTSPOTS_OFFSET_00, // Benny Hill Zone
														4096 + WORK_ENEMS01_H_BIN_OFFS + HOTSPOTS_OFFSET_01,
														4096 + WORK_ENEMS02_H_BIN_OFFS + HOTSPOTS_OFFSET_02,
														4096 + WORK_ENEMS10_H_BIN_OFFS + HOTSPOTS_OFFSET_10, // Benny Hill Zone
														4096 + WORK_ENEMS11_H_BIN_OFFS + HOTSPOTS_OFFSET_11,
														4096 + WORK_ENEMS12_H_BIN_OFFS + HOTSPOTS_OFFSET_12,
														4096 + WORK_ENEMS20_H_BIN_OFFS + HOTSPOTS_OFFSET_20, // Bosque de Badajoz Zone
														4096 + WORK_ENEMS21_H_BIN_OFFS + HOTSPOTS_OFFSET_21,
														4096 + WORK_ENEMS22_H_BIN_OFFS + HOTSPOTS_OFFSET_22,
														4096 + WORK_ENEMS30_H_BIN_OFFS + HOTSPOTS_OFFSET_30, // Wet Ruins Zone
														4096 + WORK_ENEMS31_H_BIN_OFFS + HOTSPOTS_OFFSET_31,
														4096 + WORK_ENEMS32_H_BIN_OFFS + HOTSPOTS_OFFSET_32,
														4096 + WORK_ENEMS40_H_BIN_OFFS + HOTSPOTS_OFFSET_40, // Crap Brain Zone
														4096 + WORK_ENEMS41_H_BIN_OFFS + HOTSPOTS_OFFSET_41,
														4096 + WORK_ENEMS42_H_BIN_OFFS + HOTSPOTS_OFFSET_42,
														6144 + WORK_ENEMS50_H_BIN_OFFS + HOTSPOTS_OFFSET_50, // Ola K Ase Zone
														6144 + WORK_ENEMS51_H_BIN_OFFS + HOTSPOTS_OFFSET_51,
														6144 + WORK_ENEMS52_H_BIN_OFFS + HOTSPOTS_OFFSET_52,
													};
#else
const unsigned char * const l_enems [] = 		{ enems_0, enems_1 };
const unsigned char * const l_hotspots [] = 	{ hotspots_0, hotspots_1 };
#endif

// CHR-ROM bank, for CNROM

#ifdef CNROM
	const unsigned char l_chr_rom_bank [] = 	{ 
													0, 0, 0, // Benny Hill Zone 
													0, 0, 0, // Broken Fridge Zone 
													0, 0, 0, // Bosque de Badajoz Zone 
													0, 0, 0, // Wet Ruins Zone
													0, 0, 0, // Crap Brain Zone
													0, 0, 0, // Ola K Ase Zone
												};
#endif

// Interactives

#if defined (ENABLE_INTERACTIVES) && defined (INTERACTIVES_FROM_CODE)
	const unsigned char * const l_interactives [] = 
												{ interactives0, interactives1 };
#endif

// Music track

const unsigned char l_music [] = 				{ 
													3, 3, 4, 
													2, 2, 4,
													1, 1, 4,
													0, 0, 4,
													3, 3, 4,
													1, 1, 4,
												};
