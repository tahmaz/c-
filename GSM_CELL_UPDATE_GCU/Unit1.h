//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTelnet.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TComboBox *BscComboBox;
        TPanel *RldepPanel;
        TIdTelnet *IdTelnet1;
        TQuery *Query1;
        TDataSource *DataSource1;
        TDatabase *Database1;
        TTimer *Timer1;
        TMemo *ReportMemo;
        TMemo *BufMemo;
        TMemo *Memo3;
        void __fastcall IdTelnet1DataAvailable(AnsiString Buffer);
        void __fastcall IdTelnet1Disconnected(TObject *Sender);
        void __fastcall RldepPanelClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:
bool Giris;
String RLDEP,Komanda,check;
// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
