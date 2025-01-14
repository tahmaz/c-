//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <GIFImg.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TListBox *ListBox2;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	TButton *Button1;
	TButton *Button2;
	TGroupBox *GroupBox1;
	TButton *Button3;
	TEdit *Edit3;
	TSaveDialog *SaveDialog1;
	TButton *Button4;
	TImage *Image1;
	TImage *Image2;
	TMemo *Memo1;
	TMemo *Memo2;
	TMemo *TempMemo;
	TGroupBox *GroupBox2;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TPanel *Panel7;
	TPanel *Panel8;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TEdit *PrEdit;
	TLabel *Label3;
	TButton *Button5;
	TButton *Button6;
	TEdit *Edit2;
	TListBox *ListBox3;
	TComboBox *ComboBox1;
	TButton *Button7;
	TLabel *Label4;
	TComboBox *IdComboBox;
	TPanel *Panel9;
	TLabel *Label5;
	TListBox *ListBox4;
	TComboBox *ComboBox2;
	TLabel *Label6;
	TButton *Button8;
	TButton *Button9;
	TListBox *ListBox6;
	TLabel *Label8;
	TButton *Button12;
	TButton *Button13;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Panel1Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Panel9Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Panel2Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Panel4Click(TObject *Sender);
	void __fastcall Panel3Click(TObject *Sender);
	void __fastcall Panel6Click(TObject *Sender);
	void __fastcall Panel5Click(TObject *Sender);
	void __fastcall Panel8Click(TObject *Sender);
	void __fastcall Panel7Click(TObject *Sender);
private:	// User declarations
String Directory;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
