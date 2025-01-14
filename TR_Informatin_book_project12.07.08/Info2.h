//---------------------------------------------------------------------------

#ifndef Info2H
#define Info2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TTable *Table1;
        TDataSource *DataSource1;
        TPanel *Panel1;
        TLabel *Label2;
        TLabel *Label1;
        TEdit *UserEdit;
        TEdit *PasEdit;
        TButton *Enter;
        TPanel *Panel2;
        TDBGrid *DBGrid1;
        TEdit *UseraddEdit;
        TEdit *PasaddEdit;
        TButton *Add;
        TComboBox *EditaddCombo;
        TButton *Button1;
        TButton *EEnterButton;
        TButton *Button2;
        TDBMemo *DBMemo1;
        TDBMemo *DBMemo2;
        void __fastcall EnterClick(TObject *Sender);
        void __fastcall PasEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall AddClick(TObject *Sender);
        void __fastcall EEnterButtonClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
