/**
  ******************************************************************************
  * @file    unittest.h
  * @author  Kevin Gao
  * @version V1.0.0
  * @date    26-October-2022
  * @brief   This file provides all unint test functions.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 Kevin Gao.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef __UNIT_TEST_H__
#define __UNIT_TEST_H__

#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct
{
	const char *tg;
	const char *tc;
	void (*setup)(void);
	void (*teardown)(void);
	void (*testcase)(void);
}testcase;

#define __SETUP(tg)			void __##tg##_setup()
#define __TEARDOWN(tg)		void __##tg##_teardown()

#define __TESTCASE(tg,tc)	void __##tg##tc##_testcase(void);				\
							void __##tg##_setup(void);						\
							void __##tg##_teardown(void);					\
							const static testcase __##tg##_##tc##_testcase	\
								__attribute__((used,section("testcase")))	\
								={#tg,#tc,__##tg##_setup,__##tg##_teardown,	\
								__##tg##tc##_testcase};						\
							void __##tg##tc##_testcase(void)

#define _SETUP(tg)			__SETUP(tg)
#define _TEARDOWN(tg)		__TEARDOWN(tg)
#define _TESTCASE(tg,tc)	__TESTCASE(tg,tc)

#define SETUP()				_SETUP(_GROUP_)
#define TEARDOWN()			_TEARDOWN(_GROUP_)
#define TEST(tc)			_TESTCASE(_GROUP_,tc)


#define UT_INT_EQUAL(actual,expected)										\
do{																			\
	if(ut_int_equal((actual),(expected)))									\
	{																		\
		printf("expected is %d but %d\n",(expected),(actual));				\
		return;																\
	}																		\
}while(0)

#define UT_STRING_EQUAL(actual,expected)									\
do{																			\
	if(ut_string_equal((actual),(expected)))								\
	{																		\
		printf("expected is \"%s\" but \"%s\"\n",(expected),(actual));		\
		return;																\
	}																		\
}while(0)

#define UT_FLOAT_EQUAL(actual,expected,delta)								\
do{																			\
	if(ut_float_equal((actual),(expected),(delta)))							\
	{																		\
		printf("expected is %lf but %lf\n",(expected),(actual));			\
		return;																\
	}																		\
}while(0)



void testmain(int argc,const char **argv);
uint8_t ut_int_equal(int expected,int actual);
uint8_t ut_string_equal(const char *expected,const char *actual);
uint8_t ut_float_equal(double expected,double actual,double delta);
#endif
