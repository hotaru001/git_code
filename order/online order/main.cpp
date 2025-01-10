#include "CLabel.h"
#include "CButton.h"
#include "CEdit.h"
#include "CRegWin.h"
#include "CLogWin.h"
#include "CWinBase.h"
#include <conio.h> //_getch()��ͷ�ļ�
#include <vector> //��̬����
#include "CMyDb.h"
#include "menuWin.h"
#include "viewWin.h"
#include "singleWin.h"
#include "mycartWin.h"
#include "recomWin.h"
#include "doubleWin.h"
#include "multiWin.h"
int main(void)
{
	const char* allorder[] = { "[����]��ʳ����ѡOK������", "�ϱ���������˲�",
	"ȫ�����ֲͣ�����Ʒըȫ��)","֭֭��ţ�������ļ���","����¶��ʥ����߲�", "�����ļ��׵��˲�", 
	"֭֭��ţ��������", "���������׵��˲�", "��������׵��˲�", "��ţ�����ƴ", "[��ֵ�����]���人�����ƴ", 
	"��֥����֭֭��ţ��������","[��1��1]ʥ������ը��Ͱ","[��Ʒ�Ƽ�]���ı���˫�˲�","֭֭��ţ��˫�˻����",
	"WOW˫��˫�˲�","���������㳬ֵ˫�˲�","ȫ��3ѡ1������","[����5.2��]���Լ����˲�","[��һ��һ]ʥ��ը��СʳͰ",
	"[��������]��ĩ���ƴ4������ѡ","[��������]�����ѡ������","����Сʳ�����׵��˲�","ȫ���Ա������˲�","ȫ��2ֻ������",
	"���人��16����","������ֻ���Ͱ"};
	double allprice[27] = { 19.9,27.9,29.9,34.9,39.9,34.9, 30.9 ,29.9,39.9,39.9,39.9,31.9, 50, 48,49,69.9,66,39.6,69.9,46.5,29.9, 10.9, 16.9,
	79,49.8,129,99 };
	//ʵ����һ�����ݿ�Ķ���
	CMyDb* cdb = CMyDb::getIntanse();
	cdb->no_result_exec("create table IF NOT EXISTS user (id integer primary key autoincrement, username text, pwd text); ");
	cdb->no_result_exec("CREATE TABLE IF NOT EXISTS orders (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT, order_code INTEGER, price REAL);");
	//�ര�ڽ����л�
	vector <CWinBase*> winarry;
	winarry.push_back(new CLogWin(0, 0, 40, 25)); //��¼vector-->0
	winarry.push_back(new CRegWin(0, 0, 40, 28)); //ע�� vector -->1
	winarry.push_back(new menuWin(0, 0, 30, 28));//��ҳ�� 2
	winarry.push_back(new viewWin(0, 0, 30, 28));//�˵�ҳ�� 3
	winarry.push_back(new singleWin(0, 0, 23, 28));//���˲�ҳ�� 4
	winarry.push_back(new mycartWin(0, 0, 23, 28));//���ﳵҳ�� 5
	winarry.push_back(new recomWin(0, 0, 23, 28));//�Ƽ�ҳ�� 6
	winarry.push_back(new doubleWin(0, 0, 23, 28));//˫�˲�ҳ�� 7
	winarry.push_back(new multiWin(0, 0, 23, 28));//���˲�ҳ�� 8
	//Ĭ�Ͻ���ĵ�¼����
	int i = 0;
	winarry[i]->show();
	winarry[i]->win_run();
	while (1)
	{
		i = winarry[i]->do_action(); //���¿ؼ��������������Ǹ����� 0 ��¼���� 1ע�ᴰ��
		system("cls");
		if (i == -1)
		break;
		cout << "i====" << i << endl;
		if (i == 4)
		{
			cout << "   ----------���˲�-------------�۸�-" << endl;
			cout << "   1.[����]��ʳ����ѡOK������    19.9" << endl;
			cout << "   2.�ϱ���������˲�          27.9" << endl;
			cout << "   3.ȫ�����ֲͣ�����Ʒըȫ����  29.9" << endl;
			cout << "   4.֭֭��ţ�������ļ���        34.9" << endl;
			cout << "   5.����¶��ʥ����߲�          39.9" << endl;
			cout << "   6.�����ļ��׵��˲�            34.9" << endl;
			cout << "   7.֭֭��ţ��������            30.9" << endl;
			cout << "   8.���������׵��˲�            29.9" << endl;
			cout << "   9.��������׵��˲�            39.9" << endl;
			cout << "   10.��ţ�����ƴ               39.9" << endl;
			cout << "   11.[��ֵ�����]���人�����ƴ 39.9" << endl;
			cout << "   12.��֥����֭֭��ţ��������   31.9" << endl;
		}
		if (i == 6)
		{
			cout << "   ----------�Ƽ��ײ�-------------�۸�-" << endl;
			cout << "   1.[����5.2��]���Լ����˲�     69.9" << endl;
			cout << "   2.[��һ��һ]ʥ��ը��СʳͰ      46.5" << endl;
			cout << "   3.[��������]��ĩ���ƴ4������ѡ 29.9" << endl;
			cout << "   4.[��������]�����ѡ������      10.9" << endl;
			cout << "   5.����Сʳ�����׵��˲�          16.9" << endl;
		}
		if (i == 7)
		{
			cout << "   ----------˫�˲�-------------�۸�-" << endl;
			cout << "   1.[��1��1]ʥ������ը��Ͱ        50" << endl;
			cout << "   2.[��Ʒ�Ƽ�]���ı���˫�˲�      48" << endl;
			cout << "   3.֭֭��ţ��˫�˻����          49" << endl;
			cout << "   4.WOW˫��˫�˲�               69.9" << endl;
			cout << "   5.���������㳬ֵ˫�˲�          66" << endl;
			cout << "   6.ȫ��3ѡ1������              39.6" << endl;
		}
		if (i == 8)
		{
			cout << "   ----------���˲�-------------�۸�-" << endl;
			cout << "   1.ȫ���Ա������˲�              79" << endl;
			cout << "   2.ȫ��2ֻ������               49.8" << endl;
			cout << "   3.���人��16����               129" << endl;
			cout << "   4.������ֻ���Ͱ                99" << endl;
		}
		if (i == 5)
		{
			const char* sql = "SELECT order_code FROM orders;";
			char** result = nullptr;
			int row = 0, column = 0;
			cdb->get_result_exec(sql, result, row, column);
			double myprice=0;
			// ����Ƿ��н��
			if (result != nullptr) 
			{
				for (int j = 1; j <= row; ++j)
				{
					//cout << "order_code: " << result[j * column] << endl;
					int n = atoi(result[j * column]) - 1;
					cout << "  " << result[j * column] << ". " << allorder[n] << "  " << allprice[n] << endl;
					myprice += allprice[n];
				}
				cout << "  �ܼ�:" << myprice << endl;
				sqlite3_free_table(result);
			}	
		}
		winarry[i]->show();
		winarry[i]->win_run();
	}
	//ͳһ�ͷŴ���
	/*for (i = 0; i < winarry.size() - 1; i++)
	{
		delete winarry[i];
	}
	*/
	delete cdb;
	return 0;
}