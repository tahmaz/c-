object PropertiesForm: TPropertiesForm
  Left = 241
  Top = 272
  Width = 272
  Height = 234
  Caption = 'Properties'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 16
    Top = 8
    Width = 233
    Height = 89
    TabOrder = 0
    object Label1: TLabel
      Left = 64
      Top = 24
      Width = 32
      Height = 16
      Caption = 'User:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 40
      Top = 56
      Width = 63
      Height = 16
      Caption = 'Password:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object UserEdit: TEdit
      Left = 120
      Top = 24
      Width = 97
      Height = 21
      TabOrder = 0
      Text = 'tehmaz'
    end
    object PasswordEdit: TMaskEdit
      Left = 120
      Top = 56
      Width = 97
      Height = 21
      PasswordChar = '#'
      TabOrder = 1
      Text = 'tehmaz08'
    end
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 104
    Width = 233
    Height = 89
    TabOrder = 1
    object Label3: TLabel
      Left = 80
      Top = 24
      Width = 15
      Height = 16
      Caption = 'IP:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 64
      Top = 56
      Width = 27
      Height = 16
      Caption = 'Port:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object IpEdit: TEdit
      Left = 120
      Top = 24
      Width = 97
      Height = 21
      TabOrder = 0
      Text = '172.17.10.1'
    end
    object PortEdit: TEdit
      Left = 120
      Top = 56
      Width = 97
      Height = 21
      TabOrder = 1
      Text = '52200'
    end
  end
end
