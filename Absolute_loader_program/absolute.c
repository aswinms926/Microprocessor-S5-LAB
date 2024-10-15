 #include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    FILE *fp1,*fp2;
    int i,j,hexaddr;
    char line[50],addr[50];
    
    // Open the record file for reading
    fp1 = fopen("record.txt", "r");
    if (fp1 == NULL) {
        printf("Error opening record.txt\n");
        exit(1);
    }

    do {
        // Read a line from the file
        fscanf(fp1, "%s", line);
        
        // Check if the line is a text record (starts with 'T')
        if (line[0] == 'T') {
            // Extract the starting address from the text record
            for (i = 1, j = 0; i <= 6; i++, j++) {
                addr[j] = line[i];
            }
            addr[j] = '\0';  // Null-terminate the address string

            // Open a temporary file for writing and reading
            fp2 = fopen("temp.txt", "w+");
            if (fp2 == NULL) {
                printf("Error opening temp.txt\n");
                exit(1);
            }

            // Write the extracted address to the temp file
            fprintf(fp2, "%s", addr);
            rewind(fp2);  // Rewind to read back the value

            // Read the address back as a hexadecimal value
            fscanf(fp2, "%x", &hexaddr);
            fclose(fp2);  // Close the temporary file

            // Start processing the object code bytes
            i = 9;
            while (line[i] != '\0') {
                // Print the current address and the corresponding byte
                printf("%04x\t%c%c\n", hexaddr, line[i], line[i + 1]);
                
                // Increment the address and move to the next byte
                hexaddr += 1;
                i += 2;
            }
        }
    } while (!feof(fp1));

    // Close the record file
    fclose(fp1);
}


/*
THE OUTPUT OF THE ABOVE PROGRAM IS: 

1000    14
1001    20
1002    33
1003    48
1004    30
1005    39
1006    10
1007    20
1008    36
1009    42
100a    03
100b    34
100c    83
100d    03
100e    91
100f    02
1010    03
2000    29
2001    83
2002    00
2003    23
2004    00
2005    00
2006    28
2007    20
2008    30
2009    30
200a    20
200b    15
*/