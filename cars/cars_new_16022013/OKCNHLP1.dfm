inherited OKHelpBottomDlg: TOKHelpBottomDlg
  Caption = 'T'#601'sdiq'
  ClientHeight = 171
  ExplicitWidth = 391
  ExplicitHeight = 206
  PixelsPerInch = 120
  TextHeight = 16
  inherited Bevel1: TBevel
    Height = 95
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Visible = False
    ExplicitHeight = 95
  end
  object Label1: TLabel [1]
    Left = 57
    Top = 38
    Width = 279
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Qeydi silm'#601'y'#601' '#601'minsinizmi?'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  inherited OKBtn: TButton
    Left = 86
    Top = 126
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Caption = 'B'#601'li'
    OnClick = OKBtnClick
    ExplicitLeft = 86
    ExplicitTop = 126
  end
  inherited CancelBtn: TButton
    Left = 204
    Top = 126
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Caption = 'Xeyir'
    OnClick = CancelBtnClick
    ExplicitLeft = 204
    ExplicitTop = 126
  end
  object HelpBtn: TButton
    Left = 292
    Top = 132
    Width = 92
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '&Help'
    TabOrder = 2
    Visible = False
    OnClick = HelpBtnClick
  end
end
