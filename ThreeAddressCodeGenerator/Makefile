a.out:	lex.yy.c ass4_15CS30006.tab.h ass4_15CS30006_translator.cxx ass4_15CS30006_translator.h
	g++ ass4_15CS30006_translator.cxx ass4_15CS30006.tab.c lex.yy.c -ly -lfl
ass4_15CS30006.tab.h:	ass4_15CS30006.y
	bison -d ass4_15CS30006.y
ass4_15CS30006.tab.c:	ass4_15CS30006.y
	bison ass4_15CS30006.y
lex.yy.c:	ass4_15CS30006.l
	flex ass4_15CS30006.l
clean:
	-rm a.out lex.yy.c ass4_15CS30006.tab.c ass4_15CS30006.tab.h
