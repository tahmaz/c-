//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SelectAlarm.h"
#include "Unit3.h"
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
void __fastcall TForm5::SpeedButton1Click(TObject *Sender)
{
if(ListBox1->Items->Count!=0){
ListBox2->Items->Add(ListBox1->Items->Strings[ListBox1->ItemIndex]);
ListBox1->DeleteSelected();
}
}
//---------------------------------------------------------------------------
void __fastcall TForm5::SpeedButton2Click(TObject *Sender)
{
if(ListBox2->Items->Count!=0){
ListBox1->Items->Add(ListBox2->Items->Strings[ListBox2->ItemIndex]);
ListBox2->DeleteSelected();
}
}
//---------------------------------------------------------------------------
