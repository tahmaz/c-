//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Script.h"
#include "Progres.h"
#include "TRGSM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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

 if(int Number=Memocna->Lines->Strings[s].Pos("[90]"))
 {
 Tablecna->Insert();
 Tablecna->FieldByName("Number")->AsInteger=90;
 Tablecna->FieldByName("Cell")->AsString=Trim(Memocna->Lines->Strings[k].SubString(Noqta+1,8));
 Tablecna->Post();
 }

 if(int Number=Memocna->Lines->Strings[s].Pos("[59]"))
 if(int BSRXMIN=Memocna->Lines->Strings[s].Pos("from BSRXMIN"))
 {
 Tablecna->Insert();
 Tablecna->FieldByName("Number")->AsInteger=59;
 Tablecna->FieldByName("Cell")->AsString=Trim(Memocna->Lines->Strings[k].SubString(Noqta+1,8));
 Tablecna->FieldByName("Mbcch")->AsString=Trim(Memocna->Lines->Strings[s].SubString(BSRXMIN+14,3));
 Tablecna->Post();
 }

 if(int Number=Memocna->Lines->Strings[s].Pos("[61]"))
 if(int MSRXMIN=Memocna->Lines->Strings[s].Pos("from MSRXMIN"))
 {
 Tablecna->Insert();
 Tablecna->FieldByName("Number")->AsInteger=61;
 Tablecna->FieldByName("Cell")->AsString=Trim(Memocna->Lines->Strings[k].SubString(Noqta+1,8));
 Tablecna->FieldByName("Mbcch")->AsString=Trim(Memocna->Lines->Strings[s].SubString(MSRXMIN+14,3));
 Tablecna->Post();
 }

 if(int Number=Memocna->Lines->Strings[s].Pos("[56]"))
 if(int BSPWR=Memocna->Lines->Strings[s].Pos("from BSPWR"))
 {
 Tablecna->Insert();
 Tablecna->FieldByName("Number")->AsInteger=56;
 Tablecna->FieldByName("Cell")->AsString=Trim(Memocna->Lines->Strings[k].SubString(Noqta+1,8));
 Tablecna->FieldByName("Mbcch")->AsString=Trim(Memocna->Lines->Strings[s].SubString(BSPWR+12,2));
 Tablecna->Post();
 }

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

if(Tablecna->FieldByName("Number")->AsInteger==36)
Memocna->Lines->Add("RLMFE:CELL="+Tablecna->FieldByName("Cell")->AsString+",MBCCHNO="+Tablecna->FieldByName("Mbcch")->AsInteger+",MRNIC;");

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
String SINX="IKI";

FindMemo1->Clear();
FindMemo2->Clear();
 for (int I = 0; I < FindMemo->Lines->Count; I++)
  {

    if (int Find = FindMemo->Lines->Strings[I].Pos(FindComboBox1->Text))
    {
     if(SINX=="BIR")
     {
     FindMemo2->Lines->Add("NOT FOUND");
     if(FindMemo->Lines->Strings[I+1].SubString(0,8)=="WO      ")
     FindMemo1->Lines->Add(Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit1->Text)+1].SubString(Find+StrToInt(IntervalEdit1b->Text),StrToInt(IntervalEdit1->Text))));
     else
     FindMemo1->Lines->Add(Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit1->Text)].SubString(Find+StrToInt(IntervalEdit1b->Text),StrToInt(IntervalEdit1->Text))));
     }
     else
     if(FindMemo->Lines->Strings[I+1].SubString(0,8)=="WO      ")
      FindMemo1->Lines->Add(Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit1->Text)+1].SubString(Find+StrToInt(IntervalEdit1b->Text),StrToInt(IntervalEdit1->Text))));
      else
     FindMemo1->Lines->Add(Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit1->Text)].SubString(Find+StrToInt(IntervalEdit1b->Text),StrToInt(IntervalEdit1->Text))));
    SINX="BIR";
    }

    if (int Find = FindMemo->Lines->Strings[I].Pos(FindComboBox2->Text))
    {
     if(SINX=="IKI")
     {
     FindMemo1->Lines->Add("NOT FOUND");
     if(FindMemo->Lines->Strings[I+1].SubString(0,8)=="WO      ")
     FindMemo2->Lines->Add(Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit2->Text)+1].SubString(Find+StrToInt(IntervalEdit2b->Text),StrToInt(IntervalEdit2->Text))));
     else
     FindMemo2->Lines->Add(Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit2->Text)].SubString(Find+StrToInt(IntervalEdit2b->Text),StrToInt(IntervalEdit2->Text))));
     }
     else
     if(FindMemo->Lines->Strings[I+1].SubString(0,8)=="WO      ")
     FindMemo2->Lines->Add(Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit2->Text)+1].SubString(Find+StrToInt(IntervalEdit2b->Text),StrToInt(IntervalEdit2->Text))));
     else
     FindMemo2->Lines->Add(Trim(FindMemo->Lines->Strings[I+StrToInt(SetrEdit2->Text)].SubString(Find+StrToInt(IntervalEdit2b->Text),StrToInt(IntervalEdit2->Text))));
    SINX="IKI";
    }
  }
  if(SINX=="BIR")
  FindMemo2->Lines->Add("NOT FOUND");

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
{
if(CheckBox5->Checked==true)
Form1->Memo1->Lines->Add(Memo1->Lines->Strings[h]);
if(CheckBox6->Checked==true)
Form1->Memo1->Lines->Add(Memo2->Lines->Strings[h]);
if(CheckBox7->Checked==true)
Form1->Memo1->Lines->Add(Memo3->Lines->Strings[h]);
}
Form1->Show();
}
//---------------------------------------------------------------------------

