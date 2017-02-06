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

