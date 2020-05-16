//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "pies"
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
if(StringGrid1->RowCount!=0)
{
Label1->Caption=StringGrid1->Cells[StrToInt(ComboBox2->ItemIndex)][StringGrid1->RowCount-StrToInt(Edit2->Text)+random(StrToInt(Edit2->Text))];
        if (FileExists("voice\\"+Label1->Caption+".wav")){
        MediaPlayer1->FileName="voice\\"+Label1->Caption+".wav";
        MediaPlayer1->Open();
          if(CheckBox3->Checked==true)
          MediaPlayer1->Play();
        }
        else
        MediaPlayer1->Close();
        if(CheckBox5->Checked==false)
        if (FileExists("Pictures\\"+Label1->Caption+".jpeg"))
        Image1->Picture->LoadFromFile("Pictures\\"+Label1->Caption+".jpeg");
        else
        Image1->Picture=NULL;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
if (FileExists("sozler.txt")){
BufMemo->Lines->LoadFromFile("sozler.txt");
StringGrid1->RowCount=BufMemo->Lines->Count;
BufMemo->Clear();
StringGrid1->Cols[0]->LoadFromFile("sozler.txt");
}
if (FileExists("sozlerter_rus.txt"))
StringGrid1->Cols[1]->LoadFromFile("sozlerter_rus.txt");
if (FileExists("sozlerter_az.txt"))
StringGrid1->Cols[2]->LoadFromFile("sozlerter_az.txt");

Label4->Caption="Sozlerin sayi: "+IntToStr(StringGrid1->RowCount);
Edit2->Text=StringGrid1->RowCount;

if (FileExists("Pictures\\English Language.jpeg"))
Image1->Picture->LoadFromFile("Pictures\\English Language.jpeg");

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
if(CheckBox4->Checked==true)
{
StringGrid1->Cols[0]->SaveToFile("sozler_rus.txt");
StringGrid1->Cols[1]->SaveToFile("sozler_ruster_en.txt");
StringGrid1->Cols[2]->SaveToFile("sozler_ruster_az.txt");
}
else
{
StringGrid1->Cols[0]->SaveToFile("sozler.txt");
StringGrid1->Cols[1]->SaveToFile("sozlerter_rus.txt");
StringGrid1->Cols[2]->SaveToFile("sozlerter_az.txt");
}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
if(CheckBox2->Checked==true){
Pnl1->Visible=true;
Pie1->Angles->StartAngle=90;
Timer1->Enabled=true;
Button1->Click();
}
else
{
Pnl1->Visible=false;
Timer1->Enabled=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
if(CheckBox1->Checked==true)
Label1->Visible=false;
else
Label1->Visible=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Pie1->Angles->StartAngle=Pie1->Angles->StartAngle-360/StrToInt(ComboBox1->Text)/10;
if((Pie1->Angles->StartAngle-90)%360==0)
Button1->Click();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
if(ComboBox1->Text.Length()!=0)
{
Timer1->Interval=StrToInt(ComboBox1->Text)*10;
Pie1->Angles->StartAngle=90;
Timer1->Enabled=true;
}
else
Timer1->Enabled=false;        
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button3Click(TObject *Sender)
{
Form2->RichEdit1->Clear();
BufMemo->Clear();
//------------Comment-------------
String s=StringGrid1->RowCount;
if(CheckBox4->Checked==true)
Form2->RichEdit1->Lines->Add("��������� �����: "+s);
else
Form2->RichEdit1->Lines->Add(s+" - word found.");

//---------Add Buffer---------------------
//for(int i=1;i<StringGrid1->RowCount;i++)
BufMemo->Lines=StringGrid1->Cols[StrToInt(ComboBox2->ItemIndex)];
//-------------process------------
for(int i=0;i<StringGrid1->RowCount;i++){
int k=random(BufMemo->Lines->Count);

   if((i)%2==0)
   Form2->RichEdit1->Lines->Add(BufMemo->Lines->Strings[k]);
   else{
   String a=Form2->RichEdit1->Lines->Strings[Form2->RichEdit1->Lines->Count-1];
   int b;
      if(Form2->RichEdit1->Lines->Strings[Form2->RichEdit1->Lines->Count-1].Length()/6==0)
      b=0;
      else if(Form2->RichEdit1->Lines->Strings[Form2->RichEdit1->Lines->Count-1].Length()/6==1)
      b=1;
      else if(Form2->RichEdit1->Lines->Strings[Form2->RichEdit1->Lines->Count-1].Length()/6==2)
      b=2;
      else if(Form2->RichEdit1->Lines->Strings[Form2->RichEdit1->Lines->Count-1].Length()/6==3)
      b=3;
      else
      b=4;
   Form2->RichEdit1->Lines->Delete(Form2->RichEdit1->Lines->Count);
   Form2->RichEdit1->Lines->Delete(Form2->RichEdit1->Lines->Count-1);
     if(b==0)
     Form2->RichEdit1->Lines->Add(a+"\t\t\t\t\t\t"+BufMemo->Lines->Strings[k]);
     else if(b==1)
     Form2->RichEdit1->Lines->Add(a+"\t\t\t\t\t"+BufMemo->Lines->Strings[k]);
     else if(b==2)
     Form2->RichEdit1->Lines->Add(a+"\t\t\t\t"+BufMemo->Lines->Strings[k]);
     else if(b==3)
     Form2->RichEdit1->Lines->Add(a+"\t\t\t"+BufMemo->Lines->Strings[k]);
     else
     Form2->RichEdit1->Lines->Add(a+"\t"+BufMemo->Lines->Strings[k]);
   }

BufMemo->Lines->Delete(k);
}

Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox4Click(TObject *Sender)
{
if(CheckBox4->Checked==true)
{
//save
 StringGrid1->Cols[0]->SaveToFile("sozler.txt");
 StringGrid1->Cols[1]->SaveToFile("sozlerter_rus.txt");
 StringGrid1->Cols[2]->SaveToFile("sozlerter_az.txt");
//load
 if (FileExists("sozler_rus.txt")){
 BufMemo->Lines->LoadFromFile("sozler_rus.txt");
 StringGrid1->RowCount=BufMemo->Lines->Count;
 BufMemo->Clear();
 StringGrid1->Cols[0]->LoadFromFile("sozler_rus.txt");
 }
 if (FileExists("sozler_ruster_en.txt"))
 StringGrid1->Cols[1]->LoadFromFile("sozler_ruster_en.txt");
 if (FileExists("sozler_ruster_az.txt"))
 StringGrid1->Cols[2]->LoadFromFile("sozler_ruster_az.txt");

 if (FileExists("Pictures\\������� ����.jpeg"))
 Image1->Picture->LoadFromFile("Pictures\\������� ����.jpeg");
}
else
{
//save
 StringGrid1->Cols[0]->SaveToFile("sozler_rus.txt");
 StringGrid1->Cols[1]->SaveToFile("sozler_ruster_en.txt");
 StringGrid1->Cols[2]->SaveToFile("sozler_ruster_az.txt");
//load
 if (FileExists("sozler.txt")) {
 BufMemo->Lines->LoadFromFile("sozler.txt");
 StringGrid1->RowCount=BufMemo->Lines->Count;
 BufMemo->Clear();
 StringGrid1->Cols[0]->LoadFromFile("sozler.txt");
 }
 if (FileExists("sozlerter_rus.txt"))
 StringGrid1->Cols[1]->LoadFromFile("sozlerter_rus.txt");
 if (FileExists("sozlerter_az.txt"))
 StringGrid1->Cols[2]->LoadFromFile("sozlerter_az.txt");

 if (FileExists("Pictures\\English Language.jpeg"))
 Image1->Picture->LoadFromFile("Pictures\\English Language.jpeg");
}
Label4->Caption="Sozlerin sayi: "+IntToStr(StringGrid1->RowCount);
Edit2->Text=StringGrid1->RowCount;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
//Form2->RichEdit1->Clear();

//for(int i=0;i<StringGrid1->RowCount;i++)
Form2->RichEdit1->Lines=StringGrid1->Cols[StrToInt(ComboBox2->ItemIndex)];

Form2->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::AdButtonClick(TObject *Sender)
{
StringGrid1->RowCount=StringGrid1->RowCount+1;
 StringGrid1->Cells[0][StringGrid1->RowCount-1]=Edit1->Text;
 StringGrid1->Cells[1][StringGrid1->RowCount-1]=Edit3->Text;
 StringGrid1->Cells[2][StringGrid1->RowCount-1]=Edit4->Text;
Label4->Caption="Sozlerin sayi: "+IntToStr(StringGrid1->RowCount);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DeleteButtonClick(TObject *Sender)
{
for(int i=StringGrid1->Row;i<StringGrid1->RowCount;i++)
StringGrid1->Rows[i]->Assign(StringGrid1->Rows[i+1]);
StringGrid1->RowCount=StringGrid1->RowCount-1;

Label4->Caption="Sozlerin sayi: "+IntToStr(StringGrid1->RowCount);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpdateButtonClick(TObject *Sender)
{
 StringGrid1->Cells[0][StringGrid1->Row]=Edit1->Text;
 StringGrid1->Cells[1][StringGrid1->Row]=Edit3->Text;
 StringGrid1->Cells[2][StringGrid1->Row]=Edit4->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox5Click(TObject *Sender)
{
if(CheckBox5->Checked==false){
if (FileExists("Pictures\\"+Label1->Caption+".jpeg"))
        Image1->Picture->LoadFromFile("Pictures\\"+Label1->Caption+".jpeg");
        }
else
Image1->Picture=NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1Click(TObject *Sender)
{
        Label1->Caption=StringGrid1->Cells[0][StringGrid1->Row];
        if (FileExists("voice\\"+Label1->Caption+".wav")){
        MediaPlayer1->FileName="voice\\"+Label1->Caption+".wav";
        MediaPlayer1->Open();
          if(CheckBox3->Checked==true)
          MediaPlayer1->Play();
        }
        else
        MediaPlayer1->Close();
        if(CheckBox5->Checked==false)
        if (FileExists("Pictures\\"+Label1->Caption+".jpeg"))
        Image1->Picture->LoadFromFile("Pictures\\"+Label1->Caption+".jpeg");
        else
        Image1->Picture=NULL;
        Edit1->Text=Label1->Caption;
        Edit3->Text=StringGrid1->Cells[1][StringGrid1->Row];
        Edit4->Text=StringGrid1->Cells[2][StringGrid1->Row];
}
//---------------------------------------------------------------------------

