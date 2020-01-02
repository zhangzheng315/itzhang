#include<stdio.h>
#include<stdlib.h>
#include "sqlite3.h"

int callback(void *para, int col_count, char **col_value, char **col_name) {
        printf("<a  href='f.cgi?%s'><li> %s</li></a> ",col_value[0], col_value[1]);
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
                    a{text-decoration:none;color:rgb(0,0,0);display:block;}\
                    li{margin:10px auto;padding:2px 0 2px 10px;list-style:none;background:rgba(0,255,0,0.1);font-size:20px;}\
                    li:hover{background:rgba(0,255,0,0.5);cursor:pointer;}\
                    a:hover{color:rgb(255,0,0);}\
                    </style>\
                    </head>\
                    <body>\
                    <div style=\"margin:0 auto;height:40px;width:1300px;background-color:rgba(255,0,0,0.2);border:1px solid red;color:#666;text-align:center; line-height:40px;font-size:20px;\">国内新闻</div>");
    printf("<div style='margin:40px auto;width:300px;height:400px;background-color:rgba(0,0,0,0.05);'>");
    printf("<ul style='position:relative;margin-top:10px'>");
    show(db);
    printf("</ul></div>");              
    printf("</body></html>");
    return 0;
}
