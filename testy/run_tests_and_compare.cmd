@ set testPrg= ..\cmake-build-debug\Trojuhelniky1.exe
@ echo testovany program = %testPrg%

@ %testPrg% < 0000_in.txt > 0000_out_zz.txt
@ %testPrg% < 0001_in.txt > 0001_out_zz.txt
@ %testPrg% < 0002_in.txt > 0002_out_zz.txt
@ %testPrg% < 0003_in.txt > 0003_out_zz.txt
@ %testPrg% < 0003_in.txt > 0003_out_zz.txt
@ %testPrg% < 0004_in.txt > 0004_out_zz.txt
@ %testPrg% < 0005_in.txt > 0005_out_zz.txt
@ %testPrg% < 0006_in.txt > 0006_out_zz.txt
@ %testPrg% < 0007_in.txt > 0007_out_zz.txt
@ %testPrg% < 0008_in.txt > 0008_out_zz.txt
@ %testPrg% < 0009_in.txt > 0009_out_zz.txt
@ %testPrg% < 0010_in.txt > 0010_out_zz.txt
@ %testPrg% < 0011_in.txt > 0011_out_zz.txt
@ %testPrg% < 0012_in.txt > 0012_out_zz.txt
@ %testPrg% < 0013_in.txt > 0013_out_zz.txt

@ fc /C /L 0000_out_zz.txt 0000_out_win.txt
@ fc /C /L 0001_out_zz.txt 0001_out_win.txt
@ fc /C /L 0002_out_zz.txt 0002_out_win.txt
@ fc /C /L 0003_out_zz.txt 0003_out_win.txt
@ fc /C /L 0004_out_zz.txt 0004_out_win.txt
@ fc /C /L 0005_out_zz.txt 0005_out_win.txt
@ fc /C /L 0006_out_zz.txt 0006_out_win.txt
@ fc /C /L 0007_out_zz.txt 0007_out_win.txt
@ fc /C /L 0008_out_zz.txt 0008_out_win.txt
@ fc /C /L 0009_out_zz.txt 0009_out_win.txt
@ fc /C /L 0010_out_zz.txt 0010_out_win.txt
@ fc /C /L 0011_out_zz.txt 0011_out_win.txt
@ fc /C /L 0012_out_zz.txt 0012_out_win.txt
@ fc /C /L 0013_out_zz.txt 0013_out_win.txt

