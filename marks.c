#include<stdio.h>

//Global Variables
struct student *head;
struct student *go=NULL;
char name[100];
char index[100];
char t_marks[100];
char p_marks[100];
int check=0;
int time=0;
int valid_choice;

struct student{
    char st_name[100];
    char st_index[100];
    char st_tmarks[100];
    char st_pmarks[100];
    struct student *next;
};
//To display All Student Details
void displayList(struct student *tmp){
        printf("Name\t\tIndex\t\tT_Marks\t\tP_Marks\n");
        while(!tmp->next==NULL){
            printf("\n%s\t\t%s\t\t%s\t\t%s", tmp->st_name,tmp->st_index,tmp->st_tmarks,tmp->st_pmarks);
            tmp=tmp->next;
        }
        printf("\n");
}

//To write new linked list to new file
void newList(struct student *tmp){
        check=0;
        FILE *file_write;
        file_write=fopen("marks.txt","a");
        if(!file_write){
            printf("File open error!!!");
			return 1;

        }else{
            while(!tmp->next==NULL){
                fprintf(file_write, "%s %s %s %s\n", tmp->st_name,tmp->st_index,tmp->st_tmarks,tmp->st_pmarks);
                tmp=tmp->next;
            }
            printf("\n");
        }
}

//To display one selected student details
void selectList(struct student *tmp,char index[100]){
        printf("Name\t\tIndex\t\tT_Marks\t\tP_Marks\n");
        while(!tmp->next==NULL){
            if(!strcmp(tmp->st_index,index)){
                printf("\n%s\t\t%s\t\t%s\t\t%s", tmp->st_name,tmp->st_index,tmp->st_tmarks,tmp->st_pmarks);
                check=1;

            }
            tmp=tmp->next;
        }
        printf("\n");
        if(check==0){
            printf("\nThere is the no index %s\n",index);
        }


}

//To Edit linkedlist
void editList(struct student *tmp,char index[100]){
    check=0;
    while(!tmp->next==NULL){
        if(!strcmp(tmp->st_index,index)){
            strncpy(tmp->st_name,name,100);
            strncpy(tmp->st_index,index,100);
            strncpy(tmp->st_tmarks,t_marks,100);
            strncpy(tmp->st_pmarks,p_marks,100);
            printf("\nEdit successfully........\n");
            break;
            }
         tmp=tmp->next;
    }
    printf("\n");
}

//To delete data
void deleteList(struct student *tmp,char index[100]){
        check=0;
        struct student *myhead=tmp;
        struct student *pretemp=NULL;
        while(!tmp->next==NULL){
            if(!strcmp(tmp->st_index,index)){
                pretemp->next=tmp->next;
                check=1;
                break;

            }
            pretemp=tmp;
            tmp=tmp->next;
        }
        if(check==1){
            tmp=myhead;
            printf("\n");
            FILE *file_write;
            file_write=fopen("marks.txt","w");
            if(!file_write){
                printf("File open error!!!");
                return 1;

            }else{
                while(!tmp->next==NULL){
                    fprintf(file_write, "%s %s %s %s\n", tmp->st_name,tmp->st_index,tmp->st_tmarks,tmp->st_pmarks);
                    tmp=tmp->next;
                }
                printf("\nSuccessfully Deleted......\n");
                fclose(file_write);
            }
        }else{
            printf("\nYou entered wrong index number....\n");
        }
        check=0;

}


//To store all deatils in the file to linklist
void linklist(){
    head=NULL;
    FILE *file;
    file=fopen("marks.txt","r");
    while(!feof(file)){
        //fscanf(file,"%s %s %d %d",name,index,&tmarks,&pmarks);
        if(head==NULL){
            head=(struct student*)malloc(sizeof(struct student));
            go=head;
            go->next=NULL;
        }else{
            go->next=(struct student*)malloc(sizeof(struct student));
            go=go->next;
            go->next=NULL;
        }
        fscanf(file,"%s %s %s %s",go->st_name,go->st_index,go->st_tmarks,go->st_pmarks);
    }

    //To Testing->To display the linkedlist
    /*go=head;
    printf("Name\t\tIndex\t\tT_Marks\t\tP_Marks\n");
    while(!go->next==NULL){
        printf("\n%s\t\t%s\t\t%s\t\t%s",go->st_index, go->st_name,go->st_tmarks,go->st_pmarks);
        go=go->next;
    }*/


}

//To insert data
void insertdata(){
        int int_tmarks,int_pmarks;
        printf("\nEnter your name\t\t:");
        scanf("%s",&name);
        printf("Enter your Index No\t:");
        scanf("%s",&index);
        //To insert correct Theory Marks
        while(1){
            printf("Enter your T_Marks\t:");
            scanf("%s",&t_marks);

            if(check_numeric(t_marks)){
                int int_tmarks=atoi(t_marks);
                if(int_tmarks<=100 && int_tmarks>=0){
                    break;
                }else{
                    printf("Please enter correct marks(0-100).......\n");
                }
            }else{
                printf("Please enter only numbers(0-100).......\n");
            }

        }

        //To insert correct Practical Marks
        while(1){
            printf("Enter your P_Marks\t:");
            scanf("%s",&p_marks);

             if(check_numeric(p_marks)){
                int int_pmarks=atoi(p_marks);
                if(int_pmarks<=100 && int_pmarks>=0){
                    break;
                }else{
                    printf("Please enter correct marks(0-100).......\n");
                }
            }else{
                printf("Please enter only numbers(0-100).......\n");
            }
        }
}

//To check if marks is digits
int check_numeric(char name[100]){
    int len=strlen(name);
    //printf("length=%d",len);
    for(int i=0;i<len;i++){
        if(!isdigit(name[i])){
            return 0;
        }
    }
    return 1;



}

int main(){

    while(1){
        char choices[10];
        printf("\n+----------------------------+\n");
        printf("|          MAIN MENU         |\n");
        printf("+----------------------------+\n");
        printf("| 1. Insert a Record         |\n");
        printf("| 2. Display a record        |\n");
        printf("| 3. Display all Records     |\n");
        printf("| 4. Edit a record           |\n");
        printf("| 5. Delete a Record         |\n");
        printf("| 6. Exit                    |\n");
        printf("+----------------------------+\n");
        printf("Enter your choice(1/2/3/4/5/6): ");
            scanf("%s", choices);

            // Check if the input is a valid choice (1, 2, 3, 4, 5, 6)
            if(strcmp(choices, "1") && strcmp(choices, "2") && strcmp(choices, "3") &&
               strcmp(choices, "4") && strcmp(choices, "5") && strcmp(choices, "6")){
                printf("Please enter correct number(1/2/3/4/5/6)...\n");
            } else {
                valid_choice = 1; // Set flag to exit loop
            }

            // Clear input buffer
            while(getchar() != '\n');

        //To insert a record
        if(!strcmp(choices,"1")){
            insertdata();
            FILE *file_write;
            file_write=fopen("marks.txt","a");
            if(!file_write){
                printf("File open error!!!");
                return 1;

            }else{
                fprintf(file_write, "%s %s %s %s\n",name,index,t_marks,p_marks);
                fclose(file_write);
                printf("\nInsert record successfully....\n");
            }
            linklist();

        }

        //To display selected student details
        if(!strcmp(choices,"2")){
            char selectindex[100];
            printf("Enter index do you want:");
            scanf("%s",selectindex);
            if(time==0){
                linklist();
            }
            time=1;
            selectList(head,selectindex);
        }

        //To Display all student details
        if(!strcmp(choices,"3")){

            //Display all details in linklist
            if(time==0){
                linklist();
            }
            time=1;
            displayList(head);

        }
        if(!strcmp(choices,"4")){
            char editindex[100];
            printf("Enter index do you want edit:");
            scanf("%s",editindex);

            if(time==0){
                linklist();
            }
            selectList(head,editindex);
            if(check==1){
                printf("\n\nEnter new values to this index...\n\n");
                insertdata();

                editList(head,editindex);
                newList(head);
            }else{
                printf("\nPlease enter correct index number...\n");
            }
            time=1;
            check=0;


        }
        if(!strcmp(choices,"5")){
            char deleteindex[100];
            printf("Enter index do you want delete:");
            scanf("%s",deleteindex);

            if(time==0){
                linklist();
            }
            deleteList(head,deleteindex);
            time=1;

        }
        if(!strcmp(choices,"6")){
            printf("\nGood Bye........\n");
            return 1;
        }
    }


    return 0;

}



