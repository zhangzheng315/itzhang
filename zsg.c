#include<stdio.h>
//int count;
struct User{
	char name[30];
	int  age;
	int  sex;
};
struct User users[50];

int add(int *add)
{
	int count=*add;
	int flag=1;
	int i,co,l;
	printf("您要添加几条数据：\n");
	scanf("%d",&l);
	if(l<=0||l>50){
		printf("要在1~50条之间哦");
		printf("您要添加几条数据：");
		scanf("%d",&l);
	}
	for(count=0;count<l;count++){
		printf("请输入第%d条：",count+1);
		printf("请输入姓名：\n");
		scanf("%s",users[count].name);
		printf("请输入年龄：\n");
		scanf("%d",&users[count].age);
		printf("请输入性别：\n");
		scanf("%d",&users[count].sex);
	}
	printf("添加成功\n");	
	while(flag){
		printf("继续添加请按1\n返回请按：0\n");
		scanf("%d",&i);
		switch(i){
			case 1:
				//printf("%d",l);
				printf("您还可添加%d条\n",50-count);
				printf("您要添加几条数据：\n");
				scanf("%d",&co);
				int k=0;
				for(;k<co;k++){
					printf("请输入第%d条：",count+=1);
					*add=count;
					printf("请输入姓名：\n");
					scanf("%s",users[count-1].name);
					printf("请输入年龄：\n");
					scanf("%d",&users[count-1].age);
					printf("请输入性别：\n");
					scanf("%d",&users[count-1].sex);
				//i++;
				}
				printf("添加成功\n");
				break;
			case 0:
				flag=0;
				break;
		}
	}
	*add=count;
	return 0;
}
int show(int *show)
{
	int count=*show;
	int m;
	if(count==0){
		printf("当前无用户\n");
		printf("返回请按0\n");
		scanf("%d",&m);
		if(m==0){
			return 0;
		}
	}else{
		int x=0;
		int select;
		int select_id;
		printf("1.查看全部\n2.查看单条\n");
		scanf("%d",&select);
		switch(select){
			case 1:
				for(;x<count;x++){
					printf("%d  name:%s  age:%d   sex:%d\n",(x+1),users[x].name,users[x].age,users[x].sex);
				}
				break;
			case 2:
				for(;x<count;x++){
					printf("%d  name:%s\n",(x+1),users[x].name);
				}
				printf("请输入编号\n");
				scanf("%d",&select_id);
				printf("%d  name:%s  age:%d   sex:%d\n",(select_id),users[select_id-1].name,users[select_id].age,users[select_id-1].sex);
                                break;
		}

	printf("返回请按0\n");
			scanf("%d",&m);
			if(m==0){
				return 0;
			}

	}
}

int update(int *upda)
{
	int count=*upda;
	int x=0;
        int up,up_q;	
	for(;x<count;x++){
                    printf("%d  name:%s\n",(x+1),users[x].name);
	}
       	printf("请输入编号\n");
	scanf("%d",&up);
        printf("请输入姓名：\n");
        scanf("%s",users[up-1].name);
        printf("请输入年龄：\n");
        scanf("%d",&users[up-1].age);
        printf("请输入性别：\n");
        scanf("%d",&users[up-1].sex);
	printf("修改成功,返回请按0\n");
	scanf("%d",&up_q);
	if(up_q==0) return 0;
}

int delete(int * delt)
{
	int count=*delt;
	int del;
	int flag2=1;
	int del_a,del_a_q;
	int del_d;
	int x=0;
	int del_dd;
	while(flag2){
		printf("全部删除请按 1\n单条删除请按 2\n返回请按 0\n");
		scanf("%d",&del);
		switch(del){
			case 1:
				printf("确定要清空？ 确定请按1   返回请按0\n");
				scanf("%d",&del_a);
				if(del_a==1){
					count=0;
					printf("删除成功  返回请按0\n");
					scanf("%d",&del_a_q);
					if(del_a_q==0){
						*delt=count;
						flag2=0;
						}
						break;
				}else{
					break;
				}
			case 2:
				for(;x<count;x++){
                                        printf("%d  name:%s\n",(x+1),users[x].name);
                                }
				printf("请输入编号\n");
				scanf("%d",&del_d);
				del_dd=del_d-1;
				for(;del_dd<count;del_dd++){
					users[del_dd]=users[del_dd+1];
				}
				count--;
				printf("删除成功  返回请按0\n");
                                scanf("%d",&del_a_q);
                                if(del_a_q==0){
									*delt=count;
									flag2=0;
									}
                                break;

			case 0:
				flag2=0;
				break;
		}
		//printf("");
	}
}

int main()
{
	int count;
	int flag1=1;
	while(flag1){
		int id;
		printf("请输入您要操作的编号：\n1.增加用户\n2.查询用户\n3.修改用户\n4.删除用户\n0.退出\n");
		scanf("%d",&id);
		switch(id){ 
			case 1:
				add(&count);
				break;
			case 2:
				show(&count);
				break;
			case 3:
				update(&count);
				break;
			case 4:
				delete(&count);
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
