object Form1: TForm1
  Left = 193
  Top = 118
  Width = 999
  Height = 867
  Caption = 'My Shop Manager'
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
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 991
    Height = 821
    ActivePage = TabSheet2
    Align = alClient
    TabIndex = 1
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Shops'
      object GroupBox1: TGroupBox
        Left = 0
        Top = 512
        Width = 983
        Height = 281
        Align = alBottom
        TabOrder = 0
        object DBText1: TDBText
          Left = 96
          Top = 16
          Width = 65
          Height = 17
          DataField = 'id'
          Visible = False
        end
        object Label1: TLabel
          Left = 40
          Top = 44
          Width = 40
          Height = 13
          Caption = 'Number:'
        end
        object Label2: TLabel
          Left = 66
          Top = 16
          Width = 14
          Height = 13
          Caption = 'ID:'
          Visible = False
        end
        object Label3: TLabel
          Left = 53
          Top = 76
          Width = 27
          Height = 13
          Caption = 'Type:'
        end
        object Label4: TLabel
          Left = 49
          Top = 108
          Width = 31
          Height = 13
          Caption = 'Name:'
        end
        object Label5: TLabel
          Left = 62
          Top = 140
          Width = 18
          Height = 13
          Caption = 'NE:'
        end
        object Label6: TLabel
          Left = 67
          Top = 172
          Width = 13
          Height = 13
          Caption = 'IP:'
        end
        object Label7: TLabel
          Left = 54
          Top = 204
          Width = 26
          Height = 13
          Caption = 'IP_A:'
        end
        object Label8: TLabel
          Left = 54
          Top = 236
          Width = 26
          Height = 13
          Caption = 'IP_B:'
        end
        object Label9: TLabel
          Left = 472
          Top = 44
          Width = 22
          Height = 13
          Caption = 'Port:'
        end
        object Label10: TLabel
          Left = 469
          Top = 76
          Width = 25
          Height = 13
          Caption = 'User:'
        end
        object Label11: TLabel
          Left = 445
          Top = 108
          Width = 49
          Height = 13
          Caption = 'Password:'
        end
        object Label12: TLabel
          Left = 450
          Top = 140
          Width = 44
          Height = 13
          Caption = 'Location:'
        end
        object Label13: TLabel
          Left = 468
          Top = 172
          Width = 26
          Height = 13
          Caption = 'Note:'
        end
        object Edit2: TEdit
          Left = 96
          Top = 72
          Width = 241
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 0
        end
        object Edit3: TEdit
          Left = 96
          Top = 104
          Width = 241
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 1
        end
        object Edit4: TEdit
          Left = 96
          Top = 136
          Width = 241
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 2
        end
        object Edit5: TEdit
          Left = 96
          Top = 168
          Width = 241
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 3
        end
        object Edit6: TEdit
          Left = 96
          Top = 200
          Width = 241
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 4
        end
        object Edit7: TEdit
          Left = 96
          Top = 232
          Width = 241
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 5
        end
        object Edit8: TEdit
          Left = 512
          Top = 40
          Width = 241
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 6
        end
        object Edit9: TEdit
          Left = 512
          Top = 72
          Width = 241
          Height = 21
          TabOrder = 7
        end
        object Edit10: TEdit
          Left = 512
          Top = 104
          Width = 241
          Height = 21
          TabOrder = 8
        end
        object Edit12: TEdit
          Left = 512
          Top = 168
          Width = 241
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 9
        end
        object Button1: TButton
          Left = 512
          Top = 232
          Width = 73
          Height = 25
          Caption = 'Add'
          TabOrder = 10
          OnClick = Button1Click
        end
        object Button3: TButton
          Left = 592
          Top = 232
          Width = 65
          Height = 25
          Caption = 'Delete'
          TabOrder = 11
          OnClick = Button3Click
        end
        object ComboBox1: TComboBox
          Left = 512
          Top = 136
          Width = 241
          Height = 21
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 12
          Text = 'BAKI'
          Items.Strings = (
            'BAKI'
            'SUMQAYIT'
            'SHIRVAN'
            'GENCE'
            'NAXCHIVAN')
        end
        object Edit1: TEdit
          Left = 96
          Top = 40
          Width = 241
          Height = 21
          TabOrder = 13
        end
      end
      object TntDBGrid2: TTntDBGrid
        Left = 0
        Top = 0
        Width = 983
        Height = 512
        Align = alClient
        DataSource = ShopDataSource
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
        TabOrder = 1
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Products'
      ImageIndex = 1
      object GroupBox2: TGroupBox
        Left = 0
        Top = 352
        Width = 983
        Height = 441
        Align = alBottom
        TabOrder = 0
        object Label14: TLabel
          Left = 544
          Top = 8
          Width = 96
          Height = 13
          Caption = 'Product Description:'
        end
        object Label15: TLabel
          Left = 544
          Top = 200
          Width = 111
          Height = 13
          Caption = 'Product characteristics:'
        end
        object Label16: TLabel
          Left = 16
          Top = 16
          Width = 14
          Height = 13
          Caption = 'ID:'
        end
        object Label17: TLabel
          Left = 16
          Top = 36
          Width = 31
          Height = 13
          Caption = 'Name:'
        end
        object Label18: TLabel
          Left = 16
          Top = 60
          Width = 32
          Height = 13
          Caption = 'Model:'
        end
        object Label19: TLabel
          Left = 16
          Top = 84
          Width = 52
          Height = 13
          Caption = 'MagazaID:'
        end
        object Label20: TLabel
          Left = 16
          Top = 108
          Width = 41
          Height = 13
          Caption = 'Magaza:'
        end
        object Label21: TLabel
          Left = 16
          Top = 132
          Width = 34
          Height = 13
          Caption = 'LinkID:'
        end
        object Label22: TLabel
          Left = 16
          Top = 156
          Width = 28
          Height = 13
          Caption = 'Brend'
        end
        object Label23: TLabel
          Left = 16
          Top = 180
          Width = 27
          Height = 13
          Caption = 'Type:'
        end
        object Label24: TLabel
          Left = 16
          Top = 204
          Width = 38
          Height = 13
          Caption = 'Image1:'
        end
        object Label25: TLabel
          Left = 16
          Top = 228
          Width = 38
          Height = 13
          Caption = 'Image2:'
        end
        object Label26: TLabel
          Left = 16
          Top = 252
          Width = 38
          Height = 13
          Caption = 'Image3:'
        end
        object Label27: TLabel
          Left = 16
          Top = 276
          Width = 38
          Height = 13
          Caption = 'Image4:'
        end
        object Label28: TLabel
          Left = 16
          Top = 300
          Width = 38
          Height = 13
          Caption = 'Image5:'
        end
        object Label29: TLabel
          Left = 16
          Top = 324
          Width = 27
          Height = 13
          Caption = 'Price:'
        end
        object Label30: TLabel
          Left = 16
          Top = 348
          Width = 26
          Height = 13
          Caption = 'Note:'
        end
        object Label31: TLabel
          Left = 96
          Top = 16
          Width = 3
          Height = 13
        end
        object TntDBText1: TTntDBText
          Left = 96
          Top = 82
          Width = 153
          Height = 17
          DataField = 'ID'
          DataSource = ShopDataSource
        end
        object TntDBText2: TTntDBText
          Left = 96
          Top = 106
          Width = 153
          Height = 17
          DataField = 'NAME'
          DataSource = ShopDataSource
        end
        object TntMemo1: TTntMemo
          Left = 544
          Top = 24
          Width = 409
          Height = 169
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Arial Unicode MS'
          Font.Style = []
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
        end
        object TntMemo2: TTntMemo
          Left = 544
          Top = 216
          Width = 409
          Height = 169
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Arial Unicode MS'
          Font.Style = []
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 1
        end
        object Edit11: TEdit
          Left = 96
          Top = 32
          Width = 153
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 2
        end
        object Edit13: TEdit
          Left = 96
          Top = 56
          Width = 153
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 3
        end
        object Edit16: TEdit
          Left = 96
          Top = 128
          Width = 153
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 4
        end
        object Edit17: TEdit
          Left = 96
          Top = 152
          Width = 153
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 5
        end
        object Edit18: TEdit
          Left = 96
          Top = 176
          Width = 153
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 6
        end
        object Edit19: TEdit
          Left = 96
          Top = 200
          Width = 153
          Height = 21
          TabOrder = 7
        end
        object Edit20: TEdit
          Left = 96
          Top = 224
          Width = 153
          Height = 21
          TabOrder = 8
        end
        object Edit21: TEdit
          Left = 96
          Top = 248
          Width = 153
          Height = 21
          TabOrder = 9
        end
        object Edit22: TEdit
          Left = 96
          Top = 272
          Width = 153
          Height = 21
          TabOrder = 10
        end
        object Edit23: TEdit
          Left = 96
          Top = 296
          Width = 153
          Height = 21
          TabOrder = 11
        end
        object Edit24: TEdit
          Left = 96
          Top = 320
          Width = 153
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 12
        end
        object Edit25: TEdit
          Left = 96
          Top = 344
          Width = 153
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 13
        end
        object GroupBox3: TGroupBox
          Left = 2
          Top = 382
          Width = 979
          Height = 57
          Align = alBottom
          TabOrder = 14
          object Button2: TButton
            Left = 24
            Top = 16
            Width = 81
            Height = 25
            Caption = 'Add'
            TabOrder = 0
            OnClick = Button2Click
          end
          object Button4: TButton
            Left = 120
            Top = 16
            Width = 81
            Height = 25
            Caption = 'Delete'
            TabOrder = 1
            OnClick = Button4Click
          end
          object Button5: TButton
            Left = 216
            Top = 16
            Width = 81
            Height = 25
            Caption = 'Update'
            TabOrder = 2
          end
        end
        object Button6: TButton
          Left = 264
          Top = 96
          Width = 97
          Height = 25
          Caption = 'Select Shop'
          TabOrder = 15
          OnClick = Button6Click
        end
        object Button7: TButton
          Left = 264
          Top = 198
          Width = 97
          Height = 25
          Caption = 'Select Image1'
          TabOrder = 16
        end
        object Button8: TButton
          Left = 264
          Top = 222
          Width = 97
          Height = 25
          Caption = 'Select Image2'
          TabOrder = 17
        end
        object Button9: TButton
          Left = 264
          Top = 246
          Width = 97
          Height = 25
          Caption = 'Select Image3'
          TabOrder = 18
        end
        object Button10: TButton
          Left = 264
          Top = 270
          Width = 97
          Height = 25
          Caption = 'Select Image4'
          TabOrder = 19
        end
        object Button11: TButton
          Left = 264
          Top = 294
          Width = 97
          Height = 25
          Caption = 'Select Image5'
          TabOrder = 20
        end
      end
      object TntDBGrid1: TTntDBGrid
        Left = 0
        Top = 0
        Width = 983
        Height = 352
        Align = alClient
        DataSource = DataSource1
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial Unicode MS'
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
        OnCellClick = TntDBGrid1CellClick
      end
    end
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
  object MyConnection1: TMyConnection
    Database = 'base'
    Options.UseUnicode = True
    Options.Charset = 'utf8'
    Username = 'monty'
    Password = 'some_pass'
    Server = 'so-m'
    Connected = True
    LoginPrompt = False
    Left = 864
    Top = 560
  end
  object PrQuery: TMyQuery
    SQLInsert.Strings = (
      'INSERT INTO products'
      
        '  (NAME, MODEL, MAGAZAID, MAGAZA, LINKID, PRFIRM, TYPE, IMAGE1, ' +
        'IMAGE2, IMAGE3, IMAGE4, IMAGE5, PRICE, INFO, CHARA, NOTE)'
      'VALUES'
      
        '  (:NAME, :MODEL, :MAGAZAID, :MAGAZA, :LINKID, :PRFIRM, :TYPE, :' +
        'IMAGE1, :IMAGE2, :IMAGE3, :IMAGE4, :IMAGE5, :PRICE, :INFO, :CHAR' +
        'A, :NOTE)')
    SQLDelete.Strings = (
      'DELETE FROM products'
      'WHERE'
      '  ID= :ID')
    SQLUpdate.Strings = (
      'UPDATE products'
      'SET'
      
        '  NAME = :NAME, MODEL = :MODEL, MAGAZAID = :MAGAZAID, MAGAZA = :' +
        'MAGAZA, LINKID = :LINKID, PRFIRM = :PRFIRM, TYPE = :TYPE, IMAGE1' +
        ' = :IMAGE1, IMAGE2 = :IMAGE2, IMAGE3 = :IMAGE3, IMAGE4 = :IMAGE4' +
        ', IMAGE5 = :IMAGE5, PRICE = :PRICE, INFO = :INFO, CHARA = :CHARA' +
        ', NOTE = :NOTE'
      'WHERE'
      '  ID = :ID')
    SQLRefresh.Strings = (
      'select * from products')
    Connection = MyConnection1
    SQL.Strings = (
      'select * from products')
    Active = True
    Left = 792
    Top = 72
  end
  object PrDataSource: TMyDataSource
    DataSet = PrQuery
    Left = 752
    Top = 72
  end
  object UpdateDataSource: TMyDataSource
    DataSet = UpdateQuery
    Left = 752
    Top = 112
  end
  object ShopDataSource: TMyDataSource
    DataSet = ShopQuery
    Left = 752
    Top = 32
  end
  object ShopQuery: TMyQuery
    Connection = MyConnection1
    SQL.Strings = (
      'select * from shops')
    Active = True
    Left = 792
    Top = 32
  end
  object UpdateQuery: TMyQuery
    Connection = MyConnection1
    Left = 792
    Top = 112
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;User ID=monty;Dat' +
      'a Source=MyBaseOdbc;Initial Catalog=base'
    LoginPrompt = False
    Left = 752
    Top = 240
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from products')
    Left = 792
    Top = 200
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 752
    Top = 200
  end
end
