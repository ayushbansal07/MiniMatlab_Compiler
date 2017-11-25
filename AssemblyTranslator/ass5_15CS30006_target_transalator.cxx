#include "ass5_15CS30006_translator.h"
#define CONSTANT_OFFSET 8

vector<int> numberOfParams;

void quadEntry::genTargetCode(FILE * out) {
    switch(op) {
        case(OP_PLUS):
            {
                symEntry * res = currentSymTab->lookUp(result);
                symEntry * op1 = currentSymTab->lookUp(arg1);
                if(currentSymTab->isPresent(arg2)) {
                    symEntry * op2 = currentSymTab->lookUp(arg2);
                    if(op1->type->bType == type_MATRIX) {
                        fprintf(out, "\tleaq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t%d(%%rbp), %%rdx", op2->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\taddq\t%%rdx, %%rax");
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    } else {
                        if(res->type->bType == type_CHAR) {
                            fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                            fprintf(out,"\n");
                            fprintf(out, "\tmovzbq\t%d(%%rbp), %%rdx", op2->offset + CONSTANT_OFFSET);
                            fprintf(out,"\n");
                            fprintf(out, "\taddq\t%%rdx, %%rax");
                            fprintf(out,"\n");
                            fprintf(out, "\tmovb\t%%al, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                            fprintf(out,"\n");
                        } else if(op1->type->bType == type_DOUBLE) {
                            fprintf(out, "\tmovsd\t%d(%%rbp), %%xmm0", op1->offset + CONSTANT_OFFSET);  
                            fprintf(out,"\n");
                            fprintf(out, "\tmovsd\t%d(%%rbp), %%xmm1", op2->offset + CONSTANT_OFFSET);  
                            fprintf(out,"\n");
                            fprintf(out, "\taddps\t%%xmm1, %%xmm0");  
                            fprintf(out,"\n");
                            fprintf(out, "\tmovsd\t%%xmm0, %d(%%rbp)", res->offset + CONSTANT_OFFSET); 
                            fprintf(out,"\n");
                            
                        } else {
                            fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                            fprintf(out,"\n");
                            fprintf(out, "\tmovq\t%d(%%rbp), %%rdx", op2->offset + CONSTANT_OFFSET);
                            fprintf(out,"\n");
                            fprintf(out, "\taddq\t%%rdx, %%rax");
                            fprintf(out,"\n");
                            fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                            fprintf(out,"\n");
                        }
                    }
                    
                } else {
                    if(res->type->bType == type_CHAR) {
                        fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovzbq\t%s, %%rdx", arg2.c_str());
                        fprintf(out,"\n");
                        fprintf(out, "\taddq\t%%rdx, %%rax");
                        fprintf(out,"\n");
                        fprintf(out, "\tmovb\t%%al, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    }
                        else {
                        fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t$%s, %%rdx", arg2.c_str());
                        fprintf(out,"\n");
                        fprintf(out, "\taddq\t%%rdx, %%rax");
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);   
                        fprintf(out,"\n");
                    }
                }
            }
            break;
        case(OP_MINUS):
            {
                symEntry * res = currentSymTab->lookUp(result);
                symEntry * op1 = currentSymTab->lookUp(arg1);
                if(currentSymTab->isPresent(arg2)) {
                    symEntry * op2 = currentSymTab->lookUp(arg2);
                    if(res->type->bType == type_CHAR) {
                        fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovzbq\t%d(%%rbp), %%rdx", op2->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tsubq\t%%rdx, %%rax");
                        fprintf(out,"\n");
                        fprintf(out, "\tmovb\t%%al, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    } else if(op1->type->bType == type_DOUBLE) {
                            fprintf(out, "\tmovsd\t%d(%%rbp), %%xmm0", op1->offset + CONSTANT_OFFSET);  
                            fprintf(out,"\n");
                            fprintf(out, "\tmovsd\t%d(%%rbp), %%xmm1", op2->offset + CONSTANT_OFFSET);  
                            fprintf(out,"\n");
                            fprintf(out, "\tsubps\t%%xmm1, %%xmm0");  
                            fprintf(out,"\n");
                            fprintf(out, "\tmovsd\t%%xmm0, %d(%%rbp)", res->offset + CONSTANT_OFFSET); 
                            fprintf(out,"\n");
                            
                        } 
                    else {
                        fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t%d(%%rbp), %%rdx", op2->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tsubq\t%%rdx, %%rax");
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    }
                } else {
                    if(res->type->bType == type_CHAR) {
                        fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovzbq\t%s, %%rdx", arg2.c_str());
                        fprintf(out,"\n");
                        fprintf(out, "\tsubq\t%%rdx, %%rax");
                        fprintf(out,"\n");
                        fprintf(out, "\tmovb\t%%al, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    } else {

                        fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t$%s, %%rdx", arg2.c_str());
                        fprintf(out,"\n");
                        fprintf(out, "\tsubq\t%%rdx, %%rax");
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);   
                        fprintf(out,"\n");
                    }
                }
            }

            break;
        case(OP_MULT):
            {
                symEntry * res = currentSymTab->lookUp(result);
                symEntry * op1 = currentSymTab->lookUp(arg1);
                if(currentSymTab->isPresent(arg2)) {
                    symEntry * op2 = currentSymTab->lookUp(arg2);
                    if(res->type->bType == type_CHAR) {
                        fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovzbq\t%d(%%rbp), %%rdx", op2->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\timulq\t%%rdx, %%rax");
                        fprintf(out,"\n");
                        fprintf(out, "\tmovb\t%%al, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    } else if(op1->type->bType == type_DOUBLE) {
                            fprintf(out, "\tmovsd\t%d(%%rbp), %%xmm0", op1->offset + CONSTANT_OFFSET);  
                            fprintf(out,"\n");
                            fprintf(out, "\tmovsd\t%d(%%rbp), %%xmm1", op2->offset + CONSTANT_OFFSET);  
                            fprintf(out,"\n");
                            fprintf(out, "\tmulps\t%%xmm1, %%xmm0");  
                            fprintf(out,"\n");
                            fprintf(out, "\tmovsd\t%%xmm0, %d(%%rbp)", res->offset + CONSTANT_OFFSET); 
                            fprintf(out,"\n");
                            
                        }  
                    else {
                        fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t%d(%%rbp), %%rdx", op2->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\timulq\t%%rdx, %%rax");
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    }
                } else {
                    if(res->type->bType == type_CHAR) {
                        fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovzbq\t$%s, %%rdx", arg2.c_str());
                        fprintf(out,"\n");
                        fprintf(out, "\timulq\t%%rdx, %%rax");
                        fprintf(out,"\n");
                        fprintf(out, "\tmovb\t%%al, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    } else {
                        fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t$%s, %%rdx", arg2.c_str());
                        fprintf(out,"\n");
                        fprintf(out, "\timulq\t%%rdx, %%rax");
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    }
                }
            }
            break;
        case(OP_DIV):
            {
                symEntry * res = currentSymTab->lookUp(result);
                symEntry * op1 = currentSymTab->lookUp(arg1);
                symEntry * op2 = currentSymTab->lookUp(arg2);
                if(res->type->bType == type_CHAR) {
                    fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tmovzbq\t%d(%%rbp), %%rcx", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcltd");
                    fprintf(out,"\n");
                    fprintf(out, "\tidivq\t%%rcx");
                    fprintf(out,"\n");
                    fprintf(out, "\tmovb\t%%al, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                } else if(op1->type->bType == type_DOUBLE) {
                            fprintf(out, "\tmovsd\t%d(%%rbp), %%xmm0", op1->offset + CONSTANT_OFFSET);  
                            fprintf(out,"\n");
                            fprintf(out, "\tmovsd\t%d(%%rbp), %%xmm1", op2->offset + CONSTANT_OFFSET);  
                            fprintf(out,"\n");
                            fprintf(out, "\tdivps\t%%xmm1, %%xmm0");  
                            fprintf(out,"\n");
                            fprintf(out, "\tmovsd\t%%xmm0, %d(%%rbp)", res->offset + CONSTANT_OFFSET); 
                            fprintf(out,"\n");
                            
                        }  
                else {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rcx", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcltd");
                    fprintf(out,"\n");
                    fprintf(out, "\tidivq\t%%rcx");
                    fprintf(out,"\n");
                    fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                }
            }
            break;
        case(OP_MOD):
            {
                symEntry * res = currentSymTab->lookUp(result);
                symEntry * op1 = currentSymTab->lookUp(arg1);
                symEntry * op2 = currentSymTab->lookUp(arg2);
                if(res->type->bType == type_CHAR) {
                    fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tmovzbq\t%d(%%rbp), %%rcx", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcltd");
                    fprintf(out,"\n");
                    fprintf(out, "\tidivq\t%%rcx");
                    fprintf(out,"\n");
                    fprintf(out, "\tmovq\t%%rdx, %%rax");
                    fprintf(out,"\n");
                    fprintf(out, "\tmovb\t%%al, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                } else {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rcx", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcltd");
                    fprintf(out,"\n");
                    fprintf(out, "\tidivq\t%%rcx");
                    fprintf(out,"\n");
                    fprintf(out, "\tmovq\t%%rdx, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                }
            }
            break;
        case(OP_UMINUS):
            {
                symEntry * res = currentSymTab->lookUp(result);
                symEntry * op1 = currentSymTab->lookUp(arg1);
                if(res->type->bType == type_CHAR) {
                    fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tnegq\t%%rax");
                    fprintf(out,"\n");
                    fprintf(out, "\tmovb\t%%al, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                }
                else if(op1->type->bType == type_DOUBLE) {
                            fprintf(out, "\tmovsd\t%d(%%rbp), %%xmm0", op1->offset + CONSTANT_OFFSET);  
                            fprintf(out,"\n");
                            fprintf(out, "\txorpd\t%%xmm1, %%xmm1");  
                            fprintf(out,"\n");
                            fprintf(out, "\tsubps\t%%xmm0, %%xmm1");  
                            fprintf(out,"\n");
                            fprintf(out, "\tmovsd\t%%xmm1, %d(%%rbp)", res->offset + CONSTANT_OFFSET); 
                            fprintf(out,"\n");
                            
                        }   
                        else {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tnegq\t%%rax");
                    fprintf(out,"\n");
                    fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                }
            }
            break;
        case(OP_COPY):
            {
                symEntry * res = currentSymTab->lookUp(result);
                if(currentSymTab->isPresent(arg1)) {
                    symEntry * op1 = currentSymTab->lookUp(arg1);
                    if(res->type->bType == type_CHAR) {
                        fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovb\t%%al, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    } else if(op1->type->bType == type_MATRIX) {
                        fprintf(out, "\tleaq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    }else if(op1->type->bType == type_DOUBLE) {
                        fprintf(out, "\tmovsd\t%d(%%rbp), %%xmm0", op1->offset + CONSTANT_OFFSET);  
                        fprintf(out,"\n");
                        fprintf(out, "\tmovsd\t%%xmm0, %d(%%rbp)", res->offset + CONSTANT_OFFSET); 
                        fprintf(out,"\n");
                        
                    } else {
                        fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    }
                } else {

                    if(res->type->bType == type_CHAR) {
                        fprintf(out, "\tmovb\t$%s, %%al", arg1.c_str());
                        fprintf(out,"\n");
                        fprintf(out, "\tmovb\t%%al, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    } else if(res->type->bType == type_DOUBLE) {
                        if(res->wasInitialised){
                            string label = "DBL" + i2s(res->init.dblLabel);
                            fprintf(out, "\tmovsd\t%s(%%rip), %%xmm0", label.c_str());  
                            fprintf(out,"\n");
                            fprintf(out, "\tmovq\t%%xmm0, %d(%%rbp)", res->offset + CONSTANT_OFFSET);  
                            fprintf(out,"\n");
                        }
                        
                    } else {
                        fprintf(out, "\tmovq\t$%s, %%rax", arg1.c_str());
                        fprintf(out,"\n");
                        fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);   
                        fprintf(out,"\n");
                    } 
                }
            }
            break;
        case(OP_TRUE):
            break;
        case(OP_FALSE):
            break;
        case(OP_JLT):
            {
                int idx = atoi(result.c_str());
                symEntry * op1 = currentSymTab->lookUp(arg1);
                symEntry * op2 = currentSymTab->lookUp(arg2);
                if(op1->type->bType == type_CHAR) {
                    fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcmpb\t%%al, %d(%%rbp)", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tjl\t\t.L%d", quad.quad_v[idx].labelIdx);
                    fprintf(out,"\n");
                } else {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcmpq\t%%rax, %d(%%rbp)", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tjl\t\t.L%d", quad.quad_v[idx].labelIdx);
                    fprintf(out,"\n");
                }
            }
            break;
        case(OP_JLE):
            {
                int idx = atoi(result.c_str());
                symEntry * op1 = currentSymTab->lookUp(arg1);
                symEntry * op2 = currentSymTab->lookUp(arg2);
                if(op1->type->bType == type_CHAR) {
                    fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcmpb\t%%al, %d(%%rbp)", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tjle\t\t.L%d", quad.quad_v[idx].labelIdx);
                    fprintf(out,"\n");
                } else {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcmpq\t%%rax, %d(%%rbp)", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tjle\t\t.L%d", quad.quad_v[idx].labelIdx);
                    fprintf(out,"\n");
                }
            }
            break;
        case(OP_JGT):
            {
                int idx = atoi(result.c_str());
                symEntry * op1 = currentSymTab->lookUp(arg1);
                symEntry * op2 = currentSymTab->lookUp(arg2);
                if(op1->type->bType == type_CHAR) {
                    fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcmpb\t%%al, %d(%%rbp)", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tjg\t\t.L%d", quad.quad_v[idx].labelIdx);
                    fprintf(out,"\n");
                } else {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcmpq\t%%rax, %d(%%rbp)", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tjg\t\t.L%d", quad.quad_v[idx].labelIdx);
                    fprintf(out,"\n");
                }
            }
            break;
        case(OP_JGE):
            {
                int idx = atoi(result.c_str());
                symEntry * op1 = currentSymTab->lookUp(arg1);
                symEntry * op2 = currentSymTab->lookUp(arg2);
                if(op1->type->bType == type_CHAR) {
                    fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcmpb\t%%al, %d(%%rbp)", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tjge\t\t.L%d", quad.quad_v[idx].labelIdx);
                    fprintf(out,"\n");
                } else {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcmpq\t%%rax, %d(%%rbp)", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tjge\t\t.L%d", quad.quad_v[idx].labelIdx);
                    fprintf(out,"\n");
                }
            }
            break;
        case(OP_EQ):
            {
                int idx = atoi(result.c_str());
                symEntry * op1 = currentSymTab->lookUp(arg1);
                symEntry * op2 = currentSymTab->lookUp(arg2);
                if(op1->type->bType == type_CHAR) {
                    fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcmpb\t%%al, %d(%%rbp)", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tje\t\t.L%d", quad.quad_v[idx].labelIdx);
                    fprintf(out,"\n");
                } else {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcmpq\t%%rax, %d(%%rbp)", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tje\t\t.L%d", quad.quad_v[idx].labelIdx);
                    fprintf(out,"\n");
                }
            }
            break;
        case(OP_NEQ):
            {
                int idx = atoi(result.c_str());
                symEntry * op1 = currentSymTab->lookUp(arg1);
                symEntry * op2 = currentSymTab->lookUp(arg2);
                if(op1->type->bType == type_CHAR) {
                    fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcmpb\t%%al, %d(%%rbp)", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tjne\t\t.L%d", quad.quad_v[idx].labelIdx);
                    fprintf(out,"\n");
                } else {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op2->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tcmpq\t%%rax, %d(%%rbp)", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tjne\t\t.L%d", quad.quad_v[idx].labelIdx);
                    fprintf(out,"\n");
                }
            }
            break;
        case(OP_INT2DBL):
        {
                symEntry * res = currentSymTab->lookUp(result);
                symEntry * op1 = currentSymTab->lookUp(arg1);
                fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                fprintf(out,"\n");
                fprintf(out, "\tcvtsi2ss\t%%rax, %%xmm0");
                fprintf(out,"\n");
                fprintf(out, "\tmovsd\t%%xmm0, %d(%%rbp)", res->offset + CONSTANT_OFFSET); 
                fprintf(out,"\n");
                
        }
            break;
        case(OP_DBL2INT):
        {
                symEntry * res = currentSymTab->lookUp(result);
                symEntry * op1 = currentSymTab->lookUp(arg1);
                fprintf(out, "\tmovq\t%d(%%rbp), %%xmm0", op1->offset + CONSTANT_OFFSET);
                fprintf(out,"\n");
                fprintf(out, "\tcvttss2si\t%%xmm0, %%rax");
                fprintf(out,"\n");
                fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET); 
                fprintf(out,"\n");
                
        }
            break;
        case(OP_INT2CHAR):
            break;
        case(OP_CHAR2INT):
            break;
        case(OP_L_VAL_AT):
            {
                symEntry * res = currentSymTab->lookUp(result);
                symEntry * op1 = currentSymTab->lookUp(arg1);
                if(op1->type->bType == type_CHAR) {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tmovzbq\t%d(%%rbp), %%rdx", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tmovb\t%%dl, (%%rax)");
                    fprintf(out,"\n");
                } else {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rdx", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tmovq\t%%rdx, (%%rax)");
                    fprintf(out,"\n");
                }
            }
            break;
        case(OP_R_VAL_AT):
            {
                symEntry * res = currentSymTab->lookUp(result);
                symEntry * op1 = currentSymTab->lookUp(arg1);
                if(res->type->bType == type_CHAR) {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tmovzbq\t(%%rax), %%rax");
                    fprintf(out,"\n");
                    fprintf(out, "\tmovb\t%%al, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                } else {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tmovq\t(%%rax), %%rax");
                    fprintf(out,"\n");
                    fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                }
            }
            break;
        case(OP_L_INDEX):
            {
                symEntry * res = currentSymTab->lookUp(result);
                symEntry * op1 = currentSymTab->lookUp(arg1);
                symEntry * op2 = currentSymTab->lookUp(arg2);

                fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                fprintf(out,"\n");
                fprintf(out, "\tmovsd\t%d(%%rbp), %%xmm0", op2->offset + CONSTANT_OFFSET);
                fprintf(out,"\n");
                if(res->offset < 0) {
                    fprintf(out, "\tmovsd\t%%xmm0, %d(%%rbp, %%rax)", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                }
                else {
                    fprintf(out, "\tleaq\t%d(%%rbp), %%rcx", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tmovsd\t%%xmm0, (%%rcx, %%rax)");
                    fprintf(out,"\n");
                }
            }
            break;
        case(OP_R_INDEX):
            {
                symEntry * res = currentSymTab->lookUp(result);
                symEntry * op1 = currentSymTab->lookUp(arg1);
                symEntry * op2 = currentSymTab->lookUp(arg2);

                fprintf(out, "\tmovq\t%d(%%rbp), %%rax", op2->offset + CONSTANT_OFFSET);
                fprintf(out,"\n");
                if(op1->offset < 0) {
                    fprintf(out, "\tmovsd\t%d(%%rbp, %%rax), %%xmm0", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                }
                else {
                    fprintf(out, "\tleaq\t%d(%%rbp), %%rcx", op1->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                    fprintf(out, "\tmovsd\t(%%rcx, %%rax), %%xmm0");
                    fprintf(out,"\n");
                }
                fprintf(out, "\tmovsd\t%%xmm0, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                fprintf(out,"\n");
            }
            break;
        case(OP_ADDR):
            {
                symEntry * res = currentSymTab->lookUp(result);
                symEntry * op1 = currentSymTab->lookUp(arg1);
                fprintf(out, "\tleaq\t%d(%%rbp), %%rax", op1->offset + CONSTANT_OFFSET);
                fprintf(out,"\n");
                fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                fprintf(out,"\n");
            }
            
            break;
        case(OP_PARAM):
            {
                if(currentSymTab->isPresent(result)) {
                    symEntry * res = currentSymTab->lookUp(result);
                    if(res->type->bType == type_CHAR) {
                        fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tpushq\t%%rax");
                        fprintf(out,"\n");
                        //numberOfParams[numberOfParams.size()-1]++;
                    } else if(res->type->bType == type_MATRIX) {
                        fprintf(out, "\tleaq\t%d(%%rbp), %%rax", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tpushq\t%%rax");
                        fprintf(out,"\n");
                        //numberOfParams[numberOfParams.size()-1]++;
                    }else if(res->type->bType == type_DOUBLE) {
                        fprintf(out, "\tmovsd\t%d(%%rbp), %%xmm0", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        //fprintf(out, "\tpushq\t%%xmm0\n");
                        //numberOfParams[numberOfParams.size()-1]++;
                        //fprintf(out, "\tmovq\t%d(%%rbp), %%rdi\n", res->offset + CONSTANT_OFFSET);
                    } else {
                        fprintf(out, "\tmovq\t%d(%%rbp), %%rdi", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                        fprintf(out, "\tpushq\t%%rdi");
                        fprintf(out,"\n");
                        //numberOfParams[numberOfParams.size()-1]++;
                        //fprintf(out, "\tmovq\t%d(%%rbp), %%rdi\n", res->offset + CONSTANT_OFFSET);
                    }
                } else {
                    fprintf(out, "\tpushq\t$%s", result.c_str());
                    fprintf(out,"\n");
                }
            }
            break;
        case(OP_GOTO_O):
            {
                int idx = atoi(result.c_str());
                fprintf(out, "\tjmp\t\t.L%d", quad.quad_v[idx].labelIdx);
                fprintf(out,"\n");
            }
            break;
        case(OP_CALL):
            {
                symEntry * func = globalSymTab->lookUp(arg1);
                symEntry * res = currentSymTab->lookUp(result);
                fprintf(out, "\tcall\t%s\n", arg1.c_str());
                fprintf(out, "\taddq\t$%d, %%rsp", func->nestedTable->sizeParam);
                fprintf(out,"\n");
                if(res->type->bType != type_VOID) {
                    if(res->type->bType == type_CHAR) {
                        fprintf(out, "\tmovb\t%%al, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    } else if(res->type->bType == type_MATRIX || res->type->bType == type_PTR) {
                        fprintf(out, "\tleaq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    } else {
                        fprintf(out, "\tmovq\t%%rax, %d(%%rbp)", res->offset + CONSTANT_OFFSET);
                        fprintf(out,"\n");
                    }
                }
            }
            break;
        case(OP_RETURN):
            fprintf(out, "\tleave");
            fprintf(out,"\n");
            fprintf(out, "\tret");
            fprintf(out,"\n");
            break;
        case(OP_RETURN_VAL):
            {
                symEntry * res = currentSymTab->lookUp(result);
                if(res->type->bType == type_CHAR) {
                    fprintf(out, "\tmovzbq\t%d(%%rbp), %%rax", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                } else {
                    fprintf(out, "\tmovq\t%d(%%rbp), %%rax", res->offset + CONSTANT_OFFSET);
                    fprintf(out,"\n");
                }
                fprintf(out, "\tleave");
                fprintf(out,"\n");
                fprintf(out, "\tret");
                fprintf(out,"\n");
            }
            break;
        case(OP_BW_NOT):
            break;
        case(OP_SHL):
            break;
        case(OP_SHR):
            break;
        case(OP_BW_AND):
            break;
        case(OP_BW_XOR):
            break;
        case(OP_BW_OR):
            break;
        case(OP_FUNC_START):
            currentSymTab = globalSymTab->lookUp(result)->nestedTable;
            fprintf(out, "\t.globl\t%s", result.c_str());
            fprintf(out,"\n");
            fprintf(out, "\t.type\t%s, @function", result.c_str());
            fprintf(out,"\n");
            fprintf(out, "%s:", result.c_str());
            fprintf(out,"\n");
            fprintf(out, "\tpushq\t%%rbp");
            fprintf(out,"\n");
            fprintf(out, "\tmovq\t%%rsp, %%rbp");
            fprintf(out,"\n");
            fprintf(out, "\tsubq\t$%d, %%rsp", currentSymTab->sizeLocal);
            fprintf(out,"\n");
            //numberOfParams.push_back(0);
            break;
        case(OP_FUNC_END):
            fprintf(out, "\tleave");
            fprintf(out,"\n");
            fprintf(out, "\tret");
            fprintf(out,"\n");
            fprintf(out, "\t.size\t%s, .-%s", result.c_str(), result.c_str());
            fprintf(out,"\n");
            /*for (int i=0;i<numberOfParams[numberOfParams.size()-1];++i){
                fprintf(out, "\tpopq\t%%rax\n");
            }*/
            break;
        default:
            printf("Error ! Unknown opcodeType.\n");
            exit(-1);
    }
}

bool isLeaderType(opcodeType op){
    if( op == OP_JLT ||
            op == OP_JGT ||
            op == OP_JLE ||
            op == OP_JGE ||
            op == OP_EQ ||
            op == OP_NEQ ||
            op == OP_GOTO_O
        ) return true;

        return false;
}

vector <bool> markAllLabels() {
    int labelCounter = 0;
    vector <bool> mark(quad.quad_v.size(), false);
    for(int i = 0; i < (int)quad.quad_v.size(); ++i) {
        opcodeType op = quad.quad_v[i].op;
        if(isLeaderType(op)) {
            mark[atoi(quad.quad_v[i].result.c_str())] = true;
        }
    }

    for(int i = 0; i < (int)quad.quad_v.size(); ++i) {
        if(mark[i]) quad.quad_v[i].labelIdx = labelCounter++;
    }
    return mark;
}

void labelDoubles(FILE *out){
    for(int i=0;i<doubleLabels.size();i++){
        string lbl = "DBL" + i2s(i);
        fprintf(out,"%s:\n\t.long\t%d\n\t.long\t%d\n",lbl.c_str(),doubleLabels[i].d_arr[0],doubleLabels[i].d_arr[1]); 
    }
}

void adjustOffset(symTable * sym) {    
    sym->sizeLocal = sym->entries[sym->entries.size()-1]->offset;

}

void genTargetCode(FILE * out) {

    for(int i = (int)globalSymTab->entries.size()-1; i >= 0; --i) {
        adjustOffset(globalSymTab->entries[i]->nestedTable);
    }

    numberOfParams.resize(0);

    for(int i = 0; i < (int)globalSymTab->entries.size(); ++i) {
        if(globalSymTab->entries[i]->nestedTable != NULL) {
            currentSymTab = globalSymTab->entries[i]->nestedTable;
            break;
        }
    }

    labelDoubles(out);

   
    if(doubleLabels.size() > 0) {
        fprintf(out, "\t.text\n");
    }

    vector <bool> mark = markAllLabels();

    for(int j = 0; j < (int)quad.quad_v.size(); ++j) {
        if(quad.quad_v[j].op == OP_FUNC_START) {
            currentSymTab = globalSymTab->lookUp(quad.quad_v[j].result)->nestedTable;
            break;
        }
    }

    for(int i = 0; i < (int)quad.quad_v.size(); ++i) {
        if(mark[i]) {
            fprintf(out, ".L%d:\n", quad.quad_v[i].labelIdx);
        }
        quad.quad_v[i].genTargetCode(out);
        if(quad.quad_v[i].op == OP_FUNC_END) {
            for(int j = i + 1; j < (int)quad.quad_v.size(); ++j) {
                if(quad.quad_v[j].op == OP_FUNC_START) {
                    currentSymTab = globalSymTab->lookUp(quad.quad_v[j].result)->nestedTable;
                    break;
                }
            }
        }
    }   

}