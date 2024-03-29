﻿// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// MainFrame.h: CMainFrame 类的接口
//

#pragma once
#include "ClassView.h"
#include "FileView.h"
#include "OutputWnd.h"
#include "PropertiesWnd.h"

class CMainFrame : public CMDIFrameWndEx {
  DECLARE_DYNAMIC(CMainFrame)
 public:
  CMainFrame() noexcept;

  // 特性
 public:
  bool mBrushUse = false;
  bool mRegularPolygon = false;
  // 操作
 public:
  void ShowPrompt(const CString& str);
  void ShowCoordOnStatusBar(const CString& str);
  // 重写
 public:
  virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

  //获取面板上的属性
  // 图层属性
  int LayerIndex() const;
  //画笔属性
  COLORREF PenColor() const;
  int PenWidth() const;
  int PenStyle() const;
  //画刷属性
  bool UseBrush() const;
  COLORREF BrushColor() const;
  int BrushIndex() const;
  //画线算法
  int LineAlgorithm() const;
  //圆弧算法
  int CircleAlgorithm() const;
  //填充算法
  int FillAlgorithm() const;

  //
  int TimeChose() const;
  //正多边形边数
  int RegularEdges() const;


  //是否勾选正多边形
  bool RegularPolygon() const;
  //边界颜色
  COLORREF BoundColor() const;
  // 内点颜色
  COLORREF FloodColor() const;

  //3D图形绘制模式
  int  threeDStyle() const;
  //焦距距离选择
  int FocalDistance() const;
  //材质选择
  int MaterialSelect() const;

  void FillClassView();
  void UnselectClassView();  //撤销场景树中的选择

  // 实现
 public:
  virtual ~CMainFrame();
#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

 protected:  // 控件条嵌入成员
  CMFCRibbonBar m_wndRibbonBar;
  CMFCRibbonApplicationButton m_MainButton;
  CMFCToolBarImages m_PanelImages;
  CMFCRibbonStatusBar m_wndStatusBar;
  CFileView m_wndFileView;
  CClassView m_wndClassView;
  COutputWnd m_wndOutput;
  CPropertiesWnd m_wndProperties;

  // 生成的消息映射函数
 protected:
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnWindowManager();
  afx_msg void OnApplicationLook(UINT id);
  afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
  afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
  DECLARE_MESSAGE_MAP()

  BOOL CreateDockingWindows();
  void SetDockingWindowIcons(BOOL bHiColorIcons);

 public:
  afx_msg void OnBrushUse();
  afx_msg void OnUpdateBrushUse(CCmdUI* pCmdUI);
  afx_msg void OnRegularPolygon();
  afx_msg void OnUpdateRegularPolygon(CCmdUI* pCmdUI);
  afx_msg void OnViewFileview();
  afx_msg void OnUpdateViewFileview(CCmdUI* pCmdUI);
  afx_msg void OnViewClassview();
  afx_msg void OnUpdateViewClassview(CCmdUI* pCmdUI);
  afx_msg void OnViewPropertieswnd();
  afx_msg void OnUpdateViewPropertieswnd(CCmdUI* pCmdUI);
  afx_msg void OnViewOutputwnd();
  afx_msg void OnUpdateViewOutputwnd(CCmdUI* pCmdUI);
};
