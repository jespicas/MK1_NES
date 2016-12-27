// NES MK1 v0.6
// Copyleft Mojon Twins 2013, 2015

// frame.h
// Custom game frame

const unsigned char game_frame [] = {
	 64,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  68,  65,
	 69,   0,   3,  29,  16,  16,   0,   0,   0,   0,   0,   0,   0,   0,   4,  29,  16,  16,   0,   0,   0,   0,   0,   0,   0,   0,   5,  29,  16,  16,   0,  71,
	 66,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  67
};

void __fastcall__ draw_game_frame (void) {
	vram_write ((unsigned char *) game_frame, 0x2360, 96);
	for (rdit = 0; rdit < 16; rdit ++) attr_table [48 + rdit] = 0x00;
	vram_adr (0x2343);
	vram_put (10);
	vram_adr (0x235c);
	vram_put (11);
}
