#pragma once
#include "cpputil.h"



NSBEGIN(Sim)

	class Model;	
	class Time
	{
	public:
		Time():m_t(0L){}
		Time(long milsec):m_t(milsec){}
		double asSecond()const{ return m_t/1000.0; }
		bool operator<(const Time& t)const
		{
			return m_t < t.m_t;
		}
		
	protected:
		long m_t;
	};

	class Event
	{
		friend class Model;
	public:
		virtual void Process(Model* m)=0;
		virtual void Cancel(Model * m)=0;

		const Time& getTime()const{ return m_t; }
		void setTime(const Time& t);

		virtual bool IsAutoDelete()const;
	protected:
		Event():m_bInList(false){}
		Time m_t;
		bool m_bInList; //
		
	};

	class Model
	{

	public:
		void Run();
		void addEvent(Event* e);
		void removeEvent(Event* e);
		
	protected:
		typedef std::vector<Event*> EventList;
		EventList m_eventlist;
		bool m_bCanceled;

		Event* popEvent();
		Time curTime;
		
	};


	class Exception
	{
	public:

	};
NSEND
