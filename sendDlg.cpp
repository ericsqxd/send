// sendDlg.cpp : implementation file
//

#include "stdafx.h"
#include "send.h"
#include "sendDlg.h"

#include <math.h>
#include <cstdlib>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendDlg dialog

CSendDlg::CSendDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendDlg)
	m_beat = _T("80");
	m_height = _T("120");
	m_id = _T("1");
	m_latd = _T("32");
	m_lgtd = _T("118");
	m_shou = _T("80");
	m_shu = _T("120");
	m_temperature = _T("36.8");
	m_Index = -1;
	m_BaudRate = -1;
	m_Date_Select = -1;
	m_ParityCheck = -1;
	m_StopBit = -1;
	m_lgtdfen = _T("48");
	m_lgtdmiao = _T("38");
	m_latdfen = _T("01");
	m_latdmiao = _T("39");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendDlg)
	DDX_Control(pDX, IDC_STATIC_SENDNUM, m_staticsendnum);
	DDX_Control(pDX, IDC_COMBO_ParityCheck, m_ParityCheck_M);
	DDX_Control(pDX, IDC_COMBO_StopBit, m_StopBit_M);
	DDX_Control(pDX, IDC_COMBO_Date_Select, m_Date_Select_M);
	DDX_Control(pDX, IDC_COMBO_BaudRate_Select, m_BaudRate_M);
	DDX_Control(pDX, IDC_COMBO_CommSelect, m_ComboBox);
	DDX_Text(pDX, IDC_EDIT_BEAT, m_beat);
	DDX_Text(pDX, IDC_EDIT_HEIGHT, m_height);
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDX_Text(pDX, IDC_EDIT_LATD, m_latd);
	DDX_Text(pDX, IDC_EDIT_LGTD, m_lgtd);
	DDX_Text(pDX, IDC_EDIT_SHOU, m_shou);
	DDX_Text(pDX, IDC_EDIT_SHU, m_shu);
	DDX_Text(pDX, IDC_EDIT_TEMP, m_temperature);
	DDX_Control(pDX, IDC_MSCOMM1, m_ctrlComm);
	DDX_CBIndex(pDX, IDC_COMBO_CommSelect, m_Index);
	DDX_CBIndex(pDX, IDC_COMBO_BaudRate_Select, m_BaudRate);
	DDX_CBIndex(pDX, IDC_COMBO_Date_Select, m_Date_Select);
	DDX_CBIndex(pDX, IDC_COMBO_ParityCheck, m_ParityCheck);
	DDX_CBIndex(pDX, IDC_COMBO_StopBit, m_StopBit);
	DDX_Text(pDX, IDC_EDIT_LGTDFEN, m_lgtdfen);
	DDX_Text(pDX, IDC_EDIT_LGTDMIAO, m_lgtdmiao);
	DDX_Text(pDX, IDC_EDIT_LATDFEN, m_latdfen);
	DDX_Text(pDX, IDC_EDIT_LATDMIAO, m_latdmiao);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSendDlg, CDialog)
	//{{AFX_MSG_MAP(CSendDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_SEND, OnSend)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_CBN_SELCHANGE(IDC_COMBO_BaudRate_Select, OnSelchangeCOMBOBaudRateSelect)
	ON_CBN_SELCHANGE(IDC_COMBO_CommSelect, OnSelchangeCOMBOCommSelect)
	ON_CBN_SELCHANGE(IDC_COMBO_Date_Select, OnSelchangeCOMBODateSelect)
	ON_CBN_SELCHANGE(IDC_COMBO_ParityCheck, OnSelchangeCOMBOParityCheck)
	ON_CBN_SELCHANGE(IDC_COMBO_StopBit, OnSelchangeCOMBOStopBit)
	ON_BN_CLICKED(IDC_BUTTON2, OnButtonzijian)
	ON_BN_CLICKED(IDC_BUTTON3, OnButtongonglv)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendDlg message handlers

BOOL CSendDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_ComboBox.SetCurSel(7);//打开软件时串口选择框默认显示COM1
	m_BaudRate_M.SetCurSel(7);//打开软件时波特率选择框默认显示9600
	m_Date_Select_M.SetCurSel(0);//打开软件时数据位选择框默认显示8
	m_StopBit_M.SetCurSel(0);//打开软件时停止位选择框默认显示1
	m_ParityCheck_M.SetCurSel(0);//打开软件时奇偶校验选择框默认显示无校验N
	//下面if语句用于打开默认串口
/************************************************************/
	if(m_ctrlComm.GetPortOpen())
		{
		m_ctrlComm.SetPortOpen(FALSE);//关闭串口
		}		
	m_ctrlComm.SetCommPort(8);//打开软件时默认使用COM1串口
	if(!m_ctrlComm.GetPortOpen())
		{
		m_ctrlComm.SetPortOpen(TRUE);//打开串口
		}		
	else
		{
		AfxMessageBox("cannot open serial port");
		}	
/*************************************************************/				
	m_ctrlComm.SetSettings("57600,n,8,1");//打开软件时端口设置默认为波特率9600，无校验位，8位数据，1位停止位
	m_ctrlComm.SetInputMode(1); //1：表示以二进制方式检取数据
	m_ctrlComm.SetRThreshold(1); //参数1表示每当串口接收缓冲区中有多于或等于1个字符时将引发一个接收数据的OnComm事件
	m_ctrlComm.SetInputLen(0); //设置当前接收区数据长度为0
	m_ctrlComm.GetInput();//先预读缓冲区以清除残留数据
	m_sendnum=0;

	SetDlgItemText(IDC_BUTTON1,"关闭串口");

	CString strzj="245458585800240300146003001400000010110001763026002001270000807850464B00BE";
	String2Hex(strzj,hexdatazj);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSendDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSendDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSendDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSendDlg::OnSend() 
{
	// TODO: Add your control notification handler code here

	CString m_strTXData,strtemp;
	int value;
	if(!m_ctrlComm.GetPortOpen())//判断是否打开串口
		AfxMessageBox("请打开串口");
	else
	{
	UpdateData(TRUE); //读取编辑框内容
	

	//strtemp.Format("%d",value);
	//AfxMessageBox(strtemp);

	value = atoi(m_id);//获取ID
	strtemp = ConvertCstr(value,4);
	m_strTXData+=strtemp;

	value = atoi(m_lgtd);//获取经度
	strtemp = ConvertCstr(value,2);
	m_strTXData+=strtemp;

	value = atoi(m_lgtdfen);
	strtemp = ConvertCstr(value,2);
	m_strTXData+=strtemp;

	value = atoi(m_lgtdmiao);
	strtemp = ConvertCstr(value,2);
	m_strTXData+=strtemp;

	value = 0;
	strtemp = ConvertCstr(value,2);
	m_strTXData+=strtemp;

	value = atoi(m_latd);//获取纬度
	strtemp = ConvertCstr(value,2);
	m_strTXData+=strtemp;

	value = atoi(m_latdfen);
	strtemp = ConvertCstr(value,2);
	m_strTXData+=strtemp;

	value = atoi(m_latdmiao);
	strtemp = ConvertCstr(value,2);
	m_strTXData+=strtemp;

	value = 0;
	strtemp = ConvertCstr(value,2);
	m_strTXData+=strtemp;

	value = atoi(m_height);//获取高度
	strtemp = ConvertCstr(value,4);
	m_strTXData+=strtemp;

	value = atoi(m_shou);//获取收缩压
	strtemp = ConvertCstr(value,2);
	m_strTXData+=strtemp;

	value = atoi(m_shu);//获取舒张压
	strtemp = ConvertCstr(value,2);
	m_strTXData+=strtemp;

	value = atoi(m_temperature);//获取体温
	strtemp = ConvertCstr(value,2);
	m_strTXData+=strtemp;

	value = atoi(m_beat);//获取心跳
	strtemp = ConvertCstr(value,2);
	m_strTXData+=strtemp;

	value = 0;//保留字
	strtemp = ConvertCstr(value,2);
	m_strTXData+=strtemp;

	m_strTXData+="BE";
	//m_strTXData=m_id+m_lgtd+m_lgtdfen+m_lgtdmiao+m_latd+m_latdfen+m_latdmiao+m_height+m_beat+m_shou+m_shu+m_temperature;

	CByteArray hexdata;
	CString head="24545858580024030014600300140000001000";//添加帧头
	head+=m_strTXData;
	String2Hex(head,hexdata);

	m_ctrlComm.SetOutput(COleVariant(hexdata));

	m_sendnum+=37;
	strtemp.Format("%d",m_sendnum);
	m_staticsendnum.SetWindowText(strtemp);
	//m_ctrlComm.SetOutput(COleVariant(m_strTXData));
	}
}

CString CSendDlg::ConvertCstr(int value,int n)
{
	char temp[10],i;
	int chu;
	CString str;
	for(i=0;i<n;i++)
	{
		chu = pow(16,n-1-i);
		temp[i]=value/chu;
		if(temp[i]>=0&&temp[i]<=9)
			temp[i]=value/chu+'0';
		else
			temp[i]=value/chu+'7';
		value = value%chu;

		//str.Format("%d",temp[i]);
		//AfxMessageBox(str);
	}
	temp[i]='\0';
	str.Format(temp);
	//AfxMessageBox(str);
	return str;
}


void CSendDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
if(m_Index<0)//串口的默认值没有改变	
		{
					
			switch(m_ctrlComm.GetPortOpen())//点击打开或关闭串口按键时，根据当前串口是否打开进行相应操作
			{
			case 1:	/**************************************************************
					关闭串口前先将自动发送功能关闭
					***************************************************************/
					/**************************************************************/
				
					//当前串口是打开的则进行关串口操作
					m_ctrlComm.SetPortOpen(FALSE);//关闭串口
					SetDlgItemText(IDC_BUTTON1,"打开串口");//更改按键指示
					UpdateData(FALSE);//更新按键状态
					break;
			case 0://当前串口是关闭的则进行开串口操作
					m_ctrlComm.SetCommPort(1);//如果要打开串口则应先选择哪个串口
					m_ctrlComm.SetPortOpen(TRUE);//打开串口
					SetDlgItemText(IDC_BUTTON1,"关闭串口");//更改按键指示
					UpdateData(FALSE);
					break;
			default : AfxMessageBox("cannot open or close serial port");	
			}
		}
	else//串口的默认值有改变
		{
		switch(m_ctrlComm.GetPortOpen())//点击打开或关闭串口按键时，根据当前串口是否打开进行相应操作
			{
			case 0://当前串口是关闭的则进行开串口操作	
					m_ctrlComm.SetCommPort(m_Index+1);//如果要打开串口则应先选择哪个串口
					m_ctrlComm.SetPortOpen(TRUE);//打开串口
					SetDlgItemText(IDC_BUTTON1,"关闭串口");//更改按键指示					
					UpdateData(FALSE);//更新按键状态
					break;
			case 1: /**************************************************************
					关闭串口前先将自动发送功能关闭
					***************************************************************/

					/**************************************************************/
				
					//当前串口是打开的则进行关串口操作					
					m_ctrlComm.SetPortOpen(FALSE);
					SetDlgItemText(IDC_BUTTON1,"打开串口");					
					UpdateData(FALSE);
					break;
			default : AfxMessageBox("cannot open serial port");
			}
		}
if(m_Index<0)
((CComboBox*)GetDlgItem(IDC_COMBO_CommSelect))->SetCurSel(1);//如果没有另外进行串口选择则显示COM1
if(m_BaudRate<0)
((CComboBox*)GetDlgItem(IDC_COMBO_BaudRate_Select))->SetCurSel(5);//如果没有另外进行波特率选择则显示9600
if(m_Date_Select<0)
((CComboBox*)GetDlgItem(IDC_COMBO_Date_Select))->SetCurSel(0);////如果没有另外进行数据位选择则显示8
if(m_StopBit<0)
((CComboBox*)GetDlgItem(IDC_COMBO_StopBit))->SetCurSel(0);//如果没有另外进行停止位选择则显示1
if(m_ParityCheck<0)
((CComboBox*)GetDlgItem(IDC_COMBO_ParityCheck))->SetCurSel(0);//如果没有另外进行校验位选择则显示没有校验位N

}

void CSendDlg::OnSelchangeCOMBOBaudRateSelect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_BaudRate=((CComboBox*)GetDlgItem(IDC_COMBO_BaudRate_Select))->GetCurSel();//当前选中的行	
////***********************************************************/
///根据当前选中的值进行波特率设置
///************************************************************/
	switch(m_BaudRate)
	{	
	case 1: m_ctrlComm.SetSettings("1200,,,");
	break;
	case 2: m_ctrlComm.SetSettings("2400,,,");
	break;
	case 3: m_ctrlComm.SetSettings("4800,,,");
	break;
	case 4: m_ctrlComm.SetSettings("9600,,,");
	break;
	case 5: m_ctrlComm.SetSettings("14400,,,");
	break;
	case 6: m_ctrlComm.SetSettings("19200,,,");
	break;
	case 7: m_ctrlComm.SetSettings("38400,,,");
	break;
	case 8: m_ctrlComm.SetSettings("57600,,,");
	break;
	default:m_ctrlComm.SetSettings("9600,,,");
	break;
	}
//*************************************************////
UpdateData(false);
	
}

void CSendDlg::OnSelchangeCOMBOCommSelect() 
{
	// TODO: Add your control notification handler code here
	m_Index=((CComboBox*)GetDlgItem(IDC_COMBO_CommSelect))->GetCurSel();//当前选中的行
	((CComboBox*)GetDlgItem(IDC_COMBO_CommSelect))->SetCurSel(m_Index);//设置当前选中的行的内容为显示的内容
	if(m_ctrlComm.GetPortOpen())//当要改变时则要先关闭串口才可以用按键进行打开，所以先判断当前串口是否打开
		{//如果是打开的则先关闭
		m_ctrlComm.SetPortOpen(FALSE);//关闭串口
		}		
	SetDlgItemText(IDC_BUTTON1,"打开串口");//将打开或关才按钮改为"打开串口"显示状态
		
}

void CSendDlg::OnSelchangeCOMBODateSelect() 
{
	// TODO: Add your control notification handler code here
UpdateData(true);
	m_Date_Select=((CComboBox*)GetDlgItem(IDC_COMBO_Date_Select))->GetCurSel();//当前选中的行
	
///*******************************************************************************/

///********************************************************************************/
switch(m_Date_Select)
	{
	case 1: m_ctrlComm.SetSettings(",,7,");
	break;
	case 2: m_ctrlComm.SetSettings(",,6,");
	break;
	case 3: m_ctrlComm.SetSettings(",,5,");
	break;
	case 4: m_ctrlComm.SetSettings(",,4,");
	break;
	default:m_ctrlComm.SetSettings(",,8,");
	break;
	
	}
//*********************************************************************************//
	UpdateData(false);
	
}

void CSendDlg::OnSelchangeCOMBOParityCheck() 
{
	// TODO: Add your control notification handler code here
UpdateData(true);
	m_ParityCheck=((CComboBox*)GetDlgItem(IDC_COMBO_ParityCheck))->GetCurSel();//当前选中的行
	
///*******************************************************************************/

///********************************************************************************/
switch(m_ParityCheck)
	{
	case 1: m_ctrlComm.SetSettings(",O,,");
	break;
	case 2: m_ctrlComm.SetSettings(",O,,");
	break;
	default:m_ctrlComm.SetSettings(",N,,");
	break;
	
	}
//*********************************************************************************//
	UpdateData(false);
	
}

void CSendDlg::OnSelchangeCOMBOStopBit() 
{
	// TODO: Add your control notification handler code here
UpdateData(true);
	m_StopBit=((CComboBox*)GetDlgItem(IDC_COMBO_StopBit))->GetCurSel();//当前选中的行
	
///*******************************************************************************/

///********************************************************************************/
switch(m_StopBit)
	{
	case 1: m_ctrlComm.SetSettings(",,,2");
	break;
	default:m_ctrlComm.SetSettings(",,,1");
	break;
	}
//*********************************************************************************//
UpdateData(false);
	
}

int CSendDlg::String2Hex(CString str, CByteArray &senddate)
{
	int hexdate,lowhexdate;
	int hexdatelen=0;
	int len=str.GetLength();
	senddate.SetSize(len/2);
	for(int i=0;i<len;)
		{
			char lstr,hstr=str[i];
			if(hstr==' ')
			{
			i++;
			continue;
			}
			i++;
			if(i>=len)
				break;
			lstr=str[i];
			hexdate=ConvertHexChar(hstr);
			lowhexdate=ConvertHexChar(lstr);
			if((hexdate==16)||(lowhexdate==16))
				break;
			else
				hexdate=hexdate*16+lowhexdate;
			i++;
			senddate[hexdatelen]=(char)hexdate;
			hexdatelen++;

		}
	senddate.SetSize(hexdatelen);
	return hexdatelen;

}

char CSendDlg::ConvertHexChar(char ch)
{	
	if((ch>='0')&&(ch<='9'))
		{
		return ch-0x30;
		}
	else if((ch>='A')&&(ch<='F'))
		{
		
		return ch-'A'+10;	
		}
	else if((ch>='a')&&(ch<='f'))
		{
		return ch-'a'+10;	
		}
	else 
		return (-1);
}

void CSendDlg::OnButtonzijian() 
{
	// TODO: Add your control notification handler code here
	m_ctrlComm.SetOutput(COleVariant(hexdatazj));

	m_sendnum+=37;
	strtemp.Format("%d",m_sendnum);
	m_staticsendnum.SetWindowText(strtemp);
}

void CSendDlg::OnButtongonglv() 
{
	// TODO: Add your control notification handler code here
	int i;
	char a[21];
	for(i=0;i<19;i+=2)
	{
		a[i]='0';
		a[i+1]=rand()%5+'0';
	}
	a[20]='\0';
	
	CString strgv="24474C5A4B0015030014";	//010203040002000402023A
	strgv+=a;
	strgv+="3A";

	String2Hex(strgv,hexdatagv);

	m_ctrlComm.SetOutput(COleVariant(hexdatagv));

	m_sendnum+=21;
	strtemp.Format("%d",m_sendnum);
	m_staticsendnum.SetWindowText(strtemp);
}
