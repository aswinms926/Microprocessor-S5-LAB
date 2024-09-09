#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void printfile(FILE* fp , char str[]);
void main() 
{
    char opcode[10], operand[10], label[10], mnemonic[10], code[10];
    int locctr, start, length;
    FILE *input, *optab, *symtab, *output;
    input = fopen("input.txt", "r");
    optab = fopen("optab.txt", "r");
    symtab = fopen("symtab.txt", "w");
    output = fopen("intermediate.txt", "w");
    fscanf(input, "%s\t%s\t%s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0) 
    {
        start = atoi(operand);
        locctr = start;
        fprintf(output, "\t%s\t%s\t%s\n", label, opcode, operand);
        fscanf(input, "%s\t%s\t%s", label, opcode, operand);
    } 
    else
        locctr = 0;
    while (strcmp(opcode, "END") != 0) 
    {
        fprintf(output, "%X\t", locctr);
        if (strcmp(label, "**") != 0)
            fprintf(symtab, "%s\t%X\n", label, locctr);
        rewind(optab);
        fscanf(optab, "%s\t%s", code, mnemonic);
        while (strcmp(code, "END") != 0) 
        {
            if (strcmp(opcode, code) == 0) 
            {
                locctr += 3;
                break;
            }
            fscanf(optab, "%s\t%s", code, mnemonic);
        }
        if (strcmp(opcode, "WORD") == 0)
            locctr += 3;
        else if (strcmp(opcode, "RESW") == 0)
            locctr += (3 * atoi(operand));
        else if (strcmp(opcode, "RESB") == 0)
            locctr += atoi(operand);
        else if (strcmp(opcode, "BYTE") == 0)
            locctr += (strlen(operand) - 3);
        fprintf(output, "%s\t%s\t%s\n", label, opcode, operand);
        fscanf(input, "%s\t%s\t%s", label, opcode, operand);
    }
    fprintf(output, "%X\t", locctr);
    fprintf(output, "%s\t%s\t%s\n", label, opcode, operand);
    length = locctr - start;
    rewind(input);
    rewind(optab);
    printfile(input , "input");
    printfile(optab , "optab");
    fclose(symtab);
    fclose(output);
    symtab = fopen("symtab.txt", "r");
    output = fopen("intermediate.txt", "r");
    printfile(output , "intermediate");
    printf("\nThe length of program: %X", length);
    printfile(symtab , "symtab");
}
void printfile(FILE* fp , char str[])
{
    printf("\n\nThe contents of %s file is: \n",str);
    char ch = fgetc(fp);
    while (ch != EOF) 
    {
        
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);
}