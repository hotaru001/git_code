#include "CEdit.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>
//���캯��:���ٿռ䲢���г�ʼ��
/*
* ���к�������ĸ�ʽ
* ����ֵ���� ����::������(�β��б�)
* {
* }
*/
//ʹ�ó�ʼ���б������г�ʼ��
CEdit::CEdit(int x, int y, int w, int h, const char* content, int ctrlType, int ips, int maxLen, int inputType):CtrlBase(x, y, w, h, content, ctrlType), ips(ips), maxLen(maxLen), inputType(inputType)
{
}
//�������� �޷���ֵ���� ~������(�޲�){}
CEdit::~CEdit()
{
}
void CEdit::keyListen(char key)
{
	/*
	��������ַ���һϵ�е��жϴ�������Ҫ��ı������ʾ��
	this->ips ����ʾ�ĸ�ʽ 1���� 2 ����
	this->iputType ������������������� 1���� 2.��ĸ 3.����+��ĸ
	this->maxLen�������ַ����ȣ������ǰ�Ѿ�������ַ��ĸ����ﵽ����󳤶ȵģ���û����������
	1. �ȼ��㵱ǰ�Ѿ������˼����ַ� int count = strlen();
	�ж� �ַ��ĸ�������󳤶��Ƿ����
	�����ȣ��Ͳ�������
	�������ȣ� ˵�����Ա��棬Ҫ�ж�������ַ��Ƿ�������ǵ���Ҫ
	�ж�����Ҫ������ĸ�����ֻ�����ĸ�����ֵ����
	if this->iputType == 1 ˵������Ҫ�������֣��������ж�key�����ǲ�����
	��
	if key>='0' && key<='9'
	���� �� this->content[count] = key
	��ʾ��Ҫע����ʾ�ĸ�ʽ
	if this->ips == 1 _putch(key);
	if this->ips == 2 _putch('*')
	*/
	int count = strlen(this->content);
	if (key == '\b' && count > 0) //�˸�Ĳ���
	{
		//
		printf("\b \b");//�ѽ�������ʾ���ַ����this->content[count - 1] = '\0'; //�ͱ��浽�����ж�Ӧ���ַ����
		return;
	}
	if (maxLen == count)
	{
		return;
	}
	else
	{
		if (this->inputType == 1)//����
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
		else if (this->inputType == 2)//��ĸ
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
		else if (this->inputType == 3)//��ĸ��������
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