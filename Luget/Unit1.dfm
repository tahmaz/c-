object Form1: TForm1
  Left = 212
  Top = 136
  Width = 576
  Height = 451
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 568
    Height = 424
    ActivePage = TabSheet1
    Align = alClient
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'TabSheet1'
      object GroupBox1: TGroupBox
        Left = 8
        Top = 176
        Width = 545
        Height = 209
        TabOrder = 0
        object Label1: TLabel
          Left = 136
          Top = 144
          Width = 29
          Height = 13
          Caption = 'Word:'
        end
        object Label2: TLabel
          Left = 96
          Top = 176
          Width = 73
          Height = 13
          Caption = 'Voice directory:'
        end
        object Memo1: TMemo
          Left = 8
          Top = 16
          Width = 529
          Height = 105
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
        end
        object Edit1: TEdit
          Left = 176
          Top = 138
          Width = 361
          Height = 21
          TabOrder = 1
        end
        object Button1: TButton
          Left = 8
          Top = 136
          Width = 65
          Height = 25
          Caption = 'Add'
          TabOrder = 2
          OnClick = Button1Click
        end
        object Edit2: TEdit
          Left = 176
          Top = 170
          Width = 305
          Height = 21
          TabOrder = 3
        end
        object Button2: TButton
          Left = 488
          Top = 168
          Width = 49
          Height = 25
          Caption = 'Brouse'
          TabOrder = 4
          OnClick = Button2Click
        end
        object Button3: TButton
          Left = 8
          Top = 168
          Width = 65
          Height = 25
          Caption = 'Delete'
          TabOrder = 5
          OnClick = Button3Click
        end
      end
      object GroupBox2: TGroupBox
        Left = 7
        Top = 0
        Width = 546
        Height = 169
        TabOrder = 1
        object DBMemo1: TDBMemo
          Left = 160
          Top = 8
          Width = 321
          Height = 153
          DataField = 'Translate'
          DataSource = DataSource1
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
        end
        object DBGrid1: TDBGrid
          Left = 8
          Top = 8
          Width = 145
          Height = 153
          DataSource = DataSource1
          TabOrder = 1
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'MS Sans Serif'
          TitleFont.Style = []
          Columns = <
            item
              Expanded = False
              FieldName = 'Number'
              Visible = True
            end>
        end
        object Button4: TButton
          Left = 488
          Top = 16
          Width = 49
          Height = 25
          Caption = 'Voice'
          TabOrder = 2
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'TabSheet2'
      ImageIndex = 1
    end
  end
  object DataSource1: TDataSource
    DataSet = Table1
    Left = 448
    Top = 232
  end
  object Table1: TTable
    Active = True
    DatabaseName = 'Luget'
    TableName = 'Luget.db'
    Left = 480
    Top = 232
  end
  object OpenDialog1: TOpenDialog
    Left = 416
    Top = 232
  end
end
