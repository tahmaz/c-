//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
if(!Form1->CellQuery->Eof){
        if(Form1->QueryGl->Active==true)
        Form1->QueryGl->Close();
        Form1->QueryGl->SQL->Clear();
        Form1->QueryGl->SQL->Text="delete from cells where id='"+Form1->CellQuery->FieldByName("id")->AsString+"'  order by cell";
        Form1->QueryGl->ExecSQL();

        Form1->CellQuery->Close();
        Form1->CellQuery->Open();

        Form1->CellsQuery->Close();
        Form1->CellsQuery->Open();

        if(Form1->Site_Search_Edit->Text!="")
        Form1->Site_Search_EditChange(Form1->Site_Search_Edit);
        else if(Form1->Cell_Search_Edit->Text!="")
        Form1->Cell_Search_EditChange(Form1->Cell_Search_Edit);
}

if(Form1->CellQuery->Eof)
Form5->Close();

}
//---------------------------------------------------------------------------
