#include "Status.h"

Status::Status(int status_type, RenderWindow & window,std::string window_title,Font & font)
:type(status_type),pnt_window(&window),title(window_title),pnt_font(&font)
{
	
}


int Status::getStatusType() 
{
	return type;
}


