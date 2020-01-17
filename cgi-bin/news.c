#include<stdio.h>
#include<stdlib.h>
#include "sqlite3.h"

typedef struct {
    char  *title;
    char  *name;
    char  *content;
    char  *content_date;
}Massage;

int callback(void *para, int col_count, char **col_value, char **col_name) {
    for (int i = 0; i < col_count; i++) {
        printf("%s: %s \n", col_name[i], col_value[i]);
 }
    return 0;
}

int insert(sqlite3 *db,Massage *ma)
{
    char *err;
    char sql[100];
    ma->title=malloc(sizeof(char));
    ma->name=malloc(sizeof(char));
    ma->content=malloc(sizeof(char));
    ma->content_date=malloc(sizeof(char));
    printf("请输入title\n");
    scanf("%s",ma->title);
    printf("请输入name\n");
    scanf("%s",ma->name);
    printf("请输入content\n");
    scanf("%s",ma->content);
    printf("请输入content_date\n");
    scanf("%s",ma->content_date);
    sprintf(sql,"INSERT INTO news(title,name,content,content_date) VALUES('%s','%s','%s','%s')",
    ma->title,ma->name,ma->content,ma->content_date);
    if(0!=sqlite3_exec(db,sql,NULL,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
}

int show(sqlite3 *db)
{
    char *err;
    char sql[100];
    sprintf(sql,"SELECT * FROM news");
    if(0!=sqlite3_exec(db,sql,callback,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
}

int update(sqlite3 *db,Massage *ma,int up_id)
{
    char *err;
    char sql[100];
    ma->title=malloc(sizeof(char));
    ma->name=malloc(sizeof(char));
    ma->content=malloc(sizeof(char));
    ma->content_date=malloc(sizeof(char));
    printf("请输入title\n");
    scanf("%s",ma->title);
    printf("请输入name\n");
    scanf("%s",ma->name);
    printf("请输入content\n");
    scanf("%s",ma->content);
    printf("请输入content_date\n");
    scanf("%s",ma->content_date);
    sprintf(sql,"UPDATE news SET title='%s',name='%s',content='%s',content_date='%s' WHERE id='%d'", 
    ma->title,ma->name,ma->content,ma->content_date,up_id);
    if(0!=sqlite3_exec(db,sql,NULL,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
}

int delete(sqlite3 *db,int del_id)
{
    char *err;
    char sql[100];
    sprintf(sql,"DELETE FROM news WHERE id='%d'",del_id);
    if(0!=sqlite3_exec(db,sql,NULL,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
}

int main()
{
    int s;
    int flag=1;
    int up_id;
    int del_id;
    Massage ma;
    sqlite3 *db=NULL;
    int res=sqlite3_open("cms.db",&db);
    if(res!=0){
        printf("open db fail\n");
        return -1;
    }
    while(flag){
        printf("---------主菜单----------\n1.增加2.查询3.更改4.删除5.退出\n");
        scanf("%d",&s);
        switch(s){
            case 1:            
                insert(db, &ma);
                break;
            case 2:
                show(db);
                break;
            case 3:             
                show(db);
                printf("请输入要修改的编号\n");
                scanf("%d",&up_id);
                update(db,&ma,up_id);
                break;
            case 4:
                show(db);
                printf("请输入要删除的编号\n");
                scanf("%d",&del_id);
                delete(db,del_id);
                break;
            case 5:
                flag=0;
                break;
            default :
                printf("请输入正确的编号\n");
                break;
        }
    }
    sqlite3_close(db);
    return 0;
}