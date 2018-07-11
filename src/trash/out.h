// NES MK1 v1.0
// Copyleft Mojon Twins 2013, 2015, 2017, 2018

// out.h - Script pools and scripts interpreter
// generated by mscMK1 1.1 by the Mojon Twins

const unsigned char script_pool_0 [] = {
/*            0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F */
/* 0000 */ 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 0001 */ 0x1e, 0x10, 0x01, 0x02, 0xff, 0x14, 0x01, 0x02, 0x14, 0x01, 0x02, 0x14, 0x01, 0x02, 0x15, 0x01, 
/* 0002 */ 0x15, 0x01, 0x15, 0x01, 0x15, 0x01, 0x15, 0x01, 0x10, 0x01, 0x82, 0x10, 0x01, 0x02, 0xff, 0x2d, 
/* 0003 */ 0x63, 0x82, 0x63, 0x82, 0xff, 0x10, 0x02, 0x02, 0x51, 0x09, 0x21, 0x3f, 0x5f, 0x51, 0x0a, 0x14, 
/* 0004 */ 0x1e, 0x28, 0xe3, 0x10, 0x48, 0x4f, 0x4c, 0x41, 0x2c, 0x20, 0x44, 0x4f, 0x4e, 0x20, 0x50, 0x45, 
/* 0005 */ 0x50, 0x49, 0x54, 0x4f, 0x00, 0xe3, 0x04, 0x48, 0x4f, 0x4c, 0x41, 0x00, 0xff, 0xff
};

const unsigned char * const script_pool [] = {
    script_pool_0
};

#ifdef CLEAR_FLAGS
void msc_clear_flags (void) {
    memfill (flags, 0, MAX_FLAGS);
}
#endif

unsigned char read_byte (void) {
    return *script ++;
}

unsigned char read_vbyte (void) {
    sc_c = *script ++;
    if (sc_c & 128) return flags [sc_c & 127];
    return sc_c;
}

void readxy (void) {
    sc_x = read_vbyte ();
    sc_y = read_vbyte ();
}

void run_script (unsigned char whichs) {
    // read address offset from index
    gp_gen = (unsigned char *) script_pool [level] + (whichs << 1);
    rda = *gp_gen ++; rdb = *gp_gen;
    script_result = 0;
    if (!(rda | rdb)) return;
    script = (unsigned char *) script_pool [level] + rda + (rdb << 8);

    while ((sc_c = read_byte ()) != 0xff) {
        next_script = script + sc_c;
        sc_terminado = sc_continuar = 0;
        while (!sc_terminado) {
            switch (read_byte ()) {
                case 0x10: readxy (); sc_terminado = (flags [sc_x] != sc_y); break;
                case 0x63: sc_terminado = (script_arg != read_byte ()); break;
                case 0xff: sc_terminado = sc_continuar = 1; break;
            }
        }

        if (sc_continuar) {
            fire_script_success = 1;
            sc_terminado = 0;
            while (!sc_terminado) {
                switch (read_byte ()) {
                    case 0x51: f_zone_ac = 1; fzx1 = read_byte (); fzy1 = read_byte (); fzx2 = read_byte (); fzy2 = read_byte (); break;
                    case 0x10: readxy (); flags [sc_x] += sc_y; break;
                    case 0x14: readxy (); rda = flags [sc_x]; flags [sc_x] = flags [sc_y]; flags [sc_y] = rda; break;
                    case 0x15: sc_x = read_vbyte (); flags [sc_x] = 1 - flags [sc_x]; break;
                    case 0xe3: _x = LINE_OF_TEXT_X; _y = LINE_OF_TEXT; gp_gen = script; sc_n = read_byte (); script += (sc_n + 1); pr_ul_str (); break;
                    case 0xff: sc_terminado = 1; break;
                }
            }
        }
        script = next_script;
    }
}