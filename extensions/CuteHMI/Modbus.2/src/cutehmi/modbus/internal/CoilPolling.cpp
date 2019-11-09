#include <cutehmi/modbus/internal/CoilPolling.hpp>

#include <cutehmi/modbus/AbstractDevice.hpp>

namespace cutehmi {
namespace modbus {
namespace internal {

CoilPolling::CoilPolling(AbstractDevice * device, QUuid * requestId):
	Parent(device, requestId)
{
}

const CoilPolling::DataContainer & CoilPolling::container() const
{
	return coilData(device());
}

const CoilPolling::Data * CoilPolling::dataAt(quint16 address) const
{
	return coilData(device()).at(address);
}

void CoilPolling::requestReadData(quint16 address, quint16 amount, QUuid * requestId)
{
	device()->requestReadCoils(address, amount, requestId);
}

int CoilPolling::maxRead() const
{
	return device()->maxReadCoils();
}

}
}
}

//(c)C: Copyright © 2019, Michał Policht <michal@policht.pl>. All rights reserved.
//(c)C: This file is a part of CuteHMI.
//(c)C: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)C: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)C: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
