//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HistoryUnit.h"
#include "DiaryUnit.h"
#include "ReadUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::AddButtonClick(TObject *Sender)
{
Form5->DiaryTable->Insert();
Form5->DiaryTable->FieldByName("Job")->AsString=JobEdit->Text;
Form5->DiaryTable->FieldByName("Time")->AsDateTime=FormatDateTime("hh:mm",StrToTime(TimeEdit->Text));
Form5->DiaryTable->FieldByName("Note")->AsString=NoteMemo->Text;
Form5->DiaryTable->Post();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::DeleteButtonClick(TObject *Sender)
{
if(!HistoryTable->Eof)
HistoryTable->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::DBMemo1DblClick(TObject *Sender)
{
Form3->ReadMemo->Clear();
Form3->ReadMemo->Text=DBMemo1->Text;
Form3->Show();        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button1Click(TObject *Sender)
{
Form3->ReadMemo->Clear();
Form3->ReadMemo->Lines->Add("!!!!!!!!!!!!!! "+StrToDateTime(HDateTimePicker->Date.DateString())+" !!!!!!!!!!!!!!");
for(int a=1;a<HistoryTable->RecordCount+1;a++)
{
HistoryTable->RecNo=a;
if(StrToDateTime(HDateTimePicker->Date.DateString())==HistoryTable->FieldByName("Date")->AsDateTime)
 {
 Form3->ReadMemo->Font->Color=clBlue;
 Form3->ReadMemo->Lines->Add("!!!!!!!!!!!!!! "+HistoryTable->FieldByName("Job")->AsString+"   "+HistoryTable->FieldByName("Time")->AsString+" !!!!!!!!!!!!!!");
 Form3->ReadMemo->Font->Color=clBlack;
 Form3->ReadMemo->Lines->Add(HistoryTable->FieldByName("Note")->AsString);
 Form3->ReadMemo->Lines->Add("");
 }
}

if(Form3->ReadMemo->Lines->Count<=2)
Form3->ReadMemo->Lines->Add("Secilen gun ucun melumat yoxdur!");

Form3->Show();
}
//---------------------------------------------------------------------------


