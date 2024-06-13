#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct PHONEBOOK{
    int id;
    char name[20];
    char phonenum[20];
    char note[20];
    struct PHONEBOOK *next;
} PHONE;
PHONE *head = NULL;
int count=0;
const char *filename = "phonebook2.txt";
void menu(){
    printf("*****************电话簿管理系统************************\n");
    printf("*                1. 添加联系人                        *\n");
    printf("*                2. 删除联系人                        *\n");
    printf("*                3. 查找联系人                        *\n");
    printf("*                4. 修改联系人信息                    *\n");
    printf("*                5. 排序联系人                        *\n");
    printf("*                6. 显示所有联系人                    *\n");
    printf("*                0. 退出                              *\n");
    printf("*                请输入您的选择：                     *\n");
    printf("*******************************************************\n");
}
void savefile(){
    FILE *file = fopen(filename, "w");
    if (!file){
        printf("无法打开文件\n");
        return;
    }
    PHONE *cur = head;
    while (cur){
        fprintf(file, "%d,%s,%s,%s\n", cur->id, cur->name, cur->phonenum, cur->note);
        cur = cur->next;
    }
    fclose(file);
    printf("数据已保存在文件\n");
}

void loadfile(){
    FILE *file=fopen(filename,"r");
    if(!file){
        file=fopen(filename,"w");
        if(!file){
            printf("无法创建文件\n");
            return;
        }
        fclose(file);
        printf("文件创建成功\n");
        return ;
    }
    char line[500];
    while(fgets(line,sizeof(line),file)){
        PHONE *newnode=(PHONE*)malloc(sizeof(PHONE));
        if(!newnode){
            printf("内存分配失败\n");
            fclose(file);
            return ;
        }
        
        sscanf(line,"%d,%49[^,],%19[^,],%99[^\n]",&newnode->id,newnode->name,newnode->phonenum,newnode->note);
        newnode->next=NULL;
        if(!head){
            head=newnode;
        }
        else{
            PHONE *cur=head;
            while(cur->next){
                cur=cur->next;
            }
            cur->next=newnode;
        }
        count++;
    }   
    fclose(file);
    printf("数据已加载\n");
}

void add(){
    PHONE *newnode=(PHONE*)malloc(sizeof(PHONE));
    if(!newnode){
        printf("内存分配失败\n");
        return ;
    }
    newnode->id=count+1;
    newnode->next=NULL;
    printf("请输入姓名：");
    scanf("%s",newnode->name);
    printf("请输入电话号码：");
    scanf("%s",newnode->phonenum);
    printf("请输入备注：");
    scanf("%s",newnode->note);
    if(!head){               //如果头节点指向NULL  head=NULL，即链表为空(！NULL)
        head=newnode;      //直接插在头节点后面
    }
    else{
        PHONE *cur=head;
        while(cur->next){
            cur=cur->next;
        }
        cur->next=newnode;
    }
    count++;
    savefile();
}

void del(){
    int id;
    printf("请输入要删除的联系人的序号：");
    scanf("%d",&id);
    if(id<1||id>count){
        printf("序号无效\n");
        return;
    }
    PHONE *cur=head;
    PHONE *pre=NULL;
    while(cur&&cur->id!=id){
        pre=cur;
        cur=cur->next;
    }
    if(!cur){
        printf("未找到联系人\n");
    }
    if (!pre) {                  // 删除的是头节点
        head=cur->next;
    } else {
        pre->next=cur->next;
    }
    free(cur);
    count--;
    cur=head;
    int index=1;
    while(cur){
        cur->id=index++;
        cur=cur->next;
    }
    printf("删除成功\n");
    savefile();
}

void find(){
    char name[50];
    printf("请输入要查找的联系人的姓名");
    scanf("%s",name);
    PHONE *cur=head;
    while(cur){
        if(strcmp(cur->name,name)==0){
            printf("联系人信息如下：\n");
            printf("序号：%d\n",cur->id);
            printf("姓名：%s\n",cur->name);
            printf("电话号码：\n",cur->phonenum);
            printf("备注：%s\n",cur->note);
            return ;
        }
        cur=cur->next;
    }
    printf("未找到联系人\n");
}

void modify(){
    int id;
    printf("请输入要修改的联系人的序号：");
    scanf("%d",&id);

    if(id<1||id>count){
        printf("序号无效\n");
        return ;
    }

    PHONE *cur=head;
    while(cur&&cur->id!=id){
        cur=cur->next;
    }
    if(!cur){
        printf("未找到联系人\n");
        return ;
    }

    while(getchar()!='\n');    //清理上一个scanf()后留在缓冲区的的回车
    printf("请输入新的姓名（留空保持不变）:");
    char newname[50];
    fgets(newname,sizeof(newname),stdin);
    if(newname[0]!='\n'){
        newname[strcspn(newname,"\n")]='\0';  //去掉换行符
        strcpy(cur->name,newname);
    }

    printf("请输入新的电话号码（留空保持不变）：");
    char newphonenum[20];
    fgets(newphonenum,sizeof(newphonenum),stdin);
    if(newphonenum[0]!='\n'){
        newphonenum[strcspn(newphonenum,"\n")]='\0';
        strcpy(cur->phonenum,newphonenum);
    }

    printf("请输入新的备注（留空保持不变）");
    char newnote[100];
    fgets(newnote,sizeof(newnote),stdin);
    if(newnote[0]!='\n'){
        newnote[strcspn(newnote,"\n")]='\0';
        strcpy(cur->note,newnote);
    }

    printf("修改成功\n");
    savefile();

}
void sort(){
    if(!head||!head->next){
        return ;
    }

    PHONE *i, *j, *pre_j, *temp;
    for(i=head;i！=NULL&&i->next!=NULL;i=i->next){
        pre_j=NULL;
        for(j=head;j->next!=NULL;pre_j=j,j=j->next){
            if(strcmp(j->name,j->next->name)>0){
                if(pre_j==NULL){
                    temp=j->next;
                    j->next=temp->next;
                    temp->next=j;
                    head=temp;
                    j=temp;
                }
                else{
                    temp=j->next;
                    j->next=temp->next;
                    temp->next=j;
                    pre_j->next=temp;
                    j=temp;
                }
            }
        }
    }
    printf("联系人已按姓名排序\n");
    savefile();

}

void display(){
    printf("联系人列表\n");
    printf("+------+------------------+------------------+------------------+\n");
    printf("| 序号 | 姓名             | 电话号码         | 备注             |\n");
    printf("+------+------------------+------------------+------------------+\n");

    PHONE *cur=head;
    while(cur){
        printf("| %-4d | %-16s | %-16s | %-16s |\n",cur->id,cur->name,cur->phonenum,cur->note);
        printf("+------+------------------+------------------+------------------+\n");
        cur=cur->next;
    }
}

int main(){
    loadfile();
    int op = -1;
    while (op != 0){
        menu();
        scanf("%d", &op);
        switch (op){
        case 1:
            add();
            break;

        case 2:
            del();
            break;
        case 3:
            find();
            break;
        case 4:
            modify();
            break;
        case 5:
            sort();
            break;
        case 6:
            display();
            break;
        case 0:
            printf("程序已退出\n");
            break;
        default:
            printf("无效选择\n");
        }
    }
    return 0;
}
