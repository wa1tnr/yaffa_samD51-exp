// Sun Nov 11 20:45:12 UTC 2018
// 4737-a3c-00g- // ainsuForth-gen-exp-m4
// On branch testing-hh-ii-
// SPI_FlashROM_FILENAME
#ifdef HAS_EXP_MFOUR_QSPI_FLASH


// void noooop(void) { }















// Fri Nov 24 23:31:39 UTC 2017
// 4735-b0c-09b-   the -09x- is new Nov 24, 2017.

// implemented a cpp macro to name the file read or written to SPI flashROM. 24 NOV 2017

// To ignore previous files stored in SPI flashROM, change the macro below
// to name a new file, then recompile the program and upload it
// to the target, using standard Arduino toolchain.  This is a kludge
// to allow a fresh program download from the forth interpreter into
// spi flashROM.

// previous timestamps:
// Fri Nov 24 05:23:48 UTC 2017
// 4735-b0c-09a-   the -09x- is new Nov 24, 2017.
// Thu Aug  3 19:07:55 UTC 2017
// 4735-b0f-00-

// macro to name the file read or written to SPI flashROM.
// #ifdef HAS_SPI_FLASH_DEMO // 15 Jan 2018
    #define SPI_FlashROM_FILENAME "/forth/ascii_xfer_a001.txt"
    #define SPI_FlashROM_TOPDIR "/forth"
// #endif

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// 16 January 2018 00:24z:
// 
// The SPI flashROM *must* be pre-initialized by some other
// program.  The root directory *must* have a subdirectory
// named '/forth' (unless you change the hard-coded path,
// named above, and carry out any needed adjustments).
// The directory '/forth' does *not* have to have the named
// file present ('ascii_xfer_a001.txt') as it will be created
// the first time the 'download' word is used.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    #include <Arduino.h> // LINE 59
    #include "../../yaffa.h" // LINE 60
    #define CURRENT_FILESYSTEM pythonfs // #define CURRENT_FILESYSTEM fatfs
    #ifdef EXT_KERN_GETLINE
        #include "getline.h" // this is the flag wanted: HAS_QSPI_FLASHROM_LIB
        #ifdef HAS_QSPI_FLASHROM_LIB // 11 Nov 2018 // NEW LINE 64
//          #warning HAS_QSPI_FLASHROM_LIB includes extra code on line 65 __getline_m4_exp.cpp__ // 11 Nov 2018 - NEW LINE 66
            #define FLASH_DEVICE_GD25Q
    // ref  #ifdef FLASH_DEVICE_GD25Q

            #ifdef FLASH_DEVICE_GD25Q
                #include <SPI.h>
                #include <SdFat.h>
                #include <Adafruit_SPIFlash.h>
/*
   Adafruit.com, hathach, Dean Miller, Tony DiCola, Limor Fried:
       $ ~/Arduino/libraries/Adafruit_SPIFlash/examples/SdFat_full_usage/SdFat_full_usage.ino#L33
       https://github.com/adafruit/Adafruit_SPIFlash
       https://github.com/adafruit/Adafruit_SPIFlash/blob/master/examples/SdFat_full_usage/SdFat_full_usage.ino#L33
       https://github.com/adafruit/Adafruit_SPIFlash/blob/master/src/Adafruit_FlashTransport.h
       name=Adafruit SPIFlash
       version=3.1.1

       * The MIT License (MIT)
       *
       * Copyright (c) 2019 hathach for Adafruit Industries

// local: Thu Aug 29 20:54:33 UTC 2019
*/

                #if defined(__SAMD51__) || defined(NRF52840_XXAA)
                    Adafruit_FlashTransport_QSPI flashTransport(PIN_QSPI_SCK,
                      PIN_QSPI_CS, PIN_QSPI_IO0, PIN_QSPI_IO1, PIN_QSPI_IO2,
                        PIN_QSPI_IO3);
                #else
                    #if (SPI_INTERFACES_COUNT == 1)
                        Adafruit_FlashTransport_SPI flashTransport(SS, &SPI);
                    #else
                        Adafruit_FlashTransport_SPI flashTransport(SS1, &SPI1);
                    #endif
                #endif

                Adafruit_SPIFlash flash(&flashTransport);
                FatFileSystem pythonfs; // FatFileSystem fatfs;
                File myFile;
            #endif // #ifdef FLASH_DEVICE_GD25Q
        // #endif // #ifdef HAS_QSPI_FLASHROM_LIB

                // #define FLASH_TYPE     SPIFLASHTYPE_W25Q16BV  // Flash chip type. // NEW LINE 71
    // rescind  #define FLASH_TYPE     SPIFLASHTYPE_W25Q128JV  // Flash chip type. //Albert 20190430
    // rescind  #include <Adafruit_SPIFlash_FatFs.h> // NEW LINE 69
    // rescind  #include "Adafruit_QSPI_GD25Q.h"
    // rescind  #define FLASH_TYPE     SPIFLASHTYPE_W25Q16BV  // Flash chip type. // NEW LINE 71
 
                //Adafruit_QSPI_GD25Q flash;
//                Adafruit_QSPI_GD25Q flash;
// rescind      Adafruit_QSPI_Generic flash; // Albert 20190429
// rescind      Adafruit_M0_Express_CircuitPython pythonfs(flash);

// TEMP: LINE 79
// LINE 77 // TEMP: LINE 80
// LINE 100
// LINE 108
// ------------------------ this was SPI   not    SPI1   ------ when did this change?
// LINE 110

// Adafruit_SPIFlash flash(FLASH_SS, &FLASH_SPI_PORT); // Adafruit_QSPI_GD25Q flash;
// Adafruit_W25Q16BV_FatFs fatfs(flash); // Adafruit_M0_Express_CircuitPython pythonfs(flash);
// COMMENTED // #endif // 15 Jan 2018
/* these two levels cpp still open 11 Nov 21:53 UTC:
// #ifdef HAS_EXP_MFOUR_QSPI_FLASH
    // #ifdef EXT_KERN_GETLINE
        #directive
*/
// #endif //  kludge wa1tnr 29 aug 21:14z

/*
// #ifdef HAS_EXP_MFOUR_QSPI_FLASH
//    #define SPI_FlashROM_FILENAME "/forth/ascii_xfer_a001.txt"
//    #define SPI_FlashROM_TOPDIR "/forth"
//    #include <Arduino.h> // LINE 59
//    #include "../../yaffa.h" // LINE 60
//    #define CURRENT_FILESYSTEM pythonfs // #define CURRENT_FILESYSTEM fatfs
//    #ifdef EXT_KERN_GETLINE
//        #include "getline.h" // this is the flag wanted: HAS_QSPI_FLASHROM_LIB
//        #ifdef HAS_QSPI_FLASHROM_LIB // 11 Nov 2018 // NEW LINE 64
//            #warning HAS_QSPI_FLASHROM_LIB includes extra code on line 65 __getline_m4_exp.cpp__ // 11 Nov 2018 - NEW LINE 66
//            #define FLASH_DEVICE_GD25Q
//            #ifdef FLASH_DEVICE_GD25Q
//                #include <SPI.h>
//                #include <SdFat.h>
//                #include <Adafruit_SPIFlash.h>
//                #if defined(__SAMD51__) || defined(NRF52840_XXAA)
//                #else
//                    #if (SPI_INTERFACES_COUNT == 1)
//                    #else
//                    #endif
//                #endif
//            #endif // #ifdef FLASH_DEVICE_GD25Q
//        #endif // #ifdef HAS_QSPI_FLASHROM_LIB
// COMMENTED // #endif // EXT_KERN_GETLINE test
// COMMENTED // #endif // HAS_EXP_MFOUR test

*/
// #endif // kludge 29 aug
// #endif // test for unclosed #ifdef
// #endif // test for unclosed #ifdef

// #ifdef HAS_EXP_MFOUR_QSPI_FLASH
//    #ifdef EXT_KERN_GETLINE

// #endif // test for unclosed #ifdef
/******************************************************************************/
/** getDLKey                                                                 **/
/******************************************************************************/
/** getDLKey                                                                 **/
/**   waits for the next valid key to be entered in download mode (DL)       **/
/**   and return its value                                                   **/
/**   Watches for code-escape key '\' (backslash) to detect the '\end.' word **/
/**   Valid characters are:  Backspace, Carriage Return (0x0d), Escape,      **/
/**   Tab, Newline (0x0a) and standard (printable) characters                **/
/******************************************************************************/

        #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018

#define BUFFR_SIZE 256
const char* workingFilename = SPI_FlashROM_FILENAME;
const char* workingDirname = SPI_FlashROM_TOPDIR;

/*
void setup_qspiFlashROM(void) { // void setup_spi_flash(void) {



























*/


void setup_qspiFlashROM(void) {
    Serial.println("Hello from setup_qspi m4 getline stuff.   ");
    Serial.print("VALID m4 getline ca3f-sesi-c3-f17  ");
    Serial.println("Fri Aug 30 04:27:57 UTC 2019");

    if (!flash.begin()) {
            Serial.println("E: could not find flash on QSPI bus.");
            while(1);
    }
    Serial.println("Found QSPI Flash.");

    if (!CURRENT_FILESYSTEM.begin(&flash)) {
            Serial.println("Failed to mount filesystem!");
            Serial.println("Was CircuitPython loaded on the board first to create the filesystem?");
            while(1);
    }
    Serial.println("AUG 2019: Mounted filesystem!");
}









        #endif // 15 Jan 2018

extern void printStr(char*);
extern void printHex(cell_t);
extern void printHex(cell_t, uint8_t);
extern cell_t dStack_pop();
extern cell_t*pHere;
extern void _throw(char*);
extern void _cr();
extern void _bl();
extern void _word();
extern void _download();
extern void _load();
extern void _remove();

char* parseStr(void) {
	_bl(); _word(); cell_t n = dStack_pop();
	cell_t* cStr = (cell_t*) n;
	char* str = 0;
	if(cStr) {
		n = *cStr++; str = (char*) cStr;
	  	printStr("\r\n "), Serial.print(n), printStr("-byte \""), printStr(str), printStr("\"");
	}
  	printStr(" ==> str "), printHex((cell_t) str);
        // cruft // Serial.print("str is: "); // Serial.println(str);
	return str;
}

char* fullPath(char* dirname){
        const char* pathLegend = "\r\n fullPath ";
	char* path;
        char thisbuffer[BUFFR_SIZE];
        char thatbuffer[BUFFR_SIZE];
        char* buffer;
        char* buffer_bb;
        buffer = thisbuffer;
        buffer_bb = thatbuffer; // not sure what's needed for separation and when. ;)
        strcpy(buffer, workingDirname);
	if(dirname == 0 || *dirname == 0) path = buffer;
	else if(*dirname == '/') path = dirname;

	else {
		path = (char*)pHere + 128;
		strcpy(path, workingDirname);
		char* pathEnd = path + strlen(path);
		*pathEnd++ = '/';
		strcpy(pathEnd, dirname);
	}
  	printStr("\r\n fullPath "), printStr(path);
        strcpy(buffer_bb, pathLegend);
  	printStr(buffer_bb);
        strcpy(buffer_bb, path);
  	printStr(buffer_bb);
	return path;
}

void _chdir(void){ // list filenames in given dir
	char* path = fullPath( parseStr() );
	if (!pythonfs.exists(path)) {
		printStr("\r\n directory ");
		printStr(path);
		printStr(" not exist");
		_throw("not exist");
		return;
	}
	workingDirname = path;
	printStr("\r\n working directory "); printStr(path);
}

// _dir() calls parseStr which prints " ==> str " and an address

void _dir(void){ // list filenames in given dir
	char* path = fullPath( parseStr() );
        char thisbuffer[BUFFR_SIZE];
        char* buffer;
        buffer = thisbuffer;
	if (!pythonfs.exists(path)) {
		Serial.print("\r\n directory ");
		Serial.print(path);
		Serial.println(" not exist");
                _throw("not exist");
		return;
	}
	Serial.print("\r\n directory ");
	Serial.print(path);
	File testDir = pythonfs.open(path);
	if (!testDir.isDirectory()) {
            _throw("not a dir");
		return;
	}






#ifdef NEVER_DEFINED_BB
173   Serial.println("Listing children of directory /test:");
174   File child = testDir.openNextFile();
175   while (child) {
176     char filename[64];
177     child.getName(filename, sizeof(filename));
#endif // #ifdef NEVER_DEFINED_BB


	File child = testDir.openNextFile();
        File myChild = (File) child;
	int i = 0;
	while( myChild ) {
            char filename[64];
         // strcpy(buffer, myChild.name());
            myChild.getName(filename, sizeof(filename));
            strcpy(buffer, (char*) filename);
            // debug only: // printStr(buffer);

// -----------------------------------------------------------
// -----------------------------------------------------------
#ifdef NEVER_DEFINED

 317 void _dir(void){ // list filenames in given dir
 318         char* path = fullPath( parseStr() );
 319         char thisbuffer[BUFFR_SIZE];
 320         char* buffer;
 321         buffer = thisbuffer;

 336         File child = testDir.openNextFile();
 337         File myChild = (File) child;
 338         int i = 0;
 339         while( child ) {
 354 // does not want to compile as-is:
 355             // strcpy(buffer, printStr(  myChild.name()  ));
 356             // fname = myChild.name();
 357 
 358             strcpy(buffer, myChild.name());
 359 
 360        //   printStr("\r\n "); Serial.print(++i); printStr(" "); printStr(child.name());
 361             Serial.println(" BUG - before it ");
 362             printStr("\r\n "); Serial.print(++i); printStr(" "); printStr(buffer);
 363             Serial.println(" BUG - after it ");
#endif // NEVER_DEFINED
// -----------------------------------------------------------
// -----------------------------------------------------------
// -------------------   bug   -------------------------------
// -----------------------------------------------------------
// -----------------------------------------------------------
// does not want to compile as-is:
//          printStr("\r\n "); Serial.print(++i); printStr(" "); printStr(child.name());
            // Serial.println(buffer); // Serial.println(" .. get a load of that!");

            // delay(500);  // runaway train catcher
            printStr("\r\n "); Serial.print(++i); printStr(" "); printStr(buffer); 
            if (myChild.isDirectory()) printStr(" (dir)"); // and this, too ;)
	    myChild = testDir.openNextFile(); // this caused infinite enumeration ;)
	}
        if(! i) printStr(" empty");
}

void _rmdir(void){
	char* path = fullPath( parseStr() );
	if (!pythonfs.exists(path)) {
            _throw("dir not exist");
		return;
	}
	if (!pythonfs.rmdir(path)) {
            _throw("failed to remove dir");
	  return;
	}
        printStr("\r\n Removed dir "); printStr(path);
}

void _mkdir(void){
	char* path = fullPath( parseStr() );
	if (!pythonfs.exists(path)) {
		if (!pythonfs.mkdir(path)) {
                     _throw("failed to create dir");
		  return;
		}
                printStr("\r\n Created dir ");

// may be a mistake in uncommenting previously commented code:
        } else printStr("\r\n Already had dir ");
//      else // noooop();
	printStr(path);
}

void _fdel(void){
	workingFilename = fullPath( parseStr() );
	if (!pythonfs.exists(workingFilename)) {
            _throw( "file not exist" ); return;
	}
	_remove();
}
void _fload(void){
	char* filename = fullPath( parseStr() );
	if (!pythonfs.exists(filename)) {
		Serial.print("file ");
		Serial.print(filename);
		Serial.println(" not found");
                 _throw(" not found");
		return;
	}
	workingFilename = filename;
	_load();
}
void _fsave(void){
	workingFilename = fullPath( parseStr() );
	if (!pythonfs.exists(workingFilename)) {
		File writeFile = pythonfs.open(workingFilename, FILE_WRITE);
		if (!writeFile){
                        _throw( "cannot create empty file" );
			return;
		}
		writeFile.println();
		writeFile.close();
	}
	_download();
}
void _ftype(void){
	char* filename = fullPath( parseStr() );
	if (!pythonfs.exists(filename)) {
		Serial.print("file ");
		Serial.print(filename);
		Serial.println(" not found");
                _throw(" not found");
		return;
	}
	File readFile = pythonfs.open(filename, FILE_READ);
	_cr();
	while (readFile.available()) Serial.print((char) readFile.read());
	readFile.close();
}
#ifdef SAM_STRING_FCNS
void _chdir(void){ } void _dir(void){ } void _rmdir(void){ }
void _mkdir(void){ } void _fdel(void){ } void _fload(void){ }
void _fsave(void){ } void _ftype(void){ }
#endif
/******************************************************************************/
/** getLine                                                                  **/
/**   read in a line of text ended by a Carriage Return (ASCII 13)           **/
/**   Valid characters are:  Backspace, Carriage Return, Escape, Tab, and    **/
/**   standard printable characters. Passed the address to store the string, **/
/**   and Returns the length of the string stored                            **/
/******************************************************************************/

        #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
File thisFile;
        #endif // 15 Jan 2018
        // #directive
extern void _fgRed(void);
extern void _fgWhite(void);
extern void _fgGreen(void);
void waitEsc(){
  Serial.print( "\r\nPress " );
  _fgRed(); Serial.print( "ESC and CR" ); _fgWhite();
  Serial.print( " to resume" );
  if (spiFlashReading) spiFlashReading = 0;
  while( Serial.read() != 0x1b );
  delay(1); while( Serial.available() ) Serial.read();
}
char lastChar = 0;
uint8_t getLine(char* ptr, uint8_t buffSize) {
  char inChar;
  uint8_t count = 0;
  _fgGreen();
  // if (fileClosed) { Serial.println("Indeed, fileClosed is TRUE"); }

        #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
  if (spiFlashReading) {
      // cheap_test: if (fatfs.exists("/forth/job.fs")) {



      // if (pythonfs.exists("data.txt")) { // if (fatfs.exists(workingFilename)) {
      if (pythonfs.exists(workingFilename)) {

          if (fileClosed) {

        //  File bootPy = pythonfs.open("data.txt", FILE_READ);
            File bootPy = pythonfs.open(workingFilename, FILE_READ);

        //  File forthSrcFile = fatfs.open(workingFilename, FILE_READ);

        //  thisFile = (File) forthSrcFile;
            thisFile = (File) bootPy;
            fileClosed = FALSE ; // it is open, now.
          }
      }
  }
        #endif // 15 Jan 2018


// another getLine() stanza:
  do {
        #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
    if (spiFlashReading) {
        if (thisFile) {
            if (thisFile.available()) {
             // this is where every character of job.fs is read from SPI flash:
                inChar = thisFile.read();

                spiFlashWaiting = FALSE;
                if (thisFile.available()) {
                    spiFlashWaiting = TRUE;
                } else {
                    fileClosed = TRUE; // want to close the file - set a flag
                    spiFlashReading = FALSE; // shutdown the reading mechanism
                }
            }
        }

    } else {
        #endif // 15 Jan 2018

        if (noInterpreter) {
            inChar = getKey();
            if (inChar == '\\') {
                // Serial.print("ESC \\ SEEN in getLine().\r\n");
            }
        } else {
            inChar = getKey(); 
        }
        #ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
    }
        #endif // 15 Jan 2018

    // inChar is now populated; either by keypress or by byte stored in SPI flash.
    if (inChar == ASCII_NL && lastChar == ASCII_CR) continue;
    if (inChar == ASCII_BS || inChar == ASCII_DEL) {  // new: was only ASCII_BS
       if (count) {
         *--ptr = 0;
         count--; // ainsuForth improvement -- backspace behavior


if (silentReading) { } else {
    if (flags & ECHO_ON) Serial.print("\b \b");
}



      }
    }
    else if (inChar == ASCII_TAB || inChar == ASCII_ESC) {


if (silentReading) { } else {
      if (flags & ECHO_ON) Serial.print("\a");
}




    }
    else if (inChar == ASCII_CR || inChar == ASCII_NL) { // ainsuForth improvement

                          // iirc, this was for use during colon definition upload,
                          // using copy and paste into the serial terminal.

                          // Basis: lack of newline sensitivity; added some.

                          // Test: revert, attempt a multi-line code paste.  If
                          // it fails or behaves poorly, reenable this code.
                          // Compare the two behaviors.

                          // iirc, interactive typing to the interpreter masks
                          // this behavior, whereas a paste-in unmasks it.

// -----------------------------------------------------
// -----------------------------------------------------
// -----------------------------------------------------
// -----------------------------------------------------

      // if (silentReading && spiFlashReading) { // the 'load' word
      if (silentReading) { // the 'load' word
      } else {
              if (flags & ECHO_ON) Serial.print(" "); // seems to want a space after 'dot' for example.
      }
// -----------------------------------------------------
// -----------------------------------------------------
// TRY TO REMEMBER:
// 
// The mechanism to end a file upload to the SPI Flash
// is a parsed word '\end.'

// Whereas .. the mechanism to end a 'load' (compile
// into VM code, stored in RAM -- from a disk file forth
// source program that's stored on SPI FlashROM)
// 
// That mechanism is simply to detect if flash is waiting
// (if we have reached EOF or not while reading a file
// from the SPI FlashROM chip).
// -----------------------------------------------------

      // debug // Serial.println("EVERYONE");
      // Serial.println("debug: is flash waiting or not?");
      if (spiFlashWaiting) {
          // Serial.println("a good spot to turn off silentReading perhaps.");
          // Serial.println("Flash is WAITING .. more to read.");
      } else { 
          silentReading = FALSE; // we are interactive once more, when spiFlashWaiting changes state
      }

      break;

    } else {



// always suppress echo when the load word is executed.
      if (silentReading && spiFlashReading) { // the 'load' word
          int fakeSPxT = 0;
      } else {
          if (flags & ECHO_ON) {
// -----------------------------------------------------
// -----------------------------------------------------
// -----------------------------------------------------
if (silentReading) {
} else {
              // main forth interpreter typing echo is right here:
              Serial.print(inChar); // do NOT suppress this ordinarily, if ever.
}
// -----------------------------------------------------
// -----------------------------------------------------
// -----------------------------------------------------
// -----------------------------------------------------
          }
      }

      *ptr++ = inChar;
      *ptr = 0;
      count++;
    }
  } while (count < buffSize);
  _fgWhite();
  lastChar = inChar;
  return (count);
}

        #endif // LINE 556 and LIVE CODE 29 August 2019
    #endif // #ifdef EXT_KERN_GETLINE


#ifdef EXT_KERN_GETKEY

/******************************************************************************/
/** getKey                                                                   **/
/**   waits for the next valid key to be entered and return its value        **/
/**   Valid characters are:  Backspace, Carriage Return (0x0d), Escape,      **/
/**   Tab, Newline (0x0a) and standard (printable) characters                **/
/******************************************************************************/
char isPrintable(char key){
	return (key >= 0x20 && key <= 0xfe) ? 1 : 0;
}
char getKey(void) {
//	Serial.print("getKey"); while(1);
    char inChar;
    // the load word provides this boolean:
    if (spiFlashReading) {
        if (inChar == ASCII_BS  ||
            inChar == ASCII_TAB ||
            inChar == ASCII_CR  ||  
            inChar == ASCII_NL  ||   // new
            inChar == ASCII_DEL ||   // new
            inChar == ASCII_ESC ||
            isPrintable(inChar)) {
            return inChar;
        }
    } else {
        while (1) {
            if (Serial.available()) {
                inChar = Serial.read();
                if (inChar == ASCII_BS  ||
                    inChar == ASCII_TAB ||
                    inChar == ASCII_CR  ||  
                    inChar == ASCII_NL  ||   // new
                    inChar == ASCII_DEL ||   // new
                    inChar == ASCII_ESC ||
                    isPrintable(inChar)) {
                    return inChar;
                }
            }
        }
    }
}

#endif







//  ---------------------------    ascii  transfer   --------------------------


//                      03 August 2017  15:49z begin.


// Wed Aug  2 01:22:51 UTC 2017
// 4735-b0c-03-

// #include <Arduino.h>
// #include "../../yaffa.h"
// #include "fatfs_writefile.h"

// Adafruit SPI Flash FatFs Full Usage Example
// Author: Tony DiCola

// locally modified July 2017 - wa1tnr

// modified to look at python in the fatfs - code.py and the /lib.

// This is an example of all the functions in the SPI Flash
// FatFs library.  Note that you MUST have a flash chip that's
// formatted with a flash filesystem before running.  See the
// fatfs_format example to perform this formatting.
//
// In general the API for this library closely follows the API
// for the Arduino SD card library.  However instead of interacting
// with a global SD object you create an instance of a fatfs class
// and use its open, exists, etc. functions.  See the SD library
// reference for more inspiration and examples to adapt:
//   https://www.arduino.cc/en/reference/SD
//
// Usage:
// - Modify the pins and type of fatfs object in the config
//   section below if necessary (usually not necessary).
// - Upload this sketch to your M0 express board.
// - Open the serial monitor at 115200 baud.  You should see the
//   example start to run and messages printed to the monitor.
//   If you don't see anything close the serial monitor, press
//   the board reset buttton, wait a few seconds, then open the
//   serial monitor again.
// #include <SPI.h>
// #include <Adafruit_SPIFlash.h>
// #include <Adafruit_SPIFlash_FatFs.h>


// Configuration of the flash chip pins and flash fatfs object.
// You don't normally need to change these if using a Feather/Metro
// M0 express board.
// #define FLASH_TYPE     SPIFLASHTYPE_W25Q16BV  // Flash chip type.
                                              // If you change this be
                                              // sure to change the fatfs
                                              // object type below to match.
// #define FLASH_SS       SS                    // Flash chip SS pin.
// #define FLASH_SPI_PORT SPI                   // What SPI port is Flash on?

// SHOULD NOT BE NEEDED 06 Aug:  Adafruit_SPIFlash ascii_xfer_flash(FLASH_SS, &FLASH_SPI_PORT);     // Use hardware SPI 

// Alternatively you can define and use non-SPI pins!
// Adafruit_SPIFlash flash(FLASH_SCK, FLASH_MISO, FLASH_MOSI, FLASH_SS);

// Adafruit_W25Q16BV_FatFs ascii_xfer_fatfs(ascii_xfer_flash);


//const char eflmkdir_str[] = "eflmkdir"; // forth vocabulary external flash mkdir
// void create_test_directory(void) {
void _eflmkdir(void) {
  // Check if a directory called 'test' exists and create it if not there.
  // Note you should _not_ add a trailing slash (like '/test/') to directory names!
  // You can use the same exists function to check for the existance of a file too.

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
// #ifdef HAS_STANDARD_BUILD_HERE

// #define workingDirname   "/forth"
// if (!fatfs.exists("/test")) {
  // if (!fatfs.exists(workingDirname)) {
  if (!pythonfs.exists(workingDirname)) {
    Serial.println("directory not found, Creating...");
    // Use mkdir to create directory (note you should _not_ have a trailing slash).
  // if (!fatfs.mkdir("/test")) {
    // if (!fatfs.mkdir(workingDirname)) {
    if (!pythonfs.mkdir(workingDirname)) {
      Serial.println("Error, failed to create test directory!");
      while(1);
    }
    Serial.println("Created forth directory");
  }
  Serial.print("forth directory: "); Serial.println(workingDirname);
#endif




#ifdef NEVER_DEFINED_TEN_THREE // nonsense tag to prevent compile
#ifndef HAS_STANDARD_BUILD_HERE

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
// #define workingDirname   "/forth"
// if (!fatfs.exists("/test")) { Serial.println("BAD ROBOT - fatfs.exists fails on line 97.");
  // if (!fatfs.exists(workingDirname)) {
  if (!pythonfs.exists(workingDirname)) {
    Serial.println("BAD ROBOT - fatfs.exists fails on line 473 June 17, 2018.");
  } else {
    Serial.println("local: assuming /forth directory already exists.");
  }
#endif // 15 Jan 2018

#endif
#endif
}


#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
void remove_a_file(void) {
  Serial.print("file Deleting ");
  Serial.print(workingFilename);
  Serial.println(" ...");

  // if (!fatfs.remove(workingFilename)) {
  if (!pythonfs.remove(workingFilename)) {
      Serial.print("Error, file ");
      Serial.print(workingFilename);
      Serial.println(" was not removed!");
      return;
  }
  Serial.println("file Deleted!");
}
#endif // 15 Jan 2018

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
void write_a_capture_file(void) {
  // Create a file in the test directory and write data to it.
  // Note the FILE_WRITE parameter which tells the library you intend to
  // write to the file.  This will create the file if it doesn't exist,
  // otherwise it will open the file and start appending new data to the
  // end of it.  More advanced users can specify different file modes by
  // using the FatFs f_open modes directly (which can be specified instead
  // of FILE_WRITE), see documentation at:
  //   http://elm-chan.org/fsw/ff/en/open.html

  // 03 Aug 15:52z -- try to use existing fatfs 'handle' / whatever it is
  // result: does compile just fine.

  // File writeFile = ascii_xfer_fatfs.open("/test/ascii_xfer_test.txt", FILE_WRITE);
    // pythonfs fatfs
  // File writeFile =               fatfs.open(workingFilename, FILE_WRITE);
  File writeFile =               pythonfs.open(workingFilename, FILE_WRITE);
  if (!writeFile) {
    Serial.print("Error, failed to open ");
    Serial.print(workingFilename);
    Serial.println(" for writing!");
    return;
  }
  // debug: // Serial.println("Opened file /forth/ascii_xfer_test.txt for writing/appending...");

  // Once open for writing you can print to the file as if you're printing
  // to the serial terminal, the same functions are available.

// payload -- download mode.

// model: Serial.print(cpSource);
  writeFile.println(cpSource);

  // Close the file when finished writing.
  writeFile.close();
  // debug: // Serial.println("Wrote -- appended -- to file /forth/ascii_xfer_test.txt!");
}
#endif // 15 Jan 2018


#ifndef HAS_STANDARD_BUILD_HERE

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
void read_a_test_file(void) {
  // Now open the same file but for reading.
  // cheap_test: File readFile = fatfs.open("/forth/job.fs",             FILE_READ);
    // pythonfs fatfs
  // File readFile = fatfs.open(workingFilename, FILE_READ);
  File readFile = pythonfs.open(workingFilename, FILE_READ);
  if (!readFile) {
    // cheap_test: Serial.println("Error, failed to open job.fs for reading!");
    // Serial.println("Error, failed to open /forth/ascii_xfer_test.txt for reading!");
    Serial.print("Error, failed to open ");
    Serial.print(workingFilename);
    Serial.println(" for reading!");
    while(1);
  }
  // Read data using the same read, find, readString, etc. functions as when using
  // the serial class.  See SD library File class for more documentation:
  //   https://www.arduino.cc/en/reference/SD
  // Read a line of data:
  String line = readFile.readStringUntil('\n');
  // cheap_test: Serial.print("First line of job.fs: "); Serial.println(line);
  Serial.print("First line of ");
  Serial.print(workingFilename);
  Serial.println(line);
  // You can get the current position, remaining data, and total size of the file:
  Serial.print("Ignore job.fs and say ");
  Serial.print(workingFilename);
  Serial.print(" here - several lines.");
  Serial.print("Total size of job.fs (bytes): "); Serial.println(readFile.size(), DEC);
  Serial.print("Current position in job.fs: "); Serial.println(readFile.position(), DEC);
  Serial.print("Available data to read in job.fs: "); Serial.println(readFile.available(), DEC);

  // And a few other interesting attributes of a file:
  Serial.print("File name: "); Serial.println(readFile.name());
  Serial.print("Is file a directory? "); Serial.println(readFile.isDirectory() ? "Yes" : "No");

  // You can seek around inside the file relative to the start of the file.
  // For example to skip back to the start (position 0):
  if (!readFile.seek(0)) {
    Serial.println("Error, failed to seek back to start of file!");
    while(1);
  }

  // And finally to read all the data and print it out a character at a time
  // (stopping when end of file is reached):
  Serial.println("Entire contents of job.fs:");
  while (readFile.available()) {
    char c = readFile.read();
    Serial.print(c);
  }

  // Close the file when finished reading.
  readFile.close();
}
#endif // 15 Jan 2018
#endif

#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018


#ifndef HAS_STANDARD_BUILD_HERE
void read_from_code_py_file(void) {
    // pythonfs fatfs
  // File readCodeFile = fatfs.open("/main.py", FILE_READ);
  File readCodeFile = pythonfs.open("/main.py", FILE_READ);
  if (!readCodeFile) {
    Serial.println("Error, failed to open code.py for reading!");
    while(1);
  }

  // Read a line of data:
  String line = readCodeFile.readStringUntil('\n');
  Serial.print("First line of code.py: "); Serial.println(line);

  // You can get the current position, remaining data, and total size of the file:
  Serial.print("Total size of code.py (bytes): "); Serial.println(readCodeFile.size(), DEC);
  Serial.print("Current position in code.py: "); Serial.println(readCodeFile.position(), DEC);
  Serial.print("Available data to read in code.py: "); Serial.println(readCodeFile.available(), DEC);

  // And a few other interesting attributes of a file:
  Serial.print("File name: "); Serial.println(readCodeFile.name());
  Serial.print("Is file a directory? "); Serial.println(readCodeFile.isDirectory() ? "Yes" : "No");

  // You can seek around inside the file relative to the start of the file.
  // For example to skip back to the start (position 0):
  if (!readCodeFile.seek(0)) {
    Serial.println("Error, failed to seek back to start of file!");
    while(1);
  }

  // And finally to read all the data and print it out a character at a time
  // (stopping when end of file is reached):
  Serial.println("Entire contents of code.py:");
  while (readCodeFile.available()) {
    char c = readCodeFile.read();
    Serial.print(c);
  }

  // Close the file when finished reading.
  readCodeFile.close();
}
#endif // 15 Jan 2018
#endif























// #endif // 15 Jan 2018


#ifdef HAS_QSPI_FLASH_DEMO // 15 Jan 2018
void tail_code_bb(void) {
  // You can open a directory to list all the children (files and directories).
  // Just like the SD library the File type represents either a file or directory.
#ifndef HAS_STANDARD_BUILD_HERE
    // pythonfs fatfs
  // File testDirRoot = fatfs.open("/");
  File testDirRoot = pythonfs.open("/");
  if (!testDirRoot) {
    Serial.println("Error, failed to open root directory!");
    while(1);
  }
  Serial.println("Made it past the opening of the root directory.");
#endif

#ifdef HAS_STANDARD_BUILD_HERE
    // pythonfs fatfs
  File testDir = pythonfs.open("/lib");
  if (!testDir) {
    Serial.println("Error, failed to open test directory!");
    while(1);
  } else {
    Serial.println("Made it past the opening of the /lib directory.");
  }
#endif

#ifndef HAS_STANDARD_BUILD_HERE
  if (!testDirRoot.isDirectory()) {
    Serial.println("Error, expected root to be a directory!");
    while(1);
  } else {
    Serial.println("Good - root is a directory - not a file.  Continue.");
  }
#endif

#ifdef HAS_STANDARD_BUILD_HERE
  if (!testDir.isDirectory()) {
    Serial.println("Error, expected /lib to be a directory!");
    while(1);
  } else {
    Serial.println("Good - /lib is a directory - not a file.  Continue.");
  }
#endif

#ifndef HAS_STANDARD_BUILD_HERE
  Serial.println("Listing children of root directory:");
  File child = testDirRoot.openNextFile();
  while (child) {
    // Print the file name and mention if it's a directory.
    Serial.print("- "); Serial.print(child.name());
    if (child.isDirectory()) {
      Serial.print(" (directory)");
    }
    Serial.println();
    // Keep calling openNextFile to get a new file.
    // When you're done enumerating files an unopened one will
    // be returned (i.e. testing it for true/false like at the
    // top of this while loop will fail).
    child = testDirRoot.openNextFile();
  }

  // If you want to list the files in the directory again call
  // rewindDirectory().  Then openNextFile will start from the
  // top again.
  testDirRoot.rewindDirectory();
#endif


// hold: while(1); Serial.println("WILL ROBINSON.");
         while(1); Serial.println("WILL ROBINSON.");



#ifdef HAS_STANDARD_BUILD_HERE
  Serial.println("Listing children of directory /lib:");
  File child = testDir.openNextFile();
  while (child) {
    // Print the file name and mention if it's a directory.
    Serial.print("- "); Serial.print(child.name());
    if (child.isDirectory()) {
      Serial.print(" (directory)");
    }
    Serial.println();
    // Keep calling openNextFile to get a new file.
    // When you're done enumerating files an unopened one will
    // be returned (i.e. testing it for true/false like at the
    // top of this while loop will fail).
    child = testDir.openNextFile();
  }


  // If you want to list the files in the directory again call
  // rewindDirectory().  Then openNextFile will start from the
  // top again.
  testDir.rewindDirectory();
#endif



#ifdef HAS_EXTRA_STANDARD_BUILD_HERE

  // Delete a file with the remove command.  For example create a test2.txt file
  // inside /test/foo and then delete it.
    // pythonfs fatfs
  // File test2File = fatfs.open("/forth/foo/test2.txt", FILE_WRITE);
  File test2File = pythonfs.open("/forth/foo/test2.txt", FILE_WRITE);
  test2File.close();
  Serial.println("Deleting /forth/foo/test2.txt...");
    // pythonfs fatfs
  if (!pythonfs.remove("/forth/foo/test2.txt")) {
    Serial.println("Error, couldn't delete test.txt file!");
    while(1);
  }
  Serial.println("Deleted file!");

  // Delete a directory with the rmdir command.  Be careful as
  // this will delete EVERYTHING in the directory at all levels!
  // I.e. this is like running a recursive delete, rm -rf, in
  // unix filesystems!
  Serial.println("Deleting /test directory and everything inside it...");
    // pythonfs fatfs
  // if (!fatfs.rmdir("/test")) {
  if (!pythonfs.rmdir("/test")) {
    Serial.println("Error, couldn't delete test directory!");
    while(1);
  }
  // Check that test is really deleted.
    // pythonfs fatfs
  // if (fatfs.exists("/test")) {
  if (pythonfs.exists("/test")) {
    Serial.println("Error, test directory was not deleted!");
    while(1);
  }
  Serial.println("Test directory was deleted!");
  
  Serial.println("Finished!");
#endif

#ifndef HAS_STANDARD_BUILD_HERE
#endif

}
#endif // 15 Jan 2018


































































void ascii_xfer_spi_flash_main(void) {
  // SHOULD NOT BE NEEDED 06 AUG: ascii_xfer_setup_spi_flash();
  // _eflmkdir(); // OLD NAME WAS: create_test_directory();
  // write_a_test_file();
  // read_a_test_file();
  read_from_code_py_file(); 
  tail_code_bb();

}

// void loop_flash_main(void) {
  // Nothing to be done in the main loop.
  // delay(100);
// }

#endif // #ifdef HAS_EXP_MFOUR_QSPI_FLASH - entire file omitted when this flag is set

// END.
