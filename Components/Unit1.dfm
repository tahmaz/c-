object Form1: TForm1
  Left = 240
  Top = 224
  Width = 870
  Height = 668
  Caption = 'Components'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 0
    Top = 57
    Width = 449
    Height = 447
    Align = alLeft
    DataSource = DataSource1
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
    Columns = <
      item
        Expanded = False
        FieldName = 'NAME'
        Width = 193
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'TYPE'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'COUNT'
        Visible = True
      end>
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 504
    Width = 862
    Height = 118
    Align = alBottom
    TabOrder = 1
    object DBText1: TDBText
      Left = 32
      Top = 19
      Width = 25
      Height = 15
      DataField = 'id'
      DataSource = DataSource1
      Visible = False
    end
    object Label2: TLabel
      Left = 10
      Top = 20
      Width = 14
      Height = 13
      Caption = 'ID:'
      Visible = False
    end
    object Label4: TLabel
      Left = 65
      Top = 20
      Width = 31
      Height = 13
      Caption = 'Name:'
    end
    object Label5: TLabel
      Left = 65
      Top = 84
      Width = 31
      Height = 13
      Caption = 'Count:'
    end
    object Label6: TLabel
      Left = 412
      Top = 20
      Width = 44
      Height = 13
      Caption = 'Location:'
    end
    object Label7: TLabel
      Left = 433
      Top = 52
      Width = 23
      Height = 13
      Caption = 'Link:'
    end
    object Label12: TLabel
      Left = 69
      Top = 52
      Width = 27
      Height = 13
      Caption = 'Type:'
    end
    object Edit3: TEdit
      Left = 112
      Top = 16
      Width = 241
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 0
    end
    object Edit4: TEdit
      Left = 112
      Top = 80
      Width = 241
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 1
      Text = '0'
    end
    object Edit5: TEdit
      Left = 472
      Top = 16
      Width = 241
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 2
    end
    object Edit6: TEdit
      Left = 472
      Top = 48
      Width = 241
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 3
    end
    object Button1: TButton
      Left = 472
      Top = 80
      Width = 73
      Height = 25
      Caption = 'Add'
      TabOrder = 4
      OnClick = Button1Click
    end
    object Button3: TButton
      Left = 640
      Top = 80
      Width = 73
      Height = 25
      Caption = 'Delete'
      TabOrder = 5
      OnClick = Button3Click
    end
    object ComboBox1: TComboBox
      Left = 112
      Top = 48
      Width = 241
      Height = 21
      ItemHeight = 13
      TabOrder = 6
      Items.Strings = (
        ''
        'TRANSISTOR')
    end
    object Button2: TButton
      Left = 544
      Top = 80
      Width = 73
      Height = 25
      Caption = 'Update'
      TabOrder = 7
      OnClick = Button2Click
    end
    object UpDown1: TUpDown
      Left = 353
      Top = 80
      Width = 15
      Height = 21
      Associate = Edit4
      Min = 0
      Position = 0
      TabOrder = 8
      Wrap = False
    end
  end
  object Memo1: TMemo
    Left = 449
    Top = 57
    Width = 413
    Height = 447
    Align = alClient
    ScrollBars = ssBoth
    TabOrder = 2
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 0
    Width = 862
    Height = 57
    Align = alTop
    Caption = ' Search '
    TabOrder = 3
    object Label1: TLabel
      Left = 573
      Top = 28
      Width = 27
      Height = 13
      Caption = 'Type:'
    end
    object Edit1: TEdit
      Left = 24
      Top = 24
      Width = 241
      Height = 21
      TabOrder = 0
      OnChange = Edit1Change
    end
    object ComboBox2: TComboBox
      Left = 608
      Top = 24
      Width = 241
      Height = 21
      ItemHeight = 13
      TabOrder = 1
      OnChange = ComboBox2Change
      Items.Strings = (
        ''
        'TRANSISTOR')
    end
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 752
    Top = 48
  end
  object DataSource2: TDataSource
    DataSet = Query2
    Left = 752
    Top = 88
  end
  object Query1: TQuery
    Active = True
    DatabaseName = 'MySqlDatabase'
    SQL.Strings = (
      'SELECT * FROM COMPONENTS')
    Left = 792
    Top = 56
  end
  object Database1: TDatabase
    Connected = True
    DatabaseName = 'MySqlDatabase'
    LoginPrompt = False
    Params.Strings = (
      'DATABASE NAME=test'
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
      'BLOBS TO CACHE=64'
      'BLOB SIZE=32'
      'PASSWORD=some_pass')
    SessionName = 'Default'
    Left = 816
    Top = 560
  end
  object Query2: TQuery
    DatabaseName = 'MySqlDatabase'
    Left = 792
    Top = 88
  end
  object MainMenu1: TMainMenu
    Left = 776
    Top = 560
    object File1: TMenuItem
      Caption = 'File'
      object Close1: TMenuItem
        Caption = 'Close'
        OnClick = Close1Click
      end
    end
    object About1: TMenuItem
      Caption = 'About'
      OnClick = About1Click
    end
  end
end
