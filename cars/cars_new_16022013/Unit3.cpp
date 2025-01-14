//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
#include "OKCNHLP1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
Form3->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender)
{
	if(Form2->ArchiveSQLQuery->Active)
	Form2->ArchiveSQLQuery->Close();

	Form2->ArchiveSQLQuery->SQL->Clear();
	Form2->ArchiveSQLQuery->SQL->Add("select * from archive order by tarix;");
	Form2->ArchiveSQLQuery->Open();

	if (Form2->ArchiveClientDataSet->Active==true)
	Form2->ArchiveClientDataSet->Close();
	Form2->ArchiveClientDataSet->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button4Click(TObject *Sender)
{
Form2->tesdiq=false;
OKHelpBottomDlg->ShowModal();

if(Form2->tesdiq){
	//silinme
	String id=Form2->ArchiveClientDataSet->FieldByName("id")->AsString;

	if (Form2->TempSQLQuery->Active==true)
	Form2->TempSQLQuery->Close();

	//archive databaseinden sil
	Form2->TempSQLQuery->SQL->Clear();
	Form2->TempSQLQuery->SQL->Add("delete from archive where id='"+id+"'");
	Form2->TempSQLQuery->ExecSQL();

	//archiveelave databaseinden sil
	Form2->TempSQLQuery->SQL->Clear();
	Form2->TempSQLQuery->SQL->Add("delete from archiveelave where idarchive='"+id+"'");
	Form2->TempSQLQuery->ExecSQL();

	Form2->ArchiveSQLQuery->Close();
	Form2->ArchiveSQLQuery->Open();

	if (Form2->ArchiveClientDataSet->Active==true)
	Form2->ArchiveClientDataSet->Close();
	Form2->ArchiveClientDataSet->Open();

}

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{

	String id=Form2->ArchiveClientDataSet->FieldByName("id")->AsString;

	//esas parametrleri load ele
	Form2->MarkaTekComboBox->Text=Form2->ArchiveClientDataSet->FieldByName("marka")->AsString;
	Form2->ModelTekComboBox->Text=Form2->ArchiveClientDataSet->FieldByName("model")->AsString;
	Form2->MuherrikTekComboBox->Text=Form2->ArchiveClientDataSet->FieldByName("muherrik")->AsString;
	Form2->IlTekComboBox->Text=Form2->ArchiveClientDataSet->FieldByName("il")->AsString;
	Form2->BanTekComboBox->Text=Form2->ArchiveClientDataSet->FieldByName("ban")->AsString;
	Form2->OzellikTekMemo->Text=Form2->ArchiveClientDataSet->FieldByName("ozellik")->AsString;
	Form2->QiymetTekEdit->Text=Form2->ArchiveClientDataSet->FieldByName("qiymet")->AsString;
	Form2->DateTimePicker1->Date=StrToDate(Form2->ArchiveClientDataSet->FieldByName("tarix")->AsString);
	Form2->TeklifEdit->Text=Form2->ArchiveClientDataSet->FieldByName("teklifnom")->AsString;
	Form2->MusteriEdit->Text=Form2->ArchiveClientDataSet->FieldByName("musteri")->AsString;
	Form2->QalFaizEdit->Text=Form2->ArchiveClientDataSet->FieldByName("faizp")->AsString;
	Form2->EnFaizEdit->Text=Form2->ArchiveClientDataSet->FieldByName("faizm")->AsString;
	Form2->ElaveFaizEdit->Text=Form2->ArchiveClientDataSet->FieldByName("faizel")->AsString;
	Form2->ElqalfaizEdit->Text=Form2->ArchiveClientDataSet->FieldByName("faizelp")->AsString;
	Form2->ElenfaizEdit->Text=Form2->ArchiveClientDataSet->FieldByName("faizelm")->AsString;

	//Elave cedveli boshaldiriq
	Form2->Button7->Click();

	if (Form2->TempSQLQuery->Active==true)
	Form2->TempSQLQuery->Close();

	//elaveleri load edirik
	Form2->TempSQLQuery->SQL->Clear();
	Form2->TempSQLQuery->SQL->Add("select * from archiveelave where idarchive='"+id+"'");
	Form2->TempSQLQuery->Open();

	Form2->TempSQLQuery->First();
	for(int t=0;t<Form2->TempSQLQuery->RecordCount;t++)
	{

	int count=Form2->ElaveStringGrid->RowCount;
	Form2->ElaveStringGrid->RowCount=count+1;
	Form2->ElaveStringGrid->Cells[0][count-1]=Form2->TempSQLQuery->FieldByName("kod")->AsString;
	Form2->ElaveStringGrid->Cells[1][count-1]=Form2->TempSQLQuery->FieldByName("qrup")->AsString;
	Form2->ElaveStringGrid->Cells[2][count-1]=Form2->TempSQLQuery->FieldByName("altqrup")->AsString;
	Form2->ElaveStringGrid->Cells[3][count-1]=Form2->TempSQLQuery->FieldByName("ad")->AsString;
	Form2->ElaveStringGrid->Cells[6][count-1]=Form2->TempSQLQuery->FieldByName("qiymet")->AsString;

	if(Form2->ElaveStringGrid->Cells[6][count-1]=="")
	Form2->ElaveStringGrid->Cells[6][count-1]="0";

	float qiymet=StrToFloat(Form2->ElaveStringGrid->Cells[6][count-1]);
	float faiz=StrToFloat(Form2->ElaveFaizEdit->Text)/100;
	float netice=qiymet+(qiymet*faiz);
	Form2->ElaveStringGrid->Cells[7][count-1]=FormatFloat("#",netice);

	//qiymeti ve faizli qiymeti yenile
	Form2->CheckBox1Click(Form2->CheckBox1);
	Form2->CheckBox1Click(Form2->CheckBox1);

	Form2->CheckBox2Click(Form2->CheckBox2);
	Form2->CheckBox2Click(Form2->CheckBox2);
	//hesabla
	Form2->ElavecalcButton->Click();

	Form2->TempSQLQuery->Next();
	}

	Form3->Close();



}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button5Click(TObject *Sender)
{
	if(Form2->ArchiveSQLQuery->Active)
	Form2->ArchiveSQLQuery->Close();

	Form2->ArchiveSQLQuery->SQL->Clear();
	Form2->ArchiveSQLQuery->SQL->Add("select * from archive where marka like '%"+Edit1->Text+"%' or tarix like '%"+Edit1->Text+"%' or musteri like '%"+Edit1->Text+"%' order by tarix");
	Form2->ArchiveSQLQuery->Open();

	if (Form2->ArchiveClientDataSet->Active==true)
	Form2->ArchiveClientDataSet->Close();
	Form2->ArchiveClientDataSet->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit1Change(TObject *Sender)
{
if(Edit1->Text.Length()>2)
Button5->Click();
else
Button3->Click();
}
//---------------------------------------------------------------------------

