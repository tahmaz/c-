//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Script_makerUnit.h"
#include "ReadUnit.h"
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
String Mbt(int TG,int Dcp1, int Dcp2, int Dip,bool Etru){
 int Ddcp1=Dcp1;
 int Ddcp2=Dcp2;

 if(Dcp1>285){
 Ddcp1=Dcp1-286;
 Ddcp2=Dcp2-286;}

if(Etru==true)
{
if(Form1->BscEdit->Text=="1" || Form1->BscEdit->Text=="5"){
Form2->Memo1->Lines->Add("RXAPI:MO=RXOTG-"+IntToStr(TG)+",DCP="+IntToStr(Dcp1)+"&&"+IntToStr(Dcp2)+",DEV=RBLT-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+",RES64k;");
Form2->Memo1->Lines->Add("EXDAI:DEV=RBLT-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("BLODE:DEV=RBLT-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("");}
else{
Form2->Memo1->Lines->Add("RXAPI:MO=RXOTG-"+IntToStr(TG)+",DCP="+IntToStr(Dcp1)+"&&"+IntToStr(Dcp2)+",DEV=RBLT2-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+",RES64k;");
Form2->Memo1->Lines->Add("EXDAI:DEV=RBLT2-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("BLODE:DEV=RBLT2-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("");}
goto son;
}


if(Form1->BscEdit->Text=="1" || Form1->BscEdit->Text=="5"){
Form2->Memo1->Lines->Add("RXAPI:MO=RXOTG-"+IntToStr(TG)+",DCP="+IntToStr(Dcp1)+"&&"+IntToStr(Dcp2)+",DEV=RBLT-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("EXDAI:DEV=RBLT-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("BLODE:DEV=RBLT-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("");
}
else{
Form2->Memo1->Lines->Add("RXAPI:MO=RXOTG-"+IntToStr(TG)+",DCP="+IntToStr(Dcp1)+"&&"+IntToStr(Dcp2)+",DEV=RBLT2-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("EXDAI:DEV=RBLT2-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("BLODE:DEV=RBLT2-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("");}

son:
return(0);
}

String Mbtdel(int TG,int Dcp1, int Dcp2, int Dip){
 int Ddcp1=Dcp1;
 int Ddcp2=Dcp2;

 if(Dcp1>285){
 Ddcp1=Dcp1-286;
 Ddcp2=Dcp2-286;}

if(Form1->BscEdit->Text=="1" || Form1->BscEdit->Text=="5"){
Form2->Memo1->Lines->Add("BLODI:DEV=RBLT-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("EXDAE:DEV=RBLT-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("RXAPE:MO=RXOTG-"+IntToStr(TG)+",DCP="+IntToStr(Dcp1)+"&&"+IntToStr(Dcp2)+";");
Form2->Memo1->Lines->Add("");
}
else{
Form2->Memo1->Lines->Add("BLODI:DEV=RBLT2-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("EXDAE:DEV=RBLT2-"+IntToStr(Dip*32+Ddcp1)+"&&-"+IntToStr(Dip*32+Ddcp2)+";");
Form2->Memo1->Lines->Add("RXAPE:MO=RXOTG-"+IntToStr(TG)+",DCP="+IntToStr(Dcp1)+"&&"+IntToStr(Dcp2)+";");
Form2->Memo1->Lines->Add("");}

return(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{

Form2->Memo1->Clear();
Form2->Memo1->Lines->Add("!!!!!!!!!!!!!!!FRIST PRINTOUT!!!!!!!!!!!!!!");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RXTCP:MOTY=RXOTG,CELL="+CellEdit1->Text+";");
if(Sektor2CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RXTCP:MOTY=RXOTG,CELL="+CellEdit2->Text+";");
if(Sektor3CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RXTCP:MOTY=RXOTG,CELL="+CellEdit3->Text+";");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-0;");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-1;");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-2;");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-3;");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-4;");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-5;");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-6;");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-7;");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-8;");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-9;");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-10;");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-11;");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RXAPP:MO=RXOTG-"+TgEdit->Text+";");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("STDEP:DEV=RBLT2-"+IntToStr(StrToInt(Mbit1Edit->Text)*32+1)+"&&-"+IntToStr(StrToInt(Mbit1Edit->Text)*32+31)+";");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RXMDP:MOTY=RXOTS,DEV=RBLT2-"+IntToStr(StrToInt(Mbit1Edit->Text)*32+1)+";");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTG-"+TgEdit->Text+";");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RXMFP:MO=RXOTRX-"+TgEdit->Text+"-"+TruEdit1->Text+";");
if(Sektor2CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RXMFP:MO=RXOTRX-"+TgEdit->Text+"-"+TruEdit2->Text+";");
if(Sektor3CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RXMFP:MO=RXOTRX-"+TgEdit->Text+"-"+TruEdit3->Text+";");

Form2->Memo1->Lines->Add("!!!!!!!!!!!!!!! WORK !!!!!!!!!!!!!!");

Form2->Memo1->Lines->Add("@X");
Form2->Memo1->Lines->Add("@T 5");
Form2->Memo1->Lines->Add("@O");

Form2->Memo1->Lines->Add("RLSTC:CELL="+CellEdit1->Text+",STATE=HALTED;");
if(Sektor2CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLSTC:CELL="+CellEdit2->Text+",STATE=HALTED;");
if(Sektor3CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLSTC:CELL="+CellEdit3->Text+",STATE=HALTED;");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RLBDP:CELL="+CellEdit1->Text+";");
if(Sektor2CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLBDP:CELL="+CellEdit2->Text+";");
if(Sektor3CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLBDP:CELL="+CellEdit3->Text+";");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RLBDC:CELL="+CellEdit1->Text+",NUMREQBPC=8,NUMREQEGPRSBPC="+NumreqEdit1->Text+",NUMREQCS3CS4BPC=0,CHGR=0,TN7BCCH=EGPRS;");
if(Sektor2CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLBDC:CELL="+CellEdit2->Text+",NUMREQBPC=8,NUMREQEGPRSBPC="+NumreqEdit2->Text+",NUMREQCS3CS4BPC=0,CHGR=0,TN7BCCH=EGPRS;");
if(Sektor3CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLBDC:CELL="+CellEdit3->Text+",NUMREQBPC=8,NUMREQEGPRSBPC="+NumreqEdit3->Text+",NUMREQCS3CS4BPC=0,CHGR=0,TN7BCCH=EGPRS;");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RLBDP:CELL="+CellEdit1->Text+";");
if(Sektor2CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLBDP:CELL="+CellEdit2->Text+";");
if(Sektor3CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLBDP:CELL="+CellEdit3->Text+";");

Form2->Memo1->Lines->Add("");
if(Sektor2CheckBox->Checked==true || Sektor3CheckBox->Checked==true)
{
Form2->Memo1->Lines->Add("RXBLI:MO=RXOTG-"+TgEdit->Text+",SUBORD,FORCE;");
Form2->Memo1->Lines->Add("RXESE:MO=RXOTG-"+TgEdit->Text+",SUBORD;");
}
else
{
Form2->Memo1->Lines->Add("RXBLI:MO=RXOTRX-"+TgEdit->Text+"-"+TruEdit1->Text+",SUBORD,FORCE;");
Form2->Memo1->Lines->Add("RXESE:MO=RXOTRX-"+TgEdit->Text+"-"+TruEdit1->Text+",SUBORD;");
}
Form2->Memo1->Lines->Add("@X");
Form2->Memo1->Lines->Add("@T 5");
Form2->Memo1->Lines->Add("@O");

Form2->Memo1->Lines->Add("");

bool mbt1,mbt2;
if(ComboBox1->ItemIndex==0)
mbt1=true;
else
mbt1=false;
if(ComboBox2->ItemIndex==0)
mbt2=true;
else
mbt2=false;

if(Del1CheckBox->Checked==true)
Mbtdel(StrToInt(TgEdit->Text),StrToInt(Dcpdel11Edit->Text),StrToInt(Dcpdel12Edit->Text),StrToInt(Mbit1Edit->Text));
if(Cre1CheckBox->Checked==true)
Mbt(StrToInt(TgEdit->Text),StrToInt(Dcpcre11Edit->Text),StrToInt(Dcpcre12Edit->Text),StrToInt(Mbit1Edit->Text),mbt1);

if(CheckBox1->Checked==true)
{
if(Del2CheckBox->Checked==true)
Mbtdel(StrToInt(TgEdit->Text),StrToInt(Dcpdel21Edit->Text),StrToInt(Dcpdel22Edit->Text),StrToInt(Mbit2Edit->Text));
if(Cre2CheckBox->Checked==true)
Mbt(StrToInt(TgEdit->Text),StrToInt(Dcpcre21Edit->Text),StrToInt(Dcpcre22Edit->Text),StrToInt(Mbit2Edit->Text),mbt2);
}
Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RXAPP:MO=RXOTG-"+TgEdit->Text+";");

Form2->Memo1->Lines->Add("");
if(TruEdit1->Text==0)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-0,DCP1=178,DCP2=179&&186;");
else if (TruEdit1->Text==1)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-1,DCP1=187,DCP2=188&&195;");
else if (TruEdit1->Text==2)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-2,DCP1=196,DCP2=197&&204;");
else if (TruEdit1->Text==3)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-3,DCP1=205,DCP2=206&&213;");
else if (TruEdit1->Text==4)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-4,DCP1=214,DCP2=215&&222;");
else if (TruEdit1->Text==5)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-5,DCP1=223,DCP2=224&&231;");
else if (TruEdit1->Text==6)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-6,DCP1=232,DCP2=233&&240;");
else if (TruEdit1->Text==7)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-7,DCP1=241,DCP2=242&&249;");
else if (TruEdit1->Text==8)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-8,DCP1=250,DCP2=251&&258;");
else if (TruEdit1->Text==9)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-9,DCP1=259,DCP2=260&&267;");
else if (TruEdit1->Text==10)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-10,DCP1=268,DCP2=269&&276;");
else if (TruEdit1->Text==11)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-11,DCP1=277,DCP2=278&&285;");

if(Sektor2CheckBox->Checked==true)
if(TruEdit2->Text==0)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-0,DCP1=178,DCP2=179&&186;");
else if (TruEdit2->Text==1)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-1,DCP1=187,DCP2=188&&195;");
else if (TruEdit2->Text==2)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-2,DCP1=196,DCP2=197&&204;");
else if (TruEdit2->Text==3)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-3,DCP1=205,DCP2=206&&213;");
else if (TruEdit2->Text==4)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-4,DCP1=214,DCP2=215&&222;");
else if (TruEdit2->Text==5)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-5,DCP1=223,DCP2=224&&231;");
else if (TruEdit2->Text==6)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-6,DCP1=232,DCP2=233&&240;");
else if (TruEdit2->Text==7)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-7,DCP1=241,DCP2=242&&249;");
else if (TruEdit2->Text==8)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-8,DCP1=250,DCP2=251&&258;");
else if (TruEdit2->Text==9)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-9,DCP1=259,DCP2=260&&267;");
else if (TruEdit2->Text==10)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-10,DCP1=268,DCP2=269&&276;");
else if (TruEdit2->Text==11)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-11,DCP1=277,DCP2=278&&285;");

if(Sektor3CheckBox->Checked==true)
if(TruEdit3->Text==0)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-0,DCP1=178,DCP2=179&&186;");
else if (TruEdit3->Text==1)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-1,DCP1=187,DCP2=188&&195;");
else if (TruEdit3->Text==2)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-2,DCP1=196,DCP2=197&&204;");
else if (TruEdit3->Text==3)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-3,DCP1=205,DCP2=206&&213;");
else if (TruEdit3->Text==4)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-4,DCP1=214,DCP2=215&&222;");
else if (TruEdit3->Text==5)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-5,DCP1=223,DCP2=224&&231;");
else if (TruEdit3->Text==6)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-6,DCP1=232,DCP2=233&&240;");
else if (TruEdit3->Text==7)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-7,DCP1=241,DCP2=242&&249;");
else if (TruEdit3->Text==8)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-8,DCP1=250,DCP2=251&&258;");
else if (TruEdit3->Text==9)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-9,DCP1=259,DCP2=260&&267;");
else if (TruEdit3->Text==10)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-10,DCP1=268,DCP2=269&&276;");
else if (TruEdit3->Text==11)
Form2->Memo1->Lines->Add("RXMOC:MO=RXOTRX-"+TgEdit->Text+"-11,DCP1=277,DCP2=278&&285;");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-0&&-11;");

Form2->Memo1->Lines->Add("");
if(Sektor2CheckBox->Checked==true || Sektor3CheckBox->Checked==true)
{
Form2->Memo1->Lines->Add("RXESI:MO=RXOTG-"+TgEdit->Text+",SUBORD;");
Form2->Memo1->Lines->Add("RXBLE:MO=RXOTG-"+TgEdit->Text+",SUBORD;");
}
else
{
Form2->Memo1->Lines->Add("RXESI:MO=RXOTRX-"+TgEdit->Text+"-"+TruEdit1->Text+",SUBORD;");
Form2->Memo1->Lines->Add("RXBLE:MO=RXOTRX-"+TgEdit->Text+"-"+TruEdit1->Text+",SUBORD;");
}

Form2->Memo1->Lines->Add("@X");
Form2->Memo1->Lines->Add("@T 30");
Form2->Memo1->Lines->Add("@O");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RXMSP:MO=RXOTG-"+TgEdit->Text+",SUBORD;");

Form2->Memo1->Lines->Add("@X");
Form2->Memo1->Lines->Add("@T 60");
Form2->Memo1->Lines->Add("@O");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RLSTC:CELL="+CellEdit1->Text+",STATE=ACTIVE;");
if(Sektor2CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLSTC:CELL="+CellEdit2->Text+",STATE=ACTIVE;");
if(Sektor3CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLSTC:CELL="+CellEdit3->Text+",STATE=ACTIVE;");

Form2->Memo1->Lines->Add("@X");
Form2->Memo1->Lines->Add("@T 30");
Form2->Memo1->Lines->Add("@O");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RLSLP:CELL="+CellEdit1->Text+";");
if(Sektor2CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLSLP:CELL="+CellEdit2->Text+";");
if(Sektor3CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLSLP:CELL="+CellEdit3->Text+";");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("!!!!!!!!!!!!!!!FINISH CHECK!!!!!!!!!!!!!!");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RXMOP:MO=RXOTRX-"+TgEdit->Text+"-0&&-11;");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RXAPP:MO=RXOTG-"+TgEdit->Text+";");

Form2->Memo1->Lines->Add("");
Form2->Memo1->Lines->Add("RLCRP:CELL="+CellEdit1->Text+";");
if(Sektor2CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLCRP:CELL="+CellEdit2->Text+";");
if(Sektor3CheckBox->Checked==true)
Form2->Memo1->Lines->Add("RLCRP:CELL="+CellEdit3->Text+";");

Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
if(CheckBox1->Checked==true)
Panel2->Visible=true;
else
Panel2->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Del1CheckBoxClick(TObject *Sender)
{
if(Del1CheckBox->Checked==true)
{
Label10->Visible=true;
Dcpdel11Edit->Visible=true;
Dcpdel12Edit->Visible=true;
}
else
{
Label10->Visible=false;
Dcpdel11Edit->Visible=false;
Dcpdel12Edit->Visible=false;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Cre1CheckBoxClick(TObject *Sender)
{
if(Cre1CheckBox->Checked==true)
{
Label8->Visible=true;
ComboBox1->Visible=true;
Dcpcre11Edit->Visible=true;
Dcpcre12Edit->Visible=true;
}
else
{
Label8->Visible=false;
ComboBox1->Visible=false;
Dcpcre11Edit->Visible=false;
Dcpcre12Edit->Visible=false;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Del2CheckBoxClick(TObject *Sender)
{
if(Del2CheckBox->Checked==true)
{
Label13->Visible=true;
Dcpdel21Edit->Visible=true;
Dcpdel22Edit->Visible=true;
}
else
{
Label13->Visible=false;
Dcpdel21Edit->Visible=false;
Dcpdel22Edit->Visible=false;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Cre2CheckBoxClick(TObject *Sender)
{
if(Cre2CheckBox->Checked==true)
{
Label15->Visible=true;
ComboBox2->Visible=true;
Dcpcre21Edit->Visible=true;
Dcpcre22Edit->Visible=true;
}
else
{
Label15->Visible=false;
ComboBox2->Visible=false;
Dcpcre21Edit->Visible=false;
Dcpcre22Edit->Visible=false;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Sektor2CheckBoxClick(TObject *Sender)
{
if(Sektor2CheckBox->Checked==true)
{
CellEdit2->Visible=true;
NumreqEdit2->Visible=true;
TruEdit2->Visible=true;
}
else
{
CellEdit2->Visible=false;
NumreqEdit2->Visible=false;
TruEdit2->Visible=false;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Sektor3CheckBoxClick(TObject *Sender)
{
if(Sektor3CheckBox->Checked==true)
{
CellEdit3->Visible=true;
NumreqEdit3->Visible=true;
TruEdit3->Visible=true;
}
else
{
CellEdit3->Visible=false;
NumreqEdit3->Visible=false;
TruEdit3->Visible=false;
}
}
//---------------------------------------------------------------------------
