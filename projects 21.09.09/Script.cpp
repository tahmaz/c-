//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Script.h"
#include "Progres.h"
#include "TRGSM.h"
#include "TRGSMprUnit3.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "WinSkinForm"
#pragma link "WinSkinForm"
#pragma link "WinSkinData"
#pragma resource "*.dfm"
TScriptForm *ScriptForm;
//---------------------------------------------------------------------------
__fastcall TScriptForm::TScriptForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TScriptForm::Open1Click(TObject *Sender)
{
if(Opencna->Execute())
Memocna->Lines->LoadFromFile(Opencna->FileName);
        
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::Saveas1Click(TObject *Sender)
{
if(Savecna->Execute())
Memocna->Lines->SaveToFile(Savecna->FileName+Savecna->Filter);
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::Table2Click(TObject *Sender)
{
Gridcna->Show();
Memocna->Hide();

}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::Script1Click(TObject *Sender)
{
Memocna->Show();
Gridcna->Hide();

}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::Makescript1Click(TObject *Sender)
{
if(Tablecna->Active==false)
Tablecna->Active=true;
//-------------------------------------Cedvele elave---------------------------//
while(!Tablecna->Eof)
Tablecna->Delete();
ProgressForm->Show();
ProgressForm->ProgressBar1->Max=Memocna->Lines->Count;
for(int k=0;k<=Memocna->Lines->Count;k++)
{
 ProgressForm->ProgressBar1->Position=k;
 if(int Cell=Memocna->Lines->Strings[k].Pos("Check of"))
 if(int Noqta=Memocna->Lines->Strings[k].Pos(":"))
 for(int s=k+1;s<=Memocna->Lines->Count;s++)
 {
 if(Form5->CheckBox35->Checked==true)
 if(int Number=Memocna->Lines->Strings[s].Pos("[35]"))
 if(int Cellr=Memocna->Lines->Strings[s].Pos("cell"))
 if(int Value=Memocna->Lines->Strings[s].Pos("value"))
 if(int Nqt=Memocna->Lines->Strings[s].Pos("."))
 if(int Active=Memocna->Lines->Strings[s].Pos("ACTIVE"))
 {
 Tablecna->Insert();
 Tablecna->FieldByName("Number")->AsInteger=35;
 Tablecna->FieldByName("Cell")->AsString=Trim(Memocna->Lines->Strings[k].SubString(Noqta+1,8));
 Tablecna->FieldByName("Mbcch")->AsString=Trim(Memocna->Lines->Strings[s].SubString(Value+5,Nqt-Value-5));
 Tablecna->Post();
 }

 if(Form5->CheckBox223->Checked==true)
 if(int Number=Memocna->Lines->Strings[s].Pos("[223]"))
 if(int Cell=Memocna->Lines->Strings[s].Pos("UTRAN"))
 if(int Value=Memocna->Lines->Strings[s].Pos("value"))
 {
 Tablecna->Insert();
 Tablecna->FieldByName("Number")->AsInteger=223;
 Tablecna->FieldByName("Cell")->AsString=Trim(Memocna->Lines->Strings[k].SubString(Noqta+1,8));
 Tablecna->FieldByName("Value")->AsString=Trim(Memocna->Lines->Strings[s].SubString(Value+5,16));
 Tablecna->Post();
 }

 if(Form5->CheckBox36->Checked==true)
 if(int Number=Memocna->Lines->Strings[s].Pos("[36]"))
 if(int Value=Memocna->Lines->Strings[s].Pos("Value"))
 if(int Active=Memocna->Lines->Strings[s].Pos("ACTIVE"))
 if(int in=Memocna->Lines->Strings[s].Pos("in"))
 {
 Tablecna->Insert();
 Tablecna->FieldByName("Number")->AsInteger=36;
 Tablecna->FieldByName("Cell")->AsString=Trim(Memocna->Lines->Strings[k].SubString(Noqta+1,8));
 Tablecna->FieldByName("Mbcch")->AsString=Trim(Memocna->Lines->Strings[s].SubString(Value+5,in-Value-5));
 Tablecna->Post();
 }

 if(Form5->CheckBox224->Checked==true)
 if(int Number=Memocna->Lines->Strings[s].Pos("[224]"))
 if(int Cell=Memocna->Lines->Strings[s].Pos("UTRAN"))
 if(int Value=Memocna->Lines->Strings[s].Pos("Value"))
 {
 Tablecna->Insert();
 Tablecna->FieldByName("Number")->AsInteger=224;
 Tablecna->FieldByName("Cell")->AsString=Trim(Memocna->Lines->Strings[k].SubString(Noqta+1,8));
 Tablecna->FieldByName("Value")->AsString=Trim(Memocna->Lines->Strings[s].SubString(Value+5,16));
 Tablecna->Post();
 }

 if(Form5->CheckBox90->Checked==true)
 if(int Number=Memocna->Lines->Strings[s].Pos("[90]"))
 {
 Tablecna->Insert();
 Tablecna->FieldByName("Number")->AsInteger=90;
 Tablecna->FieldByName("Cell")->AsString=Trim(Memocna->Lines->Strings[k].SubString(Noqta+1,8));
 Tablecna->Post();
 }

 if(Form5->CheckBox59->Checked==true)
 if(int Number=Memocna->Lines->Strings[s].Pos("[59]"))
 if(int BSRXMIN=Memocna->Lines->Strings[s].Pos("from BSRXMIN"))
 {
 Tablecna->Insert();
 Tablecna->FieldByName("Number")->AsInteger=59;
 Tablecna->FieldByName("Cell")->AsString=Trim(Memocna->Lines->Strings[k].SubString(Noqta+1,8));
 Tablecna->FieldByName("Mbcch")->AsString=Trim(Memocna->Lines->Strings[s].SubString(BSRXMIN+14,3));
 Tablecna->Post();
 }

 if(Form5->CheckBox61->Checked==true)
 if(int Number=Memocna->Lines->Strings[s].Pos("[61]"))
 if(int MSRXMIN=Memocna->Lines->Strings[s].Pos("from MSRXMIN"))
 {
 Tablecna->Insert();
 Tablecna->FieldByName("Number")->AsInteger=61;
 Tablecna->FieldByName("Cell")->AsString=Trim(Memocna->Lines->Strings[k].SubString(Noqta+1,8));
 Tablecna->FieldByName("Mbcch")->AsString=Trim(Memocna->Lines->Strings[s].SubString(MSRXMIN+14,3));
 Tablecna->Post();
 }

 if(Form5->CheckBox56->Checked==true)
 if(int Number=Memocna->Lines->Strings[s].Pos("[56]"))
 if(int BSPWR=Memocna->Lines->Strings[s].Pos("from BSPWR"))
 {
 Tablecna->Insert();
 Tablecna->FieldByName("Number")->AsInteger=56;
 Tablecna->FieldByName("Cell")->AsString=Trim(Memocna->Lines->Strings[k].SubString(Noqta+1,8));
 Tablecna->FieldByName("Mbcch")->AsString=Trim(Memocna->Lines->Strings[s].SubString(BSPWR+12,2));
 Tablecna->Post();
 }

 if(Form5->CheckBox57->Checked==true)
 if(int Number=Memocna->Lines->Strings[s].Pos("[57]"))
 if(int BSTXPWR=Memocna->Lines->Strings[s].Pos("from BSTXPWR"))
 {
 Tablecna->Insert();
 Tablecna->FieldByName("Number")->AsInteger=57;
 Tablecna->FieldByName("Cell")->AsString=Trim(Memocna->Lines->Strings[k].SubString(Noqta+1,8));
 Tablecna->FieldByName("Mbcch")->AsString=Trim(Memocna->Lines->Strings[s].SubString(BSTXPWR+14,2));
 Tablecna->Post();
 }

 if(int Cellson=Memocna->Lines->Strings[s].Pos("Check of")){
 k=s-1;
 goto next;}
}

next:

}
//-----------------------------------Script------------------------------------//
Memocna->Clear();
ProgressForm->ProgressBar1->Max=Tablecna->RecordCount;
for(int c=1;c<=Tablecna->RecordCount;c++){
Tablecna->RecNo=c;
ProgressForm->ProgressBar1->Position=c;

if(Tablecna->FieldByName("Number")->AsInteger==35)
Memocna->Lines->Add("RLMFC:CELL="+Tablecna->FieldByName("Cell")->AsString+",MBCCHNO="+Tablecna->FieldByName("Mbcch")->AsInteger+",MRNIC;");

if(Tablecna->FieldByName("Number")->AsInteger==223)
Memocna->Lines->Add("RLUMC:CELL="+Tablecna->FieldByName("Cell")->AsString+",ADD,UMFI="+Tablecna->FieldByName("Value")->AsString+";");

if(Tablecna->FieldByName("Number")->AsInteger==36)
Memocna->Lines->Add("RLMFE:CELL="+Tablecna->FieldByName("Cell")->AsString+",MBCCHNO="+Tablecna->FieldByName("Mbcch")->AsInteger+",MRNIC;");

if(Tablecna->FieldByName("Number")->AsInteger==224)
Memocna->Lines->Add("RLUMC:CELL="+Tablecna->FieldByName("Cell")->AsString+",REM,UMFI="+Tablecna->FieldByName("Value")->AsString+";");

if(Tablecna->FieldByName("Number")->AsInteger==90)
Memocna->Lines->Add("RLDEE:CELL="+Tablecna->FieldByName("Cell")->AsString+";");

if(Tablecna->FieldByName("Number")->AsInteger==59)
Memocna->Lines->Add("RLLOC:CELL="+Tablecna->FieldByName("Cell")->AsString+",BSRXMIN="+Tablecna->FieldByName("Mbcch")->AsInteger+";");

if(Tablecna->FieldByName("Number")->AsInteger==61)
Memocna->Lines->Add("RLLOC:CELL="+Tablecna->FieldByName("Cell")->AsString+",MSRXMIN="+Tablecna->FieldByName("Mbcch")->AsInteger+";");

if(Tablecna->FieldByName("Number")->AsInteger==56)
Memocna->Lines->Add("RLLOC:CELL="+Tablecna->FieldByName("Cell")->AsString+",BSPWR="+Tablecna->FieldByName("Mbcch")->AsInteger+";");

if(Tablecna->FieldByName("Number")->AsInteger==57)
Memocna->Lines->Add("RLLOC:CELL="+Tablecna->FieldByName("Cell")->AsString+",BSTXPWR="+Tablecna->FieldByName("Mbcch")->AsInteger+";");


ProgressForm->ProgressBar1->Position=0;
}
ProgressForm->Close();
}
//---------------------------------------------------------------------------


void __fastcall TScriptForm::Close1Click(TObject *Sender)
{
ScriptForm->Close();
}
//---------------------------------------------------------------------------


void __fastcall TScriptForm::MemocnaKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==0x11)
c=true;

if(Key==0x41)
u=true;

if(c==true && u==true)
Memocna->SelectAll();

}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::MemocnaKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
c=false;
u=false;
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::Button1Click(TObject *Sender)
{
Form1->Memo1->Clear();
for(int q=0;q<Cell->Lines->Count;q++)
{
Form1->Memo1->Lines->Add("RLNRI:CELL="+Cell->Lines->Strings[q]+",CELLR="+Cellr->Lines->Strings[q]+";");
Form1->Memo1->Lines->Add("RLMFC:CELL="+Cell->Lines->Strings[q]+",MBCCHNO="+Cellrbcch->Lines->Strings[q]+",MRNIC;");
Form1->Memo1->Lines->Add("RLMFC:CELL="+Cellr->Lines->Strings[q]+",MBCCHNO="+Cellbcch->Lines->Strings[q]+",MRNIC;");
Form1->Memo1->Lines->Add("RLNRC:CELL="+Cell->Lines->Strings[q]+",CELLR="+Cellr->Lines->Strings[q]+",KHYST=3,LHYST=6,AWOFFSET=3,CS=NO;");
Form1->Memo1->Lines->Add("");
}
Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::CellChange(TObject *Sender)
{
Celllabel->Caption=Cell->Lines->Count;
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::CellrChange(TObject *Sender)
{
Cellrlabel->Caption=Cellr->Lines->Count;        
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::CellbcchChange(TObject *Sender)
{
Cellbcchlabel->Caption=Cellbcch->Lines->Count;
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::CellrbcchChange(TObject *Sender)
{
Cellrbcchlabel->Caption=Cellrbcch->Lines->Count;        
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::Button2Click(TObject *Sender)
{
Form1->Memo1->Clear();
for(int q=0;q<Cell->Lines->Count;q++)
{
Form1->Memo1->Lines->Add("RLNRP:CELL="+Cell->Lines->Strings[q]+",CELLR="+Cellr->Lines->Strings[q]+",NODATA;");
}
Form1->Show();

}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::Button3Click(TObject *Sender)
{
if(CheckBox1->Checked)
{
String SINX="IKI",find1="NOT FOUND",find2="NOT FOUND";

FindMemo1->Clear();
FindMemo2->Clear();
 for (int I = 0; I < FindMemo->Lines->Count; I++)
  {

    if (int Find = FindMemo->Lines->Strings[I].Pos(FindComboBox1->Text))
    {
     if(SINX=="BIR")
     {
        if(CheckBox10->Checked==true)
        FindMemo2->Lines->Add(find2);
        else
        FindMemo2->Lines->Add("NOT FOUND");

        if(FindMemo->Lines->Strings[I+1].SubString(0,8)=="WO      "){
        find1=Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit1->Text)+1].SubString(Find+StrToInt(IntervalEdit1b->Text),StrToInt(IntervalEdit1->Text)));
        FindMemo1->Lines->Add(find1);
        }
        else
        {
        find1=Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit1->Text)].SubString(Find+StrToInt(IntervalEdit1b->Text),StrToInt(IntervalEdit1->Text)));
        FindMemo1->Lines->Add(find1);
        }
     }
     else
        if(FindMemo->Lines->Strings[I+1].SubString(0,8)=="WO      "){
        find1=Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit1->Text)+1].SubString(Find+StrToInt(IntervalEdit1b->Text),StrToInt(IntervalEdit1->Text)));
        FindMemo1->Lines->Add(find1);
        }
        else{
        find1=Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit1->Text)].SubString(Find+StrToInt(IntervalEdit1b->Text),StrToInt(IntervalEdit1->Text)));
        FindMemo1->Lines->Add(find1);
        }
     SINX="BIR";
    }

    if (int Find = FindMemo->Lines->Strings[I].Pos(FindComboBox2->Text))
    {
        if(SINX=="IKI")
        {

                if(CheckBox9->Checked==true)
                FindMemo1->Lines->Add(find1);
                else
                FindMemo1->Lines->Add("NOT FOUND");

                if(FindMemo->Lines->Strings[I+1].SubString(0,8)=="WO      "){
                find2=Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit2->Text)+1].SubString(Find+StrToInt(IntervalEdit2b->Text),StrToInt(IntervalEdit2->Text)));
                FindMemo2->Lines->Add(find2);
                }
                else {
                find2=Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit2->Text)].SubString(Find+StrToInt(IntervalEdit2b->Text),StrToInt(IntervalEdit2->Text)));
                FindMemo2->Lines->Add(find2);
                }
        }
        else
                if(FindMemo->Lines->Strings[I+1].SubString(0,8)=="WO      "){
                find2=Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit2->Text)+1].SubString(Find+StrToInt(IntervalEdit2b->Text),StrToInt(IntervalEdit2->Text)));
                FindMemo2->Lines->Add(find2);
                }
                else {
                find2=Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit2->Text)].SubString(Find+StrToInt(IntervalEdit2b->Text),StrToInt(IntervalEdit2->Text)));
                FindMemo2->Lines->Add(find2);
                }
     SINX="IKI";
    }
  }
  if(SINX=="BIR"){
        if(CheckBox10->Checked==true)
        FindMemo2->Lines->Add(find2);
        else
        FindMemo2->Lines->Add("NOT FOUND");
  }

}

if(CheckBox2->Checked)
{
FindMemo2->Clear();
for (int I = 0; I < FindMemo->Lines->Count; I++)
  {
    if (int Find1 = FindMemo->Lines->Strings[I].Pos("MO       "))
    if (int Find2 = FindMemo->Lines->Strings[I].Pos("RSITE"))
    {
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"0,STATE=HALTED;");
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"1,STATE=HALTED;");
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"2,STATE=HALTED;");
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"3,STATE=HALTED;");
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"4,STATE=HALTED;");
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"6,STATE=HALTED;");
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"7,STATE=HALTED;");
   // FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"8,STATE=HALTED;");

    FindMemo2->Lines->Add("RXMSC:MO="+Trim(FindMemo->Lines->Strings[I+1].SubString(Find1,11))+",SWVER=B4404R014L;");
    FindMemo2->Lines->Add("RXPLI:MO="+Trim(FindMemo->Lines->Strings[I+1].SubString(Find1,11))+";");

    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"0,STATE=ACTIVE;");
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"1,STATE=ACTIVE;");
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"2,STATE=ACTIVE;");
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"3,STATE=ACTIVE;");
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"4,STATE=ACTIVE;");
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"6,STATE=ACTIVE;");
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"7,STATE=ACTIVE;");
    //FindMemo2->Lines->Add("RLSTC:CELL="+FindMemo->Lines->Strings[I+1].SubString(Find2+10,5)+"8,STATE=ACTIVE;");
    FindMemo2->Lines->Add("");
    }
  }

}



if(CheckBox3->Checked)
{
FindMemo2->Clear();
for (int I = 0; I < FindMemo->Lines->Count; I++)
  {
    if (int Find1 = FindMemo->Lines->Strings[I].Pos("MO       "))
    if (int Find2 = FindMemo->Lines->Strings[I].Pos("RSITE"))
    {
    FindMemo2->Lines->Add("RXMSC:MO="+Trim(FindMemo->Lines->Strings[I+1].SubString(Find1,11))+",SWVER=B4404R014L;");
    
    FindMemo2->Lines->Add("");
    }
  }

}

if(CheckBox4->Checked)
{
for(int k=0;k<FindMemo1->Lines->Count;k++)
{
FindMemo2->Lines->Add("rxmop:mo=rxotrx-"+FindMemo1->Lines->Strings[k]+"-0;");
FindMemo2->Lines->Add("rxmop:mo=rxotrx-"+FindMemo1->Lines->Strings[k]+"-1;");
FindMemo2->Lines->Add("rxmop:mo=rxotrx-"+FindMemo1->Lines->Strings[k]+"-2;");
FindMemo2->Lines->Add("rxmop:mo=rxotrx-"+FindMemo1->Lines->Strings[k]+"-3;");
FindMemo2->Lines->Add("rxmop:mo=rxotrx-"+FindMemo1->Lines->Strings[k]+"-4;");
FindMemo2->Lines->Add("rxmop:mo=rxotrx-"+FindMemo1->Lines->Strings[k]+"-5;");
FindMemo2->Lines->Add("rxmop:mo=rxotrx-"+FindMemo1->Lines->Strings[k]+"-6;");
FindMemo2->Lines->Add("rxmop:mo=rxotrx-"+FindMemo1->Lines->Strings[k]+"-7;");
FindMemo2->Lines->Add("rxmop:mo=rxotrx-"+FindMemo1->Lines->Strings[k]+"-8;");
FindMemo2->Lines->Add("rxmop:mo=rxotrx-"+FindMemo1->Lines->Strings[k]+"-9;");
FindMemo2->Lines->Add("rxmop:mo=rxotrx-"+FindMemo1->Lines->Strings[k]+"-10;");
FindMemo2->Lines->Add("rxmop:mo=rxotrx-"+FindMemo1->Lines->Strings[k]+"-11;");
}
}
}
//---------------------------------------------------------------------------




void __fastcall TScriptForm::FindMemo1Change(TObject *Sender)
{
FindLabel1->Caption=FindMemo1->Lines->Count;
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::FindMemo2Change(TObject *Sender)
{
FindLabel2->Caption=FindMemo2->Lines->Count;        
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::Button4Click(TObject *Sender)
{
Form1->Memo1->Clear();

for(int h=0;h<Memo1->Lines->Count;h++)
if(CheckBox8->Checked==false)
{
        if(CheckBox5->Checked==true)
        Form1->Memo1->Lines->Add(Memo1->Lines->Strings[h]);
        if(CheckBox6->Checked==true)
        Form1->Memo1->Lines->Add(Memo2->Lines->Strings[h]);
        if(CheckBox7->Checked==true)
        Form1->Memo1->Lines->Add(Memo3->Lines->Strings[h]);
}
else
Form1->Memo1->Lines->Add(Memo1->Lines->Strings[h]+Memo2->Lines->Strings[h]+Memo3->Lines->Strings[h]);

Form1->Show();
}
//---------------------------------------------------------------------------


void __fastcall TScriptForm::SdipButtonClick(TObject *Sender)
{
if(SdipAllipMemo->Text!="" && SdipTpcopMemo->Text!="")
{
String SDIP="",LAYER="",RBLT="";
SdipProgressBar->Visible=true;
SdipProgressBar->Max=SdipAllipMemo->Lines->Count;

for(int i=0;i<SdipAllipMemo->Lines->Count;i++){
   int k=1;
   if(SdipAllipMemo->Lines->Strings[i+1].SubString(0,8)=="WO      ")
   k=2;

   if (int SDIPALLIP = SdipAllipMemo->Lines->Strings[i].Pos("SDIP     STATE     LAYER"))
   {
   SDIP=Trim(SdipAllipMemo->Lines->Strings[i+k].SubString(SDIPALLIP,7));
   LAYER=Trim(SdipAllipMemo->Lines->Strings[i+k].SubString(SDIPALLIP+19,9));
       for(int j=0;j<SdipTpcopMemo->Lines->Count;j++){
         if (int SDIPTPCOP = SdipTpcopMemo->Lines->Strings[j].Pos("SDIP     SNT"))
         if(SDIP==Trim(SdipTpcopMemo->Lines->Strings[j+k].SubString(SDIPTPCOP,7)))
         {
          for(int o=0;o<=64;o++){
          if (int Layer = SdipTpcopMemo->Lines->Strings[j+o].Pos(LAYER)){
          RBLT=Trim(SdipTpcopMemo->Lines->Strings[j+o].SubString(Layer+18,8));
            if(RBLT!="1  1  1"){
            SdipMemo->Lines->Add("DTBLI:DIP="+RBLT+";");
            SdipMemo->Lines->Add("TPBLI:SDIP="+SDIP+",LP="+LAYER+";");
            }
          goto SON;
          }
          }
         }
       }
   }
   SON:
SdipProgressBar->Position=i;
}
SdipProgressBar->Visible=false;
}
else
ShowMessage("Verilenleri duzgun daxil et!");
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::Button5Click(TObject *Sender)
{
ReportMemo->Clear();

if(CellMemo->Lines->Count!=0) {
        ReportMemo->Lines->Add("@3G NEIGHBOUR RELATIONS");
        ReportMemo->Lines->Add("@2G SIDE");
  for(int i=0;i<CellMemo->Lines->Count;i++){
        RnccellrMemo->Lines->Strings[i]=Trim(RnccellrMemo->Lines->Strings[i]);
         if(RnccellrMemo->Lines->Strings[i]=="1" || RnccellrMemo->Lines->Strings[i]=="RNC1")
        {       Lac->Text="1201";
                Rncid->Text="1201";
        }
        else if(RnccellrMemo->Lines->Strings[i]=="2" || RnccellrMemo->Lines->Strings[i]=="RNC2")
        {       Lac->Text="3200";
                Rncid->Text="3200";
        }
        else if(RnccellrMemo->Lines->Strings[i]=="3" || RnccellrMemo->Lines->Strings[i]=="RNC3")
        {       Lac->Text="3300";
                Rncid->Text="3300";
        }
        else if(RnccellrMemo->Lines->Strings[i]=="4" || RnccellrMemo->Lines->Strings[i]=="RNC4")
        {       Lac->Text="3400";
                Rncid->Text="3400";
        }
        else if(RnccellrMemo->Lines->Strings[i]=="5" || RnccellrMemo->Lines->Strings[i]=="RNC5")
        {       Lac->Text="3500";
                Rncid->Text="3500";
        }
        else if(RnccellrMemo->Lines->Strings[i]=="6" || RnccellrMemo->Lines->Strings[i]=="RNC6")
        {       Lac->Text="3600";
                Rncid->Text="3600";
        }
        else if(RnccellrMemo->Lines->Strings[i]=="7" || RnccellrMemo->Lines->Strings[i]=="RNC7")
        {
                Lac->Text="3700";
                Rncid->Text="3700";
        }
        int k=ReportMemo->Text.Pos("RLDEI:CELL="+CellrMemo->Lines->Strings[i]+",EXT,UTRAN;");
        int m=ReportMemo->Text.Pos("RLDEC:CELL="+CellrMemo->Lines->Strings[i]+",UTRANID=400-01-"+Lac->Text+"-"+CidMemo->Lines->Strings[i]+"-"+Rncid->Text+",FDDARFCN="+UarMemo->Lines->Strings[i]+",SCRCODE="+ScrMemo->Lines->Strings[i]+",MRSL="+Mrsl->Text+";");
        if(!k)
        ReportMemo->Lines->Add("RLDEI:CELL="+CellrMemo->Lines->Strings[i]+",EXT,UTRAN;");
        if(!m)
        ReportMemo->Lines->Add("RLDEC:CELL="+CellrMemo->Lines->Strings[i]+",UTRANID=400-01-"+Lac->Text+"-"+CidMemo->Lines->Strings[i]+"-"+Rncid->Text+",FDDARFCN="+UarMemo->Lines->Strings[i]+",SCRCODE="+ScrMemo->Lines->Strings[i]+",MRSL="+Mrsl->Text+";");
  }

  ReportMemo->Lines->Add("");

  for(int i=0;i<CellMemo->Lines->Count;i++){
        ReportMemo->Lines->Add("RLNRI:CELL="+CellMemo->Lines->Strings[i]+",CELLR="+CellrMemo->Lines->Strings[i]+",SINGLE;");
        ReportMemo->Lines->Add("RLUMC:CELL="+CellMemo->Lines->Strings[i]+",ADD,UMFI="+UarMemo->Lines->Strings[i]+"-"+ScrMemo->Lines->Strings[i]+"-NODIV;");
  }

  ReportMemo->Lines->Add("");

  for(int i=0;i<CellMemo->Lines->Count;i++){
         RnccellrMemo->Lines->Strings[i]=Trim(RnccellrMemo->Lines->Strings[i]);
         if(RnccellrMemo->Lines->Strings[i]=="1" || RnccellrMemo->Lines->Strings[i]=="RNC1")
        {       Lac->Text="1201";
                Rncid->Text="1201";
        }
        else if(RnccellrMemo->Lines->Strings[i]=="2" || RnccellrMemo->Lines->Strings[i]=="RNC2")
        {       Lac->Text="3200";
                Rncid->Text="3200";
        }
        else if(RnccellrMemo->Lines->Strings[i]=="3" || RnccellrMemo->Lines->Strings[i]=="RNC3")
        {       Lac->Text="3300";
                Rncid->Text="3300";
        }
        else if(RnccellrMemo->Lines->Strings[i]=="4" || RnccellrMemo->Lines->Strings[i]=="RNC4")
        {       Lac->Text="3400";
                Rncid->Text="3400";
        }
        else if(RnccellrMemo->Lines->Strings[i]=="5" || RnccellrMemo->Lines->Strings[i]=="RNC5")
        {       Lac->Text="3500";
                Rncid->Text="3500";
        }
        else if(RnccellrMemo->Lines->Strings[i]=="6" || RnccellrMemo->Lines->Strings[i]=="RNC6")
        {       Lac->Text="3600";
                Rncid->Text="3600";
        }
        else if(RnccellrMemo->Lines->Strings[i]=="7" || RnccellrMemo->Lines->Strings[i]=="RNC7")
        {
                Lac->Text="3700";
                Rncid->Text="3700";
        }
        int t=ReportMemo->Text.Pos("MGOCI:CELL="+CellrMemo->Lines->Strings[i]+",CGI=400-01-"+Lac->Text+"-"+CidMemo->Lines->Strings[i]+",MSC={MSC};");
        if(!t)
        ReportMemo->Lines->Add("MGOCI:CELL="+CellrMemo->Lines->Strings[i]+",CGI=400-01-"+Lac->Text+"-"+CidMemo->Lines->Strings[i]+",MSC={MSC};");
  }
  ReportMemo->Lines->Add("");
  ReportMemo->Lines->Add("@3G SIDE");
  TempMemo->Clear();
  for(int i=0;i<CellMemo->Lines->Count;i++){

        int k=ReportMemo->Text.Pos("cre RncFunction=1,ExternalGsmNetwork=1,ExternalGsmCell="+CellMemo->Lines->Strings[i]);
        if(!k){
        String cgi="",lac="",ci="",bcch="",ncc="",bcc="";
                for(int j=0;j<RldepMemo->Lines->Count;j++){
                        if(int m=RldepMemo->Lines->Strings[j].Pos(CellMemo->Lines->Strings[i]+"   400")){
                        cgi=Delimiter(RldepMemo->Lines->Strings[j]," ",2);
                        lac=Delimiter(cgi,"-",3);
                        ci=Delimiter(cgi,"-",4);
                        ncc=Delimiter(RldepMemo->Lines->Strings[j]," ",3).SubString(1,1);
                        bcc=Delimiter(RldepMemo->Lines->Strings[j]," ",3).SubString(2,1);
                        bcch=Delimiter(RldepMemo->Lines->Strings[j]," ",4);

                        ReportMemo->Lines->Add("");
                        ReportMemo->Lines->Add("cre RncFunction=1,ExternalGsmNetwork=1,ExternalGsmCell="+CellMemo->Lines->Strings[i]) ;
                        ReportMemo->Lines->Add(ci);
                        ReportMemo->Lines->Add(ncc);
                        ReportMemo->Lines->Add(bcc);
                        ReportMemo->Lines->Add(bcch);
                        ReportMemo->Lines->Add(lac);
                        ReportMemo->Lines->Add("set ExternalGsmCell="+CellMemo->Lines->Strings[i]+" userLabel "+CellMemo->Lines->Strings[i]);
                        ReportMemo->Lines->Add("Y");
                        TempMemo->Lines->Add("MGOCI:CELL="+CellMemo->Lines->Strings[i]+",MSC={MSC},CGI="+cgi+";");
                        cgi="";
                        lac="";
                        ci="";
                        bcch="";
                        ncc="";
                        bcc="";

                        break;
                        }
                }

        }
        
        ReportMemo->Lines->Add("cre RncFunction=1,UtranCell="+CellrMemo->Lines->Strings[i]+",GsmRelation="+CellMemo->Lines->Strings[i]);
        ReportMemo->Lines->Add("ExternalGsmNetwork=1,ExternalGsmCell="+CellMemo->Lines->Strings[i]);
  }
  ReportMemo->Lines->Add("");
  ReportMemo->Lines->Add(TempMemo->Text);

}
PageControl4->SelectNextPage(true,true);
PageControl4->SelectNextPage(true,true);
PageControl4->SelectNextPage(true,true);
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::Button6Click(TObject *Sender)
{
for(int i=0;i<DublMemo->Lines->Count-1;i++){
        for(int k=i+1;k<DublMemo->Lines->Count;k++){
        if(Trim(DublMemo->Lines->Strings[i])==Trim(DublMemo->Lines->Strings[k]))
        DublMemo->Lines->Delete(k);
        }
}

}
//---------------------------------------------------------------------------


void __fastcall TScriptForm::CNACheckPreference1Click(TObject *Sender)
{
Form5->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::Button7Click(TObject *Sender)
{
ReportMemo->Clear();

if(Memo3g1->Lines->Count!=0) {
  ReportMemo->Lines->Add("@SCRIPT FOR "+ComboBox3g1->Text);
  TempMemo->Clear();
  for(int i=0;i<Memo3g1->Lines->Count;i++){

   int k=Memo3gpool->Text.Pos("UtranCell="+Memo3g2->Lines->Strings[i]);
   int o=ReportMemo->Text.Pos("cre RncFunction=1,IurLink="+ComboBox3g2->Text+",ExternalUtranCell="+Memo3g2->Lines->Strings[i]);
        if(k && !o){ //eger parametrleri elave edilibse ve ya biraz once report edilmeyiblse  cell girilme cripti daxil et
                String cid="",lac="",scr="",uarfcnDl="",uarfcnUl="";
                for(int j=0;j<Memo3gpool->Lines->Count;j++){
                        if(int m=Memo3gpool->Lines->Strings[j].Pos("UtranCell="+Memo3g2->Lines->Strings[i])){
                        cid=Delimiter(Memo3gpool->Lines->Strings[j]," ",3);
                        lac=Delimiter(Memo3gpool->Lines->Strings[j+1]," ",3).SubString(17,4);
                        scr=Delimiter(Memo3gpool->Lines->Strings[j+2]," ",3);
                        uarfcnDl=Delimiter(Memo3gpool->Lines->Strings[j+3]," ",3);
                        uarfcnUl=Delimiter(Memo3gpool->Lines->Strings[j+4]," ",3);

                        ReportMemo->Lines->Add("cre RncFunction=1,IurLink="+ComboBox3g2->Text+",ExternalUtranCell="+Memo3g2->Lines->Strings[i]);
                        ReportMemo->Lines->Add(cid);
                        ReportMemo->Lines->Add(lac);
                        ReportMemo->Lines->Add("1");
                        ReportMemo->Lines->Add(scr);
                        ReportMemo->Lines->Add(uarfcnDl);
                        ReportMemo->Lines->Add(uarfcnUl);
                        ReportMemo->Lines->Add("");
                        int t=TempMemo->Text.Pos("MGOCI:CELL="+Memo3g2->Lines->Strings[i]+",CGI=400-01-"+lac+"-"+cid+",MSC={MSC};");
                        if(!t)
                        TempMemo->Lines->Add("MGOCI:CELL="+Memo3g2->Lines->Strings[i]+",CGI=400-01-"+lac+"-"+cid+",MSC={MSC};");
                        break;
                        }
                }
             }
        ReportMemo->Lines->Add("cre RncFunction=1,UtranCell="+Memo3g1->Lines->Strings[i]+",UtranRelation="+Memo3g2->Lines->Strings[i]);
        ReportMemo->Lines->Add("IurLink="+ComboBox3g2->Text+",ExternalUtranCell="+Memo3g2->Lines->Strings[i]);
        ReportMemo->Lines->Add("");

 }
  ReportMemo->Lines->Add(TempMemo->Text);
  ReportMemo->Lines->Add("");

}

if(Memo3g2->Lines->Count!=0) {
  ReportMemo->Lines->Add("@SCRIPT FOR "+ComboBox3g2->Text);
  TempMemo->Clear();
  for(int i=0;i<Memo3g2->Lines->Count;i++){

   int k=Memo3gpool->Text.Pos("UtranCell="+Memo3g1->Lines->Strings[i]);
   int o=ReportMemo->Text.Pos("cre RncFunction=1,IurLink="+ComboBox3g1->Text+",ExternalUtranCell="+Memo3g1->Lines->Strings[i]);
        if(k && !o){ //eger parametrleri elave edilibse ve ya biraz once report edilmeyiblse  cell girilme cripti daxil et
                String cid="",lac="",scr="",uarfcnDl="",uarfcnUl="";
                for(int j=0;j<Memo3gpool->Lines->Count;j++){
                        if(int m=Memo3gpool->Lines->Strings[j].Pos("UtranCell="+Memo3g1->Lines->Strings[i])){
                        cid=Delimiter(Memo3gpool->Lines->Strings[j]," ",3);
                        lac=Delimiter(Memo3gpool->Lines->Strings[j+1]," ",3).SubString(17,4);
                        scr=Delimiter(Memo3gpool->Lines->Strings[j+2]," ",3);
                        uarfcnDl=Delimiter(Memo3gpool->Lines->Strings[j+3]," ",3);
                        uarfcnUl=Delimiter(Memo3gpool->Lines->Strings[j+4]," ",3);

                        ReportMemo->Lines->Add("cre RncFunction=1,IurLink="+ComboBox3g1->Text+",ExternalUtranCell="+Memo3g1->Lines->Strings[i]);
                        ReportMemo->Lines->Add(cid);
                        ReportMemo->Lines->Add(lac);
                        ReportMemo->Lines->Add("1");
                        ReportMemo->Lines->Add(scr);
                        ReportMemo->Lines->Add(uarfcnDl);
                        ReportMemo->Lines->Add(uarfcnUl);
                        ReportMemo->Lines->Add("");
                        int t=TempMemo->Text.Pos("MGOCI:CELL="+Memo3g2->Lines->Strings[i]+",CGI=400-01-"+lac+"-"+cid+",MSC={MSC};");
                        if(!t)
                        TempMemo->Lines->Add("MGOCI:CELL="+Memo3g1->Lines->Strings[i]+",CGI=400-01-"+lac+"-"+cid+",MSC={MSC};");
                        break;
                        }
                }
             }
        ReportMemo->Lines->Add("cre RncFunction=1,UtranCell="+Memo3g2->Lines->Strings[i]+",UtranRelation="+Memo3g1->Lines->Strings[i]);
        ReportMemo->Lines->Add("IurLink="+ComboBox3g1->Text+",ExternalUtranCell="+Memo3g1->Lines->Strings[i]);
        ReportMemo->Lines->Add("");

 }
  ReportMemo->Lines->Add(TempMemo->Text);
  ReportMemo->Lines->Add("");

}
PageControl4->SelectNextPage(true,true);

}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::Button8Click(TObject *Sender)
{
int count=0;
String end="endendend";
RpMemo1->Lines->Add(end);

for(int i=0;i<RpMemo1->Lines->Count-1;i++){
        if(RpMemo1->Lines->Strings[i]==RpMemo1->Lines->Strings[i+1])
        count=count+1;
        else{
                for(int k=0; k<=count; k++){
                RpMemo2->Lines->Add(count+1);
                }
        count=0;
        }

}

RpMemo1->Lines->Delete(RpMemo1->Lines->Count-1);
}
//---------------------------------------------------------------------------


void __fastcall TScriptForm::Button9Click(TObject *Sender)
{

String connect="";
String time="";


        for(int i=0;i<Memosaein->Lines->Count;i++){
         if(int k=Memosaein->Lines->Strings[i].Pos("*** Connected to")){
             connect=Memosaein->Lines->Strings[i];
         }
          if(int k=Memosaein->Lines->Strings[i].Pos("TIME:")){
             time=Memosaein->Lines->Strings[i];
         }

         if(int k=Memosaein->Lines->Strings[i].Pos("SAE    BLOCK    NI")){
                Memosaeout->Lines->Add(connect);
                Memosaeout->Lines->Add(time);
                while(true){
                 if(int f=Memosaein->Lines->Strings[i+1].Pos("END"))
                 break;
                 else{
                 //Memosaeout->Lines->Add("SAE="+Memosaein->Lines->Strings[i+1]);
                 String say=Delimiter(Memosaein->Lines->Strings[i+1]," ",3);
                        if(say!="")
                        Memosaeout->Lines->Add("SAE="+Delimiter(Memosaein->Lines->Strings[i+1]," ",1)+", BLOCK="+Delimiter(Memosaein->Lines->Strings[i+1]," ",2)+", NEWNI="+Delimiter(Memosaein->Lines->Strings[i+1]," ",3));
                        else
                        Memosaeout->Lines->Add("SAE="+Delimiter(Memosaein->Lines->Strings[i+1]," ",1)+",NEWNI="+Delimiter(Memosaein->Lines->Strings[i+1]," ",2));
                 i=i+1;
                 }
                }

             Memosaeout->Lines->Add("---------------------------------------------------------------");
             Memosaeout->Lines->Add("");
         }



        }
}
//---------------------------------------------------------------------------

void __fastcall TScriptForm::Button10Click(TObject *Sender)
{
ReportMemo->Clear();

if(Memo3gintcell->Lines->Count!=0) {
  for(int i=0;i<Memo3gintcell->Lines->Count;i++){
        ReportMemo->Lines->Add("cre utrancell="+Memo3gintcell->Lines->Strings[i]+",utranrelation="+Memo3gintcellr->Lines->Strings[i]);
        ReportMemo->Lines->Add("utrancell="+Memo3gintcellr->Lines->Strings[i]);
        ReportMemo->Lines->Add("");
  }

  if(CheckBox11->Checked==true){
        ReportMemo->Lines->Add("");
        ReportMemo->Lines->Add("@Another side");
        ReportMemo->Lines->Add("");
        for(int i=0;i<Memo3gintcell->Lines->Count;i++){
                ReportMemo->Lines->Add("cre utrancell="+Memo3gintcellr->Lines->Strings[i]+",utranrelation="+Memo3gintcell->Lines->Strings[i]);
                ReportMemo->Lines->Add("utrancell="+Memo3gintcell->Lines->Strings[i]);
                ReportMemo->Lines->Add("");
        }
  }

  PageControl4->SelectNextPage(true,true);
  PageControl4->SelectNextPage(true,true);
}
}
//---------------------------------------------------------------------------

