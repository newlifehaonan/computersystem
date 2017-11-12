* struct
  * what is struct      
  struct is a data type that groups objects of possibly different types into a single object.
  * how to create and reference a struct in C.
    ```C
    struct rect{
      unsigned long height;
      unsigned long width;
      unsigned color;
      long llx; //X coordinate of lower-left//
      long lly; //Y coordinate of lower-left//   
    }
    //create a new struct r//
    struct rect \*r;

    //how to assign value to the struct//
    (\*r).llx = r.lly = 0;
    (\*r).color = 0xff0ff;
    ...
    //or//
    r->llx = 0;
    r->lly =0;
    r->height = 10;
    //or//
    (\*r) = {0,0,0xff0ff,10,20};

    ```
