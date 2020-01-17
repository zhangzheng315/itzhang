```
 ln -s /etc/apache2/mods-available/cgid.conf /etc/apache2/mods-enabled/cgid.conf

 ln -s /etc/apache2/mods-available/cgid.load /etc/apache2/mods-enabled/cgid.load
 
 ln -s /etc/apache2/mods-available/cgi.load /etc/apache2/mods-enabled/cgi.load
```

```
1,在www下建立cgi-bin目录
在其下建含html的c文件
#include <stdio.h>
//gcc hellocgi.c -o hellocgi.cgi
int main() {
    printf("Content-Type: text/html\n\n");
    printf("<h1>Hello CGI</h1>");
    return 0;
}
2在etc/apache2/conf-available下找到server-cgi-bin.conf文件,改其地址为var下面的www
3建上面的3行代码复制到Apache下的终端中
4重启Apache的服务代码为sudo etc/init.d/apache2  restart
5将刚刚的c文件编译成cgi文件
```



