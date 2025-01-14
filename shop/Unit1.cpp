//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Info2.h"
#include "Unit2.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "WinSkinData"
#pragma link "WinSkinForm"
#pragma link "Excel_2K_SRVR"
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
if(ComboBox1->Text!="" && Edit2->Text!="" && Edit3->Text!=""){
float Alis=StrToFloat(Edit2->Text);
float Satis=StrToFloat(Edit3->Text);
if(Alis>=Satis)
ShowMessage("Alish Satishdan boyuk ola bilmez!!!");
else{
String Sql=MallarQuery->SQL->Text;
MallarQuery->Close();
MallarQuery->SQL->Clear();
MallarQuery->SQL->Add("Select * from Mallar where Barcode='"+BarcodemalEdit->Text+"'");
MallarQuery->ExecSQL();
MallarQuery->Open();

        if(MallarQuery->IsEmpty()){
        MallarQuery->Close();
        MallarQuery->SQL->Clear();
        MallarQuery->SQL->Add("INSERT INTO Mallar(Name, Alis_qiymeti, Satis_qiymeti, Barcode) VALUES('"+ComboBox1->Text+"',"+Edit2->Text+","+Edit3->Text+",'"+BarcodemalEdit->Text+"')");
        MallarQuery->ExecSQL();
        MallarQuery->SQL->Clear();
        MallarQuery->SQL->Add(Sql);
        MallarQuery->Open();
        
        //Edit1->Clear();
        Edit2->Clear();
        Edit3->Clear();
        BarcodemalEdit->Clear();

        ComboBox1->Clear();
        MallarQuery->First();
        for(int k=0;k<MallarQuery->RecordCount;k++){
        ComboBox1->Items->Add(MallarQuery->FieldByName("Name")->AsString);
        MallarQuery->Next();
        }
        }
        else{
        ShowMessage("Barkod ferqli olmalidir!(Bu barkoddan artiq bazada var)");
        MallarQuery->SQL->Clear();
        MallarQuery->SQL->Add(Sql);
        MallarQuery->Open();
        }
MallarQuery->Last();
}
}
else
ShowMessage("Verilenleri duzgun daxil et");

Label12->Caption=MallarQuery->RecordCount;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DBGrid1CellClick(TColumn *Column)
{
if(Form4->Query1->Active==true)
Form4->Query1->Close();
Form4->Query1->SQL->Clear();
Form4->Query1->SQL->Add("SELECT * FROM Mallar WHERE NAME='"+MallarQuery->FieldByName("Name")->AsString+"'");
Form4->Query1->Open();

Form4->AdLabel->Caption=MallarQuery->FieldByName("Name")->AsString;
Form4->SayLabel->Caption=Form4->Query1->RecordCount;
Form4->Edit1->Text=Form4->Query1->FieldByName("Alis_qiymeti")->AsString;
Form4->Edit2->Text=Form4->Query1->FieldByName("Satis_qiymeti")->AsString;

AdLabel->Caption=MallarQuery->FieldByName("Name")->AsString;
SayLabel->Caption=Form4->Query1->RecordCount;
SatishLabel->Caption=Form4->Query1->FieldByName("Satis_qiymeti")->AsString;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
if(Edit6->Text!=""){
SatishQuery->Close();
CemAlisQuery->Close();
CemSatisQuery->Close();
SayQuery->Close();
SatishQuery->SQL->Clear();
CemAlisQuery->SQL->Clear();
CemSatisQuery->SQL->Clear();
SayQuery->SQL->Clear();
if(AdRadioButton->Checked==true){
SatishQuery->SQL->Add("Select * from satish where Ad LIKE '%"+Edit6->Text+"%' AND Type LIKE '"+TypeComboBox->Text+"'");
CemAlisQuery->SQL->Add("Select SUM(Alis) from satish where Ad LIKE '%"+Edit6->Text+"%' AND Type LIKE '"+TypeComboBox->Text+"'");
CemSatisQuery->SQL->Add("Select SUM(Satis) from satish where Ad LIKE '%"+Edit6->Text+"%' AND Type LIKE '"+TypeComboBox->Text+"'");
SayQuery->SQL->Add("Select SUM(Say) from satish where Ad LIKE '%"+Edit6->Text+"%' AND Type LIKE '"+TypeComboBox->Text+"'");
}
else if(BarcodeRadioButton->Checked==true){
SatishQuery->SQL->Add("Select * from satish where Barcode LIKE '%"+Edit6->Text+"%' AND Type LIKE '"+TypeComboBox->Text+"'");
CemAlisQuery->SQL->Add("Select SUM(Alis) from satish where Barcode LIKE '%"+Edit6->Text+"%' AND Type LIKE '"+TypeComboBox->Text+"'");
CemSatisQuery->SQL->Add("Select SUM(Satis) from satish where Barcode LIKE '%"+Edit6->Text+"%' AND Type LIKE '"+TypeComboBox->Text+"'");
SayQuery->SQL->Add("Select SUM(Say) from satish where Barcode LIKE '%"+Edit6->Text+"%' AND Type LIKE '"+TypeComboBox->Text+"'");
}
else{
SatishQuery->SQL->Add("Select * from satish where Tarix LIKE '%"+Edit6->Text+"%' AND Type LIKE '"+TypeComboBox->Text+"'");
CemAlisQuery->SQL->Add("Select SUM(Alis) from satish where Tarix LIKE '%"+Edit6->Text+"%' AND Type LIKE '"+TypeComboBox->Text+"'");
CemSatisQuery->SQL->Add("Select SUM(Satis) from satish where Tarix LIKE '%"+Edit6->Text+"%' AND Type LIKE '"+TypeComboBox->Text+"'");
SayQuery->SQL->Add("Select SUM(Say) from satish where Tarix LIKE '%"+Edit6->Text+"%' AND Type LIKE '"+TypeComboBox->Text+"'");
}
SatishQuery->Open();
CemAlisQuery->Open();
CemSatisQuery->Open();
SayQuery->Open();
}
else
{
SatishQuery->Close();
CemAlisQuery->Close();
CemSatisQuery->Close();
SayQuery->Close();
SatishQuery->SQL->Clear();
CemAlisQuery->SQL->Clear();
CemSatisQuery->SQL->Clear();
SayQuery->SQL->Clear();
SatishQuery->SQL->Add("Select * from satish");
CemAlisQuery->SQL->Add("SELECT sum(Alis) FROM satish");
CemSatisQuery->SQL->Add("SELECT sum(Satis) FROM satish");
SayQuery->SQL->Add("SELECT sum(Say) FROM satish");
SayQuery->Open();
SatishQuery->Open();
CemAlisQuery->Open();
CemSatisQuery->Open();
}

Label14->Caption=SatishQuery->RecordCount;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6Change(TObject *Sender)
{
Button5->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DateTimePicker2Change(TObject *Sender)
{
Edit6->Text=FormatDateTime("yymmdd",DateTimePicker2->Date);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
Form2->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
DateTimePicker2->DateTime=Now().CurrentDateTime();

Label12->Caption=MallarQuery->RecordCount;

ComboBox1->Clear();
MallarQuery->First();
for(int k=0;k<MallarQuery->RecordCount;k++){
ComboBox1->Items->Add(MallarQuery->FieldByName("Name")->AsString);
MallarQuery->Next();
}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::DBGrid1TitleClick(TColumn *Column)
{
/*
MallarQuery->DisableControls();
    MallarQuery->Close();
    MallarQuery->SQL->Add("");
    MallarQuery->SQL->Add("");
    MallarQuery->SQL->Strings[2]=("ORDER BY " + Column->FieldName);
    MallarQuery->Open();
    DBGrid1->Columns->Items[0]->Title->Font->Color=clBlack;
    DBGrid1->Columns->Items[1]->Title->Font->Color=clBlack;
    DBGrid1->Columns->Items[2]->Title->Font->Color=clBlack;
    // Restore the title settings, otherwise everything
    // will be blue after a while
    Column->Title->Font->Color= clBlue;
    MallarQuery->EnableControls();     */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid2TitleClick(TColumn *Column)
{
SatishQuery->DisableControls();
    SatishQuery->Close();
    SatishQuery->SQL->Add("");
    SatishQuery->SQL->Add("");
    SatishQuery->SQL->Strings[2]=("ORDER BY " + Column->FieldName);
    SatishQuery->Open();
    DBGrid2->Columns->Items[0]->Title->Font->Color=clBlack;
    DBGrid2->Columns->Items[1]->Title->Font->Color=clBlack;
    DBGrid2->Columns->Items[2]->Title->Font->Color=clBlack;
    DBGrid2->Columns->Items[3]->Title->Font->Color=clBlack;
    DBGrid2->Columns->Items[4]->Title->Font->Color=clBlack;
    DBGrid2->Columns->Items[5]->Title->Font->Color=clBlack;
    DBGrid2->Columns->Items[6]->Title->Font->Color=clBlack;
    // Restore the title settings, otherwise everything
    // will be blue after a while
    Column->Title->Font->Color= clBlue;
    SatishQuery->EnableControls();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MAxtarButtonClick(TObject *Sender)
{
 if(Edit5->Text!=""){
 MallarQuery->Close();
 MallarQuery->SQL->Clear();
 MallarQuery->SQL->Add("Select distinct (NAME) from Mallar where Name LIKE '%"+Edit5->Text+"%'");
 MallarQuery->Open();
 }
 else
 {
 MallarQuery->Close();
 MallarQuery->SQL->Clear();
 MallarQuery->SQL->Add("Select distinct (NAME) from Mallar order by name");
 MallarQuery->Open();
 }
 Label12->Caption=MallarQuery->RecordCount;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BarcodefindEditChange(TObject *Sender)
{
MAxtar2Button->Click();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MAxtar2ButtonClick(TObject *Sender)
{
if(BarcodefindEdit->Text!=""){
 MallarQuery->Close();
 MallarQuery->SQL->Clear();
 MallarQuery->SQL->Add("Select distinct (NAME) from Mallar where Barcode LIKE '%"+BarcodefindEdit->Text+"%'");
 MallarQuery->Open();
 }
 else
 {
 MallarQuery->Close();
 MallarQuery->SQL->Clear();
 MallarQuery->SQL->Add("Select distinct (NAME) from Mallar order by name");
 MallarQuery->Open();
 }
 Label12->Caption=MallarQuery->RecordCount;
}
//---------------------------------------------------------------------------
 void __fastcall TForm1::Edit5Change(TObject *Sender)
{
MAxtarButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TarixRadioButtonClick(TObject *Sender)
{

DateTimePicker2->Visible=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::BarcodeRadioButtonClick(TObject *Sender)
{

DateTimePicker2->Visible=false;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AdRadioButtonClick(TObject *Sender)
{

DateTimePicker2->Visible=false;        
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button7Click(TObject *Sender)
{
String S="DELETE FROM satish WHERE ID='"+SatishQuery->FieldByName("ID")->AsString+"'";
String Sql=SatishQuery->SQL->Text;
SatishQuery->SQL->Clear();
SatishQuery->SQL->Add(S);
SatishQuery->ExecSQL();
SatishQuery->SQL->Clear();
SatishQuery->SQL->Add(Sql);
SatishQuery->Open();

CemAlisQuery->Close();
SayQuery->Close();
CemSatisQuery->Close();
CemAlisQuery->Open();
CemSatisQuery->Open();
SayQuery->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TypeComboBoxChange(TObject *Sender)
{
Button5->Click();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::BarcodefindEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN){
String Sql=MallarQuery->SQL->Text;
MallarQuery->Close();
MallarQuery->SQL->Clear();
MallarQuery->SQL->Add("SELECT * FROM Mallar where Barcode='"+BarcodefindEdit->Text+"'");
MallarQuery->Open();

Form3->AdLabel->Caption=MallarQuery->FieldByName("NAME")->AsString;
Form3->BarkodLabel->Caption=MallarQuery->FieldByName("Barcode")->AsString;
Form3->AlishLabel->Caption=MallarQuery->FieldByName("Alis_qiymeti")->AsString;
Form3->Edit1->Text=MallarQuery->FieldByName("Satis_qiymeti")->AsString;
Form3->IdLabel->Caption=MallarQuery->FieldByName("ID")->AsString;

Form3->ShowModal();

MallarQuery->Close();
MallarQuery->SQL->Clear();
MallarQuery->SQL->Add(Sql);
MallarQuery->Open();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
String Sql=MallarQuery->SQL->Text;
String ad=MallarQuery->FieldByName("NAME")->AsString;
MallarQuery->Close();
MallarQuery->SQL->Clear();
MallarQuery->SQL->Add("SELECT * FROM Mallar where Name='"+ad+"'");
MallarQuery->Open();

Form3->AdLabel->Caption=MallarQuery->FieldByName("NAME")->AsString;
Form3->BarkodLabel->Caption=MallarQuery->FieldByName("Barcode")->AsString;
Form3->AlishLabel->Caption=MallarQuery->FieldByName("Alis_qiymeti")->AsString;
Form3->Edit1->Text=MallarQuery->FieldByName("Satis_qiymeti")->AsString;
Form3->IdLabel->Caption=MallarQuery->FieldByName("ID")->AsString;

Form3->ShowModal();

MallarQuery->Close();
MallarQuery->SQL->Clear();
MallarQuery->SQL->Add(Sql);
MallarQuery->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid1DblClick(TObject *Sender)
{
Form4->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
String Sql=MallarQuery->SQL->Text;
MallarQuery->Close();
MallarQuery->SQL->Clear();
MallarQuery->SQL->Add("SELECT * FROM Mallar");
MallarQuery->Open();
MallarQuery->First();

ExcelWorksheet1->ConnectKind=ExcelApplication1->ConnectKind;
ExcelWorkbook1->ConnectKind=ExcelApplication1->ConnectKind;

ExcelApplication1->Workbooks->Add(EmptyParam,LOCALE_USER_DEFAULT);
ExcelWorkbook1->ConnectTo(ExcelApplication1->ActiveWorkbook);
ExcelWorksheet1->ConnectTo(ExcelApplication1->ActiveSheet);
ExcelApplication1->set_SheetsInNewWorkbook(LOCALE_USER_DEFAULT, 1);

ExcelWorksheet1->Cells->get_Range_(TVariant("A1"), TVariant("D1"))->Font->set_Bold(TVariant(true));

ExcelWorksheet1->Cells->get_Range_(TVariant("A1"), TVariant("A1"))->set_ColumnWidth( Variant(45));
ExcelWorksheet1->Cells->get_Range_(TVariant("B1"), TVariant("B1"))->set_ColumnWidth( Variant(18));
ExcelWorksheet1->Cells->get_Range_(TVariant("C1"), TVariant("D1"))->set_ColumnWidth( Variant(12));

ExcelWorksheet1->Cells->get_Range_(TVariant("B2"), TVariant("B1000"))->set_NumberFormat(TVariant("@"));

ExcelWorksheet1->Cells->set_Item(Variant(1), Variant(1),Variant(WideString("Malin adi")) );
ExcelWorksheet1->Cells->set_Item(Variant(1), Variant(2),Variant(WideString("Barkodu")) );
ExcelWorksheet1->Cells->set_Item(Variant(1), Variant(3),Variant(WideString("Alish qiymeti")) );
ExcelWorksheet1->Cells->set_Item(Variant(1), Variant(4),Variant(WideString("Satish qiymeti")) );

for(int k=0;k<MallarQuery->RecordCount;k++){
ExcelWorksheet1->Cells->set_Item(Variant(k+2), Variant(1),Variant(WideString(MallarQuery->FieldByName("NAME")->AsString)) );
ExcelWorksheet1->Cells->set_Item(Variant(k+2), Variant(2),Variant(WideString(MallarQuery->FieldByName("Barcode")->AsString)) );
ExcelWorksheet1->Cells->set_Item(Variant(k+2), Variant(3),Variant(WideString(MallarQuery->FieldByName("Alis_qiymeti")->AsString)) );
ExcelWorksheet1->Cells->set_Item(Variant(k+2), Variant(4),Variant(WideString(MallarQuery->FieldByName("Satis_qiymeti")->AsString)) );
 MallarQuery->Next();
}

ExcelApplication1->set_Visible(LOCALE_USER_DEFAULT,xlSheetVisible);

MallarQuery->Close();
MallarQuery->SQL->Clear();
MallarQuery->SQL->Add(Sql);
MallarQuery->Open();
}
//---------------------------------------------------------------------------

