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

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
//if(StringGrid2->Cells[0][0]=="")
StringGrid2->RowCount=StringGrid2->RowCount+1;
StringGrid2->Cells[0][StringGrid2->RowCount-1]=Delimiter(NeComboBox->Text," ",1);
StringGrid2->Cells[1][StringGrid2->RowCount-1]=Delimiter(NeComboBox->Text," ",2);;
StringGrid2->Cells[2][StringGrid2->RowCount-1]=Delimiter(NeComboBox->Text," ",3);;
StringGrid2->Cells[3][StringGrid2->RowCount-1]=UserEdit->Text;
StringGrid2->Cells[4][StringGrid2->RowCount-1]=PasswordMaskEdit->Text;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
if(StringGrid2->Cells[0][StringGrid2->Row]!="Node name"){
for(int i=StringGrid2->Row;i<StringGrid2->RowCount;i++)
StringGrid2->Rows[i]->Assign(StringGrid2->Rows[i+1]);
StringGrid2->RowCount=StringGrid2->RowCount-1;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IdTelnetdcDataAvailable(AnsiString Buffer)
{
//IdTelnetReceive(Buffer);
 ///*
Memobufdc->Text=Memobufdc->Text+Buffer;
Memodc->Lines->Add(Buffer);

//------------------------avtomatik Girisqon---------------------//
if(Girisdc!=true){

    if (int PosReturn =Buffer.Pos("login name:"))
    IdTelnetdc->WriteLn(StringGrid2->Cells[3][1]);

    if (int PosReturn = Buffer.Pos("password:"))
    IdTelnetdc->WriteLn(StringGrid2->Cells[4][1]);

    if (int PosReturn = Buffer.Pos("Windows NT Domain:"))
    IdTelnetdc->WriteLn("");

    if (int PosReturn = Buffer.Pos("Please choose(1-5):"))
    IdTelnetdc->WriteLn("2");

    if (int PosReturn =Buffer.Pos(">"))
    IdTelnetdc->WriteLn("mml");


    if (int PosReturn = Buffer.Pos("<"))
    {
    Memobufdc->Clear();
    Girisdc=true;
    Komandadc="NOVBETI";
    }
 }

//--------------------------------------------cavablar---------------------------//
if(Komandadc=="ALLIP;")
if(int buf=Buffer.Pos("<"))
 {
 Query2->SQL->Clear();
 Query2->SQL->Add("DELETE FROM moss_buf");
 Query2->ExecSQL();

 for (int I = 0; I < Memobufdc->Lines->Count; I++)
  {
        int k=1,j=2,b=3,h=4,n=5; //int ALA;
        if(Memobufdc->Lines->Strings[I+1].SubString(0,8)=="WO      ")
        k=2;
        else if(Memobufdc->Lines->Strings[I+2].SubString(0,8)=="WO      ")
        j=3;
        else if(Memobufdc->Lines->Strings[I+3].SubString(0,8)=="WO      ")
        b=4;
        else if(Memobufdc->Lines->Strings[I+4].SubString(0,8)=="WO      ")
        h=5;
        else if(Memobufdc->Lines->Strings[I+5].SubString(0,8)=="WO      ")
        n=6;


        int ALARMA1 = Memobufdc->Lines->Strings[I].Pos("A1/");
        int ALARMA2 = Memobufdc->Lines->Strings[I].Pos("A2/");
        int ALARMA3 = Memobufdc->Lines->Strings[I].Pos("A3/");
        int ALARMO1 = Memobufdc->Lines->Strings[I].Pos("O1/");
        int ALARMO2 = Memobufdc->Lines->Strings[I].Pos("O2/");

    if (ALARMA1 || ALARMA2 || ALARMA3 || ALARMO1 || ALARMO2){
      Query2->SQL->Clear();
      Query2->SQL->Add("INSERT INTO moss_buf(Alarm_code,Alarm_class, NE, NE_Name, Problem, Event_time, Note)");
      Query2->SQL->Add("VALUES('"+Delimiter(Memobufdc->Lines->Strings[I].SubString(0,80)," ",3)+"', '"+Delimiter(Memobufdc->Lines->Strings[I].SubString(0,80)," ",1).SubString(1,2)+"', '"+StringGrid2->Cells[0][1]+"',");
      if(int Rsite = Memobufdc->Lines->Strings[I+h].Pos("RSITE"))
      Query2->SQL->Add("'"+StringGrid2->Cells[0][1]+","+Trim(Memobufdc->Lines->Strings[I+n].SubString(Rsite,16))+"','"+Trim(Memobufdc->Lines->Strings[I+1].SubString(0,80))+"', '"+Delimiter(Memobufdc->Lines->Strings[I].SubString(0,80)," ",4)+" "+Delimiter(Memobufdc->Lines->Strings[I].SubString(0,80)," ",5)+"',");
      else if(int cell = Memobufdc->Lines->Strings[I+j].Pos("CELL       SCTYPE"))
      Query2->SQL->Add("'"+StringGrid2->Cells[0][1]+","+Trim(Memobufdc->Lines->Strings[I+b].SubString(cell,7))+",KESINTI','"+Trim(Memobufdc->Lines->Strings[I+1].SubString(0,80))+"', '"+Delimiter(Memobufdc->Lines->Strings[I].SubString(0,80)," ",4)+" "+Delimiter(Memobufdc->Lines->Strings[I].SubString(0,80)," ",5)+"',");
      else
      Query2->SQL->Add("'"+StringGrid2->Cells[0][1]+"','"+Trim(Memobufdc->Lines->Strings[I+1].SubString(0,80))+"', '"+Delimiter(Memobufdc->Lines->Strings[I].SubString(0,80)," ",4)+" "+Delimiter(Memobufdc->Lines->Strings[I].SubString(0,80)," ",5)+"',");

      Memo2->Clear();
        Memo2->Lines->Add(Memobufdc->Lines->Strings[I].SubString(0,80));
          for(int u=I+1;u<Memobufdc->Lines->Count; u++){
          int ALARM_A1 = Memobufdc->Lines->Strings[u].Pos("A1/");
          int ALARM_A2 = Memobufdc->Lines->Strings[u].Pos("A2/");
          int ALARM_A3 = Memobufdc->Lines->Strings[u].Pos("A3/");
          int ALARM_O1 = Memobufdc->Lines->Strings[u].Pos("O1/");
          int ALARM_O2 = Memobufdc->Lines->Strings[u].Pos("O2/");
          int isare = Memobufdc->Lines->Strings[u].Pos("<");
          if(int isare2 = Memobufdc->Lines->Strings[u].Pos("'"))
          Memobufdc->Lines->Delete(u);

          if(!ALARM_A1 && !ALARM_A2 && !ALARM_A3 && !ALARM_O1 && !ALARM_O2 && !isare){
          Memo2->Lines->Add(Memobufdc->Lines->Strings[u].SubString(ALARMA1,80));
          }
          else break;
          }
      Query2->SQL->Add("'"+Memo2->Text+"')");
      Query2->ExecSQL();
      
      Query2->SQL->Clear();
      Query2->SQL->Add("Select * from moss_buf");
      Query2->ExecSQL();
      Query2->Open();

    }

     if (int RXOTG=Memobufdc->Lines->Strings[I].Pos("<"))
     if(Trim(Memobufdc->Lines->Strings[I].SubString(0,80))=="<")
     {
        Komandadc="NOVBETI";
        ALLIPDC="OK";

        //if(Memokom->Lines->Count==0)
        // {
        Memodc->Clear();

        Query1->SQL->Clear();
        Query1->SQL->Add("insert into moss_arxiv(Alarm_code,Alarm_class,NE,NE_Name,Acknowledger,Event_time,Problem,Note) SELECT Alarm_code,Alarm_class,NE,NE_Name,Acknowledger,Event_time,Problem,Note FROM moss WHERE moss.Alarm_code NOT IN ( SELECT Alarm_code FROM moss_buf ) and moss.NE='"+StringGrid2->Cells[0][1]+"'");
        Query1->ExecSQL();

        Query1->SQL->Clear();
        Query1->SQL->Add("UPDATE moss_arxiv SET Sease_time='"+FormatDateTime("yymmdd hhnn",Now())+"' WHERE Sease_time=''");
        Query1->ExecSQL();

        Query1->SQL->Clear();
        Query1->SQL->Add("delete FROM moss WHERE moss.Alarm_code NOT IN ( SELECT Alarm_code FROM moss_buf ) and moss.NE='"+StringGrid2->Cells[0][1]+"'");
        Query1->ExecSQL();

        Query1->SQL->Clear();
        Query1->SQL->Add("insert into moss SELECT * FROM moss_buf WHERE Alarm_code NOT IN ( SELECT Alarm_code FROM moss ) and NE='"+StringGrid2->Cells[0][1]+"'");
        Query1->ExecSQL();
      /*
        Query1->SQL->Clear();
        Query1->SQL->Add("UPDATE moss SET Yoxla = '0' where NE='"+StringGrid2->Cells[0][1]+"' and Yoxla='1'");
        Query1->ExecSQL();

        Query2->SQL->Clear();
        Query2->SQL->Add("SELECT * from moss_buf");
        Query2->ExecSQL();
        Query2->Open();

     if(!Query2->IsEmpty()){
     Query2->Open();
     Query2->First();
        while(!Query2->Eof){
        Query1->SQL->Clear();
        Query1->SQL->Add("select * from moss where NE='"+Query2->FieldByName("NE")->AsString+"' AND Alarm_code='"+Query2->FieldByName("Alarm_code")->AsString+"'");
        Query1->ExecSQL();
        Query1->Open();
                if(Query1->IsEmpty()){
                Query1->SQL->Clear();
                Query1->SQL->Add("INSERT INTO moss (Alarm_code, Alarm_class, NE, NE_Name, Problem, Event_time, Note, Yoxla)");
                Query1->SQL->Add("VALUES('"+Query2->FieldByName("Alarm_code")->AsString+"', '"+Query2->FieldByName("Alarm_class")->AsString+"',");
                Query1->SQL->Add("'"+Query2->FieldByName("NE")->AsString+"', '"+Query2->FieldByName("NE_Name")->AsString+"', '"+Query2->FieldByName("Problem")->AsString+"',");
                Query1->SQL->Add("'"+Query2->FieldByName("Event_time")->AsString+"', '"+Query2->FieldByName("Note")->AsString+"' , '1')");
                Query1->ExecSQL();
                }
                else {
                Query1->SQL->Clear();
                Query1->SQL->Add("UPDATE moss SET Yoxla = '1' WHERE NE ='"+Query2->FieldByName("NE")->AsString+"' AND Alarm_code='"+Query2->FieldByName("Alarm_code")->AsString+"' ");
                Query1->ExecSQL();
                }
        Query2->Next();
        }
        Query1->SQL->Clear();
        Query1->SQL->Add("SELECT * from moss where NE='"+StringGrid2->Cells[0][1]+"' and Yoxla<>'1'");
        Query1->ExecSQL();
        Query1->Open();

        if(!Query1->IsEmpty()){
                while(!Query1->Eof){
                Query3->SQL->Clear();
                Query3->SQL->Add("INSERT INTO moss_arxiv (Alarm_code, Alarm_class, NE, NE_Name, Problem, Event_time,Sease_time, Note)");
                Query3->SQL->Add("VALUES('"+Query1->FieldByName("Alarm_code")->AsString+"', '"+Query1->FieldByName("Alarm_class")->AsString+"',");
                Query3->SQL->Add("'"+Query1->FieldByName("NE")->AsString+"' ,'"+Query1->FieldByName("NE_Name")->AsString+"', '"+Query1->FieldByName("Problem")->AsString+"',");
                Query3->SQL->Add("'"+Query1->FieldByName("Event_time")->AsString+"','"+FormatDateTime("yymmdd hhnn",Now())+"', '"+Query1->FieldByName("Note")->AsString+"')");
                Query3->ExecSQL();
                Query1->Next();
                }

                Query1->SQL->Clear();
                Query1->SQL->Add("Delete from moss where NE='"+StringGrid2->Cells[0][1]+"' and Yoxla<>'1'");
                Query1->ExecSQL();
        }
     }

        Query1->SQL->Clear();
        Query1->SQL->Add("SELECT * from moss");
        Query1->ExecSQL();
        Query2->SQL->Clear();
        Query2->SQL->Add("SELECT * from moss_buf");
        Query2->ExecSQL();
        Query3->SQL->Clear();
        Query3->SQL->Add("SELECT * from moss_arxiv");
        Query3->ExecSQL();
        Query1->Open();
        Query2->Open();
        Query3->Open();
     */

        String Name=StringGrid2->Cells[0][1];
        String Ip=StringGrid2->Cells[1][1];
        String Port=StringGrid2->Cells[2][1];
        String User=StringGrid2->Cells[3][1];
        String Password=StringGrid2->Cells[4][1];

        for(int i=1;i<StringGrid2->RowCount;i++)
        StringGrid2->Rows[i]->Assign(StringGrid2->Rows[i+1]);

        StringGrid2->Cells[0][StringGrid2->RowCount-1]=Name;
        StringGrid2->Cells[1][StringGrid2->RowCount-1]=Ip;
        StringGrid2->Cells[2][StringGrid2->RowCount-1]=Port;
        StringGrid2->Cells[3][StringGrid2->RowCount-1]=User;
        StringGrid2->Cells[4][StringGrid2->RowCount-1]=Password;


        Stopdc->Click();
        Startdc->Click();
        // }

     goto KOM;
     }
  }
}

KOM:;
//---------------------------------------------Komandalar------------------------------//


if(Girisdc==true && Komandadc=="NOVBETI" && ALLIPDC!="OK" )
{
//Memokom->Clear();
Memobufdc->Clear();
Komandadc="ALLIP;";
IdTelnetdc->WriteLn(Komandadc);
goto son;
}

son:;
   //*/
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StartdcClick(TObject *Sender)
{
 if(StringGrid2->RowCount==1)
 ShowMessage("Nod elave et");
 else if(!IdTelnetdc->Connected())
 {
 String S="";
 for(int i=1;i<StringGrid2->RowCount;i++)
 S=S+" NE<>'"+StringGrid2->Cells[0][i]+"' and";
 S=S.SubString(0,S.Length()-4);
 Query1->SQL->Clear();
 Query1->SQL->Add("delete FROM moss WHERE "+S);
 Query1->ExecSQL();
 
 IdTelnetdc->Host=StringGrid2->Cells[1][1];
 IdTelnetdc->Port=StrToInt(StringGrid2->Cells[2][1]);
 IdTelnetdc->Connect();
 Animate1->Visible=true;
 Timerdc->Enabled=true;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerdcTimer(TObject *Sender)
{
if(checkdc==Memodc->Text){

        String Name=StringGrid2->Cells[0][1];
        String Ip=StringGrid2->Cells[1][1];
        String Port=StringGrid2->Cells[2][1];
        String User=StringGrid2->Cells[3][1];
        String Password=StringGrid2->Cells[4][1];

        Memo1->Lines->Add(Name+" :cannot conntect. Time: "+Now().CurrentTime());

        for(int i=1;i<StringGrid2->RowCount;i++)
        StringGrid2->Rows[i]->Assign(StringGrid2->Rows[i+1]);

        StringGrid2->Cells[0][StringGrid2->RowCount-1]=Name;
        StringGrid2->Cells[1][StringGrid2->RowCount-1]=Ip;
        StringGrid2->Cells[2][StringGrid2->RowCount-1]=Port;
        StringGrid2->Cells[3][StringGrid2->RowCount-1]=User;
        StringGrid2->Cells[4][StringGrid2->RowCount-1]=Password;

Stopdc->Click();
Startdc->Click();
//Memoreportdc->Lines->Add(ListBoxdc->Items->Strings[0]+": Restart proses "+Now().CurrentTime());
}

checkdc=Memodc->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StopdcClick(TObject *Sender)
{
if(IdTelnetdc->Connected()){
IdTelnetdc->Disconnect();
Timerdc->Enabled=false;
}       
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IdTelnetdcDisconnected(TObject *Sender)
{
Girisdc=false;
ALLIPDC="";
Animate1->Visible=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button1Click(TObject *Sender)
{
Query1->SQL->Clear();
Query1->SQL->Add("DELETE FROM moss");
Query1->ExecSQL();

}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
/*
//TStringGrid* StringGrid =
//    static_cast<TStringGrid*>(Sender);
 // assert(StringGrid != NULL);

  TCanvas* SGCanvas =StringGrid1->Canvas;
  SGCanvas->Font = StringGrid1->Font; 

  RECT RText = static_cast<RECT>(Rect); 
  const AnsiString text( 
    StringGrid1->Cells[ACol][ARow]);

  const bool fixed = 
    State.Contains(gdFixed);
  const bool focused = 
    State.Contains(gdFocused); 
  //Reenen's Addition
  const bool BoldCol = (ARow !=0) && (ACol == 3);

  bool selected =
    State.Contains(gdSelected); 
  if (!StringGrid1->Options.Contains(goDrawFocusSelected)) {
    selected = selected && !focused;
  }
  // if the cell is fixed (headers) 
  if (fixed) {
    SGCanvas->Brush->Color = 
      StringGrid1->FixedColor; 
    SGCanvas->Font->Color = clBtnText;
    SGCanvas->FillRect(Rect); 
    Frame3D(SGCanvas, Rect, 
      clBtnHighlight, clBtnShadow, 1);
  } 
  // if the cell is selected
  else if (selected) {
    SGCanvas->Brush->Color =clHighlight;
    SGCanvas->Font->Color =
      clHighlightText;
    SGCanvas->FillRect(Rect);
  }
  // if the cell is normal
  else {
    SGCanvas->Brush->Color = 
      StringGrid1->Color;

    //Reenen's Addition
    if (BoldCol)
      SGCanvas->Font->Style = TFontStyles() << fsBold;
    else
      SGCanvas->Font->Style = TFontStyles();


    SGCanvas->Font->Color =
      StringGrid1->Font->Color;
    SGCanvas->FillRect(Rect);
  }
  // if the cell is focused
  if (focused) {
    DrawFocusRect(
      SGCanvas->Handle, &RText);
  }

  //Reenen's Addition
  const int AllignmentFlag = (ARow!=0)&&(ACol==5) ? DT_RIGHT : DT_LEFT;
  // draw the text
  RText.left += 2; RText.top += 2; RText.right -= 2;
  DrawText(SGCanvas->Handle,
    text.c_str(), text.Length(), &RText,
    AllignmentFlag |DT_VCENTER |DT_SINGLELINE);

 */
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{
StringGrid2->Cells[0][0]="Node name";
StringGrid2->Cells[1][0]="IP";
StringGrid2->Cells[2][0]="Port";
StringGrid2->Cells[3][0]="User";
StringGrid2->Cells[4][0]="Password";

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
Memo1->Clear();
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
PageControl1->Visible=false;
PageControl1->Visible=true;
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
    if(Query4->SQL->Strings[3]!=""){
    //if(Column->Title->Font->Color==clBlue)
    Query4->SQL->Strings[3]=("ORDER BY "+Query4->SQL->Strings[3].SubString(9,Query4->SQL->Strings[3].Length())+","+Column->FieldName+" DESC");
    //else
    //Query4->SQL->Strings[3]=("ORDER BY "+Query4->SQL->Strings[3].SubString(9,Query4->SQL->Strings[3].Length())+","+Column->FieldName);
    }
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

void __fastcall TForm1::ClearTimerTimer(TObject *Sender)
{

if(Query1->IsSequenced()==false)
Stopdc->Click();

Query1->SQL->Clear();
Query1->SQL->Add("DELETE FROM moss");
Query1->ExecSQL();

Startdc->Click();

Memo1->Lines->Add("Refresh "+Now());

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
 if(Query1->Active==true)
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Text="select * from version where PROGRAM_NAME='MOSS_SERVER' and PROGRAM_VERSION='1.2'";
Query1->Open();

 if(Query1->IsEmpty()){
 ShowMessage("Program version is old, please use new version.");
 Form1->Close();
 }
}
//---------------------------------------------------------------------------
