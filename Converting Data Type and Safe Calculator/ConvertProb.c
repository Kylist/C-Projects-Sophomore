/*

    Number converter

    Menu
    Convert between integer, binary, octal and hexadecimal

    This program should accept numeric values in hexadecimal,
    decimal, octal and binary formats as:

        Hex 0x0 to 0xFFFFFFFF
        Dec 0 to 4294967295
        Oct o0 to o37777777777
        Bin b0 to b11111111111111111111111111111111

    After a value is input the code in main will interpret the
    data types above an process the conversion to an unsigned
    int.  The unsigned int will be used to convert the input to
    strings containing hexadecimal, octal and binary strings.

*/



//int input_to_decimal(char *input);
#include <stdio.h>
#include <string.h>
#include <math.h>
unsigned int bin_to_uint(char *input);
unsigned int oct_to_uint(char *input);
unsigned int hex_to_uint(char *input);
unsigned int dec_to_uint(char *input);
void uint_to_hex(unsigned int n, char *output);
void uint_to_oct(unsigned int n, char *output);
void uint_to_bin(unsigned int n, char *output);


int error = 0;


int main(){

    char input[50];
    unsigned int n = 0;
    char output[50];

    // Write code here to test your functions
    // Uncomment code below when done

   printf("Enter a binary, octal, decimal or hexadecimal number\n");
    printf("convert > ");
    gets(input);

    // Detect input data type
    // Hexadecimal
    if(input[0] == '0' && input[1] == 'x'){
        n = hex_to_uint(input);
    }
    // Decimal
    else if(input[0] >= '0' && input[0] <= '9'){
        n = dec_to_uint(input);
    }
    // Octal
    else if(input[0] == 'o'){
        n = oct_to_uint(input);
    }
    // Binary
    else if(input[0] == 'b'){
        n = bin_to_uint(input);
    }

    // Unknown

    else{

        printf("ERROR: Unknown data type: %s\n", input);

    }



    // Print results

    printf("The decimal value of %s is %u\n", input, n);

    uint_to_hex(n, output);

    printf("The hexadecimal value of %s is %s\n", input, output);

    uint_to_oct(n, output);
    printf("The octal value of %s is %s\n", input, output);

    uint_to_bin(n, output);
    printf("The binary value of %s is %s\n", input, output);



    return 0;
}



// Convert a hexadecimal char array to uint
unsigned int hex_to_uint(char *input){

   unsigned int res = 0;



    unsigned iterator;

int len=strlen(input);
unsigned mul=0;
for(int i=len-1;i>0;i--){



if('0'<=input[i] && input[i]<='9'){

      int c=input[i]-48;

int power=pow(16,mul);
      res=res+c*power;}

if('A'<=input[i] && input[i]<='E'){

      int c=input[i]-55;
printf("c is %d",c);
       int power=pow(16,mul);
      res=res+c*power;

}







mul++;
}
    return res;
}

unsigned int dec_to_uint(char *input){
unsigned int res = 0;





int len=strlen(input);
unsigned mul=0;
for(int i=len-1;i>=0;i--){



if('0'<=input[i] && input[i]<='9'){

      int c=input[i]-48;

int power=pow(10,mul);
      res=res+c*power;}




mul++;

}
return res;
}

// Convert a octal char array to uint
unsigned int oct_to_uint(char *input){
   unsigned int res = 0;



    unsigned iterator;

int len=strlen(input);
unsigned mul=0;
for(int i=len-1;i>0;i--){



if('0'<=input[i] && input[i]<='7'){

      int c=input[i]-48;

       int power=pow(8,mul);
      res=res+c*power;


      }








mul++;
}
    return res;
}


/*
    Copy oct_to_uint() and modify for binary input.
*/
// Convert a binary char array to unsigned int
unsigned int bin_to_uint(char *input){
    unsigned int res = 0;



    unsigned iterator;

int len=strlen(input);
unsigned mul=0;
for(int i=len-1;i>0;i--){



if('0'==input[i]){



      res=res+1;
}

if('1'==input[i]){
int power=pow(2,mul);
res=res+power;
}








mul++;
}
    return res;
}




void uint_to_hex(unsigned int n, char *output){

    // Declare a uint for remainder

unsigned remain;

    // Declare an int for division

int div=1;
    int i=0;

    // Declare a char array buffer

    char res[20];

printf("n is %d\n",n);

    while(div>0){
       if(0<=n&&n<=15){
        if(0<=n&&n<=9){
            char c=n+48;
            res[i]=c; res[i+1]='\0';i++;break;

        }
        if(10<=remain&&remain<=15){
            char c=n+55;
            res[i]=c;res[i+1]='\0';i++;break;

       }



       }


     else{
        div=n/16;
        remain=n%16;
        if(0<=remain&&remain<=9){
            char c=remain+48;
            res[i]=c;

        }
        if(10<=remain&&remain<=15){
            char c=remain+55;
            res[i]=c;

        }
        i++;
        n=div;

    }

    }

output[0]='0';output[1]='x';

    for(int a=0;a<i;a++){
      output[a+2]=res[i-1-a];


    }
    output[i+2]='\0';

printf("hex is %s\n",output);




    return;

}






// Convert a unsigned integer char array to octal
void uint_to_oct(unsigned int n, char *output){

    unsigned remain;

    // Declare an int for division

int div=1;
    int i=0;

    // Declare a char array buffer

    char res[20];

printf("n is %d\n",n);

    while(div>0){
       if(0<=n&&n<=7){

            char c=n+48;
            res[i]=c;res[i+1]='\0';i++;break;





       }


     else{
        div=n/8;
        remain=n%8;
        if(0<=remain&&remain<=7){
            char c=remain+48;
            res[i]=c;

        }


        i++;
        n=div;

    }}



output[0]='o';

    for(int a=0;a<i;a++){
      output[a+1]=res[i-1-a];


    }
    output[i+1]='\0';

printf("oct is %s\n",output);




    return;

}




/*
    Copy uint_to_oct() and modify for binary
*/
// Convert a unsigned integer char array to binary
void uint_to_bin(unsigned int n, char *output){


    unsigned remain;

    // Declare an int for division

int div=1;
    int i=0;

    // Declare a char array buffer

    char res[20];

printf("n is %d\n",n);

    while(div>0){
       if(0<=n&&n<=1){

            char c=n+48;
            res[i]=c;res[i+1]='\0';i++;break;





       }


     else{
        div=n/2;
        remain=n%2;
        if(0<=remain&&remain<=2){
            char c=remain+48;
            res[i]=c;

        }


        i++;
        n=div;

    }}



output[0]='b';

    for(int a=0;a<i;a++){
      output[a+1]=res[i-1-a];


    }

    output[i+1]='\0';



return;

}



