object Form6: TForm6
  Left = 186
  Top = 269
  Width = 677
  Height = 485
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Form6'
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
    Width = 669
    Height = 458
    ActivePage = TabSheet1
    Align = alClient
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Load confiquration'
      object Label3: TLabel
        Left = 72
        Top = 24
        Width = 37
        Height = 20
        Caption = 'BSC:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 16
        Top = 104
        Width = 72
        Height = 13
        Caption = 'Folder location:'
      end
      object SpeedButton1: TSpeedButton
        Left = 200
        Top = 120
        Width = 65
        Height = 23
        Cursor = crHandPoint
        Caption = 'Browse'
        Font.Charset = ANSI_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          20000000000000040000130B0000130B00000000000000000000000000000000
          0000000000000000000000000000008800FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000008800FF09C724FF008800FFA566443C000000000000
          0000000000000000000000000000000000000000000000000000000000000088
          00FF008800FF008800FF008800FF09C724FF09C724FF008800FF000000000000
          0000000000000000000000000000000000000000000000000000008800FFCCFE
          FEFF09C724FF09C724FF09C724FF09C724FF09C724FF09C724FF008800FFDC69
          30FFDC6930FFDC6930FFDC6930FFDC6930FFDC6930FF1A0A0031008800FFCCFE
          FEFF14D651FF15D651FF15D652FF15D651FF14D651FF14D651FF15D651FF0088
          00FFEFD6D0FFEED4CDFFEBD1CAFFE9D0CAFFEFC3B7FFDC6930FF008800FFCCFE
          FEFF25EB8FFF25EB8FFF24EB90FF24EB90FF25EB90FF24EB90FF24EB90FF0088
          00FFFEFEFEFFFEFEFEFFFAFEFEFFF6FCFEFFF9F0EDFFDC6930FF008800FFCCFE
          FEFFCCFEFEFFCCFEFEFFCCFEFEFF30FABDFF30FABDFF30FABDFF008800FFFEE1
          D5FFFEE0D5FFFEDED5FFFDDBD3FFF3CBC3FEF3B2A3F0DC6930FFA38B84FF0088
          00FF008800FF008800FF008800FF30FABDFF30FABDFF008800FFFE9963FFFE99
          64FFFE9565FFFE9065FFFE8F6AFFEA6D44FAE03000C9DC6930FFA38B84FFFEFE
          FEFFDC6930FFFDDEC9FF008800FF30FABDFF008800FFFD9E69FFFD9B64FFFE9A
          64FFFE9A66FFFE9666FFFE966BFFEA6D44FAE03000C9DC6930FFA38B84FFFEFE
          FEFFDC6930FFFDE4D0FFFBB98BFF008800FFFCAA78FFFDA36FFFFD9B65FFFD9B
          64FFFE9A65FFFE9966FFFE9B6BFFE97344FAE03900C9DC6930FFA38B84FFFEFE
          FEFFDC6930FFFDE3D1FFFCDCC7FFFCD9C3FFFCD6C0FFFCD7C1FFFEB992FFFD9E
          69FFFD9A62FFFE9963FFFE9D69FFE97641FAE13D00C7DC6930FFA38B84FFFEFE
          FEFFECEBECFFDC6930FFDC6930FFDC6930FFDC6930FFDC6930FFFADBCAFFFEDE
          CBFFFED2B9FFFED2B9FFFED3BBFFF6C4ACFDF6B497EDDC6930FFA38B84FFFEFE
          FEFFECEBECFFEEEEF1FFF0F1F4FFF2F4F7FFF3F7FAFFF6F7F9FFDC6930FFDC69
          30FFDC6930FFDC6930FFDC6930FFDC6930FFDC6930FF411D094EA38B84FFFEFE
          FEFFEBE4E2FFEDE6E5FFEFE9E7FFF0EBEAFFF3EEEDFFFEFEFEFFFEFEFEFFFEFE
          FEFFFEFEFEFFFEFEFEFFFEFEFEFFA18177E00B00001700000000A38B84FFFEFE
          FEFFFEFEFEFFFEFEFEFFFEFEFEFFFEFEFEFFFEFAF8FFA38B84FFA38B84FFA38B
          84FFA38B84FFA38B84FFA38B84FF1C11112C00000000000000003A2A274EA38B
          84FFA38B84FFA38B84FFA38B84FFA38B84FFA38B84FF281D1945000000000000
          0000000000000000000000000000000000000000000000000000}
        ParentFont = False
        OnClick = SpeedButton1Click
      end
      object Edit1: TEdit
        Left = 16
        Top = 120
        Width = 169
        Height = 21
        Enabled = False
        TabOrder = 8
      end
      object GroupBox2: TGroupBox
        Left = 8
        Top = 272
        Width = 281
        Height = 153
        TabOrder = 4
        Visible = False
        object Label6: TLabel
          Left = 64
          Top = 125
          Width = 33
          Height = 20
          Caption = 'Port:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label5: TLabel
          Left = 80
          Top = 88
          Width = 19
          Height = 20
          Caption = 'IP:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label2: TLabel
          Left = 32
          Top = 56
          Width = 73
          Height = 20
          Caption = 'Password:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label1: TLabel
          Left = 64
          Top = 24
          Width = 38
          Height = 20
          Caption = 'User:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Port: TEdit
          Left = 120
          Top = 121
          Width = 105
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          Text = '52200'
        end
        object Ip: TEdit
          Left = 120
          Top = 88
          Width = 105
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          Text = '172.17.10.1'
        end
        object Password: TMaskEdit
          Left = 120
          Top = 56
          Width = 105
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          PasswordChar = '*'
          TabOrder = 2
          Text = 'tehmaz08'
        end
        object User: TEdit
          Left = 120
          Top = 24
          Width = 105
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          Text = 'tehmaz'
        end
      end
      object Bsc: TComboBox
        Left = 120
        Top = 24
        Width = 169
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ItemHeight = 16
        ParentFont = False
        TabOrder = 0
        Text = 'BAKBSC1_X29,PROT=V24'
        OnChange = BscChange
        Items.Strings = (
          'BAKBSC1_X29,PROT=V24'
          'BSC3'
          'GENBSC4_X29,PROT=V24'
          'GNBSC4B_X29,PROT=V24'
          'BSC5'
          'BSC6'
          'BSC7'
          'BSC8'
          'BSC9'
          'BSC10'
          'BSC11'
          'BSC12'
          'BSC13'
          'BSC14'
          'BSC15'
          'BSC16'
          'BSC17'
          'BSC18'
          'BSC19'
          'BSC20')
      end
      object CellGroupBox: TGroupBox
        Left = 8
        Top = 84
        Width = 281
        Height = 209
        TabOrder = 1
        object Cell1Label: TLabel
          Left = 40
          Top = 80
          Width = 53
          Height = 20
          Caption = 'CELL1:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Cell2Label: TLabel
          Left = 40
          Top = 112
          Width = 53
          Height = 20
          Caption = 'CELL2:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          Visible = False
        end
        object Cell3Label: TLabel
          Left = 40
          Top = 144
          Width = 53
          Height = 20
          Caption = 'CELL3:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          Visible = False
        end
        object Cell4Label: TLabel
          Left = 40
          Top = 173
          Width = 53
          Height = 20
          Caption = 'CELL4:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          Visible = False
        end
        object Label10: TLabel
          Left = 16
          Top = 24
          Width = 114
          Height = 20
          Caption = 'Sektorlarin Sayi:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Cell4: TEdit
          Left = 112
          Top = 172
          Width = 105
          Height = 24
          CharCase = ecUpperCase
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          MaxLength = 6
          ParentFont = False
          TabOrder = 0
          Visible = False
        end
        object Seksay: TComboBox
          Left = 184
          Top = 20
          Width = 41
          Height = 24
          CharCase = ecUpperCase
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ItemHeight = 16
          ItemIndex = 0
          ParentFont = False
          TabOrder = 1
          Text = '1'
          OnChange = SeksayChange
          Items.Strings = (
            '1'
            '2'
            '3'
            '4')
        end
        object Cell2: TEdit
          Left = 112
          Top = 108
          Width = 105
          Height = 24
          CharCase = ecUpperCase
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          MaxLength = 6
          ParentFont = False
          TabOrder = 2
          Visible = False
        end
        object Cell3: TEdit
          Left = 112
          Top = 140
          Width = 105
          Height = 24
          CharCase = ecUpperCase
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          MaxLength = 6
          ParentFont = False
          TabOrder = 3
          Visible = False
        end
        object Cell1: TEdit
          Left = 112
          Top = 73
          Width = 105
          Height = 24
          CharCase = ecUpperCase
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          MaxLength = 6
          ParentFont = False
          TabOrder = 4
          Text = 'GUNES2'
          OnChange = Cell1Change
        end
      end
      object Panel1: TPanel
        Left = 352
        Top = 380
        Width = 177
        Height = 41
        TabOrder = 2
        object Connect: TButton
          Left = 8
          Top = 8
          Width = 73
          Height = 25
          Caption = 'Start'
          TabOrder = 0
          OnClick = ConnectClick
        end
        object Button5: TButton
          Left = 96
          Top = 8
          Width = 73
          Height = 25
          Caption = 'Stop'
          TabOrder = 1
          OnClick = Button5Click
        end
      end
      object Button1: TButton
        Left = 592
        Top = 388
        Width = 57
        Height = 25
        Caption = 'Close'
        TabOrder = 3
        OnClick = Button1Click
      end
      object CellRadioButton: TRadioButton
        Left = 16
        Top = 78
        Width = 85
        Height = 25
        Caption = 'Selected cell'
        Checked = True
        TabOrder = 5
        TabStop = True
        OnClick = CellRadioButtonClick
      end
      object AllRadioButton: TRadioButton
        Left = 16
        Top = 64
        Width = 73
        Height = 17
        Caption = 'All cells'
        TabOrder = 6
        OnClick = AllRadioButtonClick
      end
      object CellsMemo: TMemo
        Left = 8
        Top = 296
        Width = 121
        Height = 121
        ScrollBars = ssBoth
        TabOrder = 7
        OnDblClick = CellsMemoDblClick
      end
      object Allcellstesdiq: TCheckBox
        Left = 128
        Top = 64
        Width = 129
        Height = 17
        Caption = 'Allcellstesdiq'
        TabOrder = 9
        Visible = False
      end
      object GroupBox1: TGroupBox
        Left = 304
        Top = 0
        Width = 345
        Height = 369
        TabOrder = 10
        object Memo2: TMemo
          Left = 2
          Top = 136
          Width = 341
          Height = 231
          Align = alClient
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Courier New'
          Font.Style = []
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
        end
        object Memo3: TMemo
          Left = 2
          Top = 15
          Width = 341
          Height = 121
          Align = alTop
          ScrollBars = ssBoth
          TabOrder = 1
        end
        object Memo1: TMemo
          Left = 32
          Top = 144
          Width = 145
          Height = 97
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Courier New'
          Font.Style = []
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 2
        end
        object MscBox2: TListBox
          Left = 32
          Top = 24
          Width = 145
          Height = 81
          ItemHeight = 13
          Items.Strings = (
            'MSC1_X29,PROT=V24'
            'NAHSC3_X29,PROT=V24'
            'GENMSC4_X29,PROT=V24'
            'GENMSC4_X29,PROT=V24'
            'MSC5_X29,PROT=V24'
            'MSC6_X29,PROT=V24'
            'MSC7_X29,PROT=V24'
            'MSC8_X29,PROT=V24'
            'MSC9'
            'MSC10'
            'MSC11'
            'MSC12'
            'MSC13'
            'MSCSV2'
            'MSCSV2')
          TabOrder = 3
          Visible = False
        end
      end
    end
  end
  object IdTelnetmsc: TIdTelnet
    OnDisconnected = IdTelnetmscDisconnected
    Port = 23
    OnDataAvailable = IdTelnetmscDataAvailable
    Terminal = 'dumb'
    Left = 560
    Top = 408
  end
  object WinSkinForm1: TWinSkinForm
    DisableTag = 99
    SkinData = MainForm.SkinData1
    SkinControls = [xcMainMenu, xcPopupMenu, xcToolbar, xcControlbar, xcCombo, xcCheckBox, xcRadioButton, xcProgress, xcScrollbar, xcEdit, xcButton, xcBitBtn, xcSpeedButton, xcPanel, xcGroupBox, xcStatusBar, xcTab]
    Left = 528
    Top = 408
  end
end
