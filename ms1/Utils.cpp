#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Utils.h"
using namespace std;
namespace sdds {
   Utils ut; // The ut object of type Utils that is accessible to any file including "Utils.h" to call the Utils methods

   void Utils::testMode(bool testmode) {
      m_testMode = testmode;
   }
   void Utils::getSystemDate(int* year, int* mon, int* day) {
      if (m_testMode) {
         if(day) *day = sdds_testDay;
         if(mon) *mon = sdds_testMon;
         if(year) *year = sdds_testYear;
      }
      else {
         time_t t = std::time(NULL);
         tm lt = *localtime(&t);
         if (day) *day = lt.tm_mday;
         if (mon) *mon = lt.tm_mon + 1;
         if (year) *year = lt.tm_year + 1900;
      }
   }
   int Utils::daysOfMon(int month, int year)const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = (month >= 1 && month <= 12 ? month : 13)-1;
      return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
   }
  
   void Utils::alocpy(char*& destination, const char* source) {
       if (source) {
           destination = new char[strlen(source) + 1];
           strcpy(destination, source);
       }
       else {
           destination = nullptr; // Source is null, so destination is set to null
       }
   }

   int Utils::getint(const char* prompt) {
       int value;
       bool success = false;
       do {
           if (prompt) {
               cout << prompt;
           }
           if (!(cin >> value)) {
               cout << "Invalid Integer, retry: ";
               cin.clear();
               cin.ignore(1000, '\n');
           }
           else {
               success = true;
           }
       } while (!success);
       return value;
   }

   int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
       int value;
       bool success = false;
       do {
           if (prompt) {
               cout << prompt;
           }
           if (!(cin >> value) || value < min || value > max) {
               if (errMes) {
                   cout << errMes << ", retry: ";
               }
               else {
                   cout << "Value out of range [" << min << "<=val<=" << max << "], retry: ";
               }
               cin.clear();
               cin.ignore(1000, '\n');
           }
           else {
               success = true;
           }
       } while (!success);
       return value;
   }
}