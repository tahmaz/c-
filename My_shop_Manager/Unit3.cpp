//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TPasswordDlg *PasswordDlg;
//---------------------------------------------------------------------
__fastcall TPasswordDlg::TPasswordDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TPasswordDlg::CancelBtnClick(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TPasswordDlg::OKBtnClick(TObject *Sender)
{


Form1->UpdateQuery->SQL->Add("SELECT * FROM program_users WHERE PROGRAM='SHOp_MANAGER' AND USER='TAHMAZ' AND PASSWORD='"+Password->Text+"'");
Form1->UpdateQuery->Open();

if(Form1->UpdateQuery->RecordCount==0){
ShowMessage("Password sehvdir");
Form1->Close();
}

Form1->UpdateQuery->Close();

}
//---------------------------------------------------------------------------
