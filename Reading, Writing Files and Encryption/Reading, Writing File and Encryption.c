#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <string.h>


char *read_file(int n,char location []);
int write_file(int n,char key[],char outfile[]);
void make_rand_key(int len, char location[]);
char *XORop(char a[],char b[]);
void decrypt(char key[],char cipher [] ,char message[]);
# define MAXLINE 1000;
FILE *file;
FILE *file2;
FILE *file3;
FILE *file4;
void encrypt(char clear[],char key [] ,char cipher[]);


int main(){
char clear[]="/Users/macbook/Desktop/Ccode/lab4/Clear.txt";
char key[]="/Users/macbook/Desktop/Ccode/lab4/Key.txt";
char cipher[]="/Users/macbook/Desktop/Ccode/lab4/Cipher.txt";
char mess[]="/Users/macbook/Desktop/Ccode/lab4/Mess.txt";
char *out=read_file(0,clear);
int n=strlen(out);
make_rand_key(n,key);
int c=0;
while(1){
    printf("Encrypt a file: 1\nDecrypt a file: 2\nExit: 3\nEnter a choice:");
    scanf("%d",&c);
if(c==1){
    encrypt(clear,key,cipher);}
else if(c==2){
    decrypt(key,cipher,mess);}
else if(c==3){

    break;
}

}
}






char *XORop(char a[],char b[]){
int n=strlen(a);
char *c=(char*)malloc(n+1);
for(int i=0;i<n;i++){
    c[i]=a[i]^b[i];
}
return c;
}



char *read_file(int n,char location []){
file = fopen(location,"r");
int count=0;
while(getc(file)!=EOF){

    count++;

}



char *str=(char*)malloc(count+1);

rewind(file);
if(n==0){
for(int i=0;i<count;i++){
    str[i]=getc(file);
}

}
else{
fgets(str,n+1,file);}





fclose(file);

return str;
free(str);
}

int write_file(int n,char info[],char outfile[]){
file2 = fopen(outfile,"w+");
fputs(info,file2);
fclose(file2);
return(0);
}

void make_rand_key(int len, char location[]){

    int i =0;

    char key[len+1];

    srand(time(NULL));

    for (i=0;i<len;i++){

        //int r=rand()%32767+1-0+0;

        //int temp=r/259;
        char temp = rand()%127;

        if (temp == EOF || temp == 0) temp=1;
        key[i]=temp;

    }
    key[i] = '\0';

    file3 = fopen(location,"w+");
    fputs(key,file3);
    fclose(file3);

}


void encrypt(char clear[],char key [] ,char cipher[]){
char *infile=read_file(0,clear);
char *keyfile=read_file(0,key);
char *ciphertext=XORop(infile,keyfile);
write_file(0,ciphertext,cipher);

free(infile);free(keyfile);free(ciphertext);

}

void decrypt(char key[],char cipher [] ,char message[]){
char *cipherfile=read_file(0,cipher);
char *keyfile=read_file(0,key);
char *mess=XORop(cipherfile,keyfile);
write_file(0,mess,message);
free(mess);free(keyfile);free(cipherfile);
}









