/*
	Casey O'Kane
	PicEdit.h
	Header file for class that preforms different operations on a TIFF image using the LIBTIFF library. *At this point, it should only generate images*


*/

#ifndef _PicEdit_included_
#define _PicEdit_included_


#include <tiffo.h>
#include <stdio.h>

class PicEdit
{

public:


	//Constructor                    
	PicEdit();

	//Destructor
	~PicEdit();

	//GenImage function is used to generate an image using the LIBTIFF library.	
	//It takes a string that represents the filename that we use to generate the image.
	int GenImage(const char* sFilename);

private:

	//Our data members should only involve the pointers to the raster input and output
	uint32_t *pInputRast;
	uint32_t *pOutputRast;	
}

#endif 
