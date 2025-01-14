//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "About.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "WinSkinData"
#pragma link "WinSkinForm"
#pragma link "WinSkinData"
#pragma link "WinSkinForm"
#pragma link "WinSkinData"
#pragma link "WinSkinForm"
#pragma link "WinSkinData"
#pragma link "WinSkinForm"
#pragma link "Wwdbgrid"
#pragma link "Wwdbigrd"
#pragma resource "*.dfm"
TForm1 *Form1;

//extern "C" __declspec(dllimport)void IdTelnetReceive(String input);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button1Click(TObject *Sender)
{
logname="";

if(IdTelnet1->Connected())
IdTelnet1->Disconnect();

IdTelnet1->Host=Delimiter(ComboBox1->Text," ",2);
IdTelnet1->Port=StrToInt(Delimiter(ComboBox1->Text," ",3));

IdTelnet1->Connect();

}
//---------------------------------------------------------------------------








void __fastcall TForm1::Button5Click(TObject *Sender)
{
Query5->Close();
Query5->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
Query4->Close();
Query4->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RefreshTimerTimer(TObject *Sender)
{
Query4->Close();
Query4->Open();

Query5->Close();
Query5->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
PageControl2->Visible=false;
PageControl2->Visible=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DBGrid1DrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumn *Column,
      TGridDrawState State)
{

 TCanvas* SGCanvas =DBGrid1->Canvas;
      const bool BoldCol = (DataCol == 0);
       bool selected =State.Contains(gdSelected);

      if(BoldCol){
if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="A1")
    SGCanvas->Brush->Color = RGB(255,0,0);
if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="A2")
   SGCanvas->Brush->Color = RGB(255,200,0) ;
if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="A3")
    SGCanvas->Brush->Color = RGB(255,255,0);
if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="O1")
    SGCanvas->Brush->Color = RGB(200,200,0) ;
if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="O2")
    SGCanvas->Brush->Color = RGB(200,180,0) ;
if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="O3")
    SGCanvas->Brush->Color = RGB(200,150,0) ;}

     // if the cell is selected 
  if (selected) {
    SGCanvas->Brush->Color =clBtnFace;
    SGCanvas->Font->Color =clBlack;

    if(BoldCol){
        if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="A1")
        SGCanvas->Brush->Color = RGB(255,0,0);
        if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="A2")
        SGCanvas->Brush->Color = RGB(255,200,0) ;
        if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="A3")
        SGCanvas->Brush->Color = RGB(255,255,0);
        if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="O1")
        SGCanvas->Brush->Color = RGB(200,200,0) ;
        if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="O2")
        SGCanvas->Brush->Color = RGB(200,180,0) ;
        if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="O3")
        SGCanvas->Brush->Color = RGB(200,150,0) ;}

    SGCanvas->FillRect(Rect);
  }

  DBGrid1->DefaultDrawColumnCell(Rect,DataCol,Column,State);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::DBGrid3DrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumn *Column,
      TGridDrawState State)
{
      TCanvas* SGCanvas =DBGrid3->Canvas;
      const bool BoldCol = (DataCol == 0);
       bool selected =State.Contains(gdSelected);

      if(BoldCol){
if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="A1")
    SGCanvas->Brush->Color = RGB(255,0,0);
if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="A2")
   SGCanvas->Brush->Color = RGB(255,200,0) ;
if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="A3")
    SGCanvas->Brush->Color = RGB(255,255,0);
if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="O1")
    SGCanvas->Brush->Color = RGB(200,200,0) ;
if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="O2")
    SGCanvas->Brush->Color = RGB(200,180,0) ;
if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="O3")
    SGCanvas->Brush->Color = RGB(200,150,0) ;}

     // if the cell is selected 
  if (selected) {
    SGCanvas->Brush->Color =clBtnFace;
    SGCanvas->Font->Color =clBlack;

    if(BoldCol){
        if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="A1")
        SGCanvas->Brush->Color = RGB(255,0,0);
        if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="A2")
        SGCanvas->Brush->Color = RGB(255,200,0) ;
        if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="A3")
        SGCanvas->Brush->Color = RGB(255,255,0);
        if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="O1")
        SGCanvas->Brush->Color = RGB(200,200,0) ;
        if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="O2")
        SGCanvas->Brush->Color = RGB(200,180,0) ;
        if(Column->Field->DataSet->FieldByName("Alarm_class")->AsString=="O3")
        SGCanvas->Brush->Color = RGB(200,150,0) ;}

    SGCanvas->FillRect(Rect);
  }

  DBGrid3->DefaultDrawColumnCell(Rect,DataCol,Column,State);

}
//---------------------------------------------------------------------------




void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
Query4->Close();
Query4->SQL->Strings[1]="where Note like '%%'";
Query4->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
Query4->Close();
Query4->SQL->Strings[1]="where Note like '%RADIO X-CEIVER ADMINISTRATION%'";
Query4->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
Query4->Close();
Query4->SQL->Strings[1]="where Note like '%KESINTI%'";
Query4->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
Query4->Close();
Query4->SQL->Strings[2]="and Note like '%"+Edit1->Text+"%'";
Query4->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
Query4->Close();
Query4->SQL->Strings[1]="where Note like '%EXTERNAL%'";
Query4->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
Button2->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
Query5->Close();
Query5->SQL->Strings[2]="and Note like '%"+Edit2->Text+"%'";
Query5->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
Button6->Click();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
Query5->Close();
Query5->SQL->Strings[1]="where Note like '%%'";
Query5->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton6Click(TObject *Sender)
{
Query5->Close();
Query5->SQL->Strings[1]="where Note like '%RADIO X-CEIVER ADMINISTRATION%'";
Query5->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton7Click(TObject *Sender)
{
Query5->Close();
Query5->SQL->Strings[1]="where Note like '%EXTERNAL%'";
Query5->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton8Click(TObject *Sender)
{
Query5->Close();
Query5->SQL->Strings[1]="where Note like '%KESINTI%'";
Query5->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DBGrid1TitleClick(TColumn *Column)
{
    Query4->DisableControls();
    Query4->Close();
    if (Shiftkey){

    if(Query4->SQL->Strings[3]!="")
    Query4->SQL->Strings[3]=("ORDER BY "+Query4->SQL->Strings[3].SubString(9,Query4->SQL->Strings[3].Length())+","+Column->FieldName+" DESC");
    else
    Query4->SQL->Strings[3]=("ORDER BY " + Column->FieldName);
    }
    else
    Query4->SQL->Strings[3]=("ORDER BY " + Column->FieldName);
    Query4->Open();
    // Restore the title settings, otherwise everything
    // will be blue after a while
   if (!Shiftkey){
    DBGrid1->Columns->Items[0]->Title->Font->Color=clBlack;
    DBGrid1->Columns->Items[1]->Title->Font->Color=clBlack;
    DBGrid1->Columns->Items[2]->Title->Font->Color=clBlack;
    DBGrid1->Columns->Items[3]->Title->Font->Color=clBlack;
    }
    Column->Title->Font->Color= clBlue;
    Query4->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key ==VK_SHIFT)
Shiftkey=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key ==VK_SHIFT)
Shiftkey=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid3TitleClick(TColumn *Column)
{
Query5->DisableControls();
    Query5->Close();
    if (Shiftkey){
    if(Query5->SQL->Strings[3]!="")
    Query5->SQL->Strings[3]=("ORDER BY "+Query5->SQL->Strings[3].SubString(9,Query5->SQL->Strings[3].Length())+","+Column->FieldName+" DESC");
    else
    Query5->SQL->Strings[3]=("ORDER BY " + Column->FieldName);
    }
    else
    Query5->SQL->Strings[3]=("ORDER BY " + Column->FieldName);
    Query5->Open();
    // Restore the title settings, otherwise everything
    // will be blue after a while
    if (!Shiftkey){
    DBGrid3->Columns->Items[0]->Title->Font->Color=clBlack;
    DBGrid3->Columns->Items[1]->Title->Font->Color=clBlack;
    DBGrid3->Columns->Items[2]->Title->Font->Color=clBlack;
    DBGrid3->Columns->Items[3]->Title->Font->Color=clBlack;
    DBGrid3->Columns->Items[4]->Title->Font->Color=clBlack;
    }
    Column->Title->Font->Color= clBlue;
    Query5->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid3KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key ==VK_SHIFT)
Shiftkey=true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid3KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key ==VK_SHIFT)
Shiftkey=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Close1Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::About1Click(TObject *Sender)
{
AboutForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::IdTelnet1DataAvailable(AnsiString Buffer)
{
//IdTelnetReceive(Buffer);
 ///*
Memo3->Lines->Add(Buffer);

//------------------------avtomatik Girisqon---------------------//
if(Girisdc!=true){

    if (int PosReturn =Buffer.Pos("login name:"))
    if(logname!="ok"){
    IdTelnet1->WriteLn(Edit3->Text);
    logname="ok";
    }

    if (int PosReturn = Buffer.Pos("password:"))
    IdTelnet1->WriteLn(Edit4->Text);

    if (int PosReturn = Buffer.Pos("Windows NT Domain:"))
    IdTelnet1->WriteLn("");

    if (int PosReturn = Buffer.Pos("Please choose(1-5):"))
    IdTelnet1->WriteLn("2");

    if (int PosReturn =Buffer.Pos(">"))
    IdTelnet1->WriteLn("mml");


    if (int PosReturn = Buffer.Pos("<"))
    Girisdc=true;
 }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Memo1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(IdTelnet1->Connected()){
        if (Key ==VK_F4)
        IdTelnet1->WriteLn(Memo1->Lines->Strings[Memo1->Perform(EM_LINEFROMCHAR, -1, 0)]);

        if (Key ==VK_ESCAPE)
        IdTelnet1->WriteLn("");

        if (Key ==VK_F5)
        IdTelnet1->WriteLn("");
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::IdTelnet1Disconnected(TObject *Sender)
{
Girisdc=false;       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FilterRbClick(TObject *Sender)
{
if(Query4->Active==true)
Query4->Close();

if(FilterMemo->Lines->Count!=0){
String s;
        for(int k=0;k<FilterMemo->Lines->Count;k++){
        if(k==0)
        s=s+" Problem not like '%"+FilterMemo->Lines->Strings[k]+"%' ";
        else
        s=s+" and Problem not like '%"+FilterMemo->Lines->Strings[k]+"%' ";
        }

Query4->SQL->Strings[1]="where "+s;
//FilterMemo->Lines->Add(" where "+s);
}
else
//FilterMemo->Lines->Add("where Note like '%%'");
Query4->SQL->Strings[1]="where Note like '%%'";

Query4->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
FilterMemo->Lines->Add(DBMemo3->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
Form1->FilterRbClick(FilterRb);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
Form1->Button1Click(Button1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
if(Query1->Active==true)
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Text="select * from version where PROGRAM_NAME='MOSS_CLIENT' and PROGRAM_VERSION='1.2'";
Query1->Open();

 if(Query1->IsEmpty()){
 ShowMessage("Program version is old, please use new version.");
 Form1->Close();
 }
}
//---------------------------------------------------------------------------

