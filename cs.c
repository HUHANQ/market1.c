#include <stdio.h>
#include <string.h>
//#include <unistd.h>
#include <stdlib.h>
#include <mysql/mysql.h>

//超市管理系统
//作者：西瓜深爱着夏天
//日期 2018-8-21





int main()
{
	int b;
	char a[20];
	printf("-------------------》》  欢迎登录超市管理系统！  《《--------------------\n");
	printf("\n");
	printf("\n");
	printf("请输入用户名：\n");
	scanf("%s",a);
	printf("请输入管理员密码：\n");
	printf("-------------------》》");
//	const char* pwd = NULL;
// 	pwd  = getpass();

	scanf("%d",&b);
	if((b == 123456 ) && 0 == strcmp(a,"BOSS") )
	{
	MYSQL mysql;
	mysql_init(&mysql);
	if(!mysql_real_connect(&mysql,"localhost","root","","cs",0,NULL,0))
	{
		fprintf(stderr,"Failed to database:Error:%s\n",mysql_error(&mysql));
		exit(1);
	}
	mysql_query(&mysql,"set names utf8");
	int i;
	printf("-------------------------》》恭喜您！登录成功！《《----------------------\n");
	printf("\n");	
	printf("------------------》》 您好！欢迎您使用超市管理系统！ 《《---------------\n");
	printf("\n");
	printf("                          作者：西瓜深爱着夏天\n");
	printf("\n");
	printf("                                2018-8-21\n");
	printf("\n");
	printf("\n");
	printf("*********************************主菜单**********************************\n");
	printf("\n");
	printf("\n");
	printf("请您选择需要的服务：\n");
	printf("---------------》》1.添加商品\n");
	printf("\n");
	printf("---------------》》2.查找商品\n");
	printf("\n");
	printf("---------------》》3.删除商品\n");
	printf("\n");
	printf("---------------》》4.修改商品信息\n");
	printf("\n");
	printf("---------------》》5.查看所有商品信息\n");
	printf("\n");
	printf("---------------》》");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			{
				int id,prige;
				char sno[50];
				char bir[20];
				char exp[30];
				char sql[300];
				printf("请输入要添加的商品信息：依从为编号,名称,价格,生产日期,保质期\n");
				printf("--------------》》");
				scanf("%d %s %d %s %s",&id,&sno,&prige,&bir,&exp);
				sprintf(sql,"insert into cs values( %d ,'%s' ,%d,'%s', '%s')",id,sno,prige,bir,exp);		
				if(mysql_query(&mysql,sql))
				{
					fprintf(stderr,"Failed to  insert to table cs :Error:%s\n ",mysql_error(&mysql));
					exit(1);
				}
				printf("恭喜您！添加商品信息成功哦！\n");
				break;
			}
		case 2:
			{
				char sno[50];
				char sql2[300];
				printf("请输入要查找的商品名称：");
				printf("----------》》");
				scanf("%s",sno);
				sprintf(sql2,"select * from cs where sno = '%s'",sno);
				if(mysql_query(&mysql,sql2))
				{
					fprintf(stderr,"Failed to select to table cs : Error: %s\n",mysql_error(&mysql));
				}
				else	
				{
					MYSQL_RES* res;
					res = mysql_store_result(&mysql);
					MYSQL_ROW row;
					row = mysql_fetch_row(res);
					if(row == NULL)
					{
						printf("该商品不存在！\n");	
					}
					else
					{
						printf("您所要查找的商品信息在这里哦：%s %s %s %s %s \n",row[0],row[1],row[2],row[3],row[4]);
					}			
					mysql_free_result(res);
				}
				break;
			}
		case 3:
			{
				char sno[50];
				char sql3[300];
				printf("请输入要删除的商品名称：");	
				printf("---------->");
				scanf("%s",sno);
				sprintf(sql3,"delete from cs where sno = '%s'",sno);
				if(mysql_query(&mysql,sql3))
				{
					fprintf(stderr,"Failed to delete table : Error:%s\n",mysql_error(&mysql));
					exit(1);
				}
				printf("恭喜您!删除商品信息成功！\n");
				break;
			}
		case 4:
			{
				int m;
				char sno[20];
				printf("请输入要修改的商品名称\n");
				printf("---------->");
				scanf("%s",sno);
				printf("请选择要修改的商品属性：1.编号 2.名称 3.价格 4.生产日期 5.保质期\n");
				printf("---------->");
				scanf("%d",&m);
				switch(m)
				{
					case 1:
						{
						int id;
						char sql41[300];
						printf("请输入新的商品编号：");
						printf("---------->");
						scanf("%d",&id);
						sprintf(sql41,"update cs set id = %d  where sno = '%s'",id,sno);
						mysql_query(&mysql,sql41);
						printf("恭喜您！修改商品编号成功！\n");	
							break;
						}				
					case 2:
						{
						char sno1;
						char sql42[300];
						printf("请输入新的商品名称：");
						printf("---------->");
						scanf("%s",sno1);
						sprintf(sql42,"update cs set sno = '%s'  where sno = '%s'",sno1,sno);
						mysql_query(&mysql,sql42);	
						printf("恭喜您！修改商品名称成功！\n");	
							break;
						}				
					case 3:
						{
						int prige;
						char sql43[300];							
						printf("请输入新的商品价格：");
						printf("---------->");
						scanf("%d",&prige);
						sprintf(sql43,"update cs set prige = %d  where sno = '%s'",prige,sno);
						mysql_query(&mysql,sql43);	
						printf("恭喜您！修改商品价格成功！\n");	
							break;
						}				
					case 4:
						{
						char bir[50];
						char sql44[300];
						printf("请输入新的商品生产日期：");
						printf("---------->");
						scanf("%s",bir);
						sprintf(sql44,"update cs set bri = '%s'  where sno = '%s'",bir,sno);
						mysql_query(&mysql,sql44);	
						printf("恭喜您！修改商品生产日期成功！\n");	
							break;
						}				
					case 5:
						{
						char exp[50];							
						char sql45[300];
						printf("请输入新的商品保质期：");
						printf("---------->");
						scanf("%s",exp);
						sprintf(sql45,"update cs set exp = '%s'  where sno = '%s'",exp,sno);
						mysql_query(&mysql,sql45);	
						printf("恭喜您！修改商品保质期成功！\n");	
							break;
						}				
				}
				break;
			}
		case 5:
			{
			char sql5[300];
			sprintf(sql5,"select * from cs");
			mysql_query(&mysql,sql5);
			MYSQL_RES* res;
			res = mysql_store_result(&mysql);
			MYSQL_ROW row;
			while (row = mysql_fetch_row(res))
				{
				printf("%s          %s          %s          %s          %s \n",row[0],row[1],row[2],row[3],row[4]);
				printf("\n");
				}
			mysql_free_result(res);
				break;
			}
	}
	mysql_close(&mysql);
	}
	else
	{
	printf("Sorry! 用户名或密码输入错误！登录失败！\n");
	}
	return 0;
}
