//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EmailUnit1.h"
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
void __fastcall TForm1::NMSMTP1Connect(TObject *Sender)
{
Send->Color=clLime;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NMSMTP1Disconnect(TObject *Sender)
{
Send->Color=clBtnFace;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SendClick(TObject *Sender)
{
 /* NMSMTP1->Host = Host->Text;
     NMSMTP1->UserID = Userid->Text;
      if(!NMSMTP1->Connected)
      NMSMTP1->Connect();

      NMSMTP1->PostMessage->FromAddress = From->Text;
      NMSMTP1->PostMessage->ToAddress->Text = To->Text;
      NMSMTP1->PostMessage->Subject ="NOD";
      NMSMTP1->PostMessage->Body->Text =Body->Text;
      NMSMTP1->SendMail();
     NMSMTP1->PostMessage->ToAddress->Text ="tetahmaz@azercell.com";
     NMSMTP1->SendMail();
      Timer3->Enabled=true;   */

     NMSMTP1->SubType = mtPlain;
    NMSMTP1->Host = Host->Text;
    NMSMTP1->UserID = Userid->Text;  //Login
    if(!NMSMTP1->Connected)
      NMSMTP1->Connect();

    NMSMTP1->PostMessage->FromAddress = From->Text;
    NMSMTP1->PostMessage->FromName = "Name";
    NMSMTP1->PostMessage->ToAddress->Text = To->Text;
    NMSMTP1->PostMessage->Body->Text = Body->Text;
    //NMSMTP1->PostMessage->Attachments->Text = "c:\\File.txt";
    NMSMTP1->PostMessage->Subject = SubjectEdit->Text;
    NMSMTP1->PostMessage->LocalProgram = "Unknow";
    //NMSMTP1->PostMessage->Date = "07.22.41";

    NMSMTP1->SendMail();
    Timer3->Enabled=true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
Timer3->Enabled=false;
NMSMTP1->Disconnect();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        NMSMTP1->SubType = mtPlain;
        NMSMTP1->Host = Host->Text;
        NMSMTP1->UserID = Userid->Text;
        if(!NMSMTP1->Connected)
      NMSMTP1->Connect();
      if(NMSMTP1->Verify(Userid->Text))
      ShowMessage("Dogru adress");
      else
      ShowMessage("Yanlish adress");

}
//---------------------------------------------------------------------------
