//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
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

void __fastcall TForm1::Close1Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Add1Click(TObject *Sender)
{
Form2->DateTimePicker1->Date=Now().CurrentDate();
Form2->DateTimePicker2->Date=Now().CurrentDate();
Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Add2Click(TObject *Sender)
{
Form1->Add1Click(Add1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Delete2Click(TObject *Sender)
{
ScQuery2->SQL->Clear();
ScQuery2->SQL->Add("delete from scheduler_list where ID='"+ScQuery1->FieldByName("ID")->AsString+"'");
ScQuery2->ExecSQL();

ScQuery1->Close();
ScQuery1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Delete1Click(TObject *Sender)
{
Form1->Delete2Click(Delete2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
TDateTime a;
ScQuery1->First();
 for(int i=0;i<=ScQuery1->RecordCount-1;i++)
 {
 ScQuery1->RecNo=i;
  if(FormatDateTime("hh:mm",ScQuery1->FieldByName("Time")->AsDateTime)==FormatDateTime("hh:mm",a.CurrentTime()) && ScQuery1->FieldByName("Start_date")->AsDateTime<=a.CurrentDate() && a.CurrentDate()<=ScQuery1->FieldByName("Stop_date")->AsDateTime)
  {
  String bsc=ScQuery1->FieldByName("BSC")->AsString;
  String cell=ScQuery1->FieldByName("Cell")->AsString;
  String date2=FormatDateTime("yy.MM.dd",Now().CurrentDate());
  String time2=FormatDateTime("hh:mm",StrToTime(ScQuery1->FieldByName("Time")->AsString));

         if(ScQuery1->FieldByName("Halt_active")->AsString=="HALTED")
        {

        String sebeb=ScQuery1->FieldByName("Kesintinin_sebebi")->AsString;
        String note=ScQuery1->FieldByName("Note")->AsString;

        ScQuery2->SQL->Clear();
        ScQuery2->SQL->Add("insert into kesinti (yoxla,bsc_number,cell,location,reason,occur_date,occur_time,ceasing_date,note,alarm_no) values ('n','"+bsc+"','"+cell+"',(select location from station where cell='"+cell+"'),'"+sebeb+"','"+date2+"','"+time2+"','','"+note+"','AAA')");
        ScrepMemo->Lines->Add("insert into kesinti (yoxla,bsc_number,cell,location,reason,occur_date,occur_time,ceasing_date,note,alarm_no) values ('n','"+bsc+"','"+cell+"',(select location from station where cell='"+cell+"'),'"+sebeb+"','"+date2+"','"+time2+"','','"+note+"','AAA')");
        ScQuery2->ExecSQL();

        ScrepMemo->Lines->Add(cell+" halt edildi.(ID="+ScQuery1->FieldByName("ID")->AsString+"), "+ a.CurrentDateTime());
        }
        else
        {
        ScQuery2->Close();
        ScQuery2->SQL->Clear();
        ScQuery2->SQL->Add("select * from kesinti where cell='"+cell+"' and ceasing_date='';");
        ScQuery2->ExecSQL();
        ScQuery2->Open();

        String date1=FormatDateTime("yy.MM.dd",ScQuery2->FieldByName("OCCUR_DATE")->AsDateTime);
        String time1=ScQuery2->FieldByName("OCCUR_TIME")->AsString;

        //ScrepMemo->Lines->Add(ScQuery1->FieldByName("ID")->AsString+" aktiv edildi. "+ a.CurrentDateTime());
        ScQuery2->SQL->Clear();
        ScQuery2->SQL->Add("update kesinti set ceasing_date='"+date2+"',ceasing_time='"+time2+"',duration=TIMESTAMPDIFF(MINUTE,'"+date1+" "+time1+"','"+date2+" "+time2+"') where cell='"+cell+"' and alarm_no='AAA' and bsc_number='"+bsc+"' and ceasing_date=''");
        ScrepMemo->Lines->Add("update kesinti set ceasing_date='"+date2+"',ceasing_time='"+time2+"',duration=TIMESTAMPDIFF(MINUTE,'"+date1+" "+time1+"','"+date2+" "+time2+"') where cell='"+cell+"' and alarm_no='AAA' and bsc_number='"+bsc+"' and ceasing_date=''");
        ScQuery2->ExecSQL();


        ScrepMemo->Lines->Add(cell+" aktiv edildi edildi.(ID="+ScQuery1->FieldByName("ID")->AsString+"), "+ a.CurrentDateTime());
        }

  }
  ScQuery1->Next();
 }
}
//---------------------------------------------------------------------------


