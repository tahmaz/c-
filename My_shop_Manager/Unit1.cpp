//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TntStdCtrls"
#pragma link "TntDBGrids"
#pragma link "TntDBCtrls"
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "MyAccess"
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
/*
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
 */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DBGrid1CellClick(TColumn *Column)
{
/*Edit1->Text=Query1->FieldByName("NUMBER")->AsString;
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
Edit12->Text=Query1->FieldByName("NOTE")->AsString;  */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
/*
OKBottomDlg->ShowModal();
if(Delete=="OK"){
 Query2->SQL->Clear();
 Query2->SQL->Add("DELETE FROM PRODUCTS WHERE ID='"+DBText1->Caption+"'");
 Query2->ExecSQL();

 Query1->Close();
 Query1->Open();

 Delete="";
 }   */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
PasswordDlg->ShowModal();

if(UpdateQuery->Active==true)
UpdateQuery->Close();
UpdateQuery->SQL->Clear();
UpdateQuery->SQL->Text="select * from version where PROGRAM_NAME='SHOP_MANAGER' and PROGRAM_VERSION='1.0'";
UpdateQuery->Open();

 if(UpdateQuery->IsEmpty()){
 ShowMessage("Program version is old, please use new version.");
 Form1->Close();
 }
 
UpdateQuery->Close();

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


void __fastcall TForm1::Button2Click(TObject *Sender)
{

                UpdateQuery->SQL->Clear();
                UpdateQuery->SQL->Add("INSERT INTO products (NAME,MODEL,MAGAZAID,MAGAZA,LINKID,BREND,TYPE,IMAGE1,IMAGE2,IMAGE3,IMAGE4,IMAGE5,PRICE,DESCRIPTION,CHARA,NOTE) ");
                UpdateQuery->SQL->Add("VALUES ('"+Edit11->Text+"','"+Edit13->Text+"','"+TntDBText1->Caption+"','"+TntDBText2->Caption+"','"+Edit16->Text+"','"+Edit17->Text+"','"+Edit18->Text+"','"+Edit19->Text+"','"+Edit20->Text+"','"+Edit21->Text+"','"+Edit22->Text+"','"+Edit23->Text+"','"+Edit24->Text+"',:a,:b,'"+Edit25->Text+"')");
                UpdateQuery->Params->ParamByName("a")->AsAnsiString;
                UpdateQuery->Params->ParamByName("a")->Value=TntMemo1->Text;
                UpdateQuery->Params->ParamByName("b")->AsAnsiString;
                UpdateQuery->Params->ParamByName("b")->Value=TntMemo2->Text;
                UpdateQuery->ExecSQL();
                PrQuery->Close();
                PrQuery->Open();


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{

OKBottomDlg->ShowModal();
if(Delete=="OK"){
 UpdateQuery->SQL->Clear();
 UpdateQuery->SQL->Add("DELETE FROM PRODUCTS WHERE ID='"+Label31->Caption+"'");
 UpdateQuery->ExecSQL();

 PrQuery->Close();
 PrQuery->Open();

 Delete="";
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TntDBGrid1CellClick(TColumn *Column)
{
Label31->Caption=ADOQuery1->FieldByName("ID")->AsString;
Edit11->Text=ADOQuery1->FieldByName("NAME")->AsString;
Edit13->Text=ADOQuery1->FieldByName("MODEL")->AsString;
TntDBText1->Caption=ADOQuery1->FieldByName("MAGAZAID")->AsString;
TntDBText2->Caption=ADOQuery1->FieldByName("MAGAZA")->AsString;
Edit16->Text=ADOQuery1->FieldByName("LINKID")->AsString;
Edit17->Text=ADOQuery1->FieldByName("BREND")->AsString;
Edit18->Text=ADOQuery1->FieldByName("TYPE")->AsString;
Edit19->Text=ADOQuery1->FieldByName("IMAGE1")->AsString;
Edit20->Text=ADOQuery1->FieldByName("IMAGE2")->AsString;
Edit21->Text=ADOQuery1->FieldByName("IMAGE3")->AsString;
Edit22->Text=ADOQuery1->FieldByName("IMAGE4")->AsString;
Edit23->Text=ADOQuery1->FieldByName("IMAGE5")->AsString;
Edit24->Text=ADOQuery1->FieldByName("PRICE")->AsString;
Edit25->Text=ADOQuery1->FieldByName("NOTE")->AsString;

TntMemo1->Text=ADOQuery1->FieldByName("DESCRIPTION")->AsVariant;
TntMemo2->Text=ADOQuery1->FieldByName("CHARA")->AsVariant;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
PageControl1->SelectNextPage(false,true);
}
//---------------------------------------------------------------------------


