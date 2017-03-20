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
  pie.dropPiece(4);
	ASSERT_TRUE(Invalid);
}

TEST(PiezasTest, outofboundscheck2)
{
  pie.dropPiece(-1);
	ASSERT_TRUE(Invalid);
}

TEST(PiezasTest, placecheck1)
{
  pie.dropPiece(0); //x
	ASSERT_TRUE(X);
}

TEST(PiezasTest, placecheck2)
{
  pie.dropPiece(0); //o
	ASSERT_TRUE(O);
}

TEST(PiezasTest, placecheck3)
{
  pie.dropPiece(0); //x
  pie.dropPiece(0); //o
	ASSERT_TRUE(Blank);
}

TEST(PiezasTest, getcheck1)
{
  pie.pieceAt(0,0);
	ASSERT_TRUE(X);
}

TEST(PiezasTest, getcheck2)
{
  pie.pieceAt(1,0);
	ASSERT_TRUE(O);
}

TEST(PiezasTest, getcheck3)
{
  pie.pieceAt(2,0);
	ASSERT_TRUE(X);
}

TEST(PiezasTest, getoobcheck)
{
  pie.pieceAt(3,0);
	ASSERT_TRUE(Invalid);
}

TEST(PiezasTest, resetcheck)
{
  pie.reset();
  pie.pieceAt(0,0);
	ASSERT_TRUE(Blank);
}

TEST(PiezasTest, gamestatecheck)
{
  pie.dropPiece(0); //x
  pie.gameState();
	ASSERT_TRUE(Invalid);
}

TEST(PiezasTest, tiecheck)
{
  pie.dropPiece(1); //o
  pie.dropPiece(0); //x
  pie.dropPiece(1); //o
  pie.dropPiece(0); //x
  pie.dropPiece(1); //o
  pie.gameState();
	ASSERT_TRUE(Blank);
}

TEST(PiezasTest, Xwinverticheck)
{
  pie.reset();
  pie.dropPiece(0); //x
  pie.dropPiece(1); //o
  pie.dropPiece(0); //x
  pie.dropPiece(2); //o
  pie.dropPiece(0); //x
  pie.gameState();
	ASSERT_TRUE(X);
}

TEST(PiezasTest, Owinhoricheck)
{
  pie.reset();
  pie.dropPiece(0); //o
  pie.dropPiece(0); //x
  pie.dropPiece(1); //o
  pie.dropPiece(0); //x
  pie.dropPiece(2); //o
  pie.dropPiece(1); //x
  pie.dropPiece(3); //o
  pie.gameState();
	ASSERT_TRUE(O);
}
