﻿//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PassWord.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TPasswordDlg *PasswordDlg;
//---------------------------------------------------------------------
__fastcall TPasswordDlg::TPasswordDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TPasswordDlg::OKBtnClick(TObject *Sender)
{
Form2->TempSQLQuery->SQL->Add("SELECT * FROM users WHERE PROGRAM='CARSSHOP' AND USER='tahmaz' AND PASSWORD='"+Password->Text+"'");
Form2->TempSQLQuery->Open();

if(Form2->TempSQLQuery->RecordCount==0){
ShowMessage(L"Parol səhvdir");
ack==false;
Form1->Close();
}
else
ack=true;

Form2->TempSQLQuery->Close();

}
//---------------------------------------------------------------------------

void __fastcall TPasswordDlg::CancelBtnClick(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TPasswordDlg::FormClose(TObject *Sender, TCloseAction &Action)
{
if(ack==false)
Form1->Close();
}
//---------------------------------------------------------------------------
