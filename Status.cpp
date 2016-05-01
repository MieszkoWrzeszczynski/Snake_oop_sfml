#include "Status.h"


Status::Status(int id, RenderWindow & window,Font& font):type(id),pnt_window(&window), pnt_font(&font)
{
	
}


int Status::getStatusType() 
{
	return type;
}


