object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 553
  ClientWidth = 687
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 48
    Top = 40
    Width = 89
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 48
    Top = 136
    Width = 465
    Height = 353
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object IdSNMP1: TIdSNMP
    OnStatus = IdSNMP1Status
    Active = True
    Host = '10.40.0.1'
    ReceiveTimeout = 5000
    TrapPort = 161
    Community = 'Admin'
    Left = 616
    Top = 48
  end
end