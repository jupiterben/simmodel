#include "Event.h"
#include <algorithm>
#include <cassert>

NSBEGIN(Sim)

void Model::Run()
{

	m_bCanceled = false;
	curTime = Time();

	while(Event* e = popEvent())
	{
		curTime = e->getTime();

		e->Process(this);

		if(e->IsAutoDelete())
			delete e;

		if(m_bCanceled)
			break;
	}

	//
	while(Event* e = popEvent())
	{
		e->Cancel(this);
		if(e->IsAutoDelete())
			delete e;
	}
}

struct EventLess
{
	bool operator()(Event* e1, Event* e2)const
	{
		return e1->getTime() < e2->getTime();
	}
};
void Model::addEvent(Event* e)
{
	if(e->getTime()<curTime)
		throw Exception();

	EventList::iterator addpos = std::upper_bound(m_eventlist.begin(),m_eventlist.end(),e, EventLess() );
	m_eventlist.insert(addpos,e);
	e->m_bInList = true;
}

Event* Model::popEvent()
{
	if(m_eventlist.empty())
		return 0;
	Event* e = m_eventlist.front();
	e->m_bInList = false;
	m_eventlist.erase(m_eventlist.begin());
	return e;
}

void Model::removeEvent(Event* e)
{
	EventList::iterator itr = std::find(m_eventlist.begin(),m_eventlist.end(),e);
	if(itr!=m_eventlist.end())
	{
		m_eventlist.erase(itr);
	}
	
}

void Event::setTime(const Time& t)
{
	if(m_bInList)
	{
		throw Exception();
	}
	
	m_t = t;
}

NSEND
