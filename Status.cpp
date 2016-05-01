#include "Status.h"


Status::Status(int id, RenderWindow & window,std::string window_title,Font & font)
:type(id),pnt_window(&window),title(window_title),pnt_font(&font)
{
	
}


int Status::getStatusType() 
{
	return type;
}


