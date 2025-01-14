object Form1: TForm1
  Left = 275
  Top = 110
  Width = 917
  Height = 775
  Caption = 'RBS Faults'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  WindowState = wsMaximized
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar1: TStatusBar
    Left = 0
    Top = 704
    Width = 909
    Height = 25
    Panels = <>
    SimplePanel = False
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 599
    Width = 909
    Height = 105
    Align = alBottom
    TabOrder = 0
    object GroupBox1: TGroupBox
      Left = 2
      Top = 15
      Width = 215
      Height = 88
      Align = alLeft
      Caption = ' Search '
      TabOrder = 0
      object Edit1: TEdit
        Left = 16
        Top = 32
        Width = 185
        Height = 21
        TabOrder = 0
        OnChange = Edit1Change
      end
    end
    object GroupBox3: TGroupBox
      Left = 217
      Top = 15
      Width = 690
      Height = 88
      Align = alClient
      Caption = 'Report'
      TabOrder = 1
      object ReportMemo: TMemo
        Left = 2
        Top = 15
        Width = 686
        Height = 71
        Align = alClient
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
  end
  object BtsinternalListBox: TListBox
    Left = 344
    Top = 24
    Width = 233
    Height = 265
    ItemHeight = 13
    TabOrder = 1
    Visible = False
  end
  object StartButton: TButton
    Left = 56
    Top = 64
    Width = 57
    Height = 25
    Caption = 'Start'
    TabOrder = 2
    Visible = False
    OnClick = StartButtonClick
  end
  object StopButton: TButton
    Left = 56
    Top = 88
    Width = 57
    Height = 25
    Caption = 'Stop'
    TabOrder = 3
    Visible = False
    OnClick = StopButtonClick
  end
  object FinishButton: TButton
    Left = 56
    Top = 40
    Width = 57
    Height = 25
    Caption = 'Finish'
    TabOrder = 5
    Visible = False
    OnClick = FinishButtonClick
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 909
    Height = 599
    Align = alClient
    TabOrder = 6
    object NeListBox: TListBox
      Left = 1
      Top = 513
      Width = 113
      Height = 85
      Align = alLeft
      Enabled = False
      ItemHeight = 13
      TabOrder = 0
    end
    object BufMemo: TMemo
      Left = 114
      Top = 513
      Width = 794
      Height = 85
      Align = alClient
      Color = clMenuText
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'Courier New'
      Font.Style = []
      ParentFont = False
      ScrollBars = ssBoth
      TabOrder = 1
    end
    object DBGrid1: TDBGrid
      Left = 1
      Top = 1
      Width = 907
      Height = 512
      Align = alTop
      Ctl3D = True
      DataSource = DataSource2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
      ParentCtl3D = False
      ParentFont = False
      PopupMenu = PopupMenu1
      TabOrder = 2
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
    end
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 600
    object File1: TMenuItem
      Caption = 'File'
      object Exit1: TMenuItem
        Caption = 'Exit'
        OnClick = Exit1Click
      end
    end
    object Update1: TMenuItem
      Caption = 'Update'
      object Updatenow: TMenuItem
        Caption = 'Update now'
        OnClick = UpdatenowClick
      end
      object Stopupdate: TMenuItem
        Caption = 'Stop update'
        Enabled = False
        OnClick = StopupdateClick
      end
      object ResetUpdatetimer1: TMenuItem
        Caption = 'Reset Update timer'
        OnClick = ResetUpdatetimer1Click
      end
    end
    object Export1: TMenuItem
      Caption = 'Export'
      object Exporttoexcel1: TMenuItem
        Caption = 'Export to excel'
        OnClick = Exporttoexcel1Click
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      object About1: TMenuItem
        Caption = 'About'
        OnClick = About1Click
      end
    end
  end
  object UpdateDataSource: TDataSource
    DataSet = UpdateQuery
    Left = 848
    Top = 48
  end
  object DataSource2: TDataSource
    DataSet = Query2
    Left = 848
    Top = 88
  end
  object UpdateQuery: TQuery
    DatabaseName = 'MySqlDatabase'
    Left = 816
    Top = 48
  end
  object Query2: TQuery
    Active = True
    DatabaseName = 'MySqlDatabase'
    SQL.Strings = (
      
        'select BSC,SITE,MO,Fault_code,Repunit,CONVERT(DATE_FORMAT(ALARM_' +
        'DATE, '#39'%d.%m.%Y'#39'),CHAR(10)) AS ALARM_DATE,CONVERT(DATE_FORMAT(AL' +
        'ARM_TIME, '#39'%H:%i'#39'),CHAR(5)) AS ALARM_TIME,Description,CONVERT(DA' +
        'TE_FORMAT(Update_datetime,'#39'%d.%m.%y %H:%i'#39'),CHAR(16)) AS Update_' +
        'datetime from btsinternals')
    Left = 816
    Top = 88
  end
  object Database1: TDatabase
    Connected = True
    DatabaseName = 'MySqlDatabase'
    LoginPrompt = False
    Params.Strings = (
      'DATABASE NAME=santral'
      'USER NAME=monty'
      'ODBC DSN=MyOdbc'
      'OPEN MODE=READ/WRITE'
      'BATCH COUNT=200'
      'LANGDRIVER='
      'MAX ROWS=-1'
      'SCHEMA CACHE DIR='
      'SCHEMA CACHE SIZE=8'
      'SCHEMA CACHE TIME=-1'
      'SQLPASSTHRU MODE=SHARED AUTOCOMMIT'
      'SQLQRYMODE='
      'ENABLE SCHEMA CACHE=FALSE'
      'ENABLE BCD=FALSE'
      'ROWSET SIZE=20'
      'BLOBS TO CACHE=256'
      'BLOB SIZE=32'
      'PASSWORD=some_pass')
    SessionName = 'Default'
    Left = 848
    Top = 128
  end
  object IdTelnet1: TIdTelnet
    OnDisconnected = IdTelnet1Disconnected
    RecvBufferSize = 65536
    SendBufferSize = 65536
    Host = '172.17.10.1'
    Port = 52200
    OnDataAvailable = IdTelnet1DataAvailable
    Terminal = 'dumb'
    Left = 816
    Top = 8
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 10000
    OnTimer = Timer1Timer
    Left = 776
    Top = 8
  end
  object PopupMenu1: TPopupMenu
    Left = 40
    Top = 600
    object Refresh1: TMenuItem
      Caption = 'Refresh'
      OnClick = Refresh1Click
    end
  end
  object UpdaterequestTimer: TTimer
    Interval = 10800000
    OnTimer = UpdaterequestTimerTimer
    Left = 720
    Top = 8
  end
end
