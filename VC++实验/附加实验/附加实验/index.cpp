#include<Windows.h>
#include<stdio.h>
LRESULT CALLBACK WinSunProc(
	HWND hwnd,//handle to window
	UINT uMsg,//message identifier
	WPARAM wParam,//first message parameter
	LPARAM lParam//second message parameter
);
int WINAPI WinMain(
	HINSTANCE hInstance,//handle to current instance
	HINSTANCE hPrevInstance,//handle to previous instance
	LPSTR lpCmdLine,//command line
	int nCmdShow//show state
)
{
	//窗口属性设置
	WNDCLASS hammer;
	hammer.style = CS_HREDRAW | CS_VREDRAW;
	hammer.lpfnWndProc = WinSunProc;
	hammer.cbClsExtra = 0;
	hammer.cbWndExtra = 0;
	hammer.hInstance = hInstance;
	hammer.hIcon = LoadIcon(NULL, IDI_ERROR);
	hammer.hCursor = LoadCursor(NULL, IDI_ERROR);
	hammer.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	hammer.lpszClassName = "233333";//类名要和createwindow中的名称一致，程序名称
	hammer.lpszMenuName = NULL;//指向常量的字符串，菜单名称
	//窗口注册
	RegisterClass(&hammer);
	//窗口创建
	HWND hwnd;
	//
	/*++++
	
	++++*/
	//
	hwnd = CreateWindow(
		"233333", //注册的类名,窗口要基于前面注册的名称，否则会找不到设置造成生成失败
		"你是个啥玩意", //标题名
		WS_OVERLAPPEDWINDOW, //窗口类型(本类型为一个许多类型窗口设置的集合组成一个窗口),WS_OVERLAPPEDWINDOW == 产生层叠/嵌套窗口+创建标题栏+创建系统菜单+创建可调边框+创建最小化最大化按钮最小最大尺寸
		600, //窗口坐标x
		300, //y
		300, //宽度(CW_USEDEFAULT为缺省操作，如果第一个参数设置缺省则忽略第二个操作，如果第一个正常第二个缺省则无法生成)
		200, //高度
		NULL, //是否具有副窗口
		NULL, //菜单句柄
		hInstance, //实例句柄(实例号hInstance)
		NULL//多文档文件附加参数传入的指针
	);
	ShowWindow(hwnd, SW_SHOWNORMAL);//窗口创建的句柄+显示模式(正常模式，最大化模式，最小化模式)
	UpdateWindow(hwnd);//窗口更新

	MSG msg;
	while (GetMessage(&msg, //消息指针，getmessage返回bool值，有消息则返回真
		NULL, //从消息队列取出消息NULL表示获取所有消息，没有取得消息限制
		0, //指示获取第一个消息
		0)) {//指示获取的最后一个消息，全为0则不过滤
		TranslateMessage(&msg); //将虚拟键消息(如 WM_KEYDONW)转换为字符消息WM_CHAR，翻译
		DispatchMessage(&msg);	// 将消息回传 OS ，由 OS 调用窗口过程函数 WinSunProc 完成消息处理
	}
	return 0;
}
LRESULT CALLBACK WinSunProc(//返回long型
	HWND hwnd,		// handle to window 
	UINT uMsg,	// message identifier
	WPARAM wParam,		// first message parameter 附加参数
	LPARAM lParam	// second message parameter第二个消息附加参数
	)
{
	switch (uMsg)
	{
	case WM_CHAR: 
		char szChar[40];
		sprintf_s(szChar, "你哪怕按 %c", wParam); //格式化文本到内存
		strcat_s(szChar,strlen(szChar)+strlen(" 也还是个锤子")+1, " 也还是个锤子");
		MessageBox(hwnd, szChar, "锤子", 0); 
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, "你点左键还是个锤子", "锤子", 0); 
		HDC lhdc;
		lhdc = GetDC(hwnd);
		TextOut(lhdc, 0, 50, "都说了你是个锤子", strlen("都说了你是个锤子")); 
		ReleaseDC(hwnd, lhdc);
		break;
	case WM_RBUTTONDOWN:
		MessageBox(hwnd, "你按右键也是个锤子", "锤子", 0);
		HDC rhdc;
		rhdc = GetDC(hwnd);
		TextOut(rhdc, 0, 100, "你再按都还是个锤子", strlen("你再按都还是个锤子"));//hdc+坐标+字符和其长度
		ReleaseDC(hwnd, rhdc);//释放
		break;
	case WM_PAINT: 
		HDC hDC;
		PAINTSTRUCT ps;
		hDC = BeginPaint(hwnd, &ps);
		TextOut(hDC, 0, 0, "你是个锤子", strlen("你是个锤子")); EndPaint(hwnd, &ps);
		break;
	case WM_CLOSE:
		if (IDYES == MessageBox(hwnd, "不管你按什么都是个锤子，看你关不关我", "锤子", MB_YESNO))
		{
			DestroyWindow(hwnd);
		}

		break;
	case WM_DESTROY: PostQuitMessage(0); break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}