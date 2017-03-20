/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

Piezas pie;

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}


TEST(PiezasTest, outofboundscheck1)
{
	ASSERT_TRUE(pie.dropPiece(4) == Invalid);
}

TEST(PiezasTest, outofboundscheck2)
{
	ASSERT_TRUE(pie.dropPiece(-1) == Invalid);
}

TEST(PiezasTest, placecheck1)
{
	ASSERT_TRUE(pie.dropPiece(0) == X); //x
}

TEST(PiezasTest, placecheck2)
{
	ASSERT_TRUE(pie.dropPiece(0) == O); //o
}

TEST(PiezasTest, placecheck3)
{
  pie.dropPiece(0); //x
	ASSERT_TRUE(pie.dropPiece(0) == Blank);//o
}

TEST(PiezasTest, getcheck1)
{
	ASSERT_TRUE(pie.pieceAt(0,0) == X);
}

TEST(PiezasTest, getcheck2)
{
	ASSERT_TRUE(pie.pieceAt(1,0) == O);
}

TEST(PiezasTest, getcheck3)
{
	ASSERT_TRUE(pie.pieceAt(2,0) == X);
}

TEST(PiezasTest, getoobcheck)
{
	ASSERT_TRUE(pie.pieceAt(3,0) == Invalid);
}

TEST(PiezasTest, resetcheck)
{
  pie.reset();
	ASSERT_TRUE(pie.pieceAt(0,0) == Blank);
}

TEST(PiezasTest, gamestatecheck)
{
  pie.dropPiece(0); //x
  pie.dropPiece(0); //o
	ASSERT_TRUE(pie.gameState() == Invalid);
}

TEST(PiezasTest, tiecheck)
{
  pie.reset();
  pie.dropPiece(0); //x
  pie.dropPiece(1); //o
  pie.dropPiece(2); //x
  pie.dropPiece(3); //o
  pie.dropPiece(0); //x
  pie.dropPiece(1); //o
  pie.dropPiece(2); //x
  pie.dropPiece(3); //o
  pie.dropPiece(0); //x
  pie.dropPiece(1); //o
  pie.dropPiece(2); //x
  pie.dropPiece(3); //o
	ASSERT_TRUE(pie.gameState() == Blank);
}

TEST(PiezasTest, Xwinverticheck)
{
  pie.reset();
  pie.dropPiece(0); //x
  pie.dropPiece(1); //o
  pie.dropPiece(2); //x
  pie.dropPiece(3); //o
  pie.dropPiece(0); //x
  pie.dropPiece(1); //o
  pie.dropPiece(2); //x
  pie.dropPiece(3); //o
  pie.dropPiece(0); //x
  pie.dropPiece(0); //o
  pie.dropPiece(2); //x
  pie.dropPiece(2); //o
  pie.dropPiece(1); //x
  pie.dropPiece(2); //o
  pie.dropPiece(3); //x
	ASSERT_TRUE(pie.gameState() == X);
}


