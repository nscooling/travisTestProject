//============================================================================
// Name        : testProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "gtest/gtest.h"
#include "Buffer.h"

TEST(buffer_test, test_initial_condition)
{
    Buffer buffer;
    //Buffer::Error err;

    ASSERT_EQ(true,buffer.isEmpty());
}

TEST(buffer_test, test_initial_put)
{
    Buffer buffer;
    Buffer::Error err = buffer.add(1);

    ASSERT_EQ(err,Buffer::OK);
    ASSERT_EQ(false,buffer.isEmpty());
}

TEST(buffer_test, test_initial_get)
{
    Buffer buffer;
    int data;
    Buffer::Error err = buffer.get(data);
    ASSERT_EQ(err,Buffer::EMPTY);
}

TEST(buffer_test, test_initial_putget)
{
    Buffer buffer;
    Buffer::Error err = buffer.add(1);
    int data;
    err = buffer.get(data);
    ASSERT_EQ(err,Buffer::OK);
    ASSERT_EQ(true,buffer.isEmpty());
    ASSERT_EQ(1,data);
}
