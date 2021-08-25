#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int shoudsave = 0; /* */
struct student
{
	char  num[10];/*ѧ��*/
	char name[20];
	int cgrade;
	int mgrade;
	int egrade;
	int totle;
	int ave;
};
typedef struct node
{
	struct student data;
	struct node *next;
}Node, *Link;

void menu()
{
	printf("====================================================================================================");
	printf("\t1Input Student Data\t\t\t\t\t2Delete Student Data\n");
	printf("\t3Inquiring Student Data\t\t\t\t\t4Update Student Data\n");
	printf("\t5Show Student Data\t\t\t\t\t6Statistical Student Achievement\n");
	printf("\t7Sort Student Achievement\t\t\t\t8Save Student Data\n");
	printf("\t9Give Help Information\t\t\t\t\t0Exit System\n");
	printf("====================================================================================================");
}
void printstart()
{
	printf("====================================================================================================");
}
void Wrong()
{
	printf("\n=====>Show:input error!\n");
}
void Nofind()
{
	printf("\n=====>Show:Not Found The Student!\n");
}
void printc() /* ����������������ı��� */
{
	printf("  Student ID     Name    English_Score      Math_Score      C_Score      Total      Average\n");
}
void printe(Node *p)/*����������������ı����µľ�������  */
{
	printf("  %s              %s       %d                %d             %d          %d         %d\n", p->data.num, p->data.name, p->data.egrade, p->data.mgrade, p->data.cgrade, p->data.totle, p->data.ave);
}
Node *Locate(Link l, char findmess[], char nameornum[])  /*�ú������ڶ�λ�����з���Ҫ��Ľӵ㣬�����ظ�ָ�� */
{
	Node *r;
	if (strcmp(nameornum, "num") == 0) /*��ѧ�Ų�ѯ*/
	{
		r = l->next;
		while (r)
		{
			if (strcmp(r->data.num, findmess) == 0)
				return r;
			r = r->next;
		}
	}
	else if (strcmp(nameornum, "name") == 0)  /*��������ѯ */
	{
		r = l->next;
		while (r)
		{
			if (strcmp(r->data.name, findmess) == 0)
				return r;
			r = r->next;
		}
	}
	return 0;
}
void Add(Link l)  /*����ѧ��*/
{
	Node *p, *r, *s;
	char num[10];
	r = l;
	s = l->next;
	while (r->next != NULL)
		r = r->next;
	while (1)
	{
		printf("Please input ID(use '0' back to up lever menu:)");
		scanf("%s", num);
		getchar();
		if (strcmp(num, "0") == 0)
			break;
		while (s)
		{
			if (strcmp(s->data.num, num) == 0)
			{
				printf("=====>Show:ID Already Exist,if you want to alter select'4 Update'!\n", num);
				printstart();
				printc();
				printe(s);
				printstart();
				printf("\n");
				return;
			}
			s = s->next;
		}
		p = (Node *)malloc(sizeof(Node));
		strcpy(p->data.num, num);
		printf("Please input your name:");
		scanf("%s", p->data.name);
		getchar();//������ͣ�ȴ�����
		printf("Please input your C scores:");
		scanf("%d", &p->data.cgrade);
		getchar();
		printf("Please input your math scores:");
		scanf("%d", &p->data.mgrade);
		getchar();
		printf("Please input your english scores:");
		scanf("%d", &p->data.egrade);
		getchar();
		p->data.totle = p->data.egrade + p->data.cgrade + p->data.mgrade;
		p->data.ave = p->data.totle / 3;/*��Ϣ�����Ѿ����*/

		p->next = NULL;
		r->next = p;
		r = p;
		shoudsave = 1;
	}
}
void Qur(Link l) /*��ѯѧ��*/
{
	int sel;
	char findmess[20];
	Node *p;
	if (!l->next)
	{
		printf("\n=====>Show:No Data Can Finding!\n");
		return;

	}
	printf("\n=====>1Search by ID\n=====>2Search by Name\n");
	scanf("%d", &sel);
	if (sel == 1)/*ѧ��*/
	{
		printf("Please input ID To Search:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "num");
		if (p)
		{
			printf("\t\t\t\tSearch Result\n");
			printstart();
			printc();
			printe(p);
			printstart();
		}
		else
			Nofind();
	}
	else if (sel == 2) /*����*/
	{
		printf("Please input name to search:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "name");
		if (p)
		{
			printf("\t\t\t\tSearch Result\n");
			printstart();
			printc();
			printe(p);
			printstart();
		}
		else
			Nofind();
	}
	else
		Wrong();

}

void Del(Link l) /*ɾ��*/
{
	int sel;
	Node *p, *r;
	char findmess[20];
	if (!l->next)
	{
		printf("\n=====>Show:No Data Can Delete!\n");
		return;
	}
	printf("\n=====>1Delete by ID\n=====>2Delete by Name\n");
	scanf("%d", &sel);
	if (sel == 1)
	{
		printf("Please input ID to delete:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "num");
		if (p)
		{
			r = l;
			while (r->next != p)
				r = r->next;
			r->next = p->next;
			free(p);
			printf("\n=====>Show:Successful Delete!\n");
			shoudsave = 1;
		}
		else
			Nofind();
	}
	else if (sel == 2)
	{
		printf("Please input Name to delete:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "name");
		if (p)
		{
			r = l;
			while (r->next != p)
				r = r->next;
			r->next = p->next;
			free(p);
			printf("\n=====>Show:Successful Delete!\n");
			shoudsave = 1;
		}
		else
			Nofind();
	}
	else
		Wrong();
}

void Modify(Link l)
{
	Node *p;
	char findmess[20];
	if (!l->next)
	{
		printf("\n=====>Show:No Dta Can Update!\n");
		return;
	}
	printf("Please input ID to Update:");
	scanf("%s", findmess);
	p = Locate(l, findmess, "num");
	if (p)
	{
		printf("Please input your new C scores(Original is %d):", p->data.cgrade);
		scanf("%d", &p->data.cgrade);

		printf("\n=====>Show:Data successful update!\n");
		shoudsave = 1;
	}
	else
		Nofind();

}
void Disp(Link l)
{
	int count = 0;
	Node *p;
	p = l->next;
	if (!p)
	{
		printf("\n=====>Show:No Data can Display!\n");
		return;
	}
	printf("\t\t\t\tShow result\n");
	printstart();
	printc();
	printf("\n");
	while (p)
	{
		printe(p);
		p = p->next;
	}
	printstart();
	printf("\n");
}

void Save(Link l)
{
	FILE *fp;
	Node *p;
	int flag = 1, count = 0;
	fp = fopen("c:\\student", "wb");
	if (fp == NULL)
	{
		printf("\n=====>Show:error when open file again!\n");
		exit(1);
	}
	p = l->next;

	while (p)
	{
		if (fwrite(p, sizeof(Node), 1, fp) == 1)
		{
			p = p->next;
			count++;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		printf("\n=====>:File save successful.(%d items has been save successful.)\n", count);
		shoudsave = 0;
	}
	fclose(fp);
}
void stastic(Link l)
{
	Node *p;
	int n, c[3][5] = { 0 };
	int cmax, cmin, mmax, mmin, emax, emin;
	if (!l->next)
	{
		printf("\n=====>Show:No Data Can be Statistical!\n");
		return;
	}
	p = l->next;
	cmax = p->data.cgrade;
	cmin = p->data.cgrade;
	mmax = p->data.mgrade;
	mmin = p->data.mgrade;
	emax = p->data.egrade;
	emin = p->data.egrade;
	while (p)
	{
		if (p->data.cgrade>cmax)
			cmax = p->data.cgrade;
		if (p->data.mgrade>mmax)
			mmax = p->data.mgrade;
		if (p->data.egrade>emax)
			emax = p->data.egrade;
		if (p->data.cgrade<cmin)
			cmin = p->data.cgrade;
		if (p->data.mgrade<mmin)
			mmin = p->data.mgrade;
		if (p->data.egrade<emin)
			emin = p->data.egrade;
		if (p->data.cgrade >= 90 && p->data.cgrade <= 100)
			c[0][0]++;
		if (p->data.cgrade >= 80 && p->data.cgrade<90)
			c[0][1]++;
		if (p->data.cgrade >= 70 && p->data.cgrade<80)
			c[0][2]++;
		if (p->data.cgrade >= 60 && p->data.cgrade<70)
			c[0][3]++;
		if (p->data.cgrade<60)
			c[0][4]++;
		if (p->data.mgrade >= 90 && p->data.mgrade <= 100)
			c[1][0]++;
		if (p->data.mgrade >= 80 && p->data.mgrade<90)
			c[1][1]++;
		if (p->data.mgrade >= 70 && p->data.mgrade<80)
			c[1][2]++;
		if (p->data.mgrade >= 60 && p->data.mgrade<70)
			c[1][3]++;
		if (p->data.mgrade<60)
			c[1][4]++;
		if (p->data.egrade >= 90 && p->data.egrade <= 100)
			c[2][0]++;
		if (p->data.egrade >= 80 && p->data.egrade<90)
			c[2][1]++;
		if (p->data.egrade >= 70 && p->data.egrade<80)
			c[2][2]++;
		if (p->data.egrade >= 60 && p->data.egrade<70)
			c[2][3]++;
		if (p->data.egrade<60)
			c[2][4]++;
		p = p->next;
	}
	while (1)
	{
		printf("1.Statistics every items highest scores and lowest scores\n");
		printf("2.Statistics the number of people in each segment\n");
		printf("0.Exit Statistics\n");
		printf("Please input your select:");
		scanf("%d", &n);
		if (n == 1)
		{
			printf(" �X�T�T�j�T�T�T�T�j�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			printf(" �Usubject�U highest scores �Ulowest scores�U\n");
			printf(" �^�T�T�m�T�T�T�T�m�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
			printf("  C    %d       %d     \n", cmax, cmin);
			printf("  MATH     %d       %d     \n", mmax, mmin);
			printf("  ENGLISH     %d       %d     \n", emax, emin);
		}
		else if (n == 2)
		{
			printf(" �X�T�T�T�T�j�T�T�T�T�j�T�T�T�T�j�T�T�T�j�T�T�T�j�T�T�T�T�[\n");
			printf("  Subject  �U 90~100 �U 80~90  �U 70~80�U 60~70�Ubelow 60�U\n");
			printf(" �^�T�T�T�T�m�T�T�T�T�m�T�T�T�T�m�T�T�T�m�T�T�T�m�T�T�T�T�a\n");
			printf("  C             %d       %d        %d      %d      %d\n", c[0][0], c[0][1], c[0][2], c[0][3], c[0][4]);
			printf("  MATH          %d       %d        %d      %d      %d\n", c[1][0], c[1][1], c[1][2], c[1][3], c[1][4]);
			printf("  ENGLISH       %d       %d        %d      %d      %d\n", c[2][0], c[2][1], c[2][2], c[2][3], c[2][4]);
		}
		else if (n == 0)
		{
			break;
		}
		else
		{
			printf("input error��\n");
		}
	}
	return;
}
void sort(Link l)
{
	Node *p;
	if (!l->next)
	{
		printf("\n=====>Show:No data can be sorted!\n");
		return;
	}
	p = l->next;

}
int stu_achievement()
{
	Link l;/*����*/
	FILE *fp; /*�ļ�ָ��*/
	int sel;
	char ch;
	int count = 0;
	Node *p, *r;
	printf("====================================================================================================");
	printf("\t                   Student Achievement Management System\n");
	printf("====================================================================================================");
	l = (Node*)malloc(sizeof(Node));
	l->next = NULL;
	r = l;

	fp = fopen("C:\\Users\\lvyeq\\Desktop\\Kernel\\student_achievement", "ab+");
	if (fp == NULL)
	{
		printf("\n=====>Show:Can not open this file!\n");
		exit(0);
	}
	printf("\n=====>Show:File has been open ,now start import data......\n");

	while (!feof(fp))
	{
		p = (Node*)malloc(sizeof(Node));
		if (fread(p, sizeof(Node), 1, fp) == 1) /*���ļ������ݷ���ӵ��� */
		{
			p->next = NULL;
			r->next = p;
			r = p; /*���ýӵ��������*/
			count++;
		}
	}

	fclose(fp); /*�ر��ļ� */
	printf("\n=====>Show:Data has been import ,total %d items.\n", count);
	menu();
	while (1)
	{
		printf("Please input your select:");
		scanf("%d", &sel);

		if (sel == 0)
		{
			if (shoudsave == 1)
			{
				getchar();
				printf("\n=====>Show:Data has update whether save(y/n)?\n");
				scanf("%c", &ch);
				if (ch == 'y' || ch == 'Y')
					Save(l);
			}
			printf("\n=====>Show:You have exit system,good bey!\n");
			break;
		}
		switch (sel)
		{
		case 1:Add(l); break; /*����ѧ��*/
		case 2:Del(l); break;/*ɾ��ѧ��*/
		case 3:Qur(l); break;/*��ѯѧ��*/
		case 4:Modify(l); break;/*�޸�ѧ��*/
		case 5:Disp(l); break;
		case 6:stastic(l); break;
		case 7:sort(l); break;
		case 8:Save(l); break;/*����ѧ�� */
		case 9:printf("\t\t\t==========help information==========\n"); menu(); break;
		default: Wrong(); getchar(); break;
		}
	}

	while (l)
	{    /*�ͷ�����l(����1)��ռ�õ��ڴ棡*/
		p = l;
		l = l->next;
		free(p);
	}

	getchar();

	return 0;
}
