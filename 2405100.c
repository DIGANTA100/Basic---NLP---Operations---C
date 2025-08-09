#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>



#define MAX_DOCS 50
#define MAX_LEN 5000
#define MAX_TOKENS 500
#define MAX_TOKEN_LEN 50




char documents[MAX_DOCS][MAX_LEN];
char tokens[MAX_TOKENS][MAX_TOKEN_LEN];
char tokens_except_stop_words[MAX_TOKENS][MAX_TOKEN_LEN];
char stemmed_tokens[MAX_TOKENS][MAX_TOKEN_LEN];

#define NUM_STOP_WORDS 8
char stop_words[NUM_STOP_WORDS][MAX_TOKEN_LEN]={"the", "is", "a", "an", "and" ,"in" , "of", "to"};


int id=-1;
int d;
int tokencount=0;


void help(){

printf("set         - Prompt for the number of documents and their text.\n");
printf("preprocess  -Normalization: Convert all documents to lowercase and display them.\n             Tokenization: Tokenize all documents into words and display the tokens.\n             Stop-words Removal: Remove stop words from tokens and display the filtered tokens.\n             Stemming: Apply simple stemming (remove suffixes like “ing”, “ed”, “s”) and display results.\n");
printf("tf          - Compute and display Term Frequency for a specified word across documents.\n");
printf("idf         - Compute and display Inverse Document Frequency for a specified word.\n");
printf("tfidf       - Compute and display TF-IDF scores for a specified word across documents.\n");
printf("stat        - Display TF, IDF, and TF-IDF for all tokens across all documents in a matrix format.\n");
printf("help        - Print the list of all available commands.\n");
printf("exit        - Exit the program.\n");

}

void set(){
int i;
printf("Enter number of documents (1-50): ");
scanf("%d",&d);
getchar();
if(d<1 || d>50){printf("Invalid number of documents. Must be from 1 to 50.\n");
return ;
}
printf("\n");
for(i=0;i<d;i++){
 printf("Enter document %d: ",i+1);
 fgets(documents[i],MAX_LEN,stdin);
 if(strchr(documents[i],'\n')==NULL){
   printf("Document too long.\n");
   return;

 }


}


printf("Documents set successfully. Please, enter 'preprocess' command now. It will not take other commands.");
printf("\n");
id=1;


/*void normalize_case_all();
 normalize_case_all();
void tokenize_all();
 tokenize_all();

 */


}

void normalize_case_all(){
 if(id==-1) {

    printf("\nNo documents set. Use 'set' command first.");
    return ;
 }


int i,j;
printf("\nNormalized Documents:");
printf("\n");
for(i=0;i<d;i++)
{
        for(j=0;j<strlen(documents[i]);j++)
        documents[i][j]=tolower(documents[i][j]);
printf("Document %d: %s",i+1,documents[i]);
}



}



void sorttok(){

    int i,j;
    for (i = 0;i<tokencount-1;i++) {
for (j=i + 1; j<tokencount;j++) {
    if (strcmp(tokens[i],tokens[j]) > 0) {
                char temp[MAX_TOKEN_LEN];
        strcpy(temp, tokens[i]);
                strcpy(tokens[i], tokens[j]);
        strcpy(tokens[j], temp);
        }
    }
}
}

void remdupli(){

    int i,j,k;
    for ( i = 0; i < tokencount; i++) {
        for (j = i + 1; j < tokencount; j++) {
if (strcmp(tokens[i], tokens[j]) == 0) {

        for ( k = j; k < tokencount - 1; k++) {
            strcpy(tokens[k], tokens[k + 1]);
                }
        tokencount--;
        j--;
    }
}
    }
}




void tokenize_all(){
    if(id==-1) {

    printf("\nNo documents set. Use 'set' command first.");
    return ;
 }



tokencount=0;
int i;
for(i=0;i<MAX_TOKENS;i++)
    tokens[i][0]='\0';


for(i=0;i<d;i++){
int j = 0, k = 0;
while (documents[i][j] != '\0') {
    if (isalnum(documents[i][j])) {

        if (k < MAX_TOKEN_LEN - 1) {
            tokens[tokencount][k++] = documents[i][j];
        }
        else {
                printf("\nToken is too high");
        return ;

        }
    } else {
        if (k > 0) {

            tokens[tokencount][k] = '\0';
            tokencount++;
            k = 0;
            if (tokencount >= MAX_TOKENS) return;
        }
    }
    j++;
}


if (k > 0 && tokencount < MAX_TOKENS) {
    tokens[tokencount][k] = '\0';
    tokencount++;
}

    }
    printf("Tokens:\n");

for(i=0;i<tokencount;i++) printf("%d. %s\n",i+1,tokens[i]);
printf("Tokenization complete. Total tokens: %d",tokencount);

}


void remove_stop_words_all(){
int i,j;
int c=tokencount;

char tokenwithoutstop[tokencount][MAX_TOKEN_LEN];

for(i=0;i<c;i++) tokenwithoutstop[i][0]='\0';

int k=0;
for(i=0;i<c;i++) {
    int flag=0;
    for(j=0;j<NUM_STOP_WORDS;j++) {
        if(strcmp(tokens[i],stop_words[j])==0){
            tokencount--;
           flag=1;
            break;
        }



    }
 if(flag==0){

   strcpy(tokenwithoutstop[k++],tokens[i]);

 }


}

for(i=0;i<tokencount;i++) strcpy(tokens[i],tokenwithoutstop[i]);

printf("\nTokens after stop-words removal:\n");
    for (i = 0; i < tokencount; i++) {
        printf("%d. %s\n", i + 1, tokens[i]);
    }
    printf("Stop-words removal complete. Tokens remaining: %d\n", tokencount);



}


void stem_all_tokens(){
int i;

for(i=0;i<tokencount;i++){
    int l=strlen(tokens[i]);

    if(l>3){
        char *p=&tokens[i][l-3];
        if(strcmp(p,"ing")==0)
tokens[i][l-3]='\0';

    }


    if(l>2){
        char *p=&tokens[i][l-2];
        if(strcmp(p,"ed")==0)
tokens[i][l-2]='\0';

    }


    if(l>1){
        char *p=&tokens[i][l-1];
        if(strcmp(p,"s")==0)
tokens[i][l-1]='\0';

    }


}

 printf("\nStemmed Tokens:\n");
    for (i = 0; i < tokencount; i++) {
        printf("%d. %s\n", i + 1, tokens[i]);
    }
    printf("Stemming complete. Total stemmed tokens: %d\n",tokencount);





}


void preprocess(){
if(id==-1) {

    printf("No documents set. Use 'set' command first.\n");
    return ;
 }


normalize_case_all();
tokenize_all();
remove_stop_words_all();
stem_all_tokens();
remdupli();
sorttok();



}

double compute_tf(char word[], int doc_id){
    int count =0;
if(id==-1) {

    printf("No documents set. Use 'set' command first.\n");
    return 0 ;
 }

int i,j;

for(i=0;i<strlen(documents[doc_id]);i++){
    documents[doc_id][i]=tolower(documents[doc_id][i]);


}
char token[MAX_TOKENS][MAX_TOKEN_LEN];
for(i=0;i<MAX_TOKENS;i++) token[i][0]='\0';

int tkncnt=0;
j=0; int k=0;

while (documents[doc_id][j] != '\0'){
 if (isalnum(documents[doc_id][j])){
   if (k < MAX_TOKEN_LEN - 1) {
            token[tkncnt][k++] = documents[doc_id][j];
        }

else {
printf("\nToken is too high");

}




 }

 else {
        if (k > 0) {

            token[tkncnt][k] = '\0';
            tkncnt++;
            k = 0;
            if (tkncnt >= MAX_TOKENS) return 0.0;
        }
    }
    j++;






}


if (k > 0 && tkncnt < MAX_TOKENS) {
    token[tkncnt][k] = '\0';
    tkncnt++;
}


int c=tkncnt;
 char tokenwithoutstop[tkncnt][MAX_TOKEN_LEN];

 for(i=0;i<c;i++) tokenwithoutstop[i][0]='\0';

  k=0;
for(i=0;i<c;i++) {
    int flag=0;
    for(j=0;j<NUM_STOP_WORDS;j++) {
        if(strcmp(token[i],stop_words[j])==0){
            tkncnt--;
           flag=1;
            break;
        }



    }
 if(flag==0){

   strcpy(tokenwithoutstop[k++],token[i]);

 }


}
for(i=0;i<tkncnt;i++) strcpy(token[i],tokenwithoutstop[i]);


for(i=0;i<tkncnt;i++){
    int l=strlen(token[i]);

    if(l>3){
        char *p=&token[i][l-3];
        if(strcmp(p,"ing")==0)
token[i][l-3]='\0';

    }


    if(l>2){
        char *p=&token[i][l-2];
        if(strcmp(p,"ed")==0)
token[i][l-2]='\0';

    }


    if(l>1){
        char *p=&token[i][l-1];
        if(strcmp(p,"s")==0)
token[i][l-1]='\0';

    }
if(strcmp(word,token[i])==0) count++;

}

 if(tkncnt==0) return 0.0;

 return (double) count/tkncnt;






}

void TF(){
if(id==-1) {

    printf("\nNo documents set. Use 'set' command first.");
    return ;
 }
char word[MAX_TOKEN_LEN];
printf("Enter word to compute TF: ");
gets(word);

char *p;

int l=strlen(word);

    if(l>3){
        char *p=&word[l-3];
        if(strcmp(p,"ing")==0)
word[l-3]='\0';

    }


    if(l>2){
        char *p=&word[l-2];
        if(strcmp(p,"ed")==0)
word[l-2]='\0';

    }


    if(l>1){
        char *p=&word[l-1];
        if(strcmp(p,"s")==0)
word[l-1]='\0';

    }


int i;
for(i=0;i<d;i++){
    double ttff=compute_tf(word,i);

 if (ttff >= 0)
            printf("Document %d: %.4lf\n", i + 1, ttff);




}

}


double compute_idf(char word[]){
if(id==-1) {

    printf("No documents set. Use 'set' command first.\n");
    return 0.0 ;
 }

//printf("Enter word to compute IDF: ");

/*char *p;

int l=strlen(word);

    if(l>3){
        char *p=&word[l-3];
        if(strcmp(p,"ing")==0)
word[l-3]='\0';

    }


    if(l>2){
        char *p=&word[l-2];
        if(strcmp(p,"ed")==0)
word[l-2]='\0';

    }


    if(l>1){
        char *p=&word[l-1];
        if(strcmp(p,"s")==0)
word[l-1]='\0';

    } */



int i,j;
 int count =0;
for(i=0;i<d;i++){
       char doccpy[MAX_LEN];
       strcpy(doccpy,documents[i]);
for(j=0;j<strlen(doccpy);j++){
    doccpy[j]=tolower(doccpy[j]);


}

char token[MAX_TOKENS][MAX_TOKEN_LEN];
for(j=0;j<MAX_TOKENS;j++) token[j][0]='\0';

int tkncnt=0;
j=0; int k=0;

while (doccpy[j] != '\0'){
 if (isalnum(doccpy[j])){
   if (k < MAX_TOKEN_LEN - 1) {
            token[tkncnt][k++] = doccpy[j];
        }

else {
printf("\nToken is too high");

}




 }

 else {
        if (k > 0) {

            token[tkncnt][k] = '\0';
            tkncnt++;
            k = 0;
            if (tkncnt >= MAX_TOKENS) return 0.0;
        }
    }
    j++;






}


if (k > 0 && tkncnt < MAX_TOKENS) {
    token[tkncnt][k] = '\0';
    tkncnt++;
}


int c=tkncnt;
 char tokenwithoutstop[tkncnt][MAX_TOKEN_LEN];

 for(j=0;j<c;j++) tokenwithoutstop[j][0]='\0';

  k=0; int m;
for(j=0;j<c;j++) {
    int flag=0;
    for(m=0;m<NUM_STOP_WORDS;m++) {
        if(strcmp(token[j],stop_words[m])==0){
            tkncnt--;
           flag=1;
            break;
        }



    }
 if(flag==0){

   strcpy(tokenwithoutstop[k++],token[j]);

 }


}
for(j=0;j<tkncnt;j++) strcpy(token[j],tokenwithoutstop[j]);


for(j=0;j<tkncnt;j++){
    int l=strlen(token[j]);

    if(l>3){
        char *p=&token[j][l-3];
        if(strcmp(p,"ing")==0)
token[j][l-3]='\0';

    }


    if(l>2){
        char *p=&token[j][l-2];
        if(strcmp(p,"ed")==0)
token[j][l-2]='\0';

    }


    if(l>1){
        char *p=&token[j][l-1];
        if(strcmp(p,"s")==0)
token[j][l-1]='\0';

    }
if(strcmp(word,token[j])==0){ count++;

break;
}

}







}

return log10((double)MAX_DOCS / (1.0 + count));

}



void IDF(){
    if(id==-1) {

    printf("No documents set. Use 'set' command first.\n");
    return ;
 }
 char word[MAX_TOKEN_LEN];

printf("Enter word to compute IDF: ");


char *p;

int l=strlen(word);

    if(l>3){
        char *p=&word[l-3];
        if(strcmp(p,"ing")==0)
word[l-3]='\0';

    }


    if(l>2){
        char *p=&word[l-2];
        if(strcmp(p,"ed")==0)
word[l-2]='\0';

    }


    if(l>1){
        char *p=&word[l-1];
        if(strcmp(p,"s")==0)
word[l-1]='\0';

    }

 fgets(word, MAX_TOKEN_LEN, stdin);
    word[strcspn(word, "\n")] = '\0';

    double idfval= compute_idf(word);
    printf("IDF for '%s': %.4lf\n", word, idfval);






}


 void compute_tfidf_all(char word[]){

 if (id == -1) {
        printf("No documents set. Use 'set' command first.\n");
        return;
    }


 double idfvalue = compute_idf(word);

    for (int i = 0; i < d; i++) {
        double tf = compute_tf(word, i);
        double tf_idf = tf * idfvalue;
        printf("Document %d: %.4lf\n", i + 1, tf_idf);
    }






}

void TFIDF(){
 if (id == -1) {
        printf("No documents set. Use 'set' command first.\n");
        return;
    }

char word[MAX_TOKEN_LEN];

    printf("Enter word to compute TF-IDF: ");

    fgets(word, MAX_TOKEN_LEN, stdin);
    word[strcspn(word, "\n")] = '\0';



char *p;

int l=strlen(word);

    if(l>3){
        char *p=&word[l-3];
        if(strcmp(p,"ing")==0)
word[l-3]='\0';

    }


    if(l>2){
        char *p=&word[l-2];
        if(strcmp(p,"ed")==0)
word[l-2]='\0';

    }


    if(l>1){
        char *p=&word[l-1];
        if(strcmp(p,"s")==0)
word[l-1]='\0';

    }

    compute_tfidf_all(word);




}

void display_stat() {
    if (id == -1) {
        printf("No documents set. Use 'set' command first.\n");
        return;
    }

    double tf[MAX_TOKENS][MAX_DOCS];
    double idf[MAX_TOKENS];
    double tfidf[MAX_TOKENS][MAX_DOCS];


    for (int i = 0; i < tokencount; i++) {
        char word[MAX_TOKEN_LEN];
        strcpy(word, tokens[i]);

        idf[i] = compute_idf(word);

        for (int j = 0; j < d; j++) {
            tf[i][j] = compute_tf(word, j);
            tfidf[i][j] = tf[i][j] * idf[i];
        }
    }

    printf("\n================ TF ==================\n");
    printf("%-30s", "");
    for (int j = 0; j < d; j++) {
        printf("doc%-10d", j + 1);
    }
    printf("\n");

    for (int i = 0; i < tokencount; i++) {
        printf("%-30s", tokens[i]);
        for (int j = 0; j < d; j++) {
            printf("%-12.4lf", tf[i][j]);
        }
        printf("\n");
    }

    printf("\n================= IDF ==================\n");
    printf("%-30s%-10s\n", "", "IDF");
    for (int i = 0; i < tokencount; i++) {
        printf("%-30s%-10.4lf\n", tokens[i], idf[i]);
    }

    printf("\n=============== TF-IDF ================\n");
    printf("%-30s", "");
    for (int j = 0; j < d; j++) {
        printf("doc%-10d", j + 1);
    }
    printf("\n");

    for (int i = 0; i < tokencount; i++) {
        printf("%-30s", tokens[i]);
        for (int j = 0; j < d; j++) {
            printf("%-12.4lf", tfidf[i][j]);
        }
        printf("\n");
    }
}








int main(){
for (int i=0; i<MAX_DOCS;i++) documents[i][0]='\0';
printf("Welcome to the Document Processing System!");
printf("\n");
help();
printf("\n");
char command[100];
while(1){
printf("\nEnter command: ");
fgets(command,100,stdin);
command[strcspn(command, "\n")] = '\0';
if(strcmp(command,"set")==0)
    set();

else if(strcmp(command,"preprocess")==0)
 preprocess();

 else if(strcmp(command,"tf")==0)
TF();

else if(strcmp(command,"idf")==0)
IDF();

else if(strcmp(command,"tfidf")==0)
TFIDF();

else if(strcmp(command,"stat")==0)
display_stat();

else if(strcmp(command,"help")==0)
help();


else if(strcmp(command,"exit")==0)
break;

else printf("Unknown command. Type 'help' for list of commands.");




}

printf("Exiting program. I really had a great time . Goodbye !!!!!");


}



