mus_title_module:
	.word @chn0,@chn1,@chn2,@chn3,@chn4,music_instruments
	.byte $09

@chn0:
@chn0_loop:
@chn0_0:
	.byte $4d,$2b,$80,$2b,$28,$81,$2b,$45,$2b,$4d,$2b,$28,$81,$2b,$80,$2b
	.byte $28,$80,$28,$26,$45,$26,$4d,$26,$28,$81,$28,$29,$2b,$29,$87,$24
	.byte $80,$24,$80,$1f,$21,$24,$80,$26,$80,$24,$80
@chn0_1:
	.byte $2b,$80,$2b,$28,$81,$2b,$45,$2b,$4d,$2b,$28,$81,$2b,$80,$2b,$28
	.byte $80,$28,$26,$45,$26,$4d,$26,$28,$81,$28,$29,$2b,$29,$87,$24,$80
	.byte $24,$80,$1f,$21,$24,$80,$26,$80,$24,$80
@chn0_2:
	.byte $4c,$1f,$21,$1f,$24,$26,$2b,$29,$28,$24,$26,$80,$28,$1f,$21,$1f
	.byte $24,$26,$2b,$29,$28,$24,$26,$80,$24,$8b,$2d,$80,$2b,$80,$24,$80
	.byte $1f,$80,$21,$21,$24,$80
@chn0_3:
	.byte $1f,$21,$1f,$24,$26,$2b,$29,$28,$24,$26,$80,$28,$1f,$21,$1f,$24
	.byte $26,$2b,$29,$28,$24,$26,$80,$24,$8b,$2d,$80,$2b,$80,$24,$80,$1f
	.byte $80,$21,$21,$24,$80
	.byte $fe
	.word @chn0_loop

@chn1:
@chn1_loop:
@chn1_0:
	.byte $45,$1c,$81,$18,$81,$13,$81,$18,$81,$1c,$81,$18,$81,$13,$81,$18
	.byte $81,$1a,$81,$15,$81,$1a,$81,$11,$81,$11,$81,$18,$81,$15,$81,$18
	.byte $81
@chn1_1:
	.byte $1c,$81,$18,$81,$13,$81,$18,$81,$1c,$81,$18,$81,$13,$81,$18,$81
	.byte $1a,$81,$15,$81,$1a,$81,$11,$81,$11,$81,$18,$81,$15,$81,$18,$81
@chn1_2:
	.byte $24,$28,$2b,$24,$28,$2b,$24,$28,$2b,$24,$28,$2b,$26,$29,$2d,$26
	.byte $29,$2d,$26,$29,$2d,$26,$29,$2d,$24,$29,$2d,$24,$29,$2d,$24,$29
	.byte $2d,$24,$29,$2d,$26,$2b,$2f,$26,$2b,$2f,$26,$2b,$2f,$26,$2b,$2f
@chn1_3:
	.byte $ff,$30
	.word @chn1_2
	.byte $fe
	.word @chn1_loop

@chn2:
@chn2_loop:
@chn2_0:
	.byte $44,$0c,$81,$0c,$81,$0c,$81,$13,$11,$10,$0c,$81,$0c,$81,$0c,$81
	.byte $13,$11,$10,$0e,$81,$0e,$81,$0e,$81,$13,$11,$10,$11,$81,$11,$81
	.byte $11,$81,$13,$11,$10
@chn2_1:
	.byte $0c,$81,$0c,$81,$0c,$81,$13,$11,$10,$0c,$81,$0c,$81,$0c,$81,$13
	.byte $11,$10,$0e,$81,$0e,$81,$0e,$81,$13,$11,$10,$11,$81,$11,$81,$11
	.byte $81,$13,$11,$10
@chn2_2:
	.byte $0c,$0c,$0c,$0c,$0c,$0c,$0c,$0c,$0c,$0c,$0c,$0c,$0e,$0e,$0e,$0e
	.byte $0e,$0e,$0e,$0e,$0e,$0e,$0e,$0e,$11,$11,$11,$11,$11,$11,$11,$11
	.byte $11,$11,$11,$11,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13
@chn2_3:
	.byte $ff,$30
	.word @chn2_2
	.byte $fe
	.word @chn2_loop

@chn3:
@chn3_loop:
@chn3_0:
	.byte $44,$00,$80,$00,$48,$00,$80,$44,$00,$00,$00,$00,$48,$00,$80,$44
	.byte $00,$00,$80,$00,$48,$00,$80,$44,$00,$00,$00,$00,$48,$00,$00,$00
	.byte $44,$00,$80,$00,$48,$00,$80,$44,$00,$00,$00,$00,$48,$00,$80,$44
	.byte $00,$00,$80,$00,$48,$00,$80,$44,$00,$00,$00,$00,$48,$00,$00,$00
@chn3_1:
	.byte $ff,$30
	.word @chn3_0
@chn3_2:
	.byte $ff,$30
	.word @chn3_0
@chn3_3:
	.byte $ff,$30
	.word @chn3_0
	.byte $fe
	.word @chn3_loop

@chn4:
@chn4_loop:
@chn4_0:
	.byte $af
@chn4_1:
	.byte $af
@chn4_2:
	.byte $af
@chn4_3:
	.byte $af
	.byte $fe
	.word @chn4_loop
