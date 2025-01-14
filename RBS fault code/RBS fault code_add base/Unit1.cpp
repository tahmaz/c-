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

void __fastcall TForm1::Button1Click(TObject *Sender)
{

if(Memo1->Text!=""){
Memo2->Lines->Add("Started.");

                if(Query1->Active==true)
               Query1->Close();

               Query1->SQL->Clear();
               Query1->SQL->Add("truncate table faultdecoder");
               Query1->ExecSQL();

        String Faultcode="",Faultname="",Relatedfaults="",Description="",Action="",Note="";

 for(int i=0;i<Memo1->Lines->Count;i++){
         if(int FIND=Memo1->Lines->Strings[i].Pos("Fault No."))
         {
               if(Faultcode!="" && Faultname!=""){

               if(Query1->Active==true)
               Query1->Close();

               Query1->SQL->Clear();
               Query1->SQL->Add("Insert into faultdecoder(Faultcode,Faultname,Relatedfaults,Description,Action,Note)");
               Query1->SQL->Add("Values ('"+Faultcode+"','"+Faultname+"','"+Relatedfaults+"','"+Description+"','"+Action+"','"+Note+"')");
               Query1->ExecSQL();

               /*Memo2->Lines->Add("Faultcode: "+Faultcode);
               Memo2->Lines->Add("Faultname: "+Faultname);
               Memo2->Lines->Add("Relatedfaults: "+Relatedfaults);
               Memo2->Lines->Add("Description: "+Description);
               Memo2->Lines->Add("Action: "+Action);
               Memo2->Lines->Add("Note: "+Note);
               Memo2->Lines->Add("");*/
               
               Faultcode="";
               Faultname="";
               Relatedfaults="";
               Description="";
               Action="";
               Note="";
               }
               Faultcode=Trim(Memo1->Lines->Strings[i].SubString(10,Memo1->Lines->Strings[i].Length()));

         }

         if(int FIND=Memo1->Lines->Strings[i].Pos("Fault name"))
         Faultname=Trim(Memo1->Lines->Strings[i].SubString(11,Memo1->Lines->Strings[i].Length()));

         if(int FIND=Memo1->Lines->Strings[i].Pos("Related faults"))
         {
         Relatedfaults=Trim(Memo1->Lines->Strings[i].SubString(15,Memo1->Lines->Strings[i].Length()));
                while(true){
                int FIND2=Memo1->Lines->Strings[i+1].Pos("Description");
                int FIND3=Memo1->Lines->Strings[i+1].Pos("Action");
                int FIND4=Memo1->Lines->Strings[i+1].Pos("Note");
                int FIND5=Memo1->Lines->Strings[i+1].Pos("Fault No.");
                        if(!(FIND2>0 || FIND3>0 || FIND4>0 || FIND5>0)){
                        Relatedfaults=Relatedfaults+". "+Memo1->Lines->Strings[i+1];
                                if(Memo1->Lines->Count==i-1)
                                break;
                        i++;
                        }
                        else
                        break;

                }
         }
         if(int FIND=Memo1->Lines->Strings[i].Pos("Description"))
         {
         Description=Trim(Memo1->Lines->Strings[i].SubString(12,Memo1->Lines->Strings[i].Length()));
                for(;;i++){
                int FIND3=Memo1->Lines->Strings[i+1].Pos("Action");
                int FIND4=Memo1->Lines->Strings[i+1].Pos("Note");
                int FIND5=Memo1->Lines->Strings[i+1].Pos("Fault No.");
                        if(!(FIND3>0 || FIND4>0 || FIND5>0)){
                        Description=Description+". "+Memo1->Lines->Strings[i+1];
                                if(Memo1->Lines->Count==i-1)
                                break;
                        }
                        else
                        break;

                }
         }
         if(int FIND=Memo1->Lines->Strings[i].Pos("Action"))
         {
         Action=Trim(Memo1->Lines->Strings[i].SubString(7,Memo1->Lines->Strings[i].Length()));
                for(;;i++){
                int FIND4=Memo1->Lines->Strings[i+1].Pos("Note");
                int FIND5=Memo1->Lines->Strings[i+1].Pos("Fault No.");
                        if(!(FIND4>0 || FIND5>0)){
                        Action=Action+". "+Memo1->Lines->Strings[i+1];
                                if(Memo1->Lines->Count==i-1)
                                break;
                        }
                        else
                        break;

                }
         }
         if(int FIND=Memo1->Lines->Strings[i].Pos("Note"))
         {
         Note=Trim(Memo1->Lines->Strings[i].SubString(6,Memo1->Lines->Strings[i].Length()));
                for(;;i++){
                int FIND5=Memo1->Lines->Strings[i+1].Pos("Fault No.");
                        if(!FIND5>0){
                        Note=Note+". "+Memo1->Lines->Strings[i+1];
                                if(Memo1->Lines->Count==i-1)
                                break;
                        }
                        else
                        break;

                }
         }

         if(Memo1->Lines->Count==i-1)
         {
               Query1->Close();
               Query1->SQL->Clear();
               Query1->SQL->Add("Insert into faultdecoder(Faultcode,Faultname,Relatedfaults,Description,Action,Note)");
               Query1->SQL->Add("Values ('"+Faultcode+"','"+Faultname+"','"+Relatedfaults+"','"+Description+"','"+Action+"','"+Note+"')");
               Query1->ExecSQL();

               /*Memo2->Lines->Add("Faultcode: "+Faultcode);
               Memo2->Lines->Add("Faultname: "+Faultname);
               Memo2->Lines->Add("Relatedfaults: "+Relatedfaults);
               Memo2->Lines->Add("Description: "+Description);
               Memo2->Lines->Add("Action: "+Action);
               Memo2->Lines->Add("Note: "+Note);
               Memo2->Lines->Add("");  */

               Faultcode="";
               Faultname="";
               Relatedfaults="";
               Description="";
               Action="";
               Note="";
         }

 }

Memo2->Lines->Add("Finished.");
}
else
ShowMessage("Please insert text(RBS faults)!");

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  /* perform a global case-sensitive search for FindText in Memo1 */
  int SelPos = Memo1->Lines->Text.Pos(ReplaceDialog1->FindText);
  if (SelPos > 0)
  {
    Memo1->SelStart = SelPos - 1;
    Memo1->SelLength = ReplaceDialog1->FindText.Length();
    // Replace selected text with ReplaceText
    Memo1->SelText = ReplaceDialog1->ReplaceText;
  }
  else
    MessageBeep(0);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1Change(TObject *Sender)
{
          ReplaceDialog1->FindText="\'";
int SelPos = Memo1->Lines->Text.Pos(ReplaceDialog1->FindText);
  if (SelPos > 0)
  {
    Memo1->SelStart = SelPos - 1;
    Memo1->SelLength = ReplaceDialog1->FindText.Length();
    // Replace selected text with ReplaceText
    Memo1->SelText = ReplaceDialog1->ReplaceText;
  }

  ReplaceDialog1->FindText="\"";

int SelPos2 = Memo1->Lines->Text.Pos(ReplaceDialog1->FindText);
  if (SelPos2 > 0)
  {
    Memo1->SelStart = SelPos2 - 1;
    Memo1->SelLength = ReplaceDialog1->FindText.Length();
    // Replace selected text with ReplaceText
    Memo1->SelText = ReplaceDialog1->ReplaceText;
  }
}
//---------------------------------------------------------------------------
