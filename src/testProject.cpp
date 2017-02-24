//============================================================================
// Name        : testProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "gtest/gtest.h"
#include "Buffer.h"

class BufferTest : public ::testing::Test
{
protected:
  BufferTest()
  {
    // Do set-up work for each test here.
  }

  virtual ~BufferTest()
  {
    // Do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:
  //
  virtual void SetUp() 
  {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() 
  {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case
  Buffer buffer;
  Buffer::Error err;
  static constexpr int N = 16;
};



TEST_F(BufferTest, A1)
{
    err = buffer.add(1);

    ASSERT_EQ(err,Buffer::OK);
}

TEST_F(BufferTest, A2)
{
    err = buffer.add(1);
    err = buffer.add(2);
    ASSERT_EQ(err,Buffer::OK);
}

TEST_F(BufferTest, A3)
{
    for(int i = 0; i < N; ++i) {
        err = buffer.add(i);
        ASSERT_EQ(err,Buffer::OK);
    }
    err = buffer.add(1);

    ASSERT_EQ(err,Buffer::FULL);
}



TEST_F(BufferTest, G1)
{
    int data;
    err = buffer.get(data);

    ASSERT_EQ(err,Buffer::EMPTY);
}

TEST_F(BufferTest, G2)
{
  int value = 1;
  buffer.add(value);
  int data;
  err = buffer.get(data);

  ASSERT_EQ(err,Buffer::OK);
  ASSERT_EQ(value,data);
}

TEST_F(BufferTest, G3)
{
    for(int i = 0; i < N; ++i) {
        err = buffer.add(i);
        ASSERT_EQ(err,Buffer::OK);
    }
  int data;
  err = buffer.get(data);

  ASSERT_EQ(err,Buffer::OK);
}

/*

TEST_F(BufferTest, test_initial_condition)
{
    ASSERT_EQ(true,buffer.isEmpty());
}

TEST_F(BufferTest, test_initial_put)
{
    err = buffer.add(1);

    ASSERT_EQ(err,Buffer::OK);
    ASSERT_EQ(false,buffer.isEmpty());
}

TEST_F(BufferTest, test_initial_get)
{
    int data;
    err = buffer.get(data);

    ASSERT_EQ(err,Buffer::EMPTY);
}

TEST_F(BufferTest, test_initial_putget)
{
    err = buffer.add(1);
    int data;
    err = buffer.get(data);

    ASSERT_EQ(err,Buffer::OK);
    ASSERT_EQ(true,buffer.isEmpty());
    ASSERT_EQ(1,data);
}


TEST_F(BufferTest, test_initial_buffer_full)
{
    for(int i = 0; i < 16; ++i) {
        err = buffer.add(i);
        ASSERT_EQ(err,Buffer::OK);
    }
    err = buffer.add(1);

    ASSERT_EQ(err,Buffer::FULL);
}

TEST_F(BufferTest, test_initial_buffer_full_to_empty)
{
    int data;

    for(int i = 0; i < 10; ++i) {
        err = buffer.add(i);
        ASSERT_EQ(err,Buffer::OK);
    }
    for(int i = 0; i < 8; ++i) {
        err = buffer.get(data);
        ASSERT_EQ(err,Buffer::OK);
        ASSERT_EQ(i,data);
    }
    for(int i = 10; i < 18; ++i) {
        err = buffer.add(i);
        ASSERT_EQ(err,Buffer::OK);
    }
    for(int i = 8; i < 18; ++i) {
        err = buffer.get(data);
        ASSERT_EQ(err,Buffer::OK);
        ASSERT_EQ(i,data);
    }

    err = buffer.get(data);
    ASSERT_EQ(err,Buffer::EMPTY);


}

*/
