// NES MK1 v0.7
// Copyleft Mojon Twins 2013, 2015, 2016

// hotspots.h
// Hotspot management

void hotspots_load (void) {
	// Copies hotspots from ROM to RAM and initializes them
	gp_gen = (unsigned char *) c_hotspots;
	for (gpit = 0; gpit < MAP_W * MAP_H; gpit ++) {
#ifndef HOTSPOTS_WONT_CHANGE
		ht [gpit] = *gp_gen ++;
		hxy [gpit] = *gp_gen ++;
		gp_gen ++;
#endif
		hact [gpit] = 1;
	}	
}

// v1.0: Simple. Modify/expand when needed.
void hotspots_create (void) {
	hrt = 0;

#ifndef HOTSPOTS_WONT_CHANGE
	if (ht [n_pant] && hact [n_pant]) {
		if (hact [n_pant]) {
			hrt = ht [n_pant];
		} 
	}

	if (hrt) {
		hrx = (hxy [n_pant] >> 4) << 4;
		hry = (hxy [n_pant] & 15) << 4;

		oam_meta_spr (hrx, hry + SPRITE_ADJUST, OAM_HOTSPOTS, spr_hs [hrt]);
	}	
#else
	gp_gen = (unsigned char *) c_hotspots; gp_gen += (n_pant << 1);
	rdb = *gp_gen ++; rda = *gp_gen; 
	if (rdb && hact [n_pant]) {
		hrt = rdb;
		hrx = rda & 0xf0; hry = rda << 4;
		oam_meta_spr (hrx, hry + SPRITE_ADJUST, OAM_HOTSPOTS, spr_hs [hrt]);
	} else oam_meta_spr (0, 240, OAM_HOTSPOTS, spr_empty);
#endif
}
