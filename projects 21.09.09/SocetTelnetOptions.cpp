//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SocetTelnetOptions.h"
#include "SocetTelnet.h"
#include "Main.h"
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
int Con;
int Connection()
{
if(!Form5->IdTelnetcon1->Connected())
::Con=1;
return(0);
}


void __fastcall TForm5::OkClick(TObject *Sender)
{
if(NodTable->FieldByName("Con")->AsInteger==0)
{
Connection();
switch(::Con){
  case 1:
  {
  IdTelnetcon1->Host=NodTable->FieldByName("IP")->AsString;
 IdTelnetcon1->Port=NodTable->FieldByName("Port")->AsInteger;
  Form5->IdTelnetcon1->Connect();
  }
            }
}

/*
 IdTelnetcon1->Host=Ipcon1->Text;
 IdTelnetcon1->Port=StrToInt(Portcon1->Text);

 IdTelnetcon2->Host=Ipcon2->Text;
 IdTelnetcon2->Port=StrToInt(Portcon2->Text);

 IdTelnetcon3->Host=Ipcon3->Text;
 IdTelnetcon3->Port=StrToInt(Portcon3->Text);

 IdTelnetcon4->Host=Ipcon4->Text;
 IdTelnetcon4->Port=StrToInt(Portcon4->Text);

 IdTelnetcon5->Host=Ipcon5->Text;
 IdTelnetcon5->Port=StrToInt(Portcon5->Text);

 IdTelnetcon6->Host=Ipcon6->Text;
 IdTelnetcon6->Port=StrToInt(Portcon6->Text);

 IdTelnetcon7->Host=Ipcon7->Text;
 IdTelnetcon7->Port=StrToInt(Portcon7->Text);

 IdTelnetcon8->Host=Ipcon8->Text;
 IdTelnetcon8->Port=StrToInt(Portcon8->Text);

 IdTelnetcon9->Host=Ipcon9->Text;
 IdTelnetcon9->Port=StrToInt(Portcon9->Text);

 IdTelnetcon10->Host=Ipcon10->Text;
 IdTelnetcon10->Port=StrToInt(Portcon10->Text);

Form5->Close();     */
}
//---------------------------------------------------------------------------






void __fastcall TForm5::NoddelClick(TObject *Sender)
{
NodTable->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::NodaddClick(TObject *Sender)
{
NodTable->Insert();
NodTable->FieldByName("Number")->AsInteger=StrToInt(Nodnumber->Text);
NodTable->FieldByName("Name")->AsString=Nodname->Text;
NodTable->FieldByName("NE")->AsString=Nodne->Text;
NodTable->FieldByName("IP")->AsString=Nodip->Text;
NodTable->FieldByName("Port")->AsInteger=StrToInt(Nodport->Text);
NodTable->FieldByName("Con")->AsInteger=0;
NodTable->Post();
}
//---------------------------------------------------------------------------
























void __fastcall TForm5::IdTelnetcon1DataAvailable(AnsiString Buffer)
{
//------------------------avtomatik giris---------------------//
if(Giriscon1==false){

    if (int AAA = Buffer.Pos("Userid:"))
    IdTelnetcon1->WriteLn(User->Text);

    if (int BBB = Buffer.Pos("Password:"))
    IdTelnetcon1->WriteLn(Password->Text);

    if (int CCC = Buffer.Pos("NE:"))
    IdTelnetcon1->WriteLn("NE="+NodTable->FieldByName("Ne")->AsString);

     if (int DDD =Buffer.Pos("<"))
     {
    Giriscon1=true;
    NodTable->Edit();
   NodTable->FieldByName("Con")->AsInteger=1;
   NodTable->Post();
    }
 }


}
//---------------------------------------------------------------------------

void __fastcall TForm5::IdTelnetcon1Disconnected(TObject *Sender)
{
Giriscon1=false;
NodTable->Edit();
   NodTable->FieldByName("Con")->AsInteger=0;
   NodTable->Post();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button1Click(TObject *Sender)
{
NodTable->Edit();
   NodTable->FieldByName("Con")->AsInteger=0;
   NodTable->Post();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::IdTelnetcon2DataAvailable(AnsiString Buffer)
{
if(Giriscon2==false){

    if (int AAA = Buffer.Pos("Userid:"))
    IdTelnetcon2->WriteLn(User->Text);

    if (int BBB = Buffer.Pos("Password:"))
    IdTelnetcon2->WriteLn(Password->Text);

    if (int CCC = Buffer.Pos("NE:"))
    IdTelnetcon2->WriteLn("NE="+NodTable->FieldByName("Ne")->AsString);

     if (int DDD =Buffer.Pos("<"))
     {
    Giriscon1=true;
    NodTable->Edit();
   NodTable->FieldByName("Con")->AsInteger=1;
   NodTable->Post();
    }
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::IdTelnetcon2Disconnected(TObject *Sender)
{
Giriscon2=false;
NodTable->Edit();
   NodTable->FieldByName("Con")->AsInteger=0;
   NodTable->Post();
}
//---------------------------------------------------------------------------

