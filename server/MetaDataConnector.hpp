/* This file is part of ISAAC.
 *
 * ISAAC is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ISAAC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ISAAC.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef __METADATACONNECTOR
#define __METADATACONNECTOR

#include "Common.hpp"
#include <string>
#include "ThreadList.hpp"
#include "Runable.hpp"
#include "MessageAble.hpp"
#include "Master.hpp"
class Master;

/** This class is used for the connection between the isaac server and
 * some frontend. It defines and abstracts an interface isaac will use.*/
class MetaDataConnector : public Runable, public MessageAble
{
	public:
		//To be overwritten
		virtual errorCode init(int port) = 0;
		virtual errorCode run() = 0;
		virtual std::string getName() = 0;

		//Called from the Master
		void setMaster(Master* master);		
	protected:
		Master* master;
};

#endif