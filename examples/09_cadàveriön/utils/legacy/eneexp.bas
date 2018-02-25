' ene exporter (old)
' generates minimal contents for usage in small ROMs.

sub usage
	print "$ eneexp2 enems.ene out.h prefix"
End Sub

Dim As Integer fIn, fOut
Dim As uByte d, a, b
Dim As String Dummy, prefix
Dim As Integer mapW, mapH, nEnems, mapPants, nPant, i, j, hl, calcx,calcy
Dim As uByte t, xy1, xy2, mn, x1, y1, x2, y2, mx, my
Dim As Integer typeCounters (255)

If Command (3) = "" Then usage: End
prefix = Command (3)

' Outputs 4 bytes per entry
' T for type
' XY for ini
' XY for end
' MN for properties

' .ENE contains...
' t x1 y1 x2 y2 n s1 s2
' n is speed
' s1, s2 are unused.

fIn = FreeFile
Open Command (1) For Binary As #fIn
fOut = FreeFile
Open Command (2) For Output As #fOut

' Skip header
dummy = Input (256, fIn)
Get #fIn, , d: mapW = d
Get #fIn, , d: mapH = d
Get #fIn, , d: Get #fIn, , d
Get #fIn, , d: nEnems = d

mapPants = mapW * mapH

Print #fOut, "// " & Command (2)
Print #fOut, "// Generated by enexp.exe"
Print #fOut, "// Copyleft 2015 The Mojon Twins"
Print #fOut, ""
Print #fOut, "// Enems structure is {X1 Y1 X2 Y2 MX MY T} x " & nEnems & " x MAP_W x MAP_H"
Print #fOut, "// MX, MY are encoded weirdly and awkwardly: real value = value - 8"
Print #fOut, "const unsigned char enems_" & prefix & " [] = {"

hl = 0
For i = 1 To (mapPants * nEnems)
	Get #fIn, , t
	Get #fIn, , a: Get #fIn, , b
	x1 = a*16: y1 = b*16
	Get #fIn, , a: Get #fIn, , b
	x2 = a*16: y2 = b*16
	Get #fIn, , mn
	Get #fIn, , d: Get #fIn, , d

	calcx = mn * sgn (x2 - x1)
	calcy = mn * sgn (y2 - y1)

	mx = calcx+8
	my = calcy+8	

	If hl = 0 Then Print #fOut, "	";
	'Print #fOut, "0x" & Hex (t, 2) & ", 0x" & Hex (xy1, 2) & ", 0x" & Hex (xy2, 2) & ", 0x" & Hex (mn, 2);
	Print #fOut, "" & x1 & ", " & y1 & ", " & x2 & ", " & y2 & ", " & mx & ", " & my & ", " & t;
	If i < (mapPants * nEnems) Then Print #fOut, ", "
	
Next i
Print #fOut, ""
Print #fOut, "};"
Print #fOut, ""
Print #fOut, "// Hotspots structure is {XY T} x MAP_W x MAP_H"
Print #fOut, "const unsigned char hotspots_" & prefix & " [] = {"
hl = 0
For i = 1 To mapPants
	Get #fIn, , xy1
	Get #fIn, , xy2
	xy1 = (xy1 Shl 4) Or (xy2 And 15)
	Get #fIn, , t
	if hl = 0 Then Print #fOut, "	";
	'Print #fOut, "0x" & Hex (t, 2) & ", 0x" & Hex (xy1, 2);
	Print #fOut, "" & xy1 & ", " & t;
	If i < mapPants Then Print #fOut, ", "
	
	typeCounters (t) = typeCounters (t) + 1
Next i
Print #fOut, ""
Print #fOut, "};"
Print #fOut, ""

For i = 0 To 255
	If typeCounters (i) <> 0 then
		' Print #fOut, "// Wrote " & typecounters (i) & " hotspots of type " & i
		Print #fOut, "#define MAX_HOTSPOTS_TYPE_" & i & "_" & prefix & "	" & typeCounters (i)	
	End If
Next i

Close fIn, fOut