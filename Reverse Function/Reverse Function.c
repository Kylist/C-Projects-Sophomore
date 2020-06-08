
#include <stdio.h>

int len(char a[] );
int lowertest(char a);
char uppercase(char c);
void reversestr(char a[]);
void finishit(char a[] );
main(){

printf("hello\n");
char test[5000000];
printf("Type the input string:\n");
gets(test);
printf("the input string:%s\n",test);
printf("Len:%d\n",len(test));
finishit(test);
}

int len(char a[]){
  int count=0;
  for(int i=0;a[i]!='\0';i++){
  count=count+1;
  }
return count;

}

int lowertest(char a){
if(a>='a'&&a<='z'){
    return 1;}
else{
   return 0;
}
}

char uppercase(char c){

if (lowertest(c)==1){
   char d=c-32;
   return d;

}
return c;
}

void reversestr(char a[]){


for(int i=len(a);i>=0;i--){


    char temp=a[i];
   a[i]=a[len(a)-i-1];
   a[len(a)-i-1]=temp;


}

}

void finishit(char a[] ){
printf("Enter String is: %s\n",a);
int count=0;

for(int i=0;i<len(a);i++){

    if (lowertest(a[i])==1){
    count=count+1;}
    a[i]=uppercase(a[i]);



}

printf("The string is %d chars and %d chars were cap\n",len(a),count);
printf("New String is: %s\n",a);

for(int i=len(a);i>=0;i--){
        printf("%c\n",a[i]);

}
}







