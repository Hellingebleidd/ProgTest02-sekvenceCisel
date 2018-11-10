@ set testPrg= ..\cmake-build-debug\ProgTest02_sekvenceCisel.exe
@ echo Testy 0000-0013. Testovany program = %testPrg%

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

@ fc 0000_out_zz.txt 0000_out_win.txt > null && Echo 0000 ok || fc 0000_out_zz.txt 0000_out_win.txt
@ fc 0001_out_zz.txt 0001_out_win.txt > null && Echo 0001 ok || fc 0001_out_zz.txt 0001_out_win.txt
@ fc 0002_out_zz.txt 0002_out_win.txt > null && Echo 0002 ok || fc 0002_out_zz.txt 0002_out_win.txt
@ fc 0003_out_zz.txt 0003_out_win.txt > null && Echo 0003 ok || fc 0003_out_zz.txt 0003_out_win.txt
@ fc 0004_out_zz.txt 0004_out_win.txt > null && Echo 0004 ok || fc 0004_out_zz.txt 0004_out_win.txt
@ fc 0005_out_zz.txt 0005_out_win.txt > null && Echo 0005 ok || fc 0005_out_zz.txt 0005_out_win.txt
@ fc 0006_out_zz.txt 0006_out_win.txt > null && Echo 0006 ok || fc 0006_out_zz.txt 0006_out_win.txt
@ fc 0007_out_zz.txt 0007_out_win.txt > null && Echo 0007 ok || fc 0007_out_zz.txt 0007_out_win.txt
@ fc 0008_out_zz.txt 0008_out_win.txt > null && Echo 0008 ok || fc 0008_out_zz.txt 0008_out_win.txt
@ fc 0009_out_zz.txt 0009_out_win.txt > null && Echo 0009 ok || fc 0009_out_zz.txt 0009_out_win.txt
@ fc 0010_out_zz.txt 0010_out_win.txt > null && Echo 0010 ok || fc 0010_out_zz.txt 0010_out_win.txt
@ fc 0011_out_zz.txt 0011_out_win.txt > null && Echo 0011 ok || fc 0011_out_zz.txt 0011_out_win.txt
@ fc 0012_out_zz.txt 0012_out_win.txt > null && Echo 0012 ok || fc 0012_out_zz.txt 0012_out_win.txt
@ fc 0013_out_zz.txt 0013_out_win.txt > null && Echo 0013 ok || fc 0013_out_zz.txt 0013_out_win.txt

