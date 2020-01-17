#include<stdio.h>
#include<stdlib.h>
#include "sqlite3.h"

int callback(void *para, int col_count, char **col_value, char **col_name) {
    for (int i = 1; i < col_count; i++) {
        printf("<tr><td align='right' width='120px' >%s:</td> <td>%s</td>",col_name[i], col_value[i]);
 }
    return 0;
}

int show(sqlite3 *db)
{
    char *id=getenv("QUERY_STRING");
    char *err;
    char sql[100];
    sprintf(sql,"SELECT * FROM news WHERE id=%d",atoi(id));
    if(0!=sqlite3_exec(db,sql,callback,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
}

int main()
{
     sqlite3 *db=NULL;
    int res=sqlite3_open("cms.db",&db);
    if(res!=0){
        printf("open db fail\n");
        return -1;
    }
    printf("Content-Type: text/html\n\n");  
    printf("<!DOCTYPE html>\
                    <html>\
                    <head>\
                    <meta charset='utf-8'/>\
                    <style>\
                    ul,li,body{padding:0;margin:0;}\
                    tr{background:rgba(0,255,255,0.3);height:35px;}\
                    tr:hover{background:rgba(0,255,255,0.8);}\
                    a{display:block;}\
                    td{font-size:20px;}\
                    </style>\
                    </head>\
                    <body>\
                    <div style=\"margin:0 auto;height:40px;width:1300px;background-color:rgba(255,0,0,0.2);border:1px solid red;color:#666;text-align:center; line-height:40px;font-size:20px;\">国内新闻</div>");
    printf("<div style='position:relative;margin:20px auto;width:300px;height:400px;background-color:rgba(0,0,0,0.05);'>");
    //printf("<ul>");
    printf("<div style='position:absolute;margin:15px auto;right:5px;text-align:right;'><a href='d.cgi'><button>返回</button></a></div><br><br>");
    printf("<div style='margin-top:40px;'>\
                    <table border='0px' width='300px'>");
    show(db);
   printf("</table></div>");
   printf("</div>");              
    printf("</body></html>");
    return 0;
}