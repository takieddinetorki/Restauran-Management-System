#pragma once
#include <wx/wx.h>
#include <wx/richtooltip.h>
// ============================================================
//				User Interfaces Design
// ============================================================
class Landing;
class MANAGER_UI;
class CUSTOMER_UI;
class REST_REG_UI;
class MANAGER_REG_UI;
class LOGIN_UI;

class LOGIN_UI : public wxFrame
{
public:
	LOGIN_UI();
	~LOGIN_UI();
private:
};


class REST_REG_UI : public wxFrame
{
public:
	REST_REG_UI(Landing* MAIN_INSTANCE);
	~REST_REG_UI();
	void SET_INSTANCE(bool _state)
	{
		this->_instance = _state;
	}
	Landing* GET_MAIN_INSTANCE()
	{
		return MAIN_INSTANCE;
	}
private:
	void OnCloseWindow(wxCloseEvent& evt);
	bool _instance = false;
	Landing* MAIN_INSTANCE;
	wxButton* REG_ACTION_BUTTON;
	wxStaticText* REST_NAME_LABEL;
	wxStaticText* ADDRESS_LABEL;
	wxStaticText* _LABEL;
	wxDECLARE_EVENT_TABLE();
};

class MANAGER_REG_UI : public wxFrame
{
public:
	MANAGER_REG_UI(Landing* MAIN_INSTANCE);
	~MANAGER_REG_UI();
	void SET_INSTANCE(bool _state)
	{
		this->_instance = _state;
	}
	Landing* GET_MAIN_INSTANCE()
	{
		return MAIN_INSTANCE;
	}
private:
	void OnCloseWindow(wxCloseEvent& evt);
	bool _instance = false;
	Landing* MAIN_INSTANCE;
	wxDECLARE_EVENT_TABLE();
};

class MANAGER_UI : public wxFrame
{
public:
	MANAGER_UI();
	MANAGER_UI(Landing*);
	~MANAGER_UI();
	Landing* GET_MAIN_INSTANCE()
	{
		return MAIN_INSTANCE;
	}
	void SET_MANAGER_INSTANCE(bool _state)
	{
		MANAGER_INSTANCE = _state;
	}
private:
	/*Menu bar*/
	wxMenuBar* menubar;
	wxMenu* help;
	wxMenu* signout;
	Landing* MAIN_INSTANCE;
	bool MANAGER_INSTANCE = false;

	void OnCloseWindow(wxCloseEvent& evt);
	
	wxDECLARE_EVENT_TABLE();
}; // Manager user interface called from MANAGER_EVENT_CALL function

class CUSTOMER_UI : public wxFrame
{
public:
	CUSTOMER_UI();
	CUSTOMER_UI(Landing*);
	~CUSTOMER_UI();
	Landing* GET_MAIN_INSTANCE()
	{
		return MAIN_INSTANCE;
	}
	void SET_INSTANCE(bool _state)
	{
		CUSTOMER_INSTANCE = _state;
	}
private:
	/*Menu bar*/
	wxMenuBar* menubar;
	wxMenu* file;
	Landing* MAIN_INSTANCE;
	bool CUSTOMER_INSTANCE = false;

	void OnCloseWindow(wxCloseEvent& evt);

	wxDECLARE_EVENT_TABLE();
}; // Manager user interface called from MANAGER_EVENT_CALL function

// Landing class: Basically prompts the user to choose between either a manager or a customer
class Landing : public wxFrame
{
public:
	void SET_INSTANCE(char type,bool _state)
	{
		switch (type)
		{
		case 'M':
			this->MANAGER_INSTANCE = _state;
			break;
		case 'C':
			this->CUSTOMER_INSTANCE = _state;
			break;
		case 'R':
			this->REST_REG_INSTANCE = _state;
			break;
		case 'X':
			this->MAN_REG_INSTANCE = _state;
			break;
		default:
			break;
		}
	}

	bool GET_INSTANCE(char type, bool _state)
	{
		switch (type)
		{
		case 'M':
			return this->MANAGER_INSTANCE = _state;
		case 'C':
			return this->CUSTOMER_INSTANCE = _state;
		case 'R':
			return this->REST_REG_INSTANCE = _state;
		case 'X':
			return this->MAN_REG_INSTANCE = _state;
		default:
			break;
		}
	}
	Landing();
	~Landing() { delete tips; }
private:
	// Elemnts of the dialog goes here. Just a few we have
	wxButton* Manager;
	wxButton* Customer;
	wxMenuBar* bar;
	wxMenu* REGISTER;
	// UIs calls
	MANAGER_UI* MANAGER;
	CUSTOMER_UI* CUSTOMER;
	MANAGER_REG_UI* MAN_REGISTRATION;
	REST_REG_UI* REST_REGISTRATION;
	wxRichToolTip* tips;
	bool MANAGER_INSTANCE = false;
	bool CUSTOMER_INSTANCE = false;
	bool MAN_REG_INSTANCE = false;
	bool REST_REG_INSTANCE = false;
	void OnCloseWindow(wxCloseEvent& evt);
	void MANAGER_EVENT_CALL(wxCommandEvent& evt);
	void CUSTOMER_EVENT_CALL(wxCommandEvent& evt);
	void REST_REG_COMMAND(wxCommandEvent& evt);
	void MAN_REG_COMMAND(wxCommandEvent& evt);
	void ShowToolTip(wxMouseEvent& evt);
	wxDECLARE_EVENT_TABLE();
}; // Landing page

