bothBinaries:	lexer parser
lexer:	lex.yy.c ass3_15CS30006.tab.h ass3_15CS30006_lexer.c
	gcc lex.yy.c ass3_15CS30006_lexer.c -o lexer -lfl

lex.yy.c:	ass3_15CS30006.l
	flex ass3_15CS30006.l

ass3_15CS30006.tab.h:	ass3_15CS30006.y
	bison -d ass3_15CS30006.y

parser:	lex.yy.c ass3_15CS30006.tab.c ass3_15CS30006.tab.h ass3_15CS30006_parser.c
	gcc lex.yy.c ass3_15CS30006.tab.c ass3_15CS30006_parser.c -o parser -lfl -ly

ass3_15CS30006.tab.c:	ass3_15CS30006.y
	bison ass3_15CS30006.y

clean:
	-rm lexer parser lex.yy.c ass3_15CS30006.tab.c ass3_15CS30006.tab.h
