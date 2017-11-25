#ifndef __TRANSLATOR_H
#define __TRANSLATOR_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <assert.h>
#include <map>
#include <iomanip>

using namespace std;

#define SIZE_OF_INT     8
#define SIZE_OF_DOUBLE  8
#define SIZE_OF_CHAR    1
#define SIZE_OF_VOID    0
#define SIZE_OF_PTR     8
#define SIZE_OF_BOOL    1
#define SIZE_OF_FUNC    0

//enum for basic types
typedef enum {
	type_BOOL = 0,
	type_CHAR,
	type_INT,
    type_DOUBLE,
    type_MATRIX,
    type_FUNC,
	type_VOID,
    type_PTR
} basicType;

//All types
class complexType {
public:
	complexType();             //Empty Constructor
    complexType(basicType b);  //Constructor when a basic Type is given
    //Copy Constructor
    complexType(complexType *t);

    basicType bType;            //stores the basic type.
    int size;                   //The full size of this type.

    //For MATRIX
    int leftIndex;              //no. of rows in matrix
    int rightIndex;             //no. of cols in matrix

    //FOR PTR
    complexType * next;         //type of next in case of ptr.

    int getSize();              //function that returns size of the type.
    void print();               //print function for type.
};

//Checks if 2 given types are same.
bool areEqual(complexType * t1, complexType * t2);

// union for storing the initial values.
union dblunion {                 //Stores int values
    float d;          
    unsigned int d_arr[2];
};

union initialVal {
    int intVal;                 //Stores int values
    dblunion doubleVal;           //Stores double values
    char charVal;               //Stores char values
    vector<dblunion> * matVal;    //Stores double values for matrix in a vector.
    int dblLabel;
};

class symTable;

// structure for en entry of symbol table
class symEntry {
public:
	symEntry(string s = "local");                              //Constructor with given scope (default local).
    symEntry(string nm, complexType *tp, string s = "local");  //Constructor with given name, type, scope (default local).

    string name;                                                //Name associated with entry.
    complexType * type;                                         //Type of the entry.
    initialVal init;                                            //Initial Value (if initialised)
    int size;                                                   //Total size
    int offset;					//Offset from local symbol table
    string scope;				//local, global or param
    symTable * nestedTable;     //Nested symbol Table for functions.

    bool wasInitialised;        //Whether or not initialised entry.
    bool isParam;               //For parameters.
    
    void print();               //Print function.
};

// structure for Symbol Table
class symTable {
public:
	symTable();                    //Empty constructor
    symTable(string s);            //Cosntructor with given table name.

	string name;                   //Name of the symbol Table
    int offset;                    //offset
    
    vector <symEntry *> entries;    //List of all entries (of type symEntry)

    symEntry * lookUp(string name);         //a function that returns a pointer to the identifier (if present) or creates a new entry and then returns.
    symEntry * genTemp(complexType * type); //a function to generate a new temporary variable.

    void print();                        //Print fucntion.
    bool isPresent(string s);           //Checks if an entry is present.

    //update an entry in symbol table
    void update(symEntry * s, initialVal init);             //update when initial value is given. sets wasInitialised to true.
    void update(symEntry * s, complexType * t, int sz);     //update when type in size is given.

int sizeLocal;
int sizeParam;
};

extern symTable * globalSymTab;     
extern symTable * currentSymTab;
extern vector<dblunion> doubleLabels;

// enum for all opcodes.
typedef enum {
    OP_PLUS = 1,
    OP_MINUS,
    OP_MULT,
    OP_DIV,
    OP_MOD,
    OP_UMINUS,
    OP_COPY,
    OP_JLT,
    OP_JLE,
    OP_JGT,
    OP_JGE,
    OP_EQ,
    OP_NEQ,
    OP_TRUE,
    OP_FALSE,
    OP_INT2DBL,
    OP_DBL2INT,
    OP_INT2CHAR,
    OP_CHAR2INT,
    OP_L_VAL_AT,
    OP_R_VAL_AT,
    OP_L_INDEX,
    OP_R_INDEX,
    OP_ADDR,
    OP_PARAM,
    OP_GOTO_O,
    OP_CALL,
    OP_RETURN_VAL,
    OP_RETURN,
    OP_SHL,
    OP_SHR,
    OP_BW_NOT,
    OP_BW_AND,
    OP_BW_XOR,
    OP_BW_OR,
    OP_FUNC_START,
    OP_FUNC_END,
    OP_TRANS
} opcodeType;

// Entry of a quad
class quadEntry {
public:
    //different constuctors for different types of arguments.
	quadEntry(opcodeType o, string s1 = "", string s2 = "", string s3 = ""); 
    quadEntry(opcodeType o, string s1, int n);
    quadEntry(opcodeType o, string s1, char c);
    quadEntry(opcodeType o, string s1, double d);

    opcodeType op;              //operator associated.
    string result, arg1, arg2;  //arguments and result names.

    //Fills in the result of current symbol during backPatching.
    void setTarget(int addr);

    //Print function
    void print(FILE * out);

void genTargetCode(FILE * out);
int labelIdx;
};

// structure for list of quad to be generated
class quadList {
public:
    int nextInstr;              // index of next quad to be generated
    int width;                  // width of type
    complexType * type;         // pointer of current type
    symEntry * mat;             //stores the Matrix's location when initialising matrix
    vector <quadEntry> quad_v;      // List of quads
    void emit(quadEntry q);         //pushes the quad in quadList and increments nextInstr
    void print();                   //print function.
};

extern quadList quad;

// node for a list, stores the index of quad
class node {
public:
	node(int idx);        //Constructor when index given.
    node();                 //Empty constructor.

    int qIdx;           // index of the quad
    node * next;        // pointer of the next node
};

// List of nodes, used for trueList, falseList, nextlist etc
class List {
public:
    List(int idx);      //Constructor when index of associated quad given.
    List();             //Empty constructor.
    
    int qIdx;           // index of the quad
    node * head;        // first node of the list
    node * tail;        // last node of the list

    void clear();       //Clears the memory held by the list.
    void print();       //prints the list.

};

//Merges two List
List * mergeList(List * l1, List * l2);

//Utility fucntion to convert int to string
string i2s(int n);

// attribute for expression type non terminals
class exp_t {
public:
    
    List * trueList;        //List of addresses of Jump Statements to be backPatched later when expression evaluates to True.
    List * falseList;       //List of addresses of Jump Statements to be backPatched later when expression evaluates to True.
    
    symEntry * loc;         // pointer to entry in symbol table
    symEntry * array;       // pointer to entry of base array in symbol table
    complexType * type;     // pointer of type
    
    bool isArrayType;       // flag to store if it has offset and is to be dereferenced
    bool isPtrType;         // flag to store if it points at and address and is to be dereferenced
};

// attribute for declaration type non terminals
struct dec_t {
    int width;                      //width of type
    complexType * type;             //pointer of type
};

// attribute for identifier
struct idf_t {
    symEntry * loc;                 // pointer to entry in symbol table
    string * strVal;                // name
};


//Global functions
//convert expressions which are of non-bool into bool type by converting them to condition as expression == 0.
void conv2Bool(exp_t * e);

//converts bool type to int type
void convBool2Int(exp_t * e);

//converts int type to double type
void convInt2Dbl(exp_t * e1, exp_t * e2);

//converts int type to char type
void convInt2Char(exp_t * e1, exp_t * e2);

//converts char type to int type
void convChar2Int(exp_t * e1, exp_t * e2);

//converts double type to int type
void convDbl2Int(exp_t * e1, exp_t * e2);

//fills in address at locations specified in List p
void backPatch(List * & p, int addr);

//Checks if 2 expession types are compatible, tries for conversion if possible otherwise returns false.
bool typeCheck(exp_t * e1, exp_t * e2, bool isAssignment = false, bool isMultiplication = false);

// check the parameters of a function with the arguments
bool checkParams(exp_t e, vector <exp_t * > * v);

void genTargetCode(FILE * out);
vector <bool> markAllLabels();

#endif
