//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
if (FileExists("\\\\azercell\\files\\ICT\\CNO\\OMC\\BakuOMC\\Tahmaz\\GSM\\RBSFAULT.bin"))
 {
 AuMemo->Clear();
 AuMemo->Lines->LoadFromFile("\\\\azercell\\files\\ICT\\CNO\\OMC\\BakuOMC\\Tahmaz\\GSM\\RBSFAULT.bin");
    if(AuMemo->Lines->Strings[0]!="VER1.3")// || a.CurrentDate()>StrToDate(MainForm->AuMemo->Lines->Strings[1]))
    Form1->Close();
    else
    {
    AuMemo->Lines->Add("IP:"+Powersock1->LocalIP+" DATE:"+Date()+" TIME:"+Time());
    AuMemo->Lines->SaveToFile("\\\\azercell\\files\\ICT\\CNO\\OMC\\BakuOMC\\Tahmaz\\GSM\\RBSFAULT.bin");
    }
 }
 else
 {
 ShowMessage("Please contact your administrator");
 Form1->Close();
 }
}
//---------------------------------------------------------------------------
