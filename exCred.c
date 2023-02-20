#include <stdio.h>
#include <stdlib.h>

char dep1[6];
char dep2[6];
char dep3[6];
char dep4[6];
char dep5[6];

char prog1[5];
char prog2[5];
char prog3[5];
char prog4[5];
char prog5[5];
char *programmers[] = {prog1, prog2, prog3, prog4, prog5};

char lastVal(char target,char o1, char o2, char o3, char o4){
    char vals[]={'1','2','3','4','5'};
    int i = 0;
    for (i=0; i<5; i++) {
        if ((o1!=vals[i])&&(o2!=vals[i])&&(o3!=vals[i])&&(o3!=vals[i]))
        {
            target = vals[i];
        }
    }
    return target;
}

char next = '0';
char assignProg(char curDep[], char odep1[], char odep2[], char odep3[], char odep4[], char dep1p, char dep2p, char dep3p, char dep4p) {
    int i;
    int j;
    int k;
    char program;
    for(i=0; i<5; i++) {
        next = '0';
        char index[1] = {curDep[i]};
        if ((curDep[i]==dep1p)||(curDep[i]==dep2p)||(curDep[i]==dep3p)||(curDep[i]==dep4p)) {
            continue;
        }
        for(j=0; j<i+1; j++) {
            if (curDep[i]==odep1[j]) {
                for(k=0; k<5; k++){
                    if(programmers[atoi(index)-1][k]==curDep[5])
                    {
                        program = curDep[i];
                        break;
                    }
                    else if (programmers[atoi(index)-1][k]==odep1[5])
                    {
                        program = 'x';
                        i++;
                        break;
                    }
                }
            }
        
            else if (curDep[i]==odep2[j]) {
                for(k=0; k<5; k++){
                    if(programmers[atoi(index)-1][k]==curDep[5])
                    {
                        program = curDep[i];
                        break;
                    }
                    else if (programmers[atoi(index)-1][k]==odep2[5])
                    {
                        program = 'x';
                        i++;
                        break;
                    }
                }
            }
        
            else if (curDep[i]==odep3[j]) {
                for(k=0; k<5; k++){
                    if(programmers[atoi(index)-1][k]==curDep[5])
                    {
                        program = curDep[i];
                        break;
                    }
                    else if (programmers[atoi(index)-1][k]==odep3[5])
                    {
                        program = 'x';
                        i++;
                        break;
                    }
                }
            }
        
            else if (curDep[i]==odep4[j]) {
                for(k=0; k<5; k++){
                    if(programmers[atoi(index)-1][k]==curDep[5])
                    {
                        program = curDep[i];
                        break;
                    }
                    else if (programmers[atoi(index)-1][k]==odep4[5])
                    {
                        program = 'x';
                        i++;
                        break;
                    }
                }
            }

            else {
                char exit = 'y';
                for(k=0; k<i+1;k++){
                    if ((curDep[i]==odep1[k])||(curDep[i]==odep2[k])||(curDep[i]==odep3[k])||(curDep[i]==odep4[k])){
                        exit = 'n';
                    }
                }
                if (exit == 'y'){
                    program = curDep[i];
                    return program;
                }
            }
        }
        return program;
    }
    return program;
}

int main() {
    FILE *fp;
    fp = fopen("input.txt", "r");

    //create arrays for departments and programmers
    int i;
    for(i = 0; i < 5; i++) 
    {
        dep1[i] = fgetc(fp);
        fgetc(fp);
        dep2[i] = fgetc(fp);
        fgetc(fp);
        dep3[i] = fgetc(fp);
        fgetc(fp);
        dep4[i] = fgetc(fp);
        fgetc(fp);
        dep5[i] = fgetc(fp);
        fgetc(fp);
    }
    dep1[5] = '1';
    dep2[5] = '2';
    dep3[5] = '3';
    dep4[5] = '4';
    dep5[5] = '5';
    for(i = 0; i < 5; i++) 
    {
        prog1[i] = fgetc(fp);
        fgetc(fp);
        prog2[i] = fgetc(fp);
        fgetc(fp);
        prog3[i] = fgetc(fp);
        fgetc(fp);
        prog4[i] = fgetc(fp);
        fgetc(fp);
        prog5[i] = fgetc(fp);
        fgetc(fp);
    }
    
    char dep1prog = 'x';
    char dep2prog = 'x';
    char dep3prog = 'x';
    char dep4prog = 'x';
    char dep5prog = 'x';

    dep1prog = assignProg(dep1, dep2, dep3, dep4, dep5, dep2prog, dep3prog,dep4prog, dep5prog);
    dep2prog = assignProg(dep2, dep1, dep3, dep4, dep5, dep1prog, dep3prog,dep4prog, dep5prog);
    dep3prog = assignProg(dep3, dep2, dep1, dep4, dep5, dep2prog, dep1prog,dep4prog, dep5prog);
    dep4prog = assignProg(dep4, dep2, dep3, dep1, dep5, dep2prog, dep3prog,dep1prog, dep5prog);
    dep5prog = assignProg(dep5, dep2, dep3, dep4, dep1, dep2prog, dep3prog,dep4prog, dep1prog);

    if (dep1prog == 'x') {
        dep1prog = lastVal(dep1prog, dep2prog, dep3prog, dep4prog, dep5prog);
    }
    if (dep2prog == 'x') {
        dep2prog = lastVal(dep2prog, dep1prog, dep3prog, dep4prog, dep5prog);
    }
    if (dep3prog == 'x') {
        dep3prog = lastVal(dep3prog, dep2prog, dep1prog, dep4prog, dep5prog);
    }
    if (dep4prog == 'x') {
        dep4prog = lastVal(dep4prog, dep2prog, dep3prog, dep1prog, dep5prog);
    }
    if (dep5prog == 'x') {
        dep5prog = lastVal(dep5prog, dep2prog, dep3prog, dep4prog, dep1prog);
    }

    printf("Department 1 will get Programmer%c\n", dep1prog);
    printf("Department 2 will get Programmer%c\n", dep2prog);
    printf("Department 3 will get Programmer%c\n", dep3prog);
    printf("Department 4 will get Programmer%c\n", dep4prog);
    printf("Department 5 will get Programmer%c\n", dep5prog);

    return 0;
}