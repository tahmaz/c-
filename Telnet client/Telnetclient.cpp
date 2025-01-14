//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Telnetclient.h"
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
IdTelnet1->Host=Edit2->Text;
IdTelnet1->Port=StrToInt(Edit3->Text);
IdTelnet1->Connect();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
IdTelnet1->Disconnect();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IdTelnet1DataAvailable(AnsiString Buffer)
{
Memo1->Text=Memo1->Text+Buffer;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
Form1->Button3Click(Button3);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::IdTelnet1Connect()
{
Memo1->Lines->Add("Connected...");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IdTelnet1Connected(TObject *Sender)
{
Memo1->Lines->Add("Connected...");        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IdTelnet1Disconnect()
{
Memo1->Lines->Add("Disconnect...");        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IdTelnet1Disconnected(TObject *Sender)
{
Memo1->Lines->Add("Disconnected...");        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IdTelnet1Status(TObject *axSender,
      const TIdStatus axStatus, const AnsiString asStatusText)
{
Memo1->Lines->Add(asStatusText+"Status...");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IdTelnet1TelnetCommand(TComponent *Sender,
      TTelnetCommand Status)
{
Memo1->Lines->Add("Telnet Command...");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
IdTelnet1->WriteLn(Edit1->Text);
}
//---------------------------------------------------------------------------

