// NES MK1 v1.0
// Copyleft Mojon Twins 2013, 2015, 2017, 2018

// Use this alongisde map_renderer_complex.h
// (#define MAP_RENDERER_COMPLEX)

// Reaching this point, map_buff has the decompressed map screen.
// You can write as many modifications as you like here:

set_rand (1 + n_pant);

if (level == 2) {
	rda = n_pant & 1;
	gp_gen = bgs [level] + (rda << 7) + (rda << 6);
} else if (level == 3) {
	gp_gen = bgs [level];
}

gpit = 192; while (gpit --) {
	rda = map_buff [gpit];

	// Add 16 to
	if (rand8 () & 1) {
		if (
			(level < 2 && rda == 0)
			|| (level < 3 && rda == 1)
			|| (level == 2 && (rda == 4 || rda == 6 || rda == 9 || rda == 10 || rda == 14))
			|| (level == 4 && (rda == 3 || rda == 10 || rda == 12))
		) rda += 16;

		switch (level) {
			case 0:
			case 1:
				if (rda == 21 && map_buff [gpit - 16] != 21) rda = 22;
				break;
			case 2:
				if (rda == 8 && map_buff [gpit - 16] != 8) rda = 24;
			case 3:
				if (rda == 0) rda = gp_gen [gpit];
				break;
			case 4:
				if (rda == 15 && map_buff [gpit - 1] == 15) rda = 31;
				if (rda == 14 && map_buff [gpit - 16] != 14) rda = 30;
				break;
		}

	map_buff [gpit] = rda;
}

// Level 0 stuff
if (level == 0) {
	// Clear gate if already talked to Amador
	if (n_pant == 5 && level0_gate) {
		map_buff [0x94] = 0;
		map_buff [0xA4] = 0;
	} else if (n_pant == 11) {
		map_buff [0x9D] = 41;
		map_buff [0x9E] = 42;
		map_buff [0xAD] = 43;
		map_buff [0xAE] = 44;
	}
}

// Clear gate if all objects in place
if (level == 1 && n_pant == 6 && level1_gate) {
	map_buff [0x4E] = 22; 
	map_buff [0x5E] = 21;
}
