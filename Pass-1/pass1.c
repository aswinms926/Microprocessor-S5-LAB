  #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include<stdbool.h>

 void main()
 {
    FILE *source,*intermediate,*symtab,*optab,*length;
    char label[30],opcode[20],operand[20],symtab_data[30],optab_data[30];
    int locctr,start_addr,prog_len;
    bool symbol_found,opcode_found;

    source =fopen("source.txt","r");
    optab =fopen("optab.txt","r");
    intermediate =fopen("intermediate.txt","w");
    symtab =fopen("symtab.txt","w+");
    length =fopen("length.txt","w");

    fscanf(source,"%s%s%s",label,opcode,operand);
    if(strcmp(opcode,"START")==0)
    {
        start_addr=atoi(operand);
        locctr=start_addr;
        fprintf(intermediate,"\t\t%-15s\t%-10s\t%-20s\n",label,opcode,operand);
    }
    else{
        locctr=0;
    }
    fscanf(source,"%s%s%s",label,opcode,operand);
    while(strcmp(opcode,"END")!=0)
    {
        if(strcmp(label,"**")!=0)
        {
            symbol_found=false;
            rewind(symtab);
            while(!feof(symtab))
            {
                fscanf(symtab,"%s",symtab_data);
                if(strcmp(symtab_data,label)==0)
                {
                    symbol_found=true;
                    printf("ERROR");

                }
            }
            if(symbol_found==false)
            {
                fprintf(symtab,"%s\t%d\n",label,locctr);
            }
        }    
            opcode_found=false;
            rewind(optab);
            while(!feof(optab))
            {
                fscanf(optab,"%s",optab_data);
                if(strcmp(optab_data,opcode)==0)
                {
                    opcode_found=true;

                }
            }
            fprintf(intermediate,"%d\t",locctr);
            if(opcode_found==true)
            {
                locctr+=3;
            }
            else if(strcmp(opcode,"WORD")==0)
            {
                locctr+=3;               
            }
             else if(strcmp(opcode,"RESW")==0)
            {
                locctr+=3*atoi(operand);               
            } 
            else if(strcmp(opcode,"RESB")==0)
            {
                locctr+=atoi(operand);               
            } 
            else if(strcmp(opcode,"BYTE")==0)
            {
                locctr+=strlen(operand)-3;               
            }
            else{
                printf("Error: Invalid operation code");
            }
            fprintf(intermediate,"%-15s\t%-10s\t%-20s\n",label,opcode,operand);
            fscanf(source,"%s%s%s",label,opcode,operand);
        }
        fprintf(intermediate,"%d\t%-15s\t%-10s\t%-20s\n",locctr,label,opcode,operand);
        prog_len=locctr-start_addr;
        fprintf(length,"%d",prog_len);
       fclose(length);
        fclose(intermediate);
        fclose(symtab);
        fclose(optab);
        fclose(source);

    }
 
 