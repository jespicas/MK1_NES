// NES MK1 v1.0
// Copyleft Mojon Twins 2013, 2015, 2017, 2018

// Add here your code. Just entered n_pant.
// Background is rendered, everything initialized.
// Screen is ON.

// Turn off ring if it is on
ring_timer = 0;

// Make bosses more resistant
gpit = 3; while (gpit --) if (en_t [gpit] == 0x14) en_life [gpit] = 8;