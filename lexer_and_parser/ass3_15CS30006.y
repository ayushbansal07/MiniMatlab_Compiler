%{
	#include <stdio.h>
	#define YYSTYPE double
	extern int yylex(void);
%}

%token-table
%start translation_unit
%token UNSIGNED BREAK RETURN VOID CASE FLOAT SHORT CHAR FOR SIGNED WHILE GOTO BOOL CONTINUE IF DEFAULT DO INT SWITCH DOUBLE LONG MATRIX
%token OPENBRCSQ CLOSEBRCSQ OPENBRCCIR CLOSEBRCCIR OPENBRCCUR CLOSEBRCCUR DOT POINTSTO PLUSPLUS MINUSMINUS AND STAR PLUS MINUS NEGATE NOT DIVIDE PERCENT LESSLESS GREATGREAT LESS GREAT LESSEQUAL GREATEQUAL EQUALEQUAL NOTEQUAL XOR OR ANDAND OROR QUESTION EQUALS MULTIPLYEQUALS DIVIDEEQUALS MODEQUALS PLUSEQUALS MINUSEQUALS LESSLESSEQUALS GREATGREATEQUALS ANDEQUALS XOREQUALS OREQUALS COMMA HASH DOTINVERTEDCOMMA COLON SEMICOLON
%token IDENTIFIER CONSTANT STRINGLITERAL
%nonassoc "then"
%nonassoc ELSE

%%
primary_expr:		IDENTIFIER 								 				{printf("primary_expr -> IDENTIFIER\n");}
					|CONSTANT 												{printf("primary_expr -> CONSTANT\n");}
					|STRINGLITERAL 											{printf("primary_expr -> STRINGLITERAL\n");}
					|OPENBRCCIR expression CLOSEBRCCIR 						{printf("primary_expr -> ( expression )\n");}
;

postfix_expr:		primary_expr 											{printf("postfix_expr -> primary_expr\n");}
					|postfix_expr OPENBRCSQ expression CLOSEBRCSQ			{printf("postfix_expr -> postfix_expr [ expression ]\n");}
					|postfix_expr OPENBRCCIR CLOSEBRCCIR 					{printf("postfix_expr -> postfix_expr ()\n");}
					|postfix_expr OPENBRCCIR argument_expr_list CLOSEBRCCIR {printf("postfix_expr -> postfix_expr ( argument_expr_list )\n");}
					|postfix_expr DOT IDENTIFIER 							{printf("postfix_expr -> postfix_expr .IDENTIFIER\n");}
					|postfix_expr POINTSTO IDENTIFIER 						{printf("postfix_expr -> postfix_expr ->IDENTIFIER\n");}
					|postfix_expr PLUSPLUS 									{printf("postfix_expr -> postfix_expr ++\n");}
					|postfix_expr MINUSMINUS 								{printf("postfix_expr -> postfix_expr --\n");}
					|postfix_expr DOTINVERTEDCOMMA 							{printf("postfix_expr -> postfix_expr .'\n");}
;

argument_expr_list:			assignment_expr  								{printf("argument_expr_list -> assignment_expr\n");}
							|argument_expr_list COMMA assignment_expr 		{printf("argument_expr_list -> argument_expr_list , assignment_expr\n");}
;


unary_expr:			postfix_expr  											{printf("unary_expr -> postfix_expr\n");}
					|PLUSPLUS unary_expr									{printf("unary_expr -> ++ unary_expr\n");}
					|MINUSMINUS unary_expr									{printf("unary_expr -> -- unary_expr\n");}
					|unary_operator cast_expr								{printf("unary_expr -> unary_operator cast_expr\n");}
;

unary_operator:		AND 													{printf("unary_operator -> &\n");}
					|STAR													{printf("unary_operator -> *\n");}
					|PLUS													{printf("unary_operator -> +\n");}
					|MINUS													{printf("unary_operator -> -\n");}
;

cast_expr:			unary_expr 												{printf("cast_expr -> unary_expr\n");}
;

multiplicative_expr:		cast_expr 										{printf("multiplicative_expr -> cast_expr\n");}
							|multiplicative_expr STAR cast_expr 			{printf("multiplicative_expr -> multiplicative_expr * cast_expr\n");}
							|multiplicative_expr DIVIDE cast_expr 			{printf("multiplicative_expr -> multiplicative_expr / cast_expr\n");}
							|multiplicative_expr PERCENT cast_expr 			{printf("multiplicative_expr -> multiplicative_expr %% cast_expr\n");}
;


additive_expr:				multiplicative_expr 							{printf("additive_expr -> multiplicative_expr\n");}
							|additive_expr PLUS multiplicative_expr    		{printf("additive_expr -> additive_expr + multiplicative_expr\n");}
							|additive_expr MINUS multiplicative_expr 		{printf("additive_expr -> additive_expr - multiplicative_expr\n");}
;

				
shift_expr:					additive_expr 									{printf("shift_expr -> additive_expr\n");}
							|shift_expr LESSLESS additive_expr 				{printf("shift_expr -> shift_expr << additive_expr\n");}
							|shift_expr GREATGREAT additive_expr 			{printf("shift_expr -> shift_expr >> additive_expr\n");}
;


relational_expr:			shift_expr 										{printf("relational_expr -> shift_expr\n");}
							|relational_expr LESS shift_expr 				{printf("relational_expr -> relational_expr < shift_expr\n");}
							|relational_expr GREAT shift_expr 				{printf("relational_expr -> relational_expr > shift_expr\n");}
							|relational_expr LESSEQUAL shift_expr 			{printf("relational_expr -> relational_expr <= shift_expr\n");}
							|relational_expr GREATEQUAL shift_expr 			{printf("relational_expr -> relational_expr >= shift_expr\n");}
;


equality_expr:				relational_expr 								{printf("equality_expr -> relational_expr\n");}
							|equality_expr EQUALEQUAL relational_expr 		{printf("equality_expr -> equality_expr == relational_expr\n");}
							|equality_expr NOTEQUAL relational_expr 		{printf("equality_expr -> equality_expr != relational_expr\n");}
;


AND_expr:					equality_expr 									{printf("AND_expr -> equality_expr\n");}
							|AND_expr AND equality_expr						{printf("AND_expr -> AND_expr & equality_expr\n");}
;

exclusiveOR_expr:			AND_expr 										{printf("exclusiveOR_expr -> AND_expr\n");}
							|exclusiveOR_expr XOR AND_expr 					{printf("exclusiveOR_expr -> exclusiveOR_expr ^ AND_expr \n");}
;


inclusiveOR_expr:			exclusiveOR_expr								{printf("inclusiveOR_expr -> exclusiveOR_expr\n");}
							|inclusiveOR_expr OR exclusiveOR_expr			{printf("inclusiveOR_expr -> inclusiveOR_expr | exclusiveOR_expr\n");}
;

logicalAND_expr:			inclusiveOR_expr 								{printf("logicalAND_expr -> inclusiveOR_expr\n");}
							|logicalAND_expr ANDAND inclusiveOR_expr 		{printf("inclusiveOR_expr -> logicalAND_expr && inclusiveOR_expr\n");}
;

logicalOR_expr:				logicalAND_expr 								{printf("logicalOR_expr -> logicalAND_expr\n");}
							|logicalOR_expr OROR logicalAND_expr			{printf("logicalOR_expr -> logicalOR_expr || logicalAND_expr\n");}
;

conditional_expr:			logicalOR_expr 													{printf("conditional_expr -> logicalOR_expr\n");}
							|logicalOR_expr QUESTION expression COLON conditional_expr 	 	{printf("conditional_expr -> logicalOR_expr ? expression : conditional_expr \n");}
;

assignment_expr:			conditional_expr  								{printf("assignment_expr -> conditional_expr\n");}
							|unary_expr assignment_operator assignment_expr {printf("assignment_expr -> unary_expr assignment_operator assignment_expr\n");}
;


assignment_operator:  	 	EQUALS 											{printf("assignment_operator -> =\n");}
							|MULTIPLYEQUALS									{printf("assignment_operator -> *=\n");}
							|DIVIDEEQUALS									{printf("assignment_operator -> /=\n");}
							|MODEQUALS										{printf("assignment_operator -> %%=\n");}
							|PLUSEQUALS										{printf("assignment_operator -> +=\n");}
							|MINUSEQUALS									{printf("assignment_operator -> -=\n");}
							|LESSLESSEQUALS									{printf("assignment_operator -> <<=\n");}
							|GREATGREATEQUALS								{printf("assignment_operator -> >>=\n");}
							|ANDEQUALS										{printf("assignment_operator -> &=\n");}
							|XOREQUALS										{printf("assignment_operator -> ^=\n");}
							|OREQUALS										{printf("assignment_operator -> |=\n");}
;

expression:					assignment_expr									{printf("expression -> assignment_expr\n");}
							|expression COMMA assignment_expr				{printf("expression -> expression , assignment_expr\n");}
;

expression_opt:				expression 										{printf("expression_opt -> expression\n");}
							| 												{printf("expression_opt -> \n");}
;

constant_expr:				conditional_expr								{printf("constant_expr -> conditional_expr\n");}
;





declaration:	 			declaration_specifiers SEMICOLON						{printf("declaration -> declaration_specifiers ;\n");}
							|declaration_specifiers init_declarator_list SEMICOLON	{printf("declaration -> declaration_specifiers init_declarator_list ;\n");}
;

declaration_specifiers: 	type_specifier										{printf("declaration_specifiers -> type_specifier\n");}
							|type_specifier declaration_specifiers				{printf("declaration_specifiers -> type_specifier declaration_specifiers\n");}
;

init_declarator_list:       init_declarator										{printf("init_declarator_list -> init_declarator\n");}
							|init_declarator_list COMMA init_declarator			{printf("init_declarator_list -> init_declarator_list , init_declarator	\n");}
;
	
init_declarator:    	declarator												{printf("init_declarator -> declarator\n");}
						|declarator EQUALS initializer							{printf("init_declarator -> declarator = initializer\n");}
;

type_specifier:		 	VOID													{printf("type_specifier -> void\n");}
						|CHAR													{printf("type_specifier -> char\n");}
						|SHORT													{printf("type_specifier -> short\n");}
						|INT													{printf("type_specifier -> int\n");}
						|LONG													{printf("type_specifier -> long\n");}
						|FLOAT													{printf("type_specifier -> float\n");}
						|DOUBLE													{printf("type_specifier -> double\n");}
						|MATRIX													{printf("type_specifier -> Matrix\n");}
						|SIGNED													{printf("type_specifier -> signed\n");}
						|UNSIGNED												{printf("type_specifier -> unsigned\n");}
						|BOOL													{printf("type_specifier -> bool\n");}
;


declarator:		 		direct_declarator										{printf("declarator -> direct_declarator\n");}
						|pointer direct_declarator								{printf("declarator -> pointer direct_declarator\n");}
;

direct_declarator:	 	IDENTIFIER 														{printf("direct_declarator -> IDENTIFIER\n");}
						|OPENBRCCIR declarator CLOSEBRCCIR 								{printf("direct_declarator -> ( declarator )\n");}
						|direct_declarator OPENBRCSQ CLOSEBRCSQ 						{printf("direct_declarator -> direct_declarator []\n");}
						|direct_declarator OPENBRCSQ assignment_expr CLOSEBRCSQ 		{printf("direct_declarator -> direct_declarator [ assignment_expr ]\n");}
						|direct_declarator OPENBRCCIR parameter_type_list CLOSEBRCCIR 	{printf("direct_declarator -> direct_declarator ( parameter_type_list )\n");}
						|direct_declarator OPENBRCCIR CLOSEBRCCIR 						{printf("direct_declarator -> direct_declarator ()\n");}
						|direct_declarator OPENBRCCIR identifier_list CLOSEBRCCIR 		{printf("direct_declarator -> direct_declarator ( identifier_list )\n");}
;


pointer:  				STAR													{printf("pointer -> *\n");}
	 					|STAR pointer											{printf("pointer -> * pointer\n");}
;



parameter_type_list:	parameter_list											{printf("parameter_type_list -> parameter_list\n");}
;

parameter_list:		 	parameter_declaration									{printf("parameter_list -> parameter_declaration\n");}
						|parameter_list COMMA parameter_declaration				{printf("parameter_list -> parameter_list , parameter_declaration\n");}
;

parameter_declaration:	declaration_specifiers declarator						{printf("parameter_declaration -> declaration_specifiers declarator\n");}
						|declaration_specifiers									{printf("parameter_declaration -> declaration_specifiers\n");}
;

identifier_list:		IDENTIFIER												{printf("identifier_list -> IDENTIFIER\n");}
						|identifier_list COMMA IDENTIFIER						{printf("identifier_list -> identifier_list , IDENTIFIER\n");}			
;

initializer:	 		assignment_expr											{printf("initializer -> assignment_expr\n");}
						|OPENBRCCUR initializer_row_list CLOSEBRCCUR			{printf("initializer -> { initializer_row_list }\n");}
;

initializer_row_list:		initializer_row 									{printf("initializer_row_list -> initializer_row\n");}								
							|initializer_row_list SEMICOLON initializer_row		{printf("initializer_row_list -> initializer_row_list ; initializer_row	\n");}
;

initializer_row:	 	initializer 											{printf("initializer_row -> initializer\n");}	
						|designation initializer 								{printf("initializer_row -> designation initializer 	\n");}	
						|initializer_row COMMA initializer 						{printf("initializer_row -> initializer_row , initializer\n");}	
						|initializer_row COMMA designation 						{printf("initializer_row -> initializer_row , designation\n");}	
;

designation:			designator_list EQUALS									{printf("designation -> designator_list =\n");}	
;

designator_list:	 	designator												{printf("designator_list -> designator\n");}	
						|designator_list designator								{printf("designator_list -> designator_list designator\n");}	
;

designator:	 			OPENBRCSQ constant_expr CLOSEBRCSQ						{printf("designator -> [ constant_expr ]\n");}
						|DOT IDENTIFIER											{printf("designator -> . IDENTIFIER\n");}
;






statement:		 	labeled_statement 											{printf("statement -> labeled_statement\n");}
					|compound_statement											{printf("statement -> compound_statement\n");}
					|expression_statement										{printf("statement -> expression_statement\n");}
					|selection_statement										{printf("statement -> selection_statement\n");}
					|iteration_statement										{printf("statement -> iteration_statement\n");}
					|jump_statement												{printf("statement -> jump_statement\n");}
;

labeled_statement:	 IDENTIFIER COLON statement									{printf("labeled_statement -> IDENTIFIER : statement\n");}
					|CASE constant_expr COLON statement							{printf("labeled_statement -> case constant_expr : statement\n");}
					|DEFAULT COLON statement									{printf("labeled_statement -> default : statement\n");}
;

compound_statement:	 OPENBRCCUR CLOSEBRCCUR										{printf("compound_statement -> {}\n");}
					|OPENBRCCUR block_item_list CLOSEBRCCUR						{printf("compound_statement -> { block_item_list }\n");}
;

block_item_list:	 	block_item												{printf("block_item_list -> block_item\n");}
						|block_item_list block_item								{printf("block_item_list -> block_item_list block_item\n");}
;

block_item:		 declaration 													{printf("block_item -> declaration\n");}
				|statement														{printf("block_item -> statement\n");}
;

expression_statement:	 SEMICOLON												{printf("expression_statement -> ;\n");}
						|expression SEMICOLON									{printf("expression_statement -> expression ;\n");}
;

selection_statement:	 IF OPENBRCCIR expression CLOSEBRCCIR statement 		%prec "then"	{printf("selection_statement -> if ( expression ) statement\n");}
						|IF OPENBRCCIR expression CLOSEBRCCIR statement ELSE statement			{printf("selection_statement -> if (expression ) statement else statement\n");}
						|SWITCH OPENBRCCIR expression CLOSEBRCCIR statement						{printf("selection_statement -> switch ( expression ) statement\n");}
;

iteration_statement:	 WHILE OPENBRCCIR expression CLOSEBRCCIR statement 											{printf("iteration_statement -> while ( expression ) statement\n");}
						|DO statement WHILE OPENBRCCIR expression CLOSEBRCCIR SEMICOLON 							{printf("iteration_statement -> do statement while ( expression ) ;\n");}
						|FOR OPENBRCCIR expression_opt SEMICOLON expression_opt SEMICOLON expression_opt CLOSEBRCCIR statement  {printf("iteration_statement -> for ( expression ; expression ; expression ) statement\n");}
						|FOR OPENBRCCIR declaration expression_opt SEMICOLON expression_opt CLOSEBRCCIR statement 			{printf("iteration_statement -> for ( declaration expression ; expression ) statement\n");}
;

jump_statement:			GOTO IDENTIFIER SEMICOLON								{printf("jump_statement -> goto IDENTIFIER ;\n");}
						|CONTINUE SEMICOLON										{printf("jump_statement -> continue ;\n");}
						|BREAK SEMICOLON										{printf("jump_statement -> break ;\n");}
						|RETURN SEMICOLON										{printf("jump_statement -> return ;\n");}
						|RETURN expression SEMICOLON							{printf("jump_statement -> return expression ;\n");}
;


translation_unit:		external_declaration									{printf("translation_unit -> external_declaration\n");}
						|translation_unit external_declaration					{printf("translation_unit -> translation_unit external_declaration\n");}
;

external_declaration:	function_definition										{printf("external_declaration -> function_definition\n");}
						|declaration											{printf("external_declaration -> declaration\n");}
;

function_definition: 	declaration_specifiers declarator compound_statement 					{printf("function_definition -> declaration_specifiers declarator compound_statement");}
						|declaration_specifiers declarator declaration_list compound_statement {printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement");}
;

declaration_list: 	 	declaration 											{printf("declaration_list -> declaration");}
						|declaration_list declaration							{printf("declaration_list -> declaration_list declaration");}
;

%%



int yyerror(char *s){
  printf("Parser Error : %s\n",s);
  return -1;
}


yywrap()
{
	return 1;
}









			





