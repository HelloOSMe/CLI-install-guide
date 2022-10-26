#include<windows.h>
#include<bits/stdc++.h>
#include<conio.h>
#include<unistd.h>
#include <Urlmon.h>
#pragma comment(lib, "Urlmon.lib")
using namespace std;
void gotoxy(short x, short y) {
	COORD coord = {y, x}; 
	//COORD是Windows API中定义的一种结构体类型，表示控制台屏幕上的坐标。
	//上面语句是定义了COORD类型的变量coord，并以形参x和y进行初始化。
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	//GetStdHandle(STD_OUTPUT_HANDLE); 获取控制台输出句柄
	//然后用SetConsoleCursorPosition设置控制台(cmd)光标位置
}
void CloseFastEdit(){
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE; //移除快速编辑模式
	mode &= ~ENABLE_INSERT_MODE; //移除插入模式
	mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin, mode);
}
void ShowCursor(bool visible) { //显示或隐藏光标
	CONSOLE_CURSOR_INFO cursor_info = {20, visible};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void WindowSize(int a,int b) { 
	char cmd[128];
	sprintf_s(cmd, "mode con cols=%d lines=%d", a, b);
	system(cmd);
}
int choose(char a,bool ib,char b,bool ic,char c){
	while(1){
		char ch=getch();
		if(ch==a||ch==a+32){
			return 0;
		}else if((ch==b&&ib)||(ch==b+32&&ib)){
			return 1;
		}else if((ch==c&&ic)||(ch==c+32&&ic)){
			return 2;
		}
	}
}
void start(){
	WindowSize(55,15);
	cout<<"----------------欢迎使用game安装向导！----------------"<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"   GAMES    |           欢迎使用game安装向导!         "<<endl;
	cout<<"    Git     |                                         "<<endl;
	cout<<"   v 1.0    |            快速从GitHub上安装           "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                      [C 取消]  [O 确定] "<<endl;
	int i=choose('C',1,'O',0,'\0');
	if(i==0){
		exit(0);
	}
}
void where(){
	cout<<"----------------欢迎使用game安装向导！----------------"<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"   GAMES    |           你想将game安装在哪里?         "<<endl;
	cout<<"    Git     |  now                                    "<<endl;
	cout<<"   v 1.0    |  :                                      "<<endl;
	cout<<"            |  [                                   ]  "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                 [ANYKEY 编辑] [F2 确定] "<<endl;
	while(1){
		gotoxy(5,16);
		cout<<"                                   ";
		gotoxy(5,16);
		getch();
		char a=getch();
		if(a==60){
			return;
		}
		ShowCursor(true);
		char path[256];
		gets(path);
		chdir(path);
		ShowCursor(false);
		gotoxy(4,16);
		cout<<"                                    ";
		gotoxy(4,16);
		cout<<getcwd(NULL,0)<<endl;
	}
}
void ins(){
	WindowSize(55,15);
	cout<<"----------------欢迎使用game安装向导！----------------"<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"   GAMES    |                 开始 安装               "<<endl;
	cout<<"    Git     |                          #    #   #     "<<endl;
	cout<<"   v 1.0    |                          ##  ##  ##     "<<endl;
	cout<<"            |     ########      ##     # ##  ## #     "<<endl;
	cout<<"            |    ##      ##    ####    #        #     "<<endl;
	cout<<"            |   ##            ##  ##      ------      "<<endl;
	cout<<"            |   ##    ###### ########     |           "<<endl;
	cout<<"            |    ##      ## ##      ##    |-----      "<<endl;
	cout<<"            |     ########  ##      ##    |           "<<endl;
	cout<<"            |                             ------      "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                      [E 退出]  [I 安装] "<<endl;
	int i=choose('E',1,'I',0,'\0');
	if(i==0){
		exit(0);
	}
}
void download(){
	cout<<"----------------欢迎使用game安装向导！----------------"<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"   GAMES    |                正在安装...              "<<endl;
	cout<<"    Git     |  now                                    "<<endl;
	cout<<"   v 1.0    |  [                                  ]   "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	gotoxy(4,16);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10*16);
	URLDownloadToFile(0,"https://codeload.github.com/HelloOSMe/-Games-for-OIers-/zip/refs/heads/main","main.zip",0,NULL);
	cout<<"                  ";
	system("powershell Expand-Archive main.zip");
	cout<<"           ";
	system("del /f /q main.zip");
	cout<<"   ";
	system("rename main Game");
	cout<<"  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void finish(){
	WindowSize(55,15);
	cout<<"----------------欢迎使用game安装向导！----------------"<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"   GAMES    |           感谢使用game安装向导!         "<<endl;
	cout<<"    Git     |                                         "<<endl;
	cout<<"   v 1.0    |                安装完成！               "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                         "<<endl;
	cout<<"            |                                [O 确定] "<<endl;
	int i=choose('O',1,'O',0,'\0');
}
int main(){
	CloseFastEdit();
	ShowCursor(false);
	start();
	where();
	ins();
	download();
	finish();
	return 0;
}
