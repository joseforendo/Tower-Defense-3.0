#include "Menúprincipal.h"

using namespace System;
using namespace System::Windows::Forms;
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CastleDefense::Menúprincipal);
}
