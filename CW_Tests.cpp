#include "pch.h"
#include "CppUnitTest.h"
#include "..\CW_\EdmondsKarp.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CWTests
{
	TEST_CLASS(CWTests)
	{
	public:
		
		TEST_METHOD(EdmondsKarp1)
		{
			int cntVertexes = 5;
			int cntEdge = 7;
			int** capacities = new int* [cntEdge];
			for (int i = 0; i < cntEdge; i++)
				capacities[i] = new int[cntEdge];
			int source = 0;
			int sink = cntVertexes - 1;

			capacities[0][1] = 5;
			capacities[0][2] = 1;
			capacities[2][1] = 7;
			capacities[1][3] = 6;
			capacities[3][2] = 5;
			capacities[1][4] = 3;
			capacities[3][4] = 2;

			/*SA5
			* SB1
			* BA7
			* AC6
			* CB5
			* AT3
			* CT2
			*/

			Assert::AreEqual(5, EdmodsKarp(cntVertexes, cntEdge, source, sink, capacities));
		}

		TEST_METHOD(EdmondsKarp2)
		{
			int cntVertexes = 8;
			int cntEdge = 11;
			int** capacities = new int* [cntEdge];
			for (int i = 0; i < cntEdge; i++)
				capacities[i] = new int[cntEdge];
			int source = 0;
			int sink = cntVertexes - 1;

			capacities[0][1] = 3;
			capacities[1][2] = 6;
			capacities[3][4] = 1;
			capacities[3][7] = 1;
			capacities[0][4] = 3;
			capacities[1][3] = 2;
			capacities[2][7] = 9;
			capacities[6][0] = 3;
			capacities[6][1] = 1;
			capacities[4][6] = 4;
			capacities[6][3] = 2;

			/*SD3
			* DF6
			* EB1
			* ET1
			* SB3
			* DE2
			* FT9
			* CS3
			* CD1
			* BC4
			* CE2
			*/

			Assert::AreEqual(5, EdmodsKarp(cntVertexes, cntEdge, source, sink, capacities));
		}

		TEST_METHOD(EdmondsKarp3)
		{
			int cntVertexes = 6;
			int cntEdge = 8;
			int** capacities = new int* [cntEdge];
			for (int i = 0; i < cntEdge; i++)
				capacities[i] = new int[cntEdge];
			int source = 0;
			int sink = cntVertexes - 1;

			capacities[0][1] = 3;
			capacities[0][2] = 3;
			capacities[1][3] = 3;
			capacities[1][2] = 2;
			capacities[2][4] = 2;
			capacities[3][4] = 4;
			capacities[3][5] = 2;
			capacities[4][5] = 3;

			/*
			* SO3
			* SP3
			* OQ3
			* OP2
			* PR2
			* QR4
			* QT2
			* RT3
			*/

			Assert::AreEqual(5, EdmodsKarp(cntVertexes, cntEdge, source, sink, capacities));
		}

	};
}
