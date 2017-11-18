/*
1. exp (exp_t): 
	For expression type non-terminals.
	Associated non-terminals:
	primary_expr postfix_expr unary_expr expression cast_expr additive_expr relational_expr equality_expr shift_expr logicalAND_expr 
	inclusiveOR_expr exclusiveOR_expr logicalOR_expr conditional_expr multiplicative_expr AND_expr initializer assignment_expr constant_expr 
	expression_statement expression_opt declarator direct_declarator init_declarator init_declarator_list

	Attributes: (Type)
	trueList - (List * ). 		List of addresses of Jump Statements to be backPatched later when expression evaluates to True.	(Inherited)
    falseList - (List * ).      List of addresses of Jump Statements to be backPatched later when expression evaluates to True.  (Inherited)
    loc - (symEntry * ).        Stores Pointer to entry in symbol table.
    array - (symEntry * ).      Stores Pointer to entry of the base array in symbol table (useful while dereferencing).
    type - (complexType * ).    Pointer of type of the expression.
    isArrayType - (bool ).      Flag to store if the expression has offset and is to be dereferenced or not.
    isPtrType - (bool ).        Flag to store if the expression points at an address and is to be dereferenced or not.

2.  nextList (List *):
	Stores the List of address which are associated jumps to next statement.
	Associated non-terminals:
	statement selection_statement iteration_statement jump_statement compound_statement block_item block_item_list N

	Attributes: (Type)
	qIdx - (int ).          	Stores the index of the quad
    head - (node * ).        	Points to the first node of the list
    tail - (node * ).         	Points to the last node of the list
	
3.  instr (int):
	Stores the instruction number.
	Associated non-terminals:
	M

4.  charVal (char):
	Associated non-terminals: (Stores the charcter of the unary operator associated.)
	unary_operator
	Associated Tokens:
	CHARCONST	(Stores the value of the character constant).

5.  dec (dec_t):
	For declaration type non terminals
	Associated non-terminals:
	declaration_specifiers declaration_list type_specifier pointer

	Attributes: (Types)
	width - (int).            	Width of the type of declaration. 
    type - (complexType * ).    Type of the declaration.  

6. 	args (vector<exp_t> *):
	Stores the list of expression for arguments and also used for storing matrix Initial values.
	Associated non-terminals:
	argument_expr_list initializer_row_list initializer_row

7.	id (idf_t):
	For identifier
	Associated tokens:
	IDENTIFIER

	Attributes:
	loc - (symEntry * ).         	Pointer to entry in symbol table
    strVal - (string * ).           Name of the indentifier.

8.	intVal (int):
	stores the integer constant
	Associated tokens:
	INTCONST

9.	doubleVal (double):
	stores the double constant
	Associated tokens:
	FLOATCONST

*/
%{
	#include <stdio.h>
	#include "ass4_15CS30006_translator.h"
	extern int yylex(void);
	int yyerror(const char *);
%}

%union {
    int intVal;			//stores Integer tokens
    double doubleVal;	//stores Double tokens
    char charVal;		//stores character tokens
    int instr;			//stores intruction number
    string * strVal;	//stores Sring Value and Names.
    exp_t exp; 			//for expression type non-terminals
    dec_t dec;			//for declaration type non-terminals
    idf_t id;			//for identifier
    symEntry * loc; 	//pointer to location in symbol table.
    List * nextList;	//instruction list for statements
    vector <exp_t *> * args; 	//List of expression for arguments and matrix Initial values.
}


%start translation_unit
%token <id>         IDENTIFIER
%token <strVal>     STRINGLITERAL
%token <intVal>     INTCONST
%token <doubleVal>  FLOATCONST
%token <charVal>    CHARCONST
%token UNSIGNED BREAK RETURN VOID CASE FLOAT SHORT CHAR FOR SIGNED WHILE GOTO BOOL CONTINUE IF DEFAULT DO INT SWITCH DOUBLE LONG MATRIX
%token OPENBRCSQ CLOSEBRCSQ OPENBRCCIR CLOSEBRCCIR OPENBRCCUR CLOSEBRCCUR DOT POINTSTO PLUSPLUS MINUSMINUS AND STAR PLUS MINUS NEGATE NOT DIVIDE PERCENT LESSLESS GREATGREAT LESS GREAT LESSEQUAL GREATEQUAL EQUALEQUAL NOTEQUAL XOR OR ANDAND OROR QUESTION EQUALS MULTIPLYEQUALS DIVIDEEQUALS MODEQUALS PLUSEQUALS MINUSEQUALS LESSLESSEQUALS GREATGREATEQUALS ANDEQUALS XOREQUALS OREQUALS COMMA HASH DOTINVERTEDCOMMA COLON SEMICOLON    
%nonassoc "then"
%nonassoc ELSE

%type <exp>   primary_expr postfix_expr unary_expr expression cast_expr additive_expr relational_expr equality_expr shift_expr logicalAND_expr inclusiveOR_expr exclusiveOR_expr logicalOR_expr conditional_expr multiplicative_expr AND_expr initializer assignment_expr constant_expr expression_statement expression_opt declarator direct_declarator init_declarator init_declarator_list
%type <nextList> statement selection_statement iteration_statement jump_statement compound_statement block_item block_item_list
%type <nextList> N
%type <instr> M
%type <charVal> unary_operator
%type <dec> declaration_specifiers declaration_list type_specifier pointer
%type <args> argument_expr_list initializer_row_list initializer_row


%%


M    :
       /* epsilon */ 
       {
          //Grammar Augmentation. nextInstruction is put in M.
          $$ = quad.nextInstr;
       }   
       ;

N    :
      /* epsilon */
      {
          //Grammar Augmentation. stores a new list containing addr of next instruction.
          $$ = new List(quad.nextInstr);
          quad.emit(quadEntry(OP_GOTO_O, ""));
      }
      ;

primary_expr:		IDENTIFIER 								 				{
																				//strVal holds the identifier name value. 
																				//lookup function returns the pointer to symbol table entry if already present, 
																				//otherwise creates a new entry and return pointer to it.
																				if(!globalSymTab->isPresent(*($1.strVal))) 
																	            	$$.loc = currentSymTab->lookUp(*($1.strVal));
																	            else $$.loc = globalSymTab->lookUp(*($1.strVal));
																	            $$.array = $$.loc;
																	            $$.type = $$.loc->type;
																	            $$.trueList = NULL;
              																	$$.falseList = NULL;
																	            printf("primary_expr -> %s\n",$1.strVal->c_str());
																        	}

					|INTCONST 												{
																				  //Creates a temp to hold the value of integer constant and sets it initial Value.
																				  complexType * typeint = new complexType(type_INT);
																				  $$.loc = currentSymTab->genTemp(typeint);
																	              $$.type = typeint;
																	              initialVal init; 
																	              init.intVal = $1;
																	              currentSymTab->update($$.loc, init);
																	              $$.trueList = NULL;
              																	  $$.falseList = NULL;
																	              quad.emit(quadEntry(OP_COPY, $$.loc->name, $1));
																	              printf("primary_expr -> %d\n",$1);
																	        }
					|FLOATCONST 											{
																				  //Creates a temp to hold the value of double constant and sets it initial Value.
																				  complexType * typeflt = new complexType(type_DOUBLE);	
																				  $$.loc = currentSymTab->genTemp(typeflt);
																	              $$.type = typeflt;
																	              initialVal init; 
																	              init.doubleVal = $1;
																	              currentSymTab->update($$.loc, init);
																	              $$.trueList = NULL;
              																	  $$.falseList = NULL;
																	              quad.emit(quadEntry(OP_COPY, $$.loc->name, $1));
																	              printf("primary_expr -> %lf\n",$1);
																	        }
					|CHARCONST 												{
																				  //Creates a temp to hold the value of character constant and sets it initial Value.
																				  complexType * typechar = new complexType(type_CHAR);	
																				  $$.loc = currentSymTab->genTemp(typechar);
																	              $$.type = typechar;
																	              initialVal init; 
																	              init.charVal = $1;
																	              currentSymTab->update($$.loc, init);
																	              $$.trueList = NULL;
              																	  $$.falseList = NULL;
																	              quad.emit(quadEntry(OP_COPY, $$.loc->name, $1));
																	              printf("primary_expr -> %c\n",$1);
																	        }
					|STRINGLITERAL 											{
																				//Not Supported
																				printf("primary_expr -> %s\n",$1);
																			}
					|OPENBRCCIR expression CLOSEBRCCIR 						{
																				$$ = $2;
																			}
;

postfix_expr:		primary_expr 											{
																				$$ = $1;
																	            $$.isArrayType = false;
																	            printf("postfix_expr -> primary_expr\n");
        																  	}
					|postfix_expr OPENBRCSQ expression CLOSEBRCSQ OPENBRCSQ expression CLOSEBRCSQ			{
																												//Grammar Augmneted to support only 2D matrices.
																												if($3.type->bType != type_INT || $6.type->bType != type_INT){
																													yyerror("Matrix indexes not integer");
																													exit(1);
																												}	
																												if(!($1.type->bType == type_MATRIX)){
																													yyerror("Not Matrix type accessedd by [][]");
																													exit(1);
																												}	
																												
																												complexType * typeint = new complexType(type_INT);
																												symEntry * temp = currentSymTab->genTemp(typeint);
																												symEntry * temp2 = currentSymTab->genTemp(typeint);

																												//Calculating the offset (with extra 2*SIZE_OF_INT for storing array dimensions).
																							                    quad.emit(quadEntry(OP_MULT, temp->name, $3.loc->name, i2s($1.type->rightIndex)));
																							                    quad.emit(quadEntry(OP_PLUS, temp->name, temp->name, $6.loc->name));
																							                    quad.emit(quadEntry(OP_MULT, temp->name, temp->name, i2s(SIZE_OF_DOUBLE)));
																							                    quad.emit(quadEntry(OP_MULT, temp2->name, i2s(SIZE_OF_INT), "2"));
																							                    quad.emit(quadEntry(OP_PLUS, temp->name, temp->name, temp2->name));

																							                    $$.loc = temp;		
																												$$.isArrayType = true;	
																												$$.type = new complexType(type_DOUBLE);
																						                    																						
																												printf("postfix_expr -> postfix_expr [ expression ] [ expression ]\n");
																											}
					|postfix_expr OPENBRCCIR CLOSEBRCCIR 					{
																				//If nestedTable == NULL, then it is not of function type.
																				$$ = $1;
																				if($1.loc->nestedTable == NULL) {
																                  yyerror("Error, not a function type accessed using ()");
																                  exit(1);
																              	}
																              	//Calling function with 0 params.
																              	$$.loc = currentSymTab->genTemp($1.loc->nestedTable->entries[0]->type);
                  																$$.type = $$.loc->type;
																              	quad.emit(quadEntry(OP_CALL, $$.loc->name, $1.loc->name,"0"));
																				printf("postfix_expr -> postfix_expr ()\n");
																			}
					|postfix_expr OPENBRCCIR argument_expr_list CLOSEBRCCIR {
																			  //If nestedTable == NULL, then it is not of function type.
																			  $$ = $1;
																              if($1.loc->nestedTable == NULL || !checkParams($1, $3)) {
																                  printf("Error");
																				  yyerror("error");
																				  exit(1);
																              } 
																                  //Calling function with size($3) params.
																                  for(int i=0;i<$3->size();i++){
																                    quad.emit(quadEntry(OP_PARAM, (*$3)[i]->loc->name));
																                  }
																    
																                  $$.loc = currentSymTab->genTemp($1.loc->nestedTable->entries[0]->type);
																                  $$.type = $$.loc->type;
																                  quad.emit(quadEntry(OP_CALL, $$.loc->name, $1.loc->name, i2s($3->size())));
																				  printf("postfix_expr -> postfix_expr ( argument_expr_list )\n");
																			}
					|postfix_expr DOT IDENTIFIER 							{
																				//Not Supported
																				printf("postfix_expr -> postfix_expr .IDENTIFIER\n");
																			}
					|postfix_expr POINTSTO IDENTIFIER 						{
																				//Not Supported
																				printf("postfix_expr -> postfix_expr ->IDENTIFIER\n");
																			}
					|postfix_expr PLUSPLUS 									{
																			  //Adds the value by 1.
																			  $$ = $1;
																			  complexType * thisType = $1.type;
																              $$.loc = currentSymTab->genTemp(thisType);
																              $$.type = thisType;

																              if($1.isArrayType) {
																                  // if it is array type we need to dereference the array first and then increment
																                  quad.emit(quadEntry(OP_R_INDEX, $$.loc->name, $1.array->name, $1.loc->name));
																                  symEntry * temp = currentSymTab->genTemp(new complexType(type_DOUBLE));
																                  quad.emit(quadEntry(OP_PLUS, temp->name, $$.loc->name, "1"));
																                  quad.emit(quadEntry(OP_L_INDEX, $1.array->name, $1.loc->name, temp->name));
																              } else {
																                  quad.emit(quadEntry(OP_COPY, $$.loc->name, $1.loc->name));
																                  quad.emit(quadEntry(OP_PLUS, $1.loc->name, $1.loc->name, "1"));
																              }
																              $$.isArrayType = false;
																              printf("postfix_expr -> postfix_expr ++\n");
																          	}
					|postfix_expr MINUSMINUS 								{
																			  //Subtracts the value by 1.
																			  $$ = $1;
																			  complexType * thisType = $1.type;
																              $$.loc = currentSymTab->genTemp(thisType);
																              $$.type = thisType;

																              if($1.isArrayType) {
																                  // if it is array type we need to dereference the array first and then decrement
																                  quad.emit(quadEntry(OP_R_INDEX, $$.loc->name, $1.array->name, $1.loc->name));
																                  symEntry * temp = currentSymTab->genTemp(new complexType(type_DOUBLE));
																                  quad.emit(quadEntry(OP_MINUS, temp->name, $$.loc->name, "1"));
																                  quad.emit(quadEntry(OP_L_INDEX, $1.array->name, $1.loc->name, temp->name));
																              } else {
																                  quad.emit(quadEntry(OP_COPY, $$.loc->name, $1.loc->name));
																                  quad.emit(quadEntry(OP_MINUS, $1.loc->name, $1.loc->name, "1"));
																              }
																              $$.isArrayType = false;
																			  printf("postfix_expr -> postfix_expr --\n");
																			}
					|postfix_expr DOTINVERTEDCOMMA 							{
																				//if Not matrix type, transpose is invalid
																				if($1.loc->type->bType != type_MATRIX){
																					yyerror("Invalid operand for transpose operation");
																					exit(1);
																				}
																				complexType * typemat = new complexType($1.loc->type);
																				typemat->leftIndex = $1.loc->type->rightIndex;
																				typemat->rightIndex = $1.loc->type->leftIndex;
																				//Inverted dimensions for transposed matrix.
																				$$.loc = currentSymTab->genTemp(typemat);
																				$$.array = $$.loc;
																				$$.type = typemat;
																				quad.emit(quadEntry(OP_TRANS,$$.loc->name,$1.loc->name));
																				printf("postfix_expr -> postfix_expr .'\n");
																			}
;

argument_expr_list:			assignment_expr  								{
																				$$ = new vector<exp_t *> ();
																				$$->push_back(new exp_t($1));
																				printf("argument_expr_list -> assignment_expr\n");
																			}
							|argument_expr_list COMMA assignment_expr 		{
																				$$ = $1;
																				$$->push_back(new exp_t($3));
																				printf("argument_expr_list -> argument_expr_list , assignment_expr\n");
																			}
;


unary_expr:			postfix_expr  											{
																				$$ = $1; 
																				printf("unary_expr -> postfix_expr\n");
																			}
					|PLUSPLUS unary_expr									{
																			  //Adds the value by 1.
																			  $$ = $2;
																			  complexType * thisType = $2.type;
																              $$.loc = currentSymTab->genTemp(thisType);
																              $$.type = thisType;

																              if($2.isArrayType) {
																                  // we need to dereference the array
																                  symEntry * tmp = currentSymTab->genTemp(new complexType(type_DOUBLE));
																                  quad.emit(quadEntry(OP_R_INDEX, $$.loc->name, $2.array->name, $2.loc->name));
																                  quad.emit(quadEntry(OP_PLUS, tmp->name, $$.loc->name, "1"));
																                  quad.emit(quadEntry(OP_L_INDEX, $2.array->name, $2.loc->name, tmp->name));
																                  $$.loc = tmp;
																              } else {
																                  quad.emit(quadEntry(OP_PLUS, $2.loc->name, $2.loc->name, "1"));
																                  quad.emit(quadEntry(OP_COPY, $$.loc->name, $2.loc->name));
																              }
																              $$.isArrayType = false;
																			  printf("unary_expr -> ++ unary_expr\n");
																			}
					|MINUSMINUS unary_expr									{
																			  //Subtracts the value by 1.
																			  $$ = $2;
																			  complexType * thisType = $2.type;
																              $$.loc = currentSymTab->genTemp(new complexType(type_DOUBLE));
																              $$.type = thisType;

																              if($2.isArrayType) {
																                  // we need to dereference the array
																                  symEntry * tmp = currentSymTab->genTemp(thisType);
																                  quad.emit(quadEntry(OP_R_INDEX, $$.loc->name, $2.array->name, $2.loc->name));
																                  quad.emit(quadEntry(OP_MINUS, tmp->name, $$.loc->name, "1"));
																                  quad.emit(quadEntry(OP_L_INDEX, $2.array->name, $2.loc->name, tmp->name));
																                  $$.loc = tmp;
																              } else {
																                  quad.emit(quadEntry(OP_MINUS, $2.loc->name, $2.loc->name, "1"));
																                  quad.emit(quadEntry(OP_COPY, $$.loc->name, $2.loc->name));
																              }
																              $$.isArrayType = false;
																			  printf("unary_expr -> -- unary_expr\n");
																			}
					|unary_operator cast_expr								{
																				$$.trueList = NULL;
              																	$$.falseList = NULL;
																				switch($1)
																				{
																					case '&':
																					{
																						//Creates a new pointer type temp.
																						complexType * typeptr = new complexType(type_PTR);
																						typeptr->next = $2.type;
																						$$.loc = currentSymTab->genTemp(typeptr);
																	                    $$.type = typeptr;
																	                    if(!$2.isArrayType) quad.emit(quadEntry(OP_ADDR, $$.loc->name, $2.loc->name));
																	                    else quad.emit(quadEntry(OP_PLUS, $$.loc->name, $2.array->name, $2.loc->name));
																	                    break;
																	                }
																	                
																	                case '*':
																	                {
																	                	  if($2.type->next == NULL) {
																	                        yyerror("Error no ptr");
																	                        exit(1);
																	                      }
																	                      $$ = $2;
																	                      $$.type = $2.type->next;
																	                      //Means it has to be dereferenced.
																	                      $$.isPtrType = true;
																	                	  break;
																	                }
																	                case '+':
																	                {
																	                     if($2.isPtrType){
																	                     	//defernce first
																	                        $2.isPtrType = false;
																	                     	complexType * thisType = $2.type;
																	                        symEntry * temp = currentSymTab->genTemp(thisType);
																	                        quad.emit(quadEntry(OP_R_VAL_AT, temp->name, $2.loc->name));
																	                        $2.loc = temp;
																	                        
																	                    } else if($2.isArrayType) {
																	                    	//defernce first
																	                        complexType * thisType = $2.type;
																	                        symEntry * temp = currentSymTab->genTemp(new complexType(type_DOUBLE));
																	                        quad.emit(quadEntry(OP_R_INDEX, temp->name, $2.array->name, $2.loc->name));
																	                        $2.loc = temp;
																	                        $2.isArrayType = false;
																	                    }
																	                    $$ = $2;
																	                    break;
																	                }
																	                case '-':
																	                {
																	                	complexType	* thisType = $2.type;
																	                    if($2.isPtrType) {
																	                    	//defernce first
																	                        symEntry * temp = currentSymTab->genTemp(thisType);
																	                        quad.emit(quadEntry(OP_R_VAL_AT, temp->name, $2.loc->name));
																	                        $2.loc = temp;
																	                        $2.isPtrType = false;
																	                    } else if($2.isArrayType)  {
																	                    	//defernce first
																	                    	complexType * thisType = $2.type;
																	                        symEntry * temp = currentSymTab->genTemp(new complexType(type_DOUBLE));
																	                        quad.emit(quadEntry(OP_R_INDEX, temp->name, $2.array->name, $2.loc->name));
																	                        $2.loc = temp;
																	                        $2.isArrayType = false;
																	                    }
																	                    $$.loc = currentSymTab->genTemp(thisType);
																	                    $$.type = thisType;
																	                    quad.emit(quadEntry(OP_UMINUS, $$.loc->name, $2.loc->name));
																	                    break;
																	                }
																				}
																				printf("unary_expr -> unary_operator cast_expr\n");
																			}
;

unary_operator:		AND 													{
																				$$ = '&';
																				printf("unary_operator -> &\n");
																			}
					|STAR													{
																				$$ = '*';
																				printf("unary_operator -> *\n");
																			}
					|PLUS													{
																				$$ = '+';
																				printf("unary_operator -> +\n");
																			}
					|MINUS													{
																				$$ = '-';
																				printf("unary_operator -> -\n");
																			}
;

cast_expr:			unary_expr 												{
																				$$ = $1;
																				printf("cast_expr -> unary_expr\n");
																			}
;

multiplicative_expr:		cast_expr 										{
																		 	  //This ensures that multiplicative_expr in every rule has dereferred value
																			  $$ = $1;
																              if($1.isPtrType) {
																              	  //defernce first
																                  $1.isPtrType = false;
																                  $$.loc = currentSymTab->genTemp($1.type);
																                 //cout<<($1.array==NULL)<<endl;
																                  quad.emit(quadEntry(OP_R_VAL_AT, $$.loc->name, $1.loc->name));
																              } else if($1.isArrayType) {
																              	  //defernce first
																                  $$.loc = currentSymTab->genTemp(new complexType(type_DOUBLE));
																                  quad.emit(quadEntry(OP_R_INDEX, $$.loc->name, $1.array->name, $1.loc->name));
																                  $1.isArrayType = false;
																              }
																              printf("multiplicative_expr -> cast_expr\n");
																          	}
							|multiplicative_expr STAR cast_expr 			{

																			  complexType * thisType = $3.type;
																			  if($3.isPtrType) {
																			  	  //defernce first
																                  symEntry * temp = currentSymTab->genTemp(thisType);
																                  quad.emit(quadEntry(OP_R_VAL_AT, temp->name, $3.loc->name));
																                  $3.loc = temp;
																                  $3.isPtrType = false;																                  
																              } else if($3.isArrayType) {
																              	  //defernce first
																                  symEntry * temp = currentSymTab->genTemp(new complexType(type_DOUBLE));
																                  quad.emit(quadEntry(OP_R_INDEX, temp->name, $3.array->name, $3.loc->name));
																                  $3.loc = temp;
																                  $3.isArrayType = false;
																              }
																              
																              $$ = $1;
																              if(!(typeCheck(&($1), &($3),false,true))){
																              	yyerror("Incompatible types");
																              	exit(1);
																              }
																              //printf("I am HERE ############################\n");
																              //thisType->print();$1.type->print();$3.type->print();
																              bool matrixMultiplication = false;
																              //Handline matrices differently.
																              if($1.loc->type->bType == type_MATRIX && $3.loc->type->bType == type_MATRIX){
																              	if($1.loc->type->rightIndex == $3.loc->type->leftIndex){
																              		matrixMultiplication = true;
																              	}
																              	else{
																              		yyerror("Matrix dimension not compatible for multiplication");
																              		exit(1);
																              	}
																              }
																              
																              //dimension of resultant matrix. R = A*B, A(m*k) B(k*n) => R(m*n)
																              if(matrixMultiplication){
																              	thisType = new complexType(type_MATRIX);
																              	thisType->leftIndex = $1.loc->type->leftIndex;
																              	thisType->rightIndex = $3.loc->type->rightIndex;
																              	thisType = new complexType(thisType);
																              	printf("THIS TYPE SIZE = %d\n",thisType->getSize());
																              }
																              else{
																              	  thisType = $3.type;
																              }

																              $$.loc = currentSymTab->genTemp(thisType);
																	          $$.type = $$.loc->type;
																              quad.emit(quadEntry(OP_MULT, $$.loc->name, $1.loc->name, $3.loc->name));
																              printf("multiplicative_expr -> multiplicative_expr * cast_expr\n");
																            }
							|multiplicative_expr DIVIDE cast_expr 			{
																			  complexType * thisType = $3.type;
																			  if($3.isPtrType) { 
																			  	  //defernce first
																                  symEntry * temp = currentSymTab->genTemp(thisType);
																                  quad.emit(quadEntry(OP_R_VAL_AT, temp->name, $3.loc->name));
																                  $3.loc = temp;
																                  $3.isPtrType = false;																                  
																              } else if($3.isArrayType) {
																              	  //defernce first
																                  symEntry * temp = currentSymTab->genTemp(new complexType(type_DOUBLE));
																                  quad.emit(quadEntry(OP_R_INDEX, temp->name, $3.array->name, $3.loc->name));
																                  $3.loc = temp;
																                  $3.isArrayType = false;
																              }
																              $$ = $1;
																              if(!(typeCheck(&($1), &($3)))){
																              	yyerror("Incompatible types");
																              	exit(1);
																              }
																              //Division not supported for matrix types.
																              if($1.type->bType == type_MATRIX || $3.type->bType == type_MATRIX){
																              	yyerror("Matrices cannot be divided");
																              	exit(1);
																              }
																              thisType = $3.type;
																              $$.loc = currentSymTab->genTemp(thisType);
																              $$.type = $$.loc->type;
																              quad.emit(quadEntry(OP_DIV, $$.loc->name, $1.loc->name, $3.loc->name));
																              printf("multiplicative_expr -> multiplicative_expr / cast_expr\n");
																          }
							|multiplicative_expr PERCENT cast_expr 		  {

																			  complexType * thisType = $3.type;
																			  if($3.isPtrType) {
																			  	  //defernce first
																                  symEntry * temp = currentSymTab->genTemp(thisType);
																                  quad.emit(quadEntry(OP_R_VAL_AT, temp->name, $3.loc->name));
																                  $3.loc = temp;
																                  $3.isPtrType = false;																                  
																              } else if($3.isArrayType) {
																              	  //defernce first
																                  symEntry * temp = currentSymTab->genTemp(new complexType(type_DOUBLE));
																                  quad.emit(quadEntry(OP_R_INDEX, temp->name, $3.array->name, $3.loc->name));
																                  $3.loc = temp;
																                  $3.isArrayType = false;
																              }
																              $$ = $1;
																              if(!(typeCheck(&($1), &($3)))){
																              	yyerror("Incompatible types");
																              	exit(1);
																              }
																               //MOD not supported for Matrix
																              if($1.type->bType == type_MATRIX || $3.type->bType == type_MATRIX){
																              	yyerror("% inavlid for matrices");
																              	exit(1);
																              }
																              if(!($1.type->bType == type_INT && $3.type->bType == type_INT)){
																              	yyerror("Error. % operation for non-int type");
																              	exit(1);
																              }
																              thisType = $3.type;
																              $$.loc = currentSymTab->genTemp(thisType);
																              $$.type = $$.loc->type;
																              quad.emit(quadEntry(OP_MOD, $$.loc->name, $1.loc->name, $3.loc->name));
																              printf("multiplicative_expr -> multiplicative_expr %% cast_expr\n");
																          }
;


additive_expr:				multiplicative_expr 							{
																				$$ = $1;
																				printf("additive_expr -> multiplicative_expr\n");
																			}
							|additive_expr PLUS multiplicative_expr    		{
																			  $$ = $1;
																              if(!(typeCheck(&($1), &($3)))){
																              	yyerror("Incompatible types");
																              	exit(1);
																              }

																              complexType * typeop1 = new complexType($1.type);
																              complexType * typeop2 = new complexType($3.type);
																              if(typeop1->bType == type_MATRIX && typeop2->bType == type_MATRIX){
																              	if(!(typeop1->leftIndex == typeop2->leftIndex && typeop1->rightIndex == typeop2->rightIndex)){
																              		yyerror("matrics size incompatible for +");
																              		exit(1);
																              	}
																              }
																              $$.loc = currentSymTab->genTemp(typeop2);
																              $$.type = $$.loc->type;
																              quad.emit(quadEntry(OP_PLUS, $$.loc->name, $1.loc->name, $3.loc->name));
																              printf("additive_expr -> additive_expr + multiplicative_expr\n");
																          	}
							|additive_expr MINUS multiplicative_expr 		{
																			  $$ = $1;
																              typeCheck(&($1), &($3));
																              complexType * typeop1 = new complexType($1.type);
																              complexType * typeop2 = new complexType($3.type);
																              if(typeop1->bType == type_MATRIX && typeop2->bType == type_MATRIX){
																              	if(!(typeop1->leftIndex == typeop2->leftIndex && typeop1->rightIndex == typeop2->rightIndex)){
																              		yyerror("matrics size incompatible for -");
																              		exit(1);
																              	}
																              }
																              $$.loc = currentSymTab->genTemp(typeop2);
																              $$.type = $$.loc->type;
																              quad.emit(quadEntry(OP_MINUS, $$.loc->name, $1.loc->name, $3.loc->name));
																              printf("additive_expr -> additive_expr - multiplicative_expr\n");
																          	}
;

				
shift_expr:					additive_expr 									{
																				$$ = $1;
																				printf("shift_expr -> additive_expr\n");
																			}
							|shift_expr LESSLESS additive_expr 				{
																			  exp_t e; 
																			  complexType * typeint = new complexType(type_INT);
																			  e.type = typeint;
																			  //Invalid for double.
																              if($1.type->bType == type_DOUBLE || !typeCheck(&e, &($1), true)) {
																                  yyerror("Error Invalid type for left shift\n");
																                  exit(1);
																              }
																              //Invalid for double.
																              if($3.type->bType == type_DOUBLE || !typeCheck(&e, &($3), true)) {
																                  yyerror("Error Invalid type for left shift\n");
																                  exit(1);
																              }
																              $$ = $1;
																              $$.loc = currentSymTab->genTemp(typeint);
																              $$.type = typeint;
																              quad.emit(quadEntry(OP_SHL, $$.loc->name, $1.loc->name, $3.loc->name));
																              printf("shift_expr -> shift_expr << additive_expr\n");
																          }
							|shift_expr GREATGREAT additive_expr 			{
																			  exp_t e; 
																			  complexType * typeint = new complexType(type_INT);
																			  e.type = typeint;
																			  //Invalid for double.
																              if($1.type->bType == type_DOUBLE || !typeCheck(&e, &($1), true)) {
																                  yyerror("Error Invalid type for left shift\n");
																                  exit(1);
																              }
																              //Invalid for double.
																              if($3.type->bType == type_DOUBLE || !typeCheck(&e, &($3), true)) {
																                  yyerror("Error Invalid type for right shift\n");
																                  exit(1);
																              }
																              $$ = $1;
																              $$.loc = currentSymTab->genTemp(typeint);
																              $$.type = typeint;
																              quad.emit(quadEntry(OP_SHR, $$.loc->name, $1.loc->name, $3.loc->name));
																              printf("shift_expr -> shift_expr >> additive_expr\n");
																          	}
;


relational_expr:			shift_expr 										{
																				$$ = $1;
																				printf("relational_expr -> shift_expr\n");
																			}
							|relational_expr LESS shift_expr 				{
																			  typeCheck(&($1), &($3));
																			  //Invalid for Matrix.
																			  if($1.loc->type->bType == type_MATRIX || $3.loc->type->bType == type_MATRIX){
																			  	yyerror("Matrices can't be compared");
																			  	exit(1);
																			  }
																			  complexType * typebool = new complexType(type_BOOL);
																              $$.type = typebool;
																              $$.trueList = new List(quad.nextInstr);
																              quad.emit(quadEntry(OP_JLT, "", $1.loc->name, $3.loc->name));
																              $$.falseList = new List(quad.nextInstr);
																              quad.emit(quadEntry(OP_GOTO_O, ""));
																              printf("relational_expr -> relational_expr < shift_expr\n");

																          	}
							|relational_expr GREAT shift_expr 				{
																			  typeCheck(&($1), &($3));
																			  //Invalid for Matrix.
																			  if($1.loc->type->bType == type_MATRIX || $3.loc->type->bType == type_MATRIX){
																			  	yyerror("Matrices can't be compared");
																			  	exit(1);
																			  }
																			  complexType * typebool = new complexType(type_BOOL);
																              $$.type = typebool;
																              $$.trueList = new List(quad.nextInstr);
																              quad.emit(quadEntry(OP_JGT, "", $1.loc->name, $3.loc->name));
																              $$.falseList = new List(quad.nextInstr);
																              quad.emit(quadEntry(OP_GOTO_O, ""));
																              printf("relational_expr -> relational_expr > shift_expr\n");
																          	}
							|relational_expr LESSEQUAL shift_expr 			{
																			  typeCheck(&($1), &($3));
																			  //Invalid for Matrix.
																			  if($1.loc->type->bType == type_MATRIX || $3.loc->type->bType == type_MATRIX){
																			  	yyerror("Matrices can't be compared");
																			  	exit(1);
																			  }
																			  complexType * typebool = new complexType(type_BOOL);
																              $$.type = typebool;
																              $$.trueList = new List(quad.nextInstr);
																              quad.emit(quadEntry(OP_JLE, "", $1.loc->name, $3.loc->name));
																              $$.falseList = new List(quad.nextInstr);
																              quad.emit(quadEntry(OP_GOTO_O, ""));
																              printf("relational_expr -> relational_expr <= shift_expr\n");
																          	}
							|relational_expr GREATEQUAL shift_expr 			{
																			  typeCheck(&($1), &($3));
																			  //Invalid for Matrix.
																			  if($1.loc->type->bType == type_MATRIX || $3.loc->type->bType == type_MATRIX){
																			  	yyerror("Matrices can't be compared");
																			  	exit(1);
																			  }
																			  complexType * typebool = new complexType(type_BOOL);
																              $$.type = typebool;
																              $$.trueList = new List(quad.nextInstr);
																              quad.emit(quadEntry(OP_JGE, "", $1.loc->name, $3.loc->name));
																              $$.falseList = new List(quad.nextInstr);
																              quad.emit(quadEntry(OP_GOTO_O, ""));
																              printf("relational_expr -> relational_expr >= shift_expr\n");
																          	}
;


equality_expr:				relational_expr 								{
																				$$ = $1;
																				printf("equality_expr -> relational_expr\n");
																			}
							|equality_expr EQUALEQUAL relational_expr 		{
																			  typeCheck(&($1), &($3));
																			  complexType * typebool = new complexType(type_BOOL);
																              $$.type = typebool;
																              $$.trueList = new List(quad.nextInstr);
																              quad.emit(quadEntry(OP_EQ, "", $1.loc->name, $3.loc->name));
																              $$.falseList = new List(quad.nextInstr);
																              quad.emit(quadEntry(OP_GOTO_O, ""));
																              printf("equality_expr -> equality_expr == relational_expr\n");
																          	}
							|equality_expr NOTEQUAL relational_expr 		{
																			  typeCheck(&($1), &($3));
																			  complexType * typebool = new complexType(type_BOOL);
																              $$.type = typebool;
																              $$.trueList = new List(quad.nextInstr);
																              quad.emit(quadEntry(OP_NEQ, "", $1.loc->name, $3.loc->name));
																              $$.falseList = new List(quad.nextInstr);
																              quad.emit(quadEntry(OP_GOTO_O, ""));
																              printf("equality_expr -> equality_expr != relational_expr\n");
																          	}
;


AND_expr:					equality_expr 									{
																				$$ = $1;
																				printf("AND_expr -> equality_expr\n");
																			}	
							|AND_expr AND equality_expr						{
																			  exp_t e ; 
																			  complexType * typeint = new complexType(type_INT);
																			  e.type = typeint;
																			  //Invalid for double.
																              if($1.type->bType == type_DOUBLE || !typeCheck(&e, &($1), true)) {
																                  yyerror("Error Invalid type for &\n");
																                  exit(1);
																              }
																              //Invalid for double.
																              if($3.type->bType == type_DOUBLE || !typeCheck(&e, &($3), true)) {
																                  yyerror("Error Invalid type for &\n");
																                  exit(1);
																              }
																              $$ = $1;
																              $$.loc = currentSymTab->genTemp(typeint);
																              $$.type = $$.loc->type;
																              quad.emit(quadEntry(OP_BW_AND, $$.loc->name, $1.loc->name, $3.loc->name));
																              printf("AND_expr -> AND_expr & equality_expr\n");
																          	}
;

exclusiveOR_expr:			AND_expr 										{
																				$$ = $1;
																				printf("exclusiveOR_expr -> AND_expr\n");
																			}
							|exclusiveOR_expr XOR AND_expr 					{
																			  exp_t e ; 
																			  complexType * typeint = new complexType(type_INT);
																			  e.type = typeint;
																			  //Invalid for double.
																              if($1.type->bType == type_DOUBLE || !typeCheck(&e, &($1), true)) {
																                  yyerror("Error Invalid type for ^\n");
																                  exit(1);
																              }
																              //Invalid for double.
																              if($3.type->bType == type_DOUBLE || !typeCheck(&e, &($3), true)) {
																                  yyerror("Error Invalid type for ^\n");
																                  exit(1);
																              }
																              $$ = $1;
																              $$.loc = currentSymTab->genTemp(typeint);
																              $$.type = $$.loc->type;
																              quad.emit(quadEntry(OP_BW_XOR, $$.loc->name, $1.loc->name, $3.loc->name));
																              printf("exclusiveOR_expr -> exclusiveOR_expr ^ AND_expr \n");
																          	}
;


inclusiveOR_expr:			exclusiveOR_expr								{
																				$$ = $1;
																				printf("inclusiveOR_expr -> exclusiveOR_expr\n");
																			}
							|inclusiveOR_expr OR exclusiveOR_expr			{
																			  exp_t e ; 
																			  complexType * typeint = new complexType(type_INT);
																			  e.type = typeint;
																			  //Invalid for double.
																              if($1.type->bType == type_DOUBLE || !typeCheck(&e, &($1), true)) {
																                  yyerror("Error Invalid type for |\n");
																                  exit(1);
																              }
																              //Invalid for double.
																              if($3.type->bType == type_DOUBLE || !typeCheck(&e, &($3), true)) {
																                  yyerror("Error Invalid type for |\n");
																                  exit(1);
																              }
																              $$ = $1;
																              $$.loc = currentSymTab->genTemp(typeint);
																              $$.type = $$.loc->type;
																              quad.emit(quadEntry(OP_BW_OR, $$.loc->name, $1.loc->name, $3.loc->name));
																              printf("inclusiveOR_expr -> inclusiveOR_expr | exclusiveOR_expr\n");
																          	}
;

logicalAND_expr:			inclusiveOR_expr 								{
																				$$ = $1;
																				printf("logicalAND_expr -> inclusiveOR_expr\n");
																			}
							|logicalAND_expr ANDAND M inclusiveOR_expr 		{
																			  //Grammar Augmentation M to help backPatch.
																			  //backPatch all of $1's trueList
																			  backPatch($1.trueList, $3);
																			  complexType * typebool = new complexType(type_BOOL);
																              $$.type = typebool;
																              $$.trueList = $4.trueList;
																              //Merge the falseList of $1 with that of $4.
																              $$.falseList = mergeList($1.falseList, $4.falseList);
																              printf("inclusiveOR_expr -> logicalAND_expr && inclusiveOR_expr\n");
																          	}
;

logicalOR_expr:				logicalAND_expr 								{
																				$$ = $1;
																				printf("logicalOR_expr -> logicalAND_expr\n");
																			}
							|logicalOR_expr OROR M logicalAND_expr			{
																			  //Grammar Augmentation M to help backPatch.
																			  //backPatch all of $1's trueList
																			  backPatch($1.falseList, $3);
																			  complexType * typebool = new complexType(type_BOOL);
																              $$.type = typebool;
																              //Merge the trueList of $1 with that of $4.
																              $$.trueList = mergeList($1.trueList, $4.trueList);
																              $$.falseList = $4.falseList;
																              printf("logicalOR_expr -> logicalOR_expr || logicalAND_expr\n");
																          	}
;

conditional_expr:			logicalOR_expr 													{
																								$$ = $1;
																								printf("conditional_expr -> logicalOR_expr\n");
																							}
							|logicalOR_expr N QUESTION M expression N COLON M conditional_expr 	 	{
																			  						  //Grammar Augmentation N & M to help backPatch.
																									  complexType * typeexpr = $5.type;
																									  $$.loc = currentSymTab->genTemp(typeexpr);
																						              quad.emit(quadEntry(OP_COPY, $$.loc->name, $9.loc->name));
																						              List * l = new List(quad.nextInstr);
																						              quad.emit(quadEntry(OP_GOTO_O, ""));
																						              backPatch($6, quad.nextInstr);

																						              quad.emit(quadEntry(OP_COPY, $$.loc->name, $5.loc->name));
																						              l = mergeList(l, new List(quad.nextInstr));
																						              quad.emit(quadEntry(OP_GOTO_O, ""));
																						              //N holds the next Instruction in list entry.
																						              backPatch($2, quad.nextInstr);
																						              conv2Bool(&($1));
																						              backPatch($1.trueList, $4);
																						              backPatch($1.falseList, $8);
																						              backPatch(l, quad.nextInstr);
																						              printf("conditional_expr -> logicalOR_expr ? expression : conditional_expr \n");
																						          	}
;

assignment_expr:			conditional_expr  								{
																				$$ = $1;
																				printf("assignment_expr -> conditional_expr\n");
																			}
							|unary_expr assignment_operator assignment_expr {
																			  //Ptr can't be assigned to double
																			  if($1.type->bType == type_PTR) {
																                  if($3.type->bType == type_DOUBLE) yyerror("Error assignment");
																                  else quad.emit(quadEntry(OP_COPY, $1.loc->name, $3.loc->name));																                  
																              }
																              else {
																              	//printf("$1 type %d\n",$1.type->bType);
																                  typeCheck(&($1), &($3), true);
																                  if($1.isArrayType) {
																                      quad.emit(quadEntry(OP_L_INDEX, $1.array->name, $1.loc->name, $3.loc->name));
																                      $1.isArrayType = false;
																                  } else if($1.isPtrType) {
																                      quad.emit(quadEntry(OP_L_VAL_AT, $1.loc->name, $3.loc->name));
																                      $1.isPtrType = false;
																                  } else {
																                      quad.emit(quadEntry(OP_COPY, $1.loc->name, $3.loc->name));
																                  }
																              }
																              $$ = $3;
																              printf("assignment_expr -> unary_expr assignment_operator assignment_expr\n");
																          	}
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

expression:					assignment_expr									{
																				$$ = $1;
																				printf("expression -> assignment_expr\n");
																			}
							|expression COMMA assignment_expr				{
																				$$ = $3;
																				printf("expression -> expression , assignment_expr\n");
																			}
;

expression_opt:				expression 										{
																				$$ = $1;
																				printf("expression_opt -> expression\n");
																			}
							| 												{
																				complexType * typebool = new complexType(type_BOOL);
																				$$.type = typebool;
																				$$.trueList = NULL;
            																	$$.falseList = NULL;
																				printf("expression_opt -> \n");
																			}
;

constant_expr:				conditional_expr								{
																				$$ = $1;
																				printf("constant_expr -> conditional_expr\n");
																			}
;

declaration:        declaration_specifiers SEMICOLON            			{printf("declaration -> declaration_specifiers ;\n");}
              		|declaration_specifiers init_declarator_list SEMICOLON  {
              																  //New function.
							                                            	  if($2.type->bType == type_FUNC) {
							                                                      currentSymTab = new symTable();
							                                                  }
							                                                  printf("declaration -> declaration_specifiers init_declarator_list ;\n");
						                                             		 }
;

declaration_specifiers:   type_specifier                    {
				                                          		$$.type = $1.type;
				                                                $$.width = $1.width;
				                                                quad.type = $1.type;
				                                                quad.width = $1.width;
				                                                printf("declaration_specifiers -> type_specifier\n");
				                                            }
              |type_specifier declaration_specifiers        {
				                                          		$$.type = $1.type;
				                                                $$.width = $1.width;
				                                                quad.type = $1.type;
				                                                quad.width = $1.width;
				                                                printf("declaration_specifiers -> type_specifier declaration_specifiers\n");
				                                            }
;

init_declarator_list:       init_declarator                   {
						                                          $$ = $1;
						                                          printf("init_declarator_list -> init_declarator\n");
						                                      }
              |init_declarator_list COMMA init_declarator     {
						                                          $$ = $3;
						                                          printf("init_declarator_list -> init_declarator_list , init_declarator  \n");
						                                      }
;
  
init_declarator:      declarator                        {
					                                          $$ = $1;
					                                          printf("init_declarator -> declarator\n");
					                                    }
            |declarator EQUALS initializer              {


		                                          		  if(!typeCheck(&($1), &($3), true)){
		                                          		  	yyerror("Incompatible types");
		                                          		  	exit(1);
		                                          		  }

		                                          		  //printf("HEERE######################\n%s\n%s\n",$1.loc->name.c_str(),$3.loc->name.c_str());
		                                          		  //update the value at $1.
		                                                  if($3.loc->wasInitialised) currentSymTab->update($1.loc, $3.loc->init);

		                                                  if($3.loc->type->bType != type_MATRIX){
		                                                  	//Since Initilized Matrix is already handled.
		                                                  	quad.emit(quadEntry(OP_COPY, $1.loc->name, $3.loc->name));
		                                                  }
		                                                  else{
		                                                  	if(!$3.loc->wasInitialised){
		                                                  		quad.emit(quadEntry(OP_COPY, $1.loc->name, $3.loc->name));
		                                                  	}
		                                                  }
		                                                  $$ = $1;
		                                                  printf("init_declarator -> declarator = initializer\n");
		                                                }
;  

type_specifier:     VOID                          {
			                                          $$.type = new complexType(type_VOID);
			                                          $$.width = SIZE_OF_VOID;
			                                          printf("type_specifier -> void\n");
			                                      }
		            |CHAR                         {
			                                          $$.type = new complexType(type_CHAR);
			                                          $$.width = SIZE_OF_CHAR;
			                                          printf("type_specifier -> char\n");
		                                          }
		            |SHORT                        {
										            	//Not supportedd
										            	printf("type_specifier -> short\n");
										          }
		            |INT                          {
			                                          $$.type = new complexType(type_INT);
			                                          $$.width = SIZE_OF_INT;
			                                          printf("type_specifier -> int\n");
		                                          }
		            |LONG                         {
									            	//Not supported
									            	printf("type_specifier -> long\n");
									              }
		            |FLOAT                        {
										            	//Not supported
										            	printf("type_specifier -> float\n");
										          }
		            |DOUBLE                       {
			                                          $$.type = new complexType(type_DOUBLE);
			                                          $$.width = SIZE_OF_DOUBLE;
			                                          printf("type_specifier -> double\n");
		                                          }
		            |MATRIX                       {
										            	$$.type = new complexType(type_MATRIX);
										            	$$.width = 0;
										            	printf("type_specifier -> Matrix\n");
										          }
		            |SIGNED                       {
									            	//Not Supported
									            	printf("type_specifier -> signed\n");
									              }
		            |UNSIGNED                     {
									            	//Not Supported
									            	printf("type_specifier -> unsigned\n");
									              }
		            |BOOL                         {
									            	//Not Supported
									            	printf("type_specifier -> bool\n");
									              }
;


declarator:       direct_declarator                   {
				                                          $$ = $1;
				                                          printf("declarator -> direct_declarator\n");
				                                      }
            |pointer direct_declarator                {

		                                            	  complexType * head = new complexType(type_VOID);
		                                                  complexType * toChange;
		                                                  if($2.loc->nestedTable == NULL) toChange = $2.type;
		                                                  else toChange = $2.loc->nestedTable->entries[0]->type;

		                                                  head->next = toChange;

		                                                  complexType * ptr = head;

		                                                  int oldSize = $2.loc->size;
		                                                  if($2.loc->nestedTable != NULL) oldSize = $2.loc->nestedTable->entries[0]->size;
		                                                  int newSize = SIZE_OF_PTR;
		                                                  
		                                                  while(ptr->next->next != NULL) {
		                                                      newSize *= ptr->size;
		                                                      ptr = ptr->next;
		                                                  }

		                                                  complexType * ptr2 = $1.type;
		                                                  while(ptr2->next != NULL) ptr2 = ptr2->next;
		                                                  ptr2->next = ptr->next;
		                                                  ptr->next = $1.type; 
		                                                 
		                                                  if($2.loc->nestedTable == NULL) {
		                                                      currentSymTab->offset += newSize - oldSize; 
		                                                      $2.loc->type = head->next;
		                                                      $2.loc->size = newSize;
		                                                      $2.type = $2.loc->type;
		                                                  } else {
		                                                      for(int i = 1; i < (int)$2.loc->nestedTable->entries.size(); ++i) {
		                                                          $2.loc->nestedTable->entries[i]->offset += newSize - oldSize;
		                                                      }
		                                                      $2.loc->nestedTable->entries[0]->type = head->next;
		                                                      $2.loc->nestedTable->entries[0]->size = newSize;
		                                                      $2.loc->nestedTable->offset += newSize - oldSize;
		                                                      $2.type = head->next;
		                                                  }
		                                                  $$ = $2;
		                                                  
		                                                  delete head;
		                                                  printf("declarator -> pointer direct_declarator\n");
		                                            }
;

direct_declarator:    IDENTIFIER                            {
                                              					$$.loc = currentSymTab->lookUp(*($1.strVal));
			                                                    currentSymTab->update($$.loc, quad.type, quad.width);
			                                                    $$.type = $$.loc->type;
			                                                    printf("direct_declarator -> IDENTIFIER\n");
			                                                }
            |OPENBRCCIR declarator CLOSEBRCCIR                {
					                                              $$ = $2;
					                                              printf("direct_declarator -> ( declarator )\n");
					                                          }
            |direct_declarator OPENBRCSQ CLOSEBRCSQ             {
					                                              //Matrices of undefined size is not Supported.
					                                              printf("direct_declarator -> direct_declarator []\n");
					                                            }
            |direct_declarator OPENBRCSQ assignment_expr CLOSEBRCSQ OPENBRCSQ assignment_expr CLOSEBRCSQ  { //Grammar Augmentation. Supports only 2D Matrices.
                                              																if($3.type->bType != type_INT || $6.type->bType != type_INT){
                                              																	yyerror("Error Matrix dimensions not intgers");
                                              																	exit(1);
                                              																}
                                              																if(!($1.type->bType == type_MATRIX)){
                                              																	yyerror("Error Non Matrix type trying to declare using []");
                                              																	exit(1);
                                              																}
                                              																complexType * typemat = new complexType(type_MATRIX);
                                              																typemat->leftIndex = $3.loc->init.intVal;
                                              																typemat->rightIndex = $6.loc->init.intVal;
                                              																typemat = new complexType(typemat);

                                              																//Update the type of Matrix.
                                              																symEntry * s = currentSymTab->lookUp($1.loc->name);
                                              																currentSymTab->update(s, typemat, typemat->size);
                                              																quad.type = typemat;
                                              																quad.width = typemat->size;
                                              																$$ = $1;
                                              																$$.type = $$.loc->type;

                                              																quad.mat = $$.loc;
                                              																printf("direct_declarator -> direct_declarator [ assignment_expr ]\n");
                                              															}
            |direct_declarator OPENBRCCIR parameter_type_list CLOSEBRCCIR   {

								                                                symEntry * s = globalSymTab->lookUp($1.loc->name);
								                                                complexType * typefunc = new complexType(type_FUNC);
							                                                    globalSymTab->update(s, typefunc, SIZE_OF_FUNC);
							                                                    s->nestedTable = currentSymTab;
							                                                    currentSymTab->name = "ST (" + $1.loc->name + ")";
							                                                    quad.emit(quadEntry(OP_FUNC_START, $1.loc->name));
							                                                    $1.loc->name = "__retVal";
							                                                    $1.loc->scope = "return";
							                                                    $$.loc = s;					                                                    
							                                                    $$.type = $$.loc->type;
							                                                    printf("direct_declarator -> direct_declarator ( parameter_type_list )\n");
							                                                }
            |direct_declarator OPENBRCCIR CLOSEBRCCIR             {
					                                                symEntry * s = globalSymTab->lookUp($1.loc->name);
					                                                complexType * typefunc = new complexType(type_FUNC);
				                                                    globalSymTab->update(s, typefunc, SIZE_OF_FUNC);
				                                                    s->nestedTable = currentSymTab;
				                                                    currentSymTab->name = "ST (" + $1.loc->name + ")";
				                                                    quad.emit(quadEntry(OP_FUNC_START, $1.loc->name));
				                                                    $1.loc->name = "__retVal";
				                                                    $1.loc->scope = "return";
				                                                    $$.loc = s;
				                                                    $$.type = $$.loc->type;
				                                                    printf("direct_declarator -> direct_declarator ()\n");
				                                                  }
            |direct_declarator OPENBRCCIR identifier_list CLOSEBRCCIR     {
															            	//Not Supported
															            	printf("direct_declarator -> direct_declarator ( identifier_list )\n");
															              }
;


pointer:          STAR                          {
		                                          $$.type = new complexType(type_PTR);
		                                          printf("pointer -> *\n");
		                                        }
            |STAR pointer                     {
		                                          $$.type = new complexType(type_PTR);
		                                          $$.type->next = $2.type;
		                                          printf("pointer -> * pointer\n");
		                                      }
;



parameter_type_list:  parameter_list                      {printf("parameter_type_list -> parameter_list\n");}
;

parameter_list:     parameter_declaration                 {printf("parameter_list -> parameter_declaration\n");}
            |parameter_list COMMA parameter_declaration       {printf("parameter_list -> parameter_list , parameter_declaration\n");}
;

parameter_declaration:  declaration_specifiers declarator           {
							                                          $2.loc->scope = "param";
							                                          $2.loc->isParam = true;
							                                          printf("parameter_declaration -> declaration_specifiers declarator\n");
							                                        }
            |declaration_specifiers                 {printf("parameter_declaration -> declaration_specifiers\n");}
;

identifier_list:    IDENTIFIER                        {printf("identifier_list -> IDENTIFIER\n");}
            |identifier_list COMMA IDENTIFIER           {printf("identifier_list -> identifier_list , IDENTIFIER\n");}      
;

initializer:      assignment_expr       {
                                          $$ = $1;
                                          printf("initializer -> assignment_expr\n");
                                        }
            |OPENBRCCUR initializer_row_list CLOSEBRCCUR      {
            													//Matrix Initialisation.
												            	exp_t e;
												            	//e.loc = currentSymTab->genTemp(quad.type);
												            	e.loc = quad.mat;
												            	e.type = e.loc->type;
												            	e.loc->init.matVal = new vector<double>();
												            	vector<exp_t *> v = *($2);
												            	int sz = v.size();

												            	//Checking whether nuber of elements in Initial Matrix == size of Matrix.
												            	if(sz != (quad.type->leftIndex)*(quad.type->rightIndex)){
												            		yyerror("Inital Matrix dimension do no match");
												            		exit(0);
												            	}
												            	bool allInitialised = true;
												            	exp_t e2;
												            	e2.type = new complexType(type_DOUBLE);

												            	for(int i=0;i<sz;i++){
												            		exp_t * temp = v[i];
												            		typeCheck(&(e2),temp);
												            		if(!(temp->loc->wasInitialised && temp->loc->type->bType == type_DOUBLE)){
												            			allInitialised = false;
												            		}
												            	}
												            	
												            	//If all values of Intial Matrix are alredy initilised, then Matrix is also initialised, otherwise not.
												            	string access = quad.mat->name + "[0]";
												            	quad.emit(quadEntry(OP_COPY,access,i2s(quad.type->leftIndex)));
												            	access = quad.mat->name + "[" + i2s(SIZE_OF_INT) + "]";
												            	quad.emit(quadEntry(OP_COPY,access,i2s(quad.type->rightIndex)));
												            	if(allInitialised){
												            		for(int i=0;i<sz;i++){
												            			//Allocating individual elements to initial values.
												            			exp_t * temp = v[i];
												            			e.loc->init.matVal->push_back(temp->loc->init.doubleVal);
												            			string matop = quad.mat->name +  "[" + i2s(2*SIZE_OF_INT + SIZE_OF_DOUBLE*i) + "]"; 
												            			char dblval[20];
												            			sprintf(dblval,"%lf",temp->loc->init.doubleVal);
												            			quad.emit(quadEntry(OP_COPY,matop,dblval));
												            		}
												            		currentSymTab->update(e.loc,e.loc->init);

												            	}
												            	else{
												            		for(int i=0;i<sz;i++){
												            			//Allocating idividual element to loc of associated temp.
												            			exp_t * temp = v[i];
												            			string matop = quad.mat->name +  "[" + i2s(2*SIZE_OF_INT + SIZE_OF_DOUBLE*i) + "]"; 
												            			quad.emit(quadEntry(OP_COPY,matop,temp->loc->name));
												            		}
												            		e.loc->wasInitialised = false;
												            		
												            	}

												            	$$ = e;
												            	//cout<<"HERE###############"<<allInitialised<<sz<<endl;
												            	printf("initializer -> { initializer_row_list }\n");}
;

initializer_row_list:   initializer_row                   {
															$$ = $1;
															//If no of elemets from row != width, error.
															if($1->size() != quad.type->rightIndex){
											              		yyerror("Initial Matrix dimensions do not match");
											              		exit(0);
											              	}
															printf("initializer_row_list -> initializer_row\n");
														  }                
              |initializer_row_list SEMICOLON initializer_row   {
													              	$$ = $1;
													              	//If no of elemets from row != width, error.
													              	if($3->size() != quad.type->rightIndex){
													              		yyerror("Initial Matrix dimensions do not match");
													              		exit(0);
													              	}
													              	//Merge the 2 lists
													              	$$->insert($$->end(),$3->begin(),$3->end());
													              	printf("initializer_row_list -> initializer_row_list ; initializer_row \n");
													              }
;

initializer_row:    initializer                       {
														$$ = new vector<exp_t *>();
														$$->push_back(new exp_t($1));
														printf("initializer_row -> initializer\n");
													  } 
            |designation initializer                {
										            	//Not Supported
										            	printf("initializer_row -> designation initializer\n");
										            }  
            |initializer_row COMMA initializer            {
            												$$ = $1;
											            	$$->push_back(new exp_t($3));
											            	printf("initializer_row -> initializer_row , initializer\n");
											            } 
            |initializer_row COMMA designation            {
											            	//Not Supported
											            	printf("initializer_row -> initializer_row , designation\n");
											              }

;

designation:      designator_list EQUALS                  {
											            	//Not Supported
											            	printf("designation -> designator_list =\n");
											              } 
;

designator_list:    designator                        {
											            	//Not Supported
											            	printf("designator_list -> designator\n");
											          }  
            |designator_list designator               {
											            	//Not Supported
											            	printf("designator_list -> designator_list designator\n");
											          }  
;

designator:       OPENBRCSQ constant_expr CLOSEBRCSQ            {
													            	//Not Supported
													            	printf("designator -> [ constant_expr ]\n");
													            }
            |DOT IDENTIFIER                     		{
											            	//Not Supported
											            	printf("designator -> . IDENTIFIER\n");
											            }
;






statement:      labeled_statement                       {
											            	//Not Supported
											            	printf("statement -> labeled_statement\n");
											            }
          |compound_statement                     {
			                                          $$ = $1;
			                                          printf("statement -> compound_statement\n");
			                                      }
          |expression_statement                   {
			                                          $$ = NULL;
			                                          printf("statement -> expression_statement\n");
			                                      }
          |selection_statement                    {
			                                          $$ = $1;
			                                          backPatch($1,quad.nextInstr);
			                                          printf("statement -> selection_statement\n");
			                                      }
          |iteration_statement                    {
			                                          $$ = $1;
			                                          backPatch($1,quad.nextInstr);
			                                          printf("statement -> iteration_statement\n");
			                                      }
          |jump_statement                       {
		                                          $$ = $1;
		                                          backPatch($1,quad.nextInstr);
		                                          printf("statement -> jump_statement\n");
		                                        }
;

labeled_statement:   IDENTIFIER COLON statement                 {
													            	//Not Supported
													            	printf("labeled_statement -> IDENTIFIER : statement\n");
													            }
          |CASE constant_expr COLON statement             {
											            	//Not Supported
											            	printf("labeled_statement -> case constant_expr : statement\n");
											              }
          |DEFAULT COLON statement                  	{
											            	//Not Supported
											            	printf("labeled_statement -> default : statement\n");
											            }
;

compound_statement:  OPENBRCCUR CLOSEBRCCUR                   {
						                                          $$ = NULL;
						                                          printf("compound_statement -> {}\n");
						                                      }
          |OPENBRCCUR block_item_list CLOSEBRCCUR           {
					                                          $$ = $2;
					                                          printf("compound_statement -> { block_item_list }\n");
					                                        }
;

block_item_list:    block_item                        {
				                                          $$ = $1;
				                                          printf("block_item_list -> block_item\n");
				                                      }
            |block_item_list M block_item             {
            											  //Grammar AUgentation M.
				                                          backPatch($1,$2);
				                                          $$ = $3;
				                                          printf("block_item_list -> block_item_list block_item\n");
				                                      }
;

block_item:    declaration                          {
			                                          $$ = NULL;
			                                          printf("block_item -> declaration\n");
			                                        }
        |statement                            {
		                                          $$ = $1;
		                                          printf("block_item -> statement\n");
		                                      }
;

expression_statement:  SEMICOLON                        {printf("expression_statement -> ;\n");}
            |expression SEMICOLON                 		{printf("expression_statement -> expression ;\n");}
;

selection_statement:   IF OPENBRCCIR expression N CLOSEBRCCIR M statement     %prec "then"  {
									                                                    	  //Grammanar Augmentation. N supports non-boolean expressions by convertin them to bool.
									                                                          List * addone = new List(quad.nextInstr);
									                                                    	  List * l = mergeList($7, addone);
									                                                          quad.emit(quadEntry(OP_GOTO_O, ""));
									                                                          backPatch($4, quad.nextInstr);
									                                                          conv2Bool(&($3));
									                                                          backPatch($3.trueList, $6);
									                                                          // all dangling gotos are merged and stored
									                                                          //cout<<"FALSELIST####################"<<($7==NULL)<<endl;
									                                                          $3.falseList->print();
									                                                          $$ = mergeList($3.falseList, l);
									                                                          //addone->print();
									                                                          printf("selection_statement -> if ( expression ) statement\n");
									                                                      }
            |IF OPENBRCCIR expression N CLOSEBRCCIR M statement N ELSE M statement      {
								                                                      		//Grammanar Augmentation. N supports non-boolean expressions by convertin them to bool.
								                                                            List * addone = new List(quad.nextInstr);
								                                                            List * l = mergeList($7,addone);
								                                                            l = mergeList(l, $8);
								                                                            quad.emit(quadEntry(OP_GOTO_O, ""));
								                                                            backPatch($4, quad.nextInstr);
								                                                            // convert to bool expression
								                                                            conv2Bool(&($3));
								                                                            backPatch($3.trueList, $6);
								                                                            backPatch($3.falseList, $10);
								                                                            // merge the dangling gotos
								                                                            $$ = mergeList(l, $11);
								                                                            printf("selection_statement -> if (expression ) statement else statement\n");
								                                                        }
            |SWITCH OPENBRCCIR expression CLOSEBRCCIR statement           {
															            	//Not Supported
															            	printf("selection_statement -> switch ( expression ) statement\n");
															              }
;

iteration_statement:   WHILE OPENBRCCIR M expression N CLOSEBRCCIR M statement                      {
								                                                                	  //Grammanar Augmentation. N supports non-boolean expressions by convertin them to bool.
								                                                                      List * addone = new List(quad.nextInstr);
								                                                                      List * l = mergeList($8, addone);
								                                                                      // emit a goto after statement to goto condition again
								                                                                      quad.emit(quadEntry(OP_GOTO_O, ""));
								                                                                      backPatch($5, quad.nextInstr);
								                                                                      conv2Bool(&($4));
								                                                                      backPatch($4.trueList, $7);
								                                                                      backPatch(l, $3);
								                                                                      $$ = $4.falseList;
								                                                                      printf("iteration_statement -> while ( expression ) statement\n");
								                                                                  }
            |DO M statement WHILE OPENBRCCIR M expression CLOSEBRCCIR SEMICOLON                   {
            																						//Grammar Augmentation. M helps in BackPatching.
							                                                                        conv2Bool(&($7));
							                                                                        backPatch($7.trueList, $2);
							                                                                        backPatch($3, $6);
							                                                                        $$ = $7.falseList;
							                                                                        printf("iteration_statement -> do statement while ( expression ) ;\n");
							                                                                    }
            |FOR OPENBRCCIR expression_opt SEMICOLON M expression_opt N SEMICOLON M expression_opt N CLOSEBRCCIR M statement  {
													                                                                      		//Grammanar Augmentation. N supports non-boolean expressions by convertin them to bool.
													                                                                            List * addone = new List(quad.nextInstr);
													                                                                            List * l = mergeList($14, addone);
													                                                                            quad.emit(quadEntry(OP_GOTO_O, ""));
													                                                                            backPatch(l, $9);
													                                                                            backPatch($7, quad.nextInstr);
													                                                                            conv2Bool(&($6));
													                                                                            backPatch($6.trueList, $13);
													                                                                            backPatch($11, $5);
													                                                                            $$ = $6.falseList;
													                                                                            printf("iteration_statement -> for ( expression ; expression ; expression ) statement\n");
													                                                                        }
            |FOR OPENBRCCIR declaration expression_opt SEMICOLON expression_opt CLOSEBRCCIR statement       {
																								            	//Not Supported
																								            	printf("iteration_statement -> for ( declaration expression ; expression ) statement\n");
																								            }
;

jump_statement:     GOTO IDENTIFIER SEMICOLON               {
																//Not Supported
																printf("jump_statement -> goto IDENTIFIER ;\n");
															}
            |CONTINUE SEMICOLON                   			{
																//Not Supported
																printf("jump_statement -> continue ;\n");
															}
            |BREAK SEMICOLON                    			{
																//Not Supported
																printf("jump_statement -> break ;\n");
															}
            |RETURN SEMICOLON                   {
            										exp_t e; 
		                                            e.type = currentSymTab->entries[0]->type;
		                                            exp_t e2;
		                                            e2.type = new complexType(type_VOID);
		                                            //error if return type is not void.
		                                            if(!(typeCheck(&e,&e2,true))){
		                                            	yyerror("invalid return type");
		                                            	exit(1);
		                                            }
	                                          		quad.emit(quadEntry(OP_RETURN, ""));
	                                                $$ = NULL;
	                                                printf("jump_statement -> return ;\n");
                                                }
            |RETURN expression SEMICOLON              {
		                                                exp_t e; 
		                                                e.type = currentSymTab->entries[0]->type;
		                                                //error if return type does not match that of expression.
		                                                if(!(typeCheck(&e, &($2), true))){
		                                                	yyerror("return type invalid");
		                                                	exit(1);
		                                                }
		                                                quad.emit(quadEntry(OP_RETURN_VAL, $2.loc->name));
		                                                $$ = NULL;
		                                                printf("jump_statement -> return expression ;\n");
		                                              }
;


translation_unit:   external_declaration                  {printf("translation_unit -> external_declaration\n");}
            |translation_unit external_declaration          {printf("translation_unit -> translation_unit external_declaration\n");}
;

external_declaration: function_definition                   {printf("external_declaration -> function_definition\n");}
            |declaration                      {
                                          		quad.quad_v.pop_back();
                                                quad.nextInstr--;
                                                printf("external_declaration -> declaration\n");
                                              }
;

function_definition:  declaration_specifiers declarator compound_statement          {
								                                                  		//Nested table saved
								                                                        $2.loc->nestedTable = currentSymTab;
								                                                        currentSymTab = new symTable();
								                                                        backPatch($3, quad.nextInstr);
								                                                        quad.emit(quadEntry(OP_FUNC_END, $2.loc->name));
								                                                        printf("function_definition -> declaration_specifiers declarator compound_statement");
								                                                    }
            |declaration_specifiers declarator declaration_list compound_statement {
								                                                  		//Nested table saved
								                                                        $2.loc->nestedTable = currentSymTab;
								                                                        currentSymTab = new symTable();
								                                                        backPatch($4, quad.nextInstr);
								                                                        quad.emit(quadEntry(OP_FUNC_END, $2.loc->name));
								                                                        printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement");
								                                                    }
;

declaration_list:     declaration                       {printf("declaration_list -> declaration");}
            |declaration_list declaration             {printf("declaration_list -> declaration_list declaration");}
;







%%

int yyerror(const char *s){
  printf("Parser Error : %s\n",s);
  return -1;
}












			





