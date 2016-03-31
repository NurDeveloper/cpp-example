/* source.cpp
 ѕеревод из инфиксной записи в постфиксную (с ипользованием стека) */
#include <stdio.h>
#include <stack>
#include <string.h>
#define N 256

using namespace std;

//добавление символа x в массив символов str
void add(char* str, char x);

//ввод данных
void indata(char fname[20], char* infix)
{
 FILE *inf;
 char x; //хранит символ, прочитанный из файла
 
 inf=fopen(fname,"r");

 while (!feof(inf)){
  fscanf(inf,"%c",&x);
  add(infix,x);
 }

 fclose(inf);
 printf("Д†≠≠л• ѓаЃз®в†≠л б %s\n",fname);
 return;
}

//вывод данных
void outdata (char fname[20], char* postfix)
{
 FILE *outf;
 int i=0;

 outf=fopen(fname,"w");

 while (postfix[i]){
  fprintf(outf,"%c",postfix[i]);
 // fprintf(outf,"%c",' ');
  i++;
 }
 
 fclose(outf);
 printf("Д†≠≠л• ҐлҐ•§•≠л Ґ %s\n",fname);
 return;
}

//перевод из инфиксной записи в постфиксную
//infix - инфиксна€ запись
//postfix - постфиксна€ запись
void infTOpost(char* infix, char* postfix)
{
 stack<char> buf;
 int i=0;

 buf.push('(');
 add(infix,')');

 while (!buf.empty()){
	 if ((infix[i]>='0') && (infix[i]<='9')){
		 if ((infix[i+1]=='+') || (infix[i+1]=='-') || (infix[i+1]=='*') || (infix[i+1]=='/')){
			 add(postfix,infix[i]);
			 add(postfix,' ');
		 } 
		 else add(postfix,infix[i]);
	 }
	 else
		 if ((infix[i]=='+') || (infix[i]=='-')){
			 while ((buf.top()=='+') || (buf.top()=='-') || (buf.top()=='*') || (buf.top()=='/')){
				 add(postfix,buf.top());
				 buf.pop();
			 }
			 buf.push(infix[i]);
			 if (!((infix[i-1]>='0') && (infix[i-1]<='9')))
				 add(postfix,' ');
		 }
		 else
			 if ((infix[i]=='*') || (infix[i]=='/')){
				 while ((buf.top()=='*') || (buf.top()=='/')){
					 add(postfix,buf.top());
					 buf.pop();
				 }
				 buf.push(infix[i]);
				 if (!((infix[i-1]>='0') && (infix[i-1]<='9')))
					 add(postfix,' ');
			 }
			 else
				 if (infix[i]==')'){
					 while (buf.top()!='('){
						 add(postfix,' ');
						 add(postfix,buf.top());
						 buf.pop();
					 }
					 buf.pop();
				 }
				 else
					 if (infix[i]=='(')
						 buf.push('(');
	 i++;
 }

 return;}

void add(char* str, char x){
 int length;

 length=strlen(str); 
 str[length]=x;

 length++;
 str[length]='\0';
 return;
}

void main()
{
 char infix[N];
 char postfix[N];

 infix[0]='\0';
 postfix[0]='\0';

 indata("input.txt\0",infix);
 infTOpost(infix,postfix);
 outdata("output.txt\0",postfix);
 return;
}