#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
   const int sdds_testYear = 2023;
   const int sdds_testMon = 12;
   const int sdds_testDay = 9;

   class Utils {
      bool m_testMode = false;
   public:
       // this function will be used to get the current system date or the test date if m_testMode is true
      void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
      // this function will return the number of days in a month based on the year
      // 1<=mon<=12  year: four digit number (example: 2023)
      int daysOfMon(int mon, int year)const;
      // Puts the system date in test mode, where getSystemDate() function will return 2023, 12, 09
      // or whatever the three constant test dates are set to
      void testMode(bool testmode = true);

      void alocpy(char*& destination, const char* source);
   
      int getint(const char* prompt);

      int getint(int min, int max, const char* prompt, const char* errMes);
   };
   
   extern Utils ut; // provides global access to the ut instance in the Utils.cpp file
}

#endif // !SDDS_UTILS_H
