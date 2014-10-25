#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer07.h"

Image * Image_load(const char * filename) 
{
	FILE * fp = NULL;
	size_t Read, Read2, Read3;
	ImageHeader Header;
//Image * NewImage = NULL, * OtherImage = NULL;
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
	CommentLength = Header.comment_len; // setting comment length
//Read Comment
	char * Mallocd_Comment = malloc(Header.comment_len * sizeof(char));
	Read2 = fread(Mallocd_Comment, CommentLength, 1 , fp);
	if ( Read2 != 1) {
		printf("failed to read comment");
		free(Mallocd_Comment);
		fclose(fp);
		return NULL;}
//Check if Comment ends with Null terminator
	if (Mallocd_Comment[Header.comment_len -1] != '\0') { 
		printf("no null terminator on comment");
		free(Mallocd_Comment);
		fclose(fp);
		return NULL;}	
//Read Pixels
	Image *NewImage = malloc(sizeof(Image));
	size_t PixelArea =  Header.width * Header.height;
	NewImage->data = malloc(PixelArea * sizeof(uint8_t));
	Read3 = fread(NewImage->data, 1, PixelArea, fp);
	if (Read3 != PixelArea) {
		printf(" failed to read pixels");
		free(NewImage->data);
		free(Mallocd_Comment);
		free(NewImage);
		fclose(fp);
		return NULL;}
//Check if there are extra bytes
	size_t Checkend;
    Read3 = fread (&Checkend, sizeof(uint8_t) , 1, fp);
	if (Read3 != 0)   {
		printf("Too many bytes");
		free(NewImage->data);
		free(Mallocd_Comment);
		free(NewImage);
		fclose(fp);
		return NULL;                       }
//Assigning struct member valuesT
	NewImage->width = Header.width;
	NewImage->height = Header.height;
	NewImage->comment = Mallocd_Comment;
//Closing File
	fclose(fp);
	return NewImage;

}

int Image_save(const char * filename, Image * image)
{
	FILE * fp = NULL;
	size_t Write1, Write2, Write3;
	fp = fopen(filename, "wb");
	if (fp == NULL) { return 0;}
	//Creating Header Struct
	ImageHeader Header;
	Header.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
	Header.width = image->width;
	Header.height = image->height;
	Header.comment_len = (1 + strlen(image->comment) );
	//Writing  Header Struct
	Write1 = fwrite(&Header, sizeof(ImageHeader), 1, fp);
	if(Write1 != 1){
		printf("Failed to write");
		fclose(fp);
		return 0;
		}
	//Writing comment and data;
	Write2 = fwrite(image->comment,(1+strlen(image->comment)), 1, fp);
	if(Write2 != 1){
		printf("Failed to write");
		fclose(fp);
		return 0;
		}
	size_t PixelArea = Header.height * Header.width;
	Write3 = fwrite(image->data, sizeof(uint8_t), PixelArea, fp);
	if(Write3 != PixelArea){
		printf("Failed to write");
		fclose(fp);
		return 0;
		}
	fclose(fp);
	return 1;
}
void Image_free(Image * image) // Freeing image struct
{
	free (image->data);
	free (image->comment);
	free (image);
}
void linearNormalization(int width, int height, uint8_t * intensity)
{
	int I = 0, Min = intensity[0], Max = intensity[0];

	for (I=0; I < (width * height); I++)
	{
		if (intensity[I] > Max){ Max = intensity[I]; }
		if (intensity[I] < Min){ Min = intensity[I]; }
	}
	for (I=0; I < (width * height); I++)
	{
		intensity[I] = (intensity[I] - Min) * 255.0/(Max - Min);
	}
}



