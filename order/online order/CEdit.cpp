#include "CEdit.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>
//构造函数:开辟空间并进行初始化
/*
* 类中函数定义的格式
* 返回值类型 类名::函数名(形参列表)
* {
* }
*/
//使用初始化列表来进行初始化
CEdit::CEdit(int x, int y, int w, int h, const char* content, int ctrlType, int ips, int maxLen, int inputType):CtrlBase(x, y, w, h, content, ctrlType), ips(ips), maxLen(maxLen), inputType(inputType)
{
}
//析构函数 无返回值类型 ~函数名(无参){}
CEdit::~CEdit()
{
}
void CEdit::keyListen(char key)
{
	/*
	对输入的字符做一系列的判断处理，符和要求的保存和显示：
	this->ips ：显示的格式 1明文 2 密文
	this->iputType ：允许输入的数据类型 1数字 2.字母 3.数字+字母
	this->maxLen：最大的字符长度，如果当前已经保存的字符的个数达到了最大长度的，就没法继续保存
	1. 先计算当前已经保存了几个字符 int count = strlen();
	判断 字符的个数与最大长度是否相等
	如果相等，就不做处理
	如果不相等， 说明可以保存，要判断输入的字符是否符合我们的需要
	判断我们要的是字母、数字还是字母、数字的组合
	if this->iputType == 1 说明我们要的是数字，接下来判断key到底是不是数
	字
	if key>='0' && key<='9'
	保存 ： this->content[count] = key
	显示：要注意显示的格式
	if this->ips == 1 _putch(key);
	if this->ips == 2 _putch('*')
	*/
	int count = strlen(this->content);
	if (key == '\b' && count > 0) //退格的操作
	{
		//
		printf("\b \b");//把界面上显示的字符清掉this->content[count - 1] = '\0'; //就保存到数组中对应的字符清掉
		return;
	}
	if (maxLen == count)
	{
		return;
	}
	else
	{
		if (this->inputType == 1)//数字
		{
			if (key >= '0' && key <= '9')
			{
				this->content[count] = key;
				if (this->ips == 1)
				{
					_putch(key);
				}
				else if (this->ips == 2)
				{
					_putch('*');
				}
			}
		}
		else if (this->inputType == 2)//字母
		{
			if (key >= 'A' && key <= 'Z' || key >= 'a' && key <= 'z')
			{
				this->content[count] = key;
				if (this->ips == 1)
				{
					_putch(key);
				}
				else if (this->ips == 2)
				{
					_putch('*');
				}
			}
		}
		else if (this->inputType == 3)//字母或者数字
		{
			if (key >= 'A' && key <= 'Z' || key >= 'a' && key <= 'z' || key >=
				'0' && key <= '9')
			{
				this->content[count] = key;
				if (this->ips == 1)
				{
					_putch(key);
				}
				else if (this->ips == 2)
				{
					_putch('*');
				}
			}
		}
	}
}