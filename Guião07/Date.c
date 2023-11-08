
// JMR, 2021

// Complete the functions (marked by ...)
// so that it passes all tests in DateTest.

#include "Date.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const Date DateMIN = {0, 1, 1};
const Date DateMAX = {9999, 12, 31};



static const uint8_t monthLength[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

static char strBuffer[64];

static char* fmts[] = {
    (char*)"%04d-%02d-%02d",        // YMD
    (char*)"%3$02d/%2$02d/%1$04d",  // DMY
    (char*)"%2$02d/%3$02d/%1$04d",  // MDY
};

// Função para verificar a invariante de um objeto Date.
static int invariant(Date *d) {
  return DateIsValid(d->year, d->month, d->day);
}

// Check if a yy, mm, dd tuple forms a valid date.
int DateIsValid(int yy, int mm, int dd) {
  return (DateMIN.year) <= yy && yy <= (DateMAX.year) && 1 <= mm && mm <= 12 &&
         1 <= dd && dd <= DateDaysInMonth(yy, mm);
}

int DateDaysInMonth(int yy, int mm) {
  int isLeap = DateIsLeapYear(yy);
  return monthLength[isLeap][mm - 1];
}

int DateIsLeapYear(int yy) {
  return (yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0;
} 

char* DateFormat(const Date* d, int FMT) {
  if (d == NULL)
    snprintf(strBuffer, sizeof(strBuffer), "NULL");
  else
    snprintf(strBuffer, sizeof(strBuffer), fmts[FMT], d->year, d->month,
             d->day);
  return strBuffer;
}

Date* DateCreate(int yy, int mm, int dd) {
  assert(DateIsValid(yy, mm, dd));

  Date* d = (Date*)malloc(sizeof(Date));
  if (d == NULL) {
    return NULL; // Alocação de memória falhou.
  }

  d->year = yy;
  d->month = mm;
  d->day = dd;

  assert(invariant(d));  // Verifique a invariante
  return d;
}

void DateDestroy(Date** pd) {
  assert(*pd != NULL);
  free(*pd);
  *pd = NULL;
}

Date* DateParse1(const char* str, int FMT) {
  int yy, mm, dd;
  int n = sscanf(str, fmts[FMT], &yy, &mm, &dd);
  Date* d = NULL;
  if (n == 3 && DateIsValid(yy, mm, dd)) {
    d = DateCreate(yy, mm, dd);
  }
  return d;
}

int DateParse(Date* d, const char* str, int FMT) {
  int yy, mm, dd;
  int n = sscanf(str, fmts[FMT], &yy, &mm, &dd);
  if (!(n == 3 && DateIsValid(yy, mm, dd))) return 0;
  d->year = yy;
  d->month = mm;
  d->day = dd;
  return 1;
}

int DateCompare(const Date* a, const Date* b) {
  if (a->year != b->year) {
    return a->year - b->year;
  }
  if (a->month != b->month) {
    return a->month - b->month;
  }
  return a->day - b->day;
}

void DateIncr(Date* d) {
  assert(DateCompare(d, &DateMAX) < 0);

  if (d->day < DateDaysInMonth(d->year, d->month)) {
    d->day++;
  } else {
    d->day = 1;
    if (d->month < 12) {
      d->month++;
    } else {
      d->month = 1;
      d->year++;
    }
  }

  assert(invariant(d));  // Verifique a invariante
}

void DateDecr(Date* d) {
  assert(DateCompare(d, &DateMIN) > 0);

  if (d->day > 1) {
    d->day--;
  } else {
    if (d->month > 1) {
      d->month--;
      d->day = DateDaysInMonth(d->year, d->month);
    } else {
      d->month = 12;
      d->year--;
      d->day = DateDaysInMonth(d->year, d->month);
    }

    assert(invariant(d));  // Verifique a invariante
  }
}

