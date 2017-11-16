%{	
	#include "ass3_15CS30006.tab.h"
%}
%option noyywrap


%x 						single_line_comments multi_line_comments

ws						[ \t\n\r\f]

keyword 				("unsigned"|"break"|"return"|"void"|"case"|"float"|"short"|"char"|"for"|"signed"|"while"|"goto"|"Bool"|"continue"|"if"|"default"|"do"|"int"|"switch"|"double"|"long"|"else"|"Matrix")

identifier_nondigit 	[a-zA-Z_]
digit 					[0-9]
identifier 				{identifier_nondigit}({identifier_nondigit}|{digit})*

zero_constant 			[0]
non_zero_digit 			[1-9]
integer_constant 		{non_zero_digit}{digit}*
sign 					("+"|"-")
escape_sequence 		("\\\'"|"\\\""|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v")
digit_sequence 			{digit}+
fractional_constant 	({digit_sequence}?[.]{digit_sequence}|{digit_sequence}[.])		
exponent_part 			[eE]{sign}?{digit_sequence}
floating_constant		({fractional_constant}{exponent_part}?|{digit_sequence}{exponent_part})
c_char					([^\'\\\n]|{escape_sequence})
c_char_sequence			{c_char}+
character_constant		\'{c_char_sequence}\'
constant 				({integer_constant}|{floating_constant}|{character_constant}|{zero_constant})

string_literal			\"{c_char_sequence}?\"

integer 				({integer_constant}|{zero_constant})

punctuator (\[|\]|\(|\)|\{|\}|\.|\−\>|\+\+|\−\−|\&|\*|\+|\-|\∼|\!|\/|\%|\<\<|\>\>|\<|\>|\<\=|\>\=|\=\=|\!\=|\^|\||\&\&|\|\||\?|\:|\;|\=|\*\=|\/\=|\%\=|\+\=|\-\=|\<\<\=|\>\>\=|\&\=|\^\=|\|\=|\,|\#|\.\')

%%
{ws}		{}

unsigned	{return UNSIGNED;}
break		{return BREAK;}
return		{return RETURN;}
void		{return VOID;}
case		{return CASE;}
float		{return FLOAT;}
short		{return SHORT;}
char		{return CHAR;}
for			{return FOR;} 
signed		{return SIGNED;}
while		{return WHILE;}
goto		{return GOTO;}
Bool		{return BOOL;}
continue	{return CONTINUE;}
if			{return IF;}
default		{return DEFAULT;}
do			{return DO;}
int			{return INT;}
switch		{return SWITCH;}
double		{return DOUBLE;}
long		{return LONG;}
else		{return ELSE;}
Matrix		{return MATRIX;}

{identifier} 					{return IDENTIFIER;}
{constant}						{return CONSTANT;}
{string_literal}				{return STRINGLITERAL;}

\[			{return OPENBRCSQ;}
\]			{return CLOSEBRCSQ;}	
\(			{return OPENBRCCIR;}
\)			{return CLOSEBRCCIR;}
\{			{return OPENBRCCUR;}
\}			{return CLOSEBRCCUR;}
\.			{return DOT;}
\−\>		{return POINTSTO;}
\+\+		{return PLUSPLUS;}
\-\-		{return MINUSMINUS;}
\&			{return AND;}
\*			{return STAR;}
\+			{return PLUS;}
\-			{return MINUS;}
\∼			{return NEGATE;}
\!			{return NOT;}
\/			{return DIVIDE;}
\%			{return PERCENT;}
\<\<			{return LESSLESS;}
\>\>			{return GREATGREAT;}
\<			{return LESS;}
\>			{return GREAT;}
\<\=			{return LESSEQUAL;}
\>\=			{return GREATEQUAL;}
\=\=			{return EQUALEQUAL;}
\!\=			{return NOTEQUAL;}
\^			{return XOR;}
\|			{return OR;}
\&\&			{return ANDAND;}
\|\|			{return OROR;}
\?			{return QUESTION;}
\:			{return COLON;}
\;			{return SEMICOLON;}
\=			{return EQUALS;}
\*\=			{return MULTIPLYEQUALS;}
\/\=			{return DIVIDEEQUALS;}
\%\=			{return MODEQUALS;}
\+\=			{return PLUSEQUALS;}
\-\=			{return MINUSEQUALS;}
\<\<\=			{return LESSLESSEQUALS;}
\>\>\=			{return GREATGREATEQUALS;}
\&\=			{return ANDEQUALS;}
\^\=			{return XOREQUALS;}
\|\=			{return OREQUALS;}
\,			{return COMMA;}
\#			{return HASH;}
\.\'			{return DOTINVERTEDCOMMA;}

\/\/							{BEGIN(single_line_comments);}
<single_line_comments>\n		{BEGIN(0);}
<single_line_comments>[^\n]*	{}
\/\*							{BEGIN(multi_line_comments);}
<multi_line_comments>\**\/		{BEGIN(0);}
<multi_line_comments>\**[^\/]	{}
<multi_line_comments>[^*]*		{}
%%
