			// Hotspot interaction
			if (hrt) {
				if (hrt == HOTSPOT_TYPE_RESONATOR) {
					if (res_on == 0) {
						if (prx + 12 >= hrx && prx <= hrx + 12 && pry + 15 >= hry && pry + 8 <= hry && pvy >= PLAYER_G << 1) {
							pvy = -PLAYER_VY_JUMP_MAX;

							// res_on, start ct...
							res_on = 1; 
							res_ct = 9;
							res_subct = 50;

							// Black and white, blueish.
							//ppu_mask (0x9f);
							pal_bg (mypal_bw);

							// Change sprite to "active"
							oam_meta_spr (hrx, hry + SPRITE_ADJUST, 176, spr_hs [3]);

							sfx_play (1, 1);
						}
					}
				} else if (collide_in (prx + 8, pry + 8, hrx, hry)) {
					oam_meta_spr (0, 240, 176, spr_empty);
					switch (hrt) {
#ifndef DEACTIVATE_OBJECTS
						case HOTSPOT_TYPE_OBJECT:
							pobjs ++;
							sfx_play (3, 1);
							break;
#endif
#ifndef DEACTIVATE_KEYS
						case HOTSPOT_TYPE_KEYS:
							pkeys ++;
							sfx_play (2, 1);
							break;
#endif
						case HOTSPOT_TYPE_REFILL:
							plife += PLAYER_REFILL;
							if (plife > PLAYER_LIFE) plife = PLAYER_LIFE;
							sfx_play (3, 1);
							break;
#ifdef MAX_AMMO
						case HOTSPOT_TYPE_AMMO:
							sfx_play (2, 1);
							if (MAX_AMMO - pammo > AMMO_REFILL)
								pammo += AMMO_REFILL;
							else
								pammo = MAX_AMMO;
							break;
#endif
						case HOTSPOT_TYPE_STAR:
							pstars ++;
							sfx_play (3, 1);
							
							pal_bg (mypal_flash);
							pal_spr (mypal_black);
							
							clear_update_list ();
							ppu_waitnmi ();
							ppu_waitnmi ();
							ppu_waitnmi ();
							ppu_waitnmi ();
							
							// Fanfare [TODO]
							
							pal_bg (c_pal_bg);
							pal_spr (c_pal_fg);
							
							res_on = 0;
							
							clear_update_list (); update_index = 0;
							if (pstars == 3) {
								pr_str_upd ("       EXTRA CONTINUE!");
								pcontinues ++;
							} else {
								pr_str_upd ("     WOW! IS THIS MAGIC?");
							}

							break;
					}
					hry = 240;
					hact [n_pant] = 0;
				}
			}
			