//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
if(Edit3->Text!=Query1->FieldByName("NAME")->AsString){
   if (Edit4->Text!=Query1->FieldByName("NE")->AsString){
      if(Edit5->Text!=Query1->FieldByName("IP")->AsString){
         if(Edit6->Text!=Query1->FieldByName("IPA")->AsString){
            if(Edit7->Text!=Query1->FieldByName("IPB")->AsString){

                Query2->SQL->Clear();
                Query2->SQL->Add("INSERT INTO nodes (NUMBER,TYPE,NAME,NE,IP,IPA,IPB,PORT,USER,PASSWORD,LOCATION,NOTE) ");
                Query2->SQL->Add("VALUES ('"+Edit1->Text+"','"+Edit2->Text+"','"+Edit3->Text+"','"+Edit4->Text+"','"+Edit5->Text+"','"+Edit6->Text+"','"+Edit7->Text+"','"+Edit8->Text+"','"+Edit9->Text+"','"+Edit10->Text+"','"+ComboBox1->Text+"','"+Edit12->Text+"')");
                Query2->ExecSQL();

                Query1->Close();
                Query1->Open();
            }
            else
            ShowMessage("IP_B artiq movcuddur");
         }
         else
         ShowMessage("IP_A artiq movcuddur");
      }
      else
      ShowMessage("IP artiq movcuddur");
   }
   else
   ShowMessage("NE artiq movcuddur");
}
else
ShowMessage("Name artiq movcuddur");

}
//---------------------------------------------------------------------------
void __fastcall TForm1::DBGrid1CellClick(TColumn *Column)
{
Edit1->Text=Query1->FieldByName("NUMBER")->AsString;
Edit2->Text=Query1->FieldByName("TYPE")->AsString;
Edit3->Text=Query1->FieldByName("NAME")->AsString;
Edit4->Text=Query1->FieldByName("NE")->AsString;
Edit5->Text=Query1->FieldByName("IP")->AsString;
Edit6->Text=Query1->FieldByName("IPA")->AsString;
Edit7->Text=Query1->FieldByName("IPB")->AsString;
Edit8->Text=Query1->FieldByName("PORT")->AsString;
Edit9->Text=Query1->FieldByName("USER")->AsString;
Edit10->Text=Query1->FieldByName("PASSWORD")->AsString;
ComboBox1->Text=Query1->FieldByName("LOCATION")->AsString;
Edit12->Text=Query1->FieldByName("NOTE")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
OKBottomDlg->ShowModal();
if(Delete=="OK"){
 Query2->SQL->Clear();
 Query2->SQL->Add("DELETE FROM nodes WHERE ID='"+DBText1->Caption+"'");
 Query2->ExecSQL();

 Query1->Close();
 Query1->Open();

 Delete="";
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
PasswordDlg->ShowModal();

if(Query2->Active==true)
Query2->Close();
Query2->SQL->Clear();
Query2->SQL->Text="select * from version where PROGRAM_NAME='NODE_MANAGER' and PROGRAM_VERSION='1.1'";
Query2->Open();

 if(Query2->IsEmpty()){
 ShowMessage("Program version is old, please use new version.");
 Form1->Close();
 }
 
Query2->Close();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::About1Click(TObject *Sender)
{
  AboutBox->Show();     
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Close1Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

