

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer07.h"



/**
 * Loads an ECE264 image file, returning an Image structure.
 * Will return NULL if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
Image * Image_load(const char * filename) 

{
FILE * fp = NULL;
size_t Read, Read2, Read3;
ImageHeader Header;
//Image * NewImage = NULL, * OtherImage = NULL;
char CommentBuffer[900];
size_t  CommentLength;
//Error = 0;
//OPENING FILE
fp = fopen(filename, "rb"); // opens file
if(fp == NULL) { 
printf("failed to open");
return NULL;}// checks file for file error
//Read header
Read = fread(&Header, sizeof(ImageHeader), 1, fp);
if (Read != 1){
	printf("failed to read header");
	fclose(fp);
	return NULL;}
//Check magic number
if (Header.magic_number != ECE264_IMAGE_MAGIC_NUMBER) {
	printf("incorrect magic number");
	fclose(fp);
	return NULL;}
//Check width and height
if ((Header.width == 0) || (Header.height ==0) ) {
	printf("invalid dimensions");
	fclose(fp);
	return NULL;}
//Check comment length
if (Header.comment_len == 0){
	printf("invalid comment length");
	fclose(fp);
	return NULL;}
CommentLength = Header.comment_len; // setting commenght length
//Read Comment
Read2 = fread(&CommentBuffer, CommentLength, 1 ,fp);
if ( Read2 != 1) {
	printf("failed to read comment");
	fclose(fp);
	return NULL;}
//Check if Comment ends with Null terminator
if (CommentBuffer[Header.comment_len -1] != '\0') { 
	printf("no null terminator on comment");
	fclose(fp);
	return NULL;}	
//Read Pixels
//uint8_t PixelArray[900000];
Image *NewImage = malloc(sizeof(Image));
size_t PixelArea =  Header.width * Header.height;
NewImage->data = malloc(PixelArea * sizeof(uint8_t));
Read3 = fread(NewImage->data, PixelArea, 1, fp);
if (Read3 != 1) {
	printf(" failed to read pixels");
	free(NewImage->data);
	free(NewImage);
	fclose(fp);
	return NULL;
				}
//Check if there are extra bytes
size_t Checkend;
    Checkend = fread (&Checkend, sizeof(uint8_t) , 1, fp);

	if (Checkend != sizeof(uint8_t) )  {
	printf("Too many bytes");
	free(NewImage->data);
	free(NewImage);
	fclose(fp);
	return NULL;                       }

//ALLOCATING MEMORY FOR STRUCT

int Width = Header.width;

NewImage->width = Width;
NewImage->height = Header.height;
char * Mallocd_Comment = malloc(Header.comment_len * sizeof(char));
strcpy(Mallocd_Comment, CommentBuffer);
NewImage->comment = Mallocd_Comment;


fclose(fp);
return NewImage;


























}

/**
 * Save an image to the passed filename, in ECE264 format.
 * Return TRUE if this succeeds, or FALSE if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
int Image_save(const char * filename, Image * image)
{


	return 0;
}

/**
 * Free memory for an image structure
 *
 * Image_load(...) (above) allocates memory for an image structure. 
 * This function must clean up any allocated resources. If image is 
 * NULL, then it does nothing. (There should be no error message.) If 
 * you do not write this function correctly, then valgrind will 
 * report an error. 
 */
void Image_free(Image * image)

{
	free (image->data);
	free (image->comment);
	free (image);


}

/**
 * Performs linear normalization, see README
 */
void linearNormalization(int width, int height, uint8_t * intensity)

{

}



