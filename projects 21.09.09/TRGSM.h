//---------------------------------------------------------------------------

#ifndef TRGSMH
#define TRGSMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include "Excel_2K_SRVR.h"
#include <OleServer.hpp>
#include "WinSkinForm.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *new1;
        TMenuItem *Open1;
        TMenuItem *Edit1;
        TSaveDialog *SaveDialog1;
        TMemo *Memo1;
        TOpenDialog *OpenDialog1;
        TButton *Button3;
        TMenuItem *CreatData1;
        TMenuItem *Saveas1;
        TMenuItem *Workwithsystem1;
        TMenuItem *Exit1;
        TButton *Button1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TGroupBox *GroupBox1;
        TMemo *Memo2;
        TWinSkinForm *WinSkinForm1;
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall CreatData1Click(TObject *Sender);
        void __fastcall Open1Click(TObject *Sender);
        void __fastcall Saveas1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall Memo1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Memo1KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
