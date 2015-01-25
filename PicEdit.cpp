/*
	Casey O'Kane	
	PicEdit.cpp
	Implementation of the PicEdit class methods

*/


#include "PicEdit.h"

#include <stdio.h> 

//The basic Constructor for the PicEdit class which sets the inital raster pointers to NULL
PicEdit::PicEdit(){
	pInputRast = NULL;
	pOutputRast = NULL;
}

//The destructor for the PicEdit class is used as well to free space associated with the raster pointers
PicEdit::~PicEdit(){
	if(pInputRast != NULL){
		_TIFFfree(pInputRast);
	}	

	if(pOutputRast != NULL){
		_TIFFfree(pOutputRast);
	}
}

//The primary function of the class, which opens an image and writes random data to it to create a new image
int PicEdit::GenImage(const char* pFilename){
	
	//Open a writeable TIFF file using the filename given
	TIFF* pOutTIFF = TIFFOpen(pFilename, "w");

	//Account for errors while creating the TIFF file

	//Set up some generic tags that the random image information will take over
	TIFFSetField(pOutTIFF, TIFFTAG_IMAGEWIDTH, 256);
	TIFFSetField(pOutTIFF, TIFFTAG_IMAGELENGTH, 256);
	TIFFSetField(pOutTIFF, TIFFTAG_SAMPLESPERPIXEL, 3);
	TIFFSetField(pOutTIFF, TIFFTAG_BITSPERSAMPLE, 8);
	TIFFSetField(pOutTIFF, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
	TIFFSetField(pOutTIFF, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
	TIFFSetField(pOutTIFF, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB);

	//Get the number of line bytes and create a buffer which will store our image information (sample per pixel * the width of the file)
	tsize_t linebytes = 3 * 256;


	//Use a for loop that will write the information from the buffer to the image file using TIFFWriteScanline

	//Finally, close the TIFF object that was created earlier
	TIFFClose(pOutTIFF);

	return 0;
}

