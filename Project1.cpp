//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", MainForm);
USEFORM("Unit2.cpp", MathForm);
USEFORM("Unit3.cpp", AboutForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "Планиметрия";
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TMathForm), &MathForm);
		Application->CreateForm(__classid(TAboutForm), &AboutForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
