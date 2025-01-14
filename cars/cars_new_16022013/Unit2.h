//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RpDefine.hpp"
#include "RpRave.hpp"
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <DBGrids.hpp>
#include <DBXMySql.hpp>
#include <FMTBcd.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
#include <WideStrings.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet2;
	TGroupBox *GroupBox2;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label26;
	TLabel *Label29;
	TLabel *QiymetLabel;
	TLabel *Label36;
	TLabel *Label37;
	TComboBox *MarkaTekComboBox;
	TComboBox *ModelTekComboBox;
	TComboBox *MuherrikTekComboBox;
	TEdit *QiymetTekEdit;
	TMemo *OzellikTekMemo;
	TEdit *QalFaizEdit;
	TEdit *QalQiymetEdit;
	TButton *EsascalcButton;
	TEdit *EnFaizEdit;
	TEdit *EnQiymetEdit;
	TEdit *TeklifEdit;
	TEdit *MusteriEdit;
	TGroupBox *GroupBox4;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label22;
	TLabel *Label14;
	TLabel *Label17;
	TLabel *Label31;
	TLabel *Label30;
	TLabel *Label32;
	TLabel *Label34;
	TLabel *Label35;
	TLabel *Label33;
	TComboBox *KodTekComboBox;
	TComboBox *QrupTekComboBox;
	TComboBox *AltqrupTekComboBox;
	TComboBox *AdTekComboBox;
	TEdit *QiymetTekElaveEdit;
	TStringGrid *ElaveStringGrid;
	TButton *Button1;
	TButton *Button2;
	TEdit *ElaveFaizEdit;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TEdit *ElaveQiymetfaizliEdit;
	TEdit *ElqalfaizEdit;
	TEdit *ElqalQiymetEdit;
	TEdit *ElenfaizEdit;
	TEdit *ElenQiymetEdit;
	TEdit *ElaveQiymetEdit;
	TEdit *UmumiqiymetEdit;
	TButton *ElavecalcButton;
	TButton *Button3;
	TTabSheet *TabSheet1;
	TGroupBox *GroupBox1;
	TDBGrid *DBGrid1;
	TGroupBox *GroupBox5;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TButton *AddButton;
	TButton *DeleteButton;
	TComboBox *MarkaComboBox;
	TComboBox *ModelComboBox;
	TComboBox *MuherrikComboBox;
	TMemo *OzellikMemo;
	TEdit *QiymetEdit;
	TGroupBox *GroupBox3;
	TDBGrid *DBGrid2;
	TGroupBox *GroupBox6;
	TLabel *Label18;
	TLabel *Label23;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label24;
	TLabel *Label25;
	TComboBox *AdElaveComboBox;
	TEdit *QiymetElaveEdit;
	TComboBox *KodElaveComboBox;
	TComboBox *QrupElaveComboBox;
	TComboBox *AltqrupElaveComboBox;
	TButton *AddElaveButton;
	TButton *DeleteElaveButton;
	TComboBox *MarkaElaveComboBox;
	TComboBox *ModelElaveComboBox;
	TCheckBox *FilterElaveCheckBox;
	TSQLConnection *SQLConnection1;
	TSQLQuery *EsasSQLQuery;
	TDataSetProvider *EsasDataSetProvider;
	TDataSetProvider *ElaveDataSetProvider;
	TSQLQuery *ElaveSQLQuery;
	TSQLQuery *TempSQLQuery;
	TClientDataSet *ElaveClientDataSet;
	TClientDataSet *EsasClientDataSet;
	TDataSource *EsasDataSource;
	TDataSource *ElaveDataSource;
	TRvProject *RvProject1;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *FileOpenItem;
	TMenuItem *FileSaveItem;
	TMenuItem *N1;
	TMenuItem *FileExitItem;
	TMenuItem *Help1;
	TMenuItem *HelpAboutItem;
	TLabel *Label27;
	TComboBox *BanTekComboBox;
	TDateTimePicker *DateTimePicker1;
	TLabel *Label28;
	TLabel *Label38;
	TLabel *Label39;
	TComboBox *IlComboBox;
	TComboBox *BanComboBox;
	TComboBox *IlTekComboBox;
	TLabel *Label40;
	TGroupBox *GroupBox7;
	TCheckBox *CheckBox3;
	TButton *Button4;
	TSQLQuery *ArchiveSQLQuery;
	TDataSetProvider *ArchiveDataSetProvider;
	TClientDataSet *ArchiveClientDataSet;
	TDataSource *ArchiveDataSource;
	TButton *Button5;
	TMenuItem *Arxiv1;
	TMenuItem *Arxivpncrsi1;
	TButton *Button6;
	TButton *Button7;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FileExitItemClick(TObject *Sender);
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall DeleteButtonClick(TObject *Sender);
	void __fastcall AddElaveButtonClick(TObject *Sender);
	void __fastcall DeleteElaveButtonClick(TObject *Sender);
	void __fastcall DBGrid2DblClick(TObject *Sender);
	void __fastcall MarkaComboBoxChange(TObject *Sender);
	void __fastcall ModelComboBoxChange(TObject *Sender);
	void __fastcall MuherrikComboBoxChange(TObject *Sender);
	void __fastcall MarkaElaveComboBoxChange(TObject *Sender);
	void __fastcall ModelElaveComboBoxChange(TObject *Sender);
	void __fastcall KodElaveComboBoxChange(TObject *Sender);
	void __fastcall QrupElaveComboBoxChange(TObject *Sender);
	void __fastcall AltqrupElaveComboBoxChange(TObject *Sender);
	void __fastcall AdElaveComboBoxChange(TObject *Sender);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall BanComboBoxChange(TObject *Sender);
	void __fastcall IlComboBoxChange(TObject *Sender);
	void __fastcall MarkaTekComboBoxChange(TObject *Sender);
	void __fastcall ModelTekComboBoxChange(TObject *Sender);
	void __fastcall MuherrikTekComboBoxChange(TObject *Sender);
	void __fastcall BanTekComboBoxChange(TObject *Sender);
	void __fastcall IlTekComboBoxChange(TObject *Sender);
	void __fastcall KodTekComboBoxChange(TObject *Sender);
	void __fastcall QrupTekComboBoxChange(TObject *Sender);
	void __fastcall AltqrupTekComboBoxChange(TObject *Sender);
	void __fastcall AdTekComboBoxChange(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall EsascalcButtonClick(TObject *Sender);
	void __fastcall ElavecalcButtonClick(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall ElaveFaizEditChange(TObject *Sender);
	void __fastcall Arxivpncrsi1Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall FileOpenItemClick(TObject *Sender);
	void __fastcall FileSaveItemClick(TObject *Sender);
	void __fastcall QalFaizEditChange(TObject *Sender);
	void __fastcall EnFaizEditChange(TObject *Sender);
	void __fastcall ElqalfaizEditChange(TObject *Sender);
	void __fastcall ElenfaizEditChange(TObject *Sender);
	void __fastcall HelpAboutItemClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	bool tesdiq;
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
