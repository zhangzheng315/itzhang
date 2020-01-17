#include<stdio.h>
typedef struct{
	char name[30];
	int  age;
	int  sex;
}User;

int add(int *add,User *u)
{
	int count=*add;
    printf("第%d条\n",count+1);
    printf("请输入姓名：\n");
    scanf("%s",u->name);
    printf("请输入年龄：\n");
    scanf("%d",&u->age);
    printf("请输入性别：\n");
    scanf("%d",&u->sex);
}
int show(int count,User   *u)
{
    int q;
	if(count==0){
		printf("当前无用户\n");
		printf("返回请按0\n");
		scanf("%d",&q);
		if(q==0){
			return 0;
		}
	}else{
        printf("%d  %s  %d  %d\n",count,u->name,u->age,u->sex);
	}
}

int update(User  *u)
{
    printf("请输入姓名：\n");
    scanf("%s",u->name);
    printf("请输入年龄：\n");
    scanf("%d",&u->age);
    printf("请输入性别：\n");
    scanf("%d",&u->sex);
}

int delete(User *u1,User  *u2)
{
	*u1=*u2;
}

int main()
{
    User users[50];
	int count=0;
	int flag1=1;
	while(flag1){
		int id;
		printf("请输入您要操作的编号：\n1.增加用户\n2.查询用户\n3.修改用户\n4.删除用户\n0.退出\n");
		scanf("%d",&id);
		switch(id){ 
			case 1:
				add(&count,&users[count]); 
                count++;
                int add_q;
                printf("添加成功   返回请按：0\n");
                scanf("%d",&add_q);
                if(add_q==0)
                break;
			case 2:
                for(int x=0;x<count;x++){
				    show(x+1,&users[x]);
                }
                printf("返回请按0\n");
                int show_q;
			    scanf("%d",&show_q);
			    if(show_q==0)
				break;
			case 3:               
				for(int x=0;x<count;x++){
				    show(x+1,&users[x]);
                }
				int uid;
                printf("请输入编号\n");
                scanf("%d",&uid);
                update(&users[uid-1]);
                printf("修改成功,返回请按0\n");
                int up_q;
                scanf("%d",&up_q);
                if(up_q==0)
				break;
			case 4:
				for(int x=0;x<count;x++){
					show(x+1,&users[x]);
				}
				int did;
				printf("请输入编号\n");
				scanf("%d",&did);
				int dida=did-1;
				for(;dida<count;dida++){
					delete(&users[dida],&users[dida+1]);
				}
				count--;
				int del_q;	
				printf("删除成功  返回请按0\n");
				scanf("%d",&del_q);
				if(del_q==0)
			    break;
			case 0:
				flag1=0;
				break;
			default :
				printf("请输入正确的编号！\n");
				break;
		}
	}
	return 0;
}
