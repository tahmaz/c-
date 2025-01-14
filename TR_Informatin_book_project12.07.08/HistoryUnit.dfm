object Form6: TForm6
  Left = 409
  Top = 171
  Width = 430
  Height = 354
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
  object TabbedNotebook1: TTabbedNotebook
    Left = 0
    Top = 0
    Width = 422
    Height = 327
    Align = alClient
    TabFont.Charset = DEFAULT_CHARSET
    TabFont.Color = clBtnText
    TabFont.Height = -11
    TabFont.Name = 'MS Sans Serif'
    TabFont.Style = []
    TabOrder = 0
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Add'
      object Label1: TLabel
        Left = 8
        Top = 16
        Width = 31
        Height = 16
        Caption = 'Job:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label2: TLabel
        Left = 0
        Top = 48
        Width = 40
        Height = 16
        Caption = 'Time:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object CurrentLabel: TLabel
        Left = 120
        Top = 45
        Width = 5
        Height = 16
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object JobEdit: TEdit
        Left = 48
        Top = 8
        Width = 361
        Height = 21
        CharCase = ecUpperCase
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
      end
      object NoteMemo: TMemo
        Left = 0
        Top = 72
        Width = 409
        Height = 201
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object AddButton: TButton
        Left = 160
        Top = 280
        Width = 89
        Height = 17
        Caption = 'Add'
        TabOrder = 3
        OnClick = AddButtonClick
      end
      object TimeEdit: TMaskEdit
        Left = 48
        Top = 40
        Width = 57
        Height = 21
        EditMask = '!90:00;1;_'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ImeMode = imHanguel
        MaxLength = 5
        ParentFont = False
        TabOrder = 1
        Text = '  :  '
      end
    end
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'History'
      object DBGrid1: TDBGrid
        Left = 0
        Top = 8
        Width = 409
        Height = 153
        DataSource = DataSource1
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
      object DBMemo1: TDBMemo
        Left = 0
        Top = 160
        Width = 409
        Height = 105
        DataField = 'Note'
        DataSource = DataSource1
        ScrollBars = ssBoth
        TabOrder = 1
        OnDblClick = DBMemo1DblClick
      end
      object DeleteButton: TButton
        Left = 352
        Top = 273
        Width = 57
        Height = 19
        Caption = 'Delete'
        TabOrder = 2
        OnClick = DeleteButtonClick
      end
      object Button1: TButton
        Left = 7
        Top = 272
        Width = 66
        Height = 21
        Caption = 'Report'
        TabOrder = 3
        OnClick = Button1Click
      end
      object HDateTimePicker: TDateTimePicker
        Left = 80
        Top = 272
        Width = 81
        Height = 21
        CalAlignment = dtaLeft
        Date = 39170.5498337963
        Time = 39170.5498337963
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 4
      end
    end
  end
  object DataSource1: TDataSource
    DataSet = HistoryTable
    Left = 16
    Top = 264
  end
  object HistoryTable: TTable
    Active = True
    TableName = 'DiaryHistory.db'
    Left = 56
    Top = 264
  end
end
