//
//  Solver.h
//  EASYABC
//
//  Created by Chris Benka on 4/25/16.
//  Copyright © 2016 Chris Benka. All rights reserved.
//
#include <stdbool.h>
#ifndef Solver_h
#define Solver_h
#include <stdio.h>

void setGrid(char *onegrid);
bool checkOneRow();
bool checkOneCol();
bool checkElse();
void findSol();
char returnFinal();

#endif /* Solver_h */
