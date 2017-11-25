#include "ass5_15CS30006_translator.h"
#include "ass5_15CS30006.tab.h"
#define CONSTANT_OFFSET 8
extern int yydebug;
extern char * yytext;

extern int yyerror(const char *);
extern int yylex();

int tempCount = 0;									//Nuber of temporaries generated till now
symTable * currentSymTab = new symTable(); 			//Current Symbol Table.
symTable * globalSymTab  = new symTable("ST (global)"); 	//Global Symbol Table
quadList quad; 												//List of quads
vector<dblunion> doubleLabels;


/*************TYPE:BEGIN****************/

complexType::complexType(){}

complexType::complexType(basicType b){
	//Sets the basicType and size.
	if(b == type_MATRIX){
		bType = b;
		next = NULL;
		//when dimension not specified only, space for saving dimensions is allocated for matrix.
		size = 2*SIZE_OF_INT;
	}
	else{
		bType = b;
		next = NULL;
		size = this->getSize();
	}
	
}

complexType::complexType(complexType *t){
	//Sets the basicType, next and size.
	bType = t->bType;
	if(t->bType == type_MATRIX){
		//Sets the left and right index of Matrix and sets size accordingly.
		leftIndex = t->leftIndex;
		rightIndex = t->rightIndex;
		size = leftIndex*rightIndex*SIZE_OF_DOUBLE + 2*SIZE_OF_INT;
	}
	else{
		size = t->size;
	}
	next = t->next;
}

int complexType::getSize(){
	switch(bType){
		case(type_BOOL):	return SIZE_OF_BOOL; 			break;
		case(type_VOID):	return SIZE_OF_VOID; 			break;
		case(type_CHAR):	return SIZE_OF_CHAR; 			break;
		case(type_INT):		return SIZE_OF_INT; 			break;
		case(type_DOUBLE):	return SIZE_OF_DOUBLE; 			break;
		case(type_FUNC):	return SIZE_OF_FUNC; 			break;
		case(type_PTR):		return SIZE_OF_PTR; 			break;			
		case(type_MATRIX):	return size; 					break;
		default:			printf("Type NOT found!!"); 	exit(-1);
	}
}

void complexType::print(){
	switch(bType){
		case(type_BOOL): 	cout<<"Bool ";					break;
		case(type_VOID):	cout<<"void "; 					break;
		case(type_CHAR):	cout<<"char ";					break;
		case(type_INT):		cout<<"int ";					break;
		case(type_DOUBLE):	cout<<"double ";				break;
		case(type_FUNC):	cout<<"func ";					break;
		case(type_PTR):		cout.width(0);cout<<left<<"ptr(";next->print();cout<<left<<")";cout.width(30);					break;			
		case(type_MATRIX):	cout.width(0);cout<<left<<"MATRIX("<<leftIndex<<",Matrix("<<rightIndex<<",double))";cout.width(30); 	break;
		default:			cout<<"Type NOT FOUND"; 	exit(-1);
	}
}

bool areEqual(complexType *t1, complexType *t2){
	//in case of pointers, the level of nesting is checked. At the base level, if BasicTypes match returns true.
	complexType *p1 = t1;
	complexType *p2 = t2;
	while(1){
		if(p1==NULL && p2==NULL)
			return true;
		else if(p1==NULL || p2==NULL)
			return false;
		else if(p1->bType == p2->bType){
			p1 = p1->next;
			p2 = p2->next;
		}
		else
			return false;
	}
}

/************TYPE:END******************/

/************SYMBOL ENTRY: BEGIN***********/

symEntry::symEntry(string s){
	//Sets scope, if scope =="param", isParam falg is set to true.
	nestedTable = NULL;
	wasInitialised = false;
	scope = s;
	if(scope == "param"){
		isParam = true;
	}
	else{
		isParam = false;
	}
}

symEntry::symEntry(string nm, complexType *tp, string s){
	//Sets scope, name an type. if scope =="param", isParam falg is set to true.
	nestedTable = NULL;
	wasInitialised = false;
	scope = s;
	name = nm;
	type = tp;
	if(scope == "param"){
		isParam = true;
	}
	else{
		isParam = false;
	}
}

void symEntry::print(){
	cout.width(15);
	cout.fill(' ');
	cout<<left<<(this->name);
	//printf("%s\t",  this->name.c_str());
	cout.width(30);
	cout.fill(' ');
	(this->type)->print();
	//printf("\t");
	cout.width(60);
	cout.fill(' ');
	if(this->wasInitialised){
		switch(this->type->bType){
			case(type_INT): 	cout<<(this->init.intVal);		break;
			case(type_CHAR): 	cout<<(this->init.charVal);		break;
			case(type_DOUBLE):	cout<<(this->init.doubleVal.d);		break;
			case(type_MATRIX):
			{
				//printf("{");
				cout.width(0);
				cout<<"{";
				vector<dblunion> v = *(init.matVal);
				int height = this->type->leftIndex;
				int width = this->type->rightIndex;
				for(int i=0;i<height;i++){
					for(int j=0;j<width-1;j++){
						cout.width(0);
						cout<<fixed<<setprecision(3)<<left<<v[i*width + j].d<<",";
						//printf("%3.3lf,",v[i*width + j]);
					}
					//printf("%3.3lf;",v[i*width + width -1]);
					cout.width(0);
					cout<<left<<fixed<<setprecision(3)<<left<<v[i*width + width -1].d<<";";
				}
				//printf("}");
				cout.width(60);
				cout<<left<<"}";
				
				break;
			}
		}
	}
	else{
		cout<<"NULL";
		//printf("NULL\t\t\t");
	}
	cout.width(6);
	cout.fill(' ');
	cout<<(this->size);
	cout.width(8);
	cout.fill(' ');
	cout<<(this->offset);
	//printf("\t%d\t%d\t",this->size,this->offset);
	cout.width(15);
	cout.fill(' ');
	if(this->nestedTable !=NULL){
		//printf("%s",this->nestedTable->name.c_str());
		cout<<(this->nestedTable->name);
	}
	else{
		//printf("NULL");
		cout<<"NULL";
	}
	//printf("\n");
	cout<<endl;

}

/************SYMBOL ENTRY: END***********/

/************SYMBOL TABLE: BEGIN***********/

//Constructor, sets offset to 0
symTable::symTable(){
	offset = 0;
}

//Constructor, sets offset to 0 and name of symbola table to s.
symTable::symTable(string s){
	offset = 0;
	name = s;
}

//Checks if an entry is present.
bool symTable::isPresent(string name){
	int noOfEntries = entries.size();
	for(int i=0; i<noOfEntries; i++){
		if(name == entries[i]->name){
			return true;
		}
	}
	return false;
}

//a function that returns a pointer to the identifier (if present) or creates a new entry and then returns.
symEntry *symTable::lookUp(string name){
	int noOfEntries = entries.size();
	for(int i=0; i<noOfEntries; i++){

		if(name == entries[i]->name){
			return entries[i];
		}
	}
	symEntry *entry = new symEntry();
	entry->name = name;
	entries.push_back(entry);
	return entry;
}

//a function to generate a new temporary variable given type of temporary. sets the necesaary attricutes of type.
symEntry *symTable::genTemp(complexType *type){
	char tempVar[10];
	sprintf(tempVar,"t%03d",tempCount);
	tempCount++;
	symEntry *entry = new symEntry(tempVar, type, "temp");
	int sz = 0;
	switch(type->bType){
		case(type_INT):		sz = SIZE_OF_INT;		break;
		case(type_CHAR):	sz = SIZE_OF_CHAR;		break;
		case(type_DOUBLE):	sz = SIZE_OF_DOUBLE;	break;
		case(type_PTR):		sz = SIZE_OF_PTR;		break;
		case(type_MATRIX): 	sz = type->size; 		break;
		default:			sz = 0;
	}

	entry->size = sz;
	entry->offset = offset;
	offset += sz;
	entries.push_back(entry);
	return entry;
}

//Updates symbol table entry when initial value is given. sets wasInitialised to true.
void symTable::update(symEntry *entry, initialVal init){
	entry->init = init;
	entry->wasInitialised = true;
}

//update when type in size is given.
void symTable::update(symEntry *entry, complexType *t, int sz){
	entry->type = t;
	entry->size = sz;
	entry->offset = offset;
	offset += sz;
	if(t->bType == type_FUNC)
		entry->scope = "global";
}

void symTable::print(){
	int sz = entries.size();
	if(sz>0){
		//cout<<left<<setw(80);
		cout.width(140);
		cout.fill('=');
		cout<<"="<<endl;
		printf("%s\n",this->name.c_str());
		cout.width(15);
		cout.fill(' ');
		cout<<left<<"Name";
		cout.width(30);
		cout.fill(' ');
		cout<<left<<"Type";
		cout.width(60);
		cout.fill(' ');
		cout<<left<<"Inital Value";
		cout.width(6);
		cout.fill(' ');
		cout<<left<<"Size";
		cout.width(8);
		cout.fill(' ');
		cout<<left<<"Offset";
		cout.width(15);
		cout.fill(' ');
		cout<<left<<"NestedTable"<<endl;
		//printf("Name\tType\t\t\t\tInitalValue\t\t\tSize\tOffset\tNestedTable\n");
		for(int i=0;i<sz;i++){
			entries[i]->print();
		}
		cout.width(140);
		cout.fill('=');
		cout<<"="<<endl<<endl;
	}
}

/************SYMBOL TABLE: END***********/

/************QUAD ENTRY: BEGIN***********/

//Constructors
quadEntry::quadEntry(opcodeType opcode, string s1, string s2, string s3){
	op = opcode;
	result = s1;
	arg1 = s2;
	arg2 = s3;
}

quadEntry::quadEntry(opcodeType opcode, string s1, char c){
	op = opcode;
	result = s1;
	arg1 = "";
	arg1 += c;
	arg2 = "";
}

quadEntry::quadEntry(opcodeType opcode, string s1, int n){
	op = opcode;
	result = s1;
	char s[10];
	sprintf(s,"%d",n);
	arg1 = s;
	arg2 = "";
}

quadEntry::quadEntry(opcodeType opcode, string s1, double d){
	op = opcode;
	result = s1;
	char s[10];
	sprintf(s,"%lf",d);
	arg1 = s;
	arg2 = "";
}

//Fills in the result of current symbol during backPatching.
void quadEntry::setTarget(int address){
	char s[10];
	sprintf(s,"%d",address);
	this->result = s;
}

void quadEntry::print(FILE * out) {
    switch(op) {
        case(OP_PLUS): 		 fprintf(out, "%s = %s + %s\n", result.c_str(), arg1.c_str(), arg2.c_str()); 		break;
		case(OP_MINUS): 	 fprintf(out, "%s = %s - %s\n", result.c_str(), arg1.c_str(), arg2.c_str()); 		break;
		case(OP_MULT): 		 fprintf(out, "%s = %s * %s\n", result.c_str(), arg1.c_str(), arg2.c_str()); 		break;
		case(OP_DIV): 		 fprintf(out, "%s = %s / %s\n", result.c_str(), arg1.c_str(), arg2.c_str()); 		break;
		case(OP_MOD): 		 fprintf(out, "%s = %s %% %s\n", result.c_str(), arg1.c_str(), arg2.c_str()); 		break;
		case(OP_UMINUS): 	 fprintf(out, "%s = uminus(%s)\n", result.c_str(), arg1.c_str()); 		 			break;
		case(OP_COPY): 		 fprintf(out, "%s = %s\n", result.c_str(), arg1.c_str()); 		 					break;
		case(OP_TRUE): 		 fprintf(out, "if (%s) goto %s\n", arg1.c_str(), result.c_str()); 		 			break;
		case(OP_FALSE): 	 fprintf(out, "ifFalse (%s) goto %s\n", arg1.c_str(), result.c_str()); 				break;
		case(OP_JLT): 		 fprintf(out, "if (%s < %s) goto %s\n", arg1.c_str(), arg2.c_str(), result.c_str()); 		break;
		case(OP_JLE): 		 fprintf(out, "if (%s <= %s) goto %s\n", arg1.c_str(), arg2.c_str(), result.c_str());		break;
		case(OP_JGT): 		 fprintf(out, "if (%s > %s) goto %s\n", arg1.c_str(), arg2.c_str(), result.c_str()); 	 	break;
		case(OP_JGE): 		 fprintf(out, "if (%s >= %s) goto %s\n", arg1.c_str(), arg2.c_str(), result.c_str()); 		break;
		case(OP_EQ): 		 fprintf(out, "if (%s == %s) goto %s\n", arg1.c_str(), arg2.c_str(), result.c_str()); 		break;
		case(OP_NEQ): 		 fprintf(out, "if (%s != %s) goto %s\n", arg1.c_str(), arg2.c_str(), result.c_str()); 		break;
		case(OP_INT2DBL): 	 fprintf(out, "%s = Int2Dbl(%s)\n", result.c_str(), arg1.c_str()); 		 			break;
		case(OP_DBL2INT): 	 fprintf(out, "%s = Dbl2Int(%s)\n", result.c_str(), arg1.c_str()); 					break;
		case(OP_INT2CHAR): 	 fprintf(out, "%s = Int2Char(%s)\n", result.c_str(), arg1.c_str()); 		 		break;
		case(OP_CHAR2INT): 	 fprintf(out, "%s = Char2Int(%s)\n", result.c_str(), arg1.c_str()); 		 		break;
		case(OP_L_VAL_AT): 	 fprintf(out, "* %s = %s\n", result.c_str(), arg1.c_str()); 		 				break;
		case(OP_R_VAL_AT): 	 fprintf(out, "%s = * %s\n", result.c_str(), arg1.c_str()); 		 				break;
		case(OP_L_INDEX): 	 fprintf(out, "%s[%s] = %s\n", result.c_str(), arg1.c_str(), arg2.c_str()); 		break;
		case(OP_R_INDEX): 	 fprintf(out, "%s = %s[%s]\n", result.c_str(), arg1.c_str(), arg2.c_str()); 		break;
		case(OP_ADDR): 		 fprintf(out, "%s = & %s\n", result.c_str(), arg1.c_str()); 		 				break;
		case(OP_PARAM): 	 fprintf(out, "param %s\n", result.c_str()); 		 								break;
		case(OP_GOTO_O):	 fprintf(out, "goto %s\n", result.c_str()); 		 								break;
		case(OP_CALL): 		 fprintf(out, "%s = call %s, %s\n", result.c_str(), arg1.c_str(), arg2.c_str()); 	break;
		case(OP_RETURN):	 fprintf(out, "return\n"); 		 													break;
		case(OP_RETURN_VAL): fprintf(out, "return %s\n", result.c_str()); 		 								break;
		case(OP_BW_NOT): 	 fprintf(out, "%s = ~ %s\n", result.c_str(), arg1.c_str()); 		 				break;
		case(OP_SHL): 		 fprintf(out, "%s = %s << %s\n", result.c_str(), arg1.c_str(), arg2.c_str()); 		break;
		case(OP_SHR): 		 fprintf(out, "%s = %s >> %s\n", result.c_str(), arg1.c_str(), arg2.c_str()); 		break;
		case(OP_BW_AND): 	 fprintf(out, "%s = %s & %s\n", result.c_str(), arg1.c_str(), arg2.c_str()); 		break;
		case(OP_BW_XOR): 	 fprintf(out, "%s = %s ^ %s\n", result.c_str(), arg1.c_str(), arg2.c_str()); 		break;
		case(OP_BW_OR): 	 fprintf(out, "%s = %s | %s\n", result.c_str(), arg1.c_str(), arg2.c_str()); 		break;
		case(OP_TRANS):		 fprintf(out, "%s = Trans(%s)\n",result.c_str(),arg1.c_str());						break;
		case(OP_FUNC_START): fprintf(out, "%s FuncBegin\n", result.c_str()); 		 							break;
		case(OP_FUNC_END): 	 fprintf(out, "%s FuncEnd\n", result.c_str()); 		 								break;
        default:			 fprintf(out, "Error ! Unknown opcodeType.\n");	exit(-1);
    }
}

/************QUAD ENTRY: END***********/
//pushes the quad in quadList and increments nextInstr
void quadList::emit(quadEntry q){
	(this->quad_v).push_back(q);
	(this->nextInstr)++;
}

// node for a list, stores the index of quad
node::node(int idx){
	qIdx = idx;
	next = NULL;
}

node::node(){
	next = NULL;
}

/************LIST: BEGIN***********/

List::List(int idx){
	head = new node(idx);
	tail = head;
}

List::List(){
	head = NULL;
	tail = NULL;
}

void List::print(){

    /*if(this->head == NULL){
    	cout<<"HERE6################"<<endl;
    }
    cout<<"HERE7################"<<endl;*/
	node * ptr = head;
	//cout<<"HERE5################"<<endl;
	while(ptr!=NULL){
		printf("%d ", ptr->qIdx);
		ptr = ptr -> next;
	}
	printf("\n");
}

void List::clear(){
	//deletes every node from list.
	node * first = head;
	if(first==NULL)
		return;
	node * second = head->next;
	while(second!=NULL){
		delete first;
		first = second;
		second = second->next;
	}
	delete first;
	head = NULL;
	tail = NULL;
}

List * mergeList(List *list1, List *list2){
	//Mereges 2 lists.
	if(list1==NULL)
		return list2;
	if(list1->head==NULL)
		return list2;
	if(list2==NULL)
		return list1;
	if(list2->head==NULL)
		return list1;

	list1->tail->next = list2->head;
	list1->tail = list2->tail;
	return list1;
}

/************LIST: END***********/

//fills in address at every location specified in List p
void backPatch(List * &p, int address){
	if(p==NULL || p->head==NULL){		
		return;
	}

	node * p1 = p->head;
	while(p1 != NULL){
		quad.quad_v[p1->qIdx].setTarget(address);
		p1 = p1->next;
	}
	p->clear();
}

//Prints the quads Table.
void printAllQuads(FILE * out) {
    for(int i = 0; i < quad.quad_v.size(); i++) {
        fprintf(out, "%3d. ", i); 
        quad.quad_v[i].print(out);
    }
}

//Checks if 2 expession types are compatible, tries for conversion if possible otherwise returns false.
bool typeCheck(exp_t * e1, exp_t * e2, bool isAssignment, bool isMultiplication){
	if(areEqual(e1->type,e2->type)){
		if(e1->type->bType == type_MATRIX && e2->type->bType == type_MATRIX){
			if(isMultiplication){
				//For matrix multiplication, the two matrics have dimensions (m*n) and (n*p)
				if(e1->type->rightIndex == e2->type->leftIndex){
					return true;
				}
				else{
					return false;
				}
			}
			else{
				//for other operations on matrix, dimensions must match.
				if(e1->type->leftIndex == e2->type->leftIndex && e1->type->rightIndex == e2->type->rightIndex){
					return true;
				}
				else{
					return false;
				}
			}
		}
		return true;
	}

    basicType b1 = e1->type->bType;
    basicType b2 = e2->type->bType;
    if(!isAssignment){
    	if(b1 < b2){
    		//Lower type to higher type.
    		if(b1 == type_BOOL && b2 == type_INT) {
	            convBool2Int(e1);
	            return true;
	        } 
	        if(b1 == type_INT && b2 == type_DOUBLE) {
	        	convInt2Dbl(e1, e2);
	            return true;

	        } 
	        if(b1 == type_INT && b2 == type_CHAR) {
	        	convInt2Char(e1, e2);
	            return true;

	        }
	        if(b1 == type_CHAR && b2 == type_INT) {
	        	convChar2Int(e1, e2);
	            return true;

	        }
	        if(b1 == type_DOUBLE && b2 == type_INT) {
	        	convDbl2Int(e1, e2);
	            return true;

	        }
	        return false;
    	}
    	else{
    	
    		//Lower type to higher type.
    		if(b1 == type_BOOL && b2 == type_INT) {
	            convBool2Int(e2);
	            return true;
	        } 
	        if(b1 == type_INT && b2 == type_DOUBLE) {
	        	convDbl2Int(e2, e1);
	            return true;

	        }
	        if(b1 == type_INT && b2 == type_CHAR) {
	        	convChar2Int(e2, e1);
	            return true;

	        }
	        if(b1 == type_CHAR && b2 == type_INT) {
	        	convInt2Char(e2, e1);
	            return true;

	        }
	        if(b1 == type_DOUBLE && b2 == type_INT) {
	        	convInt2Dbl(e2, e1);
	            return true;

	        } 
	        return false;
    	}
    }
    else{
    	//forcefully converts e2 to e1 type.
    	if(b1 == type_BOOL && b2 == type_INT) {
            convBool2Int(e2);
            return true;
        } 
        if(b1 == type_INT && b2 == type_DOUBLE) {
        	convDbl2Int(e2, e1);
            return true;

        }
        if(b1 == type_INT && b2 == type_CHAR) {
        	convChar2Int(e2, e1);
            return true;

        }
        if(b1 == type_CHAR && b2 == type_INT) {
        	convInt2Char(e2, e1);
            return true;

        }
        if(b1 == type_DOUBLE && b2 == type_INT) {
        	convInt2Dbl(e2, e1);
            return true;

        }
        return false;
    }

}

/************CONV<E1>2<E2> (Converts E1.type to E2.type): BEGIN***********/

void convInt2Dbl(exp_t * e1, exp_t * e2){
	exp_t * e3 = new exp_t();
	complexType * type2 = e2->type;
    e3->loc = currentSymTab->genTemp(type2);
    e3->type = type2;
	quad.emit(quadEntry(OP_INT2DBL, e3->loc->name, e1->loc->name));
	e1->loc = e3->loc;
	e1->type = e3->loc->type;
}

void convInt2Char(exp_t * e1, exp_t * e2){
	exp_t * e3 = new exp_t();
	complexType * type2 = e2->type;
    e3->loc = currentSymTab->genTemp(type2);
    e3->type = type2;
    quad.emit(quadEntry(OP_INT2CHAR, e3->loc->name, e1->loc->name));
    e1->loc = e3->loc;
    e1->type = e3->loc->type;
}

void convChar2Int(exp_t * e1, exp_t * e2){
	exp_t * e3 = new exp_t();
	complexType * type2 = e2->type;
    e3->loc = currentSymTab->genTemp(type2);
    e3->type = type2;
    quad.emit(quadEntry(OP_CHAR2INT, e3->loc->name, e1->loc->name));
    e1->loc = e3->loc;
    e1->type = e3->loc->type;
}

void convDbl2Int(exp_t * e1, exp_t * e2){
	exp_t * e3 = new exp_t();
	complexType * type2 = e2->type;
    e3->loc = currentSymTab->genTemp(type2);
    e3->type = type2;
    quad.emit(quadEntry(OP_DBL2INT, e3->loc->name, e1->loc->name));
    e1->loc = e3->loc;		
    e1->type = e3->loc->type;
}



void convBool2Int(exp_t *e){
	if(e->type->bType == type_BOOL)		
		return;
	complexType * tint = new complexType(type_INT);
	exp_t * exp = new exp_t();
	exp->type = tint;
	exp->loc = currentSymTab->genTemp(tint);
	backPatch(e->trueList, quad.nextInstr);
	string nameNew = exp->loc->name;
	quad.emit(quadEntry(OP_COPY, nameNew, "1"));
	backPatch(e->falseList, quad.nextInstr);
    quad.emit(quadEntry(OP_COPY, nameNew, "0"));
    e->loc = exp->loc;
    e->type = exp->type;
}

void conv2Bool(exp_t * e) {
    if(e->type->bType != type_BOOL) {
        // create true list and false list
        e->falseList = new List(quad.nextInstr);
        quad.emit(quadEntry(OP_EQ, "", e->loc->name, "0"));
        e->trueList = new List(quad.nextInstr);
        quad.emit(quadEntry(OP_GOTO_O, ""));
    }
}

/************CONV<E1>2<E2>: END***********/

bool paramTypeCheck(exp_t *e1, exp_t *e2){
	if(e1->type->bType == type_PTR && e2->type->bType == type_PTR){
		return true;
	}
	return typeCheck(e1, e2, true);
}

// check the types of parameters of a function with the arguments and also matches the number of arguments required.
bool checkParams(exp_t e, vector<exp_t *> *args){
	vector<symEntry *> &v = e.loc->nestedTable->entries;
	int sz = v.size();
	int n = 0;
	for(int i=0;i<sz;i++){
		if(v[i]->isParam){
			exp_t * e1 = (*args)[n];
			exp_t e2;
			e2.type = v[i]->type;

			if(!paramTypeCheck(&e2,e1)){
				return false;
			}
			n++;
			if(n>args->size()){
				return false;
			}
		}
	}
	if(n == args->size()){
		return true;
	}
	return false;
}

//Utility function that Coverts int to string
string i2s(int n) {
    char ans[20];
    sprintf(ans, "%d", n);
    return ans;
}





int main() {
    yyparse();
    //currentSymTab->print();
    /*cout<<"#######################doubleLabels"<<endl;
    for(int i=0;i<doubleLabels.size();i++){
    	cout<<doubleLabels[i].d<<endl;
    	cout<<doubleLabels[i].d_arr[0]<<' '<<doubleLabels[i].d_arr[1]<<endl;
    }*/

     globalSymTab->print();
     for(int i = 0; i < (int)globalSymTab->entries.size(); ++i) {
         if(globalSymTab->entries[i]->nestedTable != NULL) {
             globalSymTab->entries[i]->nestedTable->print();
         }
     }
     FILE *fp;
     fp = fopen("ass5_15CS30006_quads_custom.out","w");
     printAllQuads(fp);
     fclose(fp);

     FILE *fp2;
     fp2 = fopen("ass5_15CS30006_custom.s","w");
     genTargetCode(fp2);
     fclose(fp2);
    return 0;
}
