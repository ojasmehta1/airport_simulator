/**
*  AirportServer.h
*  This class defines the methods called by the Airplanes
*/

#ifndef AIRPORT_SERVER_H
#define AIRPORT_SERVER_H

#include <mutex>
#include <random>
#include <condition_variable>
#include "AirportRunways.h"



class AirportServer
{
public:

	/**
	*  Default constructor for AirportServer class
	*/
	AirportServer()
	{
		// ***** Initialize any Locks and/or Condition Variables here as necessary *****
        lck4L = std::unique_lock<std::mutex>(run4L);
        lck4R = std::unique_lock<std::mutex>(run4R);
        lck15L = std::unique_lock<std::mutex>(run15L);
        lck15R = std::unique_lock<std::mutex>(run15R);
        lck9 = std::unique_lock<std::mutex>(run9);
        lck14 = std::unique_lock<std::mutex>(run14);

	} // end AirportServer default constructor


	  /**
	  *  Called by an Airplane when it wishes to land on a runway
	  */
	void reserveRunway(int airplaneNum, AirportRunways::RunwayNumber runway);

	/**
	*  Called by an Airplane when it is finished landing
	*/
	void releaseRunway(int airplaneNum, AirportRunways::RunwayNumber runway);


private:

	// Constants and Random number generator for use in Thread sleep calls
	static const int MAX_TAXI_TIME = 10; // Maximum time the airplane will occupy the requested runway after landing, in milliseconds
	static const int MAX_WAIT_TIME = 100; // Maximum time between landings, in milliseconds

	/**
	*  Declarations of mutexes and condition variables
	*/
	mutex runwaysMutex; // Used to enforce mutual exclusion for acquiring & releasing runways

	/**
	 *  ***** Add declarations of your own Locks and Condition Variables here *****
	 */
	std::mutex run4L;
	std::mutex run4R;
	std::mutex run15L;
	std::mutex run15R;
	std::mutex run9;
	std::mutex run14;

	std::unique_lock<std::mutex> lck4L;
	std::unique_lock<std::mutex> lck4R;
	std::unique_lock<std::mutex> lck15L;
	std::unique_lock<std::mutex> lck15R;
	std::unique_lock<std::mutex> lck9;
	std::unique_lock<std::mutex> lck14;

	std::condition_variable cv;
}; // end class AirportServer

#endif
