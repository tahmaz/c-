object Form1: TForm1
  Left = 329
  Top = 324
  Width = 706
  Height = 486
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Call'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object TabbedNotebook1: TTabbedNotebook
    Left = 0
    Top = 0
    Width = 698
    Height = 459
    Align = alClient
    PageIndex = 1
    TabFont.Charset = DEFAULT_CHARSET
    TabFont.Color = clBtnText
    TabFont.Height = -11
    TabFont.Name = 'MS Sans Serif'
    TabFont.Style = []
    TabOrder = 0
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Set'
      object Infsplabel: TLabel
        Left = 384
        Top = 408
        Width = 45
        Height = 13
        Caption = 'Infsplabel'
      end
      object Infiplabel: TLabel
        Left = 296
        Top = 408
        Width = 42
        Height = 13
        Caption = 'Infiplabel'
      end
      object GroupBox1: TGroupBox
        Left = 480
        Top = 8
        Width = 201
        Height = 81
        TabOrder = 0
        object Label4: TLabel
          Left = 40
          Top = 16
          Width = 44
          Height = 20
          Caption = 'User:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object PasswordLabel: TLabel
          Left = 8
          Top = 48
          Width = 83
          Height = 20
          Caption = 'Password:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object User: TEdit
          Left = 96
          Top = 16
          Width = 89
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          Text = 'tehmaz'
        end
        object Password: TEdit
          Left = 96
          Top = 48
          Width = 89
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          PasswordChar = '#'
          TabOrder = 1
          Text = 'tehmaz08'
        end
      end
      object GroupBox2: TGroupBox
        Left = 480
        Top = 96
        Width = 201
        Height = 129
        TabOrder = 1
        object Label1: TLabel
          Left = 39
          Top = 24
          Width = 23
          Height = 20
          Caption = 'IP:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label2: TLabel
          Left = 9
          Top = 56
          Width = 53
          Height = 20
          Caption = 'PORT:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label3: TLabel
          Left = 32
          Top = 88
          Width = 30
          Height = 20
          Caption = 'NE:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Ip: TEdit
          Left = 80
          Top = 24
          Width = 105
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          Text = '172.17.10.1'
        end
        object Port: TEdit
          Left = 80
          Top = 56
          Width = 105
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
          Text = '52200'
        end
        object Ne: TComboBox
          Left = 80
          Top = 88
          Width = 105
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          ParentFont = False
          TabOrder = 2
        end
      end
      object Callmemo: TMemo
        Left = 0
        Top = 8
        Width = 289
        Height = 297
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        Lines.Strings = (
          '')
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 2
      end
      object NeDBGrid: TDBGrid
        Left = 480
        Top = 232
        Width = 201
        Height = 113
        DataSource = NeDataSource
        TabOrder = 3
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
      object Callbuf: TMemo
        Left = 0
        Top = 304
        Width = 289
        Height = 65
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        Lines.Strings = (
          'Callbuf')
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 4
      end
      object NeEdit: TEdit
        Left = 480
        Top = 352
        Width = 145
        Height = 21
        CharCase = ecUpperCase
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
      end
      object Add: TButton
        Left = 512
        Top = 384
        Width = 57
        Height = 17
        Caption = 'Add'
        TabOrder = 6
        OnClick = AddClick
      end
      object Delete: TButton
        Left = 584
        Top = 384
        Width = 57
        Height = 17
        Caption = 'Delete'
        TabOrder = 7
        OnClick = DeleteClick
      end
      object Update: TButton
        Left = 624
        Top = 400
        Width = 49
        Height = 17
        Caption = 'Update'
        TabOrder = 8
        Visible = False
        OnClick = UpdateClick
      end
      object StartStop: TPanel
        Left = 104
        Top = 400
        Width = 89
        Height = 25
        Cursor = crHandPoint
        Caption = 'Start'
        TabOrder = 9
        OnClick = StartStopClick
      end
      object Infipmemo: TMemo
        Left = 296
        Top = 8
        Width = 89
        Height = 393
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        Lines.Strings = (
          'Infip')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 10
      end
      object Infspmemo: TMemo
        Left = 384
        Top = 8
        Width = 81
        Height = 393
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        Lines.Strings = (
          'Infsp')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 11
      end
      object Edit1: TEdit
        Left = 0
        Top = 376
        Width = 289
        Height = 22
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
        TabOrder = 12
        OnKeyDown = Edit1KeyDown
      end
      object Son: TPanel
        Left = 440
        Top = 408
        Width = 65
        Height = 17
        Caption = 'Son'
        TabOrder = 13
        Visible = False
        OnClick = SonClick
      end
      object FaylEdit: TEdit
        Left = 624
        Top = 352
        Width = 49
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 14
        Text = 'TTFILE00'
      end
    end
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'History'
      object Label5: TLabel
        Left = 480
        Top = 16
        Width = 66
        Height = 20
        Caption = 'Interval:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label6: TLabel
        Left = 616
        Top = 21
        Width = 51
        Height = 16
        Caption = '(deqiqe)'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label11: TLabel
        Left = 464
        Top = 48
        Width = 80
        Height = 20
        Caption = 'Fayl ferqi:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object CallDBGrid: TDBGrid
        Left = 0
        Top = 8
        Width = 329
        Height = 369
        DataSource = CallDataSource
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit]
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
      object Deletecall: TButton
        Left = 360
        Top = 16
        Width = 73
        Height = 25
        Caption = 'Delete'
        TabOrder = 1
        OnClick = DeletecallClick
      end
      object Deletecallall: TButton
        Left = 360
        Top = 48
        Width = 73
        Height = 25
        Caption = 'Delete All'
        TabOrder = 2
        OnClick = DeletecallallClick
      end
      object Time1: TEdit
        Left = 552
        Top = 16
        Width = 57
        Height = 24
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        Text = '60'
        OnChange = Time1Change
      end
      object GroupBox3: TGroupBox
        Left = 360
        Top = 88
        Width = 313
        Height = 297
        Caption = ' Mail options '
        TabOrder = 4
        object Label7: TLabel
          Left = 112
          Top = 64
          Width = 63
          Height = 20
          Caption = 'UserID:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label8: TLabel
          Left = 128
          Top = 32
          Width = 44
          Height = 20
          Caption = 'Host:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label9: TLabel
          Left = 24
          Top = 136
          Width = 47
          Height = 20
          Caption = 'From:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label10: TLabel
          Left = 40
          Top = 168
          Width = 26
          Height = 20
          Caption = 'To:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Host: TEdit
          Left = 192
          Top = 32
          Width = 89
          Height = 24
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Courier New'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          Text = '191.0.0.32'
        end
        object Userid: TEdit
          Left = 192
          Top = 64
          Width = 89
          Height = 24
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Courier New'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
          Text = 'santral'
        end
        object Send: TPanel
          Left = 192
          Top = 96
          Width = 89
          Height = 25
          Cursor = crHandPoint
          Caption = 'Send'
          TabOrder = 2
          OnClick = SendClick
        end
        object From: TEdit
          Left = 112
          Top = 136
          Width = 177
          Height = 24
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Courier New'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
          Text = 'tetahmaz@azercell.com'
        end
        object To: TEdit
          Left = 112
          Top = 168
          Width = 177
          Height = 24
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Courier New'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 4
          Text = 'BAKUOMCDUTY@AZERCELL.COM'
        end
        object Body: TMemo
          Left = 16
          Top = 200
          Width = 273
          Height = 89
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Courier New'
          Font.Style = [fsBold]
          Lines.Strings = (
            'Body')
          ParentFont = False
          TabOrder = 5
        end
      end
      object Ferq: TEdit
        Left = 552
        Top = 48
        Width = 57
        Height = 24
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        Text = '10'
      end
    end
  end
  object CallDataSource: TDataSource
    DataSet = CallTable
    Left = 152
    Top = 384
  end
  object CallTable: TTable
    Active = True
    TableName = 'Call.db'
    Left = 120
    Top = 384
  end
  object IdTelnet1: TIdTelnet
    OnStatus = IdTelnet1Status
    OnDisconnected = IdTelnet1Disconnected
    OnWork = IdTelnet1Work
    OnWorkBegin = IdTelnet1WorkBegin
    OnWorkEnd = IdTelnet1WorkEnd
    Port = 23
    OnTelnetCommand = IdTelnet1TelnetCommand
    OnDataAvailable = IdTelnet1DataAvailable
    Terminal = 'dumb'
    Left = 88
    Top = 384
  end
  object NeDataSource: TDataSource
    DataSet = NeTable
    Left = 24
    Top = 384
  end
  object NeTable: TTable
    Active = True
    TableName = 'NE.db'
    Left = 56
    Top = 384
  end
  object Timer1: TTimer
    Interval = 1000000
    OnTimer = Timer1Timer
    Left = 192
    Top = 384
  end
  object NMSMTP1: TNMSMTP
    Host = '191.0.0.32'
    Port = 25
    ReportLevel = 0
    OnDisconnect = NMSMTP1Disconnect
    OnConnect = NMSMTP1Connect
    EncodeType = uuMime
    ClearParams = True
    SubType = mtPlain
    Charset = 'us-ascii'
    Left = 232
    Top = 384
  end
  object Timer2: TTimer
    Interval = 800
    OnTimer = Timer2Timer
    Left = 272
    Top = 384
  end
  object Timer3: TTimer
    Enabled = False
    Interval = 5000
    OnTimer = Timer3Timer
    Left = 504
    Top = 208
  end
end
