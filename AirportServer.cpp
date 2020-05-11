#include <iostream>
#include <thread>
#include <condition_variable>

#include "AirportServer.h"


/**
*  Called by an Airplane when it wishes to land on a runway
*/
void AirportServer::reserveRunway(int airplaneNum, AirportRunways::RunwayNumber runway)
{
    // Acquire runway(s)
    {  // Begin critical region

        //		unique_lock<mutex> runwaysLock(runwaysMutex);

        {
            unique_lock<mutex> lk(AirportRunways::checkMutex);
            cv.wait(lk, []{
                return !(AirportRunways::getNumLandingRequests()>=6);
            });
            cout << "Airplane #" << airplaneNum << " is acquiring any needed runway(s) for landing on Runway "
                << AirportRunways::runwayName(runway) << endl;
            
            AirportRunways::incNumLandingRequests();
        }

        /**
         *  ***** Add your synchronization here! *****
         */
        /*		
                bool av4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L]==0);
                bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                bool av15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L]==0);
                bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                bool av9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9]==0);
            bool av14 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_14]==0);
        */
        switch(runway){
            case AirportRunways::RUNWAY_4L :
                cv.wait(lck4L, [=]{
                    bool av4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L]==0);
                    bool av15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    if(av4L && av15L && av15R) 
                        return true;
                    else
                        return false;
                });
                cv.wait(lck15L, [=]{
                    bool av4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L]==0);
                    bool av15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    if(av4L && av15L && av15R) 
                        return true;
                    else 
                        return false;
                });
                cv.wait(lck15R, [=]{
                    bool av4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L]==0);
                    bool av15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    if(av4L && av15L && av15R) 
                        return true;
                    else 
                        return false;
                });
                //run4L.lock();
                //run15L.lock();
                //run15R.lock();
                break;
            case AirportRunways::RUNWAY_4R :
                cv.wait(lck4R, [=]{
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    bool av9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9]==0);
                    if(av4R && av15L && av15R && av9) 
                    return true;
                    else 
                    return false;
                });
                cv.wait(lck15L, [=]{
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    bool av9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9]==0);
                    if(av4R && av15L && av15R && av9) 
                    return true;
                    else
                    return false;
                });
                cv.wait(lck15R, [=]{
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    bool av9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9]==0);
                    if(av4R && av15L && av15R && av9) 
                    return true;
                    else 
                    return false;
                });
                cv.wait(lck9, [=]{
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    bool av9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9]==0);
                    if(av4R && av15L && av15R && av9) 
                    return true;
                    else 
                    return false;
                });
                //run4R.lock();
                //run15L.lock();
                //run15R.lock();
                //run9.lock();
                break;
            case AirportRunways::RUNWAY_15R :
                cv.wait(lck4L, [=]{
                    bool av4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L]==0);
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    bool av9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9]==0);
                    if(av4L && av4R && av15R && av9) 
                    return true;
                    else 
                    return false;
                });
                cv.wait(lck4R, [=]{
                    bool av4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L]==0);
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    bool av9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9]==0);
                    if(av4L && av4R && av15R && av9) return true;
                    else return false;
                });
                cv.wait(lck15R, [=]{
                    bool av4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L]==0);
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    bool av9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9]==0);
                    if(av4L && av4R && av15R && av9) return true;
                    else return false;
                });
                cv.wait(lck9, [=]{
                    bool av4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L]==0);
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    bool av9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9]==0);
                    if(av4L && av4R && av15R && av9) 
                    return true;
                    else 
                    return false;
                });
                //run4L.lock();
                //run4R.lock();
                //run15R.lock();
                //run9.lock();
                break;
            case AirportRunways::RUNWAY_15L :
                cv.wait(lck4L, [=]{
                    bool av4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L]==0);
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L]==0);
                    if(av4L && av4R && av15L) 
                        return true;
                    else 
                        return false;
                });
                cv.wait(lck4R, [=]{
                    bool av4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L]==0);
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L]==0);
                    if(av4L && av4R && av15L) 
                        return true;
                    else 
                        return false;
                });
                cv.wait(lck15L, [=]{
                    bool av4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L]==0);
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L]==0);
                    if(av4L && av4R && av15L) 
                        return true;
                    else 
                        return false;
                });
                //run4L.lock();
                //run4R.lock();
                //run15L.lock();
                break;
            case AirportRunways::RUNWAY_9 :
                cv.wait(lck4R, [=]{
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    bool av9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9]==0);
                    if(av4R && av15R && av9) 
                        return true;
                    else 
                        return false;
                });
                cv.wait(lck15R, [=]{
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    bool av9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9]==0);
                    if(av4R && av15R && av9) 
                        return true;
                    else 
                        return false;
                });
                cv.wait(lck9, [=]{
                    bool av4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R]==0);
                    bool av15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R]==0);
                    bool av9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9]==0);
                    if(av4R && av15R && av9) 
                        return true;
                    else 
                        return false;
                });
                //run4R.lock();
                //run15R.lock();
                //run9.lock();
                break;
            case AirportRunways::RUNWAY_14 :
                cv.wait(lck4L, [=]{
                    bool av14 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_14]==0);
                    if(av14) 
                        return true;
                    else 
                        return false;
                });
                //run14.lock();
                break;
        }
        // Check status of the airport for any rule violations
        AirportRunways::checkAirportStatus(runway);

    //runwaysLock.unlock();

    } // End critical region

    // obtain a seed from the system clock:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // Taxi for a random number of milliseconds
    std::uniform_int_distribution<int> taxiTimeDistribution(1, MAX_TAXI_TIME);
    int taxiTime = taxiTimeDistribution(generator);

    {
        lock_guard<mutex> lk(AirportRunways::checkMutex);

        cout << "Airplane #" << airplaneNum << " is taxiing on Runway " << AirportRunways::runwayName(runway)
            << " for " << taxiTime << " milliseconds\n";
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(taxiTime));

} // end AirportServer::reserveRunway()


/**
 *  Called by an Airplane when it is finished landing
 */
void AirportServer::releaseRunway(int airplaneNum, AirportRunways::RunwayNumber runway)
{
	// Release the landing runway and any other needed runways
	{ // Begin critical region

    //unique_lock<mutex> runwaysLock(runwaysMutex);

		{
			lock_guard<mutex> lk(AirportRunways::checkMutex);

			cout << "Airplane #" << airplaneNum << " is releasing any needed runway(s) after landing on Runway "
				 << AirportRunways::runwayName(runway) << endl;
		}

		/**
		*  ***** Add your synchronization here! *****
		*/
    switch(runway){
        case AirportRunways::RUNWAY_4L :
			run4L.unlock();
			run15L.unlock();
			run15R.unlock();
			break;
        case AirportRunways::RUNWAY_4R :
			run4R.unlock();
			run15L.unlock();
			run15R.unlock();
			run9.unlock();
            break;
        case AirportRunways::RUNWAY_15R :
			run4L.unlock();
			run4R.unlock();
			run15R.unlock();
			run9.unlock();
            break;
        case AirportRunways::RUNWAY_15L :
			run4L.unlock();
			run4R.unlock();
			run15L.unlock();
            break;
        case AirportRunways::RUNWAY_9 :
			run4R.unlock();
			run15R.unlock();
			run9.unlock();
            break;
        case AirportRunways::RUNWAY_14 :
			run14.unlock();
            break;
    }
    AirportRunways::decNumLandingRequests();
    cv.notify_one();
		// Update the status of the airport to indicate that the landing is complete
		AirportRunways::finishedWithRunway(runway);

    //runwaysLock.unlock();

	} // End critical region

	// obtain a seed from the system clock:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	// Wait for a random number of milliseconds before requesting the next landing for this Airplane
	std::uniform_int_distribution<int> waitTimeDistribution(1, MAX_WAIT_TIME);
	int waitTime = waitTimeDistribution(generator);

	{
		lock_guard<mutex> lk(AirportRunways::checkMutex);

		cout << "Airplane #" << airplaneNum << " is waiting for " << waitTime << " milliseconds before landing again\n";
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));

} // end AirportServer::releaseRunway()
