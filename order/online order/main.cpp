#include "CLabel.h"
#include "CButton.h"
#include "CEdit.h"
#include "CRegWin.h"
#include "CLogWin.h"
#include "CWinBase.h"
#include <conio.h> //_getch()的头文件
#include <vector> //动态数组
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
	const char* allorder[] = { "[热销]主食随心选OK三件套", "老北京鸡肉卷单人餐",
	"全鸡可乐餐（含新品炸全鸡)","汁汁嫩牛堡经典四件套","赞萌露比圣诞玩具餐", "汉堡四件套单人餐", 
	"汁汁和牛堡两件套", "汉堡三件套单人餐", "汉堡五件套单人餐", "和牛堡疯狂拼", "[超值五件套]经典汉堡疯狂拼", 
	"奶芝意面汁汁和牛堡两件餐","[买1送1]圣诞汉堡炸鸡桶","[爆品推荐]爱的堡堡双人餐","汁汁嫩牛堡双人欢享餐",
	"WOW双堡双人餐","堡堡超满足超值双人餐","全鸡3选1两件套","[低至5.2折]疯狂吃鸡三人餐","[买一送一]圣诞炸鸡小食桶",
	"[热销百万]周末疯狂拼4件随心选","[热销百万]早八任选两件套","甜咸小食两件套单人餐","全鸡吃堡堡三人餐","全鸡2只随心配",
	"经典汉堡16件套","堡卷快乐欢聚桶"};
	double allprice[27] = { 19.9,27.9,29.9,34.9,39.9,34.9, 30.9 ,29.9,39.9,39.9,39.9,31.9, 50, 48,49,69.9,66,39.6,69.9,46.5,29.9, 10.9, 16.9,
	79,49.8,129,99 };
	//实例化一个数据库的对象
	CMyDb* cdb = CMyDb::getIntanse();
	cdb->no_result_exec("create table IF NOT EXISTS user (id integer primary key autoincrement, username text, pwd text); ");
	cdb->no_result_exec("CREATE TABLE IF NOT EXISTS orders (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT, order_code INTEGER, price REAL);");
	//多窗口进行切换
	vector <CWinBase*> winarry;
	winarry.push_back(new CLogWin(0, 0, 40, 25)); //登录vector-->0
	winarry.push_back(new CRegWin(0, 0, 40, 28)); //注册 vector -->1
	winarry.push_back(new menuWin(0, 0, 30, 28));//主页面 2
	winarry.push_back(new viewWin(0, 0, 30, 28));//菜单页面 3
	winarry.push_back(new singleWin(0, 0, 23, 28));//单人餐页面 4
	winarry.push_back(new mycartWin(0, 0, 23, 28));//购物车页面 5
	winarry.push_back(new recomWin(0, 0, 23, 28));//推荐页面 6
	winarry.push_back(new doubleWin(0, 0, 23, 28));//双人餐页面 7
	winarry.push_back(new multiWin(0, 0, 23, 28));//多人餐页面 8
	//默认进入的登录窗口
	int i = 0;
	winarry[i]->show();
	winarry[i]->win_run();
	while (1)
	{
		i = winarry[i]->do_action(); //按下控件决定你进入的是那个窗口 0 登录窗口 1注册窗口
		system("cls");
		if (i == -1)
		break;
		cout << "i====" << i << endl;
		if (i == 4)
		{
			cout << "   ----------单人餐-------------价格-" << endl;
			cout << "   1.[热销]主食随心选OK三件套    19.9" << endl;
			cout << "   2.老北京鸡肉卷单人餐          27.9" << endl;
			cout << "   3.全鸡可乐餐（含新品炸全鸡）  29.9" << endl;
			cout << "   4.汁汁嫩牛堡经典四件套        34.9" << endl;
			cout << "   5.赞萌露比圣诞玩具餐          39.9" << endl;
			cout << "   6.汉堡四件套单人餐            34.9" << endl;
			cout << "   7.汁汁和牛堡两件套            30.9" << endl;
			cout << "   8.汉堡三件套单人餐            29.9" << endl;
			cout << "   9.汉堡五件套单人餐            39.9" << endl;
			cout << "   10.和牛堡疯狂拼               39.9" << endl;
			cout << "   11.[超值五件套]经典汉堡疯狂拼 39.9" << endl;
			cout << "   12.奶芝意面汁汁和牛堡两件餐   31.9" << endl;
		}
		if (i == 6)
		{
			cout << "   ----------推荐套餐-------------价格-" << endl;
			cout << "   1.[低至5.2折]疯狂吃鸡三人餐     69.9" << endl;
			cout << "   2.[买一送一]圣诞炸鸡小食桶      46.5" << endl;
			cout << "   3.[热销百万]周末疯狂拼4件随心选 29.9" << endl;
			cout << "   4.[热销百万]早八任选两件套      10.9" << endl;
			cout << "   5.甜咸小食两件套单人餐          16.9" << endl;
		}
		if (i == 7)
		{
			cout << "   ----------双人餐-------------价格-" << endl;
			cout << "   1.[买1送1]圣诞汉堡炸鸡桶        50" << endl;
			cout << "   2.[爆品推荐]爱的堡堡双人餐      48" << endl;
			cout << "   3.汁汁嫩牛堡双人欢享餐          49" << endl;
			cout << "   4.WOW双堡双人餐               69.9" << endl;
			cout << "   5.堡堡超满足超值双人餐          66" << endl;
			cout << "   6.全鸡3选1两件套              39.6" << endl;
		}
		if (i == 8)
		{
			cout << "   ----------多人餐-------------价格-" << endl;
			cout << "   1.全鸡吃堡堡三人餐              79" << endl;
			cout << "   2.全鸡2只随心配               49.8" << endl;
			cout << "   3.经典汉堡16件套               129" << endl;
			cout << "   4.堡卷快乐欢聚桶                99" << endl;
		}
		if (i == 5)
		{
			const char* sql = "SELECT order_code FROM orders;";
			char** result = nullptr;
			int row = 0, column = 0;
			cdb->get_result_exec(sql, result, row, column);
			double myprice=0;
			// 检查是否有结果
			if (result != nullptr) 
			{
				for (int j = 1; j <= row; ++j)
				{
					//cout << "order_code: " << result[j * column] << endl;
					int n = atoi(result[j * column]) - 1;
					cout << "  " << result[j * column] << ". " << allorder[n] << "  " << allprice[n] << endl;
					myprice += allprice[n];
				}
				cout << "  总价:" << myprice << endl;
				sqlite3_free_table(result);
			}	
		}
		winarry[i]->show();
		winarry[i]->win_run();
	}
	//统一释放窗口
	/*for (i = 0; i < winarry.size() - 1; i++)
	{
		delete winarry[i];
	}
	*/
	delete cdb;
	return 0;
}