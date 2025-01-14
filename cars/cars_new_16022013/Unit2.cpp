﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "OKCNHLP1.h"
#include "Unit3.h"
#include "ABOUT.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RpDefine"
#pragma link "RpRave"
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
if(TempSQLQuery->Active==true)
TempSQLQuery->Close();

//markalari elave et
TempSQLQuery->SQL->Clear();
TempSQLQuery->SQL->Text="select distinct(marka) from esas;";
TempSQLQuery->Open();

TempSQLQuery->First();
MarkaComboBox->Clear();
while(!TempSQLQuery->Eof){
MarkaComboBox->Items->Add(TempSQLQuery->FieldByName("marka")->AsString);
TempSQLQuery->Next();
}
MarkaTekComboBox->Items=MarkaComboBox->Items;
MarkaElaveComboBox->Items=MarkaComboBox->Items;

//kodlar elave et
TempSQLQuery->Close();

TempSQLQuery->SQL->Clear();
TempSQLQuery->SQL->Text="select distinct(kod) from elave;";
TempSQLQuery->Open();

TempSQLQuery->First();
KodElaveComboBox->Clear();
while(!TempSQLQuery->Eof){
KodElaveComboBox->Items->Add(TempSQLQuery->FieldByName("kod")->AsString);
TempSQLQuery->Next();
}

ElaveStringGrid->Cells[0][0]=L"Kod";
ElaveStringGrid->Cells[1][0]=L"Qrup";
ElaveStringGrid->Cells[2][0]=L"Növ";
ElaveStringGrid->Cells[3][0]=L"Ad";
ElaveStringGrid->Cells[6][0]=L"Qiymət";
ElaveStringGrid->Cells[7][0]=L"Qiymət+%";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FileExitItemClick(TObject *Sender)
{
Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::AddButtonClick(TObject *Sender)
{
if(MarkaComboBox->Text!="" && ModelComboBox->Text!="" && MuherrikComboBox->Text!="" && IlComboBox->Text!="" && QiymetEdit->Text!="" && OzellikMemo->Text!=""){
   if(!OzellikMemo->Text.Pos(L"'")){
	if (TempSQLQuery->Active==true)
	TempSQLQuery->Close();


	  //ban nomresini yoxla
	TempSQLQuery->SQL->Clear();
	TempSQLQuery->SQL->Add("select * from esas where ban='"+BanComboBox->Text+"'" );
	TempSQLQuery->Open();

    if(TempSQLQuery->RecordCount==0){
	TempSQLQuery->Close();
	//daxil et
	TempSQLQuery->SQL->Clear();
	TempSQLQuery->SQL->Add("insert into esas (marka,model,muherrik,il,ban,qiymet,ozellik) values ('"+MarkaComboBox->Text+"','"+ModelComboBox->Text+"','"+MuherrikComboBox->Text+"','"+IlComboBox->Text+"','"+BanComboBox->Text+"',"+QiymetEdit->Text+",'"+OzellikMemo->Text+"')");
	TempSQLQuery->ExecSQL();

	//evvelki hisseye qayit
	if (EsasSQLQuery->Active==true)
	EsasSQLQuery->Close();
	EsasSQLQuery->Open();

	//goruntunu yenile
	if (EsasClientDataSet->Active==true)
	EsasClientDataSet->Close();
	EsasClientDataSet->Open();

	//sil elave edilenleri (yeniden girmemek ucun)
	MarkaComboBox->Text="";
	ModelComboBox->Text="";
	MuherrikComboBox->Text="";
	IlComboBox->Text="";
	BanComboBox->Text="";
	QiymetEdit->Text="";
	OzellikMemo->Text="";

	//secmek ucun teklif ve elavede yenile
	if(TempSQLQuery->Active==true)
	TempSQLQuery->Close();

	TempSQLQuery->SQL->Clear();
	TempSQLQuery->SQL->Text="select distinct(marka) from esas;";
	TempSQLQuery->Open();

	TempSQLQuery->First();
	MarkaComboBox->Clear();
	while(!TempSQLQuery->Eof){
	MarkaComboBox->Items->Add(TempSQLQuery->FieldByName("marka")->AsString);
	TempSQLQuery->Next();
	}
	MarkaTekComboBox->Items=MarkaComboBox->Items;
	MarkaElaveComboBox->Items=MarkaComboBox->Items;

	}//ban yoxlamanin sonu
	else
    ShowMessage(L"Bu ban nömrəsi artiq mövcuddur!");
  }
  else
  ShowMessage(L"\' isharesinden istifade etmek olmaz!");
}
else
ShowMessage(L"Bütün xanalar mütləq doldurulmalıdır!");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DBGrid1DblClick(TObject *Sender)
{
  MarkaComboBox->Text=EsasClientDataSet->FieldByName("marka")->AsString;
  ModelComboBox->Text=EsasClientDataSet->FieldByName("model")->AsString;
  MuherrikComboBox->Text=EsasClientDataSet->FieldByName("muherrik")->AsString;
  QiymetEdit->Text=EsasClientDataSet->FieldByName("qiymet")->AsString;
  OzellikMemo->Text=EsasClientDataSet->FieldByName("ozellik")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DeleteButtonClick(TObject *Sender)
{
tesdiq=false;
OKHelpBottomDlg->ShowModal();

if(tesdiq){
	//silinme
	String id=EsasClientDataSet->FieldByName("id")->AsString;

	if (TempSQLQuery->Active==true)
	TempSQLQuery->Close();

	//daxil et
	TempSQLQuery->SQL->Clear();
	TempSQLQuery->SQL->Add("delete from esas where id='"+id+"'");
	TempSQLQuery->ExecSQL();

	//goruntunu yenile
	if (EsasSQLQuery->Active==true)
	EsasSQLQuery->Close();
	EsasSQLQuery->Open();
	if (EsasClientDataSet->Active==true)
	EsasClientDataSet->Close();
	EsasClientDataSet->Open();

	//secmek ucun teklif ve elavede yenile
	if(TempSQLQuery->Active==true)
	TempSQLQuery->Close();

	TempSQLQuery->SQL->Clear();
	TempSQLQuery->SQL->Text="select marka from esas;";
	TempSQLQuery->Open();

	TempSQLQuery->First();
	MarkaComboBox->Clear();
	while(!TempSQLQuery->Eof){
	MarkaComboBox->Items->Add(TempSQLQuery->FieldByName("marka")->AsString);
	TempSQLQuery->Next();
	}
	MarkaTekComboBox->Items=MarkaComboBox->Items;
	MarkaElaveComboBox->Items=MarkaComboBox->Items;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::AddElaveButtonClick(TObject *Sender)
{
if(MarkaElaveComboBox->Text!="" && ModelElaveComboBox->Text!="" && KodElaveComboBox->Text!="" && AdElaveComboBox->Text!="" && QiymetElaveEdit->Text!=""){
   if(!AdElaveComboBox->Text.Pos(L"'")){
	  if (TempSQLQuery->Active==true)
	  TempSQLQuery->Close();

	  //daxil et
	  TempSQLQuery->SQL->Clear();
	  TempSQLQuery->SQL->Add("select * from elave where kod='"+KodElaveComboBox->Text+"'" );
	  TempSQLQuery->Open();

	  if(TempSQLQuery->RecordCount==0){
		TempSQLQuery->Close();

		//daxil et
		TempSQLQuery->SQL->Clear();
		TempSQLQuery->SQL->Add("insert into elave (marka,model,kod,qrup,altqrup,ad,qiymet) values ('"+MarkaElaveComboBox->Text+"','"+ModelElaveComboBox->Text+"','"+KodElaveComboBox->Text+"','"+QrupElaveComboBox->Text+"','"+AltqrupElaveComboBox->Text+"','"+AdElaveComboBox->Text+"',"+QiymetElaveEdit->Text+")");
		TempSQLQuery->ExecSQL();
		//evvelki hisseye qayit
		if (ElaveSQLQuery->Active==true)
		ElaveSQLQuery->Close();
		ElaveSQLQuery->Open();

		//goruntunu yenile
		if (ElaveClientDataSet->Active==true)
		ElaveClientDataSet->Close();
		ElaveClientDataSet->Open();

		//kodlar yenile
		if (TempSQLQuery->Active==true)
		TempSQLQuery->Close();

		TempSQLQuery->SQL->Clear();
		TempSQLQuery->SQL->Text="select distinct(kod) from elave;";
		TempSQLQuery->Open();

		TempSQLQuery->First();
		KodElaveComboBox->Clear();
		while(!TempSQLQuery->Eof){
		KodElaveComboBox->Items->Add(TempSQLQuery->FieldByName("kod")->AsString);
		TempSQLQuery->Next();
		}

		//sil elave dilenleri (yeniden girmemek ucun)
		MarkaElaveComboBox->Text="";
		ModelElaveComboBox->Text="";
		KodElaveComboBox->Text="";
		QrupElaveComboBox->Text="";
		AltqrupElaveComboBox->Text="";
		AdElaveComboBox->Text="";
		QiymetElaveEdit->Text="";
	  }
	  else
      ShowMessage(L"Artıq bu kodda avadanlıq mövcuddur!");
	}
	else
	ShowMessage(L"\' isharesinden istifade etmek olmaz!");
}
else
ShowMessage(L"Bütün xanalar mütləq doldurulmalıdır!");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DeleteElaveButtonClick(TObject *Sender)
{
tesdiq=false;
OKHelpBottomDlg->ShowModal();

if(tesdiq){
	//silinme
	String id=ElaveClientDataSet->FieldByName("id")->AsString;

	if (TempSQLQuery->Active==true)
	TempSQLQuery->Close();

	//daxil et
	TempSQLQuery->SQL->Clear();
	TempSQLQuery->SQL->Add("delete from elave where id='"+id+"'");
	TempSQLQuery->ExecSQL();

	//goruntunu yenile
	if (ElaveSQLQuery->Active==true)
	ElaveSQLQuery->Close();
	ElaveSQLQuery->Open();
	if (ElaveClientDataSet->Active==true)
	ElaveClientDataSet->Close();
	ElaveClientDataSet->Open();
}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::DBGrid2DblClick(TObject *Sender)
{
	MarkaElaveComboBox->Text=ElaveClientDataSet->FieldByName("marka")->AsString;
  ModelElaveComboBox->Text=ElaveClientDataSet->FieldByName("model")->AsString;
  KodElaveComboBox->Text=ElaveClientDataSet->FieldByName("kod")->AsString;
  QrupElaveComboBox->Text=ElaveClientDataSet->FieldByName("qrup")->AsString;
  AltqrupElaveComboBox->Text=ElaveClientDataSet->FieldByName("altqrup")->AsString;
  AdElaveComboBox->Text=ElaveClientDataSet->FieldByName("ad")->AsString;
  QiymetElaveEdit->Text=ElaveClientDataSet->FieldByName("qiymet")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::MarkaComboBoxChange(TObject *Sender)
{

   if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(model),marka from esas where marka='"+MarkaComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   ModelComboBox->Clear();
   while(!TempSQLQuery->Eof){
	ModelComboBox->Items->Add(TempSQLQuery->FieldByName("model")->AsString);
	TempSQLQuery->Next();
   }
   //Grid-i filteri elave et ve yenile
   if (EsasSQLQuery->Active==true)
	EsasSQLQuery->Close();
	EsasSQLQuery->SQL->Text="select * from esas where marka='"+MarkaComboBox->Text+"';";
	EsasSQLQuery->Open();
	if (EsasClientDataSet->Active==true)
	EsasClientDataSet->Close();
	EsasClientDataSet->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm2::ModelComboBoxChange(TObject *Sender)
{
 if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(muherrik),marka,model from esas where marka='"+MarkaComboBox->Text+"' and model='"+ModelComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   MuherrikComboBox->Clear();
   while(!TempSQLQuery->Eof){
	MuherrikComboBox->Items->Add(TempSQLQuery->FieldByName("muherrik")->AsString);
	TempSQLQuery->Next();
   }

	//Grid-i filteri elave et ve yenile
   if (EsasSQLQuery->Active==true)
	EsasSQLQuery->Close();
	EsasSQLQuery->SQL->Text="select * from esas where marka='"+MarkaComboBox->Text+"' and model='"+ModelComboBox->Text+"';";
	EsasSQLQuery->Open();
	if (EsasClientDataSet->Active==true)
	EsasClientDataSet->Close();
	EsasClientDataSet->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::MuherrikComboBoxChange(TObject *Sender)
{
if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(il),muherrik,marka,model from esas where marka='"+MarkaComboBox->Text+"' and model='"+ModelComboBox->Text+"' and muherrik='"+MuherrikComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   IlComboBox->Clear();
   while(!TempSQLQuery->Eof){
	IlComboBox->Items->Add(TempSQLQuery->FieldByName("il")->AsString);
	TempSQLQuery->Next();
   }

	//Grid-i filteri elave et ve yenile
   if (EsasSQLQuery->Active==true)
	EsasSQLQuery->Close();
	EsasSQLQuery->SQL->Text="select * from esas where marka='"+MarkaComboBox->Text+"' and model='"+ModelComboBox->Text+"';";
	EsasSQLQuery->Open();
	if (EsasClientDataSet->Active==true)
	EsasClientDataSet->Close();
	EsasClientDataSet->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::MarkaElaveComboBoxChange(TObject *Sender)
{
if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(model),marka from esas where marka='"+MarkaElaveComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   ModelElaveComboBox->Clear();
   while(!TempSQLQuery->Eof){
	ModelElaveComboBox->Items->Add(TempSQLQuery->FieldByName("model")->AsString);
	TempSQLQuery->Next();
   }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::ModelElaveComboBoxChange(TObject *Sender)
{

if(FilterElaveCheckBox->Checked==true ){

if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(kod),marka,model from elave where marka='"+MarkaElaveComboBox->Text+"' and model='"+ModelElaveComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   KodElaveComboBox->Clear();
   while(!TempSQLQuery->Eof){
	KodElaveComboBox->Items->Add(TempSQLQuery->FieldByName("kod")->AsString);
	TempSQLQuery->Next();
   }

   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(ad),marka,model from elave where marka='"+MarkaElaveComboBox->Text+"' and model='"+ModelElaveComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   AdElaveComboBox->Clear();
   while(!TempSQLQuery->Eof){
	AdElaveComboBox->Items->Add(TempSQLQuery->FieldByName("ad")->AsString);
	TempSQLQuery->Next();
   }

   //qruplari secek
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(qrup),marka,model from elave where marka='"+MarkaElaveComboBox->Text+"' and model='"+ModelElaveComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   QrupElaveComboBox->Clear();
   while(!TempSQLQuery->Eof){
	QrupElaveComboBox->Items->Add(TempSQLQuery->FieldByName("qrup")->AsString);
	TempSQLQuery->Next();
   }
}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::KodElaveComboBoxChange(TObject *Sender)
{
if(FilterElaveCheckBox->Checked==true ){
if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select kod,qrup,altqrup,ad,qiymet from elave where kod='"+KodElaveComboBox->Text+"';";
   TempSQLQuery->Open();

   QrupElaveComboBox->Text=TempSQLQuery->FieldByName("qrup")->AsString;
  AltqrupElaveComboBox->Text=TempSQLQuery->FieldByName("altqrup")->AsString;
  AdElaveComboBox->Text=TempSQLQuery->FieldByName("ad")->AsString;
  QiymetElaveEdit->Text=TempSQLQuery->FieldByName("qiymet")->AsString;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::QrupElaveComboBoxChange(TObject *Sender)
{
if(FilterElaveCheckBox->Checked==true ){
   if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(altqrup),marka,model,qrup from elave where marka='"+MarkaElaveComboBox->Text+"' and model='"+ModelElaveComboBox->Text+"' and qrup='"+QrupElaveComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   AltqrupElaveComboBox->Clear();
   while(!TempSQLQuery->Eof){
	AltqrupElaveComboBox->Items->Add(TempSQLQuery->FieldByName("altqrup")->AsString);
	TempSQLQuery->Next();
   }
}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::AltqrupElaveComboBoxChange(TObject *Sender)
{

if(FilterElaveCheckBox->Checked==true ){
   if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(ad),marka,model,qrup,altqrup from elave where marka='"+MarkaElaveComboBox->Text+"' and model='"+ModelElaveComboBox->Text+"' and qrup='"+QrupElaveComboBox->Text+"' and altqrup='"+AltqrupElaveComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   AdElaveComboBox->Clear();
   while(!TempSQLQuery->Eof){
	AdElaveComboBox->Items->Add(TempSQLQuery->FieldByName("ad")->AsString);
	TempSQLQuery->Next();
   }
}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::AdElaveComboBoxChange(TObject *Sender)
{
/*
  if(FilterElaveCheckBox->Checked==true ){
   if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(qiymet),marka,model,kod,qrup,altqrup,ad from elave where marka='"+MarkaElaveComboBox->Text+"' and model='"+ModelElaveComboBox->Text+"' and qrup='"+QrupElaveComboBox->Text+"' and altqrup='"+AltqrupElaveComboBox->Text+"' and ad='"+AdElaveComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   QiymetElaveEdit->Text=TempSQLQuery->FieldByName("qiymet")->AsString;
   KodElaveComboBox->Text=TempSQLQuery->FieldByName("kod")->AsString;
}   */

}
//---------------------------------------------------------------------------


void __fastcall TForm2::CheckBox3Click(TObject *Sender)
{

if(CheckBox3->Checked)
GroupBox7->Visible=true;
else
GroupBox7->Visible=false;

}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button4Click(TObject *Sender)
{
 if (EsasSQLQuery->Active==true)
	EsasSQLQuery->Close();
	EsasSQLQuery->SQL->Text="select * from esas;";
	EsasSQLQuery->Open();

	if (EsasClientDataSet->Active==true)
	EsasClientDataSet->Close();
	EsasClientDataSet->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::BanComboBoxChange(TObject *Sender)
{
	if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select * from esas where marka='"+MarkaComboBox->Text+"' and model='"+ModelComboBox->Text+"' and muherrik='"+MuherrikComboBox->Text+"' and il='"+IlComboBox->Text+"' and ban='"+BanComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   QiymetEdit->Text=TempSQLQuery->FieldByName("qiymet")->AsString;
   OzellikMemo->Text=TempSQLQuery->FieldByName("ozellik")->AsString;


	//Grid-i filteri elave et ve yenile
   if (EsasSQLQuery->Active==true)
	EsasSQLQuery->Close();
	EsasSQLQuery->SQL->Text="select * from esas where marka='"+MarkaComboBox->Text+"' and model='"+ModelComboBox->Text+"' and muherrik='"+MuherrikComboBox->Text+"' and il='"+IlComboBox->Text+"' and ban='"+BanComboBox->Text+"';";
	EsasSQLQuery->Open();
	if (EsasClientDataSet->Active==true)
	EsasClientDataSet->Close();
	EsasClientDataSet->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::IlComboBoxChange(TObject *Sender)
{
/*  //Ban olan hal ucun
	if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(ban),il,muherrik,marka,model from esas where marka='"+MarkaComboBox->Text+"' and model='"+ModelComboBox->Text+"' and muherrik='"+MuherrikComboBox->Text+"' and il='"+IlComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   BanComboBox->Clear();
   while(!TempSQLQuery->Eof){
	BanComboBox->Items->Add(TempSQLQuery->FieldByName("ban")->AsString);
	TempSQLQuery->Next();
   }

	//Grid-i filteri elave et ve yenile
   if (EsasSQLQuery->Active==true)
	EsasSQLQuery->Close();
	EsasSQLQuery->SQL->Text="select * from esas where marka='"+MarkaComboBox->Text+"' and model='"+ModelComboBox->Text+"';";
	EsasSQLQuery->Open();
	if (EsasClientDataSet->Active==true)
	EsasClientDataSet->Close();
	EsasClientDataSet->Open();       */

   if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select * from esas where marka='"+MarkaComboBox->Text+"' and model='"+ModelComboBox->Text+"' and muherrik='"+MuherrikComboBox->Text+"' and il='"+IlComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   QiymetEdit->Text=TempSQLQuery->FieldByName("qiymet")->AsString;
   OzellikMemo->Text=TempSQLQuery->FieldByName("ozellik")->AsString;


	//Grid-i filteri elave et ve yenile
   if (EsasSQLQuery->Active==true)
	EsasSQLQuery->Close();
	EsasSQLQuery->SQL->Text="select * from esas where marka='"+MarkaComboBox->Text+"' and model='"+ModelComboBox->Text+"' and muherrik='"+MuherrikComboBox->Text+"' and il='"+IlComboBox->Text+"';";
	EsasSQLQuery->Open();
	if (EsasClientDataSet->Active==true)
	EsasClientDataSet->Close();
	EsasClientDataSet->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::MarkaTekComboBoxChange(TObject *Sender)
{
 if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(model),marka from esas where marka='"+MarkaTekComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   ModelTekComboBox->Clear();
   while(!TempSQLQuery->Eof){
	ModelTekComboBox->Items->Add(TempSQLQuery->FieldByName("model")->AsString);
	TempSQLQuery->Next();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ModelTekComboBoxChange(TObject *Sender)
{
	 if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(muherrik),marka,model from esas where marka='"+MarkaTekComboBox->Text+"' and model='"+ModelTekComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   MuherrikTekComboBox->Clear();
   while(!TempSQLQuery->Eof){
	MuherrikTekComboBox->Items->Add(TempSQLQuery->FieldByName("muherrik")->AsString);
	TempSQLQuery->Next();
   }

	// kodlari secek
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(kod),marka,model from elave where marka='"+MarkaTekComboBox->Text+"' and model='"+ModelTekComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   KodTekComboBox->Clear();
   while(!TempSQLQuery->Eof){
	KodTekComboBox->Items->Add(TempSQLQuery->FieldByName("kod")->AsString);
	TempSQLQuery->Next();
   }

   //qruplari secek
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(qrup),marka,model from elave where marka='"+MarkaTekComboBox->Text+"' and model='"+ModelTekComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   QrupTekComboBox->Clear();
   while(!TempSQLQuery->Eof){
	QrupTekComboBox->Items->Add(TempSQLQuery->FieldByName("qrup")->AsString);
	TempSQLQuery->Next();
   }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::MuherrikTekComboBoxChange(TObject *Sender)
{
	 if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(il),muherrik,marka,model from esas where marka='"+MarkaTekComboBox->Text+"' and model='"+ModelTekComboBox->Text+"' and muherrik='"+MuherrikTekComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   IlTekComboBox->Clear();
   while(!TempSQLQuery->Eof){
	IlTekComboBox->Items->Add(TempSQLQuery->FieldByName("il")->AsString);
	TempSQLQuery->Next();
   }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::BanTekComboBoxChange(TObject *Sender)
{
/*if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select * from esas where marka='"+MarkaTekComboBox->Text+"' and model='"+ModelTekComboBox->Text+"' and muherrik='"+MuherrikTekComboBox->Text+"' and il='"+IlTekComboBox->Text+"' and ban='"+BanTekComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   QiymetTekEdit->Text=TempSQLQuery->FieldByName("qiymet")->AsString;
   OzellikTekMemo->Text=TempSQLQuery->FieldByName("ozellik")->AsString;

   EsascalcButton->Click();    */
}
//---------------------------------------------------------------------------

void __fastcall TForm2::IlTekComboBoxChange(TObject *Sender)
{
/*  //Ban ardicilliga elave edildiyinde
	if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(ban),il,muherrik,marka,model from esas where marka='"+MarkaTekComboBox->Text+"' and model='"+ModelTekComboBox->Text+"' and muherrik='"+MuherrikTekComboBox->Text+"' and il='"+IlTekComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   BanTekComboBox->Clear();
   while(!TempSQLQuery->Eof){
	BanTekComboBox->Items->Add(TempSQLQuery->FieldByName("ban")->AsString);
	TempSQLQuery->Next();
   }     */

   if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select * from esas where marka='"+MarkaTekComboBox->Text+"' and model='"+ModelTekComboBox->Text+"' and muherrik='"+MuherrikTekComboBox->Text+"' and il='"+IlTekComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   QiymetTekEdit->Text=TempSQLQuery->FieldByName("qiymet")->AsString;
   OzellikTekMemo->Text=TempSQLQuery->FieldByName("ozellik")->AsString;

   EsascalcButton->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::KodTekComboBoxChange(TObject *Sender)
{
   if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select kod,qrup,altqrup,ad,qiymet from elave where kod='"+KodTekComboBox->Text+"';";
   TempSQLQuery->Open();

   QrupTekComboBox->Text=TempSQLQuery->FieldByName("qrup")->AsString;
  AltqrupTekComboBox->Text=TempSQLQuery->FieldByName("altqrup")->AsString;
  AdTekComboBox->Text=TempSQLQuery->FieldByName("ad")->AsString;
  QiymetTekElaveEdit->Text=TempSQLQuery->FieldByName("qiymet")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::QrupTekComboBoxChange(TObject *Sender)
{
	if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(altqrup),marka,model,qrup from elave where marka='"+MarkaTekComboBox->Text+"' and model='"+ModelTekComboBox->Text+"' and qrup='"+QrupTekComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   AltqrupTekComboBox->Clear();
   while(!TempSQLQuery->Eof){
	AltqrupTekComboBox->Items->Add(TempSQLQuery->FieldByName("altqrup")->AsString);
	TempSQLQuery->Next();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::AltqrupTekComboBoxChange(TObject *Sender)
{
if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(ad),marka,model,qrup,altqrup from elave where marka='"+MarkaTekComboBox->Text+"' and model='"+ModelTekComboBox->Text+"' and qrup='"+QrupTekComboBox->Text+"' and altqrup='"+AltqrupTekComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   AdTekComboBox->Clear();
   while(!TempSQLQuery->Eof){
	AdTekComboBox->Items->Add(TempSQLQuery->FieldByName("ad")->AsString);
	TempSQLQuery->Next();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::AdTekComboBoxChange(TObject *Sender)
{
   if(TempSQLQuery->Active==true)
   TempSQLQuery->Close();

   TempSQLQuery->SQL->Clear();
   TempSQLQuery->SQL->Text="select distinct(qiymet),marka,model,kod,qrup,altqrup,ad from elave where marka='"+MarkaTekComboBox->Text+"' and model='"+ModelTekComboBox->Text+"' and qrup='"+QrupTekComboBox->Text+"' and altqrup='"+AltqrupTekComboBox->Text+"' and ad='"+AdTekComboBox->Text+"';";
   TempSQLQuery->Open();

   TempSQLQuery->First();
   QiymetTekElaveEdit->Text=TempSQLQuery->FieldByName("qiymet")->AsString;
   KodTekComboBox->Text=TempSQLQuery->FieldByName("kod")->AsString;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
if(KodTekComboBox->Text!="" && AdTekComboBox->Text!="" && QiymetTekElaveEdit->Text!="")
{

	bool varmi=false;
	for(int i=0;i<ElaveStringGrid->RowCount;i++)
		if(ElaveStringGrid->Cells[0][i]==KodTekComboBox->Text)
		varmi=true;

	if(!varmi){
	int count=ElaveStringGrid->RowCount;
	ElaveStringGrid->RowCount=count+1;
	ElaveStringGrid->Cells[0][count-1]=KodTekComboBox->Text;
	ElaveStringGrid->Cells[1][count-1]=QrupTekComboBox->Text;
	ElaveStringGrid->Cells[2][count-1]=AltqrupTekComboBox->Text;
	ElaveStringGrid->Cells[3][count-1]=AdTekComboBox->Text;
	ElaveStringGrid->Cells[6][count-1]=QiymetTekElaveEdit->Text;

	float qiymet=StrToFloat(QiymetTekElaveEdit->Text);
	float faiz=StrToFloat(ElaveFaizEdit->Text)/100;
	float netice=qiymet+(qiymet*faiz);
	ElaveStringGrid->Cells[7][count-1]=FormatFloat("#",netice);

	//qiymeti ve faizli qiymeti yenile
	Form2->CheckBox1Click(CheckBox1);
	Form2->CheckBox1Click(CheckBox1);

	Form2->CheckBox2Click(CheckBox2);
	Form2->CheckBox2Click(CheckBox2);
	//hesabla
	ElavecalcButton->Click();

	}
	else
	ShowMessage(L"Artiq bu özəllik seçilmişdir!");
}
else
ShowMessage(L"Parametrlər düzgün seçilmmişdir!");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
tesdiq=false;
OKHelpBottomDlg->ShowModal();

if(tesdiq)
	if(ElaveStringGrid->RowCount>2){
	int  curr=ElaveStringGrid->Row;
		for(int i=0;i<8;i++){   //8 ElaveStringGrid->ColCount deyeridir
		ElaveStringGrid->Cols[i]->Exchange(curr,ElaveStringGrid->RowCount-1);
		ElaveStringGrid->Cols[i]->Exchange(ElaveStringGrid->RowCount-2,curr);
		ElaveStringGrid->Cells[i][ElaveStringGrid->RowCount-1]="";
		}

	ElaveStringGrid->RowCount=ElaveStringGrid->RowCount-1;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::EsascalcButtonClick(TObject *Sender)
{
QiymetLabel->Caption=QiymetTekEdit->Text;

if(QiymetLabel->Caption!=""){
   float qiymet=StrToFloat(QiymetLabel->Caption);
   float qalfaiz=StrToFloat(QalFaizEdit->Text);
   float qalqiymet,enqiymet;
   float enfaiz=StrToFloat(EnFaizEdit->Text);

   qalqiymet=qiymet+(qiymet*qalfaiz/100);
   enqiymet=qalqiymet-(qalqiymet*enfaiz/100);

   QalQiymetEdit->Text=FormatFloat("#",qalqiymet);
   EnQiymetEdit->Text=FormatFloat("#",enqiymet);
}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::ElavecalcButtonClick(TObject *Sender)
{
	//esas hisseni yenile
	Form2->EsascalcButton->Click();

	//elave faiz deyishikliyini yenile
	float faiz=StrToFloat(ElaveFaizEdit->Text);

	for(int i=1;i<ElaveStringGrid->RowCount;i++)
		if(ElaveStringGrid->Cells[6][i]!="" && ElaveStringGrid->Cells[6][i]!="0"){

		float qiymet=StrToFloat(ElaveStringGrid->Cells[6][i]);
		float netice=qiymet+qiymet*faiz/100;

		ElaveStringGrid->Cells[7][i]=FormatFloat("#",netice);
		}

	Form2->CheckBox2Click(CheckBox2);
	Form2->CheckBox2Click(CheckBox2);

    //elave hisseni yenile
	float elqiymet=0,elqiymetfaiz=0;
	ElaveQiymetEdit->Text=0;
	ElaveQiymetfaizliEdit->Text=0;

	if(EnQiymetEdit->Text=="")
	EnQiymetEdit->Text=0;

	for(int i=1;i<ElaveStringGrid->RowCount;i++)
		if(ElaveStringGrid->Cells[6][i]!="" && ElaveStringGrid->Cells[6][i]!="0" && ElaveStringGrid->Cells[7][i]!="" && ElaveStringGrid->Cells[7][i]!="0"){
		elqiymet=elqiymet+StrToFloat(ElaveStringGrid->Cells[6][i]);
		elqiymetfaiz=elqiymetfaiz+StrToFloat(ElaveStringGrid->Cells[7][i]);
		}

	ElaveQiymetEdit->Text=FormatFloat("#",elqiymet);
	ElaveQiymetfaizliEdit->Text=FormatFloat("#",elqiymetfaiz);

	float enesas=StrToFloat(EnQiymetEdit->Text);
	float umuqiymet=enesas+elqiymetfaiz;
	UmumiqiymetEdit->Text=FormatFloat("#",umuqiymet);

	float elqalfaiz=StrToFloat(ElqalfaizEdit->Text);
	float elenfaiz=StrToFloat(ElenfaizEdit->Text);
	float elqalqiymet=umuqiymet+(umuqiymet*elqalfaiz/100);
	float elenqiymet=elqalqiymet-(elqalqiymet*elenfaiz/100);

	ElqalQiymetEdit->Text=FormatFloat("#",elqalqiymet);
	ElenQiymetEdit->Text=FormatFloat("#",elenqiymet);

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
RvProject1->Open();
RvProject1->SetParam("sifaris",TeklifEdit->Text);
RvProject1->SetParam("musteri",MusteriEdit->Text);
RvProject1->SetParam("vaxt",DateTimePicker1->Date.DateString());
String s=MarkaTekComboBox->Text+" "+ModelTekComboBox->Text+" "+MuherrikTekComboBox->Text+" "+IlTekComboBox->Text;
RvProject1->SetParam("mmm",s);
RvProject1->SetParam("ozesas",OzellikTekMemo->Text);
RvProject1->SetParam("qiymetesas",EnQiymetEdit->Text);

s="";
String say="";
for(int i=1;i<ElaveStringGrid->RowCount-1;i++){
say=i;
s=ElaveStringGrid->Cells[1][i]+" "+ElaveStringGrid->Cells[2][i]+" "+ElaveStringGrid->Cells[3][i];

RvProject1->SetParam("kod"+say,ElaveStringGrid->Cells[0][i]);
RvProject1->SetParam("ad"+say,s);
RvProject1->SetParam("qiymet"+say,ElaveStringGrid->Cells[7][i]);
}

RvProject1->SetParam("qiymet",UmumiqiymetEdit->Text);
RvProject1->SetParam("enfaiz",ElenfaizEdit->Text+" %");
RvProject1->SetParam("enqiymet",ElenQiymetEdit->Text);

RvProject1->Execute();

}
//---------------------------------------------------------------------------

void __fastcall TForm2::CheckBox1Click(TObject *Sender)
{
if(CheckBox1->Checked==true)
for(int i=0;i<ElaveStringGrid->RowCount;i++)
ElaveStringGrid->Cells[4][i]=ElaveStringGrid->Cells[6][i];

else
for(int i=0;i<ElaveStringGrid->RowCount;i++)
ElaveStringGrid->Cells[4][i]="";

}
//---------------------------------------------------------------------------

void __fastcall TForm2::CheckBox2Click(TObject *Sender)
{
if(CheckBox2->Checked==true)
for(int i=0;i<ElaveStringGrid->RowCount;i++)
ElaveStringGrid->Cells[5][i]=ElaveStringGrid->Cells[7][i];

else
for(int i=0;i<ElaveStringGrid->RowCount;i++)
ElaveStringGrid->Cells[5][i]="";

}
//---------------------------------------------------------------------------

void __fastcall TForm2::ElaveFaizEditChange(TObject *Sender)
{
	if(ElaveFaizEdit->Text!="")
	ElavecalcButton->Click();

}
//---------------------------------------------------------------------------


void __fastcall TForm2::Arxivpncrsi1Click(TObject *Sender)
{
Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)
{
/*
ID VARCHAR(14),
marka VARCHAR(30),
model VARCHAR(30),
muherrik VARCHAR(30),
il VARCHAR(4),
ban VARCHAR(30),
ozellik VARCHAR(10000),
qiymet int,
tarix VARCHAR(10),
teklifnom VARCHAR(50),
musteri VARCHAR(30),
faizp VARCHAR(5),
faizm VARCHAR(5),
tarixarc datetime,
faizel VARCHAR(5),
faizelp VARCHAR(5),
faizelm VARCHAR(5),

 */
if(MusteriEdit->Text!=""){

	TDateTime now= Now();
	String id=now.FormatString(L"yymmddhhnnss");

	if (TempSQLQuery->Active==true)
	TempSQLQuery->Close();
	//arxive elave et
	TempSQLQuery->SQL->Clear();
	TempSQLQuery->SQL->Add("insert into archive (id,marka,model,muherrik,il,ban,ozellik,qiymet,tarix,teklifnom,musteri,faizp,faizm,tarixarc,faizel,faizelp,faizelm) values ('"+id+"','"+MarkaTekComboBox->Text+"','"+ModelTekComboBox->Text+"','"+MuherrikTekComboBox->Text+"','"+IlTekComboBox->Text+"','"+BanTekComboBox->Text+"','"+OzellikTekMemo->Text+"','"+QiymetTekEdit->Text+"','"+DateToStr(DateTimePicker1->Date)+"','"+TeklifEdit->Text+"','"+MusteriEdit->Text+"','"+QalFaizEdit->Text+"','"+EnFaizEdit->Text+"',NOW(),'"+ElaveFaizEdit->Text+"','"+ElqalfaizEdit->Text+"','"+ElenfaizEdit->Text+"')");
	TempSQLQuery->ExecSQL();

	//elaveleri arxive elave et
	for(int i=1;i<ElaveStringGrid->RowCount-1;i++){

	TempSQLQuery->SQL->Clear();
	TempSQLQuery->SQL->Add("insert into archiveelave (idarchive,kod,qrup,altqrup,ad,qiymet) values ('"+id+"','"+ElaveStringGrid->Cells[0][i]+"','"+ElaveStringGrid->Cells[1][i]+"','"+ElaveStringGrid->Cells[2][i]+"','"+ElaveStringGrid->Cells[3][i]+"','"+ElaveStringGrid->Cells[6][i]+"')");
	TempSQLQuery->ExecSQL();

	}



	//yenile
	ArchiveSQLQuery->Close();
	ArchiveSQLQuery->Open();

	if (ArchiveClientDataSet->Active==true)
	ArchiveClientDataSet->Close();
	ArchiveClientDataSet->Open();

	ShowMessage(L"Arxivə əlavə edildi!");


   }
else
ShowMessage(L"Müştəri adını daxil edin!");

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender)
{
tesdiq=false;
OKHelpBottomDlg->ShowModal();

if(tesdiq)
		Form2->Button7->Click();

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)
{
		for(int i=0;i<8;i++)    //8 ElaveStringGrid->ColCount deyeridir
		for(int r=1;r<ElaveStringGrid->RowCount;r++)
		ElaveStringGrid->Cells[i][r]="";

		ElaveStringGrid->RowCount=2;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FileOpenItemClick(TObject *Sender)
{
Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FileSaveItemClick(TObject *Sender)
{
Form2->Button5->Click();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::QalFaizEditChange(TObject *Sender)
{
if(QalFaizEdit->Text!="")
EsascalcButton->Click();

}
//---------------------------------------------------------------------------

void __fastcall TForm2::EnFaizEditChange(TObject *Sender)
{
if(EnFaizEdit->Text!="")
EsascalcButton->Click();

}
//---------------------------------------------------------------------------

void __fastcall TForm2::ElqalfaizEditChange(TObject *Sender)
{
if(ElqalfaizEdit->Text!="")
ElavecalcButton->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ElenfaizEditChange(TObject *Sender)
{
if(ElenfaizEdit->Text!="")
ElavecalcButton->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::HelpAboutItemClick(TObject *Sender)
{
AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

