object Form1: TForm1
  Left = 192
  Top = 232
  AutoScroll = False
  Caption = 'Cell Data'
  ClientHeight = 615
  ClientWidth = 868
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 868
    Height = 615
    ActivePage = TabSheet1
    Align = alClient
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Data'
      object GroupBox1: TGroupBox
        Left = 0
        Top = 546
        Width = 860
        Height = 41
        Align = alBottom
        TabOrder = 1
        object Button1: TButton
          Left = 440
          Top = 16
          Width = 73
          Height = 17
          Caption = 'Save as'
          TabOrder = 1
          OnClick = Button1Click
        end
        object Button3: TButton
          Left = 360
          Top = 16
          Width = 73
          Height = 17
          Caption = 'Back'
          TabOrder = 0
          OnClick = Button3Click
        end
      end
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 860
        Height = 546
        Align = alClient
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
        WantTabs = True
        OnKeyDown = Memo1KeyDown
        OnKeyUp = Memo1KeyUp
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Report'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 860
        Height = 587
        Align = alClient
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 776
    object File1: TMenuItem
      Caption = 'File'
      object new1: TMenuItem
        Caption = 'New'
        object CreatData1: TMenuItem
          Caption = 'Create Data'
          OnClick = CreatData1Click
        end
        object Workwithsystem1: TMenuItem
          Caption = 'Work with system'
        end
      end
      object Open1: TMenuItem
        Caption = 'Open'
        OnClick = Open1Click
      end
      object Saveas1: TMenuItem
        Caption = 'Save as..'
        OnClick = Saveas1Click
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
        OnClick = Exit1Click
      end
    end
    object Edit1: TMenuItem
      Caption = 'Edit'
    end
  end
  object SaveDialog1: TSaveDialog
    Filter = '.txt'
    Left = 752
    Top = 576
  end
  object OpenDialog1: TOpenDialog
    Left = 720
    Top = 576
  end
  object WinSkinForm1: TWinSkinForm
    DisableTag = 99
    SkinData = MainForm.SkinData1
    SkinControls = [xcMainMenu, xcPopupMenu, xcToolbar, xcControlbar, xcCombo, xcCheckBox, xcRadioButton, xcProgress, xcScrollbar, xcEdit, xcButton, xcBitBtn, xcSpeedButton, xcPanel, xcGroupBox, xcStatusBar, xcTab]
    Left = 736
  end
end
