#define MAX_LINE 10001
#define MAX_NAMELEN 129

extern FILE *popen (const char *command, const char *type);
extern int pclose(FILE *stream);

FILE *fppo;

long long image_index = 0; //record the its the n-th image

struct Images
{
  double x[MAX_LINE];
  double y[MAX_LINE]; //record the points
  char name[MAX_NAMELEN];         //record the name of the images
  long int number;             //record the numebrs of the  points
};

struct Images image[MAX_LINE/2+1];

int print_stdout(FILE *fppo,struct Images image[MAX_LINE],char *image_name)
{
  //this function is to print the info. about image to the stdout
  int i=0,j=0;
  for (i=image_index-1 ; i>=0 ; i--)
    {
      if (!strcmp(image_name,image[i].name))
	{
	  printf ("Print Image %s =\n",image[i].name);
	  if (image[i].number > 1) //special case
	    {	  
	    	for(j=0;j<image[i].number;j++)
	     	    printf("%g %g\n",image[i].x[j],image[i].y[j]);
 	    }
	  printf ("End Image %s\n",image[i].name);
	  return 1;
	}
    }
    return 0;

}

void draw(FILE *fppo,struct Images image[MAX_LINE],char *image_name)
 {
   //this function is to send the command to the Sketchpad and draw the lines
   // also it handles the special case that the image just has start points
   int i=0,j=0;
   for (i=image_index-1 ; i>=0 ; i--)
     {
       if (!strcmp(image_name,image[i].name))
	 {
	   if (image[i].number > 1) //special case
	     {
	       for(j=0;j<image[i].number-1;j++)
		 fprintf(fppo,"drawSegment %ld %ld %ld %ld\n",lround(image[i].x[j]),
			 lround(image[i].y[j]),lround(image[i].x[j+1]),
			 lround(image[i].y[j+1]));
	     }
	   return ;
	 }
     }
 }

void translate(FILE *fppo,struct Images image[MAX_LINE],char *image_name, double move_x, double move_y)
{
  //this function is to translate the image,using move_x and move_y change and 
  //move the whole image
   int i=0,j=0;
   for (i=image_index-1 ; i>=0 ; i--)
     {
       if (!strcmp(image_name,image[i].name))
	 {
	   for(j=0;j<image[i].number;j++)
	     {
	       image[i].x[j] += move_x;
	       image[i].y[j] += move_y;
	     }
	   return ;
	 }
      }
}
