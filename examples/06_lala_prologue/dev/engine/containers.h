// NES MK1 v0.7
// Copyleft Mojon Twins 2013, 2015, 2016

void containers_init (void) {
	last_container = 0;
}

void containers_add (unsigned char x, unsigned char y, unsigned char f) {
	c_x [last_container] = x;
	c_y [last_container] = y;
	c_f [last_container ++] = f;
}

void containers_do (void) {
	rdx = (prx + 8) >> 4; rdy = (pry + 8) >> 4;
	gpit = last_container; while (gpit --) {
		if (ppossee && rdx == c_x [gpit] && rdy == c_y [gpit]){
			pvx = pvy = 0;
			upd_cont_index = c_f [gpit];
			use_ct = 1;
		}
	}
}

void containers_draw (void) {
	gpit = last_container; while (gpit --) {
		oam_meta_spr (c_x [gpit] << 4, (c_y [gpit] << 4) + SPRITE_ADJUST, 
			OAM_CONTAINERS + (gpit << 4),
			spr_hs [flags [c_f [gpit]]]);
	}
}
