#include "APP_UI.h"
#include "IDs.h"
#include <thread>
// ===================================================
//					EVENT TABLES
// ===================================================
// =========================
//	  MAIN EVENT TABLE
// =========================
BEGIN_EVENT_TABLE(Landing, wxFrame)
	EVT_BUTTON(IDs::ID_BUTTON_MAN, Landing::MANAGER_EVENT_CALL)
	EVT_BUTTON(IDs::ID_BUTTON_CUS, Landing::CUSTOMER_EVENT_CALL)
	EVT_MENU(IDs::ID_REST_SIGNUP, Landing::REST_REG_COMMAND)
	EVT_MENU(IDs::ID_MAN_SIGNUP, Landing::MAN_REG_COMMAND)
	EVT_CLOSE(Landing::OnCloseWindow)
END_EVENT_TABLE();
// =========================
//	  MANAGER EVENT TABLE
// =========================
BEGIN_EVENT_TABLE(MANAGER_UI, wxFrame)
	EVT_CLOSE(MANAGER_UI::OnCloseWindow)
END_EVENT_TABLE();
// =========================
//	  CUSTOEMR EVENT TABLE
// =========================
BEGIN_EVENT_TABLE(CUSTOMER_UI, wxFrame)
	EVT_CLOSE(CUSTOMER_UI::OnCloseWindow)
END_EVENT_TABLE();
// =========================
// REGISTRATION EVENT TABLES
// =========================
// ======================
//	 REST_REG EVENT TABLES
// ======================
BEGIN_EVENT_TABLE(REST_REG_UI, wxFrame)
	EVT_CLOSE(REST_REG_UI::OnCloseWindow)
END_EVENT_TABLE();
// ======================
//	 MAN_REG EVENT TABLES
// ======================
BEGIN_EVENT_TABLE(MANAGER_REG_UI, wxFrame)
	EVT_CLOSE(MANAGER_REG_UI::OnCloseWindow)
END_EVENT_TABLE();
// ===================================================
//					UI CONSTRUCTORS
// ===================================================
// =========================
//		MAIN UI
// =========================
Landing::Landing() : wxFrame(NULL, -1, "Greetings! Hello there! Please pick your choice")
{
	wxMessageBox(
		wxT("Hi! After you close this window, you will be asked to choose whether you are a manager"
		"or a customer.\nPlease enjoy!"), 
		wxT("Welcome!"), 
		wxOK | wxICON_NONE
	);
	bar = new wxMenuBar;
	REGISTER = new wxMenu;
	REGISTER->Append(IDs::ID_MAN_SIGNUP, _T("&Register yourself"));
	REGISTER->Append(IDs::ID_REST_SIGNUP, _T("&Register your restaurant"));
	bar->Append(REGISTER, _T("Sign up"));
	SetMenuBar(bar);
	wxSizerFlags left;
	left.Align(wxALIGN_CENTER_VERTICAL);
	left.Border(wxLEFT | wxTOP | wxRIGHT | wxBOTTOM, 50);
	wxFlexGridSizer* _INSIZER = new wxFlexGridSizer(2, 0, 0);
	wxBoxSizer* _OUTTERBOX = new wxBoxSizer(wxVERTICAL);
	Manager = new wxButton(this, IDs::ID_BUTTON_MAN, "I am a manager", wxDefaultPosition, wxSize(200, 50));
	Customer = new wxButton(this, IDs::ID_BUTTON_CUS, "I am a customer", wxDefaultPosition, wxSize(200, 50));
	Manager->SetBackgroundColour(wxColour(0, 0, 0));
	Manager->SetForegroundColour(wxColour(255, 255, 255));
	_INSIZER->Add(Manager, left);
	_INSIZER->Add(Customer, left);
	_OUTTERBOX->Add(_INSIZER, wxSizerFlags().Center());
	this->SetBackgroundColour(wxColour(100, 100, 200));
	this->SetSizerAndFit(_OUTTERBOX);
	this->Center();
}

// =========================
//		MANAGER UI
// =========================
MANAGER_UI::MANAGER_UI() : wxFrame(nullptr, wxID_ANY, "Welcome whoever it is")
{
	menubar = new wxMenuBar;
	help = new wxMenu;
	help->Append(wxID_HELP, wxT("&Contact Me"));
	menubar->Append(help, wxT("&Help"));
	SetMenuBar(menubar);
}

MANAGER_UI::MANAGER_UI(Landing* MAIN_INSTANCE) : wxFrame(nullptr, wxID_ANY, "Welcome whoever it is")
{
	this->MAIN_INSTANCE = MAIN_INSTANCE;
	this->MAIN_INSTANCE->SET_INSTANCE('M',true);
	menubar = new wxMenuBar;
	help = new wxMenu;
	signout = new wxMenu;
	help->Append(wxID_HELP, wxT("&Contact Me"));
	signout->Append(IDs::ID_SIGNOUT, wxT("&Signout"));
	menubar->Append(help, wxT("&Help"));
	menubar->Append(signout, wxT("&Sign out"));
	SetMenuBar(menubar);
}
MANAGER_UI::~MANAGER_UI()
{

}
// =========================
//		CUSTOMER UI
// =========================
CUSTOMER_UI::CUSTOMER_UI(Landing* MAIN_INSTANCE) : wxFrame(nullptr, wxStandardID::wxID_ANY, "Welcome dear valuable customer")
{
	this->MAIN_INSTANCE = MAIN_INSTANCE;
	this->MAIN_INSTANCE->SET_INSTANCE('C', true);
	menubar = new wxMenuBar;
	file = new wxMenu;
	file->Append(wxID_HELP, wxT("&Contact Me"));
	menubar->Append(file, wxT("&Help"));
	this->menubar->SetBackgroundColour(wxColour(10,10,10));
	this->SetForegroundColour(wxColour(255,255,255));
	this->SetBackgroundColour(wxColour(100, 100, 200));
	SetMenuBar(menubar);
}

CUSTOMER_UI::~CUSTOMER_UI()
{
}

// =========================
//		ADDITIONAL UI
// =========================
// ============
// MANAGER REG
// ============

MANAGER_REG_UI::MANAGER_REG_UI(Landing* MAIN_INSTANCE) : wxFrame(nullptr, wxID_ANY, "MANAGER REGISTRATION PAGE")
{
	this->MAIN_INSTANCE = MAIN_INSTANCE;
	this->GET_MAIN_INSTANCE()->SET_INSTANCE('X', true);

	// do the rest of the UI
}

MANAGER_REG_UI::~MANAGER_REG_UI()
{
}
// ============
// REST REG
// ============
REST_REG_UI::REST_REG_UI(Landing* MAIN_INSTANCE) : wxFrame(nullptr, wxID_ANY, "RESTAURANT REGISTRATION PAGE")
{
	this->MAIN_INSTANCE = MAIN_INSTANCE;
	this->GET_MAIN_INSTANCE()->SET_INSTANCE('R', true);
/*	wxSizerFlags left;
	left.Align(wxALIGN_CENTER_VERTICAL);
	left.Border(wxLEFT | wxTOP | wxRIGHT | wxBOTTOM, 50);
	wxFlexGridSizer* _INSIZER = new wxFlexGridSizer(2, 0, 0);
	wxBoxSizer* _OUTTERBOX = new wxBoxSizer(wxVERTICAL);
	Manager = new wxButton(this, IDs::ID_BUTTON_MAN, "I am a manager", wxDefaultPosition, wxSize(200, 50));
	Customer = new wxButton(this, IDs::ID_BUTTON_CUS, "I am a customer", wxDefaultPosition, wxSize(200, 50));
	_INSIZER->Add(Manager, left);
	_INSIZER->Add(Customer, left);
	_OUTTERBOX->Add(_INSIZER, wxSizerFlags().Center());
	this->SetSizerAndFit(_OUTTERBOX);
	this->Center();*/
}

REST_REG_UI::~REST_REG_UI()
{
}
// ============
// REST REG
// ============
LOGIN_UI::LOGIN_UI() : wxFrame(nullptr, wxID_ANY, "RESTAURANT REGISTRATION PAGE")
{
}

LOGIN_UI::~LOGIN_UI()
{
}



// ===================================================
//						EVENTS
// ===================================================
// =========================
//		MAIN EVENTS
// =========================
// Closing Event
void Landing::OnCloseWindow(wxCloseEvent& evt)
{
	if (this->MANAGER_INSTANCE || this->CUSTOMER_INSTANCE)
	{
		wxMessageBox(
			wxT("Please quit every running instance before closing the main window!"),
			wxT("INSTANCES RUNNING!"), wxOK | wxICON_ERROR);
		evt.Veto();
		return;
	}
	else if (evt.CanVeto())
	{
		if (wxMessageBox(wxT("Are you sure you want to quit?"),
			wxT("Are you sure?"),
			wxICON_QUESTION | wxYES_NO) != wxYES)
		{
			evt.Veto();
			return;
		}
	}
	evt.Skip();
}

// =========================
//		MANAGER EVENTS
// =========================
// Closing Event
void MANAGER_UI::OnCloseWindow(wxCloseEvent& evt)
{
	if (evt.CanVeto())
	{
		if (wxMessageBox(wxT("Are you sure you want to quit?"),
			wxT("Are you sure?"),
			wxICON_QUESTION | wxYES_NO) != wxYES)
		{
			evt.Veto();
			return;
		}
	}
	evt.Skip();
	this->SET_MANAGER_INSTANCE(false);
	this->GET_MAIN_INSTANCE()->SET_INSTANCE('M',false);
}
// Event call to instantiate and run the MANAGER_UI
void Landing::MANAGER_EVENT_CALL(wxCommandEvent& evt)
{
	if (this->MANAGER_INSTANCE)
	{
		wxMessageBox(
			wxT("There is an instance already running, please quit every other instance running and try again."),
			wxT("INSTANCE ALREADY RUNNING!"), wxOK | wxICON_INFORMATION);
		evt.Skip();
		return;
	}
	else
	{
		MANAGER = new MANAGER_UI(this);
		MANAGER->Show();
		MANAGER->SET_MANAGER_INSTANCE(TRUE);
	}
}

// =========================
//		CUSTOMER EVENTS
// =========================

// Event call to instantiate and run the CUSTOMER_UI
void Landing::CUSTOMER_EVENT_CALL(wxCommandEvent& evt)
{
	if (this->CUSTOMER_INSTANCE)
	{
		wxMessageBox(
			wxT("There is an instance already running, please quit every other instance running and try again."),
			wxT("INSTANCE ALREADY RUNNING!"), wxOK | wxICON_INFORMATION);
		evt.Skip();
		return;
	}
	else
	{
		CUSTOMER = new CUSTOMER_UI(this);
		CUSTOMER->Show();
		CUSTOMER->SET_INSTANCE(TRUE);
	}
}

// Closing Event
void CUSTOMER_UI::OnCloseWindow(wxCloseEvent& evt)
{
	if (evt.CanVeto())
	{
		if (wxMessageBox(wxT("Are you sure you want to quit?"),
			wxT("Are you sure?"),
			wxICON_QUESTION | wxYES_NO) != wxYES)
		{
			evt.Veto();
			return;
		}
	}
	evt.Skip();
	this->SET_INSTANCE(false);
	this->GET_MAIN_INSTANCE()->SET_INSTANCE('C', false);
	// Closing Event
}

// =========================
//		REG EVENTS
// =========================
void REST_REG_UI::OnCloseWindow(wxCloseEvent& evt)
{
	if (evt.CanVeto())
	{
		if (wxMessageBox(wxT("Are you sure you want to quit?"),
			wxT("Are you sure?"),
			wxICON_QUESTION | wxYES_NO) != wxYES)
		{
			evt.Veto();
			return;
		}
	}
	evt.Skip();
	this->SET_INSTANCE(false);
	this->GET_MAIN_INSTANCE()->SET_INSTANCE('R', false);
}
void MANAGER_REG_UI::OnCloseWindow(wxCloseEvent& evt)
{
	if (evt.CanVeto())
	{
		if (wxMessageBox(wxT("Are you sure you want to quit?"),
			wxT("Are you sure?"),
			wxICON_QUESTION | wxYES_NO) != wxYES)
		{
			evt.Veto();
			return;
		}
	}
	evt.Skip();
	this->SET_INSTANCE(false);
	this->GET_MAIN_INSTANCE()->SET_INSTANCE('X', false);
}
void Landing::REST_REG_COMMAND(wxCommandEvent& evt)
{
	if (this->REST_REG_INSTANCE)
	{
		wxMessageBox(
			wxT("There is an instance already running, please quit every other instance running and try again."),
			wxT("INSTANCE ALREADY RUNNING!"), wxOK | wxICON_INFORMATION);
		evt.Skip();
		return;
	}
	else
	{
		REST_REGISTRATION = new REST_REG_UI(this);
		REST_REGISTRATION->Show();
		REST_REGISTRATION->SET_INSTANCE(true);
	}
}
void Landing::MAN_REG_COMMAND(wxCommandEvent& evt)
{
	if (this->MAN_REG_INSTANCE)
	{
		wxMessageBox(
			wxT("There is an instance already running, please quit every other instance running and try again."),
			wxT("INSTANCE ALREADY RUNNING!"), wxOK | wxICON_INFORMATION);
		evt.Skip();
		return;
	}
	else
	{
		MAN_REGISTRATION = new MANAGER_REG_UI(this);
		MAN_REGISTRATION->Show();
		MAN_REGISTRATION->SET_INSTANCE(TRUE);
		MAN_REGISTRATION->Update();
	}
}