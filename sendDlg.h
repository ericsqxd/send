// sendDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_SENDDLG_H__3D0EA283_2E07_47FA_A695_190AD6F64B81__INCLUDED_)
#define AFX_SENDDLG_H__3D0EA283_2E07_47FA_A695_190AD6F64B81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSendDlg dialog

class CSendDlg : public CDialog
{
// Construction
public:
	CSendDlg(CWnd* pParent = NULL);	// standard constructor
	int String2Hex(CString str, CByteArray &senddate);
	char ConvertHexChar(char ch);
	CString ConvertCstr(int value,int n);
// Dialog Data
	//{{AFX_DATA(CSendDlg)
	enum { IDD = IDD_SEND_DIALOG };
	CStatic	m_staticsendnum;
	CComboBox	m_ParityCheck_M;
	CComboBox	m_StopBit_M;
	CComboBox	m_Date_Select_M;
	CComboBox	m_BaudRate_M;
	CComboBox	m_ComboBox;
	CString	m_beat;
	CString	m_height;
	CString	m_id;
	CString	m_latd;
	CString	m_lgtd;
	CString	m_shou;
	CString	m_shu;
	CString	m_temperature;
	CMSComm	m_ctrlComm;
	int		m_Index;
	int		m_BaudRate;
	int		m_Date_Select;
	int		m_ParityCheck;
	int		m_StopBit;
	CString	m_lgtdfen;
	CString	m_lgtdmiao;
	CString	m_latdfen;
	CString	m_latdmiao;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	int m_sendnum;
	CByteArray hexdatagv,hexdatazj;
	CString strtemp;

	// Generated message map functions
	//{{AFX_MSG(CSendDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnButton1();
	afx_msg void OnSelchangeCOMBOBaudRateSelect();
	afx_msg void OnSelchangeCOMBOCommSelect();
	afx_msg void OnSelchangeCOMBODateSelect();
	afx_msg void OnSelchangeCOMBOParityCheck();
	afx_msg void OnSelchangeCOMBOStopBit();
	afx_msg void OnButtonzijian();
	afx_msg void OnButtongonglv();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDDLG_H__3D0EA283_2E07_47FA_A695_190AD6F64B81__INCLUDED_)
