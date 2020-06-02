#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>


//括号配对问题
typedef struct snode
{
	char data;
	struct snode *text;
}snode;
typedef struct ss
{
	struct snode *top;
}ss;
void linkseackinit(ss *pst)
{
	pst->top = (snode*)malloc(sizeof(snode));
	pst->top->text = NULL;
}
bool linkstackkong(ss *pst)
{
	return pst->top->text == NULL;
}
void linkstackpush(ss *pst,char x)
{
	assert(pst != NULL);
	snode *s = (snode*)malloc(sizeof(snode));
	s->data = x;
	s->text = pst->top->text;
	pst->top->text = s;		
}
void linkstackpop(ss *pst)
{
	assert(pst != NULL);
	if (linkstackkong(pst))
	{
		printf("KONG\n");
		return;
	}
	snode *p = pst->top->text;
	pst->top->text = p->text;
	free(p);
}
char linkstacktop(ss *pst)
{
	return pst->top->text->data;
}
bool isvalid(char *s)
{

	ss sch;
	int i = 0;
	linkseackinit(&sch);
	if (s == NULL)
		return false;
	if (s[0] == '\0')
		return  true;
	
	while (s[i]!= '\0')
	{
		if (s[i] != '{'&&s[i] != '}'&&s[i] != '('&&s[i] != ')'&&s[i] != '['&&s[i] != ']')
		{
			i++;
			continue;
		}

		if (s[i] == '{' || s[i] == '[' || s[i] == '(')
			linkstackpush(&sch,s[i]);
		else
		{
			char top = linkstacktop(&sch);
			if (top == '{'&&s[i] != '}')
				return false;
			else if (top == '['&&s[i] != ']')
				return false;
			else if (top == '('&&s[i] != ')')
				return false;
			else
				linkstackpop(&sch);
		}
		i++;
		
	}
	bool flag = linkstackkong(&sch);
	return flag;
}

int main()
{
	char  s[20];
	int i = 0;
	printf("请输入一个括号字符串（以‘#'结束）\n");
	gets(s);
	bool flag = isvalid(s);
	if (flag)
	{
		printf("您输入的括号是合法的！\n");
	}
	else
		printf("您输入的括号是不合法的！\n");
   return 0;
}
