#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {int rows; int cols; unsigned char* data;} sImage;

void setImageInfo(FILE*, long, int, int);
long getImageInfo(FILE*, long, int);

int main(int argc, char* argv[])
{
    FILE			*bmpInput, *rasterOutput;
    sImage		originalImage;
    unsigned char		someChar;
    unsigned char*	pChar;
    int			nColors,nColors1;
    long			fileSize;
    int			vectorSize, y, x, i,count, x1=2,y1=3;
    int nx,ny,red,green,blue,bitpix,px;
    char *fn = "dancers3cp.bmp";

    /*
       if(argc < 2)
       {
       printf("Usage: %s bmpInput.bmp\n", argv[0]);
       exit(0);
       }
       printf("Reading filename %s\n", argv[1]);
       */

    /*bmpInput = fopen(argv[1], "rb");*/
    bmpInput = fopen(fn, "r+b"); //picture file

    //fseek(bmpInput, 0L, SEEK_END);
    rasterOutput = fopen("data.txt", "w"); //output file

    /*--------GET BMP DATA---------------*/
    nx=originalImage.cols = (int)getImageInfo(bmpInput ,18, 4);
    ny=originalImage.rows = (int)getImageInfo(bmpInput, 22, 4);
    fileSize = getImageInfo(bmpInput, 2, 4);
    nColors = getImageInfo(bmpInput, 46, 4);
    nColors1 = getImageInfo(bmpInput, 50, 4);
    bitpix = getImageInfo(bmpInput, 28, 1);
    printf("Width: %d\n", originalImage.cols);
    printf("Height: %d\n", originalImage.rows);
    printf("# Colors: %d nColors1=%d filesize=%ld bitpix=%d\n", nColors,nColors1,fileSize,bitpix);
    fclose(bmpInput);
    while(x1>=0 && y1>=0){
        printf("enter x1 and y1 values\n");
        scanf("%d %d",&x1,&y1);
        printf("x1=%d y1=%d\n",x1,y1);
        if(x1<0 || y1 < 0)break;
        bmpInput = fopen(fn, "r+b"); 
        blue=(int)getImageInfo(bmpInput, 54 + (nx*y1 + x1)*3, 1);
        green=(int)getImageInfo(bmpInput, 54 + (nx*y1 + x1)*3+1, 1);
        red=(int)getImageInfo(bmpInput, 54 + (nx*y1 + x1)*3+2, 1);
        printf("red=%d  green=%d  blue=%d\n",red,green,blue);
        setImageInfo(bmpInput, 54 + (nx*y1 + x1)*3, 1,255);
        setImageInfo(bmpInput, 54 + (nx*y1 + x1)*3+1, 1,255);
        setImageInfo(bmpInput, 54 + (nx*y1 + x1)*3+2, 1,0);
        fclose(bmpInput);
    }
    fclose(rasterOutput);
}

void setImageInfo(FILE* inputFile, long offset, int numberOfChars, int color)
{
    unsigned char			*ptrC;
    long				value = 0L;
    unsigned char			dummy;
    int				i;

    //dummy = '0';
    ptrC = &dummy;

    fseek(inputFile, offset, SEEK_SET);

    for(i=1; i<=numberOfChars; i++)
    {
        *ptrC = color;
        fwrite(ptrC, sizeof(char), 1, inputFile);
    }
} /* end of getImageInfo */

long getImageInfo(FILE* inputFile, long offset, int numberOfChars)
{
    unsigned char			*ptrC;
    long				value = 0L;
    unsigned char			dummy;
    int				i;

    //dummy = '0';
    ptrC = &dummy;

    fseek(inputFile, offset, SEEK_SET);

    for(i=1; i<=numberOfChars; i++)
    {
        fread(ptrC, sizeof(char), 1, inputFile);
        value = (long)(value + (*ptrC)*(pow(256, (i-1))));
    }
    return(value);

} /* end of getImageInfo */
