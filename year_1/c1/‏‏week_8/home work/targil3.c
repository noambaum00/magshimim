#include <stdio.h>
#include <math.h>
#define PIE 3.1415 


int distanceXY();
int excessTriangle();
int areaCircle();
int rectanglearea();
int squareArea();

int main(void) {
  int option = 0;
  printf("i");
  scanf("%d", &option);
  
  switch (option)
{
    case 1:
      distanceXY();
      break;

    case 2:
      excessTriangle();
      break;

    case 3:
      areaCircle();
      break;

    case 4:
      rectanglearea();
      break;

    case 5:
      squareArea();
      break;

    case 6:
      printf("bye");
      return 0;
      break;

    default:
    printf("bye");
    return 0;
}
  
}

int distanceXY()  
{  
    float x1, y1, x2, y2, distance;  
  
    printf("Enter point 1 (x1, y1)\n");  
    scanf("%f%f", &x1, &y1);  
    printf("Enter point 2 (x2, y2)\n");  
    scanf("%f%f", &x2, &y2);  
    distance = sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) ); 
    printf("Distance between (%0.2f, %0.2f) and (%0.2f, %0.2f) is %0.2f\n", x1, y1, x2, y2, distance);  
}  

int excessTriangle()
{
  float height=0, width=0, remainder=0;
  printf("Enter 2 NUMBER\n");  
  scanf("%f%f", &height, &width);
  remainder = sqrt(pow(height,2) + pow(width,2));
}

int areaCircle(){
  float r, Area,  Perimeter;
    printf("Enter the radius of circle");
    scanf("%f",&r); 
    Area = PIE*r*r; 
    Perimeter=2*PIE*r;
    printf("the area of the circle is %f\n",Area);
    printf("the perimeter of the circle is %f\n",Perimeter); 
}

int rectanglearea(){
  float length, breadth, area;
   printf("Enter the Length of Rectangle : ");
   scanf("%f", &length);

   printf("Enter the Breadth of Rectangle : ");
   scanf("%f", &breadth);

   area = pow(length,2);
   printf("Area of Rectangle : %f", area);

}

int squareArea(){
   float rid, area;
   printf("\nEnter the Length of rid : ");
   scanf("%f", &rid);

   area = pow(rid,2);
   printf("Area of Square : %f", area);
}