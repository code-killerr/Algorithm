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
	//������������
	WNDCLASS hammer;
	hammer.style = CS_HREDRAW | CS_VREDRAW;
	hammer.lpfnWndProc = WinSunProc;
	hammer.cbClsExtra = 0;
	hammer.cbWndExtra = 0;
	hammer.hInstance = hInstance;
	hammer.hIcon = LoadIcon(NULL, IDI_ERROR);
	hammer.hCursor = LoadCursor(NULL, IDI_ERROR);
	hammer.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	hammer.lpszClassName = "233333";//����Ҫ��createwindow�е�����һ�£���������
	hammer.lpszMenuName = NULL;//ָ�������ַ������˵�����
	//����ע��
	RegisterClass(&hammer);
	//���ڴ���
	HWND hwnd;
	//
	/*++++
	
	++++*/
	//
	hwnd = CreateWindow(
		"233333", //ע�������,����Ҫ����ǰ��ע������ƣ�������Ҳ��������������ʧ��
		"���Ǹ�ɶ����", //������
		WS_OVERLAPPEDWINDOW, //��������(������Ϊһ��������ʹ������õļ������һ������),WS_OVERLAPPEDWINDOW == �������/Ƕ�״���+����������+����ϵͳ�˵�+�����ɵ��߿�+������С����󻯰�ť��С���ߴ�
		600, //��������x
		300, //y
		300, //���(CW_USEDEFAULTΪȱʡ�����������һ����������ȱʡ����Եڶ��������������һ�������ڶ���ȱʡ���޷�����)
		200, //�߶�
		NULL, //�Ƿ���и�����
		NULL, //�˵����
		hInstance, //ʵ�����(ʵ����hInstance)
		NULL//���ĵ��ļ����Ӳ��������ָ��
	);
	ShowWindow(hwnd, SW_SHOWNORMAL);//���ڴ����ľ��+��ʾģʽ(����ģʽ�����ģʽ����С��ģʽ)
	UpdateWindow(hwnd);//���ڸ���

	MSG msg;
	while (GetMessage(&msg, //��Ϣָ�룬getmessage����boolֵ������Ϣ�򷵻���
		NULL, //����Ϣ����ȡ����ϢNULL��ʾ��ȡ������Ϣ��û��ȡ����Ϣ����
		0, //ָʾ��ȡ��һ����Ϣ
		0)) {//ָʾ��ȡ�����һ����Ϣ��ȫΪ0�򲻹���
		TranslateMessage(&msg); //���������Ϣ(�� WM_KEYDONW)ת��Ϊ�ַ���ϢWM_CHAR������
		DispatchMessage(&msg);	// ����Ϣ�ش� OS ���� OS ���ô��ڹ��̺��� WinSunProc �����Ϣ����
	}
	return 0;
}
LRESULT CALLBACK WinSunProc(//����long��
	HWND hwnd,		// handle to window 
	UINT uMsg,	// message identifier
	WPARAM wParam,		// first message parameter ���Ӳ���
	LPARAM lParam	// second message parameter�ڶ�����Ϣ���Ӳ���
	)
{
	switch (uMsg)
	{
	case WM_CHAR: 
		char szChar[40];
		sprintf_s(szChar, "�����°� %c", wParam); //��ʽ���ı����ڴ�
		strcat_s(szChar,strlen(szChar)+strlen(" Ҳ���Ǹ�����")+1, " Ҳ���Ǹ�����");
		MessageBox(hwnd, szChar, "����", 0); 
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, "���������Ǹ�����", "����", 0); 
		HDC lhdc;
		lhdc = GetDC(hwnd);
		TextOut(lhdc, 0, 50, "��˵�����Ǹ�����", strlen("��˵�����Ǹ�����")); 
		ReleaseDC(hwnd, lhdc);
		break;
	case WM_RBUTTONDOWN:
		MessageBox(hwnd, "�㰴�Ҽ�Ҳ�Ǹ�����", "����", 0);
		HDC rhdc;
		rhdc = GetDC(hwnd);
		TextOut(rhdc, 0, 100, "���ٰ������Ǹ�����", strlen("���ٰ������Ǹ�����"));//hdc+����+�ַ����䳤��
		ReleaseDC(hwnd, rhdc);//�ͷ�
		break;
	case WM_PAINT: 
		HDC hDC;
		PAINTSTRUCT ps;
		hDC = BeginPaint(hwnd, &ps);
		TextOut(hDC, 0, 0, "���Ǹ�����", strlen("���Ǹ�����")); EndPaint(hwnd, &ps);
		break;
	case WM_CLOSE:
		if (IDYES == MessageBox(hwnd, "�����㰴ʲô���Ǹ����ӣ�����ز�����", "����", MB_YESNO))
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