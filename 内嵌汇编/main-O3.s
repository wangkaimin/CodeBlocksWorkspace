   1              		.file	"main.c"
   2              		.intel_syntax noprefix
   3              	 # GNU C (GCC) version 4.5.3 (i686-pc-cygwin)
   4              	 #	compiled by GNU C version 4.5.3, GMP version 4.3.2, MPFR version 3.0.1-p4, MPC version 0.8
   5              	 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   6              	 # 传递的选项： -D__CYGWIN32__ -D__CYGWIN__ -Dunix -D__unix__ -D__unix
   7              	 # -idirafter /usr/lib/gcc/i686-pc-cygwin/4.5.3/../../../../include/w32api
   8              	 # -idirafter
   9              	 # /usr/lib/gcc/i686-pc-cygwin/4.5.3/../../../../i686-pc-cygwin/lib/../../include/w32api
  10              	 # main.c -march=core2 -mcx16 -msahf --param l1-cache-size=32 --param
  11              	 # l1-cache-line-size=64 --param l2-cache-size=1024 -mtune=core2
  12              	 # -masm=intel -g -fverbose-asm
  13              	 # 启用的选项： -falign-loops -fargument-alias -fauto-inc-dec
  14              	 # -fbranch-count-reg -fcommon -fdelete-null-pointer-checks
  15              	 # -fearly-inlining -feliminate-unused-debug-types -ffunction-cse -fgcse-lm
  16              	 # -fident -finline-functions-called-once -fira-share-save-slots
  17              	 # -fira-share-spill-slots -fivopts -fkeep-static-consts
  18              	 # -fleading-underscore -fmath-errno -fmerge-debug-strings
  19              	 # -fmove-loop-invariants -fpeephole -freg-struct-return
  20              	 # -fsched-critical-path-heuristic -fsched-dep-count-heuristic
  21              	 # -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
  22              	 # -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
  23              	 # -fsched-stalled-insns-dep -fshow-column -fsigned-zeros
  24              	 # -fsplit-ivs-in-unroller -ftrapping-math -ftree-cselim -ftree-forwprop
  25              	 # -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
  26              	 # -ftree-parallelize-loops= -ftree-phiprop -ftree-pta -ftree-reassoc
  27              	 # -ftree-scev-cprop -ftree-slp-vectorize -ftree-vect-loop-version
  28              	 # -funit-at-a-time -fvect-cost-model -fverbose-asm
  29              	 # -fzero-initialized-in-bss -m32 -m80387 -m96bit-long-double
  30              	 # -maccumulate-outgoing-args -malign-double -malign-stringops -mcx16
  31              	 # -mfancy-math-387 -mfp-ret-in-387 -mfused-madd -mieee-fp -mmmx
  32              	 # -mno-red-zone -mno-sse4 -mpush-args -msahf -msse -msse2 -msse3 -mssse3
  33              	 # -mstack-arg-probe
  34              	
  35              		.section	.debug_abbrev,"dr"
  36              	Ldebug_abbrev0:
  37              		.section	.debug_info,"dr"
  38              	Ldebug_info0:
  39              		.section	.debug_line,"dr"
  40              	Ldebug_line0:
  41 ???? 00000000 		.text
  41      02000000 
  41      00000101 
  41      FB0E0D00 
  41      01010101 
  42              	Ltext0:
  43              	 # Compiler executable checksum: 89d6774c1d510265da7d48b735ce61fb
  44              	
  45              		.section .rdata,"dr"
  46              	LC0:
  47 ???? 76616C31 		.ascii "val1:%d,val2:%d,val3:%d\12\0"
  47      3A25642C 
  47      76616C32 
  47      3A25642C 
  47      76616C33 
  48              	LC1:
  49 ???? 76616C31 		.ascii "val1:%d+val2:%d=val3:%d\12\0"
  49      3A25642B 
  49      76616C32 
  49      3A25643D 
  49      76616C33 
  50              		.text
  51              	.globl _test1
  53              	_test1:
  54              	LFB7:
  55              		.file 1 "main.c"
   1:main.c        **** #include <stdio.h>
   2:main.c        **** #include <stdlib.h>
   3:main.c        **** 
   4:main.c        **** void test1()
   5:main.c        **** {
  56              		.loc 1 5 0
  57 ???? 55       		push	ebp	 #
  58              	LCFI0:
  59 ???? 89E5     		mov	ebp, esp	 #,
  60              	LCFI1:
  61 ???? 83EC28   		sub	esp, 40	 #,
  62              	LCFI2:
   6:main.c        ****     /* val1+val2=val3 */
   7:main.c        **** 	unsigned int val1 = 1;
  63              		.loc 1 7 0
  64 ???? C745F401 		mov	DWORD PTR [ebp-12], 1	 # val1,
  64      000000
   8:main.c        **** 	unsigned int val2 = 2;
  65              		.loc 1 8 0
  66 ???? C745F002 		mov	DWORD PTR [ebp-16], 2	 # val2,
  66      000000
   9:main.c        **** 	unsigned int val3 = 0;
  67              		.loc 1 9 0
  68 ???? C745EC00 		mov	DWORD PTR [ebp-20], 0	 # val3,
  68      000000
  10:main.c        **** 	printf("val1:%d,val2:%d,val3:%d\n",val1,val2,val3);
  69              		.loc 1 10 0
  70 ???? 8B45EC   		mov	eax, DWORD PTR [ebp-20]	 # val3.2, val3
  71 ???? 8944240C 		mov	DWORD PTR [esp+12], eax	 #, val3.2
  72 ???? 8B45F0   		mov	eax, DWORD PTR [ebp-16]	 # tmp60, val2
  73 ???? 89442408 		mov	DWORD PTR [esp+8], eax	 #, tmp60
  74 ???? 8B45F4   		mov	eax, DWORD PTR [ebp-12]	 # tmp61, val1
  75 ???? 89442404 		mov	DWORD PTR [esp+4], eax	 #, tmp61
  76 ???? C7042400 		mov	DWORD PTR [esp], OFFSET FLAT:LC0	 #,
  76      000000
  77 ???? E8000000 		call	_printf	 #
  77      00
  11:main.c        **** 	asm volatile(
  78              		.loc 1 11 0
  79 ???? 8B45F4   		mov	eax, DWORD PTR [ebp-12]	 # tmp62, val1
  80 ???? 8B55F0   		mov	edx, DWORD PTR [ebp-16]	 # tmp63, val2
  81 ???? 89C1     		mov	ecx, eax	 #, tmp62
  82              	/APP
  83              	 # 11 "main.c" 1
  84              		movl $0,%eax
  85              		addl ecx,%eax	 #
  86              		addl edx,%eax	 # tmp63
  87              		movl %eax,DWORD PTR [ebp-20]	 # val3
  88              		
  89              	 # 0 "" 2
  12:main.c        **** 	"movl $0,%%eax\n\t" 	/* clear %eax to 0*/
  13:main.c        **** 	"addl %1,%%eax\n\t" 	/* %eax += val1 */
  14:main.c        **** 	"addl %2,%%eax\n\t" 	/* %eax += val2 */
  15:main.c        **** 	"movl %%eax,%0\n\t" 	/* val2 = %eax*/
  16:main.c        **** 	: "=m" (val3) 	        /* output =m mean only write output memory variable*/
  17:main.c        **** 	: "c" (val1),"d" (val2)	/* input c or d mean %ecx/%edx*/
  18:main.c        **** 	);
  19:main.c        **** 	printf("val1:%d+val2:%d=val3:%d\n",val1,val2,val3);
  90              		.loc 1 19 0
  91              	/NO_APP
  92 ???? 8B45EC   		mov	eax, DWORD PTR [ebp-20]	 # val3.3, val3
  93 ???? 8944240C 		mov	DWORD PTR [esp+12], eax	 #, val3.3
  94 ???? 8B45F0   		mov	eax, DWORD PTR [ebp-16]	 # tmp64, val2
  95 ???? 89442408 		mov	DWORD PTR [esp+8], eax	 #, tmp64
  96 ???? 8B45F4   		mov	eax, DWORD PTR [ebp-12]	 # tmp65, val1
  97 ???? 89442404 		mov	DWORD PTR [esp+4], eax	 #, tmp65
  98 ???? C7042400 		mov	DWORD PTR [esp], OFFSET FLAT:LC1	 #,
  98      000000
  99 ???? E8000000 		call	_printf	 #
  99      00
  20:main.c        **** }
 100              		.loc 1 20 0
 101 ???? C9       		leave
 102              	LCFI3:
 103 ???? C3       		ret
 104              	LFE7:
 105              		.section .rdata,"dr"
 106              	LC2:
 107 ???? 25642025 		.ascii "%d %d\12\0"
 107      640A00
 108              		.text
 109              	.globl _test2
 111              	_test2:
 112              	LFB8:
  21:main.c        **** void test2()
  22:main.c        **** {
 113              		.loc 1 22 0
 114 ???? 55       		push	ebp	 #
 115              	LCFI4:
 116 ???? 89E5     		mov	ebp, esp	 #,
 117              	LCFI5:
 118 ???? 83EC28   		sub	esp, 40	 #,
 119              	LCFI6:
  23:main.c        ****     int input,output,temp;
  24:main.c        ****     input = 1;
 120              		.loc 1 24 0
 121 ???? C745F401 		mov	DWORD PTR [ebp-12], 1	 # input,
 121      000000
  25:main.c        ****     __asm__ __volatile__ ("movl $0, %%eax;\n\t"
 122              		.loc 1 25 0
 123 ???? 8B55F4   		mov	edx, DWORD PTR [ebp-12]	 # tmp60, input
 124              	/APP
 125              	 # 25 "main.c" 1
 126              		movl $0, %eax;
 127              		movl %eax,DWORD PTR [ebp-20];	 # temp
 128              		movl edx,%eax;	 # tmp60
 129              		movl %eax,DWORD PTR [ebp-16];	 # output
 130              		
 131              	 # 0 "" 2
  26:main.c        ****                           "movl %%eax,%1;\n\t"
  27:main.c        ****                           "movl %2,%%eax;\n\t"
  28:main.c        ****                           "movl %%eax,%0;\n\t"
  29:main.c        ****                           :"=m"(output),"=m"(temp)
  30:main.c        ****                           :"r"(input)
  31:main.c        ****                           :"eax");
  32:main.c        ****     printf("%d %d\n",temp,output);
 132              		.loc 1 32 0
 133              	/NO_APP
 134 ???? 8B55F0   		mov	edx, DWORD PTR [ebp-16]	 # output.0, output
 135 ???? 8B45EC   		mov	eax, DWORD PTR [ebp-20]	 # temp.1, temp
 136 ???? 89542408 		mov	DWORD PTR [esp+8], edx	 #, output.0
 137 ???? 89442404 		mov	DWORD PTR [esp+4], eax	 #, temp.1
 138 ???? C7042400 		mov	DWORD PTR [esp], OFFSET FLAT:LC2	 #,
 138      000000
 139 ???? E8000000 		call	_printf	 #
 139      00
  33:main.c        **** }
 140              		.loc 1 33 0
 141 ???? C9       		leave
 142              	LCFI7:
 143 ???? C3       		ret
 144              	LFE8:
 146              	.globl _main
 148              	_main:
 149              	LFB9:
  34:main.c        **** int main()
  35:main.c        **** {
 150              		.loc 1 35 0
 151 ???? 55       		push	ebp	 #
 152              	LCFI8:
 153 ???? 89E5     		mov	ebp, esp	 #,
 154              	LCFI9:
 155 ???? 83E4F0   		and	esp, -16	 #,
 156              	LCFI10:
 157              		.loc 1 35 0
 158 ???? E8000000 		call	___main	 #
 158      00
  36:main.c        ****     test1();
 159              		.loc 1 36 0
 160 ???? E8000000 		call	_test1	 #
 160      00
  37:main.c        ****     test2();
 161              		.loc 1 37 0
 162 ???? E8000000 		call	_test2	 #
 162      00
  38:main.c        ****     return 0;
 163              		.loc 1 38 0
 164 ???? B8000000 		mov	eax, 0	 # D.4588,
 164      00
  39:main.c        **** }
 165              		.loc 1 39 0
 166 ???? C9       		leave
 167              	LCFI11:
 168 ???? C3       		ret
 169              	LFE9:
 170              		.section	.debug_frame,"dr"
 171              	Lframe0:
 172 ???? 00000000 		.long	LECIE0-LSCIE0
 173              	LSCIE0:
 174 ???? FFFFFFFF 		.long	0xffffffff
 175 ???? 01       		.byte	0x1
 176 ???? 00       		.ascii "\0"
 177 ???? 01       		.uleb128 0x1
 178 ???? 7C       		.sleb128 -4
 179 ???? 08       		.byte	0x8
 180 ???? 0C       		.byte	0xc
 181 ???? 04       		.uleb128 0x4
 182 ???? 04       		.uleb128 0x4
 183 ???? 88       		.byte	0x88
 184 ???? 01       		.uleb128 0x1
 185              		.align 4
 186              	LECIE0:
 187              	LSFDE0:
 188 ???? 00000000 		.long	LEFDE0-LASFDE0
 189              	LASFDE0:
 190 ???? 00000000 		.secrel32	Lframe0
 191 ???? 00000000 		.long	LFB7
 192 ???? 67000000 		.long	LFE7-LFB7
 193 ???? 41       		.byte	0x4
 194              		.long	LCFI0-LFB7
 195 ???? 0E       		.byte	0xe
 196 ???? 08       		.uleb128 0x8
 197 ???? 85       		.byte	0x85
 198 ???? 02       		.uleb128 0x2
 199 ???? 42       		.byte	0x4
 200              		.long	LCFI1-LCFI0
 201 ???? 0D       		.byte	0xd
 202 ???? 05       		.uleb128 0x5
 203 ???? 02       		.byte	0x4
 204 ???? 63       		.long	LCFI3-LCFI1
 205 ???? C5       		.byte	0xc5
 206 ???? 0C       		.byte	0xc
 207 ???? 04       		.uleb128 0x4
 208 ???? 04       		.uleb128 0x4
 209              		.align 4
 210              	LEFDE0:
 211              	LSFDE2:
 212 ???? 00000000 		.long	LEFDE2-LASFDE2
 213              	LASFDE2:
 214 ???? 00000000 		.secrel32	Lframe0
 215 ???? 00000000 		.long	LFB8
 216 ???? 2C000000 		.long	LFE8-LFB8
 217 ???? 41       		.byte	0x4
 218              		.long	LCFI4-LFB8
 219 ???? 0E       		.byte	0xe
 220 ???? 08       		.uleb128 0x8
 221 ???? 85       		.byte	0x85
 222 ???? 02       		.uleb128 0x2
 223 ???? 42       		.byte	0x4
 224              		.long	LCFI5-LCFI4
 225 ???? 0D       		.byte	0xd
 226 ???? 05       		.uleb128 0x5
 227 ???? 68       		.byte	0x4
 228              		.long	LCFI7-LCFI5
 229 ???? C5       		.byte	0xc5
 230 ???? 0C       		.byte	0xc
 231 ???? 04       		.uleb128 0x4
 232 ???? 04       		.uleb128 0x4
 233              		.align 4
 234              	LEFDE2:
 235              	LSFDE4:
 236 ???? 00000000 		.long	LEFDE4-LASFDE4
 237              	LASFDE4:
 238 ???? 00000000 		.secrel32	Lframe0
 239 ???? 00000000 		.long	LFB9
 240 ???? 1C000000 		.long	LFE9-LFB9
 241 ???? 41       		.byte	0x4
 242              		.long	LCFI8-LFB9
 243 ???? 0E       		.byte	0xe
 244 ???? 08       		.uleb128 0x8
 245 ???? 85       		.byte	0x85
 246 ???? 02       		.uleb128 0x2
 247 ???? 42       		.byte	0x4
 248              		.long	LCFI9-LCFI8
 249 ???? 0D       		.byte	0xd
 250 ???? 05       		.uleb128 0x5
 251 ???? 58       		.byte	0x4
 252              		.long	LCFI11-LCFI9
 253 ???? C5       		.byte	0xc5
 254 ???? 0C       		.byte	0xc
 255 ???? 04       		.uleb128 0x4
 256 ???? 04       		.uleb128 0x4
 257              		.align 4
 258              	LEFDE4:
 259              		.text
 260              	Letext0:
 261              		.section	.debug_loc,"dr"
 262              	Ldebug_loc0:
 263              	LLST0:
 264 ???? 00000000 		.long	LFB7-Ltext0
 265 ???? 01000000 		.long	LCFI0-Ltext0
 266 ???? 0200     		.word	0x2
 267 ???? 74       		.byte	0x74
 268 ???? 04       		.sleb128 4
 269 ???? 01000000 		.long	LCFI0-Ltext0
 270 ???? 03000000 		.long	LCFI1-Ltext0
 271 ???? 0200     		.word	0x2
 272 ???? 74       		.byte	0x74
 273 ???? 08       		.sleb128 8
 274 ???? 03000000 		.long	LCFI1-Ltext0
 275 ???? 66000000 		.long	LCFI3-Ltext0
 276 ???? 0200     		.word	0x2
 277 ???? 75       		.byte	0x75
 278 ???? 08       		.sleb128 8
 279 ???? 66000000 		.long	LCFI3-Ltext0
 280 ???? 67000000 		.long	LFE7-Ltext0
 281 ???? 0200     		.word	0x2
 282 ???? 74       		.byte	0x74
 283 ???? 04       		.sleb128 4
 284 ???? 00000000 		.long	0x0
 285 ???? 00000000 		.long	0x0
 286              	LLST1:
 287 ???? 67000000 		.long	LFB8-Ltext0
 288 ???? 68000000 		.long	LCFI4-Ltext0
 289 ???? 0200     		.word	0x2
 290 ???? 74       		.byte	0x74
 291 ???? 04       		.sleb128 4
 292 ???? 68000000 		.long	LCFI4-Ltext0
 293 ???? 6A000000 		.long	LCFI5-Ltext0
 294 ???? 0200     		.word	0x2
 295 ???? 74       		.byte	0x74
 296 ???? 08       		.sleb128 8
 297 ???? 6A000000 		.long	LCFI5-Ltext0
 298 ???? 92000000 		.long	LCFI7-Ltext0
 299 ???? 0200     		.word	0x2
 300 ???? 75       		.byte	0x75
 301 ???? 08       		.sleb128 8
 302 ???? 92000000 		.long	LCFI7-Ltext0
 303 ???? 93000000 		.long	LFE8-Ltext0
 304 ???? 0200     		.word	0x2
 305 ???? 74       		.byte	0x74
 306 ???? 04       		.sleb128 4
 307 ???? 00000000 		.long	0x0
 308 ???? 00000000 		.long	0x0
 309              	LLST2:
 310 ???? 93000000 		.long	LFB9-Ltext0
 311 ???? 94000000 		.long	LCFI8-Ltext0
 312 ???? 0200     		.word	0x2
 313 ???? 74       		.byte	0x74
 314 ???? 04       		.sleb128 4
 315 ???? 94000000 		.long	LCFI8-Ltext0
 316 ???? 96000000 		.long	LCFI9-Ltext0
 317 ???? 0200     		.word	0x2
 318 ???? 74       		.byte	0x74
 319 ???? 08       		.sleb128 8
 320 ???? 96000000 		.long	LCFI9-Ltext0
 321 ???? AE000000 		.long	LCFI11-Ltext0
 322 ???? 0200     		.word	0x2
 323 ???? 75       		.byte	0x75
 324 ???? 08       		.sleb128 8
 325 ???? AE000000 		.long	LCFI11-Ltext0
 326 ???? AF000000 		.long	LFE9-Ltext0
 327 ???? 0200     		.word	0x2
 328 ???? 74       		.byte	0x74
 329 ???? 04       		.sleb128 4
 330 ???? 00000000 		.long	0x0
 331 ???? 00000000 		.long	0x0
 332              		.section	.debug_info,"dr"
 333 ???? B9010000 		.long	0x1b9
 334 ???? 0200     		.word	0x2
 335 ???? 00000000 		.secrel32	Ldebug_abbrev0
 336 ???? 04       		.byte	0x4
 337 ???? 01       		.uleb128 0x1
 338 ???? 474E5520 		.ascii "GNU C 4.5.3\0"
 338      4320342E 
 338      352E3300 
 339 ???? 01       		.byte	0x1
 340 ???? 6D61696E 		.ascii "main.c\0"
 340      2E6300
 341 ???? 2F637967 		.ascii "/cygdrive/e/wkm/Document/CodeBlocksWorkspace/\304\332\307\266\273\343\261\340\0"
 341      64726976 
 341      652F652F 
 341      776B6D2F 
 341      446F6375 
 342 ???? 00000000 		.long	Ltext0
 343 ???? 00000000 		.long	Letext0
 344 ???? 00000000 		.secrel32	Ldebug_line0
 345 ???? 02       		.uleb128 0x2
 346 ???? 04       		.byte	0x4
 347 ???? 07       		.byte	0x7
 348 ???? 756E7369 		.ascii "unsigned int\0"
 348      676E6564 
 348      20696E74 
 348      00
 349 ???? 02       		.uleb128 0x2
 350 ???? 01       		.byte	0x1
 351 ???? 06       		.byte	0x6
 352 ???? 63686172 		.ascii "char\0"
 352      00
 353 ???? 02       		.uleb128 0x2
 354 ???? 01       		.byte	0x1
 355 ???? 06       		.byte	0x6
 356 ???? 7369676E 		.ascii "signed char\0"
 356      65642063 
 356      68617200 
 357 ???? 02       		.uleb128 0x2
 358 ???? 01       		.byte	0x1
 359 ???? 08       		.byte	0x8
 360 ???? 756E7369 		.ascii "unsigned char\0"
 360      676E6564 
 360      20636861 
 360      7200
 361 ???? 02       		.uleb128 0x2
 362 ???? 02       		.byte	0x2
 363 ???? 05       		.byte	0x5
 364 ???? 73686F72 		.ascii "short int\0"
 364      7420696E 
 364      7400
 365 ???? 02       		.uleb128 0x2
 366 ???? 02       		.byte	0x2
 367 ???? 07       		.byte	0x7
 368 ???? 73686F72 		.ascii "short unsigned int\0"
 368      7420756E 
 368      7369676E 
 368      65642069 
 368      6E7400
 369 ???? 02       		.uleb128 0x2
 370 ???? 04       		.byte	0x4
 371 ???? 05       		.byte	0x5
 372 ???? 696E7400 		.ascii "int\0"
 373 ???? 02       		.uleb128 0x2
 374 ???? 08       		.byte	0x8
 375 ???? 05       		.byte	0x5
 376 ???? 6C6F6E67 		.ascii "long long int\0"
 376      206C6F6E 
 376      6720696E 
 376      7400
 377 ???? 02       		.uleb128 0x2
 378 ???? 08       		.byte	0x8
 379 ???? 07       		.byte	0x7
 380 ???? 6C6F6E67 		.ascii "long long unsigned int\0"
 380      206C6F6E 
 380      6720756E 
 380      7369676E 
 380      65642069 
 381 ???? 02       		.uleb128 0x2
 382 ???? 04       		.byte	0x4
 383 ???? 05       		.byte	0x5
 384 ???? 6C6F6E67 		.ascii "long int\0"
 384      20696E74 
 384      00
 385 ???? 02       		.uleb128 0x2
 386 ???? 04       		.byte	0x4
 387 ???? 07       		.byte	0x7
 388 ???? 6C6F6E67 		.ascii "long unsigned int\0"
 388      20756E73 
 388      69676E65 
 388      6420696E 
 388      7400
 389 ???? 03       		.uleb128 0x3
 390 ???? 01       		.byte	0x1
 391 ???? 74657374 		.ascii "test1\0"
 391      3100
 392 ???? 01       		.byte	0x1
 393 ???? 04       		.byte	0x4
 394 ???? 00000000 		.long	LFB7
 395 ???? 00000000 		.long	LFE7
 396 ???? 00000000 		.secrel32	LLST0
 397 ???? 58010000 		.long	0x158
 398 ???? 04       		.uleb128 0x4
 399 ???? 76616C31 		.ascii "val1\0"
 399      00
 400 ???? 01       		.byte	0x1
 401 ???? 07       		.byte	0x7
 402 ???? 62000000 		.long	0x62
 403 ???? 02       		.byte	0x2
 404 ???? 91       		.byte	0x91
 405 ???? 6C       		.sleb128 -20
 406 ???? 04       		.uleb128 0x4
 407 ???? 76616C32 		.ascii "val2\0"
 407      00
 408 ???? 01       		.byte	0x1
 409 ???? 08       		.byte	0x8
 410 ???? 62000000 		.long	0x62
 411 ???? 02       		.byte	0x2
 412 ???? 91       		.byte	0x91
 413 ???? 68       		.sleb128 -24
 414 ???? 04       		.uleb128 0x4
 415 ???? 76616C33 		.ascii "val3\0"
 415      00
 416 ???? 01       		.byte	0x1
 417 ???? 09       		.byte	0x9
 418 ???? 62000000 		.long	0x62
 419 ???? 02       		.byte	0x2
 420 ???? 91       		.byte	0x91
 421 ???? 64       		.sleb128 -28
 422 ???? 00       		.byte	0x0
 423 ???? 03       		.uleb128 0x3
 424 ???? 01       		.byte	0x1
 425 ???? 74657374 		.ascii "test2\0"
 425      3200
 426 ???? 01       		.byte	0x1
 427 ???? 15       		.byte	0x15
 428 ???? 00000000 		.long	LFB8
 429 ???? 00000000 		.long	LFE8
 430 ???? 00000000 		.secrel32	LLST1
 431 ???? A3010000 		.long	0x1a3
 432 ???? 04       		.uleb128 0x4
 433 ???? 696E7075 		.ascii "input\0"
 433      7400
 434 ???? 01       		.byte	0x1
 435 ???? 17       		.byte	0x17
 436 ???? BD000000 		.long	0xbd
 437 ???? 02       		.byte	0x2
 438 ???? 91       		.byte	0x91
 439 ???? 6C       		.sleb128 -20
 440 ???? 04       		.uleb128 0x4
 441 ???? 6F757470 		.ascii "output\0"
 441      757400
 442 ???? 01       		.byte	0x1
 443 ???? 17       		.byte	0x17
 444 ???? BD000000 		.long	0xbd
 445 ???? 02       		.byte	0x2
 446 ???? 91       		.byte	0x91
 447 ???? 68       		.sleb128 -24
 448 ???? 04       		.uleb128 0x4
 449 ???? 74656D70 		.ascii "temp\0"
 449      00
 450 ???? 01       		.byte	0x1
 451 ???? 17       		.byte	0x17
 452 ???? BD000000 		.long	0xbd
 453 ???? 02       		.byte	0x2
 454 ???? 91       		.byte	0x91
 455 ???? 64       		.sleb128 -28
 456 ???? 00       		.byte	0x0
 457 ???? 05       		.uleb128 0x5
 458 ???? 01       		.byte	0x1
 459 ???? 6D61696E 		.ascii "main\0"
 459      00
 460 ???? 01       		.byte	0x1
 461 ???? 22       		.byte	0x22
 462 ???? BD000000 		.long	0xbd
 463 ???? 00000000 		.long	LFB9
 464 ???? 00000000 		.long	LFE9
 465 ???? 00000000 		.secrel32	LLST2
 466 ???? 00       		.byte	0x0
 467              		.section	.debug_abbrev,"dr"
 468 ???? 01       		.uleb128 0x1
 469 ???? 11       		.uleb128 0x11
 470 ???? 01       		.byte	0x1
 471 ???? 25       		.uleb128 0x25
 472 ???? 08       		.uleb128 0x8
 473 ???? 13       		.uleb128 0x13
 474 ???? 0B       		.uleb128 0xb
 475 ???? 03       		.uleb128 0x3
 476 ???? 08       		.uleb128 0x8
 477 ???? 1B       		.uleb128 0x1b
 478 ???? 08       		.uleb128 0x8
 479 ???? 11       		.uleb128 0x11
 480 ???? 01       		.uleb128 0x1
 481 ???? 12       		.uleb128 0x12
 482 ???? 01       		.uleb128 0x1
 483 ???? 10       		.uleb128 0x10
 484 ???? 06       		.uleb128 0x6
 485 ???? 00       		.byte	0x0
 486 ???? 00       		.byte	0x0
 487 ???? 02       		.uleb128 0x2
 488 ???? 24       		.uleb128 0x24
 489 ???? 00       		.byte	0x0
 490 ???? 0B       		.uleb128 0xb
 491 ???? 0B       		.uleb128 0xb
 492 ???? 3E       		.uleb128 0x3e
 493 ???? 0B       		.uleb128 0xb
 494 ???? 03       		.uleb128 0x3
 495 ???? 08       		.uleb128 0x8
 496 ???? 00       		.byte	0x0
 497 ???? 00       		.byte	0x0
 498 ???? 03       		.uleb128 0x3
 499 ???? 2E       		.uleb128 0x2e
 500 ???? 01       		.byte	0x1
 501 ???? 3F       		.uleb128 0x3f
 502 ???? 0C       		.uleb128 0xc
 503 ???? 03       		.uleb128 0x3
 504 ???? 08       		.uleb128 0x8
 505 ???? 3A       		.uleb128 0x3a
 506 ???? 0B       		.uleb128 0xb
 507 ???? 3B       		.uleb128 0x3b
 508 ???? 0B       		.uleb128 0xb
 509 ???? 11       		.uleb128 0x11
 510 ???? 01       		.uleb128 0x1
 511 ???? 12       		.uleb128 0x12
 512 ???? 01       		.uleb128 0x1
 513 ???? 40       		.uleb128 0x40
 514 ???? 06       		.uleb128 0x6
 515 ???? 01       		.uleb128 0x1
 516 ???? 13       		.uleb128 0x13
 517 ???? 00       		.byte	0x0
 518 ???? 00       		.byte	0x0
 519 ???? 04       		.uleb128 0x4
 520 ???? 34       		.uleb128 0x34
 521 ???? 00       		.byte	0x0
 522 ???? 03       		.uleb128 0x3
 523 ???? 08       		.uleb128 0x8
 524 ???? 3A       		.uleb128 0x3a
 525 ???? 0B       		.uleb128 0xb
 526 ???? 3B       		.uleb128 0x3b
 527 ???? 0B       		.uleb128 0xb
 528 ???? 49       		.uleb128 0x49
 529 ???? 13       		.uleb128 0x13
 530 ???? 02       		.uleb128 0x2
 531 ???? 0A       		.uleb128 0xa
 532 ???? 00       		.byte	0x0
 533 ???? 00       		.byte	0x0
 534 ???? 05       		.uleb128 0x5
 535 ???? 2E       		.uleb128 0x2e
 536 ???? 00       		.byte	0x0
 537 ???? 3F       		.uleb128 0x3f
 538 ???? 0C       		.uleb128 0xc
 539 ???? 03       		.uleb128 0x3
 540 ???? 08       		.uleb128 0x8
 541 ???? 3A       		.uleb128 0x3a
 542 ???? 0B       		.uleb128 0xb
 543 ???? 3B       		.uleb128 0x3b
 544 ???? 0B       		.uleb128 0xb
 545 ???? 49       		.uleb128 0x49
 546 ???? 13       		.uleb128 0x13
 547 ???? 11       		.uleb128 0x11
 548 ???? 01       		.uleb128 0x1
 549 ???? 12       		.uleb128 0x12
 550 ???? 01       		.uleb128 0x1
 551 ???? 40       		.uleb128 0x40
 552 ???? 06       		.uleb128 0x6
 553 ???? 00       		.byte	0x0
 554 ???? 00       		.byte	0x0
 555 ???? 00       		.byte	0x0
 556              		.section	.debug_pubnames,"dr"
 557 ???? 2B000000 		.long	0x2b
 558 ???? 0200     		.word	0x2
 559 ???? 00000000 		.secrel32	Ldebug_info0
 560 ???? BD010000 		.long	0x1bd
 561 ???? 10010000 		.long	0x110
 562 ???? 74657374 		.ascii "test1\0"
 562      3100
 563 ???? 58010000 		.long	0x158
 564 ???? 74657374 		.ascii "test2\0"
 564      3200
 565 ???? A3010000 		.long	0x1a3
 566 ???? 6D61696E 		.ascii "main\0"
 566      00
 567 ???? 00000000 		.long	0x0
 568              		.section	.debug_pubtypes,"dr"
 569 ???? 0E000000 		.long	0xe
 570 ???? 0200     		.word	0x2
 571 ???? 00000000 		.secrel32	Ldebug_info0
 572 ???? BD010000 		.long	0x1bd
 573 ???? 00000000 		.long	0x0
 574              		.section	.debug_aranges,"dr"
 575 ???? 1C000000 		.long	0x1c
 576 ???? 0200     		.word	0x2
 577 ???? 00000000 		.secrel32	Ldebug_info0
 578 ???? 04       		.byte	0x4
 579 ???? 00       		.byte	0x0
 580 ???? 0000     		.word	0x0
 581 ???? 0000     		.word	0x0
 582 ???? 00000000 		.long	Ltext0
 583 ???? AF000000 		.long	Letext0-Ltext0
 584 ???? 00000000 		.long	0x0
 585 ???? 00000000 		.long	0x0
