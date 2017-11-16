#include <stdio.h>
#include "ass3_15CS30006.tab.h"
int main(){
	int token;
	while(token=yylex()){
		switch(token){
			case UNSIGNED:
				printf("<KEYWORD>\n"); break;
			case BREAK:
				printf("<KEYWORD>\n"); break;
			case RETURN:
				printf("<KEYWORD>\n"); break;
			case VOID:
				printf("<KEYWORD>\n"); break;
			case CASE:
				printf("<KEYWORD>\n"); break;
			case FLOAT:
				printf("<KEYWORD>\n"); break;
			case SHORT:
				printf("<KEYWORD>\n"); break;
			case CHAR:
				printf("<KEYWORD>\n"); break;
			case FOR:
				printf("<KEYWORD>\n"); break;
			case SIGNED:
				printf("<KEYWORD>\n"); break;
			case WHILE:
				printf("<KEYWORD>\n"); break;
			case GOTO:
				printf("<KEYWORD>\n"); break;
			case BOOL:
				printf("<KEYWORD>\n"); break;
			case CONTINUE:
				printf("<KEYWORD>\n"); break;
			case IF:
				printf("<KEYWORD>\n"); break;
			case ELSE:
				printf("<KEYWORD>\n"); break;
			case DEFAULT:
				printf("<KEYWORD>\n"); break;
			case DO:
				printf("<KEYWORD>\n"); break;
			case INT:
				printf("<KEYWORD>\n"); break;
			case SWITCH:
				printf("<KEYWORD>\n"); break;
			case DOUBLE:
				printf("<KEYWORD>\n"); break;
			case LONG:
				printf("<KEYWORD>\n"); break;
			case MATRIX:
				printf("<KEYWORD>\n"); break;

			case IDENTIFIER:
				printf("<IDENTIFIER>\n");
				break;
			case CONSTANT:
				printf("<CONSTANT>\n");
				break;
			case STRINGLITERAL:
				printf("<STRING>\n");
				break;
			case OPENBRCSQ:
				printf("<PUNCTUATOR>\n"); break;
			case CLOSEBRCSQ:
				printf("<PUNCTUATOR>\n"); break;
			case OPENBRCCIR:
				printf("<PUNCTUATOR>\n"); break;
			case CLOSEBRCCIR:
				printf("<PUNCTUATOR>\n"); break;
			case OPENBRCCUR:
				printf("<PUNCTUATOR>\n"); break;
			case CLOSEBRCCUR:
				printf("<PUNCTUATOR>\n"); break;
			case DOT:
				printf("<PUNCTUATOR>\n"); break;
			case POINTSTO:
				printf("<PUNCTUATOR>\n"); break;
			case PLUSPLUS:
				printf("<PUNCTUATOR>\n"); break;
			case MINUSMINUS:
				printf("<PUNCTUATOR>\n"); break;
			case AND:
				printf("<PUNCTUATOR>\n"); break;
			case STAR:
				printf("<PUNCTUATOR>\n"); break;
			case PLUS:
				printf("<PUNCTUATOR>\n"); break;
			case MINUS:
				printf("<PUNCTUATOR>\n"); break;
			case NEGATE:
				printf("<PUNCTUATOR>\n"); break;
			case NOT:
				printf("<PUNCTUATOR>\n"); break;
			case DIVIDE:
				printf("<PUNCTUATOR>\n"); break;
			case PERCENT:
				printf("<PUNCTUATOR>\n"); break;
			case LESSLESS:
				printf("<PUNCTUATOR>\n"); break;
			case GREATGREAT:
				printf("<PUNCTUATOR>\n"); break;
			case LESS:
				printf("<PUNCTUATOR>\n"); break;
			case GREAT:
				printf("<PUNCTUATOR>\n"); break;
			case LESSEQUAL:
				printf("<PUNCTUATOR>\n"); break;
			case GREATEQUAL:
				printf("<PUNCTUATOR>\n"); break;
			case EQUALEQUAL:
				printf("<PUNCTUATOR>\n"); break;
			case NOTEQUAL:
				printf("<PUNCTUATOR>\n"); break;
			case XOR:
				printf("<PUNCTUATOR>\n"); break;
			case OR:
				printf("<PUNCTUATOR>\n"); break;
			case ANDAND:
				printf("<PUNCTUATOR>\n"); break;
			case OROR:
				printf("<PUNCTUATOR>\n"); break;
			case QUESTION:
				printf("<PUNCTUATOR>\n"); break;
			case EQUALS:
				printf("<PUNCTUATOR>\n"); break;
			case MULTIPLYEQUALS:
				printf("<PUNCTUATOR>\n"); break;
			case DIVIDEEQUALS:
				printf("<PUNCTUATOR>\n"); break;
			case MODEQUALS:
				printf("<PUNCTUATOR>\n"); break;
			case PLUSEQUALS:
				printf("<PUNCTUATOR>\n"); break;
			case MINUSEQUALS:
				printf("<PUNCTUATOR>\n"); break;
			case LESSLESSEQUALS:
				printf("<PUNCTUATOR>\n"); break;
			case GREATGREATEQUALS:
				printf("<PUNCTUATOR>\n"); break;
			case ANDEQUALS:
				printf("<PUNCTUATOR>\n"); break;
			case XOREQUALS:
				printf("<PUNCTUATOR>\n"); break;
			case OREQUALS:
				printf("<PUNCTUATOR>\n"); break;
			case COMMA:
				printf("<PUNCTUATOR>\n"); break;
			case HASH:
				printf("<PUNCTUATOR>\n"); break;
			case DOTINVERTEDCOMMA:
				printf("<PUNCTUATOR>\n"); break;
			case COLON:
				printf("<PUNCTUATOR>\n"); break;
			case SEMICOLON:
				printf("<PUNCTUATOR>\n"); break;
			
			default:
				printf("Invalid Input\n");

		}
	}
}