//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
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
  void __fastcall TForm1::filter(TObject *Sender)
{
        String BSC="node='BSC50'";

        if(BakiCheckBox->Checked){
        BSC=BSC+BakiLabel->Caption;
        }

        if(SumqayitCheckBox->Checked){
        BSC=BSC+SumqayitLabel->Caption;
        }

        if(ShirvanCheckBox->Checked){
        BSC=BSC+ShirvanLabel->Caption;
        }

        if(GenceCheckBox->Checked){
        BSC=BSC+GenceLabel->Caption;
        }

        if(NaxchivanCheckBox->Checked){
        BSC=BSC+NaxcivanLabel->Caption;
        }


        if(Drops_uncomment_Query->Active==true)
        Drops_uncomment_Query->Close();
        Drops_uncomment_Query->SQL->Clear();
        Drops_uncomment_Query->SQL->Text="SELECT id,node,cell,occur_date_time,ceasing_date_time,status FROM cells_drop where cell_type like '%"+TypeComboBox->Text+"%' AND status like '%"+StateComboBox->Text+"%' AND ("+BSC+") AND ((reason is null or reason='') or (status=2 and (note is null or note='')))";
        Drops_uncomment_Query->Open();

        if(DropsQuery->Active==true)
        DropsQuery->Close();
        DropsQuery->SQL->Clear();
        DropsQuery->SQL->Text="SELECT id,node,cell,location,reason,occur_date_time,ceasing_date_time,note FROM cells_drop where occur_date_time>date_sub(current_date,interval 1 day) AND cell_type like '%"+TypeComboBox->Text+"%' AND status like '%"+StateComboBox->Text+"%' AND ("+BSC+") ORDER BY occur_date_time desc";
        DropsQuery->Open();

}
//---------------------------------------------------------------------------

 void __fastcall TForm1::show(String s)
{

StringGrid2g->RowCount=1;
StringGrid3g->RowCount=1;

if(CellQuery->Active==true)
CellQuery->Close();
CellQuery->SQL->Clear();
CellQuery->SQL->Text="select * from cells where site='"+s+"' and cell_type='2G' order by cell";
CellQuery->Open();

SiteEdit->Text=CellQuery->FieldByName("site")->AsString;
LocationEdit->Text=CellQuery->FieldByName("location")->AsString;
SitenoEdit->Text=CellQuery->FieldByName("siteno")->AsString;
LatitudeEdit->Text=CellQuery->FieldByName("latitude")->AsString;
LongitudeEdit->Text=CellQuery->FieldByName("longitude")->AsString;


for(int i=0;!CellQuery->Eof;i++){
StringGrid2g->RowCount=i+2;
StringGrid2g->Cells[0][i+1]=CellQuery->FieldByName("id")->AsString;
StringGrid2g->Cells[1][i+1]=CellQuery->FieldByName("node")->AsString;
StringGrid2g->Cells[2][i+1]=CellQuery->FieldByName("cell")->AsString;
StringGrid2g->Cells[3][i+1]=CellQuery->FieldByName("tg")->AsString;
StringGrid2g->Cells[4][i+1]=CellQuery->FieldByName("rblt")->AsString;
StringGrid2g->Cells[5][i+1]=CellQuery->FieldByName("cgi")->AsString;
StringGrid2g->Cells[6][i+1]=CellQuery->FieldByName("tru")->AsString;
StringGrid2g->Cells[7][i+1]=CellQuery->FieldByName("broadcast")->AsString;
StringGrid2g->Cells[8][i+1]=CellQuery->FieldByName("rbs")->AsString;
StringGrid3g->Cells[9][i+1]=CellQuery->FieldByName("locno")->AsString;
StringGrid2g->Cells[10][i+1]=CellQuery->FieldByName("note")->AsString;
StringGrid2g->Cells[11][i+1]=CellQuery->FieldByName("direction")->AsString;
CellQuery->Next();
}

if(StringGrid2g->RowCount>1){
StringGrid2g->FixedRows=1;
StringGrid2g->FixedCols=1;
}

CellQuery->Close();
CellQuery->SQL->Clear();
CellQuery->SQL->Text="select * from cells where site='"+s+"' and cell_type='3G'  order by cell";
CellQuery->Open();




Site3gEdit->Text=CellQuery->FieldByName("site")->AsString;
Location3gEdit->Text=CellQuery->FieldByName("location")->AsString;
ImaEdit->Text=CellQuery->FieldByName("ima")->AsString;
Latitude3gEdit->Text=CellQuery->FieldByName("latitude")->AsString;
Longitude3gEdit->Text=CellQuery->FieldByName("longitude")->AsString;


for(int i=0;!CellQuery->Eof;i++){
StringGrid3g->RowCount=i+2;
StringGrid3g->Cells[0][i+1]=CellQuery->FieldByName("id")->AsString;
StringGrid3g->Cells[1][i+1]=CellQuery->FieldByName("node")->AsString;
StringGrid3g->Cells[2][i+1]=CellQuery->FieldByName("cell")->AsString;
StringGrid3g->Cells[3][i+1]=CellQuery->FieldByName("rblt")->AsString;
StringGrid3g->Cells[4][i+1]=CellQuery->FieldByName("cgi")->AsString;
StringGrid3g->Cells[5][i+1]=CellQuery->FieldByName("scr")->AsString;
StringGrid3g->Cells[6][i+1]=CellQuery->FieldByName("broadcast")->AsString;
StringGrid3g->Cells[7][i+1]=CellQuery->FieldByName("rbs")->AsString;
StringGrid3g->Cells[8][i+1]=CellQuery->FieldByName("ip")->AsString;
StringGrid3g->Cells[9][i+1]=CellQuery->FieldByName("locno")->AsString;
StringGrid3g->Cells[10][i+1]=CellQuery->FieldByName("note")->AsString;
StringGrid3g->Cells[11][i+1]=CellQuery->FieldByName("direction")->AsString;
CellQuery->Next();
}

if(StringGrid3g->RowCount>1){
StringGrid3g->FixedRows=1;
StringGrid3g->FixedCols=1;
}

Lat1Edit->Text="";
Lat2Edit->Text="";
Lat3Edit->Text="";

Lat1_3gEdit->Text="";
Lat2_3gEdit->Text="";
Lat3_3gEdit->Text="";

Lon1Edit->Text="";
Lon2Edit->Text="";
Lon3Edit->Text="";

Lon1_3gEdit->Text="";
Lon2_3gEdit->Text="";
Lon3_3gEdit->Text="";


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
 float lat1,lat2,lat3,lat,lon1,lon2,lon3,lon;

 if(Lat1Edit->Text!="" && Lat2Edit->Text!="" && Lat3Edit->Text!=""){
 lat1=StrToFloat(Lat1Edit->Text);
 lat2=StrToFloat(Lat2Edit->Text);
 lat3=StrToFloat(Lat3Edit->Text);

 lat=lat1+(((lat2*60)+(lat3))/3600);
 LatitudeEdit->Text=FloatToStr(lat);
 }

 if(Lon1Edit->Text!="" && Lon2Edit->Text!="" && Lon3Edit->Text!=""){
 lon1=StrToFloat(Lon1Edit->Text);
 lon2=StrToFloat(Lon2Edit->Text);
 lon3=StrToFloat(Lon3Edit->Text);

 lon=lon1+(((lon2*60)+(lon3))/3600);
 LongitudeEdit->Text=FloatToStr(lon);
 }


// Converts DMS ( Degrees / minutes / seconds )
// to decimal format longitude / latitude
    //function DMStoDEC($deg,$min,$sec)
    //return $deg+((($min*60)+($sec))/3600);

/*
OKBottomDlg->ShowModal();
if(Delete=="OK"){
 QueryGl->SQL->Clear();
 QueryGl->SQL->Add("DELETE FROM nodes WHERE ID='"+DBText1->Caption+"'");
 QueryGl->ExecSQL();

 QueryGl->Close();
 QueryGl->Open();

 Delete="";
 }
 */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
//Password request  and version check
PasswordDlg->ShowModal();

if(QueryGl->Active==true)
QueryGl->Close();
QueryGl->SQL->Clear();
QueryGl->SQL->Text="select * from version where PROGRAM_NAME='ADMIN' and PROGRAM_VERSION='6.8'";
QueryGl->Open();


 if(QueryGl->IsEmpty()){
 ShowMessage("Program version is old, please use new version.");
 Form1->Close();
 }
 
QueryGl->Close();
        //Incorrect cells hissesine node-larin elave edilmesi
        QueryGl->SQL->Clear();
        QueryGl->SQL->Text="select NE from nodes where NE like 'BSC%' OR NE like 'RNC%' order by NE";
        QueryGl->Open();

        ComboBox1->Items->Add("");
        while(!QueryGl->Eof){
        ComboBox1->Items->Add(QueryGl->FieldByName("NE")->AsString);
        QueryGl->Next();
        }
        ComboBox1->ItemIndex=0;

        //kesinti filterinde node-larin elave edilmesi
        //Baki
        QueryGl->Close();
        QueryGl->SQL->Clear();
        QueryGl->SQL->Text="select NE from nodes where (NE like 'BSC%' OR NE like 'RNC%') AND LOCATION='BAKI' order by NE";
        QueryGl->Open();
        BakiLabel->Caption="";
        while(!QueryGl->Eof){
        BakiLabel->Caption=BakiLabel->Caption+" OR node='"+QueryGl->FieldByName("NE")->AsString+"'";
        QueryGl->Next();
        }
        //Sumqayit
        QueryGl->Close();
        QueryGl->SQL->Clear();
        QueryGl->SQL->Text="select NE from nodes where (NE like 'BSC%' OR NE like 'RNC%') AND LOCATION='SUMQAYIT' order by NE";
        QueryGl->Open();
        SumqayitLabel->Caption="";
        while(!QueryGl->Eof){
        SumqayitLabel->Caption=SumqayitLabel->Caption+" OR node='"+QueryGl->FieldByName("NE")->AsString+"'";
        QueryGl->Next();
        }
        //Sirvan
        QueryGl->Close();
        QueryGl->SQL->Clear();
        QueryGl->SQL->Text="select NE from nodes where (NE like 'BSC%' OR NE like 'RNC%') AND LOCATION='SHIRVAN' order by NE";
        QueryGl->Open();
        ShirvanLabel->Caption="";
        while(!QueryGl->Eof){
        ShirvanLabel->Caption=ShirvanLabel->Caption+" OR node='"+QueryGl->FieldByName("NE")->AsString+"'";
        QueryGl->Next();
        }
        //Gence
        QueryGl->Close();
        QueryGl->SQL->Clear();
        QueryGl->SQL->Text="select NE from nodes where (NE like 'BSC%' OR NE like 'RNC%') AND LOCATION='GENCE' order by NE";
        QueryGl->Open();
        GenceLabel->Caption="";
        while(!QueryGl->Eof){
        GenceLabel->Caption=GenceLabel->Caption+" OR node='"+QueryGl->FieldByName("NE")->AsString+"'";
        QueryGl->Next();
        }
         //Naxcivan
        QueryGl->Close();
        QueryGl->SQL->Clear();
        QueryGl->SQL->Text="select NE from nodes where (NE like 'BSC%' OR NE like 'RNC%') AND LOCATION='NAXCHIVAN' order by NE";
        QueryGl->Open();
        NaxcivanLabel->Caption="";
        while(!QueryGl->Eof){
        NaxcivanLabel->Caption=NaxcivanLabel->Caption+" OR node='"+QueryGl->FieldByName("NE")->AsString+"'";
        QueryGl->Next();
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::About1Click(TObject *Sender)
{
  AboutBox->Show();     
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Close1Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------





void __fastcall TForm1::FormCreate(TObject *Sender)
{
StringGrid2g->ColCount=12;

StringGrid2g->Cols[0]->Text="Id";
StringGrid2g->Cols[1]->Text="BSC";
StringGrid2g->Cols[2]->Text="Cell";
StringGrid2g->Cols[3]->Text="TG";
StringGrid2g->Cols[4]->Text="E1";
StringGrid2g->Cols[5]->Text="CGI";
StringGrid2g->Cols[6]->Text="TRU";
StringGrid2g->Cols[7]->Text="Broadcast";
StringGrid2g->Cols[8]->Text="RBS ";
StringGrid2g->Cols[9]->Text="Locno";
StringGrid2g->Cols[10]->Text="Note";
StringGrid2g->Cols[11]->Text="Direction";


StringGrid2g->ColWidths[0]=30;
StringGrid2g->ColWidths[1]=40;
StringGrid2g->ColWidths[2]=50;
StringGrid2g->ColWidths[3]=25;
StringGrid2g->ColWidths[4]=90;
StringGrid2g->ColWidths[5]=60;
StringGrid2g->ColWidths[6]=30;
StringGrid2g->ColWidths[7]=120;
StringGrid2g->ColWidths[8]=40;
StringGrid2g->ColWidths[9]=120;
StringGrid2g->ColWidths[10]=180;
StringGrid2g->ColWidths[11]=50;


StringGrid3g->ColCount=12;

StringGrid3g->Cols[0]->Text="Id";
StringGrid3g->Cols[1]->Text="RNC";
StringGrid3g->Cols[2]->Text="Cell";
StringGrid3g->Cols[3]->Text="E1";
StringGrid3g->Cols[4]->Text="CGI";
StringGrid3g->Cols[5]->Text="SCR";
StringGrid3g->Cols[6]->Text="Broadcast";
StringGrid3g->Cols[7]->Text="RBS";
StringGrid3g->Cols[8]->Text="IP";
StringGrid3g->Cols[9]->Text="Locno";
StringGrid3g->Cols[10]->Text="Note";
StringGrid3g->Cols[11]->Text="Direction";


StringGrid3g->ColWidths[0]=30;
StringGrid3g->ColWidths[1]=40;
StringGrid3g->ColWidths[2]=60;
StringGrid3g->ColWidths[3]=90;
StringGrid3g->ColWidths[4]=60;
StringGrid3g->ColWidths[5]=25;
StringGrid3g->ColWidths[6]=120;
StringGrid3g->ColWidths[7]=40;
StringGrid3g->ColWidths[8]=60;
StringGrid3g->ColWidths[9]=120;
StringGrid3g->ColWidths[10]=180;
StringGrid3g->ColWidths[11]=50;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Site_Search_EditChange(TObject *Sender)
{
  if(Site_Search_Edit->Text.Length()>2){
        if(CellsQuery->Active==true)
        CellsQuery->Close();
        CellsQuery->SQL->Clear();
        CellsQuery->SQL->Text="select distinct site,node from cells where site like '%"+Site_Search_Edit->Text+"%'  order by cell";
        CellsQuery->Open();
  }
  else if(Site_Search_Edit->Text.Length()==0){
        if(CellsQuery->Active==true)
        CellsQuery->Close();
        CellsQuery->SQL->Clear();
        CellsQuery->SQL->Text="select distinct site,node from cells  order by cell";
        CellsQuery->Open();
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cell_Search_EditChange(TObject *Sender)
{

if(Cell_Search_Edit->Text.Length()>2){
        if(CellsQuery->Active==true)
        CellsQuery->Close();
        CellsQuery->SQL->Clear();
        CellsQuery->SQL->Text="select distinct site,node from cells where cell like '%"+Cell_Search_Edit->Text+"%'  order by cell";
        CellsQuery->Open();
}
else if(Cell_Search_Edit->Text.Length()==0){
        if(CellsQuery->Active==true)
        CellsQuery->Close();
        CellsQuery->SQL->Clear();
        CellsQuery->SQL->Text="select distinct site,node from cells  order by cell";
        CellsQuery->Open();
 }

}
//---------------------------------------------------------------------------




void __fastcall TForm1::DBGrid3CellClick(TColumn *Column)
{
Form1->show(CellsQuery->FieldByName("site")->AsString);        
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
        if(CellQuery->Active==true)
        CellQuery->Close();
        CellQuery->SQL->Clear();
        CellQuery->SQL->Text="select id,cell from cells where site='"+SiteEdit->Text+"'  order by cell";
        CellQuery->Open();

Form5->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
if(StringGrid2g->RowCount>1)
for(int row=1;row<StringGrid2g->RowCount;row++){
        if(QueryGl->Active==true)
        QueryGl->Close();
        QueryGl->SQL->Clear();
        QueryGl->SQL->Text="update cells set site='"+SiteEdit->Text+"', location='"+LocationEdit->Text+"', siteno='"+SitenoEdit->Text+"', latitude='"+LatitudeEdit->Text+"', longitude='"+LongitudeEdit->Text+"', node='"+StringGrid2g->Cells[1][row]+"', cell='"+StringGrid2g->Cells[2][row]+"', tg='"+StringGrid2g->Cells[3][row]+"', rblt='"+StringGrid2g->Cells[4][row]+"', cgi='"+StringGrid2g->Cells[5][row]+"',tru='"+StringGrid2g->Cells[6][row]+"', broadcast='"+StringGrid2g->Cells[7][row]+"', rbs='"+StringGrid2g->Cells[8][row]+"', locno='"+StringGrid2g->Cells[9][row]+"', note='"+StringGrid2g->Cells[10][row]+"', direction='"+StringGrid2g->Cells[11][row]+"' where id='"+StringGrid2g->Cells[0][row]+"'";
        QueryGl->ExecSQL();

}

if(StringGrid3g->RowCount>1)
for(int row=1;row<StringGrid3g->RowCount;row++){
        if(QueryGl->Active==true)
        QueryGl->Close();
        QueryGl->SQL->Clear();
        QueryGl->SQL->Text="update cells set site='"+Site3gEdit->Text+"', location='"+Location3gEdit->Text+"', latitude='"+Latitude3gEdit->Text+"', longitude='"+Longitude3gEdit->Text+"', node='"+StringGrid3g->Cells[1][row]+"', cell='"+StringGrid3g->Cells[2][row]+"', rblt='"+StringGrid3g->Cells[3][row]+"', cgi='"+StringGrid3g->Cells[4][row]+"', scr='"+StringGrid3g->Cells[5][row]+"', broadcast='"+StringGrid3g->Cells[6][row]+"', rbs='"+StringGrid3g->Cells[7][row]+"', ip='"+StringGrid3g->Cells[8][row]+"', locno='"+StringGrid3g->Cells[9][row]+"', note='"+StringGrid3g->Cells[10][row]+"', direction='"+StringGrid3g->Cells[11][row]+"' where id='"+StringGrid3g->Cells[0][row]+"'";
        QueryGl->ExecSQL();

}

if(Site_Search_Edit->Text!="")
Site_Search_EditChange(Site_Search_Edit);
else if(Cell_Search_Edit->Text!="")
Cell_Search_EditChange(Cell_Search_Edit);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Fail_search_EditChange(TObject *Sender)
{
 if(Fail_search_Edit->Text.Length()>2){
        if(CellsQuery->Active==true)
        CellsQuery->Close();
        CellsQuery->SQL->Clear();
        CellsQuery->SQL->Text="select distinct site,node from cells where cell like '%"+Fail_search_Edit->Text+"%' AND (latitude is null or latitude=0 or location is null or location='' or direction is null or length(site)<15) AND node like '%"+ComboBox1->Text+"%'  order by cell";
        CellsQuery->Open();
  }
  else if(Fail_search_Edit->Text.Length()==0){
        if(CellsQuery->Active==true)
        CellsQuery->Close();
        CellsQuery->SQL->Clear();
        CellsQuery->SQL->Text="select distinct site,node from cells where (latitude is null or latitude=0 or location is null or location='' or direction is null or length(site)<15) AND node like '%"+ComboBox1->Text+"%' order by cell";
        CellsQuery->Open();
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
   if(CheckBox1->Checked){
   GroupBox1->Visible=true;
   GroupBox7->Visible=false;
   if(CellsQuery->Active==true)
   CellsQuery->Close();
    CellsQuery->SQL->Clear();
    CellsQuery->SQL->Text="select distinct site,node from cells where latitude is null or latitude=0 or location is null or location='' or direction is null or length(site)<15 order by cell";
    CellsQuery->Open();

   }
   else{
   GroupBox1->Visible=false;
   GroupBox7->Visible=true;
        if(CellsQuery->Active==true)
        CellsQuery->Close();
        CellsQuery->SQL->Clear();
        CellsQuery->SQL->Text="select distinct site,node from cells  order by cell";
        CellsQuery->Open();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
    if(CellsQuery->Active==true)
    CellsQuery->Close();
    CellsQuery->SQL->Clear();
    CellsQuery->SQL->Text="select distinct site,node from cells where cell like '%"+Fail_search_Edit->Text+"%' AND (latitude is null or latitude=0 or location is null or location='' or direction is null  or length(site)<15) AND node like '%"+ComboBox1->Text+"%'  order by cell";
    CellsQuery->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
 float lat1_3g,lat2_3g,lat3_3g,lat_3g,lon1_3g,lon2_3g,lon3_3g,lon_3g;
 if(Lat1_3gEdit->Text!="" && Lat2_3gEdit->Text!="" && Lat3_3gEdit->Text!=""){
 lat1_3g=StrToFloat(Lat1_3gEdit->Text);
 lat2_3g=StrToFloat(Lat2_3gEdit->Text);
 lat3_3g=StrToFloat(Lat3_3gEdit->Text);

 //lat_3g=lat1_3g+(lat2_3g+lat3_3g/60)/60;
 lat_3g=lat1_3g+(((lat2_3g*60)+(lat3_3g))/3600);
 Latitude3gEdit->Text=FloatToStr(lat_3g);
 }

 if(Lon1_3gEdit->Text!="" && Lon2_3gEdit->Text!="" && Lon3_3gEdit->Text!=""){
 lon1_3g=StrToFloat(Lon1_3gEdit->Text);
 lon2_3g=StrToFloat(Lon2_3gEdit->Text);
 lon3_3g=StrToFloat(Lon3_3gEdit->Text);

 //lon_3g=lon1_3g+(lon2_3g+lon3_3g/60)/60;
 lon_3g=lon1_3g+(((lon2_3g*60)+(lon3_3g))/3600);
 Longitude3gEdit->Text=FloatToStr(lon_3g);
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BakiCheckBoxClick(TObject *Sender)
{
Form1->filter(BakiCheckBox);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SumqayitCheckBoxClick(TObject *Sender)
{
Form1->filter(SumqayitCheckBox);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ShirvanCheckBoxClick(TObject *Sender)
{
Form1->filter(ShirvanCheckBox);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GenceCheckBoxClick(TObject *Sender)
{
Form1->filter(GenceCheckBox);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NaxchivanCheckBoxClick(TObject *Sender)
{
Form1->filter(NaxchivanCheckBox);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Drops_search_EditChange(TObject *Sender)
{
String s=DropsQuery->SQL->Text;

if(Drops_search_Edit->Text.Length()>2){
        if(DropsQuery->Active==true)
        DropsQuery->Close();
        DropsQuery->SQL->Clear();
        DropsQuery->SQL->Text="select id,node,cell,location,reason,occur_date_time,ceasing_date_time,note from cells_drop where cell like '%"+Drops_search_Edit->Text+"%' order by occur_date_time desc";
        DropsQuery->Open();
  }
  else if(Drops_search_Edit->Text.Length()==0){
        if(DropsQuery->Active==true)
        DropsQuery->Close();
        DropsQuery->SQL->Clear();
        DropsQuery->SQL->Text=s;
        DropsQuery->Open();
 }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
Form6->ReasonComboBox->Items=ReasonComboBox->Items;
Form6->ReasonComboBox->Text=DropsQuery->FieldByName("reason")->AsString;
Form6->NoteEdit->Text=DropsQuery->FieldByName("note")->AsString;
Form6->IdLabel->Caption=DropsQuery->FieldByName("id")->AsString;
Form6->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 if(QueryGl->Active==true)
 QueryGl->Close();
 
if(ReasonComboBox->Text=="Xebersiz kesinti" && NoteEdit->Text=="")
ShowMessage("Zehmet olmasa note daxil edin!");
else
if(AddallCheckBox->Checked){
        while(!Drops_uncomment_Query->Eof){
        QueryGl->SQL->Clear();
        if(Drops_uncomment_Query->FieldByName("status")->AsString!="2")
        QueryGl->SQL->Text="update cells_drop set reason='"+ReasonComboBox->Text+"', note='"+NoteEdit->Text+"' where id='"+Drops_uncomment_Query->FieldByName("id")->AsString+"'";
        else
        QueryGl->SQL->Text="update cells_drop set reason='Fealiyyeti dayandirilib', note='"+NoteEdit->Text+"' where id='"+Drops_uncomment_Query->FieldByName("id")->AsString+"'";
        QueryGl->ExecSQL();
        Drops_uncomment_Query->Next();
        }
}
else{

        QueryGl->SQL->Clear();
        if(Drops_uncomment_Query->FieldByName("status")->AsString!="2")
        QueryGl->SQL->Text="update cells_drop set reason='"+ReasonComboBox->Text+"', note='"+NoteEdit->Text+"' where id='"+Drops_uncomment_Query->FieldByName("id")->AsString+"'";
        else
        QueryGl->SQL->Text="update cells_drop set reason='Fealiyyeti dayandirilib', note='"+NoteEdit->Text+"' where id='"+Drops_uncomment_Query->FieldByName("id")->AsString+"'";
        QueryGl->ExecSQL();
}
        DropsQuery->Close();
        DropsQuery->Open();

        Drops_uncomment_Query->Close();
        Drops_uncomment_Query->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TypeComboBoxChange(TObject *Sender)
{
Form1->filter(TypeComboBox);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StateComboBoxChange(TObject *Sender)
{
Form1->filter(StateComboBox);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if(Drops_uncomment_Query->Active==true)
Drops_uncomment_Query->Close();
Drops_uncomment_Query->Open();

if(DropsQuery->Active==true)
DropsQuery->Close();
DropsQuery->Open();



}
//---------------------------------------------------------------------------

