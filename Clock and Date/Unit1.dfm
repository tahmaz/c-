object Form1: TForm1
  Left = 463
  Top = 124
  Width = 287
  Height = 185
  Caption = 'Time and Date'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 0
    Width = 279
    Height = 37
    Align = alTop
    Caption = 'Time'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 0
    Top = 121
    Width = 279
    Height = 37
    Align = alBottom
    Caption = 'Date'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object DBText1: TDBText
    Left = 0
    Top = 40
    Width = 225
    Height = 33
    DataField = 'OCCUR_DATE'
    DataSource = DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object DBText2: TDBText
    Left = 0
    Top = 80
    Width = 225
    Height = 41
    DataField = 'ceasing_date'
    DataSource = DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 192
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 232
    Top = 48
  end
  object Database1: TDatabase
    AliasName = 'MySqlDatabase'
    Connected = True
    DatabaseName = 'Mybase'
    LoginPrompt = False
    Params.Strings = (
      'Password=some_pass'
      'USER NAME=monty')
    SessionName = 'Default'
    Left = 232
    Top = 8
  end
  object Query1: TQuery
    Active = True
    DatabaseName = 'Mybase'
    SQL.Strings = (
      'select * from kesinti where cell LIKE '#39'%'#39)
    Left = 232
    Top = 88
  end
end
