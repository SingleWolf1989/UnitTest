/**
  ******************************************************************************
  * @file    unittest.c
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

#include "unittest.h"
#include <math.h>

#define start testcase$$Base
#define end testcase$$Limit

extern testcase start;
extern testcase end;

uint32_t tctotal=0,tcfalse=0;

void testmain(int argc,const char **argv)
{
	const char *tg = NULL;
	
	printf("================ Start testing ==================\n");
	for(testcase *tc = &start;tc<&end;tc++)
	{
		if(tg != tc->tg)
		{
			printf("GROUP %s \n",tc->tg);
			tg = tc->tg;
		}
		tctotal++;
		printf("TEST(%s) ==> ",tc->tc);
		tc->setup();
		tc->testcase();
		tc->teardown();
	}
	
	printf("================  End testing  ==================\n");
	printf("total testcase %d,falsed %d.\n",tctotal,tcfalse);
}

uint8_t ut_int_equal(int expected,int actual)
{
	if(expected != actual)
	{
		tcfalse++;
		return 1;
	}
	else
	{
		printf("passed\n");
		return 0;
	}
}

uint8_t ut_string_equal(const char *expected,const char *actual)
{
	if(strlen(actual)!=strlen(expected) ||									\
		strncmp((actual),(expected),strlen(expected)))
	{
		tcfalse++;
		return 1;
	}
	else
	{
		printf("passed\n");
		return 0;
	}
}

uint8_t ut_float_equal(double expected,double actual,double delta)
{
	if(fabs(expected-actual)>delta)
	{
		tcfalse++;
		return 1;
	}
	else
	{
		printf("passed\n");
		return 0;
	}
}

