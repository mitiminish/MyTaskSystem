#include "AddDxlibTable.h"

void CAddDxlibTable::init(){

}

void CAddDxlibTable::exec(){

}



CAddDxlibTable::CAddDxlibTable()
{
	std::vector<std::vector<std::string>> data;
	{
		typedef std::vector<std::string> g;
		typedef std::vector<g> s;
		s buf{
			g{ "Circle" },
			g{ "text" },
		};
		std::copy(buf.begin(), buf.end(), back_inserter(data));
	}
	this->setStrArray(data);
	this->setXY(100, 100);
	this->setXYMargin(20, 20);

}


CAddDxlibTable::~CAddDxlibTable()
{
}
