#include <cutehmi/ExtensionInitializer.hpp>

#include <QtTest/QtTest>

namespace cutehmi {

class InitializerMock:
	public ExtensionInitializer<InitializerMock>
{
	public:
		InitializerMock();

		static int InitCtr;
		static int DeinitCtr;
		static int CtorCtr;
};

int InitializerMock::InitCtr = 0;
int InitializerMock::DeinitCtr = 0;
int InitializerMock::CtorCtr = 0;

InitializerMock::InitializerMock():
	ExtensionInitializer<InitializerMock>(
		[]() {
			InitCtr++;
		},
		[]() {
			DeinitCtr++;
		}
	)
{
	CtorCtr++;
}

class test_ExtensionInitializer:
	public QObject
{
	Q_OBJECT

	private slots:
		void instances();
};

void test_ExtensionInitializer::instances()
{
	QVERIFY(InitializerMock::InitCtr == 0);
	QVERIFY(InitializerMock::DeinitCtr == 0);
	QVERIFY(InitializerMock::CtorCtr == 0);

	{
		InitializerMock instance1;
		QCOMPARE(InitializerMock::InitCtr, 1);
		QCOMPARE(InitializerMock::DeinitCtr, 0);
		QCOMPARE(InitializerMock::CtorCtr, 1);

		InitializerMock instance2;
		QCOMPARE(InitializerMock::InitCtr, 1);
		QCOMPARE(InitializerMock::DeinitCtr, 0);
		QCOMPARE(InitializerMock::CtorCtr, 2);
	}

	QCOMPARE(InitializerMock::InitCtr, 1);
	QCOMPARE(InitializerMock::DeinitCtr, 1);
	QCOMPARE(InitializerMock::CtorCtr, 2);
}

}

QTEST_MAIN(cutehmi::test_ExtensionInitializer)
#include "test_ExtensionInitializer.moc"

//(c)MP: Copyright © 2019, Michal Policht <michpolicht@gmail.com>. All rights reserved.
//(c)MP: This file is a part of CuteHMI.
//(c)MP: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)MP: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)MP: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.