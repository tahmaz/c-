//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox3Change(TObject *Sender)
{
ComboBox4->Items->Clear();

ComboBox4->Items->Add("");

if(ComboBox3->ItemIndex==1)
{
        ComboBox4->Items->Add("GSM");
        ComboBox4->Items->Add("3G");
        ComboBox4->Items->Add("ALARMS");
}
else if(ComboBox3->ItemIndex==2)
{
        ComboBox4->Items->Add("JAVA");
        ComboBox4->Items->Add("C++");
        ComboBox4->Items->Add("MYSQL");
};
ComboBox4->ItemIndex=0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
ComboBox2->Items->Clear();

ComboBox2->Items->Add("ALL");

if(ComboBox1->ItemIndex==1)
{
        ComboBox2->Items->Add("GSM");
        ComboBox2->Items->Add("3G");
        ComboBox2->Items->Add("ALARMS");
}
else if(ComboBox1->ItemIndex==2)
{
        ComboBox2->Items->Add("JAVA");
        ComboBox2->Items->Add("C++");
        ComboBox2->Items->Add("MYSQL");
}

ComboBox2->ItemIndex=0;
}
//---------------------------------------------------------------------------
