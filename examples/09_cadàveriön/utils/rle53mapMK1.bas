Const SCR_W = 16
Const SCR_H = 12

Const STATE_REP = 1
Const STATE_STRING = 2

Sub usage
	Print "Usage:"
	Print 
	Print "$ rle53mapMK1.exe in.map out.h w h tlock prefix [offset] [scrsizes] [nodecos]"
End Sub

Function even (i As Integer) As Integer 
	Return ((i And 1) = 0)
End Function

Function inCommand (a As String) As Integer
	Dim As Integer i
	i = 1
	While (Command (i) <> "")
		If Command (i) = a Then Return -1
		i = i + 1
	Wend
	Return 0
End Function

Dim As Integer x, y, xx, yy, nPant, mapW, mapH, i, j, dat, f, mapsize, decosize, scrsize, founddecos
Dim As Integer printscrsizes, nodecos, offset
Dim As Integer mapWtiles, mapPants, tLock, locksI, state, tileStrI, decoT, decoCt, XYct
Dim As Integer counter, totalBytes
Dim As String o, prefix
Dim As uByte d, dp
'Redim As uByte m (0, 0)
'Redim As uByte decos (0, 0), decosI (0)
'Redim As uByte mOut (0, 0), mOutI (0)
Dim As uByte locks (63), tilestr (32)

' Sorry, but this is acting weird
Dim As uByte m (127, SCR_W * SCR_H - 1)
Dim As uByte decos (127, 127)
Dim As uByte decosXY (127, 127), XY (127)
Dim As uByte decosO (127, 127)
Dim As uByte decosI (127)
Dim As uByte decosOI (127)
Dim As uByte mOut (127, SCR_W * SCR_H - 1)
Dim As uByte mOutI (127)
Dim As String cMapAmalgam (127)
Dim As Integer scrSizes (127)
Dim As Integer scrMaps (127)
Dim As Integer screensum, n, cMapI, realPant, ctr

Print "MK1 v1.0 rle53mapMK1 ~ ";

If Command (6) = "" Then usage: End

mapW = Val (Command (3))
mapH = Val (Command (4))
mapWtiles = mapW * SCR_W
mapPants = mapW * mapH
tLock = Val (Command (5))
prefix = Command (6)

'printscrsizes = (Command (7) = "printscrsizes" Or Command (8) = "printscrsizes")
'nodecos = (Command (7) = "nodecos" Or Command (8) = "nodecos")
printscrsizes = inCommand ("scrsizes")
nodecos = inCommand ("nodecos")

For i = 7 To 9
	If Val (Command (i)) Then offset = Val (Command (i))
Next i
If offset Then Print "Offset " & offset & " ~ ";

' Read map to big array
'Redim m (mapPants - 1, SCR_W * SCR_H - 1)
' Max 64 decos as per screen
'Redim decos (mapPants - 1, 127)
'Redim decosI (mapPants - 1)
'Redim mOut (mapPants - 1, SCR_W * SCR_H - 1)
'Redim mOutI (mapPants - 1)

' Reset indexes (not needed, but good practice).
For i = 0 To mapPants - 1
	decosI (i) = 0
	decosOI (i) = 0
	mOutI (i) = 0
	cMapAmalgam (i) = ""
Next i
locksI = 0

Print "Reading MAP (" & (maph*SCR_H*mapw*SCR_W) & " bytes) ~ ";

f = Freefile
Open Command (1) For Binary as #f
i = 0: dp = 0

founddecos = 0
While Not Eof (f)
	' Read from file
	Get #f, , d
	' Offset
	d = d - offset
	' Screen coordinates
	xx = (i \ SCR_W) Mod  mapW
	yy = i \ (SCR_W * SCR_H * mapW)
	' Tile coordinates
	x = i Mod SCR_W
	y = (i \ mapWtiles) Mod SCR_H
	' screen number
	nPant = xx + yy * mapW
	' Is d a decoration' 
	If d >= 32 Then
		' Write to decos
		If Not founddecos Then 
			founddecos = -1
			Print "Found decos ~ ";
		End If
		decosXY (nPant, decosI (nPant)) = x * 16 + y
		decos (nPant, decosI (nPant)) = d
		decosI (nPant) = decosI (nPant) + 1
		' Reset to previous (so there's more repetitions)
		d = dp
	End If
	' Is d a lock' 
	If d = tLock Then
		locks (locksI) = nPant: locksI = locksI + 1
		locks (locksI) = y * 16 + x: locksI = locksI + 1
	End if
	' Write to big array
	m (nPant, x + y * SCR_W) = d
	' Previous one
	dp = d
	' Counter
	i = i + 1
Wend
Close #f

' Process screens

Print "Compressing ~ ";
totalBytes = 0
For nPant = 0 To mapPants - 1
	d = m (nPant, 0): n = 1: cMapI = 0
	cMapAmalgam (nPant) = ""
	screensum = 0
	For i = 1 To SCR_W*SCR_H-1
		screensum = screensum + m (nPant, i)
		' Different: write, substitute
		If m (nPant, i) <> d Or n = 8 Then
			mOut (nPant, cMapI) = (d And 31) Or ((n - 1) Shl 5)
			'?Hex (mOut (nPant, cMapI), 2) & " ";
			cMapAmalgam (nPant) = cMapAmalgam (nPant) & Hex (mOut (nPant, cMapI), 2)
			cMapI = cMapI + 1
			n = 0
		End If
		d = m (nPant, i): n = n + 1
	Next i
	mOut (nPant, cMapI) = (d And 31) Or ((n - 1) Shl 5)
	'?Hex (mOut (nPant, cMapI), 2) & " ";
	cMapAmalgam (nPant) = cMapAmalgam (nPant) & Hex (mOut (nPant, cMapI), 2)
	cMapI = cMapI + 1

	realPant = nPant

	' Detect empty screen
	If screensum = 0 Then 
		realPant = 255: cMapI = 0
	Else
		' Search for repeated screens
		For j = 0 To nPant - 1
			If cMapAmalgam (j) = cMapAmalgam (nPant) Then
				realPant = j
				cMapI = 0
				Exit For
			End If
		Next j
	End If

	scrSizes (nPant) = cMapI
	scrMaps (nPant) = realPant '' Fixe here
	totalBytes = totalBytes + cMapI
Next nPant

' Process decos
If founddecos And Not nodecos Then 
	For nPant = 0 To mapPants - 1
		If decosI (nPant) Then
			For i = 0 To decosI (nPant) - 1
				decoT = decos (nPant, i)
				If decoT <> &Hff Then
					decoCT = 1
					XY (0) = decosXY (nPant, i)
					' Find more:
					For j = i + 1 To decosI (nPant) - 1
						If decos (nPant, i) = decos (nPant, j) Then
							' Found! DESTROY!
							XY (decoCT) = decosXY (nPant, j)
							decoCT = decoCT + 1
							decos (nPant, j) = &Hff
						End If
					Next j
					If decoCT = 1 Then
						' T | 128, XY
						decosO (nPant, decosOI (nPant)) = decoT Or 128: decosOI (nPant) = decosOI (nPant) + 1
						decosO (nPant, decosOI (nPant)) = XY (0): decosOI (nPant) = decosOI (nPant) + 1
					Else
						' T N XY XY XY XY...
						decosO (nPant, decosOI (nPant)) = decoT: decosOI (nPant) = decosOI (nPant) + 1
						decosO (nPant, decosOI (nPant)) = decoCT: decosOI (nPant) = decosOI (nPant) + 1
						For j = 0 To decoCT - 1
							decosO (nPant, decosOI (nPant)) = XY (j): decosOI (nPant) = decosOI (nPant) + 1
						Next j
					End If
				End If
			Next i
		End If
	Next nPant
End If

' Write output
f = Freefile
Open Command (2) For Output As #f
Print #f, "// rle53mapMK1(TM) map " & Command (2)
Print #f, "// Generated by rle53mapMK1.exe"
Print #f, "// Copyleft 2015, 2017, 2018 The Mojon Twins"
Print #f, ""
Print #f, "// Map Size Is " & mapW & "x" & mapH
Print #f, "// Screen Size Is " & SCR_W & "x" & SCR_H
Print #f, ""

mapsize = 0

' Write screens
Print #f, "// Compressed map structure, screens in RLE53, byte = NNNNNRRR, repeat R times tile #N"
Print #f, ""
For nPant = 0 To mapPants - 1
	If scrMaps (nPant) = 255 Then
		Print #f, "// Screen " & Lcase (Hex (nPant, 2)) & " is empty."
	ElseIf scrSizes (nPant) Then
		Print #f, "const unsigned char scr_" & prefix & "_" & Lcase (Hex (nPant, 2)) & " [] = {";
		For i = 0 To scrSizes (nPant) - 1
			Print #f, "0x" & Lcase (Hex (mOut (nPant, i), 2));
			If i < scrSizes (nPant) - 1 Then Print #f, ", ";
		Next i
		Print #f, "};"
		If printscrsizes Then Print #f, "// Size = " & scrSizes (nPant) & " bytes."
		mapsize = mapsize + scrSizes (nPant)
	Else
		Print #f, "// Screen " & Lcase (Hex (nPant, 2)) & " is a copy of screen " & Lcase (Hex (scrMaps (nPant), 2)) & "."
	End If
Next nPant
Print #f, ""

' Write map index
Print #f, "// Compressed map array"
Print #f, ""
Print #f, "const unsigned char * const map_" & prefix & " [] = {"
ctr = 0
For nPant = 0 To mapPants - 1
	If ctr = 0 Then Print #f, "	";
	If scrMaps (nPant) = 255 Then
		Print #f, Space (Len ("scr_" & prefix & "_")) & " 0";
	Else
		Print #f, "scr_" & prefix & "_" & Lcase (Hex (scrMaps (nPant), 2));
	Endif
	If nPant < mapPants - 1 Then Print #f, ", ";
	ctr = ctr + 1: If ctr = mapW And nPant < mapPants - 1 Then ctr = 0: Print #f, ""
	mapsize = mapsize + 2
Next nPant
Print #f, ""
Print #f, "};"
Print #f, ""
Print #f, "// Total map size in bytes is " & mapsize
Print #f, ""

Print "Wrote MAP (" & mapsize & " bytes) ~ ";

' Write decos
If founddecos And Not nodecos Then 
	decosize = 0
	Print #f, "// Decorations"
	Print #f, "// Format: [T N XY XY XY XY... (T < 128) | T XY (T >= 128)]"
	Print #f, ""
	For nPant = 0 To mapPants - 1
		If decosOI (nPant) Then
			Print #f, "const unsigned char map_" & prefix & "_decos_" & Lcase (Hex (nPant, 2)) & " [] = { ";
			For i = 0 To decosOI (nPant) - 1
				Print #f, "0x" & Lcase (Hex (decosO (nPant, i), 2)) & ", " ;
				decosize = decosize + 1
			Next i
			Print #f, "0x00 }; "
		End If
	Next nPant
	Print #f, ""
	Print #f, "const unsigned char * const map_" & prefix & "_decos [] = {"
	For y = 0 To mapH - 1
		Print #f, "	";
		For x = 0 To mapW - 1
			nPant = x + y * mapW
			If decosOI (nPant) Then
				Print #f, "map_" & prefix & "_decos_" & Lcase (Hex (nPant, 2));
			Else 
				Print #f, "0";
			End If
			decosize = decosize + 2
			If x < mapW - 1 Or y < mapH - 1 Then Print #f, ", ";
		Next x
		Print #f, ""
	Next y
	Print #f, "};"
	Print #f, ""
	Print #f, "// Total decorations size in bytes is " & decosize
	Print #f, ""

	Print "Wrote decos (" & decosize & " bytes) ~ ";
End If

' Write locks
If locksI Then
	Print #f, "// Locks"
	Print #f, "// Format: NP YX ..."
	print #f, ""
	Print #f, "#define N_BOLTS_" & Ucase (prefix) & " " & (locksI \ 2)
	print #f, ""
	Print #f, "const unsigned char map_" & prefix & "_locks [] = {"
	Print #f, "	";
	For i = 0 To locksI - 1
		Print #f, "0x" & Lcase (Hex (locks (i), 2));
		If i < locksI - 1 Then Print #f, ", ";
	Next i
	Print #f, ""
	Print #f, "};"
	Print #f, ""
else
	Print #f, "#define N_BOLTS_" & Ucase (prefix) & " 0"	
End If

Print "Wrote locks (" & locksI & " bytes) ~ ";

' Exit cleanly
Close #f
Erase m, decos, decosI

Print " DONE!"
