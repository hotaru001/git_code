#pragma once
class CtrlBase
{
public:
	CtrlBase(int x = 0, int y = 0, int w = 0, int h = 0, const char* content = nullptr, int ctrlType = 0);
	~CtrlBase();
	void show();
	int getX(); //x����
	int getY(); //y����
	int getCtrlType(); //��ÿؼ������� 1-->CEdit 2.CButton��3.CLabel
	char* getContent(); //�������
	virtual void keyListen(char key);
protected:
	int x;
	int y;
	int w;
	int h;
	char content[20];
	int ctrlType; //�ؼ����� CEdit (1) CButton(2) CLabel(3)
};

