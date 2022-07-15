//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <cmath>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------

int type = 0;

void calculate()
{
    double a, a1, a2, a3;
    switch (type)
    {
    	case 1: //Прямоугольник периметр
        {
            if (MainForm->Edit1->Text != "" && MainForm->Edit2->Text != "")
            {
            	a1 = MainForm->Edit1->Text.ToDouble();
    		a2 = MainForm->Edit2->Text.ToDouble();
            	if (a1 > 0 || a2 > 0)
                {
            	    a = (a1 + a2)*2;
                    MainForm->InfoLabel->Caption = "Периметр: " + FloatToStr(a);
                    MainForm->ErrorLabel->Visible = false;

                    //построение
                    while (a1 > 180 || a2 > 180)
                    {
                    	a1 *= 0.99;
                        a2 *= 0.99;
                    }
                    while (a1 < 180 && a2 < 180)
                    {
                    	a1 *= 1.01;
                        a2 *= 1.01;
                    }
                    MainForm->PaintArea->Canvas->Rectangle(0,0,199,199);
                    MainForm->PaintArea->Canvas->Rectangle(4,195,4+std::floor(a1),195-std::floor(a2));
                }
                else
                {
                    MainForm->ErrorLabel->Caption = "Числа должны быть положительные!";
                    MainForm->ErrorLabel->Visible = true;
                }
            }
            else
            {
            	MainForm->ErrorLabel->Caption = "Нужно ввести два числа!";
                MainForm->ErrorLabel->Visible = true;
            }
        } break;
        case 2: //Прямоугольник площадь
        {
            if (MainForm->Edit1->Text != "" && MainForm->Edit2->Text != "")
            {
            	a1 = MainForm->Edit1->Text.ToDouble();
    		a2 = MainForm->Edit2->Text.ToDouble();
            	if (a1 > 0 || a2 > 0)
                {
            	    a = a1*a2;
                    MainForm->InfoLabel->Caption = "Площадь: " + FloatToStr(a);
                    MainForm->ErrorLabel->Visible = false;

                    //построение
                    while (a1 > 180 || a2 > 180)
                    {
                    	a1 *= 0.99;
                        a2 *= 0.99;
                    }
                    while (a1 < 180 && a2 < 180)
                    {
                    	a1 *= 1.01;
                        a2 *= 1.01;
                    }
                    MainForm->PaintArea->Canvas->Rectangle(0,0,199,199);
                    MainForm->PaintArea->Canvas->Rectangle(4,195,4+std::floor(a1),195-std::floor(a2));
                }
                else
                {
                    MainForm->ErrorLabel->Caption = "Числа должны быть положительные!";
                    MainForm->ErrorLabel->Visible = true;
                }
            }
            else
            {
            	MainForm->ErrorLabel->Caption = "Нужно ввести два числа!";
                MainForm->ErrorLabel->Visible = true;
            }
        } break;
        case 3: //Треугольник периметр
        {
            if (MainForm->Edit1->Text != "" && MainForm->Edit2->Text != "" && MainForm->Edit3->Text != "")
            {
                a1 = MainForm->Edit1->Text.ToDouble();
                a2 = MainForm->Edit2->Text.ToDouble();
                a3 = MainForm->Edit3->Text.ToDouble();
                if (a1 > 0 || a2 > 0 || a3 > 0)
                {
                    if (a1 + a2 > a3 && a2 + a3 > a1 && a3 + a1 > a2)
                    {
            	        a = a1+a2+a3;
                        MainForm->InfoLabel->Caption = "Периметр: " + FloatToStr(a);
                        MainForm->ErrorLabel->Visible = false;

                        //построение
                        while (a1 > 180 || a2 > 180 || a3 > 180)
                        {
                            a1 *= 0.99;
                            a2 *= 0.99;
                            a3 *= 0.99;
                        }
                        while (a1 < 180 && a2 < 180 && a3 < 180)
                        {
                            a1 *= 1.01;
                            a2 *= 1.01;
                            a3 *= 1.01;
                        }
                        MainForm->PaintArea->Canvas->Rectangle(0,0,199,199);
                        int x = (a1*a1+a2*a2-a3*a3)/2/a1;
                        int y = std::sqrt(a2*a2-x*x);
                        MainForm->PaintArea->Canvas->MoveTo(4,195);
                        MainForm->PaintArea->Canvas->LineTo(4+a1,195);
                        MainForm->PaintArea->Canvas->LineTo(x,195-y);
                        MainForm->PaintArea->Canvas->LineTo(4,195);
                    }
                    else
                    {
                        MainForm->ErrorLabel->Caption = "Треугольник не существует!";
                        MainForm->ErrorLabel->Visible = true;
                    }
                }
                else
                {
                    MainForm->ErrorLabel->Caption = "Числа должны быть положительные!";
                    MainForm->ErrorLabel->Visible = true;
                }
            }
            else
            {
                MainForm->ErrorLabel->Caption = "Нужно ввести три числа!";
                MainForm->ErrorLabel->Visible = true;
            }
        } break;
        case 4: //Треугольник площадь
        {
            if (MainForm->Edit1->Text != "" && MainForm->Edit2->Text != "" && MainForm->Edit3->Text != "")
            {
                a1 = MainForm->Edit1->Text.ToDouble();
                a2 = MainForm->Edit2->Text.ToDouble();
                a3 = MainForm->Edit3->Text.ToDouble();
            	if (a1 > 0 || a2 > 0 || a3 > 0)
                {
                    if (a1 + a2 > a3 && a2 + a3 > a1 && a3 + a1 > a2)
                    {
			double p = (a1+a2+a3)/2;
                        a = std::sqrt(p*(p-a1)*(p-a2)*(p-a3));
                        MainForm->InfoLabel->Caption = "Площадь: " + FloatToStr(a);
                        MainForm->ErrorLabel->Visible = false;

                        //построение
                        while (a1 > 180 || a2 > 180 || a3 > 180)
                    	{
                            a1 *= 0.99;
                            a2 *= 0.99;
                            a3 *= 0.99;
                    	}
                        while (a1 < 180 && a2 < 180 && a3 < 180)
                        {
                            a1 *= 1.01;
                            a2 *= 1.01;
                            a3 *= 1.01;
                    	}
                    	MainForm->PaintArea->Canvas->Rectangle(0,0,199,199);
                        int x = (a1*a1+a2*a2-a3*a3)/2/a1;
                        int y = std::sqrt(a2*a2-x*x);
                    	MainForm->PaintArea->Canvas->MoveTo(4,195);
                        MainForm->PaintArea->Canvas->LineTo(4+a1,195);
                        MainForm->PaintArea->Canvas->LineTo(x,195-y);
                        MainForm->PaintArea->Canvas->LineTo(4,195);
                    }
                    else
                    {
                    	MainForm->ErrorLabel->Caption = "Треугольник не существует!";
                        MainForm->ErrorLabel->Visible = true;
                    }
                }
                else
                {
                    MainForm->ErrorLabel->Caption = "Числа должны быть положительные!";
                    MainForm->ErrorLabel->Visible = true;
                }
            }
            else
            {
            	MainForm->ErrorLabel->Caption = "Нужно ввести три числа!";
                MainForm->ErrorLabel->Visible = true;
            }
        } break;
        case 5: //Окружность длина
        {
            if (MainForm->Edit1->Text != "")
            {
            	a1 = MainForm->Edit1->Text.ToDouble();
            	if (a1 > 0 || a2 > 0)
                {
            	    a = a1 * 2 * 3.1415926535;
        	    MainForm->InfoLabel->Caption = "Длина: " + FloatToStr(a);
                    MainForm->ErrorLabel->Visible = false;

                    //построение
                    MainForm->PaintArea->Canvas->Rectangle(0,0,199,199);
                    MainForm->PaintArea->Canvas->Ellipse(4,195,184,15);
                }
                else
                {
                    MainForm->ErrorLabel->Caption = "Число должно быть положительным!";
                    MainForm->ErrorLabel->Visible = true;
                }
            }
            else
            {
            	MainForm->ErrorLabel->Caption = "Нужно ввести число!";
                MainForm->ErrorLabel->Visible = true;
            }
        } break;
        case 6: //Окружность площадь
        {
            if (MainForm->Edit1->Text != "")
            {
            	a1 = MainForm->Edit1->Text.ToDouble();
            	if (a1 > 0 || a2 > 0)
                {
                    a = a1 * a1 * 3.1415926535;
                    MainForm->InfoLabel->Caption = "Площадь: " + FloatToStr(a);
                    MainForm->ErrorLabel->Visible = false;

                    //построение
                    MainForm->PaintArea->Canvas->Rectangle(0,0,199,199);
                    MainForm->PaintArea->Canvas->Ellipse(4,195,184,15);
                }
                else
                {
                    MainForm->ErrorLabel->Caption = "Число должно быть положительным!";
                    MainForm->ErrorLabel->Visible = true;
                }
            }
            else
            {
            	MainForm->ErrorLabel->Caption = "Нужно ввести число!";
                MainForm->ErrorLabel->Visible = true;
            }
        } break;
    }
}
//---------------------------------------------------------------------------

__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AppCloseClick(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N2Click(TObject *Sender)
{
    type = 1;
    MenuLabel->Caption = "Прямоугольник";
    Label1->Caption = "Сторона А";
    Label2->Caption = "Сторона В";
    InfoLabel->Caption = "Периметр: ";

    Screen->Visible = false;
    MenuLabel->Visible = true;
    Edit1->Visible = true;
    Edit2->Visible = true;
    Edit3->Visible = false;
    Label1->Visible = true;
    Label2->Visible = true;
    Label3->Visible = false;
    InfoLabel->Visible = true;
    PaintArea->Visible = true;

    calculate();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N3Click(TObject *Sender)
{
    type = 2;
    MenuLabel->Caption = "Прямоугольник";
    Label1->Caption = "Сторона А";
    Label2->Caption = "Сторона В";
    InfoLabel->Caption = "Площадь: ";

    Screen->Visible = false;
    MenuLabel->Visible = true;
    Edit1->Visible = true;
    Edit2->Visible = true;
    Edit3->Visible = false;
    Label1->Visible = true;
    Label2->Visible = true;
    Label3->Visible = false;
    InfoLabel->Visible = true;
    PaintArea->Visible = true;

    calculate();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N5Click(TObject *Sender)
{
    type = 3;
    MenuLabel->Caption = "Треугольник";
    Label1->Caption = "Сторона А";
    Label2->Caption = "Сторона В";
    Label3->Caption = "Сторона С";
    InfoLabel->Caption = "Периметр: ";

    Screen->Visible = false;
    MenuLabel->Visible = true;
    Edit1->Visible = true;
    Edit2->Visible = true;
    Edit3->Visible = true;
    Label1->Visible = true;
    Label2->Visible = true;
    Label3->Visible = true;
    InfoLabel->Visible = true;
    PaintArea->Visible = true;

    calculate();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N6Click(TObject *Sender)
{
    type = 4;
    MenuLabel->Caption = "Треугольник";
    Label1->Caption = "Сторона А";
    Label2->Caption = "Сторона В";
    Label3->Caption = "Сторона С";
    InfoLabel->Caption = "Площадь: ";

    Screen->Visible = false;
    MenuLabel->Visible = true;
    Edit1->Visible = true;
    Edit2->Visible = true;
    Edit3->Visible = true;
    Label1->Visible = true;
    Label2->Visible = true;
    Label3->Visible = true;
    InfoLabel->Visible = true;
    PaintArea->Visible = true;

    calculate();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N8Click(TObject *Sender)
{
    type = 5;
    MenuLabel->Caption = "Окружность";
    Label1->Caption = "Радиус";
    InfoLabel->Caption = "Длина: ";

    Screen->Visible = false;
    MenuLabel->Visible = true;
    Edit1->Visible = true;
    Edit2->Visible = false;
    Edit3->Visible = false;
    Label1->Visible = true;
    Label2->Visible = false;
    Label3->Visible = false;
    InfoLabel->Visible = true;
    PaintArea->Visible = true;

    calculate();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N9Click(TObject *Sender)
{
    type = 6;
    MenuLabel->Caption = "Окружность";
    Label1->Caption = "Радиус";
    InfoLabel->Caption = "Площадь: ";

    Screen->Visible = false;
    MenuLabel->Visible = true;
    Edit1->Visible = true;
    Edit2->Visible = false;
    Edit3->Visible = false;
    Label1->Visible = true;
    Label2->Visible = false;
    Label3->Visible = false;
    InfoLabel->Visible = true;
    PaintArea->Visible = true;

    calculate();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N11Click(TObject *Sender)
{
    MathForm->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N12Click(TObject *Sender)
{
    AboutForm->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit1Change(TObject *Sender)
{
    calculate();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit2Change(TObject *Sender)
{
    calculate();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit3Change(TObject *Sender)
{
    calculate();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
    MainForm->PaintArea->Canvas->Pen->Color = RGB(255,255,255);
    MainForm->PaintArea->Canvas->Brush->Color = RGB(0,0,0);
    MainForm->PaintArea->Canvas->Rectangle(0,0,199,199);
}
//---------------------------------------------------------------------------

