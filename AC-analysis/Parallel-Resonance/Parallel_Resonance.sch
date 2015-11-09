*version 9.1 657536080
u 150
V? 3
R? 2
C? 4
L? 4
? 22
I? 2
@libraries
@analysis
.AC 1 1 0
+0 100k
+1 1n
+2 5k
.TRAN 0 0 0 0
+0 1us
+1 10ms
@targets
@attributes
@translators
a 0 u 13 0 0 0 hln 100 PCBOARDS=PCB
a 0 u 13 0 0 0 hln 100 PSPICE=PSPICE
a 0 u 13 0 0 0 hln 100 XILINX=XILINX
@setup
unconnectedPins 0
connectViaLabel 0
connectViaLocalLabels 0
NoStim4ExtIFPortsWarnings 1
AutoGenStim4ExtIFPorts 1
@index
pageloc 1 0 2134 
@status
n 0 115:10:10:01:42:14;1447087334 e 
s 2832 115:10:10:01:42:14;1447087334 e 
*page 1 0 970 720 iA
@ports
port 62 AGND 410 300 h
@parts
part 123 c 500 250 v
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C3
a 0 ap 9 0 15 0 hln 100 REFDES=C3
a 0 u 13 0 15 25 hln 100 VALUE=0.001
part 122 L 450 260 v
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L3
a 0 ap 9 0 15 0 hln 100 REFDES=L3
a 0 u 13 0 15 25 hln 100 VALUE=0.00001
part 3 R 410 250 v
a 0 sp 0 0 0 10 hlb 100 PART=R
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=5
part 145 IAC 360 210 h
a 0 sp 0:11 0 0 50 hln 100 PART=IAC
a 0 a 0:13 0 0 0 hln 100 PKGREF=I1
a 1 ap 9 0 20 10 hcn 100 REFDES=I1
a 0 u 13 0 -8 22 hcn 100 ACMAG=0.2A
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 137 nodeMarker 410 180 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=L3:2
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=21
@conn
w 107
a 0 up 0:33 0 0 0 hln 100 V=
s 500 300 450 300 108
s 450 300 410 300 127
s 450 260 450 300 125
s 500 300 500 250 128
s 410 250 410 300 143
s 360 300 360 250 73
s 410 300 360 300 63
a 0 up 33 0 385 299 hct 100 V=
w 7
a 0 up 0:33 0 0 0 hln 100 V=
s 500 220 500 180 130
s 500 180 450 180 132
a 0 up 33 0 475 179 hct 100 V=
s 450 180 450 200 134
s 410 180 450 180 142
s 410 180 410 210 140
s 360 180 360 210 8
s 360 180 410 180 138
@junction
j 410 300
+ s 62
+ w 107
j 450 260
+ p 122 1
+ w 107
j 450 300
+ w 107
+ w 107
j 500 250
+ p 123 1
+ w 107
j 500 220
+ p 123 2
+ w 7
j 450 200
+ p 122 2
+ w 7
j 410 210
+ p 3 2
+ w 7
j 410 250
+ p 3 1
+ w 107
j 360 250
+ p 145 -
+ w 107
j 360 210
+ p 145 +
+ w 7
j 410 180
+ w 7
+ w 7
j 410 180
+ p 137 pin1
+ w 7
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
