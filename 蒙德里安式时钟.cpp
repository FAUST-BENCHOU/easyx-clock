/*2252543 周瑾瑜 国06*/

/*我一步一步地排除着曲线，直到我的作品最后只由直线和横线构成，形成诸十字形，各自互相
分离地隔开，……直线和横线是两相对立的力量的表现；这类对立物的平衡到处存在着，控制着一切。”
																	   ——蒙德里安
*/

#include <graphics.h>
#include <conio.h>
#include <math.h>
#pragma comment(lib,"Winmm.lib")
#define	PI	3.1415926536

void Hand(int hour, int minute, int second)
{
	double a_hour, a_min, a_sec;					// 时、分、秒针的弧度值
	int x_hour, y_hour, x_min, y_min, x_sec, y_sec;	// 时、分、秒针的末端位置

	// 计算时、分、秒针的弧度值
	a_sec = second * 2 * PI / 60;
	a_min = minute * 2 * PI / 60 + a_sec / 60;
	a_hour = hour * 2 * PI / 12 + a_min / 12;

	// 计算时、分、秒针的末端位置
	x_sec = int(143 * sin(a_sec));	y_sec = int(143 * cos(a_sec));
	x_min = int(95.79 * sin(a_min));	y_min = int(95.79 * cos(a_min));//黄金分割比
	x_hour = int(59.2 * sin(a_hour));	y_hour = int(59.2 * cos(a_hour));


	// 画时针
	setfillcolor(LIGHTGRAY);
	solidrectangle((320 + x_hour - 16), (240 - y_hour - 16), (320 + x_hour + 16), (240 - y_hour + 16));
	// 画分针
	setfillcolor(LIGHTGRAY);
	solidrectangle(320 + x_min - 13, 240 - y_min - 13, 320 + x_min + 13, 240 - y_min + 13);
	//画秒针
	setfillcolor(LIGHTGRAY);
	solidrectangle(320 + x_sec - 10, 240 - y_sec - 10, 320 + x_sec + 10, 240 - y_sec + 10);
	//中心
	setfillcolor(LIGHTGRAY);
	solidrectangle(320 - 7, 240 - 7, 320 + 7, 240 + 7);

}

void Dial()
{
	// 绘制表盘
	setbkcolor(WHITE);		// 设置背景色


	cleardevice();				// 清屏
	// 输出字符串
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿
	f.lfHeight = 20;                        //字体大小
	settextstyle(&f);						// 设置字体样式
	outtextxy(73, 20, _T("1921 Composition with Large Blue Plane, Red, Black, Yellow, and Gray"));

	setcolor(BLACK);
	rectangle(320 - 2, 240 - 2, 320 + 2, 240 + 2);
	setlinestyle(PS_DASH | PS_ENDCAP_SQUARE, 4);
	rectangle(320 - 160, 240 - 160, 320 + 160, 240 + 160);//中心点（320,240）
	//           160         80        480        400



	//标志框外刻度
	int x, y;
	for (int i = 0; i < 60; i++)
	{
		x = 320;
		y = 240;

		if (i % 15 == 0)
		{
			setfillcolor(RED);
			solidrectangle(x - 7 + int(180 * sin(PI * 2 * i / 60)), y - 7 + int(180 * cos(PI * 2 * i / 60)),
				x + 7 + int(180 * sin(PI * 2 * i / 60)), y + 7 + int(180 * cos(PI * 2 * i / 60)));
		}

		else if (i % 10 == 0)
		{
			setfillcolor(RGB(227, 216, 45));
			solidrectangle(x - 7 + int(211 * sin(PI * 2 * i / 60)), y - 7 + int(211 * cos(PI * 2 * i / 60)),
				x + 7 + int(211 * sin(PI * 2 * i / 60)), y + 7 + int(211 * cos(PI * 2 * i / 60)));
		}
		else if (i % 5 == 0)
		{
			setfillcolor(RGB(38, 21, 140));
			solidrectangle(x - 7 + int(208 * sin(PI * 2 * i / 60)), y - 7 + int(208 * cos(PI * 2 * i / 60)),
				x + 7 + int(208 * sin(PI * 2 * i / 60)), y + 7 + int(208 * cos(PI * 2 * i / 60)));
		}
	}


	// 绘制具体色块

	POINT pts1[] = { {160 + 5 , 80 + 5}, {280, 80 + 5}, {280,220},{160 + 5,220} };
	// 设置填充颜色为红色
	setfillcolor(RED);
	solidpolygon(pts1, 4);

	POINT pts2[] = { {360, 280}, {480 - 5, 280}, {480 - 5,400 - 5 },{360,400 - 5} };
	// 设置填充颜色为红色
	setfillcolor(RED);
	solidpolygon(pts2, 4);

	POINT pts3[] = { {160 + 5, 280}, {360, 280}, {360,400 - 5 },{160 + 5,400 - 5} };
	// 设置填充颜色为黄色
	setfillcolor(RGB(227, 216, 45));
	solidpolygon(pts3, 4);


	POINT pts4[] = { {280, 80 + 5}, {360, 80 + 5}, {360,200 },{280,200} };
	// 设置填充颜色为蓝色
	setfillcolor(RGB(38, 21, 140));
	solidpolygon(pts4, 4);

	POINT pts5[] = { {280,200},{360,200 }, {360,280},{280, 280} };
	// 设置填充颜色为黑色
	setfillcolor(BLACK);
	solidpolygon(pts5, 4);

	//黑色线分割
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 3);
	setlinecolor(BLACK);

	line(280, 80 + 5, 280, 280);
	line(360, 80 + 5, 360, 400 - 5);
	line(420, 80 + 5, 420, 400 - 5);

	line(160 + 5, 280, 480 - 5, 280);
	line(160 + 5, 280, 480 - 5, 280);
	line(160 + 5, 220, 280, 220);
	line(280, 200, 360, 200);
}

int main()
{
	initgraph(640, 480);		// 初始化 640 x 480 的绘图窗口

	SYSTEMTIME ti;
	// 定义变量保存当前时间

	// 获得窗口句柄
	HWND hWnd = GetHWnd();
	// 使用 Windows API 修改窗口名称
	SetWindowText(hWnd, L"蒙德里安式时钟：红、黄、蓝、灰的构成");
	mciSendString(_T("open backmusic.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
	while (!_kbhit())			// 按任意键退出钟表程序
	{

		GetLocalTime(&ti);		// 获取当前时间
		Dial();	// 绘制表盘
		Hand(ti.wHour, ti.wMinute, ti.wSecond);	// 画表针
		Sleep(1000);			// 延时 1 秒
	}


	return 0;
}