//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TRGSMprUnit3.h"
#include "TRGSMprUnit2.h"
#include "Loadsystem.h"
#include "Main.h"
#include "TRGSM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
if(Seksay->GetTextLen()<1 || Fhop->GetTextLen()<1 || Siteno->GetTextLen()<1 ||
Tgsayi->GetTextLen()<1 || Rbltsayi->GetTextLen()<1)
ShowMessage("Parametrleri duz daxil et");
else{



if(PageControl1->ActivePageIndex==PageControl1->PageCount-1)
Form3->Close();
if(PageControl1->ActivePageIndex<PageControl1->PageCount)
PageControl1->SelectNextPage(true,true);
 }

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
if(PageControl1->ActivePageIndex>0)
PageControl1->SelectNextPage(false,true);
if (!(PageControl1->ActivePageIndex==PageControl1->PageCount-1))
Form3->Button1->Caption="Next";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::TgsayiChange(TObject *Sender)
{

Tg1->Visible=false;
Tg1Label->Visible=false;
Tg2->Visible=false;
Tg2Label->Visible=false;
Tg3->Visible=false;
Tg3Label->Visible=false;
Tg4->Visible=false;
Tg4Label->Visible=false;


if(Tgsayi->ItemIndex>=0){
Tg1->Visible=true;
Tg1Label->Visible=true;}
if(Tgsayi->ItemIndex>=1){
Tg2->Visible=true;
Tg2Label->Visible=true;}
if(Tgsayi->ItemIndex>=2){
Tg3->Visible=true;
Tg3Label->Visible=true;}
if(Tgsayi->ItemIndex>=3){
Tg4->Visible=true;
Tg4Label->Visible=true;}

Ksayi->ItemIndex=Tgsayi->ItemIndex;
K2->Visible=false;
K3->Visible=false;
K4->Visible=false;

if(Ksayi->ItemIndex>=1)
K2->Visible=true;
if(Ksayi->ItemIndex>=2)
K3->Visible=true;
if(Ksayi->ItemIndex>=3)
K4->Visible=true;

//Tg1->Clear();
//Tg2->Clear();
//Tg3->Clear();
//Tg4->Clear();

//Tgk1->Clear();
//Tgk2->Clear();
//Tgk3->Clear();
//Tgk4->Clear();

}
//---------------------------------------------------------------------------


void __fastcall TForm3::RbltsayiChange(TObject *Sender)
{

Rblt1->Visible=false;
Rblt1Label->Enabled=false;
Rblt2->Visible=false;
Rblt2Label->Enabled=false;
Rblt3->Visible=false;
Rblt3Label->Enabled=false;
Rblt4->Visible=false;
Rblt4Label->Enabled=false;


if(Rbltsayi->ItemIndex>=0){
Rblt1->Visible=true;
Rblt1Label->Enabled=true;}
if(Rbltsayi->ItemIndex>=1){
Rblt2->Visible=true;
Rblt2Label->Enabled=true;}
if(Rbltsayi->ItemIndex>=2){
Rblt3->Visible=true;
Rblt3Label->Enabled=true;}
if(Rbltsayi->ItemIndex>=3){
Rblt4->Visible=true;
Rblt4Label->Enabled=true;}
}
//---------------------------------------------------------------------------




void __fastcall TForm3::Tpk1Change(TObject *Sender)
{
Tru1k1->Height=160;
Tru3k1->Height=160;
Tru5k1->Height=160;
Tru7k1->Height=160;
Tru9k1->Height=160;
Tru11k1->Height=160;
Tru9k1->Hide();
Tru11k1->Hide();
Tru2k1->Hide();
Tru4k1->Hide();
Tru6k1->Hide();
Tru8k1->Hide();
Tru10k1->Hide();
Tru12k1->Hide();

if(Tpk1->ItemIndex==1 || Tpk1->ItemIndex==4 || Tpk1->ItemIndex==5 )
{
Tru1k1->Height=80;
Tru3k1->Height=80;
Tru5k1->Height=80;
Tru7k1->Height=80;
Tru9k1->Height=80;
Tru11k1->Height=80;
Tru9k1->Show();
Tru11k1->Show();
Tru2k1->Show();
Tru4k1->Show();
Tru6k1->Show();
Tru8k1->Show();
Tru10k1->Show();
Tru12k1->Show();
}

if(Tpk1->ItemIndex==2 || Tpk1->ItemIndex==3 )
{
Tru9k1->Hide();
Tru11k1->Hide();
Tru2k1->Hide();
Tru4k1->Hide();
Tru6k1->Hide();
Tru8k1->Hide();
Tru10k1->Hide();
Tru12k1->Hide();
}

if(Tpk1->ItemIndex==0)
{
Tru9k1->Show();
Tru11k1->Show();
}

}
//---------------------------------------------------------------------------

void __fastcall TForm3::FhopChange(TObject *Sender)
{


if(Csystype->ItemIndex==0)
{
if(Fhop->ItemIndex==0){
Bufferf3->Clear();
Bufferf3->Lines->LoadFromFile("Bin\\BB_GSM900.trg");
Form2->LoadcellClick(Form2->Loadcell);}

if(Fhop->ItemIndex==1){
Bufferf3->Clear();
Bufferf3->Lines->LoadFromFile("Bin\\SY_GSM900.trg");
Form2->LoadcellClick(Form2->Loadcell);}
}

if(Csystype->ItemIndex==1)
{
if(Fhop->ItemIndex==1){
Bufferf3->Clear();
Bufferf3->Lines->LoadFromFile("Bin\\SY_GSM1800.trg");
Form2->LoadcellClick(Form2->Loadcell);}

if(Fhop->ItemIndex==0){
Bufferf3->Clear();
Bufferf3->Lines->LoadFromFile("Bin\\BB_GSM1800.trg");
Form2->LoadcellClick(Form2->Loadcell);}
}


Chgrtru1k1->Text=0;
Chgrtru2k1->Text=0;
Chgrtru3k1->Text=0;
Chgrtru4k1->Text=0;
Chgrtru5k1->Text=0;
Chgrtru6k1->Text=0;
Chgrtru7k1->Text=0;
Chgrtru8k1->Text=0;
Chgrtru9k1->Text=0;
Chgrtru10k1->Text=0;
Chgrtru11k1->Text=0;
Chgrtru12k1->Text=0;

Chgrtru1k2->Text=0;
Chgrtru2k2->Text=0;
Chgrtru3k2->Text=0;
Chgrtru4k2->Text=0;
Chgrtru5k2->Text=0;
Chgrtru6k2->Text=0;
Chgrtru7k2->Text=0;
Chgrtru8k2->Text=0;
Chgrtru9k2->Text=0;
Chgrtru10k2->Text=0;
Chgrtru11k2->Text=0;
Chgrtru12k2->Text=0;

Chgrtru1k3->Text=0;
Chgrtru2k3->Text=0;
Chgrtru3k3->Text=0;
Chgrtru4k3->Text=0;
Chgrtru5k3->Text=0;
Chgrtru6k3->Text=0;
Chgrtru7k3->Text=0;
Chgrtru8k3->Text=0;
Chgrtru9k3->Text=0;
Chgrtru10k3->Text=0;
Chgrtru11k3->Text=0;
Chgrtru12k3->Text=0;

Chgrtru1k4->Text=0;
Chgrtru2k4->Text=0;
Chgrtru3k4->Text=0;
Chgrtru4k4->Text=0;
Chgrtru5k4->Text=0;
Chgrtru6k4->Text=0;
Chgrtru7k4->Text=0;
Chgrtru8k4->Text=0;
Chgrtru9k4->Text=0;
Chgrtru10k4->Text=0;
Chgrtru11k4->Text=0;
Chgrtru12k4->Text=0;



if(Fhop->ItemIndex==1)
{

Chgrtru1k1->Text=1;
Chgrtru2k1->Text=1;
Chgrtru3k1->Text=1;
Chgrtru4k1->Text=1;
Chgrtru5k1->Text=1;
Chgrtru6k1->Text=1;
Chgrtru7k1->Text=1;
Chgrtru8k1->Text=1;
Chgrtru9k1->Text=1;
Chgrtru10k1->Text=1;
Chgrtru11k1->Text=1;
Chgrtru12k1->Text=1;

Chgrtru1k2->Text=1;
Chgrtru2k2->Text=1;
Chgrtru3k2->Text=1;
Chgrtru4k2->Text=1;
Chgrtru5k2->Text=1;
Chgrtru6k2->Text=1;
Chgrtru7k2->Text=1;
Chgrtru8k2->Text=1;
Chgrtru9k2->Text=1;
Chgrtru10k2->Text=1;
Chgrtru11k2->Text=1;
Chgrtru12k2->Text=1;

Chgrtru1k3->Text=1;
Chgrtru2k3->Text=1;
Chgrtru3k3->Text=1;
Chgrtru4k3->Text=1;
Chgrtru5k3->Text=1;
Chgrtru6k3->Text=1;
Chgrtru7k3->Text=1;
Chgrtru8k3->Text=1;
Chgrtru9k3->Text=1;
Chgrtru10k3->Text=1;
Chgrtru11k3->Text=1;
Chgrtru12k3->Text=1;

Chgrtru1k4->Text=1;
Chgrtru2k4->Text=1;
Chgrtru3k4->Text=1;
Chgrtru4k4->Text=1;
Chgrtru5k4->Text=1;
Chgrtru6k4->Text=1;
Chgrtru7k4->Text=1;
Chgrtru8k4->Text=1;
Chgrtru9k4->Text=1;
Chgrtru10k4->Text=1;
Chgrtru11k4->Text=1;
Chgrtru12k4->Text=1;

}

}



//---------------------------------------------------------------------------

void __fastcall TForm3::Skt1Click(TObject *Sender)
{

Skt->Color=clFuchsia;

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Skt2Click(TObject *Sender)
{

Skt->Color=clLime;

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Skt3Click(TObject *Sender)
{

Skt->Color=clGradientActiveCaption;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Skt4Click(TObject *Sender)
{

Skt->Color=clYellow;

}
//---------------------------------------------------------------------------


void __fastcall TForm3::DesktClick(TObject *Sender)
{
Skt->Color=clBtnFace;

}
//---------------------------------------------------------------------------

void __fastcall TForm3::KsayiChange(TObject *Sender)
{
K2->Visible=false;
K3->Visible=false;
K4->Visible=false;

if(Ksayi->ItemIndex>=1)
K2->Visible=true;
if(Ksayi->ItemIndex>=2)
K3->Visible=true;
if(Ksayi->ItemIndex>=3)
K4->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tpk2Change(TObject *Sender)
{
Tru1k2->Height=160;
Tru3k2->Height=160;
Tru5k2->Height=160;
Tru7k2->Height=160;
Tru9k2->Height=160;
Tru11k2->Height=160;
Tru9k2->Hide();
Tru11k2->Hide();
Tru2k2->Hide();
Tru4k2->Hide();
Tru6k2->Hide();
Tru8k2->Hide();
Tru10k2->Hide();
Tru12k2->Hide();

if(Tpk2->ItemIndex==1 || Tpk2->ItemIndex==4 || Tpk2->ItemIndex==5 ){
Tru1k2->Height=80;
Tru3k2->Height=80;
Tru5k2->Height=80;
Tru7k2->Height=80;
Tru9k2->Height=80;
Tru11k2->Height=80;
Tru9k2->Show();
Tru11k2->Show();
Tru2k2->Show();
Tru4k2->Show();
Tru6k2->Show();
Tru8k2->Show();
Tru10k2->Show();
Tru12k2->Show();
}

if(Tpk2->ItemIndex==2 || Tpk2->ItemIndex==3 ){
Tru9k2->Hide();
Tru11k2->Hide();
Tru2k2->Hide();
Tru4k2->Hide();
Tru6k2->Hide();
Tru8k2->Hide();
Tru10k2->Hide();
Tru12k2->Hide();
}
if(Tpk2->ItemIndex==0){
Tru9k2->Show();
Tru11k2->Show();
}


}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tpk3Change(TObject *Sender)
{
Tru1k3->Height=160;
Tru3k3->Height=160;
Tru5k3->Height=160;
Tru7k3->Height=160;
Tru9k3->Height=160;
Tru11k3->Height=160;
Tru9k3->Hide();
Tru11k3->Hide();
Tru2k3->Hide();
Tru4k3->Hide();
Tru6k3->Hide();
Tru8k3->Hide();
Tru10k3->Hide();
Tru12k3->Hide();

if(Tpk3->ItemIndex==1 || Tpk3->ItemIndex==4 || Tpk3->ItemIndex==5 ){
Tru1k3->Height=80;
Tru3k3->Height=80;
Tru5k3->Height=80;
Tru7k3->Height=80;
Tru9k3->Height=80;
Tru11k3->Height=80;
Tru9k3->Show();
Tru11k3->Show();
Tru2k3->Show();
Tru4k3->Show();
Tru6k3->Show();
Tru8k3->Show();
Tru10k3->Show();
Tru12k3->Show();
}

if(Tpk3->ItemIndex==2 || Tpk3->ItemIndex==3 ){
Tru9k3->Hide();
Tru11k3->Hide();
Tru2k3->Hide();
Tru4k3->Hide();
Tru6k3->Hide();
Tru8k3->Hide();
Tru10k3->Hide();
Tru12k3->Hide();
}
if(Tpk3->ItemIndex==0){
Tru9k3->Show();
Tru11k3->Show();
}


}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tpk4Change(TObject *Sender)
{
Tru1k4->Height=160;
Tru3k4->Height=160;
Tru5k4->Height=160;
Tru7k4->Height=160;
Tru9k4->Height=160;
Tru11k4->Height=160;
Tru9k4->Hide();
Tru11k4->Hide();
Tru2k4->Hide();
Tru4k4->Hide();
Tru6k4->Hide();
Tru8k4->Hide();
Tru10k4->Hide();
Tru12k4->Hide();

if(Tpk4->ItemIndex==1 || Tpk4->ItemIndex==4 || Tpk4->ItemIndex==5 ){
Tru1k4->Height=80;
Tru3k4->Height=80;
Tru5k4->Height=80;
Tru7k4->Height=80;
Tru9k4->Height=80;
Tru11k4->Height=80;
Tru9k4->Show();
Tru11k4->Show();
Tru2k4->Show();
Tru4k4->Show();
Tru6k4->Show();
Tru8k4->Show();
Tru10k4->Show();
Tru12k4->Show();
}

if(Tpk4->ItemIndex==2 || Tpk4->ItemIndex==3 ){
Tru9k4->Hide();
Tru11k4->Hide();
Tru2k4->Hide();
Tru4k4->Hide();
Tru6k4->Hide();
Tru8k4->Hide();
Tru10k4->Hide();
Tru12k4->Hide();
}
if(Tpk4->ItemIndex==0){
Tru9k4->Show();
Tru11k4->Show();
}


}
//---------------------------------------------------------------------------


void __fastcall TForm3::Tru1k2Click(TObject *Sender)
{
Tru1k2->Color=Skt->Color;
}
//---------------------------------------------------------------------------











void __fastcall TForm3::Tru1k3Click(TObject *Sender)
{
Tru1k3->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru2k3Click(TObject *Sender)
{
Tru2k3->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru3k3Click(TObject *Sender)
{
Tru3k3->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru4k3Click(TObject *Sender)
{
Tru4k3->Color=Skt->Color;         
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru5k3Click(TObject *Sender)
{
Tru5k3->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru6k3Click(TObject *Sender)
{
Tru6k3->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru7k3Click(TObject *Sender)
{
Tru7k3->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru8k3Click(TObject *Sender)
{
Tru8k3->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru9k3Click(TObject *Sender)
{
Tru9k3->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru10k3Click(TObject *Sender)
{
Tru10k3->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru11k3Click(TObject *Sender)
{
Tru11k3->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru12k3Click(TObject *Sender)
{
Tru12k3->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru1k4Click(TObject *Sender)
{
Tru1k4->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru3k4Click(TObject *Sender)
{
Tru3k4->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru2k4Click(TObject *Sender)
{
Tru2k4->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru4k4Click(TObject *Sender)
{
Tru4k4->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru5k4Click(TObject *Sender)
{
Tru5k4->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru6k4Click(TObject *Sender)
{
Tru6k4->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru7k4Click(TObject *Sender)
{
Tru7k4->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru8k4Click(TObject *Sender)
{
Tru8k4->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru9k4Click(TObject *Sender)
{
Tru9k4->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru10k4Click(TObject *Sender)
{
Tru10k4->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru11k4Click(TObject *Sender)
{
Tru11k4->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru12k4Click(TObject *Sender)
{
Tru12k4->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tg1Change(TObject *Sender)
{
Tgk1->Text=Tg1->Text;
  Tgk1->Items->Clear();
 Tgk1->Items->Add(Tg1->Text);
 if(Tg2->Visible==true)
 Tgk1->Items->Add(Tg2->Text);
  if(Tg3->Visible==true)
 Tgk1->Items->Add(Tg3->Text);
  if(Tg4->Visible==true)
 Tgk1->Items->Add(Tg4->Text);

 if(K2->Visible==true)
 {
  Tgk2->Items->Clear();
 Tgk2->Items->Add(Tg1->Text);
  if(Tg2->Visible==true)
 Tgk2->Items->Add(Tg2->Text);
  if(Tg3->Visible==true)
 Tgk2->Items->Add(Tg3->Text);
  if(Tg4->Visible==true)
 Tgk2->Items->Add(Tg4->Text);
 }

  if(K3->Visible==true)
  {
   Tgk3->Items->Clear();
 Tgk3->Items->Add(Tg1->Text);
  if(Tg2->Visible==true)
 Tgk3->Items->Add(Tg2->Text);
  if(Tg3->Visible==true)
 Tgk3->Items->Add(Tg3->Text);
  if(Tg4->Visible==true)
 Tgk3->Items->Add(Tg4->Text);
 }

  if(K4->Visible==true)
  {
   Tgk4->Items->Clear();
 Tgk4->Items->Add(Tg1->Text);
  if(Tg2->Visible==true)
 Tgk4->Items->Add(Tg2->Text);
  if(Tg3->Visible==true)
 Tgk4->Items->Add(Tg3->Text);
  if(Tg4->Visible==true)
 Tgk4->Items->Add(Tg4->Text);
 }

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tg2Change(TObject *Sender)
{
Tgk2->Text=Tg2->Text;
  Tgk1->Items->Clear();
 Tgk1->Items->Add(Tg1->Text);
 Tgk1->Items->Add(Tg2->Text);
  if(Tg3->Visible==true)
 Tgk1->Items->Add(Tg3->Text);
  if(Tg4->Visible==true)
 Tgk1->Items->Add(Tg4->Text);


  Tgk2->Items->Clear();
 Tgk2->Items->Add(Tg1->Text);
 Tgk2->Items->Add(Tg2->Text);
  if(Tg3->Visible==true)
 Tgk2->Items->Add(Tg3->Text);
  if(Tg4->Visible==true)
 Tgk2->Items->Add(Tg4->Text);

  if(K3->Visible==true)
  {
   Tgk3->Items->Clear();
 Tgk3->Items->Add(Tg1->Text);
 Tgk3->Items->Add(Tg2->Text);
  if(Tg3->Visible==true)
 Tgk3->Items->Add(Tg3->Text);
  if(Tg4->Visible==true)
 Tgk3->Items->Add(Tg4->Text);
 }

  if(K4->Visible==true)
  {
   Tgk4->Items->Clear();
 Tgk4->Items->Add(Tg1->Text);
 Tgk4->Items->Add(Tg2->Text);
  if(Tg3->Visible==true)
 Tgk4->Items->Add(Tg3->Text);
  if(Tg4->Visible==true)
 Tgk4->Items->Add(Tg4->Text);
 }


}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tg3Change(TObject *Sender)
{
Tgk3->Text=Tg3->Text;
  Tgk1->Items->Clear();
 Tgk1->Items->Add(Tg1->Text);
 Tgk1->Items->Add(Tg2->Text);
 Tgk1->Items->Add(Tg3->Text);
  if(Tg4->Visible==true)
 Tgk1->Items->Add(Tg4->Text);



  Tgk2->Items->Clear();
 Tgk2->Items->Add(Tg1->Text);
 Tgk2->Items->Add(Tg2->Text);
 Tgk2->Items->Add(Tg3->Text);
  if(Tg4->Visible==true)
 Tgk2->Items->Add(Tg4->Text);



   Tgk3->Items->Clear();
 Tgk3->Items->Add(Tg1->Text);
 Tgk3->Items->Add(Tg2->Text);
 Tgk3->Items->Add(Tg3->Text);
  if(Tg4->Visible==true)
 Tgk3->Items->Add(Tg4->Text);


  if(K4->Visible==true)
  {
   Tgk4->Items->Clear();
 Tgk4->Items->Add(Tg1->Text);
 Tgk4->Items->Add(Tg2->Text);
 Tgk4->Items->Add(Tg3->Text);
  if(Tg4->Visible==true)
 Tgk4->Items->Add(Tg4->Text);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tg4Change(TObject *Sender)
{
Tgk4->Text=Tg4->Text;
  Tgk1->Items->Clear();
 Tgk1->Items->Add(Tg1->Text);
 Tgk1->Items->Add(Tg2->Text);
 Tgk1->Items->Add(Tg3->Text);
 Tgk1->Items->Add(Tg4->Text);

  Tgk2->Items->Clear();
 Tgk2->Items->Add(Tg1->Text);
 Tgk2->Items->Add(Tg2->Text);
 Tgk2->Items->Add(Tg3->Text);
 Tgk2->Items->Add(Tg4->Text);

  Tgk3->Items->Clear();
 Tgk3->Items->Add(Tg1->Text);
 Tgk3->Items->Add(Tg2->Text);
 Tgk3->Items->Add(Tg3->Text);
 Tgk3->Items->Add(Tg4->Text);

  Tgk4->Items->Clear();
 Tgk4->Items->Add(Tg1->Text);
 Tgk4->Items->Add(Tg2->Text);
 Tgk4->Items->Add(Tg3->Text);
 Tgk4->Items->Add(Tg4->Text);

}
//---------------------------------------------------------------------------



void __fastcall TForm3::SitenoChange(TObject *Sender)
{
Form2->Cic1->Text=Siteno->Text+"1";
Form2->Cic2->Text=Siteno->Text+"2";
Form2->Cic3->Text=Siteno->Text+"3";
Form2->Cic4->Text=Siteno->Text+"4";
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Rblt1Change(TObject *Sender)
{
Odp01k1->Text=Rblt1->Text;

Odp01k1->Items->Clear();
Odp23k1->Items->Clear();
Odp01k2->Items->Clear();
Odp23k2->Items->Clear();
Odp01k3->Items->Clear();
Odp23k3->Items->Clear();
Odp01k4->Items->Clear();
Odp23k4->Items->Clear();

Odp01k1->Items->Add(Rblt1->Text);
Odp23k1->Items->Add(Rblt1->Text);
 if(Rblt2->Visible==true){
 Odp01k1->Items->Add(Rblt2->Text);
Odp23k1->Items->Add(Rblt2->Text);}
 if(Rblt3->Visible==true){
 Odp01k1->Items->Add(Rblt3->Text);
Odp23k1->Items->Add(Rblt3->Text);}
 if(Rblt4->Visible==true){
 Odp01k1->Items->Add(Rblt4->Text);
Odp23k1->Items->Add(Rblt4->Text);}
if(K2->Visible==true)
{
Odp01k2->Items->Add(Rblt1->Text);
Odp23k2->Items->Add(Rblt1->Text);
 if(Rblt2->Visible==true){
 Odp01k2->Items->Add(Rblt2->Text);
Odp23k2->Items->Add(Rblt2->Text);}
 if(Rblt3->Visible==true){
 Odp01k2->Items->Add(Rblt3->Text);
Odp23k2->Items->Add(Rblt3->Text);}
 if(Rblt4->Visible==true){
 Odp01k2->Items->Add(Rblt4->Text);
Odp23k2->Items->Add(Rblt4->Text);}

}
if(K3->Visible==true)
{
Odp01k3->Items->Add(Rblt1->Text);
Odp23k3->Items->Add(Rblt1->Text);
 if(Rblt2->Visible==true){
 Odp01k3->Items->Add(Rblt2->Text);
Odp23k3->Items->Add(Rblt2->Text);}
 if(Rblt3->Visible==true){
 Odp01k3->Items->Add(Rblt3->Text);
Odp23k3->Items->Add(Rblt3->Text);}
 if(Rblt4->Visible==true){
 Odp01k3->Items->Add(Rblt4->Text);
Odp23k3->Items->Add(Rblt4->Text);}
}
if(K4->Visible==true)
{
Odp01k4->Items->Add(Rblt1->Text);
Odp23k4->Items->Add(Rblt1->Text);
 if(Rblt2->Visible==true){
 Odp01k4->Items->Add(Rblt2->Text);
Odp23k4->Items->Add(Rblt2->Text);}
 if(Rblt3->Visible==true){
 Odp01k4->Items->Add(Rblt3->Text);
Odp23k4->Items->Add(Rblt3->Text);}
 if(Rblt4->Visible==true){
 Odp01k4->Items->Add(Rblt4->Text);
Odp23k4->Items->Add(Rblt4->Text);}
}

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Rblt2Change(TObject *Sender)
{
Odp01k2->Text=Rblt2->Text;

Odp01k1->Items->Clear();
Odp23k1->Items->Clear();
Odp01k2->Items->Clear();
Odp23k2->Items->Clear();
Odp01k3->Items->Clear();
Odp23k3->Items->Clear();
Odp01k4->Items->Clear();
Odp23k4->Items->Clear();

Odp01k1->Items->Add(Rblt1->Text);
Odp23k1->Items->Add(Rblt1->Text);
 if(Rblt2->Visible==true){
 Odp01k1->Items->Add(Rblt2->Text);
Odp23k1->Items->Add(Rblt2->Text);}
 if(Rblt3->Visible==true){
 Odp01k1->Items->Add(Rblt3->Text);
Odp23k1->Items->Add(Rblt3->Text);}
 if(Rblt4->Visible==true){
 Odp01k1->Items->Add(Rblt4->Text);
Odp23k1->Items->Add(Rblt4->Text);}

if(K2->Visible==true)
{
Odp01k2->Items->Add(Rblt1->Text);
Odp23k2->Items->Add(Rblt1->Text);

 Odp01k2->Items->Add(Rblt2->Text);
Odp23k2->Items->Add(Rblt2->Text);
 if(Rblt3->Visible==true){
 Odp01k2->Items->Add(Rblt3->Text);
Odp23k2->Items->Add(Rblt3->Text);}
 if(Rblt4->Visible==true){
 Odp01k2->Items->Add(Rblt4->Text);
Odp23k2->Items->Add(Rblt4->Text);}

}
if(K3->Visible==true)
{
Odp01k3->Items->Add(Rblt1->Text);
Odp23k3->Items->Add(Rblt1->Text);

 Odp01k3->Items->Add(Rblt2->Text);
Odp23k3->Items->Add(Rblt2->Text);
 if(Rblt3->Visible==true){
 Odp01k3->Items->Add(Rblt3->Text);
Odp23k3->Items->Add(Rblt3->Text);}
 if(Rblt4->Visible==true){
 Odp01k3->Items->Add(Rblt4->Text);
Odp23k3->Items->Add(Rblt4->Text);}
}
if(K4->Visible==true)
{
Odp01k4->Items->Add(Rblt1->Text);
Odp23k4->Items->Add(Rblt1->Text);

 Odp01k4->Items->Add(Rblt2->Text);
Odp23k4->Items->Add(Rblt2->Text);
 if(Rblt3->Visible==true){
 Odp01k4->Items->Add(Rblt3->Text);
Odp23k4->Items->Add(Rblt3->Text);}
 if(Rblt4->Visible==true){
 Odp01k4->Items->Add(Rblt4->Text);
Odp23k4->Items->Add(Rblt4->Text);}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Rblt3Change(TObject *Sender)
{
Odp01k3->Text=Rblt3->Text;

Odp01k1->Items->Clear();
Odp23k1->Items->Clear();
Odp01k2->Items->Clear();
Odp23k2->Items->Clear();
Odp01k3->Items->Clear();
Odp23k3->Items->Clear();
Odp01k4->Items->Clear();
Odp23k4->Items->Clear();

Odp01k1->Items->Add(Rblt1->Text);
Odp23k1->Items->Add(Rblt1->Text);
 if(Rblt2->Visible==true){
 Odp01k1->Items->Add(Rblt2->Text);
Odp23k1->Items->Add(Rblt2->Text);}
 if(Rblt3->Visible==true){
 Odp01k1->Items->Add(Rblt3->Text);
Odp23k1->Items->Add(Rblt3->Text);}
 if(Rblt4->Visible==true){
 Odp01k1->Items->Add(Rblt4->Text);
Odp23k1->Items->Add(Rblt4->Text);}

if(K2->Visible==true)
{
Odp01k2->Items->Add(Rblt1->Text);
Odp23k2->Items->Add(Rblt1->Text);

 Odp01k2->Items->Add(Rblt2->Text);
Odp23k2->Items->Add(Rblt2->Text);

 Odp01k2->Items->Add(Rblt3->Text);
Odp23k2->Items->Add(Rblt3->Text);
 if(Rblt4->Visible==true){
 Odp01k2->Items->Add(Rblt4->Text);
Odp23k2->Items->Add(Rblt4->Text);}

}
if(K3->Visible==true)
{
Odp01k3->Items->Add(Rblt1->Text);
Odp23k3->Items->Add(Rblt1->Text);

 Odp01k3->Items->Add(Rblt2->Text);
Odp23k3->Items->Add(Rblt2->Text);

 Odp01k3->Items->Add(Rblt3->Text);
Odp23k3->Items->Add(Rblt3->Text);
 if(Rblt4->Visible==true){
 Odp01k3->Items->Add(Rblt4->Text);
Odp23k3->Items->Add(Rblt4->Text);}
}
if(K4->Visible==true)
{
Odp01k4->Items->Add(Rblt1->Text);
Odp23k4->Items->Add(Rblt1->Text);

 Odp01k4->Items->Add(Rblt2->Text);
Odp23k4->Items->Add(Rblt2->Text);

 Odp01k4->Items->Add(Rblt3->Text);
Odp23k4->Items->Add(Rblt3->Text);
 if(Rblt4->Visible==true){
 Odp01k4->Items->Add(Rblt4->Text);
Odp23k4->Items->Add(Rblt4->Text);}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Rblt4Change(TObject *Sender)
{
Odp01k4->Text=Rblt4->Text;

Odp01k1->Items->Clear();
Odp23k1->Items->Clear();
Odp01k2->Items->Clear();
Odp23k2->Items->Clear();
Odp01k3->Items->Clear();
Odp23k3->Items->Clear();
Odp01k4->Items->Clear();
Odp23k4->Items->Clear();

Odp01k1->Items->Add(Rblt1->Text);
Odp23k1->Items->Add(Rblt1->Text);
 if(Rblt2->Visible==true){
 Odp01k1->Items->Add(Rblt2->Text);
Odp23k1->Items->Add(Rblt2->Text);}
 if(Rblt3->Visible==true){
 Odp01k1->Items->Add(Rblt3->Text);
Odp23k1->Items->Add(Rblt3->Text);}
 if(Rblt4->Visible==true){
 Odp01k1->Items->Add(Rblt4->Text);
Odp23k1->Items->Add(Rblt4->Text);}

if(K2->Visible==true)
{
Odp01k2->Items->Add(Rblt1->Text);
Odp23k2->Items->Add(Rblt1->Text);

 Odp01k2->Items->Add(Rblt2->Text);
Odp23k2->Items->Add(Rblt2->Text);

 Odp01k2->Items->Add(Rblt3->Text);
Odp23k2->Items->Add(Rblt3->Text);

 Odp01k2->Items->Add(Rblt4->Text);
Odp23k2->Items->Add(Rblt4->Text);

}
if(K3->Visible==true)
{
Odp01k3->Items->Add(Rblt1->Text);
Odp23k3->Items->Add(Rblt1->Text);

 Odp01k3->Items->Add(Rblt2->Text);
Odp23k3->Items->Add(Rblt2->Text);

 Odp01k3->Items->Add(Rblt3->Text);
Odp23k3->Items->Add(Rblt3->Text);

 Odp01k3->Items->Add(Rblt4->Text);
Odp23k3->Items->Add(Rblt4->Text);
}
if(K4->Visible==true)
{
Odp01k4->Items->Add(Rblt1->Text);
Odp23k4->Items->Add(Rblt1->Text);

 Odp01k4->Items->Add(Rblt2->Text);
Odp23k4->Items->Add(Rblt2->Text);

 Odp01k4->Items->Add(Rblt3->Text);
Odp23k4->Items->Add(Rblt3->Text);

 Odp01k4->Items->Add(Rblt4->Text);
Odp23k4->Items->Add(Rblt4->Text);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Odp23k1Change(TObject *Sender)
{
Odp2k1->Checked=false;
if(Odp23k1->GetTextLen()!=0)
Odp2k1->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Odp23k2Change(TObject *Sender)
{
Odp2k2->Checked=false;
if(Odp23k2->GetTextLen()!=0)
Odp2k2->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Odp23k3Change(TObject *Sender)
{
Odp2k3->Checked=false;
if(Odp23k3->GetTextLen()!=0)
Odp2k3->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Odp23k4Change(TObject *Sender)
{
Odp2k4->Checked=false;
if(Odp23k4->GetTextLen()!=0)
Odp2k4->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SeksayChange(TObject *Sender)
{
Form2->Tabc2->TabVisible=true;
Form2->Tabc3->TabVisible=true;
Form2->Tabc4->TabVisible=true;
Skt2->Visible=true;
Skt3->Visible=true;
Skt4->Visible=true;
Edgec2->TabVisible=true;
Edgec3->TabVisible=true;
Edgec4->TabVisible=true;

if(Seksay->ItemIndex==0)
{
Form2->Tabc2->TabVisible=false;
Form2->Tabc3->TabVisible=false;
Form2->Tabc4->TabVisible=false;
Skt2->Visible=false;
Skt3->Visible=false;
Skt4->Visible=false;
Edgec2->TabVisible=false;
Edgec3->TabVisible=false;
Edgec4->TabVisible=false;
}

if(Seksay->ItemIndex==1)
{
Form2->Tabc3->TabVisible=false;
Form2->Tabc4->TabVisible=false;
Skt3->Visible=false;
Skt4->Visible=false;
Edgec3->TabVisible=false;
Edgec4->TabVisible=false;
}

if(Seksay->ItemIndex==2)
{
Form2->Tabc4->TabVisible=false;
Skt4->Visible=false;
Edgec4->TabVisible=false;
}


}
//---------------------------------------------------------------------------




void __fastcall TForm3::CsystypeChange(TObject *Sender)
{
Form2->Band->Text=Csystype->Text;
if(Csystype->ItemIndex==0){

if(Fhop->ItemIndex==0){
Bufferf3->Clear();
Bufferf3->Lines->LoadFromFile("Bin\\BB_GSM900.trg");
Form2->LoadcellClick(Form2->Loadcell);}

if(Fhop->ItemIndex==0){
Bufferf3->Clear();
Bufferf3->Lines->LoadFromFile("Bin\\SY_GSM900.trg");
Form2->LoadcellClick(Form2->Loadcell);}

Form2->Tnchgr0c1->Text="2";
Form2->Tnchgr0c1Change(Form2->Tnchgr0c1);



}

if(Csystype->ItemIndex==1){
if(Fhop->ItemIndex==1){
Bufferf3->Clear();
Bufferf3->Lines->LoadFromFile("Bin\\SY_GSM1800.trg");
Form2->LoadcellClick(Form2->Loadcell);}

if(Fhop->ItemIndex==0){
Bufferf3->Clear();
Bufferf3->Lines->LoadFromFile("Bin\\BB_GSM1800.trg");
Form2->LoadcellClick(Form2->Loadcell);}

Form2->Tnchgr0c1->Text="1&2";
Form2->Tnchgr0c1Change(Form2->Tnchgr0c1);



}

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru2k1Click(TObject *Sender)
{
Tru2k1->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru3k1Click(TObject *Sender)
{
Tru3k1->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru4k1Click(TObject *Sender)
{
Tru4k1->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru5k1Click(TObject *Sender)
{
Tru5k1->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru6k1Click(TObject *Sender)
{
Tru6k1->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru7k1Click(TObject *Sender)
{
Tru7k1->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru8k1Click(TObject *Sender)
{
Tru8k1->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru9k1Click(TObject *Sender)
{
Tru9k1->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru10k1Click(TObject *Sender)
{
Tru10k1->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru11k1Click(TObject *Sender)
{
Tru11k1->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru12k1Click(TObject *Sender)
{
Tru12k1->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru1k1Click(TObject *Sender)
{
Tru1k1->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru2k2Click(TObject *Sender)
{
Tru2k2->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru3k2Click(TObject *Sender)
{
Tru3k2->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru4k2Click(TObject *Sender)
{
Tru4k2->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru5k2Click(TObject *Sender)
{
Tru5k2->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru6k2Click(TObject *Sender)
{
 Tru6k2->Color=Skt->Color;       
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru7k2Click(TObject *Sender)
{
Tru7k2->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru8k2Click(TObject *Sender)
{
Tru8k2->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru9k2Click(TObject *Sender)
{
Tru9k2->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru10k2Click(TObject *Sender)
{
Tru10k2->Color=Skt->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru11k2Click(TObject *Sender)
{
Tru11k2->Color=Skt->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Tru12k2Click(TObject *Sender)
{
Tru12k2->Color=Skt->Color;
}
//---------------------------------------------------------------------------


bool Giris=false;
String Komanda="NOVBETI",CELLS;
String TG1,TG2,TG3,TG4,RLDEPC1,RLDEPC2,RLDEPC3,RLDEPC4,RLDHPC1,RBLT1,RBLT2,RBLT3,RBLT4;
String RLBDPC1,RLBDPC2,RLBDPC3,RLBDPC4,RXMFPTG1,RXMFPTG2,RXMFPTG3,RXMFPTG4;
String RLCFPC1,RLCFPC2,RLCFPC3,RLCFPC4;
String RLSLPC1,RLSLPC2,RLSLPC3,RLSLPC4;
String RLCHPC1,RLCHPC2,RLCHPC3,RLCHPC4;
String RLCPPC1,RLCPPC2,RLCPPC3,RLCPPC4;
String RLCXPC1,RLCXPC2,RLCXPC3,RLCXPC4;
String RLLOPC1,RLLOPC2,RLLOPC3,RLLOPC4;
String RLLUPC1,RLLUPC2,RLLUPC3,RLLUPC4;
String RLLPPC1,RLLPPC2,RLLPPC3,RLLPPC4;
String RLLFPC1,RLLFPC2,RLLFPC3,RLLFPC4;
String RLLDPC1,RLLDPC2,RLLDPC3,RLLDPC4;
String RLLCPC1,RLLCPC2,RLLCPC3,RLLCPC4;
String RLSSPC1,RLSSPC2,RLSSPC3,RLSSPC4;
String RLSBPC1,RLSBPC2,RLSBPC3,RLSBPC4;
String RLIHPC1,RLIHPC2,RLIHPC3,RLIHPC4;
String RLLHPC1,RLLHPC2,RLLHPC3,RLLHPC4;
String RLPCPC1,RLPCPC2,RLPCPC3,RLPCPC4;
String RLBCPC1,RLBCPC2,RLBCPC3,RLBCPC4;
String RLCDPC1,RLCDPC2,RLCDPC3,RLCDPC4;
String RLIMPC1,RLIMPC2,RLIMPC3,RLIMPC4;
String RLNRPC1,RLNRPC2,RLNRPC3,RLNRPC4;
String RLMTPC1,RLMTPC2,RLMTPC3,RLMTPC4;
String RLMBPC1,RLMBPC2,RLMBPC3,RLMBPC4;

String RXMOPTG1,RXMOPTG2,RXMOPTG3,RXMOPTG4;
String RXMOPCF1,RXMOPCF2,RXMOPCF3,RXMOPCF4;
String RXMOPTF1,RXMOPTF2,RXMOPTF3,RXMOPTF4;
String QONCELL1,QONCELL2,QONCELL3,QONCELL4;
String DTSTPTG1ODP1,DTSTPTG2ODP1,DTSTPTG3ODP1,DTSTPTG4ODP1;
String DTSTPTG1ODP3,DTSTPTG2ODP3,DTSTPTG3ODP3,DTSTPTG4ODP3;
String RXMOP0TG1,RXMOP1TG1,RXMOP2TG1,RXMOP3TG1,RXMOP4TG1,RXMOP5TG1,RXMOP6TG1,RXMOP7TG1,RXMOP8TG1,RXMOP9TG1,RXMOP10TG1,RXMOP11TG1;
String RXMOP0TG2,RXMOP1TG2,RXMOP2TG2,RXMOP3TG2,RXMOP4TG2,RXMOP5TG2,RXMOP6TG2,RXMOP7TG2,RXMOP8TG2,RXMOP9TG2,RXMOP10TG2,RXMOP11TG2;
String RXMOP0TG3,RXMOP1TG3,RXMOP2TG3,RXMOP3TG3,RXMOP4TG3,RXMOP5TG3,RXMOP6TG3,RXMOP7TG3,RXMOP8TG3,RXMOP9TG3,RXMOP10TG3,RXMOP11TG3;
String RXMOP0TG4,RXMOP1TG4,RXMOP2TG4,RXMOP3TG4,RXMOP4TG4,RXMOP5TG4,RXMOP6TG4,RXMOP7TG4,RXMOP8TG4,RXMOP9TG4,RXMOP10TG4,RXMOP11TG4;

//-----------------------------------------------------//
String RXMOPTRU(String CELL)
 {
      if(Form6->Cell1->Text==CELL)
       Form3->Skt1->Checked=true;
      if(Form6->Cell2->Visible==true && Form6->Cell2->Text==CELL)
       Form3->Skt2->Checked=true;
      if(Form6->Cell3->Visible==true && Form6->Cell3->Text==CELL)
       Form3->Skt3->Checked=true;
      if(Form6->Cell3->Visible==true && Form6->Cell4->Text==CELL)
       Form3->Skt4->Checked=true;
       return(0);
  }


void __fastcall TForm3::IdTelnet1DataAvailable(AnsiString Buffer)
{
Form6->Memo2->Lines->Add(Buffer);
Form6->Memo1->Text=Form6->Memo1->Text+Buffer;

//------------------------avtomatik giris---------------------//
if(Giris==false)
 {

    if (int PosReturn =Buffer.Pos("Userid:"))
    IdTelnet1->WriteLn(Form6->User->Text);

    if (int PosReturn = Buffer.Pos("Password:"))
    IdTelnet1->WriteLn(Form6->Password->Text);

    if (int PosReturn =Buffer.Pos("NE:"))
    IdTelnet1->WriteLn("ne="+Form6->Bsc->Text);


    if (int PosReturn = Buffer.Pos("<"))
    {
    Form6->Panel1->Color=clGreen;
    Form6->Memo1->Clear();
    Giris=true;
    Komanda="NOVBETI";
    TG1="";
    TG2="";
    TG3="";
    TG4="";
    RBLT1="";
    RBLT2="";
    RBLT3="";
    RBLT4="";
    RLDEPC1="";
    RLDHPC1="";
    }
 }
//-----------------------Teleblere(komanda) uygun cavablar----------------//

if(Giris==true)
{
//------------serverin tekrarladigi komandani kenarlasdirir------------------//
         for (int I = 0; I <Form6->Memo1->Lines->Count-1; I++)
        {
                if (int r=Form6->Memo1->Lines->Strings[I].Pos(Komanda) && Form6->Memo1->Lines->Count<2)//gonderilen komandani girisden kenarlasdirir
                {
                Form6->Memo1->Clear();
                }
        }

 //-------------------------Servislerden cixis----------------------------//
       if(Komanda=="SERVISCIXIS")
        for (int I = 0; I <Form6->Memo1->Lines->Count; I++)
         if (int CIXIS = Form6->Memo1->Lines->Strings[I].Pos("<"))
         {
         Komanda="NOVBETI";
         }
 //--------------------------Servislere giris---------------------------//
        if(Servis=="CELLS")
        if (int PosReturn = Buffer.Pos("<"))
        {
        Form3->CellsPanelClick(CellsPanel);
        goto son;
        }
        //------------------------------------
        if(Servis=="RXTCP")
        {
        Form3->RxtcpPanelClick(RxtcpPanel);
        goto son;
        }
        //------------------------------------
        if(Servis=="RXAPP")
        if (int PosReturn = Buffer.Pos("<"))
        {
        Form3->RxappPanelClick(RxappPanel);
        goto son;
        }
        //------------------------------------
        if(Servis=="RLBDP")
        if (int PosReturn = Buffer.Pos("<"))
        {
        Form3->RlbdpPanelClick(RlbdpPanel);
        goto son;
        }
        //------------------------------------
        if(Servis=="RXMOP")
        if (int PosReturn = Buffer.Pos("<"))
        {
        Form3->RxmopPanelClick(RxmopPanel);
        goto son;
        }
        //------------------------------------
        if(Servis=="RLDEP")
        if (int PosReturn = Buffer.Pos("<"))
        {
        Form3->RldepPanelClick(RldepPanel);
        goto son;
        }
        //------------------------------------
        if(Servis=="RXMOPTRUK1")
        if (int PosReturn = Buffer.Pos("<"))
        {
        Form3->Rxmoptruk1PanelClick(Rxmoptruk1Panel);
        goto son;
        }
        //------------------------------------

        if(Servis=="RXMOPTRUK2")
        if (int PosReturn = Buffer.Pos("<"))
        if(Tg2->Visible==true)
        {
        Form3->Rxmoptruk2PanelClick(Rxmoptruk2Panel);
        goto son;
        }
        else
        Servis="CELL1";
        //------------------------------------
        if(Servis=="RXMOPTRUK3")
        if (int PosReturn = Buffer.Pos("<"))
        if(Tg3->Visible==true)
        {
        Form3->Rxmoptruk3PanelClick(Rxmoptruk3Panel);
        goto son;
        }
        else
        Servis="CELL1";
        //-------------------------------------

        if(Servis=="RXMOPTRUK4")
        if (int PosReturn = Buffer.Pos("<"))
        if(Tg4->Visible==true)
        {
        Form3->Rxmoptruk4PanelClick(Rxmoptruk4Panel);
        goto son;
        }
        else
        Servis="CELL1";
        //-------------------------------------
        if(Servis=="CELL1")
        if (int PosReturn = Buffer.Pos("<"))
        {
        Form3->Cell1PanelClick(Cell1Panel);
        goto son;
        }
        //------------------------------------
        if(Servis=="CELL2")
        if(Form6->Cell2->Visible==true)
        {
        Form3->Cell2PanelClick(Cell2Panel);
        goto son;
        }
        else
        Servis="CELL3";
        //-------------------------------------
        if(Servis=="CELL3")
        if(Form6->Cell3->Visible==true)
        {
        Form3->Cell3PanelClick(Cell3Panel);
        goto son;
        }
        else
        Servis="CELL4";
        //--------------------------------------
        if(Servis=="CELL4")
        if(Form6->Cell4->Visible==true)
        {
        Form3->Cell4PanelClick(Cell4Panel);
        goto son;
        }
        else
        Servis="ADDITION";
        //--------------------------------------
        if(Servis=="ADDITION")
        if (int PosReturn = Buffer.Pos("<"))
        {
        Form3->AdditionPanelClick(AdditionPanel);
        goto son;
        }
        //--------------------------------------
        if(Servis=="RLDEPQON")
        if (int PosReturn = Buffer.Pos("<"))
        {
        Form3->RldepqonPanelClick(RldepqonPanel);
        goto son;
        }
        //--------------------------------------
        if(Servis=="FINISH")
        {
        Form3->FinishPanelClick(FinishPanel);
        goto son;
        }
}

//-------------------------------------SON------------------------------------
  son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Loadfromsystem1Click(TObject *Sender)
{
Form6->Show();
}
//---------------------------------------------------------------------------







void __fastcall TForm3::IdTelnet1Disconnected(TObject *Sender)
{
Giris=false;
Form6->Panel1->Color=clBtnFace;
Form2->Avtopnl->Color=clBtnFace;
//Form6->CellGroupBox->Enabled=true;

Form3->ClearPanelDblClick(ClearPanel);
}
//---------------------------------------------------------------------------


void __fastcall TForm3::TgbufferChange(TObject *Sender)
{
for(int o=0;o<Tgbuffer->Lines->Count-1;o++)
for(int p=o+1;p<Tgbuffer->Lines->Count;p++)
if(Tgbuffer->Lines->Strings[p]==Tgbuffer->Lines->Strings[o])
{
Tgbuffer->Lines->Delete(p);
p--;
}

Tgsayi->ItemIndex=Tgbuffer->Lines->Count-1;
Form3->TgsayiChange(Tgsayi);
if(Tgsayi->ItemIndex>=0)
Tg1->Text=Tgbuffer->Lines->Strings[0];
if(Tgsayi->ItemIndex>=1)
Tg2->Text=Tgbuffer->Lines->Strings[1];
if(Tgsayi->ItemIndex>=2)
Tg3->Text=Tgbuffer->Lines->Strings[2];
if(Tgsayi->ItemIndex>=3)
Tg4->Text=Tgbuffer->Lines->Strings[3];
Form3->TgsayiChange(Tgsayi);
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Pbodp01k1Click(TObject *Sender)
{
if(Ppodp01k1->Visible==false)
goto Bir;
if(Ppodp01k1->Visible==true)
goto Iki;

Bir:{
Pbodp01k1->Glyph->LoadFromFile("Images\\sola.bmp");
Ppodp01k1->Show();
goto son;}
Iki:{
 Pbodp01k1->Glyph->LoadFromFile("Images\\saga.bmp");
Ppodp01k1->Hide();}
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Pbodp23k1Click(TObject *Sender)
{
if(Ppodp23k1->Visible==false)
goto Bir;
if(Ppodp23k1->Visible==true)
goto Iki;

Bir:{
Pbodp23k1->Glyph->LoadFromFile("Images\\sola.bmp");
Ppodp23k1->Show();
goto son;}
Iki:{
 Pbodp23k1->Glyph->LoadFromFile("Images\\saga.bmp");
Ppodp23k1->Hide();}
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Pbodp01k2Click(TObject *Sender)
{
if(Ppodp01k2->Visible==false)
goto Bir;
if(Ppodp01k2->Visible==true)
goto Iki;

Bir:{
Pbodp01k2->Glyph->LoadFromFile("Images\\sola.bmp");
Ppodp01k2->Show();
goto son;}
Iki:{
 Pbodp01k2->Glyph->LoadFromFile("Images\\saga.bmp");
Ppodp01k2->Hide();}
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Pbodp01k3Click(TObject *Sender)
{
if(Ppodp01k3->Visible==false)
goto Bir;
if(Ppodp01k3->Visible==true)
goto Iki;

Bir:{
Pbodp01k3->Glyph->LoadFromFile("Images\\sola.bmp");
Ppodp01k3->Show();
goto son;}
Iki:{
 Pbodp01k3->Glyph->LoadFromFile("Images\\saga.bmp");
Ppodp01k3->Hide();}
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Pbodp01k4Click(TObject *Sender)
{
if(Ppodp01k4->Visible==false)
goto Bir;
if(Ppodp01k4->Visible==true)
goto Iki;

Bir:{
Pbodp01k4->Glyph->LoadFromFile("Images\\sola.bmp");
Ppodp01k4->Show();
goto son;}
Iki:{
 Pbodp01k4->Glyph->LoadFromFile("Images\\saga.bmp");
Ppodp01k4->Hide();}
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Pbodp23k2Click(TObject *Sender)
{
if(Ppodp23k2->Visible==false)
goto Bir;
if(Ppodp23k2->Visible==true)
goto Iki;

Bir:{
Pbodp23k2->Glyph->LoadFromFile("Images\\sola.bmp");
Ppodp23k2->Show();
goto son;}
Iki:{
 Pbodp23k2->Glyph->LoadFromFile("Images\\saga.bmp");
Ppodp23k2->Hide();}
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Pbodp23k3Click(TObject *Sender)
{
if(Ppodp23k3->Visible==false)
goto Bir;
if(Ppodp23k3->Visible==true)
goto Iki;

Bir:{
Pbodp23k3->Glyph->LoadFromFile("Images\\sola.bmp");
Ppodp23k3->Show();
goto son;}
Iki:{
 Pbodp23k3->Glyph->LoadFromFile("Images\\saga.bmp");
Ppodp23k3->Hide();}
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Pbodp23k4Click(TObject *Sender)
{
if(Ppodp23k4->Visible==false)
goto Bir;
if(Ppodp23k4->Visible==true)
goto Iki;

Bir:{
Pbodp23k4->Glyph->LoadFromFile("Images\\sola.bmp");
Ppodp23k4->Show();
goto son;}
Iki:{
 Pbodp23k4->Glyph->LoadFromFile("Images\\saga.bmp");
Ppodp23k4->Hide();}
son:;
}
//---------------------------------------------------------------------------






void __fastcall TForm3::EdgevarClick(TObject *Sender)
{
if(Seksay->ItemIndex<0){
ShowMessage("SEKTORLERIN SAYINI DAXIL ET!");
Edgeyoxdu->Checked=true;
goto son;}

Edge->Visible=true;

Etru1k1->Visible=true;
Etru2k1->Visible=true;
Etru3k1->Visible=true;
Etru4k1->Visible=true;
Etru5k1->Visible=true;
Etru6k1->Visible=true;
Etru7k1->Visible=true;
Etru8k1->Visible=true;
Etru9k1->Visible=true;
Etru10k1->Visible=true;
Etru11k1->Visible=true;
Etru12k1->Visible=true;

Etru1k2->Visible=true;
Etru2k2->Visible=true;
Etru3k2->Visible=true;
Etru4k2->Visible=true;
Etru5k2->Visible=true;
Etru6k2->Visible=true;
Etru7k2->Visible=true;
Etru8k2->Visible=true;
Etru9k2->Visible=true;
Etru10k2->Visible=true;
Etru11k2->Visible=true;
Etru12k2->Visible=true;

Etru1k3->Visible=true;
Etru2k3->Visible=true;
Etru3k3->Visible=true;
Etru4k3->Visible=true;
Etru5k3->Visible=true;
Etru6k3->Visible=true;
Etru7k3->Visible=true;
Etru8k3->Visible=true;
Etru9k3->Visible=true;
Etru10k3->Visible=true;
Etru11k3->Visible=true;
Etru12k3->Visible=true;

Etru1k4->Visible=true;
Etru2k4->Visible=true;
Etru3k4->Visible=true;
Etru4k4->Visible=true;
Etru5k4->Visible=true;
Etru6k4->Visible=true;
Etru7k4->Visible=true;
Etru8k4->Visible=true;
Etru9k4->Visible=true;
Etru10k4->Visible=true;
Etru11k4->Visible=true;
Etru12k4->Visible=true;

Eodp01k1->Visible=true;
Eodp23k1->Visible=true;

Eodp01k2->Visible=true;
Eodp23k2->Visible=true;

Eodp01k3->Visible=true;
Eodp23k3->Visible=true;

Eodp01k4->Visible=true;
Eodp23k4->Visible=true;

son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::EdgeyoxduClick(TObject *Sender)
{
Edge->Visible=false;
Etru1k1->Hide();
Etru2k1->Hide();
Etru3k1->Hide();
Etru4k1->Hide();
Etru5k1->Hide();
Etru6k1->Hide();
Etru7k1->Hide();
Etru8k1->Hide();
Etru9k1->Hide();
Etru10k1->Hide();
Etru11k1->Hide();
Etru12k1->Hide();

Etru1k2->Hide();
Etru2k2->Hide();
Etru3k2->Hide();
Etru4k2->Hide();
Etru5k2->Hide();
Etru6k2->Hide();
Etru7k2->Hide();
Etru8k2->Hide();
Etru9k2->Hide();
Etru10k2->Hide();
Etru11k2->Hide();
Etru12k2->Hide();

Etru1k3->Hide();
Etru2k3->Hide();
Etru3k3->Hide();
Etru4k3->Hide();
Etru5k3->Hide();
Etru6k3->Hide();
Etru7k3->Hide();
Etru8k3->Hide();
Etru9k3->Hide();
Etru10k3->Hide();
Etru11k3->Hide();
Etru12k3->Hide();

Etru1k4->Hide();
Etru2k4->Hide();
Etru3k4->Hide();
Etru4k4->Hide();
Etru5k4->Hide();
Etru6k4->Hide();
Etru7k4->Hide();
Etru8k4->Hide();
Etru9k4->Hide();
Etru10k4->Hide();
Etru11k4->Hide();
Etru12k4->Hide();

Eodp01k1->Hide();
Eodp23k1->Hide();

Eodp01k2->Hide();
Eodp23k2->Hide();

Eodp01k3->Hide();
Eodp23k3->Hide();

Eodp01k4->Hide();
Eodp23k4->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Timerc1Timer(TObject *Sender)
{

if(p<620)
Edgec1->Width=p;
p+=10;
if(l<175)
Edgec1->Height=l;
l+=3;
}
//---------------------------------------------------------------------------




void __fastcall TForm3::Cell1Change(TObject *Sender)
{
if(Cell1->GetTextLen()>=6){
Form2->Cell1->Text=Cell1->Text;
Form2->Cell1Change(Form2->Cell1);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru1k1Click(TObject *Sender)
{
if(Etru1k1->Color==clAqua){
Etru1k1->Color=clBtnFace;
goto son;}
Etru1k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru2k1Click(TObject *Sender)
{
if(Etru2k1->Color==clAqua){
Etru2k1->Color=clBtnFace;
goto son;}
Etru2k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru3k1Click(TObject *Sender)
{
if(Etru3k1->Color==clAqua){
Etru3k1->Color=clBtnFace;
goto son;}
Etru3k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru4k1Click(TObject *Sender)
{
if(Etru4k1->Color==clAqua){
Etru4k1->Color=clBtnFace;
goto son;}
Etru4k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru5k1Click(TObject *Sender)
{
if(Etru5k1->Color==clAqua){
Etru5k1->Color=clBtnFace;
goto son;}
Etru5k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru6k1Click(TObject *Sender)
{
if(Etru6k1->Color==clAqua){
Etru6k1->Color=clBtnFace;
goto son;}
Etru6k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru7k1Click(TObject *Sender)
{
if(Etru7k1->Color==clAqua){
Etru7k1->Color=clBtnFace;
goto son;}
Etru7k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru8k1Click(TObject *Sender)
{
if(Etru8k1->Color==clAqua){
Etru8k1->Color=clBtnFace;
goto son;}
Etru8k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru9k1Click(TObject *Sender)
{
if(Etru9k1->Color==clAqua){
Etru9k1->Color=clBtnFace;
goto son;}
Etru9k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru10k1Click(TObject *Sender)
{
if(Etru10k1->Color==clAqua){
Etru10k1->Color=clBtnFace;
goto son;}
Etru10k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru11k1Click(TObject *Sender)
{
if(Etru11k1->Color==clAqua){
Etru11k1->Color=clBtnFace;
goto son;}
Etru11k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru12k1Click(TObject *Sender)
{
if(Etru12k1->Color==clAqua){
Etru12k1->Color=clBtnFace;
goto son;}
Etru12k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru1k2Click(TObject *Sender)
{
if(Etru1k2->Color==clAqua){
Etru1k2->Color=clBtnFace;
goto son;}
Etru1k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru2k2Click(TObject *Sender)
{
if(Etru2k2->Color==clAqua){
Etru2k2->Color=clBtnFace;
goto son;}
Etru2k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru3k2Click(TObject *Sender)
{
if(Etru3k2->Color==clAqua){
Etru3k2->Color=clBtnFace;
goto son;}
Etru3k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru4k2Click(TObject *Sender)
{
if(Etru4k2->Color==clAqua){
Etru4k2->Color=clBtnFace;
goto son;}
Etru4k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru5k2Click(TObject *Sender)
{
if(Etru5k2->Color==clAqua){
Etru5k2->Color=clBtnFace;
goto son;}
Etru5k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru6k2Click(TObject *Sender)
{
if(Etru6k2->Color==clAqua){
Etru6k2->Color=clBtnFace;
goto son;}
Etru6k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru7k2Click(TObject *Sender)
{
if(Etru7k2->Color==clAqua){
Etru7k2->Color=clBtnFace;
goto son;}
Etru7k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru8k2Click(TObject *Sender)
{
if(Etru8k2->Color==clAqua){
Etru8k2->Color=clBtnFace;
goto son;}
Etru8k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru9k2Click(TObject *Sender)
{
if(Etru9k2->Color==clAqua){
Etru9k2->Color=clBtnFace;
goto son;}
Etru9k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru10k2Click(TObject *Sender)
{
if(Etru10k2->Color==clAqua){
Etru10k2->Color=clBtnFace;
goto son;}
Etru10k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru11k2Click(TObject *Sender)
{
if(Etru11k2->Color==clAqua){
Etru11k2->Color=clBtnFace;
goto son;}
Etru11k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru12k2Click(TObject *Sender)
{
if(Etru12k2->Color==clAqua){
Etru12k2->Color=clBtnFace;
goto son;}
Etru12k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru1k3Click(TObject *Sender)
{
if(Etru1k3->Color==clAqua){
Etru1k3->Color=clBtnFace;
goto son;}
Etru1k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru2k3Click(TObject *Sender)
{
if(Etru2k3->Color==clAqua){
Etru2k3->Color=clBtnFace;
goto son;}
Etru2k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru3k3Click(TObject *Sender)
{
if(Etru3k3->Color==clAqua){
Etru3k3->Color=clBtnFace;
goto son;}
Etru3k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru4k3Click(TObject *Sender)
{
if(Etru4k3->Color==clAqua){
Etru4k3->Color=clBtnFace;
goto son;}
Etru4k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru5k3Click(TObject *Sender)
{
if(Etru5k3->Color==clAqua){
Etru5k3->Color=clBtnFace;
goto son;}
Etru5k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru6k3Click(TObject *Sender)
{
if(Etru6k3->Color==clAqua){
Etru6k3->Color=clBtnFace;
goto son;}
Etru6k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru7k3Click(TObject *Sender)
{
if(Etru7k3->Color==clAqua){
Etru7k3->Color=clBtnFace;
goto son;}
Etru7k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru8k3Click(TObject *Sender)
{
if(Etru8k3->Color==clAqua){
Etru8k3->Color=clBtnFace;
goto son;}
Etru8k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru9k3Click(TObject *Sender)
{
if(Etru9k3->Color==clAqua){
Etru9k3->Color=clBtnFace;
goto son;}
Etru9k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru10k3Click(TObject *Sender)
{
if(Etru10k3->Color==clAqua){
Etru10k3->Color=clBtnFace;
goto son;}
Etru10k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru11k3Click(TObject *Sender)
{
if(Etru11k3->Color==clAqua){
Etru11k3->Color=clBtnFace;
goto son;}
Etru11k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru12k3Click(TObject *Sender)
{
if(Etru12k3->Color==clAqua){
Etru12k3->Color=clBtnFace;
goto son;}
Etru12k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru1k4Click(TObject *Sender)
{
if(Etru1k4->Color==clAqua){
Etru1k4->Color=clBtnFace;
goto son;}
Etru1k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru2k4Click(TObject *Sender)
{
if(Etru2k4->Color==clAqua){
Etru2k4->Color=clBtnFace;
goto son;}
Etru2k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru3k4Click(TObject *Sender)
{
if(Etru3k4->Color==clAqua){
Etru3k4->Color=clBtnFace;
goto son;}
Etru3k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru4k4Click(TObject *Sender)
{
if(Etru4k4->Color==clAqua){
Etru4k4->Color=clBtnFace;
goto son;}
Etru4k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru5k4Click(TObject *Sender)
{
if(Etru5k4->Color==clAqua){
Etru5k4->Color=clBtnFace;
goto son;}
Etru5k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru6k4Click(TObject *Sender)
{
if(Etru6k4->Color==clAqua){
Etru6k4->Color=clBtnFace;
goto son;}
Etru6k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru7k4Click(TObject *Sender)
{
if(Etru7k4->Color==clAqua){
Etru7k4->Color=clBtnFace;
goto son;}
Etru7k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru8k4Click(TObject *Sender)
{
if(Etru8k4->Color==clAqua){
Etru8k4->Color=clBtnFace;
goto son;}
Etru8k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru9k4Click(TObject *Sender)
{
if(Etru9k4->Color==clAqua){
Etru9k4->Color=clBtnFace;
goto son;}
Etru9k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru10k4Click(TObject *Sender)
{
if(Etru10k4->Color==clAqua){
Etru10k4->Color=clBtnFace;
goto son;}
Etru10k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru11k4Click(TObject *Sender)
{
if(Etru11k4->Color==clAqua){
Etru11k4->Color=clBtnFace;
goto son;}
Etru11k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Etru12k4Click(TObject *Sender)
{
if(Etru12k4->Color==clAqua){
Etru12k4->Color=clBtnFace;
goto son;}
Etru12k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Eodp01k1Click(TObject *Sender)
{
if(Eodp01k1->Color==clAqua){
Eodp01k1->Color=clBtnFace;
goto son;}
Eodp01k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Eodp23k1Click(TObject *Sender)
{
if(Eodp23k1->Color==clAqua){
Eodp23k1->Color=clBtnFace;
goto son;}
Eodp23k1->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Eodp01k2Click(TObject *Sender)
{
if(Eodp01k2->Color==clAqua){
Eodp01k2->Color=clBtnFace;
goto son;}
Eodp01k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Eodp23k2Click(TObject *Sender)
{
if(Eodp23k2->Color==clAqua){
Eodp23k2->Color=clBtnFace;
goto son;}
Eodp23k2->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Eodp01k3Click(TObject *Sender)
{
if(Eodp01k3->Color==clAqua){
Eodp01k3->Color=clBtnFace;
goto son;}
Eodp01k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Eodp01k4Click(TObject *Sender)
{
if(Eodp01k4->Color==clAqua){
Eodp01k4->Color=clBtnFace;
goto son;}
Eodp01k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Eodp23k3Click(TObject *Sender)
{
if(Eodp23k3->Color==clAqua){
Eodp23k3->Color=clBtnFace;
goto son;}
Eodp23k3->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Eodp23k4Click(TObject *Sender)
{
if(Eodp23k4->Color==clAqua){
Eodp23k4->Color=clBtnFace;
goto son;}
Eodp23k4->Color=clAqua;
son:;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::RbltbufferDblClick(TObject *Sender)
{
for(int f=0;f<Memo1->Lines->Count;f++)
if(Memo1->Lines->Strings[f]=="")
{
Memo1->Lines->Delete(f);
f--;
}

for(int o=0;o<Rbltbuffer->Lines->Count-1;o++)
for(int p=o+1;p<Rbltbuffer->Lines->Count;p++)
if(Rbltbuffer->Lines->Strings[p]==Rbltbuffer->Lines->Strings[o])
{
Rbltbuffer->Lines->Delete(p);
p--;
}

Rbltsayi->ItemIndex=Rbltbuffer->Lines->Count-1;
Form3->RbltsayiChange(Rbltsayi);
if(Rbltsayi->ItemIndex>=0)
Rblt1->Text=Rbltbuffer->Lines->Strings[0];
if(Rbltsayi->ItemIndex>=1)
Rblt2->Text=Rbltbuffer->Lines->Strings[1];
if(Rbltsayi->ItemIndex>=2)
Rblt3->Text=Rbltbuffer->Lines->Strings[2];
if(Rbltsayi->ItemIndex>=3)
Rblt4->Text=Rbltbuffer->Lines->Strings[3];
Form3->RbltsayiChange(Rbltsayi);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Swverk1Change(TObject *Sender)
{
if(K2->Visible==true)
Swverk2->ItemIndex=Swverk1->ItemIndex;
if(K3->Visible==true)
Swverk3->ItemIndex=Swverk1->ItemIndex;
if(K4->Visible==true)
Swverk4->ItemIndex=Swverk1->ItemIndex;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::RxtcpPanelClick(TObject *Sender)
{

//----------------------------Qebul-----------------------------------

if(Komanda=="RXTCP:MOTY=RXOTG,CELL="+Form6->Cell1->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("RXOTG-"))
    Form3->Tgbuffer->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTG+6,10)));

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     TG1="OK";
     if(Form6->Cell2->Visible==false)
     Komanda="RXTCPCIXIS";
    }

   }

   goto KOM;
  }



if(Komanda=="RXTCP:MOTY=RXOTG,CELL="+Form6->Cell2->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("RXOTG-"))
    Form3->Tgbuffer->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTG+6,10)));


    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     TG2="OK";
     if(Form6->Cell3->Visible==false)
     Komanda="RXTCPCIXIS";
    }

  }

   goto KOM;
  }



if(Komanda=="RXTCP:MOTY=RXOTG,CELL="+Form6->Cell3->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("RXOTG-"))
    Form3->Tgbuffer->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTG+6,10)));

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     TG3="OK";
     if(Form6->Cell4->Visible==false)
     Komanda="RXTCPCIXIS";
    }

    }

   goto KOM;
  }

  

if(Komanda=="RXTCP:MOTY=RXOTG,CELL="+Form6->Cell4->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("RXOTG-"))
    Form3->Tgbuffer->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTG+6,10)));

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="RXTCPCIXIS";
     TG4="OK";
     }

    }

    goto KOM;
  }


//--------------------------------------Komandalar----------------------------
KOM:
if(Komanda=="NOVBETI" && TG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXTCP:MOTY=RXOTG,CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }


if(Form6->Cell2->Visible==true && Komanda=="NOVBETI" && TG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXTCP:MOTY=RXOTG,CELL="+Form6->Cell2->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Form6->Cell3->Visible==true && Komanda=="NOVBETI" && TG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXTCP:MOTY=RXOTG,CELL="+Form6->Cell3->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Form6->Cell4->Visible==true && Komanda=="NOVBETI" && TG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXTCP:MOTY=RXOTG,CELL="+Form6->Cell4->Text+";";
  Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Komanda=="RXTCPCIXIS")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="RXAPP";
   Form3->TgbufferDblClick(Tgbuffer);
   Form3->IdTelnet1->WriteLn("");
   }

 son: 
}
//---------------------------------------------------------------------------












void __fastcall TForm3::RxappPanelClick(TObject *Sender)
{

//--------------------------------------RBLT-qebul---------------------------//

if(Komanda=="RXAPP:MO=RXOTG-"+Form3->Tg1->Text+";")
{
 Form3->Rbltbuffer->Clear();
 Devk1CheckBox->Checked=true;
 Tpk1->ItemIndex=1;
        String z[4][100];
        int a=0,b=0,DCP,EDGE;
  for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
  if(int DCPB=Form6->Memo1->Lines->Strings[I].Pos("DCP"))
  DCP=DCPB;
  if(int EDGEB=Form6->Memo1->Lines->Strings[I].Pos("64K"))
  EDGE=EDGEB;

  int RXOTGA = Form6->Memo1->Lines->Strings[I].Pos("RBLT2-");
  int RXOTGB = Form6->Memo1->Lines->Strings[I].Pos("RBLT-");
    if (RXOTGA)
    {
    Form3->Rbltbuffer->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGA+6,9)));
      if(Trim(Form6->Memo1->Lines->Strings[I].SubString(EDGE,4))=="YES")
      {
      z[0][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGA+6,9));   // Edge ucun dev
      z[1][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));        // Edge ucun dcp
      a++;
      }
      else
      {
      z[2][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGA+6,9));   // Adi dev
      z[3][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));         //Adi dcp
      b++;
      }
    }
    //BSC1,5 ucun taplmasi
    if (RXOTGB)
    {
    Form3->Rbltbuffer->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGB+5,8)));
      if(Trim(Form6->Memo1->Lines->Strings[I].SubString(EDGE,4))=="YES")
      {
      z[0][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGB+5,8));
      z[1][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));
      a++;
      }
      else
      {
      z[2][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGB+5,8));
      z[3][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));
      b++;
      }
    }

    if (int END = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
    RBLT1="OK";
    Komanda="NOVBETI";
      // z[3][b] massivinden secib lazimlilarin yigilmasi;

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[0][l]);
    Form3->Memo1DblClick(Memo1);
    Devek1Edit->Text=Edits;
    Form3->Devek1EditDblClick(Devek1Edit);

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[1][l]);
    Form3->Memo1DblClick(Memo1);
    Dcpek1Edit->Text=Edits;

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[2][l]);
    Form3->Memo1DblClick(Memo1);
    Devk1Edit->Text=Edits;
    Form3->Devk1EditDblClick(Devk1Edit);

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[3][l]);
    Form3->Memo1DblClick(Memo1);
    Dcpk1Edit->Text=Edits;

      if(Form3->Tg2->Visible==false)
      {
      Komanda="RXAPPCIXIS";
          for(int p=0;p<Rbltbuffer->Lines->Count;p++)
          {
          String a=Rbltbuffer->Lines->Strings[p];
          Rbltbuffer->Lines->Strings[p]=a/32;
          }
      Form3->RbltbufferDblClick(Form3->Rbltbuffer);
      }

    }
   }

    goto KOM;
}

if(Komanda=="RXAPP:MO=RXOTG-"+Form3->Tg2->Text+";")
{
Devk2CheckBox->Checked=true;
Tpk2->ItemIndex=1;
  String z[4][100];
  int a=0,b=0,DCP,EDGE;

 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
  if(int DCPB=Form6->Memo1->Lines->Strings[I].Pos("DCP"))
  DCP=DCPB;
  if(int EDGEB=Form6->Memo1->Lines->Strings[I].Pos("64K"))
  EDGE=EDGEB;
  int RXOTGA = Form6->Memo1->Lines->Strings[I].Pos("RBLT2-");
  int RXOTGB = Form6->Memo1->Lines->Strings[I].Pos("RBLT-");
    if (RXOTGA)
    {
    Form3->Rbltbuffer->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGA+6,9)));
      if(Trim(Form6->Memo1->Lines->Strings[I].SubString(EDGE,4))=="YES")
      {
      z[0][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGA+6,9));   // Edge ucun dev
      z[1][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));        // Edge ucun dcp
      a++;
      }
      else
      {
      z[2][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGA+6,9));   // Adi dev
      z[3][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));         //Adi dcp
      b++;
      }
    }
    if (RXOTGB)
    {
    Form3->Rbltbuffer->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGB+5,8)));
     if(Trim(Form6->Memo1->Lines->Strings[I].SubString(EDGE,4))=="YES")
      {
      z[0][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGB+5,8));
      z[1][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));
      a++;
      }
      else
      {
      z[2][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGB+5,8));
      z[3][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));
      b++;
      }
    }


    if (int END = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
    RBLT2="OK";
    Komanda="NOVBETI";
      // z[3][b] massivinden secib lazimlilarin yigilmasi;

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[0][l]);
    Form3->Memo1DblClick(Memo1);
    Devek2Edit->Text=Edits;
    Form3->Devek2EditDblClick(Devek2Edit);

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[1][l]);
    Form3->Memo1DblClick(Memo1);
    Dcpek2Edit->Text=Edits;

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[2][l]);
    Form3->Memo1DblClick(Memo1);
    Devk2Edit->Text=Edits;
    Form3->Devk2EditDblClick(Devk2Edit);

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[3][l]);
    Form3->Memo1DblClick(Memo1);
    Dcpk2Edit->Text=Edits;

    if(Form3->Tg3->Visible==false)
    {
    Komanda="RXAPPCIXIS";

        for(int p=0;p<Rbltbuffer->Lines->Count;p++)
        {
        String a=Rbltbuffer->Lines->Strings[p];
        Rbltbuffer->Lines->Strings[p]=a/32;
        }

    Form3->RbltbufferDblClick(Form3->Rbltbuffer);
    }
    }
   }

    goto KOM;
}


if(Komanda=="RXAPP:MO=RXOTG-"+Form3->Tg3->Text+";")
{
  Devk3CheckBox->Checked=true;
  Tpk3->ItemIndex=1;
        String z[4][100];
        int a=0,b=0,DCP,EDGE;
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
   if(int DCPB=Form6->Memo1->Lines->Strings[I].Pos("DCP"))
  DCP=DCPB;
  if(int EDGEB=Form6->Memo1->Lines->Strings[I].Pos("64K"))
  EDGE=EDGEB;
  int RXOTGA = Form6->Memo1->Lines->Strings[I].Pos("RBLT2-");
  int RXOTGB = Form6->Memo1->Lines->Strings[I].Pos("RBLT-");
    if (RXOTGA)
    {
    Form3->Rbltbuffer->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGA+6,9)));
    if(Trim(Form6->Memo1->Lines->Strings[I].SubString(EDGE,4))=="YES")
      {
      z[0][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGA+6,9));   // Edge ucun dev
      z[1][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));        // Edge ucun dcp
      a++;
      }
      else
      {
      z[2][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGA+6,9));   // Adi dev
      z[3][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));         //Adi dcp
      b++;
      }
    }
    if (RXOTGB)
    {
    Form3->Rbltbuffer->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGB+5,8)));
     if(Trim(Form6->Memo1->Lines->Strings[I].SubString(EDGE,4))=="YES")
      {
      z[0][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGB+5,8));
      z[1][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));
      a++;
      }
      else
      {
      z[2][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGB+5,8));
      z[3][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));
      b++;
      }
    }


    if (int END = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
    RBLT3="OK";
    Komanda="NOVBETI";
      // z[3][b] massivinden secib lazimlilarin yigilmasi;

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[0][l]);
    Form3->Memo1DblClick(Memo1);
    Devek3Edit->Text=Edits;
    Form3->Devek3EditDblClick(Devek3Edit);

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[1][l]);
    Form3->Memo1DblClick(Memo1);
    Dcpek3Edit->Text=Edits;

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[2][l]);
    Form3->Memo1DblClick(Memo1);
    Devk3Edit->Text=Edits;
    Form3->Devk3EditDblClick(Devk3Edit);

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[3][l]);
    Form3->Memo1DblClick(Memo1);
    Dcpk3Edit->Text=Edits;

    if(Form3->Tg4->Visible==false)
    {
        Komanda="RXAPPCIXIS";
        for(int p=0;p<Rbltbuffer->Lines->Count;p++)
        {
        String a=Rbltbuffer->Lines->Strings[p];
         Rbltbuffer->Lines->Strings[p]=a/32;
        }

        Form3->RbltbufferDblClick(Form3->Rbltbuffer);
    }

    }
   }

    goto KOM;
}

if(Komanda=="RXAPP:MO=RXOTG-"+Form3->Tg4->Text+";")
{
 Devk4CheckBox->Checked=true;
 Tpk4->ItemIndex=1;
        String z[4][100];
        int a=0,b=0,DCP,EDGE;
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
   if(int DCPB=Form6->Memo1->Lines->Strings[I].Pos("DCP"))
  DCP=DCPB;
  if(int EDGEB=Form6->Memo1->Lines->Strings[I].Pos("64K"))
  EDGE=EDGEB;
  int RXOTGA = Form6->Memo1->Lines->Strings[I].Pos("RBLT2-");
  int RXOTGB = Form6->Memo1->Lines->Strings[I].Pos("RBLT-");
    if (RXOTGA)
    {
    Form3->Rbltbuffer->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGA+6,9)));
     if(Trim(Form6->Memo1->Lines->Strings[I].SubString(EDGE,4))=="YES")
      {
      z[0][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGA+6,9));   // Edge ucun dev
      z[1][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));        // Edge ucun dcp
      a++;
      }
      else
      {
      z[2][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGA+6,9));   // Adi dev
      z[3][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));         //Adi dcp
      b++;
      }
    }
    if (RXOTGB)
    {
    Form3->Rbltbuffer->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGB+5,8)));
    if(Trim(Form6->Memo1->Lines->Strings[I].SubString(EDGE,4))=="YES")
      {
      z[0][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGB+5,8));
      z[1][a]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));
      a++;
      }
      else
      {
      z[2][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(RXOTGB+5,8));
      z[3][b]=Trim(Form6->Memo1->Lines->Strings[I].SubString(DCP,4));
      b++;
      }
    }


    if (int END = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
    RBLT4="OK";
    Komanda="RXAPPCIXIS";
      // z[3][b] massivinden secib lazimlilarin yigilmasi;

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[0][l]);
    Form3->Memo1DblClick(Memo1);
    Devek4Edit->Text=Edits;
    Form3->Devek4EditDblClick(Devek4Edit);

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[1][l]);
    Form3->Memo1DblClick(Memo1);
    Dcpek4Edit->Text=Edits;

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[2][l]);
    Form3->Memo1DblClick(Memo1);
    Devk4Edit->Text=Edits;
    Form3->Devk4EditDblClick(Devk4Edit);

    Memo1->Clear();
    Memo2->Clear();
    for(int l=0;l<=b;l++)
    Memo1->Lines->Add(z[3][l]);
    Form3->Memo1DblClick(Memo1);
    Dcpk4Edit->Text=Edits;

    for(int p=0;p<Rbltbuffer->Lines->Count;p++)
    {
    String a=Rbltbuffer->Lines->Strings[p];
    Rbltbuffer->Lines->Strings[p]=a/32;
    }
    Form3->RbltbufferDblClick(Form3->Rbltbuffer);

    }
   }

    goto KOM;
}

KOM:
 //----------------------------------RBLT-komandalari----------------------------------//

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RBLT1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXAPP:MO=RXOTG-"+Form3->Tg1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RBLT2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXAPP:MO=RXOTG-"+Form3->Tg2->Text+";";
 Form3->IdTelnet1->WriteLn("RXAPP:MO=RXOTG-"+Form3->Tg2->Text+";");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RBLT3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXAPP:MO=RXOTG-"+Form3->Tg3->Text+";";
 Form3->IdTelnet1->WriteLn("RXAPP:MO=RXOTG-"+Form3->Tg3->Text+";");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RBLT4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXAPP:MO=RXOTG-"+Form3->Tg4->Text+";";
 Form3->IdTelnet1->WriteLn("RXAPP:MO=RXOTG-"+Form3->Tg4->Text+";");
  goto son;
  }

if(Komanda=="RXAPPCIXIS")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="RLBDP";
   Form3->IdTelnet1->WriteLn("");
   }

  son:

}
//---------------------------------------------------------------------------

void __fastcall TForm3::RlbdpPanelClick(TObject *Sender)
{
//----------------------------------------RLBDP qebul-------------------------------//
 if(Komanda=="RLBDP:CELL="+Form6->Cell1->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int CHGR,NUMREQEGPRSBPC,NUMREQBPC,NUMREQCS3CS4BPC,TN7BCCH;

    if (int CHGRB=Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
        CHGR=CHGRB;
    if (int NUMREQEGPRSBPCB=Form6->Memo1->Lines->Strings[I].Pos("NUMREQEGPRSBPC"))
        NUMREQEGPRSBPC=NUMREQEGPRSBPCB;
    if (int NUMREQBPCB=Form6->Memo1->Lines->Strings[I].Pos("NUMREQBPC"))
        NUMREQBPC=NUMREQBPCB;
    if (int TN7BCCHB=Form6->Memo1->Lines->Strings[I].Pos("TN7BCCH"))
        TN7BCCH=TN7BCCHB;
    if (int NUMREQCS3CS4BPCB=Form6->Memo1->Lines->Strings[I].Pos("NUMREQCS3CS4BPC"))
        NUMREQCS3CS4BPC=NUMREQCS3CS4BPCB;

    if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="0")
       {
       Form3->Numreqbpcch0c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch0c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch0c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch0c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch0c1->Text)!=0)
       Edgevar->Checked=true;
       }

   if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="1")
       {
       Chgr1c1cbox->Checked=true;
       Form3->Numreqbpcch1c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch1c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch1c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch1c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch1c1->Text)!=0)
       Edgevar->Checked=true;
       }

   if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="2")
       {
       Chgr2c1cbox->Checked=true;
       Form3->Numreqbpcch2c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch2c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch2c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch2c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch2c1->Text)!=0)
       Edgevar->Checked=true;
       }

   if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="3")
       {
       Chgr3c1cbox->Checked=true;
       Form3->Numreqbpcch3c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch3c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch3c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch3c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch3c1->Text)!=0)
       Edgevar->Checked=true;
       }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RLBDPC1="OK";
     if(Form6->Cell2->Visible==false)
     Komanda="RLBDPCIXIS";
    }
  }

    goto KOM;
  }

 if(Komanda=="RLBDP:CELL="+Form6->Cell2->Text+";")
 {
  for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int CHGR,NUMREQEGPRSBPC,NUMREQBPC,NUMREQCS3CS4BPC,TN7BCCH;

    if (int CHGRB=Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
        CHGR=CHGRB;
    if (int NUMREQEGPRSBPCB=Form6->Memo1->Lines->Strings[I].Pos("NUMREQEGPRSBPC"))
        NUMREQEGPRSBPC=NUMREQEGPRSBPCB;
    if (int NUMREQBPCB=Form6->Memo1->Lines->Strings[I].Pos("NUMREQBPC"))
        NUMREQBPC=NUMREQBPCB;
    if (int TN7BCCHB=Form6->Memo1->Lines->Strings[I].Pos("TN7BCCH"))
        TN7BCCH=TN7BCCHB;
    if (int NUMREQCS3CS4BPCB=Form6->Memo1->Lines->Strings[I].Pos("NUMREQCS3CS4BPC"))
        NUMREQCS3CS4BPC=NUMREQCS3CS4BPCB;

    if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="0")
       {
       Form3->Numreqbpcch0c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch0c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch0c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch0c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch0c2->Text)!=0)
       Edgevar->Checked=true;
       }

   if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="1")
       {
       Chgr1c2cbox->Checked=true;
       Form3->Numreqbpcch1c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch1c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch1c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch1c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch1c2->Text)!=0)
       Edgevar->Checked=true;
       }

   if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="2")
       {
       Chgr2c2cbox->Checked=true;
       Form3->Numreqbpcch2c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch2c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch2c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch2c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch2c2->Text)!=0)
       Edgevar->Checked=true;
       }

   if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="3")
       {
       Chgr3c2cbox->Checked=true;
       Form3->Numreqbpcch3c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch3c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch3c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch3c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch3c2->Text)!=0)
       Edgevar->Checked=true;
       }
    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RLBDPC2="OK";
     if(Form6->Cell3->Visible==false)
     Komanda="RLBDPCIXIS";
    }
  }

    goto KOM;
  }

 if(Komanda=="RLBDP:CELL="+Form6->Cell3->Text+";")
 {
  for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int CHGR,NUMREQEGPRSBPC,NUMREQBPC,NUMREQCS3CS4BPC,TN7BCCH;

    if (int CHGRB=Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
        CHGR=CHGRB;
    if (int NUMREQEGPRSBPCB=Form6->Memo1->Lines->Strings[I].Pos("NUMREQEGPRSBPC"))
        NUMREQEGPRSBPC=NUMREQEGPRSBPCB;
    if (int NUMREQBPCB=Form6->Memo1->Lines->Strings[I].Pos("NUMREQBPC"))
        NUMREQBPC=NUMREQBPCB;
    if (int TN7BCCHB=Form6->Memo1->Lines->Strings[I].Pos("TN7BCCH"))
        TN7BCCH=TN7BCCHB;
    if (int NUMREQCS3CS4BPCB=Form6->Memo1->Lines->Strings[I].Pos("NUMREQCS3CS4BPC"))
        NUMREQCS3CS4BPC=NUMREQCS3CS4BPCB;

    if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="0")
       {
       Form3->Numreqbpcch0c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch0c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch0c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch0c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch0c3->Text)!=0)
       Edgevar->Checked=true;
       }

   if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="1")
       {
       Chgr1c3cbox->Checked=true;
       Form3->Numreqbpcch1c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch1c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch1c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch1c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch1c3->Text)!=0)
       Edgevar->Checked=true;
       }

   if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="2")
       {
       Chgr2c3cbox->Checked=true;
       Form3->Numreqbpcch2c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch2c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch2c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch2c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch2c3->Text)!=0)
       Edgevar->Checked=true;
       }

   if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="3")
       {
       Chgr3c3cbox->Checked=true;
       Form3->Numreqbpcch3c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch3c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch3c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch3c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch3c3->Text)!=0)
       Edgevar->Checked=true;
       }
    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RLBDPC3="OK";
     if(Form6->Cell4->Visible==false)
     Komanda="RLBDPCIXIS";
    }
  }

    goto KOM;
  }

 if(Komanda=="RLBDP:CELL="+Form6->Cell4->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int CHGR,NUMREQEGPRSBPC,NUMREQBPC,NUMREQCS3CS4BPC,TN7BCCH;

    if (int CHGRB=Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
        CHGR=CHGRB;
    if (int NUMREQEGPRSBPCB=Form6->Memo1->Lines->Strings[I].Pos("NUMREQEGPRSBPC"))
        NUMREQEGPRSBPC=NUMREQEGPRSBPCB;
    if (int NUMREQBPCB=Form6->Memo1->Lines->Strings[I].Pos("NUMREQBPC"))
        NUMREQBPC=NUMREQBPCB;
    if (int TN7BCCHB=Form6->Memo1->Lines->Strings[I].Pos("TN7BCCH"))
        TN7BCCH=TN7BCCHB;
    if (int NUMREQCS3CS4BPCB=Form6->Memo1->Lines->Strings[I].Pos("NUMREQCS3CS4BPC"))
        NUMREQCS3CS4BPC=NUMREQCS3CS4BPCB;

    if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="0")
       {
       Form3->Numreqbpcch0c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch0c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch0c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch0c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch0c4->Text)!=0)
       Edgevar->Checked=true;
       }

   if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="1")
       {
       Chgr1c4cbox->Checked=true;
       Form3->Numreqbpcch1c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch1c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch1c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch1c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch1c4->Text)!=0)
       Edgevar->Checked=true;
       }

   if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="2")
       {
       Chgr2c4cbox->Checked=true;
       Form3->Numreqbpcch2c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch2c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch2c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch2c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch2c4->Text)!=0)
       Edgevar->Checked=true;
       }

   if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,4))=="3")
       {
       Chgr3c4cbox->Checked=true;
       Form3->Numreqbpcch3c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQBPC,7));
       Form3->Numreqegprsbpcch3c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQEGPRSBPC,7));
       Form3->Numreqcs3cs4bpcch3c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(NUMREQCS3CS4BPC,7));
       Form3->Tn7bcchch3c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(TN7BCCH,7));

       if(StrToInt(Numreqegprsbpcch3c4->Text)!=0)
       Edgevar->Checked=true;
       }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     RLBDPC4="OK";
     Komanda="RLBDPCIXIS";
    }
  }

    goto KOM;
  }

KOM:
//---------------------------------------RLBDP komandalari ------------------//
 if(Giris==true && Komanda=="NOVBETI" &&
Form6->Cell1->Visible==true && RLBDPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLBDP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn("RLBDP:CELL="+Form6->Cell1->Text+";");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form6->Cell2->Visible==true && RLBDPC2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLBDP:CELL="+Form6->Cell2->Text+";";
 Form3->IdTelnet1->WriteLn("RLBDP:CELL="+Form6->Cell2->Text+";");
  goto son;
  }

 if(Giris==true && Komanda=="NOVBETI" &&
Form6->Cell3->Visible==true && RLBDPC3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLBDP:CELL="+Form6->Cell3->Text+";";
 Form3->IdTelnet1->WriteLn("RLBDP:CELL="+Form6->Cell3->Text+";");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form6->Cell4->Visible==true && RLBDPC4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLBDP:CELL="+Form6->Cell4->Text+";";
 Form3->IdTelnet1->WriteLn("RLBDP:CELL="+Form6->Cell4->Text+";");
  goto son;
  }

if(Komanda=="RLBDPCIXIS")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="RXMOP";
   Form3->IdTelnet1->WriteLn("");
   }

son:
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RxmopPanelClick(TObject *Sender)
{
//----------------------------------------RXMOP qebul-----------------------------------------------//
if(Komanda=="RXMOP:MO=RXOTG-"+Form3->Tg1->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int RSITE = Form6->Memo1->Lines->Strings[I].Pos("RSITE"))
    {
    Form2->Rsitec1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(RSITE,16));
    Form2->Rsitec1Change(Form2->Rsitec1);
    }

    if (int FHOP = Form6->Memo1->Lines->Strings[I].Pos("FHOP"))
    {
    String  FHOPS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(FHOP,3));
    if(FHOPS=="SY")
    Fhop->ItemIndex=1;
    else
    Fhop->ItemIndex=0;
    Form3->FhopChange(Fhop);
    }

    if (int SWVERACT = Form6->Memo1->Lines->Strings[I].Pos("SWVERACT"))
    {
    String  SWVERACTS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SWVERACT,11));
    if(SWVERACTS=="B4404R014L")
    Swverk1->ItemIndex=1;
    else
    Swverk1->ItemIndex=0;
    Form3->Swverk1Change(Swverk1);
    }


     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOPTG1="OK";
    }

  }

    goto KOM;
  }
if(Komanda=="DTSTP:DIP="+Form3->Tg1->Text+"ODP1;")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
      if (int ODP=Form6->Memo1->Lines->Strings[I].Pos("STATE"))
      Odp1k1->Checked=true;

      if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
      {
      Komanda="NOVBETI";
      DTSTPTG1ODP1="OK";
      }
    }
    goto KOM;
 }
if(Komanda=="DTSTP:DIP="+Form3->Tg1->Text+"ODP3;")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
      if (int ODP=Form6->Memo1->Lines->Strings[I].Pos("STATE"))
      Odp3k1->Checked=true;

      if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
      {
      Komanda="NOVBETI";
      DTSTPTG1ODP3="OK";
      }
    }
    goto KOM;
 }

if(Komanda=="RXMOP:MO=RXOCF-"+Form3->Tg1->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int TEI = Form6->Memo1->Lines->Strings[I].Pos("TEI"))
    {
    String  TEIS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TEI,3));
    if(TEIS=="62")
    Teik1->ItemIndex=2;
    else if(TEIS=="63")
    Teik1->ItemIndex=3;
    else if(TEIS=="61")
    Teik1->ItemIndex=1;
    }

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOPCF1="OK";
    }
  }
    goto KOM;
 }

if(Komanda=="RXMOP:MO=RXOTF-"+Form3->Tg1->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int TFMODE = Form6->Memo1->Lines->Strings[I].Pos("TFMODE"))
    {
    String  TFMODES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TFMODE,3));
    if(TFMODES=="SA")
    Tfmodek1->ItemIndex=0;
    else if(TFMODES=="M")
    Tfmodek1->ItemIndex=1;
    else if(TFMODES=="S")
    Tfmodek1->ItemIndex=2;
    }

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOPTF1="OK";
     if(Form3->Tg2->Visible==false)
     Komanda="RXMOPCIXIS";
    }
  }
    goto KOM;
 }
 
//Kabinet2
if(Komanda=="RXMOP:MO=RXOTG-"+Form3->Tg2->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int SWVERACT = Form6->Memo1->Lines->Strings[I].Pos("SWVERACT"))
    {
    String  SWVERACTS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SWVERACT,11));
    if(SWVERACTS=="B4404R014L")
    Swverk2->ItemIndex=1;
    else
    Swverk2->ItemIndex=0;
    }

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOPTG2="OK";
    }
  }
    goto KOM;
  }
if(Komanda=="DTSTP:DIP="+Form3->Tg2->Text+"ODP1;")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
      if (int ODP=Form6->Memo1->Lines->Strings[I].Pos("STATE"))
      Odp1k2->Checked=true;

      if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
      {
      Komanda="NOVBETI";
      DTSTPTG2ODP1="OK";
      }
    }
    goto KOM;
 }
if(Komanda=="DTSTP:DIP="+Form3->Tg2->Text+"ODP3;")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
      if (int ODP=Form6->Memo1->Lines->Strings[I].Pos("STATE"))
      Odp3k1->Checked=true;

      if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
      {
      Komanda="NOVBETI";
      DTSTPTG2ODP3="OK";
      }
    }
    goto KOM;
 }
if(Komanda=="RXMOP:MO=RXOCF-"+Form3->Tg2->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int TEI = Form6->Memo1->Lines->Strings[I].Pos("TEI"))
    {
    String  TEIS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TEI,3));
    if(TEIS=="62")
    Teik2->ItemIndex=2;
    else if(TEIS=="63")
    Teik2->ItemIndex=3;
    else if(TEIS=="61")
    Teik2->ItemIndex=1;
    }

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOPCF2="OK";
    }
  }
    goto KOM;
 }

if(Komanda=="RXMOP:MO=RXOTF-"+Form3->Tg2->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int TFMODE = Form6->Memo1->Lines->Strings[I].Pos("TFMODE"))
    {
    String  TFMODES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TFMODE,3));
    if(TFMODES=="SA")
    Tfmodek2->ItemIndex=0;
    else if(TFMODES=="M")
    Tfmodek2->ItemIndex=1;
    else if(TFMODES=="S")
    Tfmodek2->ItemIndex=2;
    }

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOPTF2="OK";
     if(Form3->Tg3->Visible==false)
     Komanda="RXMOPCIXIS";
    }
  }
    goto KOM;
 }

 //Kabinet3
if(Komanda=="RXMOP:MO=RXOTG-"+Form3->Tg3->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int SWVERACT = Form6->Memo1->Lines->Strings[I].Pos("SWVERACT"))
    {
    String  SWVERACTS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SWVERACT,11));
    if(SWVERACTS=="B4404R014L")
    Swverk3->ItemIndex=1;
    else
    Swverk3->ItemIndex=0;
    }

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOPTG3="OK";
    }
  }
    goto KOM;
  }
if(Komanda=="DTSTP:DIP="+Form3->Tg3->Text+"ODP1;")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
      if (int ODP=Form6->Memo1->Lines->Strings[I].Pos("STATE"))
      Odp1k3->Checked=true;

      if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
      {
      Komanda="NOVBETI";
      DTSTPTG3ODP1="OK";
      }
    }
    goto KOM;
 }
if(Komanda=="DTSTP:DIP="+Form3->Tg3->Text+"ODP3;")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
      if (int ODP=Form6->Memo1->Lines->Strings[I].Pos("STATE"))
      Odp3k3->Checked=true;

      if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
      {
      Komanda="NOVBETI";
      DTSTPTG3ODP3="OK";
      }
    }
    goto KOM;
 }
if(Komanda=="RXMOP:MO=RXOCF-"+Form3->Tg3->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int TEI = Form6->Memo1->Lines->Strings[I].Pos("TEI"))
    {
    String  TEIS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TEI,3));
    if(TEIS=="62")
    Teik3->ItemIndex=2;
    else if(TEIS=="63")
    Teik3->ItemIndex=3;
    else if(TEIS=="61")
    Teik3->ItemIndex=1;
    }

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOPCF3="OK";
    }
  }
    goto KOM;
 }

if(Komanda=="RXMOP:MO=RXOTF-"+Form3->Tg3->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int TFMODE = Form6->Memo1->Lines->Strings[I].Pos("TFMODE"))
    {
    String  TFMODES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TFMODE,3));
    if(TFMODES=="SA")
    Tfmodek3->ItemIndex=0;
    else if(TFMODES=="M")
    Tfmodek3->ItemIndex=1;
    else if(TFMODES=="S")
    Tfmodek3->ItemIndex=2;
    }

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOPTF3="OK";
     if(Form3->Tg4->Visible==false)
     Komanda="RXMOPCIXIS";
    }
  }
    goto KOM;
 }

 //Kabinet 4
if(Komanda=="RXMOP:MO=RXOTG-"+Form3->Tg4->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int SWVERACT = Form6->Memo1->Lines->Strings[I].Pos("SWVERACT"))
    {
    String  SWVERACTS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SWVERACT,11));
    if(SWVERACTS=="B4404R014L")
    Swverk4->ItemIndex=1;
    else
    Swverk4->ItemIndex=0;
    }

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="RXMOPCIXIS";
     RXMOPTG2="OK";
    }
  }
    goto KOM;
  }
if(Komanda=="DTSTP:DIP="+Form3->Tg4->Text+"ODP1;")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
      if (int ODP=Form6->Memo1->Lines->Strings[I].Pos("STATE"))
      Odp1k4->Checked=true;

      if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
      {
      Komanda="NOVBETI";
      DTSTPTG4ODP1="OK";
      }
    }
    goto KOM;
 }
if(Komanda=="DTSTP:DIP="+Form3->Tg4->Text+"ODP3;")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
      if (int ODP=Form6->Memo1->Lines->Strings[I].Pos("STATE"))
      Odp3k4->Checked=true;

      if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
      {
      Komanda="NOVBETI";
      DTSTPTG4ODP3="OK";
      }
    }
    goto KOM;
 }
if(Komanda=="RXMOP:MO=RXOCF-"+Form3->Tg4->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int TEI = Form6->Memo1->Lines->Strings[I].Pos("TEI"))
    {
    String  TEIS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TEI,3));
    if(TEIS=="62")
    Teik4->ItemIndex=2;
    else if(TEIS=="63")
    Teik4->ItemIndex=3;
    else if(TEIS=="61")
    Teik4->ItemIndex=1;
    }

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOPCF4="OK";
    }
  }
    goto KOM;
 }

if(Komanda=="RXMOP:MO=RXOTF-"+Form3->Tg4->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int TFMODE = Form6->Memo1->Lines->Strings[I].Pos("TFMODE"))
    {
    String  TFMODES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TFMODE,3));
    if(TFMODES=="SA")
    Tfmodek4->ItemIndex=0;
    else if(TFMODES=="M")
    Tfmodek4->ItemIndex=2;
    else if(TFMODES=="S")
    Tfmodek4->ItemIndex=2;
    }

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     RXMOPTF4="OK";
     Komanda="RXMOPCIXIS";
    }
  }
    goto KOM;
 }


KOM:
//-------------------------------------------RXMOP komandalari-----------------------------//
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOPTG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTG-"+Form3->Tg1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && DTSTPTG1ODP1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="DTSTP:DIP="+Form3->Tg1->Text+"ODP1;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && DTSTPTG1ODP3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="DTSTP:DIP="+Form3->Tg1->Text+"ODP3;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOPCF1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOCF-"+Form3->Tg1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOPTF1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTF-"+Form3->Tg1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }


if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOPTG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTG-"+Form3->Tg2->Text+";";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTG-"+Form3->Tg2->Text+";");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && DTSTPTG2ODP1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="DTSTP:DIP="+Form3->Tg2->Text+"ODP1;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && DTSTPTG2ODP3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="DTSTP:DIP="+Form3->Tg2->Text+"ODP3;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOPCF2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOCF-"+Form3->Tg2->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOPTF2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTF-"+Form3->Tg2->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOPTG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTG-"+Form3->Tg3->Text+";";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTG-"+Form3->Tg3->Text+";");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && DTSTPTG3ODP1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="DTSTP:DIP="+Form3->Tg3->Text+"ODP1;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && DTSTPTG3ODP3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="DTSTP:DIP="+Form3->Tg3->Text+"ODP3;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOPCF3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOCF-"+Form3->Tg3->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOPTF3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTF-"+Form3->Tg3->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOPTG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTG-"+Form3->Tg4->Text+";";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTG-"+Form3->Tg4->Text+";");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && DTSTPTG4ODP1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="DTSTP:DIP="+Form3->Tg4->Text+"ODP1;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && DTSTPTG4ODP3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="DTSTP:DIP="+Form3->Tg4->Text+"ODP3;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOPCF4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOCF-"+Form3->Tg4->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOPTF4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTF-"+Form3->Tg4->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

  if(Komanda=="RXMOPCIXIS")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="RLDEP";
   Form3->IdTelnet1->WriteLn("");
   }

son:



}
//---------------------------------------------------------------------------



void __fastcall TForm3::RldepPanelClick(TObject *Sender)
{
//-------------------------------------RLDEPC1 qebul----------------------//
if(Komanda=="RLDEP:CELL="+Form6->Cell1->Text+";")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int CSYSTYPE = Form6->Memo1->Lines->Strings[I].Pos("CSYSTYPE"))
        {
        String  CSYSTYPES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CSYSTYPE,8));
        if(CSYSTYPES=="GSM900")
        Form3->Csystype->ItemIndex=0;
        else
        Form3->Csystype->ItemIndex=1;
        Form3->CsystypeChange(Csystype);
        }

        if (int BCCHNO=Form6->Memo1->Lines->Strings[I].Pos("BCCHNO"))
        Form2->Bcchnoc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BCCHNO,4));

        if (int CGI = Form6->Memo1->Lines->Strings[I].Pos("CGI"))
        {
         Form2->Cgibufedt->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CGI,20));
         Form3->Siteno->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CGI,20));

         Form2->Cgibufedt->Text=Form2->Cgibufedt->Text.SubString(8,4);
         String SPF=Form2->Cgibufedt->Text.c_str();
         if(SPF[4]=='-')
         {
         Form2->Bscc1->Text=Trim(Form2->Cgibufedt->Text.SubString(0,1));
         Form2->Bscc1Change(Form2->Bscc1);
         }
         else
         {
         Form2->Bscc1->Text=Trim(Form2->Cgibufedt->Text.SubString(0,2));
         Form2->Bscc1Change(Form2->Bscc1);
         }

         String SITENO=Form3->Siteno->Text.c_str();
         for(int h=Form3->Siteno->GetTextLen();h>0;h--)
         if(SITENO[h]=='-'){
         Form3->Siteno->Text=Form3->Siteno->Text.SubString(h+1,Siteno->GetTextLen()-h-1);
         break;}
         }

        if (int BSIC=Form6->Memo1->Lines->Strings[I].Pos("BSIC"))
        Form2->Bsicc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BSIC,4));

        if (int XRANGE = Form6->Memo1->Lines->Strings[I].Pos("XRANGE")){
        String  XRANGES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(XRANGE,3));
        if(XRANGES=="YES")
        Form2->Xrangec1->ItemIndex=0;
        else
        Form2->Xrangec1->ItemIndex=1;}

        if (int AGBLK=Form6->Memo1->Lines->Strings[I].Pos("AGBLK"))
        Form2->Agblk->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(AGBLK,2));

        if (int MFRMS=Form6->Memo1->Lines->Strings[I].Pos("MFRMS"))
        Form2->Mfrms->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(MFRMS,2));

        if (int BCCHTYPE=Form6->Memo1->Lines->Strings[I].Pos("BCCHTYPE")){
        String  BCCHTYPES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BCCHTYPE,6));
        if(BCCHTYPES=="COMBC")
        Form2->Bcchtype->ItemIndex=1;
        else if(BCCHTYPES=="NCOMB")
        Form2->Bcchtype->ItemIndex=2;
        else
        Form2->Bcchtype->ItemIndex=0;}

        if (int CGI=Form6->Memo1->Lines->Strings[I].Pos("CGI "))
        Form2->Cgic1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CGI,20));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
     Komanda="NOVBETI";
     RLDEPC1="OK";
     if(Form6->Cell2->Visible==false)
     Komanda="RXDEPCIXIS";
        goto KOM;
        }

    }

 }

//-------------------------------------RLDEPC2 qebul----------------------//
if(Komanda=="RLDEP:CELL="+Form6->Cell2->Text+";")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int BCCHNO=Form6->Memo1->Lines->Strings[I].Pos("BCCHNO"))
        Form2->Bcchnoc2->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BCCHNO,4));

        if (int BSIC=Form6->Memo1->Lines->Strings[I].Pos("BSIC"))
        Form2->Bsicc2->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BSIC,4));

        if (int XRANGE = Form6->Memo1->Lines->Strings[I].Pos("XRANGE")){
        String  XRANGES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(XRANGE,3));
        if(XRANGES=="YES")
        Form2->Xrangec2->ItemIndex=0;
        else
        Form2->Xrangec2->ItemIndex=1;}

        if (int CGI=Form6->Memo1->Lines->Strings[I].Pos("CGI "))
        Form2->Cgic2->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CGI,20));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
     Komanda="NOVBETI";
     RLDEPC2="OK";
     if(Form6->Cell3->Visible==false)
     Komanda="RXDEPCIXIS";
        goto KOM;
        }
    }
 }

//-------------------------------------RLDEPC3 qebul----------------------//
if(Komanda=="RLDEP:CELL="+Form6->Cell3->Text+";")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int BCCHNO=Form6->Memo1->Lines->Strings[I].Pos("BCCHNO"))
        Form2->Bcchnoc3->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BCCHNO,4));

        if (int BSIC=Form6->Memo1->Lines->Strings[I].Pos("BSIC"))
        Form2->Bsicc3->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BSIC,4));

        if (int XRANGE = Form6->Memo1->Lines->Strings[I].Pos("XRANGE")){
        String  XRANGES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(XRANGE,3));
        if(XRANGES=="YES")
        Form2->Xrangec3->ItemIndex=0;
        else
        Form2->Xrangec3->ItemIndex=1;}

        if (int CGI=Form6->Memo1->Lines->Strings[I].Pos("CGI "))
        Form2->Cgic3->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CGI,20));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
     Komanda="NOVBETI";
     RLDEPC3="OK";
     if(Form6->Cell4->Visible==false)
     Komanda="RXDEPCIXIS";
        goto KOM;
        }
    }
 }
//-------------------------------------RLDEPC4 qebul----------------------//
if(Komanda=="RLDEP:CELL="+Form6->Cell4->Text+";")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int BCCHNO=Form6->Memo1->Lines->Strings[I].Pos("BCCHNO"))
        Form2->Bcchnoc4->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BCCHNO,4));

        if (int BSIC=Form6->Memo1->Lines->Strings[I].Pos("BSIC"))
        Form2->Bsicc4->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BSIC,4));

        if (int XRANGE = Form6->Memo1->Lines->Strings[I].Pos("XRANGE")){
        String  XRANGES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(XRANGE,3));
        if(XRANGES=="YES")
        Form2->Xrangec4->ItemIndex=0;
        else
        Form2->Xrangec4->ItemIndex=1;}

        if (int CGI=Form6->Memo1->Lines->Strings[I].Pos("CGI "))
        Form2->Cgic4->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CGI,20));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
     Komanda="RXDEPCIXIS";
     RLDEPC4="OK";
        goto KOM;
        }
    }
 }

 KOM:

 //--------------------------------------RLDEP komandalari----------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLDEPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLDEP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn("RLDEP:CELL="+Form6->Cell1->Text+";");
  goto son;
  }
//--------------------------------------RLDEPC2 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" &&
Form6->Cell2->Visible==true && RLDEPC2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLDEP:CELL="+Form6->Cell2->Text+";";
 Form3->IdTelnet1->WriteLn("RLDEP:CELL="+Form6->Cell2->Text+";");
  goto son;
  }

//--------------------------------------RLDEPC3 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" &&
Form6->Cell3->Visible==true && RLDEPC3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLDEP:CELL="+Form6->Cell3->Text+";";
 Form3->IdTelnet1->WriteLn("RLDEP:CELL="+Form6->Cell3->Text+";");
  goto son;
  }

//--------------------------------------RLDEPC4 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" &&
Form6->Cell4->Visible==true && RLDEPC4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLDEP:CELL="+Form6->Cell4->Text+";";
 Form3->IdTelnet1->WriteLn("RLDEP:CELL="+Form6->Cell4->Text+";");
  goto son;
  }

if(Komanda=="RXDEPCIXIS")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="RXMOPTRUK1";
   Form3->IdTelnet1->WriteLn("");
   }

 son:
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Rxmoptruk1PanelClick(TObject *Sender)
{
//-----------------------------------TRU RXMOP qebul-----------------------//

 if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-0;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru1k1Click(Tru1k1);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru1k1Click(Etru1k1);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru1k1->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP0TG1="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-1;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk1->ItemIndex==0 || Tpk1->ItemIndex==2 || Tpk1->ItemIndex==3)
    Form3->Tru3k1Click(Tru3k1);
    else
    Form3->Tru2k1Click(Tru2k1);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru2k1Click(Etru2k1);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru2k1->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP1TG1="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-2;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk1->ItemIndex==0 || Tpk1->ItemIndex==2 || Tpk1->ItemIndex==3)
    Form3->Tru5k1Click(Tru5k1);
    else
    Form3->Tru3k1Click(Tru3k1);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru3k1Click(Etru3k1);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru3k1->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP2TG1="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-3;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
     int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
   if(Tpk1->ItemIndex==0 || Tpk1->ItemIndex==2 || Tpk1->ItemIndex==3)
    Form3->Tru7k1Click(Tru7k1);
    else
    Form3->Tru4k1Click(Tru4k1);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru4k1Click(Etru4k1);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru4k1->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP3TG1="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-4;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk1->ItemIndex==0 || Tpk1->ItemIndex==2 || Tpk1->ItemIndex==3)
    Form3->Tru9k1Click(Tru9k1);
    else
    Form3->Tru5k1Click(Tru5k1);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru5k1Click(Etru5k1);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru5k1->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP4TG1="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-5;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk1->ItemIndex==0 || Tpk1->ItemIndex==2 || Tpk1->ItemIndex==3)
    Form3->Tru11k1Click(Tru11k1);
    else
    Form3->Tru6k1Click(Tru6k1);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru6k1Click(Etru6k1);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru6k1->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP5TG1="OK";
    }
  }

    goto KOM;
  }

if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-6;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {

    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru7k1Click(Tru7k1);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru7k1Click(Etru7k1);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru7k1->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP6TG1="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-7;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru8k1Click(Tru8k1);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru8k1Click(Etru8k1);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru8k1->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP7TG1="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-8;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru9k1Click(Tru9k1);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru9k1Click(Etru9k1);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru9k1->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP8TG1="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-9;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru10k1Click(Tru10k1);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru10k1Click(Etru10k1);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru10k1->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP9TG1="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-10;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru11k1Click(Tru11k1);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru11k1Click(Etru11k1);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru11k1->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP10TG1="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-11;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
     int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru12k1Click(Tru12k1);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru12k1Click(Etru12k1);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru12k1->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="RXMOPTRUK1CIXIS";
     RXMOP11TG1="OK";
    }
  }

    goto KOM;
  }

KOM:

 //-----------------------------------------TRU RXMOP-lar----------------------//
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOP0TG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-0;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-0;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOP1TG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-1;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-1;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOP2TG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-2;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-2;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOP3TG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-3;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-3;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOP4TG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-4;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-4;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOP5TG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-5;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-5;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOP6TG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-6;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-6;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOP7TG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-7;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-7;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOP8TG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-8;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-8;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOP9TG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-9;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-9;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOP10TG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-10;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-10;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg1->Visible==true && RXMOP11TG1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-11;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg1->Text+"-11;");
  goto son;
  }

  if(Komanda=="RXMOPTRUK1CIXIS")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="RXMOPTRUK2";
   Form3->IdTelnet1->WriteLn("");
   }
son:
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Cell1PanelClick(TObject *Sender)
{
//------------------------------RLDHPC1 qebul-------------------------------------//

if(Komanda=="RLDHP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

        if (int DHA= Form6->Memo1->Lines->Strings[I].Pos("DHA "))
        {
        String  DHAS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DHA,4));
         if(DHAS=="OFF")
         Form2->Dha->ItemIndex=1;
         else
         Form2->Dha->ItemIndex=0;
         Form2->Dha->Color=clLime;
        }

        if (int DTHNAMR=Form6->Memo1->Lines->Strings[I].Pos("DTHNAMR "))
        {
        Form2->Dthnamr->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DTHNAMR,4));
        Form2->Dthnamr->Color=clLime;
        }

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLDHPC1="OK";
        goto KOM;
        }
 }
}
//------------------------------RLCFPC1 qebul-------------------------------------//

if(Komanda=="RLCFP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
    int CHGR,SDCCH,TN,HSN,DCHNO;

        if (int CHGRB=Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
        CHGR=CHGRB;
        if (int SDCCHB=Form6->Memo1->Lines->Strings[I].Pos("SDCCH"))
        SDCCH=SDCCHB;
        if (int TNB=Form6->Memo1->Lines->Strings[I].Pos("TN "))
        TN=TNB;
        if (int HSNB=Form6->Memo1->Lines->Strings[I].Pos("HSN"))
        HSN=HSNB;
        if (int DCHNOB=Form6->Memo1->Lines->Strings[I].Pos("DCHNO"))
        DCHNO=DCHNOB;

       //-chgr0-in dannilari
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="0")
       {
       Form2->Sdcchchgr0c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
         if(Fhop->ItemIndex==0)
         {
         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //DCHNO-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="1")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
             Form3->Memo1DblClick(Memo1);
             Form2->Tchch0c1->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
          }
         }
           //TN-in teyin edilmesi
         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="1")
            {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
             Form3->Memo1DblClick(Memo1);
             Form2->Tnchgr0c1->Text=Edits;
             I=y;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
          }

        }
        //CHGR1-in teyini ve parametrleri
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="1")
        {
        Form2->Sdcchchgr1c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
        Form2->Hsnch1c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="2")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tchch1c1->Text=Edits;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
         }
         //TN-in teyini(chgr1)
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="2")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tnchgr1c1->Text=Edits;
            I=y;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
         }
        }
        //CHGR2
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="2")
        {
        Form2->Sdcchchgr2c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="3")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tchch2c1->Text=Edits;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
         }
         //TN-in teyini(chgr1)
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="3")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tnchgr2c1->Text=Edits;
            I=y;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
         }
        }
        //CHGR3
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="3")
        {
        Form2->Sdcchchgr3c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="3")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tchch3c1->Text=Edits;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
         }
         //TN-in teyini(chgr1)
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="2")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tnchgr3c1->Text=Edits;
            I=y;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
         }
        }

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLCFPC1="OK";
        goto KOM;
        }
 }
}

//------------------------------RLCHPC1 qebul-------------------------------------//

if(Komanda=="RLCHP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
    int CHGR,HOP,MAIO,HSN;

        if (int CHGRB=Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
        CHGR=CHGRB;
        if (int HOPB=Form6->Memo1->Lines->Strings[I].Pos("HOP"))
        HOP=HOPB;
        if (int HSNB=Form6->Memo1->Lines->Strings[I].Pos("HSN"))
        HSN=HSNB;
        if (int MAIOB=Form6->Memo1->Lines->Strings[I].Pos("MAIO"))
        MAIO=MAIOB;

       //-chgr0-in dannilari
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="0")
       {
       Form2->Hsnch0c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch0c1->ItemIndex=0;
       else
       Form2->Hopch0c1->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="1")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch0c1->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

        //CHGR1-in teyini ve parametrleri
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="1")
       {
       Form2->Hsnch1c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch1c1->ItemIndex=0;
       else
       Form2->Hopch1c1->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="2")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch1c1->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

       //CHGR2-in teyini ve parametrleri
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="2")
       {
       Form2->Hsnch2c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch2c1->ItemIndex=0;
       else
       Form2->Hopch2c1->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="3")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch2c1->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

               //CHGR1-in teyini ve parametrleri
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="3")
       {
       Form2->Hsnch3c1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch3c1->ItemIndex=0;
       else
       Form2->Hopch3c1->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="4")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch3c1->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLCHPC1="OK";
        goto KOM;
        }
 }
}
//------------------------------RLCPPC1 qebul-------------------------------------//

if(Komanda=="RLCPP:CELL="+Form6->Cell1->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {

    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

        if (int BSPWRB=Form6->Memo1->Lines->Strings[I].Pos("BSPWRB"))
        {
        Form2->Bspwrbc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BSPWRB,3));
        Form2->Bspwrbc1Change(Form2->Bspwrbc1);
        Form2->Bspwrbc1->Color=clLime;
        }

        if (int BSPWRT=Form6->Memo1->Lines->Strings[I].Pos("BSPWRT"))
        {
        Form2->Bspwrtc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BSPWRT,3));
        Form2->Bspwrtc1Change(Form2->Bspwrtc1);
        Form2->Bspwrtc1->Color=clLime;
        }

        if (int MSTXPWR=Form6->Memo1->Lines->Strings[I].Pos("MSTXPWR"))
        {
        Form2->Mstxpwr->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(MSTXPWR,3));
        Form2->Mstxpwr->Color=clLime;
        }

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLCPPC1="OK";
        goto KOM;
        }
 }
}

//------------------------------RLCXPC1 qebul-------------------------------------//

if(Komanda=="RLCXP:CELL="+Form6->Cell1->Text+";")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int DTXD= Form6->Memo1->Lines->Strings[I].Pos("DTXD"))
        {
        String  DTXDS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DTXD,3));
        if(DTXDS=="OFF")
        Form2->Dtxd->ItemIndex=1;
        else
        Form2->Dtxd->ItemIndex=0;
        Form2->Dtxd->Color=clLime;
        }

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLCXPC1="OK";
        goto KOM;
        }
 }
}

//------------------------------RLLOPC1 qebul-------------------------------------//

if(Komanda=="RLLOP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;
        if (int BSPWR=Form6->Memo1->Lines->Strings[I].Pos("BSPWR")){
        Form2->Bspwrc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BSPWR,3));
        Form2->Bspwrc1Change(Form2->Bspwrc1);}

        if (int BSRXMIN=Form6->Memo1->Lines->Strings[I].Pos("BSRXMIN")){
        Form2->Bsrxminc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BSRXMIN,4));
        Form2->Bsrxminc1Change(Form2->Bsrxminc1);}

        if (int BSRXSUFF=Form6->Memo1->Lines->Strings[I].Pos("BSRXSUFF")){
        Form2->Bsrxsuffc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BSRXSUFF,4));
        Form2->Bsrxsuffc1Change(Form2->Bsrxsuffc1);}

        if (int MSRXMIN=Form6->Memo1->Lines->Strings[I].Pos("MSRXMIN")){
        Form2->Msrxminc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(MSRXMIN,4));
        Form2->Msrxminc1Change(Form2->Msrxminc1);}

        if (int MSRXSUFF=Form6->Memo1->Lines->Strings[I].Pos("MSRXSUFF"))
        Form2->Msrxsuff->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(MSRXSUFF,4));

        if (int MISSNM=Form6->Memo1->Lines->Strings[I].Pos("MISSNM"))
        Form2->Missnm->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(MISSNM,3));

        if (int AW= Form6->Memo1->Lines->Strings[I].Pos("AW")){
        String  AWS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(AW,4));
        if(AWS=="OFF")
        Form2->Awc1->ItemIndex=1;
        else
        Form2->Awc1->ItemIndex=0;}

        if (int BSTXPWR=Form6->Memo1->Lines->Strings[I].Pos("BSTXPWR")){
        Form2->Bstxpwrc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BSTXPWR,3));
        Form2->Bstxpwrc1Change(Form2->Bstxpwrc1);}

        if (int SCHO= Form6->Memo1->Lines->Strings[I].Pos("SCHO")){
        String  SCHOS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SCHO,4));
        if(SCHOS=="ON")
        Form2->Scho->ItemIndex=0;
        else
        Form2->Scho->ItemIndex=1;}

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLLOPC1="OK";
        goto KOM;
        }
 }
}

//------------------------------RLLUPC1 qebul-------------------------------------//

if(Komanda=="RLLUP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {      int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int QLIMUL=Form6->Memo1->Lines->Strings[I].Pos("QLIMUL"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLIMUL,4)).Length()!=0)
        Form2->Qlimul->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLIMUL,4));

        if (int QLIMDL=Form6->Memo1->Lines->Strings[I].Pos("QLIMDL"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLIMDL,4)).Length()!=0)
        Form2->Qlimdl->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLIMDL,4));

        if (int TALIM=Form6->Memo1->Lines->Strings[I].Pos("TALIM"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TALIM,4)).Length()!=0){
        Form2->Talimc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TALIM,4));
        Form2->Talimc1Change(Form2->Talimc1);}

        if (int QLIMDL=Form6->Memo1->Lines->Strings[I].Pos("QLIMDL"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLIMDL,4)).Length()!=0)
        Form2->Qlimdl->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLIMDL,4));

        if (int CELLQ= Form6->Memo1->Lines->Strings[I].Pos("CELLQ"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELLQ,5)).Length()!=0){
        String  CELLQS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELLQ,5));
        if(CELLQS=="HIGH")
        Form2->Cellq->ItemIndex=1;
        else
        Form2->Cellq->ItemIndex=0;}

        if (int QLIMULAFR=Form6->Memo1->Lines->Strings[I].Pos("QLIMULAFR"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLIMULAFR,4)).Length()!=0)
        Form2->Qlimulafr->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLIMULAFR,4));

        if (int QLIMDLAFR=Form6->Memo1->Lines->Strings[I].Pos("QLIMDLAFR"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLIMDLAFR,4)).Length()!=0)
        Form2->Qlimdlafr->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLIMDLAFR,4));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLLUPC1="OK";
        goto KOM;
        }
 }
}


//------------------------------RLLPPC1 qebul-------------------------------------//

if(Komanda=="RLLPP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {      int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int PTIMHF=Form6->Memo1->Lines->Strings[I].Pos("PTIMHF"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PTIMHF,4)).Length()!=0)
        Form2->Ptimhf->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PTIMHF,4));

        if (int PTIMBQ=Form6->Memo1->Lines->Strings[I].Pos("PTIMBQ"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PTIMBQ,3)).Length()!=0)
        Form2->Ptimbq->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PTIMBQ,3));

        if (int PTIMTA=Form6->Memo1->Lines->Strings[I].Pos("PTIMTA"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PTIMTA,4)).Length()!=0)
        Form2->Ptimta->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PTIMTA,4));

        if (int PSSHF=Form6->Memo1->Lines->Strings[I].Pos("PSSHF"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PSSHF,4)).Length()!=0)
        Form2->Psshf->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PSSHF,4));

        if (int PSSBQ=Form6->Memo1->Lines->Strings[I].Pos("PSSBQ"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PSSBQ,3)).Length()!=0)
        Form2->Pssbq->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PSSBQ,3));

        if (int PSSTA=Form6->Memo1->Lines->Strings[I].Pos("PSSTA"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PSSTA,4)).Length()!=0)
        Form2->Pssta->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PSSTA,4));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLLPPC1="OK";
        goto KOM;
        }
 }
}

//------------------------------RLLFPC1 qebul-------------------------------------//

if(Komanda=="RLLFP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {      int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int SSEVALSD=Form6->Memo1->Lines->Strings[I].Pos("SSEVALSD"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSEVALSD,3)).Length()!=0)
        Form2->Ssevalsd->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSEVALSD,3));

        if (int QEVALSD=Form6->Memo1->Lines->Strings[I].Pos("QEVALSD"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QEVALSD,3)).Length()!=0)
        Form2->Qevalsd->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QEVALSD,3));

        if (int SSEVALSI=Form6->Memo1->Lines->Strings[I].Pos("SSEVALSI"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSEVALSI,3)).Length()!=0)
        Form2->Ssevalsi->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSEVALSI,3));

        if (int QEVALSI=Form6->Memo1->Lines->Strings[I].Pos("QEVALSI"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QEVALSI,3)).Length()!=0)
        Form2->Qevalsi->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QEVALSI,3));

        if (int SSLENSD=Form6->Memo1->Lines->Strings[I].Pos("SSLENSD"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSLENSD,4)).Length()!=0)
        Form2->Sslensd->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSLENSD,4));

        if (int QLENSD=Form6->Memo1->Lines->Strings[I].Pos("QLENSD"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLENSD,4)).Length()!=0)
        Form2->Qlensd->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLENSD,4));

        if (int SSLENSI=Form6->Memo1->Lines->Strings[I].Pos("SSLENSI"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSLENSI,3)).Length()!=0)
        Form2->Sslensi->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSLENSI,3));

        if (int QLENSI=Form6->Memo1->Lines->Strings[I].Pos("QLENSI"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLENSI,3)).Length()!=0)
        Form2->Qlensi->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLENSI,3));

        if (int SSRAMPSD=Form6->Memo1->Lines->Strings[I].Pos("SSRAMPSD"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSRAMPSD,3)).Length()!=0)
        Form2->Ssrampsd->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSRAMPSD,3));

        if (int SSRAMPSI=Form6->Memo1->Lines->Strings[I].Pos("SSRAMPSI"))
        if(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSRAMPSI,2)).Length()!=0)
        Form2->Ssrampsi->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSRAMPSI,2));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLLFPC1="OK";
        goto KOM;
        }
 }
}

//------------------------------RLLDPC1 qebul-------------------------------------//

if(Komanda=="RLLDP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int MAXTA=Form6->Memo1->Lines->Strings[I].Pos("MAXTA"))
        Form2->Maxta->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(MAXTA,4));

        if (int RLINKUP=Form6->Memo1->Lines->Strings[I].Pos("RLINKUP"))
        Form2->Rlinkup->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(RLINKUP,4));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLLDPC1="OK";
        goto KOM;
        }
 }
}

//------------------------------RLLCPC1 qebul-------------------------------------//

if(Komanda=="RLLCP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {      int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int CLSSTATE= Form6->Memo1->Lines->Strings[I].Pos("CLSSTATE")){
        String  CLSSTATES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CLSSTATE,9));
        if(CLSSTATES=="INACTIVE")
        Form2->Clsstatec1->ItemIndex=1;
        else
        Form2->Clsstatec1->ItemIndex=0;}

        if (int CLSLEVEL=Form6->Memo1->Lines->Strings[I].Pos("CLSLEVEL"))
        Form2->Clslevelc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CLSLEVEL,4));

        if (int CLSACC=Form6->Memo1->Lines->Strings[I].Pos("CLSACC"))
        Form2->Clsaccc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CLSACC,4));

        if (int HOCLSACC= Form6->Memo1->Lines->Strings[I].Pos("HOCLSACC")){
        String  HOCLSACCS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(HOCLSACC,4));
        if(HOCLSACCS=="OFF")
        Form2->Hoclsaccc1->ItemIndex=1;
        else
        Form2->Hoclsaccc1->ItemIndex=0;}

        if (int RHYST=Form6->Memo1->Lines->Strings[I].Pos("RHYST"))
        Form2->Rhystc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(RHYST,5));

        if (int CLSRAMP=Form6->Memo1->Lines->Strings[I].Pos("CLSRAMP"))
        Form2->Clsrampc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CLSRAMP,4));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLLCPC1="OK";
        goto KOM;
        }
 }
}


//------------------------------RLSSPC1 qebul-------------------------------------//

if(Komanda=="RLSSP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int ACCMIN=Form6->Memo1->Lines->Strings[I].Pos("ACCMIN"))
        Form2->Accmin->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(ACCMIN,5));

        if (int CCHPWR=Form6->Memo1->Lines->Strings[I].Pos("CCHPWR"))
        Form2->Cchpwr->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CCHPWR,4));

        if (int CRH=Form6->Memo1->Lines->Strings[I].Pos("CRH"))
        Form2->Crh->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CRH,4));

        if (int DTXU=Form6->Memo1->Lines->Strings[I].Pos("DTXU"))
        Form2->Dtxu->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DTXU,4));

        if (int RLINKT=Form6->Memo1->Lines->Strings[I].Pos("RLINKT "))
        Form2->Rlinkt->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(RLINKT,4));


        if (int NCCPERM=Form6->Memo1->Lines->Strings[I].Pos("NCCPERM"))
        {
        String NCC=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(NCCPERM,25));
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
        for(int k=1;k<NCC.Length()+1;k++)
        if(NCC.SubString(k,1)!=" ")
        Memo1->Lines->Add(NCC.SubString(k,1));
        Memo1DblClick(Memo1);
        Form2->Nccperm->Text=Edits;
        }

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLSSPC1="OK";
        goto KOM;
        }
 }
}

//------------------------------RLSBPC1 qebul-------------------------------------//

if(Komanda=="RLSBP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int CB= Form6->Memo1->Lines->Strings[I].Pos("CB   MAXRET")){
        String  CBS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CB,4));
        if(CBS=="YES")
        Form2->Cb->ItemIndex=1;
        else
        Form2->Cb->ItemIndex=0;}

        if (int MAXRET=Form6->Memo1->Lines->Strings[I].Pos("MAXRET"))
        Form2->Maxret->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(MAXRET,3));

        if (int TX=Form6->Memo1->Lines->Strings[I].Pos("TX  ATT"))
        Form2->Tx->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TX,3));

        if (int ATT= Form6->Memo1->Lines->Strings[I].Pos("ATT")){
        String  ATTS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(ATT,4));
        if(ATTS=="YES")
        Form2->Att->ItemIndex=1;
        else
        Form2->Att->ItemIndex=0;}

        if (int T3212=Form6->Memo1->Lines->Strings[I].Pos("T3212"))
        Form2->T3212->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(T3212,3));

        if (int CBQ= Form6->Memo1->Lines->Strings[I].Pos("CBQ")){
        String  CBQS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CBQ,4));
        if(CBQS=="LOW")
        Form2->Cbq->ItemIndex=1;
        else
        Form2->Cbq->ItemIndex=0;}

        if (int CRO=Form6->Memo1->Lines->Strings[I].Pos("CRO"))
        Form2->Cro->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CRO,3));

        if (int TO=Form6->Memo1->Lines->Strings[I].Pos("TO  PT"))
        Form2->To->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TO,4));

        if (int PT=Form6->Memo1->Lines->Strings[I].Pos("PT  ECSC"))
        Form2->Pt->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PT,4));

        if (int ECSC= Form6->Memo1->Lines->Strings[I].Pos("ECSC")){
        String  ECSCS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(ECSC,4));
        if(ECSCS=="YES")
        Form2->Ecsc->ItemIndex=1;
        else
        Form2->Ecsc->ItemIndex=0;}

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLSBPC1="OK";
        goto KOM;
        }
 }
}

//------------------------------RLIHPC1 qebul-------------------------------------//

if(Komanda=="RLIHP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int IHO= Form6->Memo1->Lines->Strings[I].Pos("IHO  MAXIHO")){
        String  IHOS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(IHO,4));
        if(IHOS=="OFF")
        Form2->Iho->ItemIndex=1;
        else
        Form2->Iho->ItemIndex=0;}

        if (int MAXIHO=Form6->Memo1->Lines->Strings[I].Pos("MAXIHO  TMAXIHO"))
        Form2->Maxiho->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(MAXIHO,3));

        if (int TMAXIHO=Form6->Memo1->Lines->Strings[I].Pos("TMAXIHO"))
        Form2->Tmaxiho->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TMAXIHO,3));

        if (int TIHO=Form6->Memo1->Lines->Strings[I].Pos("TIHO"))
        Form2->Tiho->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TIHO,3));

        if (int SSOFFSETULP=Form6->Memo1->Lines->Strings[I].Pos("SSOFFSETULP"))
        Form2->Ssoffsetulp->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSOFFSETULP,3));

        if (int SSOFFSETDLP=Form6->Memo1->Lines->Strings[I].Pos("SSOFFSETDLP"))
        Form2->Ssoffsetdlp->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSOFFSETDLP,3));

        if (int QOFFSETULN=Form6->Memo1->Lines->Strings[I].Pos("QOFFSETULN"))
        Form2->Qoffsetuln->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QOFFSETULN,4));

        if (int QOFFSETDLN=Form6->Memo1->Lines->Strings[I].Pos("QOFFSETDLN"))
        Form2->Qoffsetdln->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QOFFSETDLN,4));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLIHPC1="OK";
        goto KOM;
        }
 }
}

//------------------------------RLLHPC1 qebul-------------------------------------//

if(Komanda=="RLLHP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int LAYER=Form6->Memo1->Lines->Strings[I].Pos("LAYER  LAYERTHR"))
        Form2->Levelc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(LAYER,3));

        if (int LAYERTHR=Form6->Memo1->Lines->Strings[I].Pos("LAYERTHR"))
        Form2->Levthrc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(LAYERTHR,3));

        if (int LAYERHYST=Form6->Memo1->Lines->Strings[I].Pos("LAYERHYST"))
        Form2->Layerhystc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(LAYERHYST,3));

        if (int PSSTEMP=Form6->Memo1->Lines->Strings[I].Pos("PSSTEMP"))
        Form2->Psstemp->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PSSTEMP,3));

        if (int PTIMTEMP=Form6->Memo1->Lines->Strings[I].Pos("PTIMTEMP"))
        Form2->Ptimtemp->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(PTIMTEMP,3));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLLHPC1="OK";
        goto KOM;
        }
 }
}

//------------------------------RLPCPC1 qebul-------------------------------------//

if(Komanda=="RLPCP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int DMPSTATE= Form6->Memo1->Lines->Strings[I].Pos("DMPSTATE")){
        String  DMPSTATES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DMPSTATE,9));
        if(DMPSTATES=="INACTIVE")
        Form2->Dmpstate->ItemIndex=1;
        else
        Form2->Dmpstate->ItemIndex=0;}

        if (int SSDESUL=Form6->Memo1->Lines->Strings[I].Pos("SSDESUL"))
        Form2->Ssdesul->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSDESUL,3));

        if (int SSLENUL=Form6->Memo1->Lines->Strings[I].Pos("SSLENUL"))
        Form2->Sslenul->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSLENUL,3));

        if (int LCOMPUL=Form6->Memo1->Lines->Strings[I].Pos("LCOMPUL"))
        Form2->Lcompul->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(LCOMPUL,3));

        if (int QDESUL=Form6->Memo1->Lines->Strings[I].Pos("QDESUL"))
        Form2->Qdesul->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QDESUL,3));

        if (int QLENUL=Form6->Memo1->Lines->Strings[I].Pos("QLENUL"))
        Form2->Qlenul->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLENUL,3));

        if (int QCOMPUL=Form6->Memo1->Lines->Strings[I].Pos("QCOMPUL"))
        Form2->Qcompul->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QCOMPUL,3));

        if (int REGINTUL=Form6->Memo1->Lines->Strings[I].Pos("REGINTUL"))
        Form2->Regintul->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(REGINTUL,3));

        if (int DTXFUL=Form6->Memo1->Lines->Strings[I].Pos("DTXFUL"))
        Form2->Dtxful->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DTXFUL,3));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLPCPC1="OK";
        goto KOM;
        }
 }
}

//------------------------------RLBCPC1 qebul-------------------------------------//

if(Komanda=="RLBCP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int DBPSTATE= Form6->Memo1->Lines->Strings[I].Pos("DBPSTATE")){
        String  DBPSTATES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DBPSTATE,9));
        if(DBPSTATES=="INACTIVE")
        Form2->Dbpstate->ItemIndex=1;
        else
        Form2->Dbpstate->ItemIndex=0;}

        if (int SDCCHREG= Form6->Memo1->Lines->Strings[I].Pos("SDCCHREG")){
        String  SDCCHREGS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SDCCHREG,4));
        if(SDCCHREGS=="OFF")
        Form2->Sdcchreg->ItemIndex=1;
        else
        Form2->Sdcchreg->ItemIndex=0;}

        if (int SSDESDL=Form6->Memo1->Lines->Strings[I].Pos("SSDESDL"))
        Form2->Ssdesdl->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSDESDL,3));

        if (int REGINTDL=Form6->Memo1->Lines->Strings[I].Pos("REGINTDL"))
        Form2->Regintdl->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(REGINTDL,3));

        if (int SSLENDL=Form6->Memo1->Lines->Strings[I].Pos("SSLENDL"))
        Form2->Sslendl->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(SSLENDL,3));

        if (int LCOMPDL=Form6->Memo1->Lines->Strings[I].Pos("LCOMPDL"))
        Form2->Lcompdl->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(LCOMPDL,3));

        if (int QDESDL=Form6->Memo1->Lines->Strings[I].Pos("QDESDL"))
        Form2->Qdesdl->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QDESDL,3));

        if (int QCOMPDL=Form6->Memo1->Lines->Strings[I].Pos("QCOMPDL"))
        Form2->Qcompdl->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QCOMPDL,3));

        if (int QLENDL=Form6->Memo1->Lines->Strings[I].Pos("QLENDL"))
        Form2->Qlendl->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(QLENDL,3));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLBCPC1="OK";
        goto KOM;
        }
 }
}

//------------------------------RLCDPC1 qebul-------------------------------------//

if(Komanda=="RLCDP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int MC= Form6->Memo1->Lines->Strings[I].Pos("CELL     MC")){
        String  MCS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(MC,4));
        if(MCS=="OFF")
        Form2->Mc->ItemIndex=1;
        else
        Form2->Mc->ItemIndex=0;}

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLCDPC1="OK";
        goto KOM;
        }
 }
}


//------------------------------RLIMPC1 qebul-------------------------------------//

if(Komanda=="RLIMP:CELL="+Form6->Cell1->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int ICMSTATE= Form6->Memo1->Lines->Strings[I].Pos("ICMSTATE")){
        String  ICMSTATES=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(ICMSTATE,9));
        if(ICMSTATES=="INACTIVE")
        Form2->Icmstate->ItemIndex=1;
        else
        Form2->Icmstate->ItemIndex=0;}

        if (int INTAVE=Form6->Memo1->Lines->Strings[I].Pos("INTAVE"))
        Form2->Intave->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(INTAVE,3));

        if (int LIMIT1=Form6->Memo1->Lines->Strings[I].Pos("LIMIT1"))
        Form2->Limit1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(LIMIT1,3));

        if (int LIMIT2=Form6->Memo1->Lines->Strings[I].Pos("LIMIT2"))
        Form2->Limit2->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(LIMIT2,3));

        if (int LIMIT3=Form6->Memo1->Lines->Strings[I].Pos("LIMIT3"))
        Form2->Limit3->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(LIMIT3,3));

        if (int LIMIT4=Form6->Memo1->Lines->Strings[I].Pos("LIMIT4"))
        Form2->Limit4->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(LIMIT4,3));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="CELL1CIXIS";
        RLIMPC1="OK";
        goto KOM;
        }
 }
}

KOM:

//---------------------------------------RLDHPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLDHPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLDHP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLCFPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLCFPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLCFP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
 //---------------------------------------RLCHPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLCHPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLCHP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLCPPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLCPPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLCPP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLCXPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLCXPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLCXP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLLOPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLLOPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLLOP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLLUPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLLUPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLLUP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLLPPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLLPPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLLPP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLLFPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLLFPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLLFP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLLDPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLLDPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLLDP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLLCPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLLCPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLLCP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLSSPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLSSPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLSSP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLSBPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLSBPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLSBP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLIHPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLIHPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLIHP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLLHPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLLHPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLLHP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLPCPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLPCPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLPCP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLBCPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLBCPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLBCP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLCDPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLCDPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLCDP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//---------------------------------------RLIMPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLIMPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLIMP:CELL="+Form6->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Komanda=="CELL1CIXIS")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="CELL2";
   Form3->IdTelnet1->WriteLn("");
   }

son:

}
//---------------------------------------------------------------------------




void __fastcall TForm3::Chgr1c1cboxClick(TObject *Sender)
{
if(Chgr1c1cbox->Checked==true)
{
Numreqbpcch1c1->Visible=true;
Numreqegprsbpcch1c1->Visible=true;
Numreqcs3cs4bpcch1c1->Visible=true;
Tn7bcchch1c1->Visible=true;

Form2->Addch1c1->Checked=true;
}
else
{
Numreqbpcch1c1->Visible=false;
Numreqegprsbpcch1c1->Visible=false;
Numreqcs3cs4bpcch1c1->Visible=false;
Tn7bcchch1c1->Visible=false;

Form2->Addch1c1->Checked=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Chgr2c1cboxClick(TObject *Sender)
{
if(Chgr2c1cbox->Checked==true)
{
Numreqbpcch2c1->Visible=true;
Numreqegprsbpcch2c1->Visible=true;
Numreqcs3cs4bpcch2c1->Visible=true;
Tn7bcchch2c1->Visible=true;

Form2->Addch2c1->Checked=true;
}
else
{
Numreqbpcch2c1->Visible=false;
Numreqegprsbpcch2c1->Visible=false;
Numreqcs3cs4bpcch2c1->Visible=false;
Tn7bcchch2c1->Visible=false;

Form2->Addch2c1->Checked=false;
}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Chgr3c1cboxClick(TObject *Sender)
{
if(Chgr3c1cbox->Checked==true)
{
Numreqbpcch3c1->Visible=true;
Numreqegprsbpcch3c1->Visible=true;
Numreqcs3cs4bpcch3c1->Visible=true;
Tn7bcchch3c1->Visible=true;
Form2->Addch3c1->Checked=true;
}
else
{
Numreqbpcch3c1->Visible=false;
Numreqegprsbpcch3c1->Visible=false;
Numreqcs3cs4bpcch3c1->Visible=false;
Tn7bcchch3c1->Visible=false;
Form2->Addch3c1->Checked=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Chgr1c2cboxClick(TObject *Sender)
{
if(Chgr1c2cbox->Checked==true)
{
Numreqbpcch1c2->Visible=true;
Numreqegprsbpcch1c2->Visible=true;
Numreqcs3cs4bpcch1c2->Visible=true;
Tn7bcchch1c2->Visible=true;
Form2->Addch1c2->Checked=true;
}
else
{
Numreqbpcch1c2->Visible=false;
Numreqegprsbpcch1c2->Visible=false;
Numreqcs3cs4bpcch1c2->Visible=false;
Tn7bcchch1c2->Visible=false;
Form2->Addch1c2->Checked=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Chgr1c3cboxClick(TObject *Sender)
{
if(Chgr1c3cbox->Checked==true)
{
Numreqbpcch1c3->Visible=true;
Numreqegprsbpcch1c3->Visible=true;
Numreqcs3cs4bpcch1c3->Visible=true;
Tn7bcchch1c3->Visible=true;
Form2->Addch1c3->Checked=true;
}
else
{
Numreqbpcch1c3->Visible=false;
Numreqegprsbpcch1c3->Visible=false;
Numreqcs3cs4bpcch1c3->Visible=false;
Tn7bcchch1c3->Visible=false;
Form2->Addch1c3->Checked=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Chgr3c3cboxClick(TObject *Sender)
{
if(Chgr3c3cbox->Checked==true)
{
Numreqbpcch3c3->Visible=true;
Numreqegprsbpcch3c3->Visible=true;
Numreqcs3cs4bpcch3c3->Visible=true;
Tn7bcchch3c3->Visible=true;
Form2->Addch3c3->Checked=true;
}
else
{
Numreqbpcch3c3->Visible=false;
Numreqegprsbpcch3c3->Visible=false;
Numreqcs3cs4bpcch3c3->Visible=false;
Tn7bcchch3c3->Visible=false;
Form2->Addch3c3->Checked=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Chgr1c4cboxClick(TObject *Sender)
{
if(Chgr1c4cbox->Checked==true)
{
Numreqbpcch1c4->Visible=true;
Numreqegprsbpcch1c4->Visible=true;
Numreqcs3cs4bpcch1c4->Visible=true;
Tn7bcchch1c4->Visible=true;
Form2->Addch1c4->Checked=true;
}
else
{
Numreqbpcch1c4->Visible=false;
Numreqegprsbpcch1c4->Visible=false;
Numreqcs3cs4bpcch1c4->Visible=false;
Tn7bcchch1c4->Visible=false;
Form2->Addch1c4->Checked=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Chgr2c2cboxClick(TObject *Sender)
{
if(Chgr2c2cbox->Checked==true)
{
Numreqbpcch2c2->Visible=true;
Numreqegprsbpcch2c2->Visible=true;
Numreqcs3cs4bpcch2c2->Visible=true;
Tn7bcchch2c2->Visible=true;
Form2->Addch2c2->Checked=true;
}
else
{
Numreqbpcch2c2->Visible=false;
Numreqegprsbpcch2c2->Visible=false;
Numreqcs3cs4bpcch2c2->Visible=false;
Tn7bcchch2c2->Visible=false;
Form2->Addch2c2->Checked=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Chgr2c3cboxClick(TObject *Sender)
{
if(Chgr2c3cbox->Checked==true)
{
Numreqbpcch2c3->Visible=true;
Numreqegprsbpcch2c3->Visible=true;
Numreqcs3cs4bpcch2c3->Visible=true;
Tn7bcchch2c3->Visible=true;
Form2->Addch2c3->Checked=true;
}
else
{
Numreqbpcch2c3->Visible=false;
Numreqegprsbpcch2c3->Visible=false;
Numreqcs3cs4bpcch2c3->Visible=false;
Tn7bcchch2c3->Visible=false;
Form2->Addch2c3->Checked=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Chgr2c4cboxClick(TObject *Sender)
{
if(Chgr2c4cbox->Checked==true)
{
Numreqbpcch2c4->Visible=true;
Numreqegprsbpcch2c4->Visible=true;
Numreqcs3cs4bpcch2c4->Visible=true;
Tn7bcchch2c4->Visible=true;
Form2->Addch2c4->Checked=true;
}
else
{
Numreqbpcch2c4->Visible=false;
Numreqegprsbpcch2c4->Visible=false;
Numreqcs3cs4bpcch2c4->Visible=false;
Tn7bcchch2c4->Visible=false;
Form2->Addch2c4->Checked=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Chgr3c2cboxClick(TObject *Sender)
{
if(Chgr3c2cbox->Checked==true)
{
Numreqbpcch3c2->Visible=true;
Numreqegprsbpcch3c2->Visible=true;
Numreqcs3cs4bpcch3c2->Visible=true;
Tn7bcchch3c2->Visible=true;
Form2->Addch3c2->Checked=true;
}
else
{
Numreqbpcch3c2->Visible=false;
Numreqegprsbpcch3c2->Visible=false;
Numreqcs3cs4bpcch3c2->Visible=false;
Tn7bcchch3c2->Visible=false;
Form2->Addch3c2->Checked=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Chgr3c4cboxClick(TObject *Sender)
{
if(Chgr3c4cbox->Checked==true)
{
Numreqbpcch3c4->Visible=true;
Numreqegprsbpcch3c4->Visible=true;
Numreqcs3cs4bpcch3c4->Visible=true;
Tn7bcchch3c4->Visible=true;
Form2->Addch3c4->Checked=true;
}
else
{
Numreqbpcch3c4->Visible=false;
Numreqegprsbpcch3c4->Visible=false;
Numreqcs3cs4bpcch3c4->Visible=false;
Tn7bcchch3c4->Visible=false;
Form2->Addch3c4->Checked=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SubCellCheckBoxClick(TObject *Sender)
{
Form2->TabSubc1->TabVisible=false;
Form2->TabSubc2->TabVisible=false;
Form2->TabSubc3->TabVisible=false;
Form2->TabSubc4->TabVisible=false;
if(SubCellCheckBox->Checked==true)
{
Form2->TabSubc1->TabVisible=true;
if(Form2->Tabc2->TabVisible==true)
Form2->TabSubc2->TabVisible=true;
if(Form2->Tabc3->TabVisible==true)
Form2->TabSubc3->TabVisible=true;
if(Form2->Tabc4->TabVisible==true)
Form2->TabSubc4->TabVisible=true;
}
}
//---------------------------------------------------------------------------







void __fastcall TForm3::Memo1DblClick(TObject *Sender)
{
Memo2->Lines->Clear();
Edits="";

for(int f=0;f<Memo1->Lines->Count;f++)
if(Memo1->Lines->Strings[f]=="")
{
Memo1->Lines->Delete(f);
f--;
}

for(int f=0;f<Memo1->Lines->Count;f++)
{
  if((Memo1->Lines->Count-f+1)>3 &&
  Memo1->Lines->Strings[f+1].ToInt()==Memo1->Lines->Strings[f].ToInt()+1 &&
  Memo1->Lines->Strings[f+2].ToInt()==Memo1->Lines->Strings[f+1].ToInt()+1)
  Memo2->Lines->Add(f+1);
}

for(int p=0;p<Memo2->Lines->Count;p++)
{
Memo1->Lines->Strings[Memo2->Lines->Strings[p].ToInt()]="&";
}

Edits=Memo1->Lines->Strings[0];
for(int f=1;f<Memo1->Lines->Count;f++)
Edits=Edits+"&"+Memo1->Lines->Strings[f];

//----------------------------------------------------------
String s;
for(int f=0;f<Edits.Length();f++)
{
if(Edits.Length()-f+1>3 &&
Edits.SubString(f,1)=="&" &&
Edits.SubString(f+1,1)=="&" &&
Edits.SubString(f+2,1)=="&")
{
s=s;
}
else
s=s+Edits.SubString(f+1,1);
}

Edits=s;        
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Rxmoptruk2PanelClick(TObject *Sender)
{
//-----------------------------------TRU RXMOP qebul-----------------------//

 if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-0;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru1k2Click(Tru1k2);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru1k2Click(Etru1k2);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru1k2->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP0TG2="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-1;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk2->ItemIndex==0 || Tpk2->ItemIndex==2 || Tpk2->ItemIndex==3)
    Form3->Tru3k2Click(Tru3k2);
    else
    Form3->Tru2k2Click(Tru2k2);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru2k2Click(Etru2k2);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru2k2->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP1TG2="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-2;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk2->ItemIndex==0 || Tpk2->ItemIndex==2 || Tpk2->ItemIndex==3)
    Form3->Tru5k2Click(Tru5k2);
    else
    Form3->Tru3k2Click(Tru3k2);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru3k2Click(Etru3k2);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru3k2->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP2TG2="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-3;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
     int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
   if(Tpk2->ItemIndex==0 || Tpk2->ItemIndex==2 || Tpk2->ItemIndex==3)
    Form3->Tru7k2Click(Tru7k2);
    else
    Form3->Tru4k2Click(Tru4k2);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru4k2Click(Etru4k2);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru4k2->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP3TG2="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-4;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk2->ItemIndex==0 || Tpk2->ItemIndex==2 || Tpk2->ItemIndex==3)
    Form3->Tru9k2Click(Tru9k2);
    else
    Form3->Tru5k2Click(Tru5k2);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru5k2Click(Etru5k2);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru5k2->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP4TG2="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-5;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk2->ItemIndex==0 || Tpk2->ItemIndex==2 || Tpk2->ItemIndex==3)
    Form3->Tru11k2Click(Tru11k2);
    else
    Form3->Tru6k2Click(Tru6k2);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru6k2Click(Etru6k2);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru6k2->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP5TG2="OK";
    }
  }

    goto KOM;
  }

if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-6;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {

    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru7k2Click(Tru7k2);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru7k2Click(Etru7k2);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru7k2->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP6TG2="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-7;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru8k2Click(Tru8k2);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru8k2Click(Etru8k2);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru8k2->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP7TG2="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-8;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru9k2Click(Tru9k2);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru9k2Click(Etru9k2);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru9k2->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP8TG2="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-9;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru10k2Click(Tru10k2);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru10k2Click(Etru10k2);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru10k2->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP9TG2="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-10;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru11k2Click(Tru11k2);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru11k2Click(Etru11k2);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru11k2->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP10TG2="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-11;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
     int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru12k2Click(Tru12k2);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru12k2Click(Etru12k2);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru12k2->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="RXMOPTRUK2CIXIS";
     RXMOP11TG2="OK";
    }
  }

    goto KOM;
  }

KOM:

 //-----------------------------------------TRU RXMOP-lar----------------------//
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOP0TG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-0;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-0;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOP1TG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-1;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-1;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOP2TG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-2;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-2;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOP3TG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-3;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-3;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOP4TG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-4;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-4;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOP5TG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-5;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-5;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOP6TG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-6;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-6;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOP7TG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-7;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-7;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOP8TG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-8;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-8;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOP9TG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-9;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-9;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOP10TG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-10;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-10;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg2->Visible==true && RXMOP11TG2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-11;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg2->Text+"-11;");
  goto son;
  }

  if(Komanda=="RXMOPTRUK2CIXIS")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="RXMOPTRUK3";
   Form3->IdTelnet1->WriteLn("");
   }
son:
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Rxmoptruk3PanelClick(TObject *Sender)
{
//-----------------------------------TRU RXMOP qebul-----------------------//

 if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-0;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru1k3Click(Tru1k3);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru1k3Click(Etru1k3);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru1k3->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP0TG3="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-1;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk3->ItemIndex==0 || Tpk3->ItemIndex==2 || Tpk3->ItemIndex==3)
    Form3->Tru3k3Click(Tru3k3);
    else
    Form3->Tru2k3Click(Tru2k3);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru2k3Click(Etru2k3);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru2k3->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP1TG3="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-2;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk3->ItemIndex==0 || Tpk3->ItemIndex==2 || Tpk3->ItemIndex==3)
    Form3->Tru5k3Click(Tru5k3);
    else
    Form3->Tru3k3Click(Tru3k3);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru3k3Click(Etru3k3);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru3k3->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP2TG3="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-3;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
     int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
   if(Tpk3->ItemIndex==0 || Tpk3->ItemIndex==2 || Tpk3->ItemIndex==3)
    Form3->Tru7k3Click(Tru7k3);
    else
    Form3->Tru4k3Click(Tru4k3);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru4k3Click(Etru4k3);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru4k3->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP3TG3="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-4;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk3->ItemIndex==0 || Tpk3->ItemIndex==2 || Tpk3->ItemIndex==3)
    Form3->Tru9k3Click(Tru9k3);
    else
    Form3->Tru5k3Click(Tru5k3);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru5k3Click(Etru5k3);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru5k3->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP4TG3="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-5;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk3->ItemIndex==0 || Tpk3->ItemIndex==2 || Tpk3->ItemIndex==3)
    Form3->Tru11k3Click(Tru11k3);
    else
    Form3->Tru6k3Click(Tru6k3);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru6k3Click(Etru6k3);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru6k3->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP5TG3="OK";
    }
  }

    goto KOM;
  }

if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-6;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {

    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru7k3Click(Tru7k3);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru7k3Click(Etru7k3);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru7k3->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP6TG3="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-7;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru8k3Click(Tru8k3);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru8k3Click(Etru8k3);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru8k3->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP7TG3="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-8;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru9k3Click(Tru9k3);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru9k3Click(Etru9k3);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru9k3->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP8TG3="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-9;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru10k3Click(Tru10k3);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru10k3Click(Etru10k3);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru10k3->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP9TG3="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-10;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru11k3Click(Tru11k3);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru11k3Click(Etru11k3);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru11k3->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP10TG3="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-11;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
     int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru12k3Click(Tru12k3);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru12k3Click(Etru12k3);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru12k3->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="RXMOPTRUK3CIXIS";
     RXMOP11TG3="OK";
    }
  }

    goto KOM;
  }

KOM:

 //-----------------------------------------TRU RXMOP-lar----------------------//
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOP0TG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-0;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOP1TG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-1;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOP2TG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-2;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOP3TG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-3;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOP4TG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-4;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOP5TG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-5;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOP6TG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-6;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOP7TG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-7;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOP8TG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-8;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOP9TG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-9;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOP10TG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-10;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg3->Visible==true && RXMOP11TG3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg3->Text+"-11;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

  if(Komanda=="RXMOPTRUK3CIXIS")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="RXMOPTRUK4";
   Form3->IdTelnet1->WriteLn("");
   }
son:
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Rxmoptruk4PanelClick(TObject *Sender)
{
//-----------------------------------TRU RXMOP qebul-----------------------//

 if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-0;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru1k4Click(Tru1k4);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru1k4Click(Etru1k4);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru1k4->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP0TG4="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-1;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk4->ItemIndex==0 || Tpk4->ItemIndex==2 || Tpk4->ItemIndex==3)
    Form3->Tru3k4Click(Tru3k4);
    else
    Form3->Tru2k4Click(Tru2k4);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru2k4Click(Etru2k4);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru2k4->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP1TG4="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-2;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk4->ItemIndex==0 || Tpk4->ItemIndex==2 || Tpk4->ItemIndex==3)
    Form3->Tru5k4Click(Tru5k4);
    else
    Form3->Tru3k4Click(Tru3k4);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru3k4Click(Etru3k4);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru3k4->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP2TG4="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-3;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
     int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
   if(Tpk4->ItemIndex==0 || Tpk4->ItemIndex==2 || Tpk4->ItemIndex==3)
    Form3->Tru7k4Click(Tru7k4);
    else
    Form3->Tru4k4Click(Tru4k4);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru4k4Click(Etru4k4);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru4k4->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP3TG4="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-4;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk4->ItemIndex==0 || Tpk4->ItemIndex==2 || Tpk4->ItemIndex==3)
    Form3->Tru9k4Click(Tru9k4);
    else
    Form3->Tru5k4Click(Tru5k4);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru5k4Click(Etru5k4);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru5k4->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP4TG4="OK";
    }
  }

    goto KOM;
  }

  if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-5;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    if(Tpk4->ItemIndex==0 || Tpk4->ItemIndex==2 || Tpk4->ItemIndex==3)
    Form3->Tru11k4Click(Tru11k4);
    else
    Form3->Tru6k4Click(Tru6k4);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru6k4Click(Etru6k4);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru6k4->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP5TG4="OK";
    }
  }

    goto KOM;
  }

if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-6;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {

    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru7k4Click(Tru7k4);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru7k4Click(Etru7k4);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru7k4->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP6TG4="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-7;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru8k4Click(Tru8k4);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru8k4Click(Etru8k4);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru8k4->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP7TG4="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-8;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru9k4Click(Tru9k4);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru9k4Click(Etru9k4);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru9k4->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP8TG4="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-9;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru10k4Click(Tru10k4);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru10k4Click(Etru10k4);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru10k4->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP9TG4="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-10;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru11k4Click(Tru11k4);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru11k4Click(Etru11k4);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru11k4->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="NOVBETI";
     RXMOP10TG4="OK";
    }
  }

    goto KOM;
  }

   if(Komanda=="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-11;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
     int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int CELL = Form6->Memo1->Lines->Strings[I].Pos("CELL"))
    {
    String  CELLS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELL,7));
    RXMOPTRU(CELLS);
    Form3->Tru12k4Click(Tru12k4);
    }

    if (int DCP1 = Form6->Memo1->Lines->Strings[I].Pos("DCP1"))
    {
    String  DCP1S=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(DCP1,5));
      if(StrToInt(DCP1S)>=177)
      Form3->Etru12k4Click(Etru12k4);
    }

    if (int CHGR = Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
    {
    String  CHGRS=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CHGR,2));
    Chgrtru12k4->Text=StrToInt(CHGRS);
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
     Komanda="RXMOPTRUK4CIXIS";
     RXMOP11TG4="OK";
    }
  }

    goto KOM;
  }

KOM:

 //-----------------------------------------TRU RXMOP-lar----------------------//
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOP0TG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-0;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-0;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOP1TG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-1;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-1;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOP2TG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-2;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-2;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOP3TG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-3;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-3;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOP4TG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-4;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-4;");
  goto son;
  }
if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOP5TG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-5;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-5;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOP6TG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-6;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-6;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOP7TG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-7;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-7;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOP8TG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-8;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-8;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOP9TG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-9;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-9;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOP10TG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-10;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-10;");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" &&
Form3->Tg4->Visible==true && RXMOP11TG4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-11;";
 Form3->IdTelnet1->WriteLn("RXMOP:MO=RXOTRX-"+Form3->Tg4->Text+"-11;");
  goto son;
  }

  if(Komanda=="RXMOPTRUK4CIXIS")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="CELL1";
   Form3->IdTelnet1->WriteLn("");
   }
son:
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Cell2PanelClick(TObject *Sender)
{
//--------------------------RLCFP----------------------------//
if(Komanda=="RLCFP:CELL="+Form6->Cell2->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
     int CHGR,SDCCH,TN,HSN,DCHNO;
     
        if (int CHGRB=Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
        CHGR=CHGRB;
        if (int SDCCHB=Form6->Memo1->Lines->Strings[I].Pos("SDCCH"))
        SDCCH=SDCCHB;
        if (int TNB=Form6->Memo1->Lines->Strings[I].Pos("TN "))
        TN=TNB;
        if (int HSNB=Form6->Memo1->Lines->Strings[I].Pos("HSN"))
        HSN=HSNB;
        if (int DCHNOB=Form6->Memo1->Lines->Strings[I].Pos("DCHNO"))
        DCHNO=DCHNOB;

       //-chgr0-in dannilari
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="0")
       {
       Form2->Sdcchchgr0c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
         if(Fhop->ItemIndex==0)
         {
         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //DCHNO-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="1")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
             Form3->Memo1DblClick(Memo1);
             Form2->Tchch0c2->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
          }
         }
           //TN-in teyin edilmesi
         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="1")
            {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
             Form3->Memo1DblClick(Memo1);
             Form2->Tnchgr0c2->Text=Edits;
             I=y;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
          }

        }
        //CHGR1-in teyini ve parametrleri
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="1")
        {
        Form2->Sdcchchgr1c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
        Form2->Hsnch1c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="2")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tchch1c2->Text=Edits;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
         }
         //TN-in teyini(chgr1)
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="2")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tnchgr1c2->Text=Edits;
            I=y;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
         }
        }
        //CHGR2
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="2")
        {
        Form2->Sdcchchgr2c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="3")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tchch2c2->Text=Edits;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
         }
         //TN-in teyini(chgr1)
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="3")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tnchgr2c2->Text=Edits;
            I=y;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
         }
        }

        //CHGR3
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="3")
        {
        Form2->Sdcchchgr3c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="4")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tchch3c2->Text=Edits;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
         }
         //TN-in teyini(chgr1)
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="4")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tnchgr3c2->Text=Edits;
            I=y;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
         }
        }

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLCFPC2="OK";
        goto KOM;
        }
 }
}

//------------------------------RLCHPC1 qebul-------------------------------------//

if(Komanda=="RLCHP:CELL="+Form6->Cell2->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
    int CHGR,HOP,MAIO,HSN;

        if (int CHGRB=Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
        CHGR=CHGRB;
        if (int HOPB=Form6->Memo1->Lines->Strings[I].Pos("HOP"))
        HOP=HOPB;
        if (int HSNB=Form6->Memo1->Lines->Strings[I].Pos("HSN"))
        HSN=HSNB;
        if (int MAIOB=Form6->Memo1->Lines->Strings[I].Pos("MAIO"))
        MAIO=MAIOB;

       //-chgr0-in dannilari
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="0")
       {
       Form2->Hsnch0c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch0c2->ItemIndex=0;
       else
       Form2->Hopch0c2->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="1")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch0c2->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

        //CHGR1-in teyini ve parametrleri
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="1")
       {
       Form2->Hsnch1c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch1c2->ItemIndex=0;
       else
       Form2->Hopch1c2->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="2")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch1c2->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

       //CHGR2-in teyini ve parametrleri
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="2")
       {
       Form2->Hsnch2c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch2c2->ItemIndex=0;
       else
       Form2->Hopch2c2->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="3")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch2c2->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

               //CHGR1-in teyini ve parametrleri
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="3")
       {
       Form2->Hsnch3c2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch3c2->ItemIndex=0;
       else
       Form2->Hopch3c2->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="4")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch3c2->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="CELL2CIXIS";
        RLCHPC2="OK";
        goto KOM;
        }
 }
}
KOM:

//---------------------------------------RLCFPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLCFPC2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLCFP:CELL="+Form6->Cell2->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Komanda=="NOVBETI" && Giris==true && RLCHPC2!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLCHP:CELL="+Form6->Cell2->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Komanda=="CELL2CIXIS")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="CELL3";
   Form3->IdTelnet1->WriteLn("");
   }
son:
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Cell3PanelClick(TObject *Sender)
{
//--------------------------RLCFP----------------------------//
if(Komanda=="RLCFP:CELL="+Form6->Cell3->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
    int CHGR,SDCCH,TN,HSN,DCHNO;

        if (int CHGRB=Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
        CHGR=CHGRB;
        if (int SDCCHB=Form6->Memo1->Lines->Strings[I].Pos("SDCCH"))
        SDCCH=SDCCHB;
        if (int TNB=Form6->Memo1->Lines->Strings[I].Pos("TN "))
        TN=TNB;
        if (int HSNB=Form6->Memo1->Lines->Strings[I].Pos("HSN"))
        HSN=HSNB;
        if (int DCHNOB=Form6->Memo1->Lines->Strings[I].Pos("DCHNO"))
        DCHNO=DCHNOB;

       //-chgr0-in dannilari
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="0")
       {
       Form2->Sdcchchgr0c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
         if(Fhop->ItemIndex==0)
         {
         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //DCHNO-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="1")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
             Form3->Memo1DblClick(Memo1);
             Form2->Tchch0c3->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
          }
         }
           //TN-in teyin edilmesi
         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="1")
            {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
             Form3->Memo1DblClick(Memo1);
             Form2->Tnchgr0c3->Text=Edits;
             I=y;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
          }

        }
        //CHGR1-in teyini ve parametrleri
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="1")
        {
        Form2->Sdcchchgr1c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
        Form2->Hsnch1c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="2")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tchch1c3->Text=Edits;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
         }
         //TN-in teyini(chgr1)
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="2")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tnchgr1c3->Text=Edits;
            I=y;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
         }
        }

        //CHGR2-in teyini ve parametrleri
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="2")
        {
        Form2->Sdcchchgr2c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="3")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tchch2c3->Text=Edits;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
         }
         //TN-in teyini(chgr1)
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="3")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tnchgr2c3->Text=Edits;
            I=y;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
         }
        }
        //CHGR3-in teyini ve parametrleri
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="3")
        {
        Form2->Sdcchchgr3c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="4")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tchch3c3->Text=Edits;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
         }
         //TN-in teyini(chgr1)
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="4")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tnchgr3c3->Text=Edits;
            I=y;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
         }
        }

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLCFPC3="OK";
        goto KOM;
        }
 }
}

//------------------------------RLCHPC3 qebul-------------------------------------//

if(Komanda=="RLCHP:CELL="+Form6->Cell3->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
    int CHGR,HOP,MAIO,HSN;

        if (int CHGRB=Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
        CHGR=CHGRB;
        if (int HOPB=Form6->Memo1->Lines->Strings[I].Pos("HOP"))
        HOP=HOPB;
        if (int HSNB=Form6->Memo1->Lines->Strings[I].Pos("HSN"))
        HSN=HSNB;
        if (int MAIOB=Form6->Memo1->Lines->Strings[I].Pos("MAIO"))
        MAIO=MAIOB;

       //-chgr0-in dannilari
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="0")
       {
       Form2->Hsnch0c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch0c3->ItemIndex=0;
       else
       Form2->Hopch0c3->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="1")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch0c3->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

        //CHGR1-in teyini ve parametrleri
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="1")
       {
       Form2->Hsnch1c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch1c3->ItemIndex=0;
       else
       Form2->Hopch1c3->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="2")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch1c3->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

       //CHGR2-in teyini ve parametrleri
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="2")
       {
       Form2->Hsnch2c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch2c3->ItemIndex=0;
       else
       Form2->Hopch2c3->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="3")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch2c3->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

               //CHGR1-in teyini ve parametrleri
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="3")
       {
       Form2->Hsnch3c3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch3c3->ItemIndex=0;
       else
       Form2->Hopch3c3->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="4")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch3c3->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="CELL3CIXIS";
        RLCHPC3="OK";
        goto KOM;
        }
 }
}
KOM:

//---------------------------------------RLCFPc2----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLCFPC3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLCFP:CELL="+Form6->Cell3->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Komanda=="NOVBETI" && Giris==true && RLCHPC3!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLCHP:CELL="+Form6->Cell3->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Komanda=="CELL3CIXIS")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="CELL4";
   Form3->IdTelnet1->WriteLn("");
   }
son:
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Cell4PanelClick(TObject *Sender)
{
//--------------------------RLCFP----------------------------//
if(Komanda=="RLCFP:CELL="+Form6->Cell4->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
    int CHGR,SDCCH,TN,HSN,DCHNO;

        if (int CHGRB=Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
        CHGR=CHGRB;
        if (int SDCCHB=Form6->Memo1->Lines->Strings[I].Pos("SDCCH"))
        SDCCH=SDCCHB;
        if (int TNB=Form6->Memo1->Lines->Strings[I].Pos("TN "))
        TN=TNB;
        if (int HSNB=Form6->Memo1->Lines->Strings[I].Pos("HSN"))
        HSN=HSNB;
        if (int DCHNOB=Form6->Memo1->Lines->Strings[I].Pos("DCHNO"))
        DCHNO=DCHNOB;

       //-chgr0-in dannilari
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="0")
       {
       Form2->Sdcchchgr0c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
         if(Fhop->ItemIndex==0)
         {
         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //DCHNO-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="1")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
             Form3->Memo1DblClick(Memo1);
             Form2->Tchch0c4->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
          }
         }
           //TN-in teyin edilmesi
         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="1")
            {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
             Form3->Memo1DblClick(Memo1);
             Form2->Tnchgr0c4->Text=Edits;
             I=y;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
          }

        }
        //CHGR1-in teyini ve parametrleri
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="1")
        {
        Form2->Sdcchchgr1c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
        Form2->Hsnch1c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="2")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tchch1c4->Text=Edits;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
         }
         //TN-in teyini(chgr1)
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="2")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tnchgr1c4->Text=Edits;
            I=y;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
         }
        }

        //CHGR2-in teyini ve parametrleri
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="2")
        {
        Form2->Sdcchchgr2c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="3")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tchch2c4->Text=Edits;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
         }
         //TN-in teyini(chgr1)
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="3")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tnchgr2c4->Text=Edits;
            I=y;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
         }
        }

        //CHGR3-in teyini ve parametrleri
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="3")
        {
        Form2->Sdcchchgr3c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(SDCCH,3));
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="4")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tchch3c4->Text=Edits;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(DCHNO,4)));
         }
         //TN-in teyini(chgr1)
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
         for(int y=I;y<Form6->Memo1->Lines->Count;y++)
         {
         int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
         if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
         y++;
           if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
           Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="4")
           {
            Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
            Form3->Memo1DblClick(Memo1);
            Form2->Tnchgr3c4->Text=Edits;
            I=y;
            break;
           }
         Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(TN,4)));
         }
        }

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="NOVBETI";
        RLCFPC4="OK";
        goto KOM;
        }
 }
}

//------------------------------RLCHPC1 qebul-------------------------------------//

if(Komanda=="RLCHP:CELL="+Form6->Cell4->Text+";")
{
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
 {
    int CHGR,HOP,MAIO,HSN;

        if (int CHGRB=Form6->Memo1->Lines->Strings[I].Pos("CHGR"))
        CHGR=CHGRB;
        if (int HOPB=Form6->Memo1->Lines->Strings[I].Pos("HOP"))
        HOP=HOPB;
        if (int HSNB=Form6->Memo1->Lines->Strings[I].Pos("HSN"))
        HSN=HSNB;
        if (int MAIOB=Form6->Memo1->Lines->Strings[I].Pos("MAIO"))
        MAIO=MAIOB;

       //-chgr0-in dannilari
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="0")
       {
       Form2->Hsnch0c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch0c4->ItemIndex=0;
       else
       Form2->Hopch0c4->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="1")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch0c4->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

        //CHGR1-in teyini ve parametrleri
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="1")
       {
       Form2->Hsnch1c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch1c4->ItemIndex=0;
       else
       Form2->Hopch1c4->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="2")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch1c4->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

       //CHGR2-in teyini ve parametrleri
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="2")
       {
       Form2->Hsnch2c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch2c4->ItemIndex=0;
       else
       Form2->Hopch2c4->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="3")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch2c4->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

               //CHGR1-in teyini ve parametrleri
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(CHGR,3))=="3")
       {
       Form2->Hsnch3c4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(HSN,3));
       if(Trim(Form6->Memo1->Lines->Strings[I].SubString(HOP,4))=="ON")
       Form2->Hopch3c4->ItemIndex=0;
       else
       Form2->Hopch3c4->ItemIndex=1;

         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
          for(int y=I;y<Form6->Memo1->Lines->Count;y++)  //Maionun-nun tapilmasi
          {
          int d=1;
          if(Form6->Memo1->Lines->Strings[y+1].SubString(0,8)=="WO      ")
          d=2;
          if(Form6->Memo1->Lines->Strings[y].SubString(0,8)=="WO      ")
          y++;
            if(Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="END" ||
            Trim(Form6->Memo1->Lines->Strings[y+d].SubString(CHGR,5))=="4")
            {
             Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
             Form3->Memo1DblClick(Memo1);
             Form2->Maioch3c4->Text=Edits;
             break;
            }
          Memo1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[y].SubString(MAIO,7)));
          }
         }

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
        Komanda="CELL4CIXIS";
        RLCHPC4="OK";
        goto KOM;
        }
 }
}
KOM:

//---------------------------------------RLCFPC1----------------------------------------//
if(Komanda=="NOVBETI" && Giris==true && RLCFPC4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLCFP:CELL="+Form6->Cell4->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
if(Komanda=="NOVBETI" && Giris==true && RLCHPC4!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLCHP:CELL="+Form6->Cell4->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }


if(Komanda=="CELL4CIXIS")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="ADDITION";
   Form3->IdTelnet1->WriteLn("");
   }
son:
}
//---------------------------------------------------------------------------

void __fastcall TForm3::AdditionPanelClick(TObject *Sender)
{
//-------------------------------------RLNRPC1 qebul----------------------//
if(Komanda=="RLNRP:CELL="+Form6->Cell1->Text+",CELLR=ALL,NODATA;")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int CELLR=Form6->Memo1->Lines->Strings[I].Pos("CELLR   "))
        Form2->Ncellc1->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELLR,7)));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
     Komanda="NOVBETI";
     RLNRPC1="OK";
     Form2->Ncellc1DblClick(Form2->Ncellc1);
        goto KOM;
        }
    }
 }

//-------------------------------------RLNRPC2 qebul----------------------//
if(Komanda=="RLNRP:CELL="+Form6->Cell2->Text+",CELLR=ALL,NODATA;")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int CELLR=Form6->Memo1->Lines->Strings[I].Pos("CELLR   "))
        Form2->Ncellc2->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELLR,7)));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
     Komanda="NOVBETI";
     RLNRPC2="OK";
     Form2->Ncellc2DblClick(Form2->Ncellc2);
        goto KOM;
        }
    }
 }

//-------------------------------------RLNRPC3 qebul----------------------//
if(Komanda=="RLNRP:CELL="+Form6->Cell3->Text+",CELLR=ALL,NODATA;")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int CELLR=Form6->Memo1->Lines->Strings[I].Pos("CELLR   "))
        Form2->Ncellc3->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELLR,7)));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
     Komanda="NOVBETI";
     RLNRPC3="OK";
     Form2->Ncellc3DblClick(Form2->Ncellc3);
        goto KOM;
        }
    }
 }

//-------------------------------------RLNRPC4 qebul----------------------//
if(Komanda=="RLNRP:CELL="+Form6->Cell4->Text+",CELLR=ALL,NODATA;")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if (int CELLR=Form6->Memo1->Lines->Strings[I].Pos("CELLR   "))
        Form2->Ncellc4->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CELLR,7)));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
       Komanda="NOVBETI";
       RLNRPC4="OK";
       Form2->Ncellc4DblClick(Form2->Ncellc4);
        goto KOM;
        }
    }
 }

//-------------------------------------RLMTPC1 qebul----------------------//
if(Komanda=="RLMTP:CELL="+Form6->Cell1->Text+",ID=ALL;")
 {
 Form2->Codec1->Text="";
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
        int ID,CODE;

        if(int IDS=Form6->Memo1->Lines->Strings[I].Pos("ID "))
        ID=IDS;

        if(int CODES=Form6->Memo1->Lines->Strings[I].Pos("CODE "))
        CODE=CODES;

        if (Trim(Form6->Memo1->Lines->Strings[I].SubString(ID,5))=="50")
        Form2->Codec1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(CODE,5));


        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
       Komanda="NOVBETI";
       RLMTPC1="OK";
        goto KOM;
        }
    }
 }
 //-------------------------------------RLMTPC2 qebul----------------------//
if(Komanda=="RLMTP:CELL="+Form6->Cell2->Text+",ID=ALL;")
 {
 Form2->Codec2->Text="";
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
    int ID,CODE;

        if(int IDS=Form6->Memo1->Lines->Strings[I].Pos("ID "))
        ID=IDS;

        if(int CODES=Form6->Memo1->Lines->Strings[I].Pos("CODE "))
        CODE=CODES;

        if (Trim(Form6->Memo1->Lines->Strings[I].SubString(ID,5))=="50")
        Form2->Codec2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(CODE,5));


        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
       Komanda="NOVBETI";
       RLMTPC2="OK";
        goto KOM;
        }
    }
 }
 //-------------------------------------RLMTPC3 qebul----------------------//
if(Komanda=="RLMTP:CELL="+Form6->Cell3->Text+",ID=ALL;")
 {
 Form2->Codec3->Text="";
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
    int ID,CODE;

        if(int IDS=Form6->Memo1->Lines->Strings[I].Pos("ID "))
        ID=IDS;

        if(int CODES=Form6->Memo1->Lines->Strings[I].Pos("CODE "))
        CODE=CODES;

        if (Trim(Form6->Memo1->Lines->Strings[I].SubString(ID,5))=="50")
        Form2->Codec3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(CODE,5));


        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
       Komanda="NOVBETI";
       RLMTPC3="OK";
        goto KOM;
        }
    }
 }
 //-------------------------------------RLMTPC4 qebul----------------------//
if(Komanda=="RLMTP:CELL="+Form6->Cell4->Text+",ID=ALL;")
 {
 Form2->Codec4->Text="";
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
    int ID,CODE;

        if(int IDS=Form6->Memo1->Lines->Strings[I].Pos("ID "))
        ID=IDS;

        if(int CODES=Form6->Memo1->Lines->Strings[I].Pos("CODE "))
        CODE=CODES;

        if (Trim(Form6->Memo1->Lines->Strings[I].SubString(ID,5))=="50")
        Form2->Codec4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(CODE,5));


        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
       Komanda="NOVBETI";
       RLMTPC4="OK";
        goto KOM;
        }
    }
 }
 //-------------------------------------RLMBPC1 qebul----------------------//
if(Komanda=="RLMBP:ID=50,CODE="+Form2->Codec1->Text+",GS=0;")
 {
 Form2->Brc1->Text="";
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if(int TEXT=Form6->Memo1->Lines->Strings[I].Pos("TEXT "))
        Form2->Brc1->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TEXT,41));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
       Komanda="NOVBETI";
       RLMBPC1="OK";
        goto KOM;
        }
    }
 }
 //-------------------------------------RLMBPC2 qebul----------------------//
if(Komanda=="RLMBP:ID=50,CODE="+Form2->Codec2->Text+",GS=0;")
 {
 Form2->Brc2->Text="";
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if(int TEXT=Form6->Memo1->Lines->Strings[I].Pos("TEXT "))
        Form2->Brc2->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TEXT,41));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
       Komanda="NOVBETI";
       RLMBPC2="OK";
        goto KOM;
        }
    }
 }
  //-------------------------------------RLMBPC3 qebul----------------------//
if(Komanda=="RLMBP:ID=50,CODE="+Form2->Codec3->Text+",GS=0;")
 {
 Form2->Brc3->Text="";
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if(int TEXT=Form6->Memo1->Lines->Strings[I].Pos("TEXT "))
        Form2->Brc3->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TEXT,41));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
       Komanda="NOVBETI";
       RLMBPC3="OK";
        goto KOM;
        }
    }
 }
  //-------------------------------------RLMBPC4 qebul----------------------//
if(Komanda=="RLMBP:ID=50,CODE="+Form2->Codec4->Text+",GS=0;")
 {
 Form2->Brc4->Text="";
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
        int k=1;
        if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;

        if(int TEXT=Form6->Memo1->Lines->Strings[I].Pos("TEXT "))
        Form2->Brc4->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(TEXT,41));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
       Komanda="NOVBETI";
       RLMBPC4="OK";
        goto KOM;
        }
    }
 }

  //-------------------------------------RLSLPC1 qebul----------------------//
if(Komanda=="RLSLP:CELL="+Form2->Cell1->Text+";")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
    int LVA;

    if(int LVAS=Form6->Memo1->Lines->Strings[I].Pos("LVA "))
    LVA=LVAS;

        if(int SDCCH=Form6->Memo1->Lines->Strings[I].Pos("SDCCH"))
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5)).Length()!=0)
        Form2->Rlslpsdcchc1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5));

        if(int TCH=Form6->Memo1->Lines->Strings[I].Pos("TCH"))
        if(int FR=Form6->Memo1->Lines->Strings[I].Pos("FR"))
        if(int A1=Form6->Memo1->Lines->Strings[I].Pos("A1"))
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5)).Length()!=0)
        Form2->Rlslptchc1->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
       Komanda="NOVBETI";
       RLSLPC1="OK";
        goto KOM;
        }
    }
 }
  //-------------------------------------RLSLPC2 qebul----------------------//
if(Komanda=="RLSLP:CELL="+Form2->Cell2->Text+";")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
    int LVA;

    if(int LVAS=Form6->Memo1->Lines->Strings[I].Pos("LVA "))
    LVA=LVAS;

        if(int SDCCH=Form6->Memo1->Lines->Strings[I].Pos("SDCCH"))
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5)).Length()!=0)
        Form2->Rlslpsdcchc2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5));

        if(int TCH=Form6->Memo1->Lines->Strings[I].Pos("TCH"))
        if(int FR=Form6->Memo1->Lines->Strings[I].Pos("FR"))
        if(int A1=Form6->Memo1->Lines->Strings[I].Pos("A1"))
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5)).Length()!=0)
        Form2->Rlslptchc2->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
       Komanda="NOVBETI";
       RLSLPC2="OK";
        goto KOM;
        }
    }
 }
  //-------------------------------------RLSLPC3 qebul----------------------//
if(Komanda=="RLSLP:CELL="+Form2->Cell3->Text+";")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
    int LVA;

    if(int LVAS=Form6->Memo1->Lines->Strings[I].Pos("LVA "))
    LVA=LVAS;

        if(int SDCCH=Form6->Memo1->Lines->Strings[I].Pos("SDCCH"))
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5)).Length()!=0)
        Form2->Rlslpsdcchc3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5));

        if(int TCH=Form6->Memo1->Lines->Strings[I].Pos("TCH"))
        if(int FR=Form6->Memo1->Lines->Strings[I].Pos("FR"))
        if(int A1=Form6->Memo1->Lines->Strings[I].Pos("A1"))
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5)).Length()!=0)
        Form2->Rlslptchc3->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
       Komanda="NOVBETI";
       RLSLPC3="OK";
        goto KOM;
        }
    }
 }
  //-------------------------------------RLSLPC4 qebul----------------------//
if(Komanda=="RLSLP:CELL="+Form2->Cell4->Text+";")
 {
    for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
    {
    int LVA;

    if(int LVAS=Form6->Memo1->Lines->Strings[I].Pos("LVA "))
    LVA=LVAS;

        if(int SDCCH=Form6->Memo1->Lines->Strings[I].Pos("SDCCH"))
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5)).Length()!=0)
        Form2->Rlslpsdcchc4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5));

        if(int TCH=Form6->Memo1->Lines->Strings[I].Pos("TCH"))
        if(int FR=Form6->Memo1->Lines->Strings[I].Pos("FR"))
        if(int A1=Form6->Memo1->Lines->Strings[I].Pos("A1"))
        if(Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5)).Length()!=0)
        Form2->Rlslptchc4->Text=Trim(Form6->Memo1->Lines->Strings[I].SubString(LVA,5));

        if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
        {
       Komanda="NOVBETI";
       RLSLPC4="OK";
        goto KOM;
        }
    }
 }
KOM:
//--------------------------------------RLNRPC1 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLNRPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLNRP:CELL="+Form6->Cell1->Text+",CELLR=ALL,NODATA;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLNRPC2 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLNRPC2!="OK" && Form6->Cell2->Visible==true)
  {
  Form6->Memo1->Clear();
  Komanda="RLNRP:CELL="+Form6->Cell2->Text+",CELLR=ALL,NODATA;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLNRPC3 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLNRPC3!="OK" && Form6->Cell3->Visible==true)
  {
  Form6->Memo1->Clear();
  Komanda="RLNRP:CELL="+Form6->Cell3->Text+",CELLR=ALL,NODATA;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLNRPC4 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLNRPC4!="OK" && Form6->Cell4->Visible==true)
  {
  Form6->Memo1->Clear();
  Komanda="RLNRP:CELL="+Form6->Cell4->Text+",CELLR=ALL,NODATA;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLMTPC1 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLMTPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLMTP:CELL="+Form6->Cell1->Text+",ID=ALL;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLMTPC2 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLMTPC2!="OK" && Form6->Cell2->Visible==true)
  {
  Form6->Memo1->Clear();
  Komanda="RLMTP:CELL="+Form6->Cell2->Text+",ID=ALL;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLMTPC3 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLMTPC3!="OK" && Form6->Cell3->Visible==true)
  {
  Form6->Memo1->Clear();
  Komanda="RLMTP:CELL="+Form6->Cell3->Text+",ID=ALL;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLMTPC4 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLMTPC4!="OK" && Form6->Cell4->Visible==true)
  {
  Form6->Memo1->Clear();
  Komanda="RLMTP:CELL="+Form6->Cell4->Text+",ID=ALL;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLMTPC1 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLMBPC1!="OK" && Form2->Codec1->Text.Length()>0)
  {
  Form6->Memo1->Clear();
  Komanda="RLMBP:ID=50,CODE="+Form2->Codec1->Text+",GS=0;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLMTPC2 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLMBPC2!="OK" && Form6->Cell2->Visible==true && Form2->Codec2->Text.Length()>0)
  {
  Form6->Memo1->Clear();
  Komanda="RLMBP:ID=50,CODE="+Form2->Codec2->Text+",GS=0;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLMTPC3 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLMBPC3!="OK" && Form6->Cell3->Visible==true && Form2->Codec3->Text.Length()>0)
  {
  Form6->Memo1->Clear();
  Komanda="RLMBP:ID=50,CODE="+Form2->Codec3->Text+",GS=0;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLMTPC4 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLMBPC4!="OK" && Form6->Cell4->Visible==true && Form2->Codec4->Text.Length()>0)
  {
  Form6->Memo1->Clear();
  Komanda="RLMBP:ID=50,CODE="+Form2->Codec4->Text+",GS=0;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLSLPC1 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLSLPC1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RLSLP:CELL="+Form2->Cell1->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLSLPC2 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLSLPC2!="OK" && Form6->Cell2->Visible==true)
  {
  Form6->Memo1->Clear();
  Komanda="RLSLP:CELL="+Form2->Cell2->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLSLPC3 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLSLPC3!="OK" && Form6->Cell3->Visible==true)
  {
  Form6->Memo1->Clear();
  Komanda="RLSLP:CELL="+Form2->Cell3->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }
//--------------------------------------RLSLPC4 komandalari----------------------------//
if(Giris==true && Komanda=="NOVBETI" && RLSLPC4!="OK" && Form6->Cell4->Visible==true)
  {
  Form6->Memo1->Clear();
  Komanda="RLSLP:CELL="+Form2->Cell4->Text+";";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

if(Komanda=="NOVBETI")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   Servis="RLDEPQON";
   Form3->IdTelnet1->WriteLn("");
   }
son:

}
//---------------------------------------------------------------------------

void __fastcall TForm3::CellsPanelClick(TObject *Sender)
{
if(Komanda=="RXTCP:MOTY=RXOTG;")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int CELL,START;
    if (int CELLS = Form6->Memo1->Lines->Strings[I].Pos("CELL "))
    CELL=CELLS;

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("RXOTG-"))
    START=1;

     if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
     {
     Komanda="NOVBETI";
     Servis="";
     CELLS="OK";
     Form6->CellsMemoDblClick(Form6->CellsMemo);
     if(Form6->CellsMemo->Lines->Count>1)
     {
     int k=0;
      Form6->Cell1->Text=Form6->CellsMemo->Lines->Strings[0];
      if(Form6->CellsMemo->Lines->Strings[0].SubString(0,5)==Form6->CellsMemo->Lines->Strings[1].SubString(0,5))
      {
      int c=0,c2=1;
      if(Form6->CellsMemo->Lines->Strings[0].SubString(6,1)<5)
      c=1;
      if(Form6->CellsMemo->Lines->Strings[0].SubString(6,1)>5)
      c=2;
      if(Form6->CellsMemo->Lines->Strings[1].SubString(6,1)<5)
      c2=1;
      if(Form6->CellsMemo->Lines->Strings[1].SubString(6,1)>5)
      c2=2;
       if(c==c2)
       {
       Form6->Cell2->Text=Form6->CellsMemo->Lines->Strings[1];
       Form6->CellsMemo->Lines->Delete(0);
       k++;
       }
       else
       {
       Form6->CellsMemo->Lines->Delete(0);
       goto soncell;
       }
      }
      else
      {
      Form6->CellsMemo->Lines->Delete(0);
      goto soncell;
      }

      if(Form6->CellsMemo->Lines->Strings[0].SubString(0,5)==Form6->CellsMemo->Lines->Strings[1].SubString(0,5))
      {
      int c=0,c2=1;
      if(Form6->CellsMemo->Lines->Strings[0].SubString(6,1)<5)
      c=1;
      if(Form6->CellsMemo->Lines->Strings[0].SubString(6,1)>5)
      c=2;
      if(Form6->CellsMemo->Lines->Strings[1].SubString(6,1)<5)
      c2=1;
      if(Form6->CellsMemo->Lines->Strings[1].SubString(6,1)>5)
      c2=2;
       if(c==c2)
       {
       Form6->Cell3->Text=Form6->CellsMemo->Lines->Strings[1];
       Form6->CellsMemo->Lines->Delete(0);
       c2=2;
       k++;
       }
       else
       {
       Form6->CellsMemo->Lines->Delete(0);
       goto soncell;
       }
      }
      else
      {
      Form6->CellsMemo->Lines->Delete(0);
      goto soncell;
      }

      if(Form6->CellsMemo->Lines->Strings[0].SubString(0,5)==Form6->CellsMemo->Lines->Strings[1].SubString(0,5))
      {
      int c=0,c2=1;
      if(Form6->CellsMemo->Lines->Strings[0].SubString(6,1)<5)
      c=1;
      if(Form6->CellsMemo->Lines->Strings[0].SubString(6,1)>5)
      c=2;
      if(Form6->CellsMemo->Lines->Strings[1].SubString(6,1)<5)
      c2=1;
      if(Form6->CellsMemo->Lines->Strings[1].SubString(6,1)>5)
      c2=2;
       if(c==c2)
       {
       Form6->Cell4->Text=Form6->CellsMemo->Lines->Strings[1];
       Form6->CellsMemo->Lines->Delete(0);
       Form6->CellsMemo->Lines->Delete(0);
       k++;
       }
       else
       {
       Form6->CellsMemo->Lines->Delete(0);
       goto soncell;
       }
      }
      else
      {
      Form6->CellsMemo->Lines->Delete(0);
      goto soncell;
      }
      soncell:
      Form6->Seksay->ItemIndex=k;
      Form6->SeksayChange(Form6->Seksay);
      Form6->MGCEPC1="";
      Form6->MGLCPC1="";
      Form6->IdTelnetmscDataAvailable("");
     }
     else if(Form6->CellsMemo->Lines->Count==1)
     {
     Form6->Cell1->Text=Form6->CellsMemo->Lines->Strings[0];
     Form6->Seksay->ItemIndex=0;
     Form6->SeksayChange(Form6->Seksay);
     }
     else
     ShowMessage("BSC-de Cell Yoxdur");

     Form6->CellRadioButton->Checked=true;
     Form6->Allcellstesdiq->Checked=true;
     Form6->ConnectClick(Form6->Connect);
     goto son;
     }
     else
     if(START==1)
     Form6->CellsMemo->Lines->Add(Trim(Form6->Memo1->Lines->Strings[I].SubString(CELL,7)));
  }
 }


//--------------------------------------Komandalar----------------------------
KOM:
if(Komanda=="NOVBETI" && CELLS!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="RXTCP:MOTY=RXOTG;";
 Form3->IdTelnet1->WriteLn(Komanda);
  goto son;
  }

 son:
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FinishPanelClick(TObject *Sender)
{
if(Form6->Allcellstesdiq->Checked==false)
{
Form6->Close();
Form3->Close();
}
Form1->Memo1->Clear();

Form2->CheckpnlClick(Form2->Checkpnl);
if(Form2->Test=="OK")
{
Form2->VerilenlerpnlClick(Form2->Verilenlerpnl);
Form2->CelldatapnlClick(Form2->Celldatapnl);
Form2->DxupnlClick(Form2->Dxupnl);
Form2->TrupnlClick(Form2->Trupnl);
Form2->IkimbitpnlClick(Form2->Ikimbitpnl);
Form2->RxesiblepnlClick(Form2->Rxesiblepnl);
Form2->SupervisionpnlClick(Form2->Supervisionpnl);
Form2->NeighbourpnlClick(Form2->Neighbourpnl);
Form2->MscpnlClick(Form2->Mscpnl);
Form2->CellacpnlClick(Form2->Cellacpnl);
Form2->BroadcastpnlClick(Form2->Broadcastpnl);
Form2->PrintoutpnlClick(Form2->Printoutpnl);
Form2->Test="";
}

if(Form6->CellRadioButton->Checked==true && Form6->Allcellstesdiq->Checked==true)
{
        if(Form2->Tabc4->TabVisible==true)
        {
        SaveDialog1->FileName=Form2->Cell1->Text+","+Form2->Cell2->Text.SubString(6,1)+","+Form2->Cell3->Text.SubString(6,1)+","+Form2->Cell4->Text.SubString(6,1)+" - "+ Form2->Rsitec1->Text;
        goto sss;
        }
        if(Form2->Tabc3->TabVisible==true)
        {
        SaveDialog1->FileName=Form2->Cell1->Text+","+Form2->Cell2->Text.SubString(6,1)+","+Form2->Cell3->Text.SubString(6,1)+" - "+ Form2->Rsitec1->Text;
        goto sss;
        }
        if(Form2->Tabc2->TabVisible==true)
        {
        SaveDialog1->FileName=Form2->Cell1->Text+","+Form2->Cell2->Text.SubString(6,1)+" - "+ Form2->Rsitec1->Text;
        goto sss;
        }
        SaveDialog1->FileName=Form2->Cell1->Text+" - "+Form2->Rsitec1->Text;
        sss:

Form1->Memo1->Lines->SaveToFile(Form6->Edit1->Text+"\\"+SaveDialog1->FileName+SaveDialog1->Filter);
Form1->Memo1->Clear();

     if(Form6->CellsMemo->Lines->Count>1)
     {
      int k=0;
      Form6->Cell1->Text=Form6->CellsMemo->Lines->Strings[0];
      if(Form6->CellsMemo->Lines->Strings[0].SubString(0,5)==Form6->CellsMemo->Lines->Strings[1].SubString(0,5))
      {
      int c=0,c2=1;
      if(Form6->CellsMemo->Lines->Strings[0].SubString(6,1)<5)
      c=1;
      if(Form6->CellsMemo->Lines->Strings[0].SubString(6,1)>5)
      c=2;
      if(Form6->CellsMemo->Lines->Strings[1].SubString(6,1)<5)
      c2=1;
      if(Form6->CellsMemo->Lines->Strings[1].SubString(6,1)>5)
      c2=2;
       if(c==c2)
       {
       Form6->Cell2->Text=Form6->CellsMemo->Lines->Strings[1];
       Form6->CellsMemo->Lines->Delete(0);
       k++;
       }
       else
       {
       Form6->CellsMemo->Lines->Delete(0);
       goto son;
       }
      }
      else
      {
      Form6->CellsMemo->Lines->Delete(0);
      goto son;
      }


      if(Form6->CellsMemo->Lines->Strings[0].SubString(0,5)==Form6->CellsMemo->Lines->Strings[1].SubString(0,5))
      {
      int c=0,c2=1;
      if(Form6->CellsMemo->Lines->Strings[0].SubString(6,1)<5)
      c=1;
      if(Form6->CellsMemo->Lines->Strings[0].SubString(6,1)>5)
      c=2;
      if(Form6->CellsMemo->Lines->Strings[1].SubString(6,1)<5)
      c2=1;
      if(Form6->CellsMemo->Lines->Strings[1].SubString(6,1)>5)
      c2=2;
       if(c==c2)
       {
       Form6->Cell3->Text=Form6->CellsMemo->Lines->Strings[1];
       Form6->CellsMemo->Lines->Delete(0);
       c2=2;
       k++;
       }
       else
       {
       Form6->CellsMemo->Lines->Delete(0);
       goto son;
       }
      }
      else
      {
      Form6->CellsMemo->Lines->Delete(0);
      goto son;
      }

      if(Form6->CellsMemo->Lines->Strings[0].SubString(0,5)==Form6->CellsMemo->Lines->Strings[1].SubString(0,5))
      {
      int c=0,c2=1;
      if(Form6->CellsMemo->Lines->Strings[0].SubString(6,1)<5)
      c=1;
      if(Form6->CellsMemo->Lines->Strings[0].SubString(6,1)>5)
      c=2;
      if(Form6->CellsMemo->Lines->Strings[1].SubString(6,1)<5)
      c2=1;
      if(Form6->CellsMemo->Lines->Strings[1].SubString(6,1)>5)
      c2=2;
       if(c==c2)
       {
       Form6->Cell4->Text=Form6->CellsMemo->Lines->Strings[1];
       Form6->CellsMemo->Lines->Delete(0);
       Form6->CellsMemo->Lines->Delete(0);
       k++;
       }
       else
       {
       Form6->CellsMemo->Lines->Delete(0);
       goto son;
       }
      }
      else
      {
      Form6->CellsMemo->Lines->Delete(0);
      goto son;
      }
      son:;
      Form6->Seksay->ItemIndex=k;
      Form6->SeksayChange(Form6->Seksay);
     }
     else if(Form6->CellsMemo->Lines->Count==1)
     {
     Form6->Cell1->Text=Form6->CellsMemo->Lines->Strings[0];
     Form6->Seksay->ItemIndex=0;
     Form6->SeksayChange(Form6->Seksay);
     }
     else
     {
     ShowMessage("FINISH");
     Form6->Allcellstesdiq->Checked=false;
     Form6->IdTelnetmsc->Disconnect();
     goto bitti;
     }
     Form6->ConnectClick(Form6->Connect);
     Form6->MGCEPC1="";
     Form6->MGLCPC1="";
     Form6->IdTelnetmscDataAvailable("");
}
else
Form1->Show();
bitti:;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::RldepqonPanelClick(TObject *Sender)
{
//---------------------------Cell1-----------------------------//

if(Komanda=="Komandaqonc1")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int BCCHNO = Form6->Memo1->Lines->Strings[I].Pos("BCCHNO"))
    {
    Form2->Nbcchc1->Lines->Add("");
    Form2->Nbcchc1->Lines->Strings[SAY]=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BCCHNO,6));
    }

    if (int CGI = Form6->Memo1->Lines->Strings[I].Pos("CGI"))
    {
    Form2->Cgibufedt->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CGI,20));
    Form2->Cgibufedt->Text=Form2->Cgibufedt->Text.SubString(8,4);
    String SPF=Form2->Cgibufedt->Text.c_str();
    Form2->Bscinc1->Lines->Add("");
    if(SPF[4]=='-')
    Form2->Bscinc1->Lines->Strings[SAY]=Trim(Form2->Cgibufedt->Text.SubString(0,1));
    else
    Form2->Bscinc1->Lines->Strings[SAY]=Trim(Form2->Cgibufedt->Text.SubString(0,2));
    }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
    if(SAY<Form2->Ncellc1->Lines->Count-1)
     SAY++;
     else
     {
     QONCELL1="OK";
     for(int l=0;l<Form2->Ncellc1->Lines->Count;l++)
     if(Form2->Bscinc1->Lines->Strings[l]!=Form2->Bscc1->Text)
     {
     Form2->Necellc1->Lines->Add(Form2->Ncellc1->Lines->Strings[l]);
     Form2->Bscexc1->Lines->Add(Form2->Bscinc1->Lines->Strings[l]);
     Form2->Ncellc1->Lines->Delete(l);
     Form2->Nbcchc1->Lines->Delete(l);
     Form2->Bscinc1->Lines->Delete(l);
     l--;
     }
     SAY=0;
     }
     Komanda="NOVBETI";
    }

   }

   goto KOM;
  }

//---------------------------Cell2-----------------------------//

if(Komanda=="Komandaqonc2")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int BCCHNO = Form6->Memo1->Lines->Strings[I].Pos("BCCHNO"))
    {
    Form2->Nbcchc2->Lines->Add("");
    Form2->Nbcchc2->Lines->Strings[SAY]=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BCCHNO,6));
    }

    if (int CGI = Form6->Memo1->Lines->Strings[I].Pos("CGI"))
    {
    Form2->Cgibufedt->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CGI,20));
    Form2->Cgibufedt->Text=Form2->Cgibufedt->Text.SubString(8,4);
    String SPF=Form2->Cgibufedt->Text.c_str();
    Form2->Bscinc2->Lines->Add("");
    if(SPF[4]=='-')
    Form2->Bscinc2->Lines->Strings[SAY]=Trim(Form2->Cgibufedt->Text.SubString(0,1));
    else
    Form2->Bscinc2->Lines->Strings[SAY]=Trim(Form2->Cgibufedt->Text.SubString(0,2));
  }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
    if(SAY<Form2->Ncellc2->Lines->Count-1)
     SAY++;
     else
     {
     QONCELL2="OK";
     for(int l=0;l<Form2->Ncellc2->Lines->Count;l++)
      if(Form2->Bscinc2->Lines->Strings[l]!=Form2->Bscc2->Text)
      {
      Form2->Necellc2->Lines->Add(Form2->Ncellc2->Lines->Strings[l]);
      Form2->Bscexc2->Lines->Add(Form2->Bscinc2->Lines->Strings[l]);
      Form2->Ncellc2->Lines->Delete(l);
      Form2->Nbcchc2->Lines->Delete(l);
      Form2->Bscinc2->Lines->Delete(l);
      l--;
      }
     SAY=0;
     }
     Komanda="NOVBETI";
    }

   }

   goto KOM;
  }

//---------------------------Cell3-----------------------------//

if(Komanda=="Komandaqonc3")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int BCCHNO = Form6->Memo1->Lines->Strings[I].Pos("BCCHNO"))
    {
    Form2->Nbcchc3->Lines->Add("");
    Form2->Nbcchc3->Lines->Strings[SAY]=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BCCHNO,6));
    }

    if (int CGI = Form6->Memo1->Lines->Strings[I].Pos("CGI"))
    {
    Form2->Cgibufedt->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CGI,20));
    Form2->Cgibufedt->Text=Form2->Cgibufedt->Text.SubString(8,4);
    String SPF=Form2->Cgibufedt->Text.c_str();
    Form2->Bscinc3->Lines->Add("");
    if(SPF[4]=='-')
    Form2->Bscinc3->Lines->Strings[SAY]=Trim(Form2->Cgibufedt->Text.SubString(0,1));
    else
    Form2->Bscinc3->Lines->Strings[SAY]=Trim(Form2->Cgibufedt->Text.SubString(0,2));
  }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
    if(SAY<Form2->Ncellc3->Lines->Count-1)
     SAY++;
     else
     {
     QONCELL3="OK";
     for(int l=0;l<Form2->Ncellc3->Lines->Count;l++)
     if(Form2->Bscinc3->Lines->Strings[l]!=Form2->Bscc3->Text)
     {
     Form2->Necellc3->Lines->Add(Form2->Ncellc3->Lines->Strings[l]);
     Form2->Bscexc3->Lines->Add(Form2->Bscinc3->Lines->Strings[l]);
     Form2->Ncellc3->Lines->Delete(l);
     Form2->Nbcchc3->Lines->Delete(l);
     Form2->Bscinc3->Lines->Delete(l);
     l--;
     }
     SAY=0;
     }
     Komanda="NOVBETI";
    }

   }

   goto KOM;
  }

//---------------------------Cell4-----------------------------//

if(Komanda=="Komandaqonc4")
 {
 for (int I = 0; I < Form6->Memo1->Lines->Count; I++)
  {
    int k=1;
    if(Form6->Memo1->Lines->Strings[I+1].SubString(0,8)=="WO      ")
    k=2;

    if (int BCCHNO = Form6->Memo1->Lines->Strings[I].Pos("BCCHNO"))
    {
    Form2->Nbcchc4->Lines->Add("");
    Form2->Nbcchc4->Lines->Strings[SAY]=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(BCCHNO,6));
    }

    if (int CGI = Form6->Memo1->Lines->Strings[I].Pos("CGI"))
    {
    Form2->Cgibufedt->Text=Trim(Form6->Memo1->Lines->Strings[I+k].SubString(CGI,20));
    Form2->Cgibufedt->Text=Form2->Cgibufedt->Text.SubString(8,4);
    String SPF=Form2->Cgibufedt->Text.c_str();
    Form2->Bscinc4->Lines->Add("");
    if(SPF[4]=='-')
    Form2->Bscinc4->Lines->Strings[SAY]=Trim(Form2->Cgibufedt->Text.SubString(0,1));
    else
    Form2->Bscinc4->Lines->Strings[SAY]=Trim(Form2->Cgibufedt->Text.SubString(0,2));
  }

    if (int RXOTG = Form6->Memo1->Lines->Strings[I].Pos("<"))
    {
        if(SAY<Form2->Ncellc4->Lines->Count-1)
        SAY++;
        else
        {
         QONCELL4="OK";
        for(int l=0;l<Form2->Ncellc4->Lines->Count;l++)
         if(Form2->Bscinc4->Lines->Strings[l]!=Form2->Bscc4->Text)
         {
         Form2->Necellc4->Lines->Add(Form2->Ncellc4->Lines->Strings[l]);
         Form2->Bscexc4->Lines->Add(Form2->Bscinc4->Lines->Strings[l]);
         Form2->Ncellc4->Lines->Delete(l);
         Form2->Nbcchc4->Lines->Delete(l);
         Form2->Bscinc4->Lines->Delete(l);
         l--;
         }
        SAY=0;
        }
     Komanda="NOVBETI";
    }

   }

   goto KOM;
  }
//------------------------Komandalar---------------------------------//
KOM:

if(Giris==true && Komanda=="NOVBETI" && QONCELL1!="OK")
  {
  Form6->Memo1->Clear();
  Komanda="Komandaqonc1";
 Form3->IdTelnet1->WriteLn("RLDEP:CELL="+Form2->Ncellc1->Lines->Strings[SAY]+";");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" && QONCELL2!="OK" && Form2->Tabc2->TabVisible==true)
  {
  Form6->Memo1->Clear();
  Komanda="Komandaqonc2";
 Form3->IdTelnet1->WriteLn("RLDEP:CELL="+Form2->Ncellc2->Lines->Strings[SAY]+";");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" && QONCELL3!="OK" && Form2->Tabc3->TabVisible==true)
  {
  Form6->Memo1->Clear();
  Komanda="Komandaqonc3";
 Form3->IdTelnet1->WriteLn("RLDEP:CELL="+Form2->Ncellc3->Lines->Strings[SAY]+";");
  goto son;
  }

if(Giris==true && Komanda=="NOVBETI" && QONCELL4!="OK" && Form2->Tabc4->TabVisible==true)
  {
  Form6->Memo1->Clear();
  Komanda="Komandaqonc4";
  Form3->IdTelnet1->WriteLn("RLDEP:CELL="+Form2->Ncellc4->Lines->Strings[SAY]+";");
  goto son;
  }

if(Komanda=="NOVBETI")
   {
   Form6->Memo1->Clear();
   Komanda="SERVISCIXIS";
   if(Form2->Avtocbx->Checked==false)
   Servis="FINISH";
   else
   Servis="";
   Form3->IdTelnet1->WriteLn("");
   }
   
//-------------------------------------SON------------------------------------
  son:;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::ClearPanelDblClick(TObject *Sender)
{
 CELLS="";
 TG1="",TG2="",TG3="",TG4="",RLDEPC1="",RLDEPC2="",RLDEPC3="",RLDEPC4="",RLDHPC1="",RBLT1="",RBLT2="",RBLT3="",RBLT4="";
 RLBDPC1="",RLBDPC2="",RLBDPC3="",RLBDPC4="",RXMFPTG1="",RXMFPTG2="",RXMFPTG3="",RXMFPTG4="";
 RLCFPC1="",RLCFPC2="",RLCFPC3="",RLCFPC4="";
 RLSLPC1="",RLSLPC2="",RLSLPC3="",RLSLPC4="";
 RLCHPC1="",RLCHPC2="",RLCHPC3="",RLCHPC4="";
 RLCPPC1="",RLCPPC2="",RLCPPC3="",RLCPPC4="";
 RLCXPC1="",RLCXPC2="",RLCXPC3="",RLCXPC4="";
 RLLOPC1="",RLLOPC2="",RLLOPC3="",RLLOPC4="";
 RLLUPC1="",RLLUPC2="",RLLUPC3="",RLLUPC4="";
 RLLPPC1="",RLLPPC2="",RLLPPC3="",RLLPPC4="";
 RLLFPC1="",RLLFPC2="",RLLFPC3="",RLLFPC4="";
 RLLDPC1="",RLLDPC2="",RLLDPC3="",RLLDPC4="";
 RLLCPC1="",RLLCPC2="",RLLCPC3="",RLLCPC4="";
 RLSSPC1="",RLSSPC2="",RLSSPC3="",RLSSPC4="";
 RLSBPC1="",RLSBPC2="",RLSBPC3="",RLSBPC4="";
 RLIHPC1="",RLIHPC2="",RLIHPC3="",RLIHPC4="";
 RLLHPC1="",RLLHPC2="",RLLHPC3="",RLLHPC4="";
 RLPCPC1="",RLPCPC2="",RLPCPC3="",RLPCPC4="";
 RLBCPC1="",RLBCPC2="",RLBCPC3="",RLBCPC4="";
 RLCDPC1="",RLCDPC2="",RLCDPC3="",RLCDPC4="";
 RLIMPC1="",RLIMPC2="",RLIMPC3="",RLIMPC4="";
 RLNRPC1="",RLNRPC2="",RLNRPC3="",RLNRPC4="";
 RLMTPC1="",RLMTPC2="",RLMTPC3="",RLMTPC4="";
 RLMBPC1="",RLMBPC2="",RLMBPC3="",RLMBPC4="";

 RXMOPTG1="",RXMOPTG2="",RXMOPTG3="",RXMOPTG4="";
 RXMOPCF1="",RXMOPCF2="",RXMOPCF3="",RXMOPCF4="";
 RXMOPTF1="",RXMOPTF2="",RXMOPTF3="",RXMOPTF4="";
 QONCELL1="",QONCELL2="",QONCELL3="",QONCELL4="";
 DTSTPTG1ODP1="",DTSTPTG2ODP1="",DTSTPTG3ODP1="",DTSTPTG4ODP1="";
 DTSTPTG1ODP3="",DTSTPTG2ODP3="",DTSTPTG3ODP3="",DTSTPTG4ODP3="";
 RXMOP0TG1="",RXMOP1TG1="",RXMOP2TG1="",RXMOP3TG1="",RXMOP4TG1="",RXMOP5TG1="",RXMOP6TG1="",RXMOP7TG1="",RXMOP8TG1="",RXMOP9TG1="",RXMOP10TG1="",RXMOP11TG1="";
 RXMOP0TG2="",RXMOP1TG2="",RXMOP2TG2="",RXMOP3TG2="",RXMOP4TG2="",RXMOP5TG2="",RXMOP6TG2="",RXMOP7TG2="",RXMOP8TG2="",RXMOP9TG2="",RXMOP10TG2="",RXMOP11TG2="";
 RXMOP0TG3="",RXMOP1TG3="",RXMOP2TG3="",RXMOP3TG3="",RXMOP4TG3="",RXMOP5TG3="",RXMOP6TG3="",RXMOP7TG3="",RXMOP8TG3="",RXMOP9TG3="",RXMOP10TG3="",RXMOP11TG3="";
 RXMOP0TG4="",RXMOP1TG4="",RXMOP2TG4="",RXMOP3TG4="",RXMOP4TG4="",RXMOP5TG4="",RXMOP6TG4="",RXMOP7TG4="",RXMOP8TG4="",RXMOP9TG4="",RXMOP10TG4="",RXMOP11TG4="";

}
//---------------------------------------------------------------------------




void __fastcall TForm3::InitPanelDblClick(TObject *Sender)
{
Edgeyoxdu->Checked=true;

Form3->Tgbuffer->Clear();
Form3->Rbltbuffer->Clear();

Form2->Rlslptchc1->Text="";
Form2->Rlslpsdcchc1->Text="";

Form2->Rlslptchc2->Text="";
Form2->Rlslpsdcchc2->Text="";

Form2->Rlslptchc3->Text="";
Form2->Rlslpsdcchc3->Text="";

Form2->Rlslptchc4->Text="";
Form2->Rlslpsdcchc4->Text="";

Tru1k1->Color=clBtnFace;
Tru2k1->Color=clBtnFace;
Tru3k1->Color=clBtnFace;
Tru4k1->Color=clBtnFace;
Tru5k1->Color=clBtnFace;
Tru6k1->Color=clBtnFace;
Tru7k1->Color=clBtnFace;
Tru8k1->Color=clBtnFace;
Tru9k1->Color=clBtnFace;
Tru10k1->Color=clBtnFace;
Tru11k1->Color=clBtnFace;
Tru12k1->Color=clBtnFace;

Tru1k2->Color=clBtnFace;
Tru2k2->Color=clBtnFace;
Tru3k2->Color=clBtnFace;
Tru4k2->Color=clBtnFace;
Tru5k2->Color=clBtnFace;
Tru6k2->Color=clBtnFace;
Tru7k2->Color=clBtnFace;
Tru8k2->Color=clBtnFace;
Tru9k2->Color=clBtnFace;
Tru10k2->Color=clBtnFace;
Tru11k2->Color=clBtnFace;
Tru12k2->Color=clBtnFace;

Tru1k3->Color=clBtnFace;
Tru2k3->Color=clBtnFace;
Tru3k3->Color=clBtnFace;
Tru4k3->Color=clBtnFace;
Tru5k3->Color=clBtnFace;
Tru6k3->Color=clBtnFace;
Tru7k3->Color=clBtnFace;
Tru8k3->Color=clBtnFace;
Tru9k3->Color=clBtnFace;
Tru10k3->Color=clBtnFace;
Tru11k3->Color=clBtnFace;
Tru12k3->Color=clBtnFace;

Tru1k4->Color=clBtnFace;
Tru2k4->Color=clBtnFace;
Tru3k4->Color=clBtnFace;
Tru4k4->Color=clBtnFace;
Tru5k4->Color=clBtnFace;
Tru6k4->Color=clBtnFace;
Tru7k4->Color=clBtnFace;
Tru8k4->Color=clBtnFace;
Tru9k4->Color=clBtnFace;
Tru10k4->Color=clBtnFace;
Tru11k4->Color=clBtnFace;
Tru12k4->Color=clBtnFace;

Etru1k1->Color=clBtnFace;
Etru2k1->Color=clBtnFace;
Etru3k1->Color=clBtnFace;
Etru4k1->Color=clBtnFace;
Etru5k1->Color=clBtnFace;
Etru6k1->Color=clBtnFace;
Etru7k1->Color=clBtnFace;
Etru8k1->Color=clBtnFace;
Etru9k1->Color=clBtnFace;
Etru10k1->Color=clBtnFace;
Etru11k1->Color=clBtnFace;
Etru12k1->Color=clBtnFace;

Etru1k2->Color=clBtnFace;
Etru2k2->Color=clBtnFace;
Etru3k2->Color=clBtnFace;
Etru4k2->Color=clBtnFace;
Etru5k2->Color=clBtnFace;
Etru6k2->Color=clBtnFace;
Etru7k2->Color=clBtnFace;
Etru8k2->Color=clBtnFace;
Etru9k2->Color=clBtnFace;
Etru10k2->Color=clBtnFace;
Etru11k2->Color=clBtnFace;
Etru12k2->Color=clBtnFace;

Etru1k3->Color=clBtnFace;
Etru2k3->Color=clBtnFace;
Etru3k3->Color=clBtnFace;
Etru4k3->Color=clBtnFace;
Etru5k3->Color=clBtnFace;
Etru6k3->Color=clBtnFace;
Etru7k3->Color=clBtnFace;
Etru8k3->Color=clBtnFace;
Etru9k3->Color=clBtnFace;
Etru10k3->Color=clBtnFace;
Etru11k3->Color=clBtnFace;
Etru12k3->Color=clBtnFace;

Etru1k4->Color=clBtnFace;
Etru2k4->Color=clBtnFace;
Etru3k4->Color=clBtnFace;
Etru4k4->Color=clBtnFace;
Etru5k4->Color=clBtnFace;
Etru6k4->Color=clBtnFace;
Etru7k4->Color=clBtnFace;
Etru8k4->Color=clBtnFace;
Etru9k4->Color=clBtnFace;
Etru10k4->Color=clBtnFace;
Etru11k4->Color=clBtnFace;
Etru12k4->Color=clBtnFace;

Chgr1c1cbox->Checked=false;
Chgr2c1cbox->Checked=false;
Chgr3c1cbox->Checked=false;

Chgr1c2cbox->Checked=false;
Chgr2c2cbox->Checked=false;
Chgr3c2cbox->Checked=false;

Chgr1c3cbox->Checked=false;
Chgr2c3cbox->Checked=false;
Chgr3c3cbox->Checked=false;

Chgr1c4cbox->Checked=false;
Chgr2c4cbox->Checked=false;
Chgr3c4cbox->Checked=false;

Form2->Ncellc1->Clear();
Form2->Nbcchc1->Clear();
Form2->Bscinc1->Clear();
Form2->Necellc1->Clear();
Form2->Bscexc1->Clear();

Form2->Ncellc2->Clear();
Form2->Nbcchc2->Clear();
Form2->Bscinc2->Clear();
Form2->Necellc2->Clear();
Form2->Bscexc2->Clear();

Form2->Ncellc3->Clear();
Form2->Nbcchc3->Clear();
Form2->Bscinc3->Clear();
Form2->Necellc3->Clear();
Form2->Bscexc3->Clear();

Form2->Ncellc4->Clear();
Form2->Nbcchc4->Clear();
Form2->Bscinc4->Clear();
Form2->Necellc4->Clear();
Form2->Bscexc4->Clear();

Form2->Brc1->Text="";
Form2->Brc2->Text="";
Form2->Brc3->Text="";
Form2->Brc4->Text="";

Form2->Codec1->Text="";
Form2->Codec2->Text="";
Form2->Codec3->Text="";
Form2->Codec4->Text="";

Edgeyoxdu->Checked=true;

Odp0k1->Checked=true;
Odp1k1->Checked=false;
Odp2k1->Checked=false;
Odp3k1->Checked=false;

Odp0k2->Checked=true;
Odp1k2->Checked=false;
Odp2k2->Checked=false;
Odp3k2->Checked=false;

Odp0k3->Checked=true;
Odp1k3->Checked=false;
Odp2k3->Checked=false;
Odp3k3->Checked=false;

Odp0k3->Checked=true;
Odp1k3->Checked=false;
Odp2k3->Checked=false;
Odp3k3->Checked=false;

}
//---------------------------------------------------------------------------







void __fastcall TForm3::TgbufferDblClick(TObject *Sender)
{
for(int f=0;f<Memo1->Lines->Count;f++)
if(Memo1->Lines->Strings[f]=="")
{
Memo1->Lines->Delete(f);
f--;
}

for(int o=0;o<Tgbuffer->Lines->Count-1;o++)
for(int p=o+1;p<Tgbuffer->Lines->Count;p++)
if(Tgbuffer->Lines->Strings[p]==Tgbuffer->Lines->Strings[o])
{
Tgbuffer->Lines->Delete(p);
p--;
}

Tgsayi->ItemIndex=Tgbuffer->Lines->Count-1;
Form3->TgsayiChange(Tgsayi);
if(Tgsayi->ItemIndex>=0)
Tg1->Text=Tgbuffer->Lines->Strings[0];
if(Tgsayi->ItemIndex>=1)
Tg2->Text=Tgbuffer->Lines->Strings[1];
if(Tgsayi->ItemIndex>=2)
Tg3->Text=Tgbuffer->Lines->Strings[2];
if(Tgsayi->ItemIndex>=3)
Tg4->Text=Tgbuffer->Lines->Strings[3];
Form3->TgsayiChange(Tgsayi);        
}
//---------------------------------------------------------------------------







void __fastcall TForm3::Devek1EditDblClick(TObject *Sender)
{
String S;
for (int k=1;k<=Devek1Edit->Text.Length();k++)
{
 if(Devek1Edit->Text.SubString(k,2)=="&&")
 {
 S=S+Devek1Edit->Text.SubString(k,2);
 S=S+"-";
 k++;
 }
 else if (Devek1Edit->Text.SubString(k,1)=="&")
 {
 S=S+Devek1Edit->Text.SubString(k,1);
 S=S+"-";
 }
 else
 {
 S=S+Devek1Edit->Text.SubString(k,1);
 }
}

Devek1Edit->Text=S;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Devk1EditDblClick(TObject *Sender)
{
String S;
for (int k=1;k<=Devk1Edit->Text.Length();k++)
{
 if(Devk1Edit->Text.SubString(k,2)=="&&")
 {
 S=S+Devk1Edit->Text.SubString(k,2);
 S=S+"-";
 k++;
 }
 else if (Devk1Edit->Text.SubString(k,1)=="&")
 {
 S=S+Devk1Edit->Text.SubString(k,1);
 S=S+"-";
 }
 else
 {
 S=S+Devk1Edit->Text.SubString(k,1);
 }
}

Devk1Edit->Text=S;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Devk2EditDblClick(TObject *Sender)
{
String S;
for (int k=1;k<=Devk2Edit->Text.Length();k++)
{
 if(Devk2Edit->Text.SubString(k,2)=="&&")
 {
 S=S+Devk2Edit->Text.SubString(k,2);
 S=S+"-";
 k++;
 }
 else if (Devk2Edit->Text.SubString(k,1)=="&")
 {
 S=S+Devk2Edit->Text.SubString(k,1);
 S=S+"-";
 }
 else
 {
 S=S+Devk2Edit->Text.SubString(k,1);
 }
}

Devk2Edit->Text=S;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Devk3EditDblClick(TObject *Sender)
{
String S;
for (int k=1;k<=Devk3Edit->Text.Length();k++)
{
 if(Devk3Edit->Text.SubString(k,2)=="&&")
 {
 S=S+Devk3Edit->Text.SubString(k,2);
 S=S+"-";
 k++;
 }
 else if (Devk3Edit->Text.SubString(k,1)=="&")
 {
 S=S+Devk3Edit->Text.SubString(k,1);
 S=S+"-";
 }
 else
 {
 S=S+Devk3Edit->Text.SubString(k,1);
 }
}

Devk3Edit->Text=S;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Devk4EditDblClick(TObject *Sender)
{
String S;
for (int k=1;k<=Devk4Edit->Text.Length();k++)
{
 if(Devk4Edit->Text.SubString(k,2)=="&&")
 {
 S=S+Devk4Edit->Text.SubString(k,2);
 S=S+"-";
 k++;
 }
 else if (Devk4Edit->Text.SubString(k,1)=="&")
 {
 S=S+Devk4Edit->Text.SubString(k,1);
 S=S+"-";
 }
 else
 {
 S=S+Devk4Edit->Text.SubString(k,1);
 }
}

Devk4Edit->Text=S;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Devek3EditDblClick(TObject *Sender)
{
String S;
for (int k=1;k<=Devek3Edit->Text.Length();k++)
{
 if(Devek3Edit->Text.SubString(k,2)=="&&")
 {
 S=S+Devek3Edit->Text.SubString(k,2);
 S=S+"-";
 k++;
 }
 else if (Devek3Edit->Text.SubString(k,1)=="&")
 {
 S=S+Devek3Edit->Text.SubString(k,1);
 S=S+"-";
 }
 else
 {
 S=S+Devek3Edit->Text.SubString(k,1);
 }
}

Devek3Edit->Text=S;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Devek4EditDblClick(TObject *Sender)
{
String S;
for (int k=1;k<=Devek4Edit->Text.Length();k++)
{
 if(Devek4Edit->Text.SubString(k,2)=="&&")
 {
 S=S+Devek4Edit->Text.SubString(k,2);
 S=S+"-";
 k++;
 }
 else if (Devek4Edit->Text.SubString(k,1)=="&")
 {
 S=S+Devek4Edit->Text.SubString(k,1);
 S=S+"-";
 }
 else
 {
 S=S+Devek4Edit->Text.SubString(k,1);
 }
}

Devek4Edit->Text=S;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Devek2EditDblClick(TObject *Sender)
{
String S;
for (int k=1;k<=Devek2Edit->Text.Length();k++)
{
 if(Devek2Edit->Text.SubString(k,2)=="&&")
 {
 S=S+Devek2Edit->Text.SubString(k,2);
 S=S+"-";
 k++;
 }
 else if (Devek2Edit->Text.SubString(k,1)=="&")
 {
 S=S+Devek2Edit->Text.SubString(k,1);
 S=S+"-";
 }
 else
 {
 S=S+Devek2Edit->Text.SubString(k,1);
 }
}

Devek2Edit->Text=S;        
}
//---------------------------------------------------------------------------



